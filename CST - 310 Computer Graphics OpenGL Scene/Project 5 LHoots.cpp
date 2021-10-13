//Written by Logan Hoots
//Project 5: Render Scene with Primitives
//Due: 3/1/2020

//Include libraries
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//Function to create shading on the wall
void wall_shading()
{
    //Lighter Shading
    glColor3f(0.654f, 0.501f, 0.349f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(0, 0); //First QUAD coordinate
        glVertex2f(260, 0); //Second QUAD coordinate
        glVertex2f(260, 600); //Third QUAD coordinate
        glVertex2f(0, 600); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.835f, 0.717f, 0.584f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(260, 0); //First QUAD coordinate
        glVertex2f(360, 0); //Second QUAD coordinate
        glVertex2f(360, 600); //Third QUAD coordinate
        glVertex2f(260, 600); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Lighter Shading
    glColor3f(0.380f, 0.282f, 0.164f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(575, 505); //First POLYGON coordinate
        glVertex2f(655, 505); //Second POLYGON coordinate
        glVertex2f(680, 310); //Third POLYGON coordinate
        glVertex2f(500, 310); //Fourth POLYGON coordinate
        glVertex2f(500, 340); //Fifth POLYGON  coordinate
        glVertex2f(575, 340); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(675, 300); //First POLYGON coordinate
        glVertex2f(685, 300); //Second POLYGON coordinate
        glVertex2f(800, 265); //Third POLYGON coordinate
        glVertex2f(800, 0); //Fourth POLYGON coordinate
        glVertex2f(675, 0); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Darker Shading
    glColor3f(0.333f, 0.239f, 0.129f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(675, 300); //First POLYGON coordinate
        glVertex2f(685, 300); //Second POLYGON coordinate
        glVertex2f(725, 286); //Third POLYGON coordinate
        glVertex2f(725, 0); //Fourth POLYGON coordinate
        glVertex2f(675, 0); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(575, 505); //First POLYGON coordinate
        glVertex2f(605, 505); //Second POLYGON coordinate
        glVertex2f(625, 310); //Third POLYGON coordinate
        glVertex2f(500, 310); //Fourth POLYGON coordinate
        glVertex2f(500, 340); //Fifth POLYGON  coordinate
        glVertex2f(575, 340); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Floor Board
    glColor3f(0.588f, 0.482f, 0.415f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(800, 38); //First QUAD coordinate
        glVertex2f(800, 0); //Second QUAD coordinate
        glVertex2f(0, 0); //Third QUAD coordinate
        glVertex2f(0, 38); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Darker Shading
    glColor3f(0.345f, 0.254f, 0.133f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(180, 370); //First QUAD coordinate
        glVertex2f(215, 370); //Second QUAD coordinate
        glVertex2f(215, 310); //Third QUAD coordinate
        glVertex2f(180, 310); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //This is the shading for the plant
    glColor3f(0.556f, 0.427f, 0.305f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(43, 528); //First POLYGON coordinate
        glVertex2f(65, 522); //Second POLYGON coordinate
        glVertex2f(90, 500); //Third POLYGON coordinate
        glVertex2f(90, 422); //Fourth POLYGON coordinate
        glVertex2f(70, 422); //Fifth POLYGON  coordinate
        glVertex2f(47, 439); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the darker part of the shelves
void shelves_1()
{
    //Shapes to create the darker part of the shelves
    glColor3f(0.360f, 0.282f, 0.215f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(100, 0); //First QUAD coordinate
        glVertex2f(100, 300); //Second QUAD coordinate
        glVertex2f(110, 300); //Third QUAD coordinate
        glVertex2f(110, 0); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(95, 300); //First QUAD coordinate
        glVertex2f(95, 310); //Second QUAD coordinate
        glVertex2f(120, 310); //Third QUAD coordinate
        glVertex2f(120, 300); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(110, 215); //First QUAD coordinate
        glVertex2f(110, 205); //Second QUAD coordinate
        glVertex2f(125, 205); //Third QUAD coordinate
        glVertex2f(125, 215); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(110, 125); //First QUAD coordinate
        glVertex2f(110, 115); //Second QUAD coordinate
        glVertex2f(125, 115); //Third QUAD coordinate
        glVertex2f(125, 125); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(110, 30); //First QUAD coordinate
        glVertex2f(110, 10); //Second QUAD coordinate
        glVertex2f(125, 10); //Third QUAD coordinate
        glVertex2f(125, 30); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(110, 10); //First QUAD coordinate
        glVertex2f(110, 0); //Second QUAD coordinate
        glVertex2f(115, 0); //Third QUAD coordinate
        glVertex2f(115, 10); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(110, 300); //First QUAD coordinate
        glVertex2f(110, 295); //Second QUAD coordinate
        glVertex2f(125, 295); //Third QUAD coordinate
        glVertex2f(125, 300); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(380, 0); //First QUAD coordinate
        glVertex2f(380, 10); //Second QUAD coordinate
        glVertex2f(410, 10); //Third QUAD coordinate
        glVertex2f(410, 0); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
  
    //Creates the middle peg under the TV stand
    glColor3f(0.078f, 0.023f, 0.023f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(380, 0); //First QUAD coordinate
        glVertex2f(380, 10); //Second QUAD coordinate
        glVertex2f(115, 10); //Third QUAD coordinate
        glVertex2f(115, 0); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(410, 0); //First QUAD coordinate
        glVertex2f(410, 10); //Second QUAD coordinate
        glVertex2f(665, 10); //Third QUAD coordinate
        glVertex2f(665, 0); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the light part of the shelves
void shelves_2()
{
    //Shapes to create the lighter part of the tv stand
    glColor3f(0.745f, 0.619f, 0.529f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(665, 0); //First QUAD coordinate
        glVertex2f(665, 300); //Second QUAD coordinate
        glVertex2f(675, 300); //Third QUAD coordinate
        glVertex2f(675, 0); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(390, 300); //First QUAD coordinate
        glVertex2f(390, 10); //Second QUAD coordinate
        glVertex2f(400, 10); //Third QUAD coordinate
        glVertex2f(400, 300); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(120, 300); //First QUAD coordinate
        glVertex2f(120, 310); //Second QUAD coordinate
        glVertex2f(680, 310); //Third QUAD coordinate
        glVertex2f(680, 300); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(125, 300); //First QUAD coordinate
        glVertex2f(125, 295); //Second QUAD coordinate
        glVertex2f(665, 295); //Third QUAD coordinate
        glVertex2f(665, 300); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(125, 215); //First QUAD coordinate
        glVertex2f(125, 205); //Second QUAD coordinate
        glVertex2f(665, 205); //Third QUAD coordinate
        glVertex2f(665, 215); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(125, 125); //First QUAD coordinate
        glVertex2f(125, 115); //Second QUAD coordinate
        glVertex2f(390, 115); //Third QUAD coordinate
        glVertex2f(390, 125); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(400, 100); //First QUAD coordinate
        glVertex2f(400, 90); //Second QUAD coordinate
        glVertex2f(665, 90); //Third QUAD coordinate
        glVertex2f(665, 100); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(665, 30); //First QUAD coordinate
        glVertex2f(665, 10); //Second QUAD coordinate
        glVertex2f(125, 10); //Third QUAD coordinate
        glVertex2f(125, 30); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(660, 10); //First QUAD coordinate
        glVertex2f(660, 0); //Second QUAD coordinate
        glVertex2f(665, 0); //Third QUAD coordinate
        glVertex2f(665, 10); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the depth on the first left shelf
void shelf_depth_1()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(390, 215); //First QUAD coordinate
        glVertex2f(390, 225); //Second QUAD coordinate
        glVertex2f(110, 225); //Third QUAD coordinate
        glVertex2f(110, 215); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.098f, 0.066f, 0.043f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(110, 295); //First POLYGON coordinate
        glVertex2f(150, 295); //Second POLYGON coordinate
        glVertex2f(150, 225); //Third POLYGON coordinate
        glVertex2f(210, 225); //Fourth POLYGON coordinate
        glVertex2f(110, 215); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.258f, 0.196f, 0.133f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(150, 295); //First POLYGON coordinate
        glVertex2f(390, 295); //Second POLYGON coordinate
        glVertex2f(390, 260); //Third POLYGON coordinate
        glVertex2f(210, 260); //Fourth POLYGON coordinate
        glVertex2f(210, 225); //Fifth POLYGON  coordinate
        glVertex2f(150, 225); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.596f, 0.505f, 0.396f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(210, 260); //First QUAD coordinate
        glVertex2f(210, 225); //Second QUAD coordinate
        glVertex2f(390, 225); //Third QUAD coordinate
        glVertex2f(390, 260); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the depth on the first right shelf
void shelf_depth_2()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(665, 215); //First QUAD coordinate
        glVertex2f(665, 225); //Second QUAD coordinate
        glVertex2f(400, 225); //Third QUAD coordinate
        glVertex2f(400, 215); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.098f, 0.066f, 0.043f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(400, 295); //First POLYGON coordinate
        glVertex2f(440, 295); //Second POLYGON coordinate
        glVertex2f(440, 225); //Third POLYGON coordinate
        glVertex2f(500, 225); //Fourth POLYGON coordinate
        glVertex2f(400, 215); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.380f, 0.317f, 0.219f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(665, 215); //First POLYGON coordinate
        glVertex2f(645, 225); //Second POLYGON coordinate
        glVertex2f(645, 295); //Third POLYGON coordinate
        glVertex2f(665, 295); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.141f, 0.086f, 0.035f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(440, 295); //First POLYGON coordinate
        glVertex2f(665, 295); //Second POLYGON coordinate
        glVertex2f(645, 260); //Third POLYGON coordinate
        glVertex2f(500, 260); //Fourth POLYGON coordinate
        glVertex2f(500, 225); //Fifth POLYGON  coordinate
        glVertex2f(440, 225); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.419f, 0.329f, 0.254f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(500, 260); //First QUAD coordinate
        glVertex2f(500, 225); //Second QUAD coordinate
        glVertex2f(645, 225); //Third QUAD coordinate
        glVertex2f(645, 260); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the depth on the second left shelf
void shelf_depth_3()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(390, 125); //First QUAD coordinate
        glVertex2f(390, 135); //Second QUAD coordinate
        glVertex2f(110, 135); //Third QUAD coordinate
        glVertex2f(110, 125); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.098f, 0.066f, 0.043f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(110, 205); //First POLYGON coordinate
        glVertex2f(150, 205); //Second POLYGON coordinate
        glVertex2f(150, 135); //Third POLYGON coordinate
        glVertex2f(210, 135); //Fourth POLYGON coordinate
        glVertex2f(110, 125); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.258f, 0.196f, 0.133f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(150, 205); //First POLYGON coordinate
        glVertex2f(390, 205); //Second POLYGON coordinate
        glVertex2f(390, 170); //Third POLYGON coordinate
        glVertex2f(210, 170); //Fourth POLYGON coordinate
        glVertex2f(210, 135); //Fifth POLYGON  coordinate
        glVertex2f(150, 135); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.596f, 0.505f, 0.396f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(210, 170); //First QUAD coordinate
        glVertex2f(210, 135); //Second QUAD coordinate
        glVertex2f(390, 135); //Third QUAD coordinate
        glVertex2f(390, 170); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the depth on the second right shelf
void shelf_depth_4()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.329f, 0.262f, 0.184f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(665, 100); //First QUAD coordinate
        glVertex2f(665, 115); //Second QUAD coordinate
        glVertex2f(400, 115); //Third QUAD coordinate
        glVertex2f(400, 100); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.098f, 0.066f, 0.043f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(500, 205); //First POLYGON coordinate
        glVertex2f(500, 115); //Second POLYGON coordinate
        glVertex2f(400, 100); //Third POLYGON coordinate
        glVertex2f(400, 205); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.458f, 0.364f, 0.258f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(665, 100); //First POLYGON coordinate
        glVertex2f(645, 115); //Second POLYGON coordinate
        glVertex2f(645, 205); //Third POLYGON coordinate
        glVertex2f(665, 205); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.145f, 0.090f, 0.039f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(440, 205); //First POLYGON coordinate
        glVertex2f(665, 205); //Second POLYGON coordinate
        glVertex2f(645, 170); //Third POLYGON coordinate
        glVertex2f(500, 170); //Fourth POLYGON coordinate
        glVertex2f(500, 115); //Fifth POLYGON  coordinate
        glVertex2f(440, 115); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.429f, 0.349f, 0.254f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(500, 170); //First QUAD coordinate
        glVertex2f(500, 115); //Second QUAD coordinate
        glVertex2f(645, 115); //Third QUAD coordinate
        glVertex2f(645, 170); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the depth on the last left shelf
void shelf_depth_5()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(390, 30); //First QUAD coordinate
        glVertex2f(390, 50); //Second QUAD coordinate
        glVertex2f(110, 50); //Third QUAD coordinate
        glVertex2f(110, 30); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.098f, 0.066f, 0.043f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(110, 115); //First POLYGON coordinate
        glVertex2f(150, 115); //Second POLYGON coordinate
        glVertex2f(150, 50); //Third POLYGON coordinate
        glVertex2f(210, 50); //Fourth POLYGON coordinate
        glVertex2f(110, 30); //Fifth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.196f, 0.141f, 0.098f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(150, 115); //First POLYGON coordinate
        glVertex2f(390, 115); //Second POLYGON coordinate
        glVertex2f(390, 50); //Third POLYGON coordinate
        glVertex2f(150, 50); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.086f, 0.050f, 0.031f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(215, 115); //First QUAD coordinate
        glVertex2f(347, 115); //Second QUAD coordinate
        glVertex2f(347, 50); //Third QUAD coordinate
        glVertex2f(215, 50); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
}

//Function to create the depth on the last right shelf
void shelf_depth_6()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.329f, 0.262f, 0.184f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(665, 30); //First QUAD coordinate
        glVertex2f(665, 50); //Second QUAD coordinate
        glVertex2f(400, 50); //Third QUAD coordinate
        glVertex2f(400, 30); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.098f, 0.066f, 0.043f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(500, 90); //First POLYGON coordinate
        glVertex2f(500, 50); //Second POLYGON coordinate
        glVertex2f(400, 30); //Third POLYGON coordinate
        glVertex2f(400, 90); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.458f, 0.364f, 0.258f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(665, 30); //First POLYGON coordinate
        glVertex2f(645, 50); //Second POLYGON coordinate
        glVertex2f(645, 90); //Third POLYGON coordinate
        glVertex2f(665, 90); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.145f, 0.090f, 0.039f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(440, 90); //First POLYGON coordinate
        glVertex2f(665, 90); //Second POLYGON coordinate
        glVertex2f(645, 70); //Third POLYGON coordinate
        glVertex2f(500, 70); //Fourth POLYGON coordinate
        glVertex2f(500, 50); //Fifth POLYGON  coordinate
        glVertex2f(440, 50); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.429f, 0.349f, 0.254f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(500, 70); //First QUAD coordinate
        glVertex2f(500, 50); //Second QUAD coordinate
        glVertex2f(645, 50); //Third QUAD coordinate
        glVertex2f(645, 70); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the TV
void tv()
{
    //Frame
    glColor3f(0.133f, 0.098f, 0.109f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(240, 535); //First QUAD coordinate
        glVertex2f(575, 535); //Second QUAD coordinate
        glVertex2f(575, 340); //Third QUAD coordinate
        glVertex2f(240, 340); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Screen
    glColor3f(0.333f, 0.282f, 0.250f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(245, 530); //First QUAD coordinate
        glVertex2f(570, 530); //Second QUAD coordinate
        glVertex2f(570, 345); //Third QUAD coordinate
        glVertex2f(245, 345); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
        
    //Shading
    glColor3f(0.258f, 0.219f, 0.184f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(375, 530); //First QUAD coordinate
        glVertex2f(570, 530); //Second QUAD coordinate
        glVertex2f(570, 345); //Third QUAD coordinate
        glVertex2f(375, 345); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.133f, 0.098f, 0.109f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(325, 310); //First QUAD coordinate
        glVertex2f(500, 310); //Second QUAD coordinate
        glVertex2f(500, 340); //Third QUAD coordinate
        glVertex2f(325, 340); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates

    //Lights
    glColor3f(1.0f, 1.0f, 0.952f); //sets color
    glPointSize(2.0); //Sets the point size
    glBegin(GL_POINTS); //Creates an OpenGL POINTS shape
        glVertex2f(405, 342); //Creates a POINTS SHAPE at this coordinate
        glVertex2f(408, 342); //Creates a POINTS SHAPE at this coordinate
    glEnd(); //Makes it so no more POINTS are created
}

//Function to create the stuff on the top of the tv stand
void stuff_on_top()
{
    //Creates the object on the left
    glColor3f(0.168f, 0.109f, 0.082f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(140, 310); //First POLYGON coordinate
        glVertex2f(140, 375); //Second POLYGON coordinate
        glVertex2f(150, 385); //Third POLYGON coordinate
        glVertex2f(180, 385); //Fourth POLYGON coordinate
        glVertex2f(180, 310); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.258f, 0.215f, 0.200f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(145, 375); //First QUAD coordinate
        glVertex2f(170, 375); //Second QUAD coordinate
        glVertex2f(170, 310); //Third QUAD coordinate
        glVertex2f(145, 310); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.368f, 0.329f, 0.321f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(175, 375); //First QUAD coordinate
        glVertex2f(170, 375); //Second QUAD coordinate
        glVertex2f(170, 310); //Third QUAD coordinate
        glVertex2f(175, 310); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Creates the object on the right bottom
    glColor3f(0.090f, 0.078f, 0.058f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(195, 325); //First QUAD coordinate
        glVertex2f(290, 325); //Second QUAD coordinate
        glVertex2f(290, 310); //Third QUAD coordinate
        glVertex2f(195, 310); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.552f, 0.470f, 0.388f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(300, 323); //First POLYGON coordinate
        glVertex2f(290, 325); //Second POLYGON coordinate
        glVertex2f(290, 310); //Third POLYGON coordinate
        glVertex2f(300, 310); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.360f, 0.356f, 0.376f); //sets color
    glPointSize(2.0); //Sets the point size
    glBegin(GL_POINTS); //Creates an OpenGL POINTS shape
        glVertex2f(280, 320); //Creates a POINTS SHAPE at this coordinate
        glVertex2f(286, 320); //Creates a POINTS SHAPE at this coordinate
    glEnd(); //Makes it so no more POINTS are created
    
    //Creates the object on the right top
    glColor3f(0.058f, 0.027f, 0.019f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(250, 325); //First QUAD coordinate
        glVertex2f(220, 325); //Second QUAD coordinate
        glVertex2f(220, 335); //Third QUAD coordinate
        glVertex2f(250, 335); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.360f, 0.337f, 0.345f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(224, 325); //First QUAD coordinate
        glVertex2f(222, 325); //Second QUAD coordinate
        glVertex2f(222, 335); //Third QUAD coordinate
        glVertex2f(224, 335); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
}

//Function to create the stuff on the first left shelf
void stuff_on_shelf_1()
{
    //Creates the main shape
    glColor3f(1.0f, 1.0f, 0.984f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(210, 280); //First QUAD coordinate
        glVertex2f(250, 280); //Second QUAD coordinate
        glVertex2f(250, 220); //Third QUAD coordinate
        glVertex2f(210, 220); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.541f, 0.443f, 0.427f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(215, 275); //First QUAD coordinate
        glVertex2f(245, 275); //Second QUAD coordinate
        glVertex2f(245, 225); //Third QUAD coordinate
        glVertex2f(215, 225); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(1.0f, 1.0f, 0.984f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(218, 272); //First QUAD coordinate
        glVertex2f(242, 272); //Second QUAD coordinate
        glVertex2f(242, 228); //Third QUAD coordinate
        glVertex2f(218, 228); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Shading
    glColor3f(0.105f, 0.070f, 0.050f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(260, 260); //First POLYGON coordinate
        glVertex2f(300, 260); //Second POLYGON coordinate
        glVertex2f(310, 255); //Third POLYGON coordinate
        glVertex2f(310, 225); //Fourth POLYGON coordinate
        glVertex2f(250, 220); //Fifth POLYGON  coordinate
        glVertex2f(260, 225); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.235f, 0.172f, 0.109f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(280, 260); //First POLYGON coordinate
        glVertex2f(300, 260); //Second POLYGON coordinate
        glVertex2f(310, 255); //Third POLYGON coordinate
        glVertex2f(310, 225); //Fourth POLYGON coordinate
        glVertex2f(280, 225); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.384f, 0.345f, 0.305f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(260, 260); //First POLYGON coordinate
        glVertex2f(250, 260); //Second POLYGON coordinate
        glVertex2f(250, 220); //Third POLYGON coordinate
        glVertex2f(260, 225); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.105f, 0.043f, 0.047f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(260, 260); //First POLYGON coordinate
        glVertex2f(250, 260); //Second POLYGON coordinate
        glVertex2f(250, 280); //Third POLYGON coordinate
        glVertex2f(260, 275); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the stuff on the first right shelf
void stuff_on_shelf_2()
{
    //Creates the wooden thing on the shelf
    glColor3f(0.141f, 0.086f, 0.035f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(620, 260); //First POLYGON coordinate
        glVertex2f(645, 260); //Second POLYGON coordinate
        glVertex2f(655, 265); //Third POLYGON coordinate
        glVertex2f(655, 220); //Fourth POLYGON coordinate
        glVertex2f(620, 218); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.619f, 0.435f, 0.262f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(620, 218); //First POLYGON coordinate
        glVertex2f(620, 278); //Second POLYGON coordinate
        glVertex2f(555, 280); //Third POLYGON coordinate
        glVertex2f(555, 220); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.756f, 0.505f, 0.254f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(567, 272); //First POLYGON coordinate
        glVertex2f(608, 270); //Second POLYGON coordinate
        glVertex2f(608, 264); //Third POLYGON coordinate
        glVertex2f(616, 253); //Fourth POLYGON coordinate
        glVertex2f(616, 240); //Fifth POLYGON  coordinate
        glVertex2f(608, 230); //Sixth POLYGON coordinate
        glVertex2f(608, 223); //Seventh POLYGON coordinate
        glVertex2f(566, 225); //Eigth POLYGON coordinate
        glVertex2f(566, 232); //Ninth POLYGON coordinate
        glVertex2f(560, 241); //Tenth POLYGON coordinate
        glVertex2f(560, 258); //Eleventh POLYGON coordinate
        glVertex2f(567, 266); //Twelveth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Shading
    glColor3f(0.239f, 0.168f, 0.121f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(620, 218); //First POLYGON coordinate
        glVertex2f(623, 220); //Second POLYGON coordinate
        glVertex2f(623, 276); //Third POLYGON coordinate
        glVertex2f(620, 280); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the stuff on the second left shelf
void stuff_on_shelf_3()
{
    //First book from right
    glColor3f(0.780f, 0.725f, 0.682f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(390, 125); //First QUAD coordinate
        glVertex2f(390, 200); //Second QUAD coordinate
        glVertex2f(385, 200); //Third QUAD coordinate
        glVertex2f(385, 125); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Second Book
    glColor3f(0.200f, 0.184f, 0.188f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(375, 127); //First QUAD coordinate
        glVertex2f(375, 182); //Second QUAD coordinate
        glVertex2f(385, 182); //Third QUAD coordinate
        glVertex2f(385, 127); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Third Book
    glColor3f(0.882f, 0.411f, 0.349f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(375, 125); //First QUAD coordinate
        glVertex2f(375, 194); //Second QUAD coordinate
        glVertex2f(367, 194); //Third QUAD coordinate
        glVertex2f(367, 125); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.964f, 0.937f, 0.913f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(375, 152); //First QUAD coordinate
        glVertex2f(375, 178); //Second QUAD coordinate
        glVertex2f(367, 178); //Third QUAD coordinate
        glVertex2f(367, 152); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Fourth book
    glColor3f(0.588f, 0.337f, 0.298f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(362, 125); //First QUAD coordinate
        glVertex2f(362, 196); //Second QUAD coordinate
        glVertex2f(367, 196); //Third QUAD coordinate
        glVertex2f(367, 125); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(1.0f, 0.870f, 0.866f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(362, 151); //First QUAD coordinate
        glVertex2f(362, 180); //Second QUAD coordinate
        glVertex2f(367, 180); //Third QUAD coordinate
        glVertex2f(367, 151); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates

    //Fifth Book
    glColor3f(0.952f, 0.843f, 0.839f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(362, 128); //First QUAD coordinate
        glVertex2f(362, 194); //Second QUAD coordinate
        glVertex2f(358, 194); //Third QUAD coordinate
        glVertex2f(358, 128); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Sixth Book
    glColor3f(0.529f, 0.556f, 0.768f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(352, 128); //First QUAD coordinate
        glVertex2f(352, 195); //Second QUAD coordinate
        glVertex2f(358, 195); //Third QUAD coordinate
        glVertex2f(358, 128); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Seventh Book
    glColor3f(1.0f, 0.976f, 0.992f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(352, 127); //First QUAD coordinate
        glVertex2f(352, 196); //Second QUAD coordinate
        glVertex2f(347, 196); //Third QUAD coordinate
        glVertex2f(347, 127); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.132f, 0.227f, 0.219f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(352, 133); //First POLYGON coordinate
        glVertex2f(352, 162); //Second POLYGON coordinate
        glVertex2f(347, 167); //Third POLYGON coordinate
        glVertex2f(347, 130); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates

    //XBOX
    glColor3f(0.043f, 0.043f, 0.050f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(142, 153); //First POLYGON coordinate
        glVertex2f(142, 132); //Second POLYGON coordinate
        glVertex2f(145, 125); //Third POLYGON coordinate
        glVertex2f(261, 125); //Fourth POLYGON coordinate
        glVertex2f(261, 153); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.203f, 0.188f, 0.192f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(142, 153); //First QUAD coordinate
        glVertex2f(142, 132); //Second QUAD coordinate
        glVertex2f(201, 132); //Third QUAD coordinate
        glVertex2f(201, 153); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.090f, 0.062f, 0.039f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(261, 153); //First POLYGON coordinate
        glVertex2f(261, 125); //Second POLYGON coordinate
        glVertex2f(268, 135); //Third POLYGON coordinate
        glVertex2f(268, 163); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.125f, 0.121f, 0.141f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(142, 153); //First POLYGON coordinate
        glVertex2f(149, 163); //Second POLYGON coordinate
        glVertex2f(268, 163); //Third POLYGON coordinate
        glVertex2f(261, 153); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.0f, 0.0f, 0.0f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(146, 144); //First QUAD coordinate
        glVertex2f(146, 142); //Second QUAD coordinate
        glVertex2f(195, 142); //Third QUAD coordinate
        glVertex2f(195, 144); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Shading
    glColor3f(0.192f, 0.145f, 0.098f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(261, 125); //First POLYGON coordinate
        glVertex2f(318, 132); //Second POLYGON coordinate
        glVertex2f(318, 135); //Third POLYGON coordinate
        glVertex2f(268, 135); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.149f, 0.101f, 0.039f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(268, 156); //First POLYGON coordinate
        glVertex2f(286, 156); //Second POLYGON coordinate
        glVertex2f(318, 135); //Third POLYGON coordinate
        glVertex2f(268, 135); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Lights
    glColor3f(0.450f, 0.443f, 0.454f); //sets color
    glPointSize(4.0); //Sets the point size
    glBegin(GL_POINTS); //Creates an OpenGL POINTS shape
        glVertex2f(248, 142); //Creates a POINTS SHAPE at this coordinate
    glEnd(); //Makes it so no more POINTS are created
}

//Function to create the stuff on the second right shelf
void stuff_on_shelf_4()
{
    //Shading
    glColor3f(0.184f, 0.121f, 0.058f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(500, 170); //First POLYGON coordinate
        glVertex2f(533, 170); //Second POLYGON coordinate
        glVertex2f(553, 162); //Third POLYGON coordinate
        glVertex2f(563, 115); //Fourth POLYGON coordinate
        glVertex2f(466, 101); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.105f, 0.074f, 0.031f); //sets color
    glBegin(GL_TRIANGLES); //Creates an OpenGL TRIANGLE shape
        glVertex2f(500, 115); //First TRIANGLE coordinate
        glVertex2f(563, 115); //Second TRIANGLE coordinate
        glVertex2f(466, 101); //Third TRIANGLE coordinate
    glEnd(); //Makes it so the TRIANGLE doesn't take anymore coordinates
    
    //LAMP
    glColor3f(0.505f, 0.427f, 0.329f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(466, 103); //First POLYGON coordinate
        glVertex2f(423, 106); //Second POLYGON coordinate
        glVertex2f(423, 183); //Third POLYGON coordinate
        glVertex2f(466, 180); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.156f, 0.113f, 0.098f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(435, 104); //First POLYGON coordinate
        glVertex2f(423, 106); //Second POLYGON coordinate
        glVertex2f(423, 183); //Third POLYGON coordinate
        glVertex2f(435, 182); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.525f, 0.517f, 0.521f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(462, 111); //First POLYGON coordinate
        glVertex2f(427, 114); //Second POLYGON coordinate
        glVertex2f(427, 177); //Third POLYGON coordinate
        glVertex2f(462, 174); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.172f, 0.141f, 0.098f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(436, 112); //First POLYGON coordinate
        glVertex2f(427, 114); //Second POLYGON coordinate
        glVertex2f(427, 177); //Third POLYGON coordinate
        glVertex2f(436, 176); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.145f, 0.090f, 0.047f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(466, 103); //First POLYGON coordinate
        glVertex2f(501, 106); //Second POLYGON coordinate
        glVertex2f(501, 183); //Third POLYGON coordinate
        glVertex2f(466, 180); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.317f, 0.301f, 0.254f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(470, 111); //First POLYGON coordinate
        glVertex2f(497, 114); //Second POLYGON coordinate
        glVertex2f(497, 177); //Third POLYGON coordinate
        glVertex2f(470, 174); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.360f, 0.317f, 0.294f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(444, 182); //First POLYGON coordinate
        glVertex2f(469, 165); //Second POLYGON coordinate
        glVertex2f(466, 160); //Third POLYGON coordinate
        glVertex2f(441, 177); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glBegin(GL_POLYGON); //GL POLYGON shape
        glVertex2f(503, 170); //First POLYGON coordinate
        glVertex2f(469, 165); //Second POLYGON coordinate
        glVertex2f(466, 160); //Third POLYGON coordinate
        glVertex2f(501, 165); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.125f, 0.074f, 0.039f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(501, 180); //First POLYGON coordinate
        glVertex2f(466, 183); //Second POLYGON coordinate
        glVertex2f(423, 186); //Third POLYGON coordinate
        glVertex2f(466, 183); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the stuff on the last left shelf
void stuff_on_shelf_5()
{
    //Shading
    glColor3f(0.266f, 0.184f, 0.117f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(180, 28); //First POLYGON coordinate
        glVertex2f(193, 20); //Second POLYGON coordinate
        glVertex2f(348, 20); //Third POLYGON coordinate
        glVertex2f(340, 28); //Fourth POLYGON coordinate
        glVertex2f(346, 30); //Fifth POLYGON  coordinate
        glVertex2f(320, 30); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.141f, 0.090f, 0.054f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(346, 30); //First POLYGON coordinate
        glVertex2f(372, 38); //Second POLYGON coordinate
        glVertex2f(372, 53); //Third POLYGON coordinate
        glVertex2f(390, 49); //Fourth POLYGON coordinate
        glVertex2f(390, 115); //Fifth POLYGON  coordinate
        glVertex2f(347, 115); //Sixth POLYGON coordinate
        glVertex2f(347, 50); //Seventh POLYGON coordinate
        glVertex2f(320, 50); //Eigth POLYGON coordinate
        glVertex2f(320, 30); //Ninth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.345f, 0.294f, 0.258f); //sets color
    glBegin(GL_TRIANGLES); //Creates an OpenGL TRIANGLE shape
        glVertex2f(347, 80); //First TRIANGLE coordinate
        glVertex2f(356, 80); //Second TRIANGLE coordinate
        glVertex2f(356, 72); //Third TRIANGLE coordinate
    glEnd(); //Makes it so the TRIANGLE doesn't take anymore coordinates
    
    //Creates the box
    glColor3f(0.066f, 0.0f, 0.039f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(168, 28); //First QUAD coordinate
        glVertex2f(323, 28); //Second QUAD coordinate
        glVertex2f(323, 59); //Third QUAD coordinate
        glVertex2f(168, 59); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.133f, 0.133f, 0.141f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(183, 81); //First POLYGON coordinate
        glVertex2f(338, 81); //Second POLYGON coordinate
        glVertex2f(323, 59); //Third POLYGON coordinate
        glVertex2f(168, 59); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.066f, 0.0f, 0.039f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(338, 50); //First POLYGON coordinate
        glVertex2f(338, 81); //Second POLYGON coordinate
        glVertex2f(323, 59); //Third POLYGON coordinate
        glVertex2f(323, 28); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Lights
    glColor3f(0.898f, 0.870f, 0.839f); //sets color
    glPointSize(4.0); //Sets the point size
    glBegin(GL_POINTS); //Creates an OpenGL POINTS shape
        glVertex2f(175, 45); //Creates a POINTS SHAPE at this coordinate
        glVertex2f(315, 45); //Creates a POINTS SHAPE at this coordinate
    glEnd(); //Makes it so no more POINTS are created
}

//Function to create the stuff on the last right shelf
void stuff_on_shelf_6()
{
    //First box
    glColor3f(0.933f, 0.239f, 0.215f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(554, 35); //First QUAD coordinate
        glVertex2f(659, 35); //Second QUAD coordinate
        glVertex2f(659, 52); //Third QUAD coordinate
        glVertex2f(554, 52); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.972f, 0.925f, 0.870f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(554, 35); //First POLYGON coordinate
        glVertex2f(542, 50); //Second POLYGON coordinate
        glVertex2f(542, 67); //Third POLYGON coordinate
        glVertex2f(554, 52); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.250f, 0.203f, 0.156f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(647, 67); //First POLYGON coordinate
        glVertex2f(542, 67); //Second POLYGON coordinate
        glVertex2f(554, 52); //Third POLYGON coordinate
        glVertex2f(659, 52); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Second box
    glColor3f(0.894f, 0.611f, 0.141f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(657, 68); //First QUAD coordinate
        glVertex2f(644, 68); //Second QUAD coordinate
        glVertex2f(644, 54); //Third QUAD coordinate
        glVertex2f(657, 54); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.725f, 0.635f, 0.270f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(634, 85); //First POLYGON coordinate
        glVertex2f(634, 71); //Second POLYGON coordinate
        glVertex2f(644, 54); //Third POLYGON coordinate
        glVertex2f(644, 68); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.968f, 0.756f, 0.262f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(658, 67); //First QUAD coordinate
        glVertex2f(643, 67); //Second QUAD coordinate
        glVertex2f(643, 71); //Third QUAD coordinate
        glVertex2f(658, 71); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.568f, 0.411f, 0.066f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(633, 89); //First POLYGON coordinate
        glVertex2f(633, 85); //Second POLYGON coordinate
        glVertex2f(643, 67); //Third POLYGON coordinate
        glVertex2f(643, 71); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.356f, 0.258f, 0.047f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(633, 89); //First POLYGON coordinate
        glVertex2f(648, 89); //Second POLYGON coordinate
        glVertex2f(658, 71); //Third POLYGON coordinate
        glVertex2f(643, 71); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Third box
    glColor3f(0.145f, 0.090f, 0.039f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(653, 78); //First QUAD coordinate
        glVertex2f(630, 78); //Second QUAD coordinate
        glVertex2f(630, 90); //Third QUAD coordinate
        glVertex2f(653, 90); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.090f, 0.0f, 0.0f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(606, 56); //First POLYGON coordinate
        glVertex2f(599, 68); //Second POLYGON coordinate
        glVertex2f(599, 82); //Third POLYGON coordinate
        glVertex2f(630, 82); //Fourth POLYGON coordinate
        glVertex2f(634, 78); //Fifth POLYGON  coordinate
        glVertex2f(601, 78); //Sixth POLYGON coordinate
        glVertex2f(606, 66); //Seventh POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(1.0f, 0.847f, 0.439f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(642, 56); //First QUAD coordinate
        glVertex2f(606, 56); //Second QUAD coordinate
        glVertex2f(606, 65); //Third QUAD coordinate
        glVertex2f(642, 65); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.090f, 0.0f, 0.0f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(642, 65); //First POLYGON coordinate
        glVertex2f(599, 65); //Second POLYGON coordinate
        glVertex2f(602, 73); //Third POLYGON coordinate
        glVertex2f(636, 73); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(1.0f, 0.952f, 0.0749); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(632, 67); //First POLYGON coordinate
        glVertex2f(628, 72); //Second POLYGON coordinate
        glVertex2f(613, 72); //Third POLYGON coordinate
        glVertex2f(614, 69); //Fourth POLYGON coordinate
        glVertex2f(628, 69); //Fifth POLYGON  coordinate
        glVertex2f(630, 67); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.309f, 0.215f, 0.121f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(602, 73); //First POLYGON coordinate
        glVertex2f(636, 73); //Second POLYGON coordinate
        glVertex2f(634, 78); //Third POLYGON coordinate
        glVertex2f(600, 78); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the table on the left
void table()
{
    //Shading
    glColor3f(0.094f, 0.027f, 0.0f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(64, 137); //First POLYGON coordinate
        glVertex2f(0, 137); //Second POLYGON coordinate
        glVertex2f(0, 0); //Third POLYGON coordinate
        glVertex2f(30, 0); //Fourth POLYGON coordinate
        glVertex2f(30, 38); //Fifth POLYGON  coordinate
        glVertex2f(64, 38); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.149f, 0.078f, 0.023f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(64, 137); //First QUAD coordinate
        glVertex2f(86, 137); //Second QUAD coordinate
        glVertex2f(86, 38); //Third QUAD coordinate
        glVertex2f(64, 38); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    glColor3f(0.254f, 0.168f, 0.086f); //sets color
    glBegin(GL_QUADS); //Creates an OpenGL QUAD shape
        //Uses the following coordinates to create the QUAD
        glVertex2f(100, 136); //First QUAD coordinate
        glVertex2f(86, 136); //Second QUAD coordinate
        glVertex2f(86, 38); //Third QUAD coordinate
        glVertex2f(100, 38); //Fourth QUAD coordinate
    glEnd(); //Makes it so the QUAD doesn't take anymore coordinates
    
    //Table
    glColor3f(0.541f, 0.372f, 0.239f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(86, 141); //First POLYGON coordinate
        glVertex2f(0, 141); //Second POLYGON coordinate
        glVertex2f(0, 124); //Third POLYGON coordinate
        glVertex2f(50, 124); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.321f, 0.207f, 0.145f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(86, 141); //First POLYGON coordinate
        glVertex2f(86, 131); //Second POLYGON coordinate
        glVertex2f(43, 112); //Third POLYGON coordinate
        glVertex2f(43, 122); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the chair on the left
void chair()
{
    //This creates the chair
    glColor3f(0.874f, 0.603f, 0.380f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(36, 151); //First POLYGON coordinate
        glVertex2f(46, 151); //Second POLYGON coordinate
        glVertex2f(39, 0); //Third POLYGON coordinate
        glVertex2f(29, 0); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.447f, 0.278f, 0.141f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(46, 151); //First POLYGON coordinate
        glVertex2f(49, 149); //Second POLYGON coordinate
        glVertex2f(42, 0); //Third POLYGON coordinate
        glVertex2f(39, 0); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.870f, 0.600f, 0.337f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(0, 149); //First POLYGON coordinate
        glVertex2f(42, 149); //Second POLYGON coordinate
        glVertex2f(40, 118); //Third POLYGON coordinate
        glVertex2f(0, 118); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.870f, 0.600f, 0.337f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(0, 111); //First POLYGON coordinate
        glVertex2f(40, 111); //Second POLYGON coordinate
        glVertex2f(38, 80); //Third POLYGON coordinate
        glVertex2f(0, 80); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.870f, 0.600f, 0.337f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(0, 73); //First POLYGON coordinate
        glVertex2f(38, 73); //Second POLYGON coordinate
        glVertex2f(36, 42); //Third POLYGON coordinate
        glVertex2f(0, 42); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.870f, 0.600f, 0.337f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(0, 34); //First POLYGON coordinate
        glVertex2f(36, 34); //Second POLYGON coordinate
        glVertex2f(34,3); //Third POLYGON coordinate
        glVertex2f(0, 3); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to ccreate the fan reflection
void fan()
{
    //Base
    glColor3f(0.215f, 0.160f, 0.149f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(462, 530); //First POLYGON coordinate
        glVertex2f(442, 480); //Second POLYGON coordinate
        glVertex2f(414, 464); //Third POLYGON coordinate
        glVertex2f(389, 481); //Fourth POLYGON coordinate
        glVertex2f(371, 530); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.305f, 0.270f, 0.250f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(401, 472); //First POLYGON coordinate
        glVertex2f(408, 474); //Second POLYGON coordinate
        glVertex2f(415, 471); //Third POLYGON coordinate
        glVertex2f(415, 464); //Fourth POLYGON coordinate
        glVertex2f(406, 455); //Fifth POLYGON  coordinate
        glVertex2f(403, 462); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Fan Blades
    glColor3f(0.149f, 0.109f, 0.101f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(295, 478); //First POLYGON coordinate
        glVertex2f(288, 487); //Second POLYGON coordinate
        glVertex2f(303, 493); //Third POLYGON coordinate
        glVertex2f(393, 482); //Fourth POLYGON coordinate
        glVertex2f(393, 476); //Fifth POLYGON  coordinate
        glVertex2f(379, 472); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.149f, 0.109f, 0.101f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(375, 464); //First POLYGON coordinate
        glVertex2f(315, 438); //Second POLYGON coordinate
        glVertex2f(336, 427); //Third POLYGON coordinate
        glVertex2f(395, 457); //Fourth POLYGON coordinate
        glVertex2f(391, 465); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.149f, 0.109f, 0.101f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(418, 463); //First POLYGON coordinate
        glVertex2f(434, 464); //Second POLYGON coordinate
        glVertex2f(481, 423); //Third POLYGON coordinate
        glVertex2f(461, 422); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.149f, 0.109f, 0.101f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(440, 476); //First POLYGON coordinate
        glVertex2f(564, 471); //Second POLYGON coordinate
        glVertex2f(555, 466); //Third POLYGON coordinate
        glVertex2f(434, 471); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates

    //Lights
    //Darker Parts
    glColor3f(0.274f, 0.239f, 0.211f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(397, 460); //First POLYGON coordinate
        glVertex2f(381, 442); //Second POLYGON coordinate
        glVertex2f(393, 420); //Third POLYGON coordinate
        glVertex2f(404, 430); //Fourth POLYGON coordinate
        glVertex2f(396, 444); //Fifth POLYGON  coordinate
        glVertex2f(402, 453); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(412, 461); //First POLYGON coordinate
        glVertex2f(410, 442); //Second POLYGON coordinate
        glVertex2f(415, 430); //Third POLYGON coordinate
        glVertex2f(430, 427); //Fourth POLYGON coordinate
        glVertex2f(435, 432); //Fifth POLYGON  coordinate
        glVertex2f(438, 437); //Sixth POLYGON coordinate
        glVertex2f(419, 465); //Seventh POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(423, 427); //First POLYGON coordinate
        glVertex2f(430, 415); //Second POLYGON coordinate
        glVertex2f(441, 422); //Third POLYGON coordinate
        glVertex2f(432, 433); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Lighter Parts
    glColor3f(0.282f, 0.262f, 0.247f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(411, 455); //First POLYGON coordinate
        glVertex2f(411, 447); //Second POLYGON coordinate
        glVertex2f(416, 443); //Third POLYGON coordinate
        glVertex2f(418, 447); //Fourth POLYGON coordinate
        glVertex2f(418, 452); //Fifth POLYGON  coordinate
        glVertex2f(414, 456); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(425, 423); //First POLYGON coordinate
        glVertex2f(430, 416); //Second POLYGON coordinate
        glVertex2f(437, 420); //Third POLYGON coordinate
        glVertex2f(430, 426); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //Reflection
    glColor3f(0.556f, 0.407f, 0.403f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(245, 467); //First POLYGON coordinate
        glVertex2f(570, 521); //Second POLYGON coordinate
        glVertex2f(570, 511); //Third POLYGON coordinate
        glVertex2f(245, 456); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.176f, 0.219f, 0.164f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(303, 477); //First POLYGON coordinate
        glVertex2f(359, 486); //Second POLYGON coordinate
        glVertex2f(395, 481); //Third POLYGON coordinate
        glVertex2f(353, 474); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.305f, 0.278f, 0.215f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(408, 494); //First POLYGON coordinate
        glVertex2f(359, 486); //Second POLYGON coordinate
        glVertex2f(395, 481); //Third POLYGON coordinate
        glVertex2f(414, 485); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.247f, 0.188f, 0.176f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(408, 494); //First POLYGON coordinate
        glVertex2f(494, 510); //Second POLYGON coordinate
        glVertex2f(500, 498); //Third POLYGON coordinate
        glVertex2f(414, 485); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.188f, 0.168f, 0.145f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(570, 521); //First POLYGON coordinate
        glVertex2f(494, 510); //Second POLYGON coordinate
        glVertex2f(500, 498); //Third POLYGON coordinate
        glVertex2f(570, 511); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the first shape of leaf
void leave_1(int x, int y)
{
    glColor3f(0.243f, 0.247f, 0.113f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(x - 1, y - 4); //First POLYGON coordinate
        glVertex2f(x + 7, y - 4); //Second POLYGON coordinate
        glVertex2f(x + 8, y - 8); //Third POLYGON coordinate
        glVertex2f(x + 2, y - 15); //Fourth POLYGON coordinate
        glVertex2f(x - 4, y - 9); //Fifth POLYGON  coordinate
        glVertex2f(x - 4, y - 7); //Sixth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.215f, 0.160f, 0.149f); //sets color
    glBegin(GL_LINES); //Creates an OpenGL LINES shape
        glVertex2f(x, y); //First LINES coordinate
        glVertex2f(x + 2, y - 6); //Second LINES coordinate
    glEnd(); //Makes it so the LINES doesn't take anymore coordinates
}

//Function to create the second shape of leaf
void leaf_2(int x, int y)
{
    glColor3f(0.298f, 0.258f, 0.152f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(x, y); //First POLYGON coordinate
        glVertex2f(x + 7, y + 5); //Second POLYGON coordinate
        glVertex2f(x + 10, y - 1); //Third POLYGON coordinate
        glVertex2f(x + 6, y - 6); //Fourth POLYGON coordinate
        glVertex2f(x + 2, y - 5); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create the third shape of leaf
void leaf_3(int x, int y)
{
    glColor3f(0.294f, 0.301f, 0.207f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(x, y); //First POLYGON coordinate
        glVertex2f(x + 4, y); //Second POLYGON coordinate
        glVertex2f(x + 7, y + 2); //Third POLYGON coordinate
        glVertex2f(x + 9, y); //Fourth POLYGON coordinate
        glVertex2f(x + 9, y - 3); //Fifth POLYGON  coordinate
        glVertex2f(x + 6, y - 6); //Sixth POLYGON coordinate
        glVertex2f(x + 2, y - 6); //Seventh POLYGON coordinate
        glVertex2f(x, y - 4); //Eigth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
}

//Function to create many of the first leaf shape
void create_leaf_1()
{
    leave_1(31, 439); //Creates the first leaf shape at these coordinates
    leave_1(21, 472); //Creates the first leaf shape at these coordinates
    leave_1(43, 476); //Creates the first leaf shape at these coordinates
    leave_1(31, 487); //Creates the first leaf shape at these coordinates
    leave_1(24, 499); //Creates the first leaf shape at these coordinates
    leave_1(29, 501); //Creates the first leaf shape at these coordinates
    leave_1(40, 499); //Creates the first leaf shape at these coordinates
    leave_1(17, 508); //Creates the first leaf shape at these coordinates
    leave_1(22, 512); //Creates the first leaf shape at these coordinates
    leave_1(32, 512); //Creates the first leaf shape at these coordinates
    leave_1(44, 516); //Creates the first leaf shape at these coordinates
    leave_1(36, 522); //Creates the first leaf shape at these coordinates
    leave_1(39, 541); //Creates the first leaf shape at these coordinates
    leave_1(32, 544); //Creates the first leaf shape at these coordinates
    leave_1(30, 548); //Creates the first leaf shape at these coordinates
    leave_1(23, 549); //Creates the first leaf shape at these coordinates
    leave_1(17, 549); //Creates the first leaf shape at these coordinates
    leave_1(13, 552); //Creates the first leaf shape at these coordinates
    leave_1(11, 549); //Creates the first leaf shape at these coordinates
}

//Function to create many of the second leaf shape
void create_leaf_2()
{
    leaf_2(17, 448); //Creates the second leaf shape at these coordinates
    leaf_2(23, 437); //Creates the second leaf shape at these coordinates
    leaf_2(38, 444); //Creates the second leaf shape at these coordinates
    leaf_2(25, 445); //Creates the second leaf shape at these coordinates
    leaf_2(31, 445); //Creates the second leaf shape at these coordinates
    leaf_2(26, 453); //Creates the second leaf shape at these coordinates
    leaf_2(29, 453); //Creates the second leaf shape at these coordinates
    leaf_2(34, 451); //Creates the second leaf shape at these coordinates
    leaf_2(36, 460); //Creates the second leaf shape at these coordinates
    leaf_2(31, 465); //Creates the second leaf shape at these coordinates
    leaf_2(33, 469); //Creates the second leaf shape at these coordinates
    leaf_2(33, 473); //Creates the second leaf shape at these coordinates
    leaf_2(32, 475); //Creates the second leaf shape at these coordinates
    leaf_2(20, 475); //Creates the second leaf shape at these coordinates
    leaf_2(20, 487); //Creates the second leaf shape at these coordinates
    leaf_2(24, 488); //Creates the second leaf shape at these coordinates
    leaf_2(28, 489); //Creates the second leaf shape at these coordinates
    leaf_2(32, 493); //Creates the second leaf shape at these coordinates
    leaf_2(34, 497); //Creates the second leaf shape at these coordinates
    leaf_2(35, 501); //Creates the second leaf shape at these coordinates
    leaf_2(33, 501); //Creates the second leaf shape at these coordinates
    leaf_2(28, 501); //Creates the second leaf shape at these coordinates
    leaf_2(30, 504); //Creates the second leaf shape at these coordinates
    leaf_2(30, 507); //Creates the second leaf shape at these coordinates
    leaf_2(28, 511); //Creates the second leaf shape at these coordinates
    leaf_2(27, 514); //Creates the second leaf shape at these coordinates
    leaf_2(26, 517); //Creates the second leaf shape at these coordinates
    leaf_2(25, 521); //Creates the second leaf shape at these coordinates
    leaf_2(39, 526); //Creates the second leaf shape at these coordinates
    leaf_2(36, 550); //Creates the second leaf shape at these coordinates
    leaf_2(38, 545); //Creates the second leaf shape at these coordinates
    leaf_2(34, 547); //Creates the second leaf shape at these coordinates
    leaf_2(32, 548); //Creates the second leaf shape at these coordinates
    leaf_2(29, 549); //Creates the second leaf shape at these coordinates
    leaf_2(26, 549); //Creates the second leaf shape at these coordinates
    leaf_2(23, 550); //Creates the second leaf shape at these coordinates
    leaf_2(20, 553); //Creates the second leaf shape at these coordinates
    leaf_2(16, 553); //Creates the second leaf shape at these coordinates
    leaf_2(13, 553); //Creates the second leaf shape at these coordinates
    leaf_2(11, 559); //Creates the second leaf shape at these coordinates
    leaf_2(9, 553); //Creates the second leaf shape at these coordinates
    leaf_2(5, 553); //Creates the second leaf shape at these coordinates
    leaf_2(0, 552); //Creates the second leaf shape at these coordinates
    leaf_2(0, 547); //Creates the second leaf shape at these coordinates
    leaf_2(0, 542); //Creates the second leaf shape at these coordinates
    leaf_2(-2, 549); //Creates the second leaf shape at these coordinates
    leaf_2(-2, 541); //Creates the second leaf shape at these coordinates
    leaf_2(3, 541); //Creates the second leaf shape at these coordinates
}

//Function to create many of the third leaf shape
void create_leaf_3()
{
    leaf_3(36, 518); //Creates the third leaf shape at these coordinates
    leaf_3(33, 524); //Creates the third leaf shape at these coordinates
    leaf_3(30, 530); //Creates the third leaf shape at these coordinates
    leaf_3(25, 534); //Creates the third leaf shape at these coordinates
    leaf_3(22, 538); //Creates the third leaf shape at these coordinates
    leaf_3(17, 542); //Creates the third leaf shape at these coordinates
    leaf_3(16, 546); //Creates the third leaf shape at these coordinates
    leaf_3(22, 516); //Creates the third leaf shape at these coordinates
    leaf_3(38, 480); //Creates the third leaf shape at these coordinates
    leaf_3(38, 484); //Creates the third leaf shape at these coordinates
    leaf_3(26, 460); //Creates the third leaf shape at these coordinates
    leaf_3(32, 440); //Creates the third leaf shape at these coordinates
}

//Function to create the plant on the left
void plant()
{
    //Calls function that creates the second leaf shape
    create_leaf_2();
    //Calls function that creates the first leaf shape
    create_leaf_1();
    
    glColor3f(0.278f, 0.176f, 0.117f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(0, 505); //First POLYGON coordinate
        glVertex2f(10, 505); //Second POLYGON coordinate
        glVertex2f(25, 518); //Third POLYGON coordinate
        glVertex2f(25, 537); //Fourth POLYGON coordinate
        glVertex2f(0, 537); //Fifth POLYGON  coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    glColor3f(0.929f, 0.788f, 0.654f); //sets color
    glBegin(GL_POLYGON); //Creates an OpenGL POLYGON shape
        glVertex2f(25, 537); //First POLYGON coordinate
        glVertex2f(22, 537); //Second POLYGON coordinate
        glVertex2f(1, 600); //Third POLYGON coordinate
        glVertex2f(4, 600); //Fourth POLYGON coordinate
    glEnd(); //Makes it so the POLYGON doesn't take anymore coordinates
    
    //calls function that creates the third lead shape
    create_leaf_3();
}

//Function to call all the other functions before this
void render()
{
    //Adds the wall shading
    wall_shading();
    
    //Creates the tv stand
    shelves_1();
    shelves_2();
    
    //Gives the tv stand depth
    shelf_depth_1();
    shelf_depth_2();
    shelf_depth_3();
    shelf_depth_4();
    shelf_depth_5();
    shelf_depth_6();
    
    //adds objects to the tv stand
    tv();
    stuff_on_top();
    stuff_on_shelf_1();
    stuff_on_shelf_2();
    stuff_on_shelf_3();
    stuff_on_shelf_4();
    stuff_on_shelf_5();
    stuff_on_shelf_6();
    
    //adds chair and table on the left
    table();
    chair();

    //adds the fan reflection on the tv
    fan();
    
    //adds the plant in the top left corner
    plant();
}

//Sets initial background color
void Init()
{
    //Sets initial background color
    glClearColor(0.855, 0.729, 0.568, 0);
    //Makes the shapes possible to render
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Makes it so the screen can "snap"
    glOrtho(0.0, 800.0, 0.0, 600.0, 0.0, 1.0);
}

//Display function to render the picture
void myDisplay(void)
{
    //Sets the OpenGL colors up to be used
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Creates all the objects
    render();
    //displays them
    glFlush();
    glutSwapBuffers();
}

//Game loop this is almost the same in every code
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Project 5: Render Your Scene With Primitives");
    glutDisplayFunc(myDisplay);
    Init();
    glutMainLoop();
    return 0;
}
