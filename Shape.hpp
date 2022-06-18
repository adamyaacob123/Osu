#ifndef SHAPE_H
#define SHAPE_H


class Circle{

private:
	int m_x = 0, m_y = 0;
	int m_r;
	int m_dx = 0, m_dy = 0;

public:
  Circle();
  Circle(int x, int y, int r, int dx, int dy);
  Circle(int x, int y, int r);
  void setLocation(int x, int y);
  void setRadius(int r);
  void draw(int color) const;
  void undraw() const;
  int distance(const Circle &circle);
  int operator-(const Circle &circle);
};


#endif