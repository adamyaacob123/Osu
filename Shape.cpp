#include "Shape.hpp"
#include <graphics.h>
#include <cmath>
using namespace std ;


Circle::Circle() : 	m_x(0), m_y(0),  m_r(0),  m_dx (0), m_dy(0){}
Circle::Circle(int x, int y, int r, int dx, int dy) : 	m_x(x), m_y(y),  m_r(r),  m_dx (dx), m_dy (dy){}
Circle::Circle(int x, int y, int r) : m_x(x), m_y(y),  m_r(r) {}

void Circle::setLocation(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Circle::setRadius(int r)
{
  m_r = r;
}

void Circle::draw(int color) const
{ 
  setcolor(color) ;
  circle(m_x, m_y, m_r);
}

void Circle::undraw() const
{
  setcolor(BLACK);
  circle(m_x, m_y, m_r);
}

int Circle::distance(const Circle &circle)
{
  return sqrt(pow(circle.m_x - m_x, 2) + pow(circle.m_y - m_y, 2));
}

int Circle::operator-(const Circle &circle)
{
  return distance(circle);
}