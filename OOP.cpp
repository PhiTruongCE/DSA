#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Point
{
private:
    double x, y;

public:
    Point()
    {
        this->x=0;
        this->y=0;
    }

    Point(double x, double y)
    {
        this->x=x;
        this->y=y;
    }

    void setX(double x)
    {
        this->x=x;
    }

    void setY(double y)
    {
        this->y=y;
    }

    double getX() const
    {
        return this->x;
    }

    double getY() const
    {
        return this->y;
    }

    double distanceToPoint(const Point& pointA)
    {
        return sqrt(pow((this->x - pointA.x),2)+pow((this->y - pointA.y),2));
    }
};
/*
class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        this->center.setX(0);
        this->center.setY(0);
        this->radius=0;
    }

    Circle(Point center, double radius)
    {
        double i = center.getX();
        this->center.setX(i);
        double k = center.getY();
        this->center.setY(k);
        this->radius=radius;
    }
    
    void operator=(const Circle &circle)
    {
        double i = circle.center.getX();
        this->center.setX(i);
        double k = circle.center.getY();
        this->center.setY(k);
        this->radius=circle.radius;
    }

    bool operator==(const Circle &circle)
    {
        return ((this->center.getX() == circle.center.getX()) && (this->center.getY() == circle.center.getY()) && (this->radius == circle.radius));
    }

    friend istream& operator >> (istream &in, Circle &circle)
    {
        double x,y;
        in>> x;
        circle.center.setX(x);
        in>> y;
        circle.center.setY(y);
        in>> circle.radius;
        return in;
    }

    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};*/

/*class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        this->center.setX(0);
        this->center.setY(0);
        this->radius=0;
    }

    Circle(Point center, double radius)
    {
        double i = center.getX();
        this->center.setX(i);
        double k = center.getY();
        this->center.setY(k);
        this->radius=radius;
    }

    Circle(const Circle &circle)
    {
        double i = circle.center.getX();
        this->center.setX(i);
        double k = circle.center.getY();
        this->center.setY(k);
        this->radius = circle.radius;
    }
    
    void setCenter(Point point)
    {
        double i = point.getX();
        this->center.setX(i);
        double k = point.getY();
        this->center.setY(k);
    }

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    Point getCenter() const
    {
        return this->center;
    }

    double getRadius() const
    {
        return this->radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};*/

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        this->center.setX(0);
        this->center.setY(0);
        this->radius=0;
    }

    Circle(Point center, double radius)
    {
        double i = center.getX();
        this->center.setX(i);
        double k = center.getY();
        this->center.setY(k);
        this->radius=radius;
    }

    bool containsPoint(const Point point)
    {
        /*  
         * STUDENT ANSWER 
         * TODO: check if a given point is entirely within the circle (does not count if the point lies on the circle).  
                 If contain, return true.
         */
        return sqrt((pow((point.getX()-this->center.getX()),2) + pow((point.getY()-this->center.getY()),2))) < this->radius;
    }

    bool containsTriangle(const Point pointA, const Point pointB, const Point pointC)
    {
        /*  
         * STUDENT ANSWER   
         * TODO: check if a given triangle ABC (A, B, C are not on the same line) is entirely within the circle (does not count if any point of the triangle lies on the circle).  
                 If contain, return true.
         */
        return (containsPoint(pointA) && containsPoint(pointB) && containsPoint(pointC));
    }
};
int main(){
    Point pointO(0, 0);
    Point point1(1, 0), point2(-1, 0), point3(0, 3);
    Circle A = Circle(pointO, 3);
    cout << A.containsTriangle(point1, point2, point3);
    return 0;
}