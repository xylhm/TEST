// EffectiveC++Ìõ¿î28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "memory"
//#include "new"
struct point {
public:
    point():x(0), y(0){}
    point(int a , int b):x(a), y(b)
    {
    }
    point& point::operator=(const point& rhs);
    void SetX(int);
    void SetY(int);
    int SetA ()const;
private:
    int x;
    int y;
};

struct RectData {
public:
    RectData()
    {

    }
    point UperLeft;
    point LowerRight;
};

struct Rectangle
{
    Rectangle(point a, point b)
    {
        pData->UperLeft = a;
        pData->LowerRight = b;
    }
    const point& uper_left() const { return pData->UperLeft; }
     point& lower_right() const { return pData->LowerRight; }
private:
    //std::tr1::shared_ptr<RectData> pData ;
    RectData* pData = new RectData;
};

int main()
{
    point p1(10, 10);
    point p2(20, 20);
    const point p3(50, 50);
    p3.SetA();
    Rectangle rect(p1, p2);
    rect.lower_right().SetX(50);
    return 0;
}

void point::SetX(int a)
{
    x = a;
}

void point::SetY(int a)
{
    y = a;
}
int point::SetA()const
{
    return x;
}
point& point::operator=(const point& rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}