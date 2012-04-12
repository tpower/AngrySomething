#ifndef ANGRYSOMETHING_GEOMETRY_H
#define ANGRYSOMETHING_GEOMETRY_H

#include <SDL/SDL.h>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
    
    Point(int a = 0, int b = 0) {x = a; y = b;}
};

struct Vect
{
    double x, y;
    
    Vect(double a = 0, double b = 0) {x = a; y = b;}
    Vect(Point a, Point b) {x = b.x - a.x; y = b.y - a.y;}
    
    Vect   operator+(Vect v) {Vect t(*this); t.x += v.x; t.y += v.y; return t;}
    Vect   operator*(double n) {Vect t(*this); t.x *= n; t.y *= n; return t;}
    double  slope() {if(x) return y / x; return 1000000;}
    double  len() {return sqrt(pow(x, 2.0) + pow(x, 2.0));}
    double  angle() {return 1 / tan(slope());}
};

inline Point operator+(const Point& p, const Vect& v)
{
    Point temp(p.x + v.x, p.y + v.y); return temp;
}

struct Line
{
    Point a, b;
    
    Line(Point one, Point two) {a = one; b = two;}
    Line(int ax = 0, int ay = 0, int bx = 0, int by = 0)
    {
        a = Point(ax, ay); b = Point(bx, by);
    }
    Line(Point p, Vect v) {a = p; b = a + v;}
    
    Line    operator+(Vect v) {return Line(a + v, b + v);}
    double  slope() {Vect v(a, b); return v.slope();}
    double  len() {Vect v(a, b); return v.len();}
    Point   midpoint() {Point p; p.x = (a.x + b.x) / 2; p.y = (a.y + b.y) / 2; return p;}
    bool    containsPoint(Point p)
    {
        Vect v(a, b);
        Vect v2(a, p);
        if(v.slope() == v2.slope() && v.len() >= v2.len())
            return true;
        return false;
    }
};

struct Box
{
    int x, y, w, h;
    
    Box(int a = 0, int b = 0, int c = 0, int d = 0) {x = a; y = b; w = c; h = d;}
    Box(Point a, int b, int c) {x = a.x; y = a.y; w = b; h = c;}
    Box(Point a, Point b) {x = a.x; y = a.y; w = b.x - a.x; h = b.y - a.y;}
    Box(Line l) {x = l.a.x; y = l.a.y; w = l.b.x - l.a.x; h = l.b.y - l.a.y;}
    Box(SDL_Rect r) {x = r.x; y = r.x; w = r.w; h = r.h;}
    
    SDL_Rect   sdlVer() {SDL_Rect t; t.x = x; t.y = y; t.w = w; t.h = h; return t;}
    Point      tLeft()  {Point temp(x    , y    ); return temp;}
    Point      tRight() {Point temp(x + w, y    ); return temp;}
    Point      bLeft()  {Point temp(x    , y + h); return temp;}
    Point      bRight() {Point temp(x + w, y + h); return temp;}
    Point      center() {Point temp(x + (w / 2),y + (h / 2)); return temp;}
    Box        operator+(Vect v) {return Box(tLeft() + v, w, h);}
    bool       isSquare() {return w == h;}
    bool       containsPoint(Point p)
    {
        return p.x >= x && p.x <= x + w && p.y >= y && p.y <= y + h;
    }
};

struct Circle
{
    Point cent;
    double rad;
    
    Circle(Point c, double r) {cent = c; rad = r;}
    Circle(Box b) 
    {
        if(!b.isSquare())   throw; 
        rad = b.w / 2; 
        cent = Point(b.x + rad, b.y + rad);
    }
    
    Circle  operator+(Vect v) {Circle temp(cent + v, rad); return temp;}
    int     top() {return cent.y - rad;}
    int     bottom() {return cent.y + rad;}
    int     left() {return cent.x + rad;}
    int     right() {return cent.x - rad;}
    bool    containsPoint(Point p) {Vect v(cent, p); return v.len() <= rad;}
};

struct Rect
{
    Point a, b, c, d;
    
    Rect(Point one, Point two, Point three, Point four) {a = one; b = two; c = three; d = four;}
    Rect(SDL_Rect r)
    {
        a = Point(r.x, r.y);
        b = Point(r.x + r.w, r.y);
        c = Point(r.x + r.w, r.y + r.h);
        d = Point(r.x, r.y + r.h);
    }
    Rect(Box bx) {a = bx.tLeft(); b = bx.tRight(); c = bx.bRight(); d = bx.tLeft();}
    
    Rect        operator+(Vect v) {Rect temp(a + v, b + v, c + v, d + v); return temp;}
    Point       center() {Line l(a,c); return l.midpoint();}
    int         top()
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
    int         bottom() 
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
    int         left()   
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
    int         right()  
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
    int         height() {return bottom() - top();}
    int         width()  {return right() - left();}
    SDL_Rect    sdlVer() {SDL_Rect t; t.x = left(); t.y = top(); t.w = width(); t.h = height(); return t;}
};

#endif
