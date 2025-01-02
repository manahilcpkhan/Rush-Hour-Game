//============================================================================
// Name        : ManahilKamran 21i-2668
// departement : Data Science
// Author      : FAST CS Department
// Version     : 1.0
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================
#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
 
int score = 0, timercount = 1740;

//function for timer displayed in the game. The game will end when the timer completes after 3 minutes
void
self_destruct ()
{
  timercount -= 1;
  if (timercount <= 1)
    {
      exit (1);
    }
}

//To set the size of screen
void
SetCanvasSize (int width, int height)
{
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glOrtho (0, width, 0, height, -1, 1);	// set the screen size to given width and height.
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
}

char name;
bool flag_A = true, flag_M = true, flag_B = true, flag_C = true, flag_D =
  true;

 // Headstart Menu function displayed at the start to initiate the game and select the carof choice
void
Menu ()
{
  DrawSquare (0, 0, 600, colors[BLACK]);
  DrawString (220, 510, "MENU", colors[WHITE]);
  DrawString (100, 460, "To start Rush Hour:", colors[WHITE]);
  DrawString (100, 410, "Choose colour of  your taxi:", colors[WHITE]);
  DrawString (100, 360, "Yellow: press 'y'", colors[WHITE]);
  DrawString (100, 330, "Red: press 'r'", colors[WHITE]);
  DrawString (100, 280, "Press 'Esc' to exit", colors[WHITE]);
  glutPostRedisplay ();
}

int xI = 0, yI = 520;
//long int a, b;

//Yellow Car of choice
void
drawCarY ()
{
  DrawRectangle (xI + 5, yI + 19, 20, 10, colors[DARK_GOLDEN_ROD]);
  DrawRectangle (xI, yI + 10, 30, 10, colors[DARK_GOLDEN_ROD]);
  DrawCircle (xI + 5, yI + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (xI + 25, yI + 5, 5, colors[DARK_SLATE_BLUE]);

  glutPostRedisplay ();


}

//RED car function of choice
void
drawCarR ()
{
  DrawRectangle (xI + 5, yI + 19, 20, 10, colors[RED]);
  DrawRectangle (xI, yI + 10, 30, 10, colors[RED]);
  DrawCircle (xI + 5, yI + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (xI + 25, yI + 5, 5, colors[DARK_SLATE_BLUE]);
  glutPostRedisplay ();
  // glutSwapBuffers();

}

bool flag1 = true, flag2 = true;
int c2 = 410, d2 = 160;

//automatic car1 that moves without control within a specific range
void
drawCar1 ()
{
  DrawRectangle (300, c2 + 10, 30, 10, colors[WHITE]);
  DrawCircle (300 + 5, c2 + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (300 + 25, c2 + 5, 5, colors[DARK_SLATE_BLUE]);
}

//automatic car2 that moves without control within a specific range
void
drawCar2 ()
{
  DrawRectangle (570, d2 + 10, 30, 10, colors[WHITE]);
  DrawCircle (570 + 5, d2 + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (570 + 25, d2 + 5, 5, colors[DARK_SLATE_BLUE]);
}

// car1 movement. Function is important ot move the automatic cars within a range
void
moveCar1 ()
{
  if (c2 > 10 && flag1)
    {
      c2 -= 10;
      cout << "going up";
      if (c2 < 409)
	flag1 = false;

    }
  if (c2 < 600 && !flag1)
    {
      cout << "go down";
      c2 += 10;
      if (c2 > 570)
	flag1 = true;
    }
  glutPostRedisplay ();
}

//car 2 movement. Function is important ot move the automatic cars within a range
void
moveCar2 ()
{
  if (d2 > 10 && flag2)
    {
      d2 -= 10;
      cout << "going up";
      if (d2 < 160)
	flag2 = false;

    }
  else if (d2 < 600 && !flag2)
    {
      cout << "go down";
      d2 += 10;
      if (d2 > 500)
	flag2 = true;
    }
  glutPostRedisplay ();
}

/*
 * Main Canvas drawing function.
 * */
 //long long int building[][3];

//buliding, park and roundabout function to draw the setup of game.
void
drawBuilding ()
{

  //roundabout
  DrawCircle (300, 350, 50, colors[DARK_VIOLET]);
  //building;

  DrawRectangle (60, 180, 120, 30, colors[DARK_VIOLET]);
  DrawRectangle (60, 210, 30, 180, colors[DARK_VIOLET]);

  DrawRectangle (120, 450, 150, 30, colors[DARK_VIOLET]);
  DrawSquare (120, 480, 30, colors[DARK_VIOLET]);

  DrawRectangle (390, 520, 90, 30, colors[DARK_VIOLET]);
  DrawRectangle (480, 460, 30, 90, colors[DARK_VIOLET]);

  //park
  DrawRectangle (450, 300, 90, 120, colors[GREEN]);
  DrawString (470, 360, "Park", colors[WHITE]);
  //buliding
  DrawRectangle (480, 210, 30, 90, colors[DARK_VIOLET]);

  DrawRectangle (360, 110, 240, 30, colors[DARK_VIOLET]);

  DrawRectangle (270, 220, 150, 30, colors[DARK_VIOLET]);
  DrawRectangle (270, 70, 30, 150, colors[DARK_VIOLET]);

  DrawRectangle (420, 0, 30, 60, colors[DARK_VIOLET]);

  DrawRectangle (0, 80, 150, 30, colors[DARK_VIOLET]);

}


 // trees function to draw the trees as obstacles on the board. 
void
Tree_a ()
{
  DrawRectangle (540, 0, 10, 30, colors[BROWN]);
  DrawCircle (540 + 5, 0 + 40, 20, colors[GREEN]);
}

void
Tree_b ()
{
  DrawRectangle (30, 440, 10, 30, colors[BROWN]);
  DrawCircle (30 + 5, 440 + 40, 20, colors[GREEN]);
}

void
Tree_c ()
{
  DrawRectangle (240, 130, 10, 30, colors[BROWN]);
  DrawCircle (240 + 5, 130 + 40, 20, colors[GREEN]);
}

void
Tree_d ()
{
  DrawRectangle (25, 0, 10, 30, colors[BROWN]);
  DrawCircle (25 + 5, 0 + 40, 20, colors[GREEN]);
}

 //passengers functions. The passengers are drwan on the canvas uisng this.     
int m1;
void
man1 ()
{
  DrawCircle (m1, 0 + 20, 5, colors[RED]);
  DrawLine (m1, 0, m1, 0 + 20, 2, colors[RED]);
  glutPostRedisplay ();
}

int m2;
void
man2 ()
{
  DrawCircle (550, m2 + 20, 5, colors[BLACK]);
  DrawLine (550, m2, 550, m2 + 20, 2, colors[BLACK]);
}

int m3;
void
man3 ()
{
  DrawCircle (130, m3 + 20, 5, colors[WHITE]);
  DrawLine (130, m3, 130, m3 + 20, 2, colors[WHITE]);
}

int m4;
void
man4 ()
{

  DrawCircle (370, m4 + 20, 5, colors[BLUE]);
  DrawLine (370, m4, 370, m4 + 20, 2, colors[BLUE]);
}

// drop point functions. The box will appear on the canvas where passenger needs to be dropped
void
drop1 ()
{
  DrawSquare (110, 250, 30, colors[YELLOW]);
  glutPostRedisplay ();
}

void
drop2 ()
{
  DrawSquare (10, 540, 30, colors[BLACK]);
}

void
drop3 ()
{
  DrawSquare (560, 520, 30, colors[WHITE]);
}

void
drop4 ()
{
  DrawSquare (157, 520, 30, colors[BLUE]);
}

 // box obstacle function, to draw boxes on the canvas   
void
box_a ()
{
  DrawSquare (420, 490, 30, colors[YELLOW]);
}

void
box_b ()
{
  DrawSquare (120, 110, 30, colors[YELLOW]);
}

void
box_c ()
{
  DrawSquare (270, 530, 30, colors[YELLOW]);
}

bool fl;

void
GameDisplay ()
  /**/
{
  // set the background color using function glClearColor.
  // to change the background play with the red, green and blue values below.
  // Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

  glClearColor (1 /*Red Component */ , 0.411764705882353,	//148.0/255/*Green Component*/,
		0.705882352941177 /*Blue Component */ , 0 /*Alpha component */ );	// Red==Green==Blue==1 --> White Colour


  glClear (GL_COLOR_BUFFER_BIT);	//Update the colors

  DrawLine (0, 601, 600, 601, 2, colors[BLACK]);
  DrawLine (30, 0, 30, 600, 1, colors[AQUA]);
  DrawLine (60, 0, 60, 600, 1, colors[AQUA]);
  DrawLine (90, 0, 90, 600, 1, colors[AQUA]);
  DrawLine (120, 0, 120, 600, 1, colors[AQUA]);
  DrawLine (150, 0, 150, 600, 1, colors[AQUA]);
  DrawLine (180, 0, 180, 600, 1, colors[AQUA]);
  DrawLine (210, 0, 210, 600, 1, colors[AQUA]);
  DrawLine (240, 0, 240, 600, 1, colors[AQUA]);
  DrawLine (270, 0, 270, 600, 1, colors[AQUA]);
  DrawLine (300, 0, 300, 600, 1, colors[AQUA]);
  DrawLine (330, 0, 330, 600, 1, colors[AQUA]);
  DrawLine (360, 0, 360, 600, 1, colors[AQUA]);
  DrawLine (390, 0, 390, 600, 1, colors[AQUA]);
  DrawLine (420, 0, 420, 600, 1, colors[AQUA]);
  DrawLine (450, 0, 450, 600, 1, colors[AQUA]);
  DrawLine (480, 0, 480, 600, 1, colors[AQUA]);
  DrawLine (510, 0, 510, 600, 1, colors[AQUA]);
  DrawLine (540, 0, 540, 600, 1, colors[AQUA]);
  DrawLine (570, 0, 570, 600, 1, colors[AQUA]);
  DrawLine (600, 0, 600, 600, 1, colors[AQUA]);

  //Display Score 
  DrawString (10, 610, "Score=" + to_string (score), colors[WHITE]);
  DrawString (400, 610, "Timer=" + to_string (timercount), colors[WHITE]);
  //display other cars
  drawCar1 ();
  drawCar2 ();
  //display buildings
  drawBuilding ();
  //display tree;
  Tree_a ();
  Tree_b ();
  Tree_c ();
  Tree_d ();
  //display box;
  box_a ();
  box_b ();
  box_c ();
  //display man
  //to pick and drop the passenger.
  if (flag_A)
    {
      man1 ();
      glutPostRedisplay ();
    }
  else if (!flag_A)
    {
      drop1 ();
      glutPostRedisplay ();
    }

  if (flag_B)
    {
      man2 ();
      glutPostRedisplay ();
    }
  else if (!flag_B)
    {
      drop2 ();
      glutPostRedisplay ();
    }
  if (flag_C)
    {
      man3 ();
      glutPostRedisplay ();
    }
  else if (!flag_C)
    {
      drop3 ();
      glutPostRedisplay ();
    }
  if (flag_D)
    {
      man4 ();
      glutPostRedisplay ();
    }
  else if (!flag_D)
    {
      drop4 ();
      glutPostRedisplay ();
    }
  // display car
  if (fl == true)
    drawCarY ();
  else
    drawCarR ();

  //display menu   
  if (flag_M == true)
    {
      Menu ();
    }

  glutSwapBuffers ();		// do not modify this line..

//}
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void
NonPrintableKeys (int key, int x, int y)
{
  if (key ==
      GLUT_KEY_LEFT
      /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key */ )
    {
      // what to do when left key is pressed...
      if (fl == true)
	{
	  xI -= 5;
	}
      else
	{
	  xI -= 2;
	}

    }
  else if (key ==
	   GLUT_KEY_RIGHT
	   /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key */
	   )
    {
      if (fl == true)
	{
	  xI += 5;
	}
      else
	{
	  xI += 2;
	}

    }
  else if (key ==
	   GLUT_KEY_UP
	   /*GLUT_KEY_UP is constant and contains ASCII for up arrow key */ )
    {

      if (fl == true)
	{
	  yI += 5;
	}
      else
	{
	  yI += 2;
	}
    }

  else if (key ==
	   GLUT_KEY_DOWN
	   /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key */
	   )
    {

      if (fl == true)
	{
	  yI -= 5;
	}
      else
	{
	  yI -= 2;
	}
    }
  if (xI < 0)
    {
      xI += 5;

    }
  else if (xI > 570)
    {
      xI -= 13;
    }
  else if (yI < 0)
    {
      yI += 13;

    }
  else if (yI > 570)
    {
      yI -= 13;
    }

  /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
   * this function*/
  glutPostRedisplay ();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

void
PrintableKeys (unsigned char key, int x, int y)
{
  if (key == 27 /* Escape key ASCII */ )
    {
      exit (1);			// exit the program when escape key is pressed.
    }

  if (key == 'b' || key == 'B')	//Key for placing the bomb
    {
      //do something if b is pressed
      cout << "b pressed" << endl;
    }

  if (key == 'y' || key == 89)	//Key for placing the bomb
    {
      //do something if y is pressed
      fl = true;
      flag_M = false;

      cout << "y pressed" << endl;
    }
  if (key == 'r' || key == 114)	//Key for placing the bomb
    {
      //do something if r is pressed
      fl = false;
      flag_M = false;
      cout << "r pressed" << endl;
    }

  if (key == 'm' || key == 110)	//Key for placing the bomb
    {
      //do something if m is pressed

      flag_M = true;
      if (key >= 'a' && key <= 'z' || key >= 'A' && key <= 'Z')
	{
	  cin >> name;

	  cout << "m pressed" << endl;
	}
    }

  if (key == 32 || key == ' ')	//Key for picking passenger
    {
      //to pick up the passenger
      if ((flag_A) && (flag_B) && (flag_C) && (flag_D))
	{
	  if (((xI >= m1 - 30) && (xI <= m1 + 30))
	      && ((yI >= 0) && (yI <= 45)))
	    {

	      flag_A = false;
	    }
	  if (((xI >= 510) && (xI <= 600))
	      && ((yI >= m2 - 50) && (yI <= m2 + 50)))
	    {

	      flag_B = false;
	    }
	  if (((xI >= 100) && (xI <= 160))
	      && ((yI >= m3 - 30) && (yI <= m3 + 30)))
	    {

	      flag_C = false;
	    }
	  if (((xI >= 340) && (xI <= 400))
	      && ((yI >= m4 - 30) && (yI <= m4 + 30)))
	    {

	      flag_D = false;
	    }
	}
      //to drop the passenger and generation of random new passenger spot     
      else if (!flag_A)
	{
	  if (((xI >= 80) && (xI <= 140)) && ((yI >= 200) && (yI <= 300)))
	    {

	      flag_A = true;
	      score += 10;
	      m1 = GetRandInRange (180, 390);

	      if (score >= 100)
		{
		  exit (1);
		}
	    }
	}
      else if (!flag_B)
	{
	  if (((xI >= 0) && (xI <= 40)) && ((yI >= 510) && (yI <= 570)))
	    {

	      flag_B = true;
	      score += 10;
	      m2 = GetRandInRange (210, 590);
	      if (score >= 100)
		{
		  exit (1);
		}
	    }
	}
      else if (!flag_C)
	{
	  if (((xI >= 530) && (xI <= 590)) && ((yI >= 490) && (yI <= 550)))
	    {

	      flag_C = true;
	      score += 10;
	      m3 = GetRandInRange (215, 430);
	      if (score >= 100)
		{
		  exit (1);
		}
	    }
	}
      else if (!flag_D)
	{
	  if (((xI >= 127) && (xI <= 187)) && ((yI >= 490) && (yI <= 550)))
	    {

	      flag_D = true;
	      score += 10;
	      m4 = GetRandInRange (300, 470);
	      if (score >= 100)
		{
		  exit (1);
		}
	    }
	}
    }
  // for over taking cars
  else if (((xI >= 300) && (xI <= 320)) && ((yI >= 570) && (yI <= 409)))
    {
      if (yI != c2)
	{
	  score += 1;
	  if (score >= 100)
	    {
	      exit (1);
	    }
	}
      else
	{
	  score -= 2;
	  if (score >= 100)
	    {
	      exit (1);
	    }
	}
    }
  else if (((xI >= 570) && (xI <= 590)) && ((yI >= 160) && (yI <= 500)))
    {
      if (yI != d2)
	{
	  score += 1;
	  if (score >= 100)
	    {
	      exit (1);
	    }
	}
      else
	{
	  score -= 2;
	  if (score >= 100)
	    {
	      exit (1);
	    }
	}
    }
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void
Timer (int m)
{


  // implement your functionality here

  self_destruct ();
  moveCar1 ();
  moveCar2 ();

  // once again we tell the library to call our Timer function after next 1000/FPS
  glutTimerFunc (100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void
MousePressedAndMoved (int x, int y)
{
  cout << x << " " << y << endl;
  glutPostRedisplay ();
}

void
MouseMoved (int x, int y)
{
  //cout << x << " " << y << endl;
  glutPostRedisplay ();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void
MouseClicked (int button, int state, int x, int y)
{

  if (button == GLUT_LEFT_BUTTON)	// dealing only with left button
    {
      cout << GLUT_DOWN << " " << GLUT_UP << endl;

    }
  else if (button == GLUT_RIGHT_BUTTON)	// dealing with right button
    {
      cout << "Right Button Pressed" << endl;

    }
  glutPostRedisplay ();
}

/*
 * our gateway main function
 * */
int
main (int argc, char *argv[])
{

  int width = 600, height = 640;	// i have set my window size to be 800 x 600

  InitRandomizer ();		// seed the random number generator...
  glutInit (&argc, argv);	// initialize the graphics library...
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);	// we will be using color display mode
  glutInitWindowPosition (50, 50);	// set the initial position of our window
  glutInitWindowSize (width, height);	// set the size of our window
  glutCreateWindow ("Rush Hour by Manahil Kamran");	// set the title of our game window
  SetCanvasSize (width, height);	// set the number of pixels...

  // Register your functions to the library,
  // you are telling the library names of function to call for different tasks.
  //glutDisplayFunc();
  // tell library which function to call for drawing Canvas.


  glutDisplayFunc (GameDisplay);	// tell library which function to call for drawing Canvas.

  glutSpecialFunc (NonPrintableKeys);	// tell library which function to call for non-printable ASCII characters
  glutKeyboardFunc (PrintableKeys);	// tell library which function to call for printable ASCII characters
  // This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
  glutTimerFunc (1000.0, Timer, 0);

  glutMouseFunc (MouseClicked);
  glutPassiveMotionFunc (MouseMoved);	// Mouse
  glutMotionFunc (MousePressedAndMoved);	// Mouse

  // random function for passengers

  m1 = GetRandInRange (180, 390);
  m2 = GetRandInRange (210, 590);
  m3 = GetRandInRange (215, 430);
  m4 = GetRandInRange (300, 470);

  // now handle the control to library and it will call our registered functions when
  // it deems necessary...
  glutMainLoop ();


  return 1;
}
#endif /* RushHour_CPP_ */

