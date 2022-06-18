#include <iostream>
#include <string>
#include <graphics.h>
#include <cstdio>
#include <stdlib.h> /* srand, rand */
#include "Clock.h"
#include "Shape.hpp"
#include <stdio.h>
#include <conio.h>

using namespace std;

int displacement(const Circle &c1, const Circle &c2);
int randomGenerator(int offset, int max);

void DisplayText(char *const text)
{
  /* request autodetection */

  int gdriver = DETECT, gmode, errorcode;

  int style, midx, midy;

  int size = 1;

  /* initialize graphics and local variables */

  initgraph(&gdriver, &gmode, "");

  /* read result of initialization */

  errorcode = graphresult();

  if (errorcode != grOk)
  { /* an error occurred */

    printf("Graphics error: %s\n", grapherrormsg(errorcode));

    printf("Press any key to halt:");

    getch();

    exit(1); /* terminate with an error code */
  }

  midx = getmaxx() / 2;

  midy = getmaxy() / 2;
  style = 6;
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  cleardevice();

  settextstyle(style, HORIZ_DIR, size);
  outtextxy(midx, midy, text);

  if (getch())
  {
    closegraph();
    return;
  }
}
void cleartext()
{
  // setfillstyle(SOLID_FILL, getmaxcolor());
  setfillstyle(SOLID_FILL, 0);
  bar(0, 0, 220, 40);
}

/* clean up */

int main()
{

  DisplayText("PRESS ANY KEY TO START THE GAME");
  Clock<> clock;
  // Clock<> clock2 ;
  constexpr long long spawnRate = 2499;
  constexpr long long Rate = 700;
  int Lifepoint = 12;
  int width = getmaxwidth();
  int height = getmaxheight();
  char ch = 0; // Set placeholder key
  const int count = 2;
  int radius = 100;
  int w_Max, h_Max;
  const uint32_t SleepMicroseconds = 100;
  char msg[128];
  char msg2[128];
  int style = 4;
  int size = 1;
  int Score(0) ;
  // settextstyle(style, HORIZ_DIR, size);

  // To initialize WinBGI and open a new window for graphic display
  initwindow(width, height, "Click & Go");

  /* initialize random seed: */
  srand(time(NULL));
  readimagefile("Click & GO Storyboard.jpg", 0 , 0, width , height) ;

  Circle circles;

  w_Max = randomGenerator(radius, width);
  h_Max = randomGenerator(radius, height);
  circles.setLocation(w_Max, h_Max);
  circles.setRadius(radius);
  circles.draw(15);


  while (ch != 27) // ASCII code 27 is the ESC key
  {
    // Global Clock
    //  cout << clock.getSeconds() << endl ;
    //  cout << "clock1 : " << clock.getMilliseconds() << endl ;
    //  cout << "clock2 : " << clock2.getMilliseconds() << endl ;
    //  if (clock.getMilliseconds() >= spawnRate && clock.getMilliseconds() <= spawnRate + 500)
    //  if (clock.getMilliseconds() == spawnRate)
    //  {
    //    cout << clock.getMilliseconds() << endl ;
    //    // clock.reset();
    //    cout << "image printed" ;
    //    w_Max = randomGenerator(radius, width);
    //    h_Max = randomGenerator(radius, height);
    //    circles.setLocation(w_Max, h_Max);
    //    circles.draw();
    //  }

    if (ismouseclick(WM_LBUTTONDOWN))
    {
      int mx, my;
      getmouseclick(WM_LBUTTONDOWN, mx, my);
      cout << mx << endl;
      Circle cur = Circle(mx, my, 0);

      if (displacement(circles, cur) <= radius)
      {
        clock.reset();
        cout << "hit" << endl;
        Score+=100 ;
        circles.draw(2);
        circles.undraw();
        w_Max = randomGenerator(radius, width);
        h_Max = randomGenerator(radius, height);
        circles.setLocation(w_Max, h_Max);
        circles.draw(2);
        cleartext();
        sprintf(msg, "Life :%d", Lifepoint);
        sprintf(msg2, "Score :%d", Score);
        settextstyle(2, 0, 10);
        outtextxy(0, 0, msg);
        outtextxy(width - 300, 0, msg2);
        // outtext((char*)"Score : ");

        // outtextxy(xmin, ymid, msg);
      }
      else
      {
        clock.reset();
        circles.undraw();
        Lifepoint--;
        cout << "noob" << endl;
        w_Max = randomGenerator(radius, width);
        h_Max = randomGenerator(radius, height);
        circles.setLocation(w_Max, h_Max);
        circles.draw(15);
        cleartext();
        sprintf(msg, "Life :%d", Lifepoint);
        sprintf(msg2, "Score :%d", Score);
        settextstyle(2, 0, 10);
        outtextxy(0, 0, msg);
        outtextxy(width - 300, 0, msg2);
        // outtext((char*)"Score : ");
      }
    }
    // else if(clock.getMilliseconds() >= Rate && clock.getMilliseconds() <= Rate + 500){
    else if (clock.getMilliseconds() == Rate)
    {
      cout << clock.getMilliseconds() << endl;
      cout << "Life : " << Lifepoint;
      Lifepoint--;
      cout << "out of bound" << endl;
      circles.undraw();
      clock.reset();
      w_Max = randomGenerator(radius, width);
      h_Max = randomGenerator(radius, height);
      circles.setLocation(w_Max, h_Max);
      circles.draw(15);
      cleartext();
      sprintf(msg, "Life :%d", Lifepoint);
      sprintf(msg2, "Score :%d", Score);
      settextstyle(2, 0, 10);
      outtextxy(0, 0, msg);        
      outtextxy(width - 300, 0, msg2);
    }

    if (Lifepoint == 0)
    {
      DisplayText("GAME OVER");
      // cout << "Game Over" << endl;
      exit(1);
    }
    // clock.reset();
    // delay(0.01);
  }
  return 0;
}

int displacement(const Circle &c1, const Circle &c2)
{
  Circle c = c1;
  return c - c2;
}

int randomGenerator(int offset, int max)
{
  int pos = rand() % (max - offset);
  if (pos <= offset)
    return pos + offset;
  return pos;
}