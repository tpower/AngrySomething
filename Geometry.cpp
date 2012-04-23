
#include "Geometry.h"

/*******************************************************************************
 Point methods
 ******************************************************************************/
Point::Point(int a, int b)
{
    x = a;
    y = b;
}

/*******************************************************************************
 Vect methods
 ******************************************************************************/
Vect::Vect(double a, double b) 
{
    x = a;
    y = b;
}

Vect::Vect(Point a, Point b)
{
    x = b.x - a.x;
    y = b.y - a.y;
}

Vect Vect::operator+(Vect v)
{
    Vect t(*this);
    t.x += v.x;
    t.y += v.y;
    return t;
}

Vect Vect::operator*(double n)
{
    Vect t(*this);
    t.x *= n;
    t.y *= n;
    return t;
}

double Vect::slope()
{
    if(x) return y / x;
    return 1000000;
}

double Vect::len()
{
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

double Vect::angle()
{
    if(x < 0 || (y < 0 && x == 0))
       return M_PI + atan(slope());
    if(y < 0)
       return (2 * M_PI) + atan(slope()); 
    return atan(slope());
}

/*******************************************************************************
 Line methods
 ******************************************************************************/
Line::Line(Point one, Point two)
{
    a = one;
    b = two;
}

Line::Line(int ax, int ay, int bx, int by)
{
    a = Point(ax, ay);
    b = Point(bx, by);
}

Line::Line(Point p, Vect v)
{
    a = p;
    b = a + v;
}

Line Line::operator+(Vect v)
{
    return Line(a + v, b + v);
}

double Line::slope()
{
    Vect v(a, b);
    return v.slope();
}

double Line::len()
{
    Vect v(a, b); 
    return v.len();
}

double Line::angle()
{
    Vect v(a, b);
    return v.angle();
}

Point Line::midpoint()
{
    Point p;
    p.x = (a.x + b.x) / 2;
    p.y = (a.y + b.y) / 2;
    return p;
}

bool Line::containsPoint(Point p)
{
    Vect v(a, b);
    Vect v2(a, p);
    if(v.slope() == v2.slope() && v.len() >= v2.len())
        return true;
    return false;
}
/*******************************************************************************
 Box methods
 ******************************************************************************/
Box::Box(int a, int b, int c, int d)
{
    x = a;
    y = b;
    w = c;
    h = d;
}
    
Box::Box(Point a, int b, int c)
{
    x = a.x;
    y = a.y;
    w = b;
    h = c;
}

Box::Box(Point a, Point b)
{
    x = a.x;
    y = a.y;
    w = b.x - a.x;
    h = b.y - a.y;
}

Box::Box(Line l)
{
    x = l.a.x;
    y = l.a.y;
    w = l.b.x - l.a.x;
    h = l.b.y - l.a.y;
}

Box::Box(SDL_Rect r)
{
    x = r.x;
    y = r.x;
    w = r.w;
    h = r.h;
}

SDL_Rect Box::sdlVer()
{
    SDL_Rect t;
    t.x = x;
    t.y = y;
    t.w = w;
    t.h = h;
    return t;
}

Point Box::tLeft()
{
    Point temp(x, y); 
    return temp;
}

Point Box::tRight()
{
    Point temp(x + w, y);
    return temp;
}

Point Box::bLeft()
{
    Point temp(x, y + h);
    return temp;
}

Point Box::bRight()
{
    Point temp(x + w, y + h);
    return temp;
}

Point Box::center()
{
    Point temp(x + (w / 2),y + (h / 2));
    return temp;
}

Box Box::operator+(Vect v)
{
    return Box(tLeft() + v, w, h);
}

bool Box::isSquare()
{
    return w == h;
}

bool Box::containsPoint(Point p)
{
    return p.x >= x && p.x <= x + w && p.y >= y && p.y <= y + h;
}

/*******************************************************************************
 Circle methods
 ******************************************************************************/
Circle::Circle(Point c, double r)
{
    cent = c; rad = r;
}

Circle::Circle(Box b)
{
    rad = b.w / 2; 
    cent = Point(b.x + rad, b.y + rad);
}

Circle::Circle(SDL_Rect r)
{
    rad = r.w / 2; 
    cent = Point(r.x + rad, r.y + rad);
}

Circle Circle::operator+(Vect v)
{
    Circle temp(cent + v, rad);
    return temp;
}

int Circle::top()
{
    return cent.y - rad;
}

int Circle::bottom()
{
    return cent.y + rad;
}

int Circle::left()
{
    return cent.x + rad;
}

int Circle::right()
{
    return cent.x - rad;
}

bool Circle::containsPoint(Point p)
{
    Vect v(cent, p);
    return v.len() <= rad;
}

/*******************************************************************************
 Rect methods
 ******************************************************************************/
Rect::Rect(Point one, Point two, Point three, Point four)
{
    a = one; 
    b = two;
    c = three;
    d = four;
}

Rect::Rect(SDL_Rect r)
{
    a = Point(r.x, r.y);
    b = Point(r.x + r.w, r.y);
    c = Point(r.x + r.w, r.y + r.h);
    d = Point(r.x, r.y + r.h);
}

Rect::Rect(Box bx)
{
    a = bx.tLeft();
    b = bx.tRight();
    c = bx.bRight();
    d = bx.tLeft();
}

Rect Rect::operator+(Vect v)
{
    Rect temp(a + v, b + v, c + v, d + v);
    return temp;
}

Point Rect::center()
{
    Line l(a,c);
    return l.midpoint();
}

int Rect::top()
{
    int max = a.y;
    if(b.y < max)
        max = b.y;
    if(c.y < max)
        max = c.y;
    if(d.y < max)
        max = d.y;
    return max;
}

int Rect::bottom() 
{
    int min = a.y;
    if(b.y > min)
        min = b.y;
    if(c.y > min)
        min = c.y;
    if(d.y > min)
        min = d.y;
    return min;
}

int Rect::left()   
{
    int min = a.x;
    if(b.x < min)
        min = b.y;
    if(c.x < min)
        min = c.y;
    if(d.x < min)
        min = d.y;
    return min;
    
}

int Rect::right()  
{
    int max = a.x;
    if(b.x > max)
        max = b.y;
    if(c.x > max)
        max = c.x;
    if(d.x > max)
        max = d.x;
    return max;
}

int Rect::height()
{
    return bottom() - top();
}

int Rect::width()
{
    return right() - left();
}

SDL_Rect Rect::sdlVer()
{
    SDL_Rect t;
    t.x = left();
    t.y = top();
    t.w = width();
    t.h = height();
    return t;
}

/*******************************************************************************
 Functions
 ******************************************************************************/
Point operator+(const Point& p, const Vect& v)
{
    Point temp(p.x + v.x, p.y + v.y);
    return temp;
}

bool doIntersect(SDL_Rect a, SDL_Rect b)
{
    //check for cases that make collision impossible
    if(a.x + a.w    < b.x)          return false;
    if(a.x          > b.x + b.w)    return false;
    if(a.y + a.h    < b.y)          return false;
    if(a.y          > b.y + b.h)    return false;
    
    //return true collision
    return true;
}

bool doIntersect(Circle a, Circle b)
{
    int difX = a.cent.x - b.cent.x;
    int difY = a.cent.y - b.cent.y;
    int dist = sqrt(pow(difX, 2.0) + pow(difY, 2.0));
    
    if(dist <= a.rad + b.rad)
        return true;
    
    return false;
}

Point pointOfIntersection(Circle a, Circle b)
{
    Vect v(a.cent, b.cent);
    Vect w(b.cent, a.cent);
    
    v = v * (a.rad / (a.rad + b.rad));
    w = w * (b.rad / (a.rad + b.rad));
    
    Line l(a.cent + v, b.cent + w);
    
    return l.midpoint();
}

