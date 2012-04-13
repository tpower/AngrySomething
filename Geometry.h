#ifndef ANGRYSOMETHING_GEOMETRY_H
#define ANGRYSOMETHING_GEOMETRY_H

#include <SDL/SDL.h>
#include <cmath>

using namespace std;

/*******************************************************************************
 Enum side, shape
 ******************************************************************************/
enum side
{
    NO_COLLISION    = 0,
    TOP             = 1,
    TOP_RIGHT       = 2,
    RIGHT           = 3,
    BOTTOM_RIGHT    = 4,
    BOTTOM          = 5,
    BOTTOM_LEFT     = 6,
    LEFT            = 7,
    TOP_LEFT        = 8
};

enum shape
{
    BOX     = 0,
    CIRCLE  = 1,
    RECT    = 2
};

/*******************************************************************************
 Point
 ******************************************************************************/
struct Point
{
    int x, y;
    
    Point(int a = 0, int b = 0);
};

/*******************************************************************************
 Vect
 ******************************************************************************/
struct Vect
{
    double x, y;
    
    Vect(double a = 0, double b = 0);
    Vect(Point a, Point b);
    
    Vect    operator+(Vect v);
    Vect    operator*(double n);
    double  slope();
    double  len();
    double  angle();
};

/*******************************************************************************
 Line
 ******************************************************************************/
struct Line
{
    Point a, b;
    
    Line(Point one, Point two);
    Line(int ax = 0, int ay = 0, int bx = 0, int by = 0);
    Line(Point p, Vect v);
    
    Line    operator+(Vect v);
    double  slope();
    double  len();
    Point   midpoint();
    bool    containsPoint(Point p);
};

/*******************************************************************************
 Box
 ******************************************************************************/
struct Box
{
    int x, y, w, h;
    
    Box(int a = 0, int b = 0, int c = 0, int d = 0);
    Box(Point a, int b, int c);
    Box(Point a, Point b);
    Box(Line l);
    Box(SDL_Rect r);
    
    SDL_Rect   sdlVer();
    Point      tLeft();
    Point      tRight();
    Point      bLeft();
    Point      bRight();
    Point      center();
    Box        operator+(Vect v);
    bool       isSquare();
    bool       containsPoint(Point p);
};

/*******************************************************************************
 Circle
 ******************************************************************************/
struct Circle
{
    Point cent;
    double rad;
    
    Circle(Point c, double r);
    Circle(Box b);
    
    Circle  operator+(Vect v);
    int     top();
    int     bottom();
    int     left();
    int     right();
    bool    containsPoint(Point p);
};

/*******************************************************************************
 Rect
 ******************************************************************************/
struct Rect
{
    Point a, b, c, d;
    
    Rect(Point one, Point two, Point three, Point four);
    Rect(SDL_Rect r);
    Rect(Box bx);
    
    Rect        operator+(Vect v);
    Point       center();
    int         top();
    int         bottom();
    int         left();
    int         right();
    int         height();
    int         width();
    SDL_Rect    sdlVer();
};

/*******************************************************************************
 Functions
 ******************************************************************************/
Point   operator+(const Point& p, const Vect& v);
bool    doIntersect(SDL_Rect a, SDL_Rect b);
bool    doIntersect(Circle a, Circle b);

#endif
