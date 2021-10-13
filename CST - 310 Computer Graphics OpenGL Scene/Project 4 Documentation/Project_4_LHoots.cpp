//Written by Logan Hoots
//Project 4: Render Scene with Primitives
//Due: 2/23/2020

//Include libraries
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//Function to create shading on the wall
void wall_shading()
{
    //Lighter Shading
    glColor3f(0.654f, 0.501f, 0.349f);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(260, 0);
        glVertex2f(260, 600);
        glVertex2f(0, 600);
    glEnd();
    glColor3f(0.835f, 0.717f, 0.584f);
    glBegin(GL_QUADS);
        glVertex2f(260, 0);
        glVertex2f(360, 0);
        glVertex2f(360, 600);
        glVertex2f(260, 600);
    glEnd();
    
    //Lighter Shading
    glColor3f(0.380f, 0.282f, 0.164f);
    glBegin(GL_POLYGON);
        glVertex2f(575, 505);
        glVertex2f(655, 505);
        glVertex2f(680, 310);
        glVertex2f(500, 310);
        glVertex2f(500, 340);
        glVertex2f(575, 340);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(675, 300);
        glVertex2f(685, 300);
        glVertex2f(800, 265);
        glVertex2f(800, 0);
        glVertex2f(675, 0);
    glEnd();
    
    //Darker Shading
    glColor3f(0.333f, 0.239f, 0.129f);
    glBegin(GL_POLYGON);
        glVertex2f(675, 300);
        glVertex2f(685, 300);
        glVertex2f(725, 286);
        glVertex2f(725, 0);
        glVertex2f(675, 0);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(575, 505);
        glVertex2f(605, 505);
        glVertex2f(625, 310);
        glVertex2f(500, 310);
        glVertex2f(500, 340);
        glVertex2f(575, 340);
    glEnd();
    
    //Floor Board
    glColor3f(0.588f, 0.482f, 0.415f);
    glBegin(GL_QUADS);
        glVertex2f(800, 38);
        glVertex2f(800, 0);
        glVertex2f(0, 0);
        glVertex2f(0, 38);
    glEnd();
    
    //Darker Shading
    glColor3f(0.345f, 0.254f, 0.133f);
    glBegin(GL_QUADS);
        glVertex2f(180, 370);
        glVertex2f(215, 370);
        glVertex2f(215, 310);
        glVertex2f(180, 310);
    glEnd();
}

//Function to create the darker part of the shelves
void shelves_1()
{
    //Shapes to create the darker part of the shelves
    glColor3f(0.360f, 0.282f, 0.215f);
    glBegin(GL_QUADS);
        glVertex2f(100, 0);
        glVertex2f(100, 300);
        glVertex2f(110, 300);
        glVertex2f(110, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(95, 300);
        glVertex2f(95, 310);
        glVertex2f(120, 310);
        glVertex2f(120, 300);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(110, 215);
        glVertex2f(110, 205);
        glVertex2f(125, 205);
        glVertex2f(125, 215);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(110, 125);
        glVertex2f(110, 115);
        glVertex2f(125, 115);
        glVertex2f(125, 125);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(110, 30);
        glVertex2f(110, 10);
        glVertex2f(125, 10);
        glVertex2f(125, 30);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(110, 10);
        glVertex2f(110, 0);
        glVertex2f(115, 0);
        glVertex2f(115, 10);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(110, 300);
        glVertex2f(110, 295);
        glVertex2f(125, 295);
        glVertex2f(125, 300);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(380, 0);
        glVertex2f(380, 10);
        glVertex2f(410, 10);
        glVertex2f(410, 0);
    glEnd();
  
    //Creates the middle peg under the TV stand
    glColor3f(0.078f, 0.023f, 0.023f);
    glBegin(GL_QUADS);
        glVertex2f(380, 0);
        glVertex2f(380, 10);
        glVertex2f(115, 10);
        glVertex2f(115, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(410, 0);
        glVertex2f(410, 10);
        glVertex2f(665, 10);
        glVertex2f(665, 0);
    glEnd();
}

//Function to create the light part of the shelves
void shelves_2()
{
    //Shapes to create the lighter part of the tv stand
    glColor3f(0.745f, 0.619f, 0.529f);
    glBegin(GL_QUADS);
        glVertex2f(665, 0);
        glVertex2f(665, 300);
        glVertex2f(675, 300);
        glVertex2f(675, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(390, 300);
        glVertex2f(390, 10);
        glVertex2f(400, 10);
        glVertex2f(400, 300);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(120, 300);
        glVertex2f(120, 310);
        glVertex2f(680, 310);
        glVertex2f(680, 300);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(125, 300);
        glVertex2f(125, 295);
        glVertex2f(665, 295);
        glVertex2f(665, 300);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(125, 215);
        glVertex2f(125, 205);
        glVertex2f(665, 205);
        glVertex2f(665, 215);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(125, 125);
        glVertex2f(125, 115);
        glVertex2f(390, 115);
        glVertex2f(390, 125);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(400, 100);
        glVertex2f(400, 90);
        glVertex2f(665, 90);
        glVertex2f(665, 100);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(665, 30);
        glVertex2f(665, 10);
        glVertex2f(125, 10);
        glVertex2f(125, 30);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(660, 10);
        glVertex2f(660, 0);
        glVertex2f(665, 0);
        glVertex2f(665, 10);
    glEnd();
}

//Function to create the depth on the first left shelf
void shelf_depth_1()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f);
    glBegin(GL_QUADS);
        glVertex2f(390, 215);
        glVertex2f(390, 225);
        glVertex2f(110, 225);
        glVertex2f(110, 215);
    glEnd();
    glColor3f(0.098f, 0.066f, 0.043f);
    glBegin(GL_POLYGON);
        glVertex2f(110, 295);
        glVertex2f(150, 295);
        glVertex2f(150, 225);
        glVertex2f(210, 225);
        glVertex2f(110, 215);
    glEnd();
    glColor3f(0.258f, 0.196f, 0.133f);
    glBegin(GL_POLYGON);
        glVertex2f(150, 295);
        glVertex2f(390, 295);
        glVertex2f(390, 260);
        glVertex2f(210, 260);
        glVertex2f(210, 225);
        glVertex2f(150, 225);
    glEnd();
    glColor3f(0.596f, 0.505f, 0.396f);
    glBegin(GL_QUADS);
        glVertex2f(210, 260);
        glVertex2f(210, 225);
        glVertex2f(390, 225);
        glVertex2f(390, 260);
    glEnd();    
}

//Function to create the depth on the first right shelf
void shelf_depth_2()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f);
    glBegin(GL_QUADS);
        glVertex2f(665, 215);
        glVertex2f(665, 225);
        glVertex2f(400, 225);
        glVertex2f(400, 215);
    glEnd();
    glColor3f(0.098f, 0.066f, 0.043f);
    glBegin(GL_POLYGON);
        glVertex2f(400, 295);
        glVertex2f(440, 295);
        glVertex2f(440, 225);
        glVertex2f(500, 225);
        glVertex2f(400, 215);
    glEnd();
    glColor3f(0.380f, 0.317f, 0.219f);
    glBegin(GL_POLYGON);
        glVertex2f(665, 215);
        glVertex2f(645, 225);
        glVertex2f(645, 295);
        glVertex2f(665, 295);
    glEnd();
    glColor3f(0.141f, 0.086f, 0.035f);
    glBegin(GL_POLYGON);
        glVertex2f(440, 295);
        glVertex2f(665, 295);
        glVertex2f(645, 260);
        glVertex2f(500, 260);
        glVertex2f(500, 225);
        glVertex2f(440, 225);
    glEnd();
    glColor3f(0.419f, 0.329f, 0.254f);
    glBegin(GL_QUADS);
        glVertex2f(500, 260);
        glVertex2f(500, 225);
        glVertex2f(645, 225);
        glVertex2f(645, 260);
    glEnd();
}

//Function to create the depth on the second left shelf
void shelf_depth_3()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f);
    glBegin(GL_QUADS);
        glVertex2f(390, 125);
        glVertex2f(390, 135);
        glVertex2f(110, 135);
        glVertex2f(110, 125);
    glEnd();
    glColor3f(0.098f, 0.066f, 0.043f);
    glBegin(GL_POLYGON);
        glVertex2f(110, 205);
        glVertex2f(150, 205);
        glVertex2f(150, 135);
        glVertex2f(210, 135);
        glVertex2f(110, 125);
    glEnd();
    glColor3f(0.258f, 0.196f, 0.133f);
    glBegin(GL_POLYGON);
        glVertex2f(150, 205);
        glVertex2f(390, 205);
        glVertex2f(390, 170);
        glVertex2f(210, 170);
        glVertex2f(210, 135);
        glVertex2f(150, 135);
    glEnd();
    glColor3f(0.596f, 0.505f, 0.396f);
    glBegin(GL_QUADS);
        glVertex2f(210, 170);
        glVertex2f(210, 135);
        glVertex2f(390, 135);
        glVertex2f(390, 170);
    glEnd();    
}

//Function to create the depth on the second right shelf
void shelf_depth_4()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.329f, 0.262f, 0.184f);
    glBegin(GL_QUADS);
        glVertex2f(665, 100);
        glVertex2f(665, 115);
        glVertex2f(400, 115);
        glVertex2f(400, 100);
    glEnd();
    glColor3f(0.098f, 0.066f, 0.043f);
    glBegin(GL_POLYGON);
        glVertex2f(500, 205);
        glVertex2f(500, 115);
        glVertex2f(400, 100);
        glVertex2f(400, 205);
    glEnd();
    glColor3f(0.458f, 0.364f, 0.258f);
    glBegin(GL_POLYGON);
        glVertex2f(665, 100);
        glVertex2f(645, 115);
        glVertex2f(645, 205);
        glVertex2f(665, 205);
    glEnd();
    glColor3f(0.145f, 0.090f, 0.039f);
    glBegin(GL_POLYGON);
        glVertex2f(440, 205);
        glVertex2f(665, 205);
        glVertex2f(645, 170);
        glVertex2f(500, 170);
        glVertex2f(500, 115);
        glVertex2f(440, 115);
    glEnd();
    glColor3f(0.429f, 0.349f, 0.254f);
    glBegin(GL_QUADS);
        glVertex2f(500, 170);
        glVertex2f(500, 115);
        glVertex2f(645, 115);
        glVertex2f(645, 170);
    glEnd();
}

//Function to create the depth on the last left shelf
void shelf_depth_5()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.450f, 0.384f, 0.321f);
    glBegin(GL_QUADS);
        glVertex2f(390, 30);
        glVertex2f(390, 50);
        glVertex2f(110, 50);
        glVertex2f(110, 30);
    glEnd();
    glColor3f(0.098f, 0.066f, 0.043f);
    glBegin(GL_POLYGON);
        glVertex2f(110, 115);
        glVertex2f(150, 115);
        glVertex2f(150, 50);
        glVertex2f(210, 50);
        glVertex2f(110, 30);
    glEnd();
    glColor3f(0.196f, 0.141f, 0.098f);
    glBegin(GL_POLYGON);
        glVertex2f(150, 115);
        glVertex2f(390, 115);
        glVertex2f(390, 50);
        glVertex2f(150, 50);
    glEnd();
    glColor3f(0.086f, 0.050f, 0.031f);
    glBegin(GL_QUADS);
        glVertex2f(215, 115);
        glVertex2f(347, 115);
        glVertex2f(347, 50);
        glVertex2f(215, 50);
    glEnd();    
    
}

//Function to create the depth on the last right shelf
void shelf_depth_6()
{
    //Creates the different shapes with different color, to look like there's depth
    glColor3f(0.329f, 0.262f, 0.184f);
    glBegin(GL_QUADS);
        glVertex2f(665, 30);
        glVertex2f(665, 50);
        glVertex2f(400, 50);
        glVertex2f(400, 30);
    glEnd();
    glColor3f(0.098f, 0.066f, 0.043f);
    glBegin(GL_POLYGON);
        glVertex2f(500, 90);
        glVertex2f(500, 50);
        glVertex2f(400, 30);
        glVertex2f(400, 90);
    glEnd();
    glColor3f(0.458f, 0.364f, 0.258f);
    glBegin(GL_POLYGON);
        glVertex2f(665, 30);
        glVertex2f(645, 50);
        glVertex2f(645, 90);
        glVertex2f(665, 90);
    glEnd();
    glColor3f(0.145f, 0.090f, 0.039f);
    glBegin(GL_POLYGON);
        glVertex2f(440, 90);
        glVertex2f(665, 90);
        glVertex2f(645, 70);
        glVertex2f(500, 70);
        glVertex2f(500, 50);
        glVertex2f(440, 50);
    glEnd();
    glColor3f(0.429f, 0.349f, 0.254f);
    glBegin(GL_QUADS);
        glVertex2f(500, 70);
        glVertex2f(500, 50);
        glVertex2f(645, 50);
        glVertex2f(645, 70);
    glEnd();
}

//Function to create the TV
void tv()
{
    //Frame
    glColor3f(0.133f, 0.098f, 0.109f);
    glBegin(GL_QUADS);
        glVertex2f(240, 535);
        glVertex2f(575, 535);
        glVertex2f(575, 340);
        glVertex2f(240, 340);
    glEnd();
    
    //Screen
    glColor3f(0.333f, 0.282f, 0.250f);
    glBegin(GL_QUADS);
        glVertex2f(245, 530);
        glVertex2f(570, 530);
        glVertex2f(570, 345);
        glVertex2f(245, 345);
    glEnd();
        
    //Shading
    glColor3f(0.258f, 0.219f, 0.184f);
    glBegin(GL_QUADS);
        glVertex2f(375, 530);
        glVertex2f(570, 530);
        glVertex2f(570, 345);
        glVertex2f(375, 345);
    glEnd();
    glColor3f(0.133f, 0.098f, 0.109f);
    glBegin(GL_QUADS);
        glVertex2f(325, 310);
        glVertex2f(500, 310);
        glVertex2f(500, 340);
        glVertex2f(325, 340);
    glEnd();

    //Lights
    glColor3f(1.0f, 1.0f, 0.952f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
        glVertex2f(405, 342);
        glVertex2f(408, 342);
    glEnd();
}

//Function to create the stuff on the top of the tv stand
void stuff_on_top()
{
    //Creates the object on the left
    glColor3f(0.168f, 0.109f, 0.082f);
    glBegin(GL_POLYGON);
        glVertex2f(140, 310);
        glVertex2f(140, 375);
        glVertex2f(150, 385);
        glVertex2f(180, 385);
        glVertex2f(180, 310);
    glEnd();
    glColor3f(0.258f, 0.215f, 0.200f);
    glBegin(GL_QUADS);
        glVertex2f(145, 375);
        glVertex2f(170, 375);
        glVertex2f(170, 310);
        glVertex2f(145, 310);
    glEnd();
    glColor3f(0.368f, 0.329f, 0.321f);
    glBegin(GL_QUADS);
        glVertex2f(175, 375);
        glVertex2f(170, 375);
        glVertex2f(170, 310);
        glVertex2f(175, 310);
    glEnd();
    
    //Creates the object on the right bottom
    glColor3f(0.090f, 0.078f, 0.058f);
    glBegin(GL_QUADS);
        glVertex2f(195, 325);
        glVertex2f(290, 325);
        glVertex2f(290, 310);
        glVertex2f(195, 310);
    glEnd();
    glColor3f(0.552f, 0.470f, 0.388f);
    glBegin(GL_POLYGON);
        glVertex2f(300, 323);
        glVertex2f(290, 325);
        glVertex2f(290, 310);
        glVertex2f(300, 310);
    glEnd();
    glColor3f(0.360f, 0.356f, 0.376f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
        glVertex2f(280, 320);
        glVertex2f(286, 320);
    glEnd();
    
    //Creates the object on the right top
    glColor3f(0.058f, 0.027f, 0.019f);
    glBegin(GL_QUADS);
        glVertex2f(250, 325);
        glVertex2f(220, 325);
        glVertex2f(220, 335);
        glVertex2f(250, 335);
    glEnd();
    glColor3f(0.360f, 0.337f, 0.345f);
    glBegin(GL_QUADS);
        glVertex2f(224, 325);
        glVertex2f(222, 325);
        glVertex2f(222, 335);
        glVertex2f(224, 335);
    glEnd();
}

//Function to create the stuff on the first left shelf
void stuff_on_shelf_1()
{
    //Creates the main shape
    glColor3f(1.0f, 1.0f, 0.984f);
    glBegin(GL_QUADS);
        glVertex2f(210, 280);
        glVertex2f(250, 280);
        glVertex2f(250, 220);
        glVertex2f(210, 220);
    glEnd();    
    glColor3f(0.541f, 0.443f, 0.427f);
    glBegin(GL_QUADS);
        glVertex2f(215, 275);
        glVertex2f(245, 275);
        glVertex2f(245, 225);
        glVertex2f(215, 225);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.984f);
    glBegin(GL_QUADS);
        glVertex2f(218, 272);
        glVertex2f(242, 272);
        glVertex2f(242, 228);
        glVertex2f(218, 228);
    glEnd();
    
    //Shading
    glColor3f(0.105f, 0.070f, 0.050f);
    glBegin(GL_POLYGON);
        glVertex2f(260, 260);
        glVertex2f(300, 260);
        glVertex2f(310, 255);
        glVertex2f(310, 225);
        glVertex2f(250, 220);
        glVertex2f(260, 225);
    glEnd();
    glColor3f(0.235f, 0.172f, 0.109f);
    glBegin(GL_POLYGON);
        glVertex2f(280, 260);
        glVertex2f(300, 260);
        glVertex2f(310, 255);
        glVertex2f(310, 225);
        glVertex2f(280, 225);
    glEnd();
    glColor3f(0.384f, 0.345f, 0.305f);
    glBegin(GL_POLYGON);
        glVertex2f(260, 260);
        glVertex2f(250, 260);
        glVertex2f(250, 220);
        glVertex2f(260, 225);
    glEnd();
    glColor3f(0.105f, 0.043f, 0.047f);
    glBegin(GL_POLYGON);
        glVertex2f(260, 260);
        glVertex2f(250, 260);
        glVertex2f(250, 280);
        glVertex2f(260, 275);
    glEnd();
}

//Function to create the stuff on the first right shelf
void stuff_on_shelf_2()
{
    //Creates the wooden thing on the shelf
    glColor3f(0.141f, 0.086f, 0.035f);
    glBegin(GL_POLYGON);
        glVertex2f(620, 260);
        glVertex2f(645, 260);
        glVertex2f(655, 265);
        glVertex2f(655, 220);
        glVertex2f(620, 218);
    glEnd();
    glColor3f(0.619f, 0.435f, 0.262f);
    glBegin(GL_POLYGON);
        glVertex2f(620, 218);
        glVertex2f(620, 278);
        glVertex2f(555, 280);
        glVertex2f(555, 220);
    glEnd();
    glColor3f(0.756f, 0.505f, 0.254f);
    glBegin(GL_POLYGON);
        glVertex2f(567, 272);
        glVertex2f(608, 270);
        glVertex2f(608, 264);
        glVertex2f(616, 253);
        glVertex2f(616, 240);
        glVertex2f(608, 230);
        glVertex2f(608, 223);
        glVertex2f(566, 225);
        glVertex2f(566, 232);
        glVertex2f(560, 241);
        glVertex2f(560, 258);
        glVertex2f(567, 266);
    glEnd();
    
    //Shading
    glColor3f(0.239f, 0.168f, 0.121f);
    glBegin(GL_POLYGON);
        glVertex2f(620, 218);
        glVertex2f(623, 220);
        glVertex2f(623, 276);
        glVertex2f(620, 280);
    glEnd();
}

//Function to create the stuff on the second left shelf
void stuff_on_shelf_3()
{
    //First book from right
    glColor3f(0.780f, 0.725f, 0.682f);
    glBegin(GL_QUADS);
        glVertex2f(390, 125);
        glVertex2f(390, 200);
        glVertex2f(385, 200);
        glVertex2f(385, 125);
    glEnd();
    
    //Second Book
    glColor3f(0.200f, 0.184f, 0.188f);
    glBegin(GL_QUADS);
        glVertex2f(375, 127);
        glVertex2f(375, 182);
        glVertex2f(385, 182);
        glVertex2f(385, 127);
    glEnd();
    
    //Third Book
    glColor3f(0.882f, 0.411f, 0.349f);
    glBegin(GL_QUADS);
        glVertex2f(375, 125);
        glVertex2f(375, 194);
        glVertex2f(367, 194);
        glVertex2f(367, 125);
    glEnd();
    glColor3f(0.964f, 0.937f, 0.913f);
    glBegin(GL_QUADS);
        glVertex2f(375, 152);
        glVertex2f(375, 178);
        glVertex2f(367, 178);
        glVertex2f(367, 152);
    glEnd();
    
    //Fourth book
    glColor3f(0.588f, 0.337f, 0.298f);
    glBegin(GL_QUADS);
        glVertex2f(362, 125);
        glVertex2f(362, 196);
        glVertex2f(367, 196);
        glVertex2f(367, 125);
    glEnd();
    glColor3f(1.0f, 0.870f, 0.866f);
    glBegin(GL_QUADS);
        glVertex2f(362, 151);
        glVertex2f(362, 180);
        glVertex2f(367, 180);
        glVertex2f(367, 151);
    glEnd();

    //Fifth Book
    glColor3f(0.952f, 0.843f, 0.839f);
    glBegin(GL_QUADS);
        glVertex2f(362, 128);
        glVertex2f(362, 194);
        glVertex2f(358, 194);
        glVertex2f(358, 128);
    glEnd();
    
    //Sixth Book
    glColor3f(0.529f, 0.556f, 0.768f);
    glBegin(GL_QUADS);
        glVertex2f(352, 128);
        glVertex2f(352, 195);
        glVertex2f(358, 195);
        glVertex2f(358, 128);
    glEnd();
    
    //Seventh Book
    glColor3f(1.0f, 0.976f, 0.992f);
    glBegin(GL_QUADS);
        glVertex2f(352, 127);
        glVertex2f(352, 196);
        glVertex2f(347, 196);
        glVertex2f(347, 127);
    glEnd();
    glColor3f(0.132f, 0.227f, 0.219f);
    glBegin(GL_POLYGON);
        glVertex2f(352, 133);
        glVertex2f(352, 162);
        glVertex2f(347, 167);
        glVertex2f(347, 130);
    glEnd();

    //XBOX
    glColor3f(0.043f, 0.043f, 0.050f);
    glBegin(GL_POLYGON);
        glVertex2f(142, 153);
        glVertex2f(142, 132);
        glVertex2f(145, 125);
        glVertex2f(261, 125);
        glVertex2f(261, 153);
    glEnd();
    glColor3f(0.203f, 0.188f, 0.192f);
    glBegin(GL_QUADS);
        glVertex2f(142, 153);
        glVertex2f(142, 132);
        glVertex2f(201, 132);
        glVertex2f(201, 153);
    glEnd();
    glColor3f(0.090f, 0.062f, 0.039f);
    glBegin(GL_POLYGON);
        glVertex2f(261, 153);
        glVertex2f(261, 125);
        glVertex2f(268, 135);
        glVertex2f(268, 163);
    glEnd();
    glColor3f(0.125f, 0.121f, 0.141f);
    glBegin(GL_POLYGON);
        glVertex2f(142, 153);
        glVertex2f(149, 163);
        glVertex2f(268, 163);
        glVertex2f(261, 153);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(146, 144);
        glVertex2f(146, 142);
        glVertex2f(195, 142);
        glVertex2f(195, 144);
    glEnd();
    
    //Shading
    glColor3f(0.192f, 0.145f, 0.098f);
    glBegin(GL_POLYGON);
        glVertex2f(261, 125);
        glVertex2f(318, 132);
        glVertex2f(318, 135);
        glVertex2f(268, 135);
    glEnd();
    glColor3f(0.149f, 0.101f, 0.039f);
    glBegin(GL_POLYGON);
        glVertex2f(268, 156);
        glVertex2f(286, 156);
        glVertex2f(318, 135);
        glVertex2f(268, 135);
    glEnd();
    
    //Lights
    glColor3f(0.450f, 0.443f, 0.454f);
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glVertex2f(248, 142);
    glEnd();
}

//Function to create the stuff on the second right shelf
void stuff_on_shelf_4()
{
    //LAMP
    glColor3f(0.505f, 0.427f, 0.329f);
    glBegin(GL_POLYGON);
        glVertex2f(466, 103);
        glVertex2f(423, 106);
        glVertex2f(423, 183);
        glVertex2f(466, 180);
    glEnd();
    glColor3f(0.156f, 0.113f, 0.098f);
    glBegin(GL_POLYGON);
        glVertex2f(435, 104);
        glVertex2f(423, 106);
        glVertex2f(423, 183);
        glVertex2f(435, 182);
    glEnd();
    glColor3f(0.525f, 0.517f, 0.521f);
    glBegin(GL_POLYGON);
        glVertex2f(462, 111);
        glVertex2f(427, 114);
        glVertex2f(427, 177);
        glVertex2f(462, 174);
    glEnd();
    glColor3f(0.172f, 0.141f, 0.098f);
    glBegin(GL_POLYGON);
        glVertex2f(436, 112);
        glVertex2f(427, 114);
        glVertex2f(427, 177);
        glVertex2f(436, 176);
    glEnd();
    glColor3f(0.145f, 0.090f, 0.047f);
    glBegin(GL_POLYGON);
        glVertex2f(466, 103);
        glVertex2f(501, 106);
        glVertex2f(501, 183);
        glVertex2f(466, 180);
    glEnd();
    glColor3f(0.317f, 0.301f, 0.254f);
    glBegin(GL_POLYGON);
        glVertex2f(470, 111);
        glVertex2f(497, 114);
        glVertex2f(497, 177);
        glVertex2f(470, 174);
    glEnd();
    glColor3f(0.360f, 0.317f, 0.294f);
    glBegin(GL_POLYGON);
        glVertex2f(444, 182);
        glVertex2f(469, 165);
        glVertex2f(466, 160);
        glVertex2f(441, 177);
    glEnd();
    glColor3f(0.054f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(503, 170);
        glVertex2f(469, 165);
        glVertex2f(466, 160);
        glVertex2f(501, 165);
    glEnd();
    glColor3f(0.125f, 0.074f, 0.039f);
    glBegin(GL_POLYGON);
        glVertex2f(501, 180);
        glVertex2f(466, 183);
        glVertex2f(423, 186);
        glVertex2f(466, 183);
    glEnd();
}

//Function to create the stuff on the last left shelf
void stuff_on_shelf_5()
{
    //Creates the box
    glColor3f(0.066f, 0.0f, 0.039f);
    glBegin(GL_QUADS);
        glVertex2f(168, 28);
        glVertex2f(323, 28);
        glVertex2f(323, 59);
        glVertex2f(168, 59);
    glEnd();
    glColor3f(0.133f, 0.133f, 0.141f);
    glBegin(GL_POLYGON);
        glVertex2f(183, 81);
        glVertex2f(338, 81);
        glVertex2f(323, 59);
        glVertex2f(168, 59);
    glEnd();
    glColor3f(0.066f, 0.0f, 0.039f);
    glBegin(GL_POLYGON);
        glVertex2f(338, 50);
        glVertex2f(338, 81);
        glVertex2f(323, 59);
        glVertex2f(323, 28);
    glEnd();
    
    //Lights
    glColor3f(0.898f, 0.870f, 0.839f);
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glVertex2f(175, 45);
        glVertex2f(315, 45);
    glEnd();
}

//Function to create the stuff on the last right shelf
void stuff_on_shelf_6()
{
    //First box
    glColor3f(0.933f, 0.239f, 0.215f);
    glBegin(GL_QUADS);
        glVertex2f(554, 35);
        glVertex2f(659, 35);
        glVertex2f(659, 52);
        glVertex2f(554, 52);
    glEnd();
    glColor3f(0.972f, 0.925f, 0.870f);
    glBegin(GL_POLYGON);
        glVertex2f(554, 35);
        glVertex2f(542, 50);
        glVertex2f(542, 67);
        glVertex2f(554, 52);
    glEnd();
    glColor3f(0.250f, 0.203f, 0.156f);
    glBegin(GL_POLYGON);
        glVertex2f(647, 67);
        glVertex2f(542, 67);
        glVertex2f(554, 52);
        glVertex2f(659, 52);
    glEnd();
    
    //Second box
    glColor3f(0.894f, 0.611f, 0.141f);
    glBegin(GL_QUADS);
        glVertex2f(657, 68);
        glVertex2f(644, 68);
        glVertex2f(644, 54);
        glVertex2f(657, 54);
    glEnd();
    glColor3f(0.725f, 0.635f, 0.270f);
    glBegin(GL_POLYGON);
        glVertex2f(634, 85);
        glVertex2f(634, 71);
        glVertex2f(644, 54);
        glVertex2f(644, 68);
    glEnd();
    glColor3f(0.968f, 0.756f, 0.262f);
    glBegin(GL_QUADS);
        glVertex2f(658, 67);
        glVertex2f(643, 67);
        glVertex2f(643, 71);
        glVertex2f(658, 71);
    glEnd();
    glColor3f(0.568f, 0.411f, 0.066f);
    glBegin(GL_POLYGON);
        glVertex2f(633, 89);
        glVertex2f(633, 85);
        glVertex2f(643, 67);
        glVertex2f(643, 71);
    glEnd();
    glColor3f(0.356f, 0.258f, 0.047f);
    glBegin(GL_POLYGON);
        glVertex2f(633, 89);
        glVertex2f(648, 89);
        glVertex2f(658, 71);
        glVertex2f(643, 71);
    glEnd();
    
    //Third box
    glColor3f(0.145f, 0.090f, 0.039f);
    glBegin(GL_QUADS);
        glVertex2f(653, 78);
        glVertex2f(630, 78);
        glVertex2f(630, 90);
        glVertex2f(653, 90);
    glEnd();
    glColor3f(0.090f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(606, 56);
        glVertex2f(599, 68);
        glVertex2f(599, 82);
        glVertex2f(630, 82);
        glVertex2f(634, 78);
        glVertex2f(601, 78);
        glVertex2f(606, 66);
    glEnd();
    glColor3f(1.0f, 0.847f, 0.439f);
    glBegin(GL_QUADS);
        glVertex2f(642, 56);
        glVertex2f(606, 56);
        glVertex2f(606, 65);
        glVertex2f(642, 65);
    glEnd();
    glColor3f(0.090f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(642, 65);
        glVertex2f(599, 65);
        glVertex2f(602, 73);
        glVertex2f(636, 73);
    glEnd();
    glColor3f(1.0f, 0.952f, 0.0749);
    glBegin(GL_POLYGON);
        glVertex2f(632, 67);
        glVertex2f(628, 72);
        glVertex2f(613, 72);
        glVertex2f(614, 69);
        glVertex2f(628, 69);
        glVertex2f(630, 67);
    glEnd();
    glColor3f(0.309f, 0.215f, 0.121f);
    glBegin(GL_POLYGON);
        glVertex2f(602, 73);
        glVertex2f(636, 73);
        glVertex2f(634, 78);
        glVertex2f(600, 78);
    glEnd();
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
}

//Sets initial background color
void Init()
{
    //Sets initial background color
    glClearColor(0.855, 0.729, 0.568, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Makes it so the screen can "snap"
    glOrtho(0.0, 800.0, 0.0, 600.0, 0.0, 1.0);
}

//Display function to render the picture
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    render();
    glFlush();
    glutSwapBuffers();
}

//Game loop
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Project 4: Render Your Scene With Primitives");
    glutDisplayFunc(myDisplay);
    Init();
    glutMainLoop();
    return 0;
}
