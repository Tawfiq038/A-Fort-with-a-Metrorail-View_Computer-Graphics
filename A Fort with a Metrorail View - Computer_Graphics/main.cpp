#include <windows.h>
#include <GL/glut.h>
#include <math.h>

float car1_position = 0.0f;
float car1speed = 0.3f;
float car2_position = 0.0f;
float car2speed = 0.3f;
float cloud_position = 0.0f;
float Cloudspeed = 0.1f;
float helicopter_position = 0.0f;
float helicopterspeed = 0.2f;
float train_position = 0.0f;
float trainspeed = 0.5f;
float rotaterims1 = 0.0f;
float rotaterims2 = 0.0f;
float rimsspeed1 = 5.0f;
float rimsspeed2 = 5.0f;
float position = 0.0f;
float rainspeed = 0.8;
float rotatepropeller = 0.0f;
float propellerspeed = 10.0f;

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

//void display(int val);

///***Rafin***///
void road()
{
    glBegin(GL_QUADS); //road
    glColor3f(0.415f, 0.423f, 0.427f);
    glVertex2f(-50.0f, -50.0f);
    glVertex2f(50.0f, -50.0f);
    glVertex2f(50.0f, -25.0f);
    glVertex2f(-50.0f, -25.0f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //side lines
    glVertex2f(-50.0f, -48.0f);
    glVertex2f(50.0f, -48.0f);
    glVertex2f(-50.0f, -27.0f);
    glVertex2f(-15.0f, -27.0f);
    glVertex2f(15.0f, -27.0f);
    glVertex2f(50.0f, -27.0f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //middle lines

    float x = -50.0;
    float y = -37.0;
    for (int i = 0;i < 11;i++)
    {
        glVertex2f(x, y);
        glVertex2f(x + 5.0, y);
        x = x + 10.0;
    }
    glEnd();
}

///*** Tawfiq & Rafin ***///
void land()
{
    glBegin(GL_QUADS); //land
    //glColor3ub(0, 204, 0);
    glVertex2f(-50.0f, -25.0f);
    glVertex2f(50.0f, -25.0f);
    glVertex2f(50.0f, 4.0f);
    glVertex2f(-50.0f, 4.0f);
    glEnd();

    glBegin(GL_QUADS); //land(road)
    glColor3f(0.415f, 0.423f, 0.427f);
    glVertex2f(-15.0f, -25.0f);
    glVertex2f(15.0f, -25.0f);
    glVertex2f(8.0f, -7.0f);
    glVertex2f(-8.0f, -7.0f);
    glEnd();


}

void fense()
{
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    float x = -47.5;
    float y = -24.0;
    for (int i = 0;i < 30;i++)
    {
        glVertex2f(x, y);
        glVertex2f(x, y + 8.0);
        x = x + 1.0;
    }
    glVertex2f(-48.0, -23.5f);
    glVertex2f(-18.0, -23.5f);
    glVertex2f(-48.0, -18.0f);
    glVertex2f(-18.0, -18.0f);
    glEnd();

    glBegin(GL_QUADS); //fense pillar1
    glColor3ub(221, 221, 221);
    glVertex2f(-50.0f, -24.0f);
    glVertex2f(-48.0f, -24.0f);
    glVertex2f(-48.0f, -14.0f);
    glVertex2f(-50.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS); //fense pillar2
    glColor3ub(221, 221, 221);
    glVertex2f(-18.0f, -24.0f);
    glVertex2f(-16.0f, -24.0f);
    glVertex2f(-16.0f, -14.0f);
    glVertex2f(-18.0f, -14.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    float a = 47.5;
    float b = -24.0;
    for (int i = 0;i < 30;i++)
    {
        glVertex2f(a, b);
        glVertex2f(a, b + 8.0);
        a = a - 1.0;
    }
    glVertex2f(48.0, -23.5f);
    glVertex2f(18.0, -23.5f);
    glVertex2f(48.0, -18.0f);
    glVertex2f(18.0, -18.0f);
    glEnd();

    glBegin(GL_QUADS); //fense pillar3
    glColor3ub(221, 221, 221);
    glVertex2f(18.0f, -24.0f);
    glVertex2f(16.0f, -24.0f);
    glVertex2f(16.0f, -14.0f);
    glVertex2f(18.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS); //fense pillar4
    glColor3ub(221, 221, 221);
    glVertex2f(50.0f, -24.0f);
    glVertex2f(48.0f, -24.0f);
    glVertex2f(48.0f, -14.0f);
    glVertex2f(50.0f, -14.0f);
    glEnd();
}

//**Shahriar**//
void lampost_day()
{
    glLineWidth(7);
    glBegin(GL_LINES); //lampost1
    glColor3ub(96, 96, 96);
    glVertex2f(-14.0f, -18.0f);
    glVertex2f(-14.0f, -5.0f);
    glVertex2f(-14.0f, -5.0f);
    glVertex2f(-10.0f, -5.0f);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-12.0, -5.5);
    glVertex2f(-10.0, -5.5);
    glEnd();

    glBegin(GL_LINES); //lampost2
    glColor3ub(96, 96, 96);
    glVertex2f(-12.0f, -12.0f);
    glVertex2f(-12.0f, -3.0f);
    glVertex2f(-12.0f, -3.0f);
    glVertex2f(-8.0f, -3.0f);
    glColor3ub(0, 0, 0);
    glVertex2f(-10.0, -3.5);
    glVertex2f(-8.0, -3.5);
    glEnd();

    glBegin(GL_LINES); //lampost3
    glColor3ub(96, 96, 96);
    glVertex2f(14.0f, -18.0f);
    glVertex2f(14.0f, -5.0f);
    glVertex2f(14.0f, -5.0f);
    glVertex2f(10.0f, -5.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(12.0, -5.5);
    glVertex2f(10.0, -5.5);
    glEnd();

    glBegin(GL_LINES); //lampost4
    glColor3ub(96, 96, 96);
    glVertex2f(12.0f, -12.0f);
    glVertex2f(12.0f, -3.0f);
    glVertex2f(12.0f, -3.0f);
    glVertex2f(8.0f, -3.0f);
    glColor3ub(0, 0, 0);
    glVertex2f(10.0, -3.5);
    glVertex2f(8.0, -3.5);
    glEnd();
}
//**Shahriar**///
void lampost_night()
{
    glLineWidth(7);
    glBegin(GL_LINES); //lampost1
    glColor3ub(96, 96, 96);
    glVertex2f(-14.0f, -18.0f);
    glVertex2f(-14.0f, -5.0f);
    glVertex2f(-14.0f, -5.0f);
    glVertex2f(-10.0f, -5.0f);

    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(-12.0, -5.5);
    glVertex2f(-10.0, -5.5);
    glEnd();

    glBegin(GL_LINES); //lampost2
    glColor3ub(96, 96, 96);
    glVertex2f(-12.0f, -12.0f);
    glVertex2f(-12.0f, -3.0f);
    glVertex2f(-12.0f, -3.0f);
    glVertex2f(-8.0f, -3.0f);
    glColor3ub(255, 255, 0);
    glVertex2f(-10.0, -3.5);
    glVertex2f(-8.0, -3.5);
    glEnd();

    glBegin(GL_LINES); //lampost3
    glColor3ub(96, 96, 96);
    glVertex2f(14.0f, -18.0f);
    glVertex2f(14.0f, -5.0f);
    glVertex2f(14.0f, -5.0f);
    glVertex2f(10.0f, -5.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(255, 255, 0);
    glVertex2f(12.0, -5.5);
    glVertex2f(10.0, -5.5);
    glEnd();

    glBegin(GL_LINES); //lampost4
    glColor3ub(96, 96, 96);
    glVertex2f(12.0f, -12.0f);
    glVertex2f(12.0f, -3.0f);
    glVertex2f(12.0f, -3.0f);
    glVertex2f(8.0f, -3.0f);
    glColor3ub(255, 255, 0);
    glVertex2f(10.0, -3.5);
    glVertex2f(8.0, -3.5);
    glEnd();
}

void tree()
{
    glBegin(GL_QUADS);  //tree 1 base
    glColor3ub(58, 28, 28);
    glVertex2f(40, -20);
    glVertex2f(42, -20);
    glVertex2f(42, -12);
    glVertex2f(40, -12);
    glEnd();

    glBegin(GL_TRIANGLES); //leaf 1 tree 1
    glColor3ub(54, 128, 45);
    glVertex2f(38, -12);
    glVertex2f(44, -12);
    glVertex2f(41, 0);
    glEnd();

    glBegin(GL_TRIANGLES); //leaf 2 tree 1
    glColor3ub(54, 128, 45);
    glVertex2f(38.5, -8);
    glVertex2f(43.5, -8);
    glVertex2f(41, 2);
    glEnd();

    glBegin(GL_TRIANGLES); //leaf 3 tree 1
    glColor3ub(54, 128, 45);
    glVertex2f(39, -4);
    glVertex2f(43, -4);
    glVertex2f(41, 3);
    glEnd();

    glBegin(GL_QUADS);  //tree 2 base
    glColor3ub(58, 28, 28);
    glVertex2f(-40, -20);
    glVertex2f(-42, -20);
    glVertex2f(-42, -12);
    glVertex2f(-40, -12);
    glEnd();

    glBegin(GL_TRIANGLES); //leaf 1 tree 2
    glColor3ub(54, 128, 45);
    glVertex2f(-38, -12);
    glVertex2f(-44, -12);
    glVertex2f(-41, 0);
    glEnd();

    glBegin(GL_TRIANGLES); //leaf 2 tree 2
    glColor3ub(54, 128, 45);
    glVertex2f(-38.5, -8);
    glVertex2f(-43.5, -8);
    glVertex2f(-41, 2);
    glEnd();

    glBegin(GL_TRIANGLES); //leaf 3 tree 2
    glColor3ub(54, 128, 45);
    glVertex2f(-39, -4);
    glVertex2f(-43, -4);
    glVertex2f(-41, 3);
    glEnd();


}

///*** Srastha ***///
void sky()
{
    glBegin(GL_QUADS);//sky
    glVertex2f(-50.0f, 4.0f);
    glVertex2f(50.0f, 4.0f);
    glVertex2f(50.0f, 50.0f);
    glVertex2f(-50.0f, 50.0f);
    glEnd();
}
///*** Srastha ***///
void sky_day()
{
    glBegin(GL_QUADS);//sky
    glColor3ub(135, 206, 250);
    glVertex2f(-50.0f, 4.0f);
    glVertex2f(50.0f, 4.0f);
    glColor3ub(0, 133, 255);
    glVertex2f(50.0f, 50.0f);
    glVertex2f(-50.0f, 50.0f);
    glEnd();
}
///*** Rafin ***///
void car1()
{
    glPushMatrix();
    glTranslatef(car1_position, 0.0, 0.0);

    glBegin(GL_POLYGON);  //left-car
    glColor3ub(0, 0, 255);
    glVertex2f(-40.0f, -34.0f);
    glVertex2f(-25.0f, -34.0f);
    glVertex2f(-25.0f, -30.0f);
    glVertex2f(-27.0f, -30.0f);
    glVertex2f(-29.0f, -26.0f);
    glVertex2f(-36.0f, -26.0f);
    glVertex2f(-37.0f, -30.0f);
    glVertex2f(-40.0f, -30.0f);
    glEnd();

    glBegin(GL_QUADS); //headlight
    glColor3ub(211, 211, 211);
    glVertex2f(-25.0f, -32.5f);
    glVertex2f(-25.0f, -31.0f);
    glVertex2f(-24.5f, -31.0f);
    glVertex2f(-24.5f, -32.5f);
    glEnd();

    glBegin(GL_QUADS); //car 1 mirror1
    glColor3ub(0, 0, 0);
    glVertex2f(-29.5f, -27.0f);
    glVertex2f(-32.25f, -27.0f);
    glVertex2f(-32.25f, -30.0f);
    glVertex2f(-28.0f, -30.0f);
    glEnd();

    glBegin(GL_QUADS); //car 1 mirror2
    glColor3ub(0, 0, 0);
    glVertex2f(-33.0f, -27.0f);
    glVertex2f(-33.0f, -30.0f);
    glVertex2f(-37.0f, -30.0f);
    glVertex2f(-35.5f, -27.0f);
    glEnd();

    //car 1 wheel
    circle(1.5, -28.0, -34.0, 0, 0, 0);
    circle(1.5, -37.0, -34.0, 0, 0, 0);
    glEnd();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(-28.0, -34.0, 0.0);
    glRotatef(rotaterims1, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(-37.0, -34.0, 0.0);
    glRotatef(rotaterims1, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}
void car1_night()
{
    glPushMatrix();
    glTranslatef(car1_position, 0.0, 0.0);

    glBegin(GL_POLYGON);  //left-car
    glColor3ub(0, 0, 255);
    glVertex2f(-40.0f, -34.0f);
    glVertex2f(-25.0f, -34.0f);
    glVertex2f(-25.0f, -30.0f);
    glVertex2f(-27.0f, -30.0f);
    glVertex2f(-29.0f, -26.0f);
    glVertex2f(-36.0f, -26.0f);
    glVertex2f(-37.0f, -30.0f);
    glVertex2f(-40.0f, -30.0f);
    glEnd();

    glBegin(GL_QUADS); //headlight
    glColor3ub(255, 255, 0);
    glVertex2f(-25.0f, -32.5f);
    glVertex2f(-25.0f, -31.0f);
    glVertex2f(-24.5f, -31.0f);
    glVertex2f(-24.5f, -32.5f);
    glEnd();

    glBegin(GL_QUADS); //car 1 mirror1
    glColor3ub(0, 0, 0);
    glVertex2f(-29.5f, -27.0f);
    glVertex2f(-32.25f, -27.0f);
    glVertex2f(-32.25f, -30.0f);
    glVertex2f(-28.0f, -30.0f);
    glEnd();

    glBegin(GL_QUADS); //car 1 mirror2
    glColor3ub(0, 0, 0);
    glVertex2f(-33.0f, -27.0f);
    glVertex2f(-33.0f, -30.0f);
    glVertex2f(-37.0f, -30.0f);
    glVertex2f(-35.5f, -27.0f);
    glEnd();

    //car 1 wheel
    circle(1.5, -28.0, -34.0, 0, 0, 0);
    circle(1.5, -37.0, -34.0, 0, 0, 0);
    glEnd();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(-28.0, -34.0, 0.0);
    glRotatef(rotaterims1, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(-37.0, -34.0, 0.0);
    glRotatef(rotaterims1, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}
///*** Rafin ***///
void car2()
{
    glPushMatrix();
    glTranslatef(car2_position, 0.0, 0.0);

    glBegin(GL_POLYGON);  //right-car
    glColor3ub(255, 0, 0);
    glVertex2f(40.0f, -44.0f);
    glVertex2f(25.0f, -44.0f);
    glVertex2f(25.0f, -40.0f);
    glVertex2f(27.0f, -40.0f);
    glVertex2f(29.0f, -36.0f);
    glVertex2f(36.0f, -36.0f);
    glVertex2f(38.0f, -40.0f);
    glVertex2f(40.0f, -40.0f);
    glEnd();

    glBegin(GL_QUADS); //headlight
    glColor3ub(211, 211, 211);
    glVertex2f(25.0f, -42.5f);
    glVertex2f(25.0f, -41.0f);
    glVertex2f(24.5f, -41.0f);
    glVertex2f(24.5f, -42.5f);
    glEnd();

    glBegin(GL_QUADS); //car 2 mirror1
    glColor3ub(0, 0, 0);
    glVertex2f(29.5f, -37.0f);
    glVertex2f(32.25f, -37.0f);
    glVertex2f(32.25f, -40.0f);
    glVertex2f(28.0f, -40.0f);
    glEnd();

    glBegin(GL_QUADS); //car 2 mirror2
    glColor3ub(0, 0, 0);
    glVertex2f(33.0f, -37.0f);
    glVertex2f(33.0f, -40.0f);
    glVertex2f(37.0f, -40.0f);
    glVertex2f(35.5f, -37.0f);
    glEnd();

    //car 2 wheel
    circle(1.5, 28.0, -44.0, 0, 0, 0);
    circle(1.5, 37.0, -44.0, 0, 0, 0);
    glEnd();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(28.0, -44.0, 0.0);
    glRotatef(rotaterims2, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(37.0, -44.0, 0.0);
    glRotatef(rotaterims2, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void car2_night()
{
    glPushMatrix();
    glTranslatef(car2_position, 0.0, 0.0);

    glBegin(GL_POLYGON);  //right-car
    glColor3ub(255, 0, 0);
    glVertex2f(40.0f, -44.0f);
    glVertex2f(25.0f, -44.0f);
    glVertex2f(25.0f, -40.0f);
    glVertex2f(27.0f, -40.0f);
    glVertex2f(29.0f, -36.0f);
    glVertex2f(36.0f, -36.0f);
    glVertex2f(38.0f, -40.0f);
    glVertex2f(40.0f, -40.0f);
    glEnd();

    glBegin(GL_QUADS); //headlight
    glColor3ub(255, 255, 0);
    glVertex2f(25.0f, -42.5f);
    glVertex2f(25.0f, -41.0f);
    glVertex2f(24.5f, -41.0f);
    glVertex2f(24.5f, -42.5f);
    glEnd();

    glBegin(GL_QUADS); //car 2 mirror1
    glColor3ub(0, 0, 0);
    glVertex2f(29.5f, -37.0f);
    glVertex2f(32.25f, -37.0f);
    glVertex2f(32.25f, -40.0f);
    glVertex2f(28.0f, -40.0f);
    glEnd();

    glBegin(GL_QUADS); //car 2 mirror2
    glColor3ub(0, 0, 0);
    glVertex2f(33.0f, -37.0f);
    glVertex2f(33.0f, -40.0f);
    glVertex2f(37.0f, -40.0f);
    glVertex2f(35.5f, -37.0f);
    glEnd();

    //car 2 wheel
    circle(1.5, 28.0, -44.0, 0, 0, 0);
    circle(1.5, 37.0, -44.0, 0, 0, 0);
    glEnd();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(28.0, -44.0, 0.0);
    glRotatef(rotaterims2, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glLineWidth(5);
    glTranslatef(37.0, -44.0, 0.0);
    glRotatef(rotaterims2, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.5, 0.0);
    glVertex2f(1.5, 0.0);
    glVertex2f(0.0, 1.5);
    glVertex2f(0.0, -1.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void update_car1(int value)  //car1 animation
{

    if (car1_position >= 90) //screen size
    {
        car1_position = -45;
    }

    car1_position += car1speed;
    glutPostRedisplay();

    glutTimerFunc(20, update_car1, 0);

}

void update_car2(int value)  //car2 animation
{

    if (car2_position < -90) //screen size
    {
        car2_position = 45;
    }

    car2_position -= car2speed;
    glutPostRedisplay();

    glutTimerFunc(20, update_car2, 0);

}

void rotate_rims1(int value)
{

    rotaterims1 -= rimsspeed1;

    if (rotaterims1 < -360.0)
    {
        rotaterims1 += 360;
    }

    glutPostRedisplay();

    glutTimerFunc(20, rotate_rims1, 0);
}
void rotate_rims2(int value)
{

    rotaterims2 += rimsspeed2;

    if (rotaterims2 < -360.0)
    {
        rotaterims2 += 360;
    }

    glutPostRedisplay();

    glutTimerFunc(20, rotate_rims2, 0);
}

///*** Srastha ***///
void sun()
{

    circle(4.0, 35.0, 40.0, 255, 255, 0); //sun
}


///*** Srastha ***///
void moon()
{
    circle(4.0, 35.0, 40.0, 244, 241, 201);
}
///*** Srastha & Shahriar ***///
void fort()
{
    glBegin(GL_QUADS);//ground
    glColor3f(0.415f, 0.423f, 0.427f);
    glVertex2f(-35.0f, -8.0f);
    glVertex2f(35.0f, -8.0f);
    glVertex2f(33.0f, -5.0f);
    glVertex2f(-33.0f, -5.0f);
    glEnd();

    glBegin(GL_QUADS);//step
    glColor3ub(192, 192, 192);
    glVertex2f(-30.0f, -7.0f);
    glVertex2f(30.0f, -7.0f);
    glVertex2f(30.0f, -8.0f);
    glVertex2f(-30.0f, -8.0f);
    glEnd();

    glBegin(GL_QUADS);//base1
    glColor3ub(221, 221, 221);
    glVertex2f(-30.0f, -7.0f);
    glVertex2f(30.0f, -7.0f);
    glVertex2f(30.0f, 7.0f);
    glVertex2f(-30.0f, 7.0f);
    glEnd();
    //***base1 -door,windows***
    glBegin(GL_POLYGON); //door big
    glColor3ub(192, 192, 192);
    glVertex2f(-5.0f, -7.0f);
    glVertex2f(5.0f, -7.0f);
    glVertex2f(5.0f, 3.0f);
    glVertex2f(-5.0f, 3.0f);
    glEnd();

    glBegin(GL_QUADS); //door left
    glColor3ub(0, 0, 0);
    glVertex2f(-4.0, -7.0);
    glVertex2f(-0.5f, -7.0f);
    glVertex2f(-0.5f, 2.0f);
    glVertex2f(-4.0f, 2.0f);
    glEnd();

    glBegin(GL_QUADS); //door right
    glColor3ub(0, 0, 0);
    glVertex2f(4.0, -7.0);
    glVertex2f(0.5f, -7.0f);
    glVertex2f(0.5f, 2.0f);
    glVertex2f(4.0f, 2.0f);
    glEnd();

    glBegin(GL_QUADS); //left window 1
    glColor3ub(192, 192, 192);
    glVertex2f(-23.0, -7.0);
    glVertex2f(-20.0f, -7.0f);
    glVertex2f(-20.0f, 1.0f);
    glVertex2f(-23.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //left window 1
    glColor3ub(0, 0, 0);
    glVertex2f(-22.5, 0.5);
    glVertex2f(-20.5f, 0.5f);
    glVertex2f(-20.5f, -5.0f);
    glVertex2f(-22.5f, -5.0f);
    glEnd();


    glBegin(GL_QUADS); //left window 2
    glColor3ub(192, 192, 192);
    glVertex2f(-17.0, -7.0);
    glVertex2f(-14.0f, -7.0f);
    glVertex2f(-14.0f, 1.0f);
    glVertex2f(-17.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //left window 2
    glColor3ub(0, 0, 0);
    glVertex2f(-16.5, 0.5);
    glVertex2f(-14.5f, 0.5f);
    glVertex2f(-14.5f, -5.0f);
    glVertex2f(-16.5f, -5.0f);
    glEnd();

    glBegin(GL_QUADS); //left window 3
    glColor3ub(192, 192, 192);
    glVertex2f(-11.0, -7.0);
    glVertex2f(-8.0f, -7.0f);
    glVertex2f(-8.0f, 1.0f);
    glVertex2f(-11.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //left window 3
    glColor3ub(0, 0, 0);
    glVertex2f(-10.5, 0.5);
    glVertex2f(-8.5f, 0.5f);
    glVertex2f(-8.5f, -5.0f);
    glVertex2f(-10.5f, -5.0f);
    glEnd();

    glBegin(GL_QUADS); //right window 1
    glColor3ub(192, 192, 192);
    glVertex2f(11.0, -7.0);
    glVertex2f(8.0f, -7.0f);
    glVertex2f(8.0f, 1.0f);
    glVertex2f(11.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //right window 1
    glColor3ub(0, 0, 0);
    glVertex2f(10.5, 0.5);
    glVertex2f(8.5f, 0.5f);
    glVertex2f(8.5f, -5.0f);
    glVertex2f(10.5f, -5.0f);
    glEnd();

    glBegin(GL_QUADS); //right window 2
    glColor3ub(192, 192, 192);
    glVertex2f(17.0, -7.0);
    glVertex2f(14.0f, -7.0f);
    glVertex2f(14.0f, 1.0f);
    glVertex2f(17.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //right window 2
    glColor3ub(0, 0, 0);
    glVertex2f(16.5, 0.5);
    glVertex2f(14.5f, 0.5f);
    glVertex2f(14.5f, -5.0f);
    glVertex2f(16.5f, -5.0f);
    glEnd();

    glBegin(GL_QUADS); //right window 3
    glColor3ub(192, 192, 192);
    glVertex2f(23.0, -7.0);
    glVertex2f(20.0f, -7.0f);
    glVertex2f(20.0f, 1.0f);
    glVertex2f(23.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS); //right window 3
    glColor3ub(0, 0, 0);
    glVertex2f(22.5, 0.5);
    glVertex2f(20.5f, 0.5f);
    glVertex2f(20.5f, -5.0f);
    glVertex2f(22.5f, -5.0f);
    glEnd();



    glBegin(GL_LINES); //left-right shading part
    glColor3ub(0, 0, 0);
    glVertex2f(-26.0f, -7.0f);
    glVertex2f(-26.0f, 7.0f);
    glVertex2f(26.0f, -7.0f);
    glVertex2f(26.0f, 7.0f);
    glEnd();

    glBegin(GL_QUADS);//base2
    glColor3ub(128, 128, 128);
    glVertex2f(-20.0f, 7.0f);
    glVertex2f(20.0f, 7.0f);
    glVertex2f(20.0f, 16.0f);
    glVertex2f(-20.0f, 16.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-17.0f, 7.0f);
    glVertex2f(-17.0f, 16.0f);

    glVertex2f(17.0f, 7.0f);
    glVertex2f(17.0f, 16.0f);
    glEnd();

    glBegin(GL_QUADS); //window 1
    glColor3ub(192, 192, 192);
    glVertex2f(-14.0, 7.0);
    glVertex2f(-11.0f, 7.0f);
    glVertex2f(-11.0f, 15.0f);
    glVertex2f(-14.0f, 15.0f);
    glEnd();
    glBegin(GL_QUADS); //window 1
    glColor3ub(0, 0, 0);
    glVertex2f(-13.5, 14.5);
    glVertex2f(-13.5f, 9.0f);
    glVertex2f(-11.5f, 9.0f);
    glVertex2f(-11.5f, 14.5f);
    glEnd();

    glBegin(GL_QUADS); //window 2
    glColor3ub(192, 192, 192);
    glVertex2f(-8.0, 7.0);
    glVertex2f(-5.0f, 7.0f);
    glVertex2f(-5.0f, 15.0f);
    glVertex2f(-8.0f, 15.0f);
    glEnd();

    glBegin(GL_QUADS); //window 2
    glColor3ub(0, 0, 0);
    glVertex2f(-7.5, 14.5);
    glVertex2f(-7.5f, 9.0f);
    glVertex2f(-5.5f, 9.0f);
    glVertex2f(-5.5f, 14.5f);
    glEnd();

    glBegin(GL_QUADS); //window 3
    glColor3ub(192, 192, 192);
    glVertex2f(-2.0, 7.0);
    glVertex2f(1.0f, 7.0f);
    glVertex2f(1.0f, 15.0f);
    glVertex2f(-2.0f, 15.0f);
    glEnd();

    glBegin(GL_QUADS); //window 3
    glColor3ub(0, 0, 0);
    glVertex2f(-1.5, 14.5);
    glVertex2f(-1.5f, 9.0f);
    glVertex2f(0.5f, 9.0f);
    glVertex2f(0.5f, 14.5f);
    glEnd();

    glBegin(GL_QUADS); //window 4
    glColor3ub(192, 192, 192);
    glVertex2f(4.0, 7.0);
    glVertex2f(7.0f, 7.0f);
    glVertex2f(7.0f, 15.0f);
    glVertex2f(4.0f, 15.0f);
    glEnd();

    glBegin(GL_QUADS); //window 4
    glColor3ub(0, 0, 0);
    glVertex2f(4.5, 14.5);
    glVertex2f(4.5f, 9.0f);
    glVertex2f(6.5f, 9.0f);
    glVertex2f(6.5f, 14.5f);
    glEnd();

    glBegin(GL_QUADS); //window 5
    glColor3ub(192, 192, 192);
    glVertex2f(10.0, 7.0);
    glVertex2f(13.0f, 7.0f);
    glVertex2f(13.0f, 15.0f);
    glVertex2f(10.0f, 15.0f);
    glEnd();

    glBegin(GL_QUADS); //window 5
    glColor3ub(0, 0, 0);
    glVertex2f(10.5, 14.5);
    glVertex2f(10.5f, 9.0f);
    glVertex2f(12.5f, 9.0f);
    glVertex2f(12.5f, 14.5f);
    glEnd();

    glBegin(GL_QUADS);//base3
    glColor3ub(221, 221, 221);
    glVertex2f(-16.0f, 16.0f);
    glVertex2f(16.0f, 16.0f);
    glVertex2f(16.0f, 18.0f);
    glVertex2f(-16.0f, 18.0f);
    glEnd();


    glBegin(GL_QUADS);//base4
    glColor3ub(128, 128, 128);
    glVertex2f(-12.0f, 18.0f);
    glVertex2f(12.0f, 18.0f);
    glVertex2f(12.0f, 20.0f);
    glVertex2f(-12.0f, 20.0f);
    glEnd();

    glBegin(GL_QUADS);//base5
    glColor3ub(221, 221, 221);
    glVertex2f(-8.0f, 20.0f);
    glVertex2f(8.0f, 20.0f);
    glVertex2f(8.0f, 22.0f);
    glVertex2f(-8.0f, 22.0f);
    glEnd();



    glBegin(GL_TRIANGLES);//base5
    glColor3ub(128, 128, 128);
    glVertex2f(-8.0f, 22.0f);
    glVertex2f(8.0f, 22.0f);
    glVertex2f(0.0f, 25.0f);

    glEnd();

}
///*** Srastha ***///
void cloud1()
{

    circle(2.5, 35.0, 35.0, 240, 240, 240);
    circle(2, 37.0, 37.0, 240, 240, 240);
    circle(2.5, 40.0, 35.0, 240, 240, 240);
    circle(2, 37.0, 33.0, 240, 240, 240);
}

void cloud2()
{
    circle(2.5, -35.0, 37.0, 240, 240, 240);
    circle(2, -37.0, 39.0, 240, 240, 240);
    circle(2.5, -40.0, 37.0, 240, 240, 240);
    circle(2, -37.0, 35.0, 240, 240, 240);
}
///*** Srastha ***///
void cloud()
{
    glPushMatrix();
    glTranslatef(cloud_position, 0, 0);
    cloud1();
    cloud2();
    glPopMatrix();
}
void rain_cloud()
{
    glPushMatrix();
    glTranslatef(cloud_position, 0, 0);

    circle(2.5, 35.0, 35.0, 204, 204, 204);
    circle(2, 37.0, 37.0, 204, 204, 204);
    circle(2.5, 40.0, 35.0, 204, 204, 204);
    circle(2, 37.0, 33.0, 204, 204, 204);

    circle(2.5, -35.0, 37.0, 204, 204, 204);
    circle(2, -37.0, 39.0, 204, 204, 204);
    circle(2.5, -40.0, 37.0, 204, 204, 204);
    circle(2, -37.0, 35.0, 204, 204, 204);

    glPopMatrix();
}
void move_cloud(int value)
{

    cloud_position += Cloudspeed;

    if (cloud_position > 75)
    {
        cloud_position = -45;
    }

    glutPostRedisplay();

    glutTimerFunc(20, move_cloud, 0);
}


///*** Srastha and Shahriar***///
void helicopter()
{
    ///*** Srastha ***///
    glPushMatrix();
    glTranslatef(helicopter_position, 0.0, 0.0);
    glBegin(GL_POLYGON); //body
    glColor3ub(95, 95, 95);
    glVertex2f(-35.0f, 40.0f);
    glVertex2f(-25.0f, 40.0f);
    glVertex2f(-24.0f, 41.0f);
    glVertex2f(-27.0f, 44.0f);
    glVertex2f(-30.0f, 46.0f);
    glVertex2f(-35.0f, 43.0f);
    glEnd();

    glBegin(GL_QUADS); //window1
    glColor3ub(0, 0, 0);
    glVertex2f(-27.0f, 44.0f);
    glVertex2f(-25.0f, 42.0f);
    glVertex2f(-28.0f, 42.0f);
    glVertex2f(-28.0f, 44.0f);
    glEnd();

    glBegin(GL_QUADS); //window2
    glColor3ub(0, 0, 0);
    glVertex2f(-29.0f, 44.0f);
    glVertex2f(-29.0f, 42.0f);
    glVertex2f(-30.0f, 42.0f);
    glVertex2f(-30.0f, 44.0f);
    glEnd();

    glBegin(GL_QUADS); //window3
    glColor3ub(0, 0, 0);
    glVertex2f(-31.0f, 44.0f);
    glVertex2f(-31.0f, 42.0f);
    glVertex2f(-32.0f, 42.0f);
    glVertex2f(-32.0f, 44.0f);
    glEnd();

    glBegin(GL_POLYGON); //tail
    glColor3ub(95, 95, 95);
    glVertex2f(-35.0f, 43.0f);
    glVertex2f(-45.0f, 43.0f);
    glVertex2f(-45.0f, 42.0f);

    glVertex2f(-38.0f, 41.5f);
    glVertex2f(-35.0f, 40.0f);
    glEnd();

    glBegin(GL_QUADS); //propeller part
    glColor3ub(95, 95, 95);
    glVertex2f(-44.0f, 43.0f);
    glVertex2f(-45.0f, 43.0f);
    glVertex2f(-45.0f, 45.0f);
    glVertex2f(-44.0f, 45.0f);
    glEnd();

    ///*** Shariar ***///
    glPushMatrix();
    glTranslatef(-44.5f, 44.5f, 0.0f);
    glRotatef(rotatepropeller, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS); //propeller small
    glColor3ub(0, 0, 0);
    glVertex2f(-2.5f, 0.5f);
    glVertex2f(-2.5f, -0.5f);
    glVertex2f(2.5f, -0.5f);
    glVertex2f(2.5f, 0.5f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-30.0f, 46.0f, 0.0f);
    glRotatef(rotatepropeller, 0.0, 1.0, 1.0);
    glBegin(GL_QUADS); //main propeller
    glColor3ub(0, 0, 0);

    glVertex2f(-7.0f, 0.5f);
    glVertex2f(-7.0f, -0.5f);
    glVertex2f(7.0f, -0.5f);
    glVertex2f(7.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}

void helicopter_night()
{
    ///*** Srastha ***///
    glPushMatrix();
    glTranslatef(helicopter_position, 0.0, 0.0);
    glBegin(GL_POLYGON); //body
    glColor3ub(95, 95, 95);
    glVertex2f(-35.0f, 40.0f);
    glVertex2f(-25.0f, 40.0f);
    glVertex2f(-24.0f, 41.0f);
    glVertex2f(-27.0f, 44.0f);
    glVertex2f(-30.0f, 46.0f);
    glVertex2f(-35.0f, 43.0f);
    glEnd();

    glBegin(GL_QUADS); //window1
    glColor3ub(255, 255, 0);
    glVertex2f(-27.0f, 44.0f);
    glVertex2f(-25.0f, 42.0f);
    glVertex2f(-28.0f, 42.0f);
    glVertex2f(-28.0f, 44.0f);
    glEnd();

    glBegin(GL_QUADS); //window2
    glColor3ub(255, 255, 0);
    glVertex2f(-29.0f, 44.0f);
    glVertex2f(-29.0f, 42.0f);
    glVertex2f(-30.0f, 42.0f);
    glVertex2f(-30.0f, 44.0f);
    glEnd();

    glBegin(GL_QUADS); //window3
    glColor3ub(255, 255, 0);
    glVertex2f(-31.0f, 44.0f);
    glVertex2f(-31.0f, 42.0f);
    glVertex2f(-32.0f, 42.0f);
    glVertex2f(-32.0f, 44.0f);
    glEnd();

    glBegin(GL_POLYGON); //tail
    glColor3ub(95, 95, 95);
    glVertex2f(-35.0f, 43.0f);
    glVertex2f(-45.0f, 43.0f);
    glVertex2f(-45.0f, 42.0f);

    glVertex2f(-38.0f, 41.5f);
    glVertex2f(-35.0f, 40.0f);
    glEnd();

    glBegin(GL_QUADS); //propeller part
    glColor3ub(95, 95, 95);
    glVertex2f(-44.0f, 43.0f);
    glVertex2f(-45.0f, 43.0f);
    glVertex2f(-45.0f, 45.0f);
    glVertex2f(-44.0f, 45.0f);
    glEnd();

    ///*** Shariar ***///
    glPushMatrix();
    glTranslatef(-44.5f, 44.5f, 0.0f);
    glRotatef(rotatepropeller, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS); //propeller small
    glColor3ub(0, 0, 0);
    glVertex2f(-2.5f, 0.5f);
    glVertex2f(-2.5f, -0.5f);
    glVertex2f(2.5f, -0.5f);
    glVertex2f(2.5f, 0.5f);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-30.0f, 46.0f, 0.0f);
    glRotatef(rotatepropeller, 0.0, 1.0, 1.0);
    glBegin(GL_QUADS); //main propeller
    glColor3ub(0, 0, 0);

    glVertex2f(-7.0f, 0.5f);
    glVertex2f(-7.0f, -0.5f);
    glVertex2f(7.0f, -0.5f);
    glVertex2f(7.0f, 0.5f);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}
void update_helicopter(int value)
{

    helicopter_position += helicopterspeed;

    if (helicopter_position > 100)
    {
        helicopter_position = -45;
    }


    glutPostRedisplay();

    glutTimerFunc(20, update_helicopter, 0);

}
void rotate_propeller(int value)
{

    rotatepropeller -= propellerspeed;

    if (rotatepropeller < -360.0)
    {
        rotatepropeller += 360;
    }

    glutPostRedisplay();

    glutTimerFunc(20, rotate_propeller, 0);
}

///*** Tawfiq ***///
void train_track()
{
    glBegin(GL_QUADS); //piller1
    glColor3ub(128, 128, 128);
    glVertex2f(-45.0f, 4.0f);
    glVertex2f(-44.0f, 4.0f);
    glVertex2f(-44.0f, 10.0f);
    glVertex2f(-45.0f, 10.0f);
    glEnd();

    glBegin(GL_QUADS); //piller1
    glColor3ub(128, 128, 128);
    glVertex2f(-46.0f, 10.0f);
    glVertex2f(-43.0f, 10.0f);
    glVertex2f(-43.0f, 11.0f);
    glVertex2f(-46.0f, 11.0f);
    glEnd();

    glBegin(GL_QUADS); //piller2
    glColor3ub(128, 128, 128);
    glVertex2f(-32.0f, 4.0f);
    glVertex2f(-31.0f, 4.0f);
    glVertex2f(-31.0f, 10.0f);
    glVertex2f(-32.0f, 10.0f);
    glEnd();

    glBegin(GL_QUADS); //piller2
    glColor3ub(128, 128, 128);
    glVertex2f(-33.0f, 10.0f);
    glVertex2f(-30.0f, 10.0f);
    glVertex2f(-30.0f, 11.0f);
    glVertex2f(-33.0f, 11.0f);
    glEnd();

    glBegin(GL_QUADS); //piller3
    glColor3ub(128, 128, 128);
    glVertex2f(32.0f, 4.0f);
    glVertex2f(31.0f, 4.0f);
    glVertex2f(31.0f, 10.0f);
    glVertex2f(32.0f, 10.0f);
    glEnd();

    glBegin(GL_QUADS); //piller3
    glColor3ub(128, 128, 128);
    glVertex2f(33.0f, 10.0f);
    glVertex2f(30.0f, 10.0f);
    glVertex2f(30.0f, 11.0f);
    glVertex2f(33.0f, 11.0f);
    glEnd();

    glBegin(GL_QUADS); //piller4
    glColor3ub(128, 128, 128);
    glVertex2f(45.0f, 4.0f);
    glVertex2f(44.0f, 4.0f);
    glVertex2f(44.0f, 10.0f);
    glVertex2f(45.0f, 10.0f);
    glEnd();

    glBegin(GL_QUADS); //piller4
    glColor3ub(128, 128, 128);
    glVertex2f(46.0f, 10.0f);
    glVertex2f(43.0f, 10.0f);
    glVertex2f(43.0f, 11.0f);
    glVertex2f(46.0f, 11.0f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-50.0, 11.0);
    glVertex2f(50.0, 11.0);
    glEnd();

}
///*** Tawfiq ***///
void train()
{

    glPushMatrix();
    glTranslatef(train_position, 0.0, 0.0);
    glBegin(GL_POLYGON);    //metro/train
    glColor3ub(211, 211, 211);
    glVertex2f(21.0, 11.0);
    glVertex2f(25.0, 14.0);
    glVertex2f(48.0, 14.0);
    glVertex2f(48.0, 11.0);
    glVertex2f(21.0, 11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);    //driver window
    glVertex2f(26.0, 13.5);
    glVertex2f(28.0, 13.5);
    glVertex2f(28.0, 12.0);
    glVertex2f(26.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);  //window 1
    glColor3ub(0, 128, 255);
    glVertex2f(29.0, 13.5);
    glVertex2f(35.0, 13.5);
    glVertex2f(35.0, 12.0);
    glVertex2f(29.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);  //window 2
    glColor3ub(0, 128, 255);
    glVertex2f(36.0, 13.5);
    glVertex2f(42.0, 13.5);
    glVertex2f(42.0, 12.0);
    glVertex2f(36.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);  //window 3
    glColor3ub(0, 128, 255);
    glVertex2f(43.0, 13.5);
    glVertex2f(47.0, 13.5);
    glVertex2f(47.0, 12.0);
    glVertex2f(43.0, 12.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3ub(0, 255, 60);
    glVertex2f(22.0, 11.5);
    glVertex2f(47.0, 11.5);
    glEnd();
    glPopMatrix();

}

void train_night()
{

    glPushMatrix();
    glTranslatef(train_position, 0.0, 0.0);
    glBegin(GL_POLYGON);    //metro/train
    glColor3ub(211, 211, 211);
    glVertex2f(21.0, 11.0);
    glVertex2f(25.0, 14.0);
    glVertex2f(48.0, 14.0);
    glVertex2f(48.0, 11.0);
    glVertex2f(21.0, 11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 153);    //driver window
    glVertex2f(26.0, 13.5);
    glVertex2f(28.0, 13.5);
    glVertex2f(28.0, 12.0);
    glVertex2f(26.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);  //window 1
    glColor3ub(0, 128, 255);
    glVertex2f(29.0, 13.5);
    glVertex2f(35.0, 13.5);
    glVertex2f(35.0, 12.0);
    glVertex2f(29.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);  //window 2
    glColor3ub(0, 128, 255);
    glVertex2f(36.0, 13.5);
    glVertex2f(42.0, 13.5);
    glVertex2f(42.0, 12.0);
    glVertex2f(36.0, 12.0);
    glEnd();

    glBegin(GL_QUADS);  //window 3
    glColor3ub(0, 128, 255);
    glVertex2f(43.0, 13.5);
    glVertex2f(47.0, 13.5);
    glVertex2f(47.0, 12.0);
    glVertex2f(43.0, 12.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3ub(0, 255, 60);
    glVertex2f(22.0, 11.5);
    glVertex2f(47.0, 11.5);
    glEnd();
    glPopMatrix();

}
void update_train(int value)  //train animation
{

    if (train_position < -120)
    {
        train_position = 45;
    }

    train_position -= trainspeed;
    glutPostRedisplay();

    glutTimerFunc(20, update_train, 0);

}
///*** Shahriar ***///
void fortlight_day()
{
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-29.5, 7.0);
    glVertex2f(-29.5, 9.0);
    glVertex2f(29.5, 7.0);
    glVertex2f(29.5, 9.0);
    glEnd();

    circle(1.0, -29.5, 9.0, 211, 211, 211);
    circle(1.0, 29.5, 9.0, 211, 211, 211);

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-19.5, 16.0);
    glVertex2f(-19.5, 18.0);
    glVertex2f(19.5, 16.0);
    glVertex2f(19.5, 18.0);
    glEnd();

    circle(1.0, -19.5, 18.0, 211, 211, 211);
    circle(1.0, 19.5, 18.0, 211, 211, 211);
}
void fortlight_night()
{
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-29.5, 7.0);
    glVertex2f(-29.5, 9.0);
    glVertex2f(29.5, 7.0);
    glVertex2f(29.5, 9.0);
    glEnd();

    circle(1.0, -29.5, 9.0, 255, 255, 0);
    circle(1.0, 29.5, 9.0, 255, 255, 0);

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-19.5, 16.0);
    glVertex2f(-19.5, 18.0);
    glVertex2f(19.5, 16.0);
    glVertex2f(19.5, 18.0);
    glEnd();

    circle(1.0, -19.5, 18.0, 255, 255, 0);
    circle(1.0, 19.5, 18.0, 255, 255, 0);
}

void star()
{
    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);

    for (float x = 45.0f; x >= -45.0f; x -= 5.0) {
        for (float y = 45.0f; y >= 30.0f; y -= 5.0) {
            glVertex2f(x, y);
        }
    }

    for (float x = 47.5f; x >= -47.5f; x -= 5.0f) {
        for (float y = 47.5f; y >= 32.5f; y -= 5.0f) {
            glVertex2f(x, y);
        }
    }

    glEnd();

}

void building()
{
    glBegin(GL_QUADS); //main building 1
    glColor3ub(202, 88, 31);
    glVertex2f(40, 4);
    glVertex2f(45, 4);
    glVertex2f(45, 20);
    glVertex2f(40, 20);

    glColor3ub(0, 0, 0);
    glVertex2f(40.5, 19);
    glVertex2f(42, 19);
    glVertex2f(42, 17);
    glVertex2f(40.5, 17);

    glColor3ub(0, 0, 0);
    glVertex2f(43, 19);
    glVertex2f(44.5, 19);
    glVertex2f(44.5, 17);
    glVertex2f(43, 17);

    glColor3ub(0, 0, 0);
    glVertex2f(40.5, 15.5);
    glVertex2f(42, 15.5);
    glVertex2f(42, 13.5);
    glVertex2f(40.5, 13.5);

    glColor3ub(0, 0, 0);
    glVertex2f(43, 15.5);
    glVertex2f(44.5, 15.5);
    glVertex2f(44.5, 13.5);
    glVertex2f(43, 13.5);

    glColor3ub(0, 0, 0);
    glVertex2f(40.5, 10.5);
    glVertex2f(42, 10.5);
    glVertex2f(42, 8.5);
    glVertex2f(40.5, 8.5);

    glColor3ub(0, 0, 0);
    glVertex2f(40.5, 7);
    glVertex2f(42, 7);
    glVertex2f(42, 5);
    glVertex2f(40.5, 5);



    glColor3ub(235, 149, 106); //side shade
    glVertex2f(45, 20);
    glVertex2f(47, 18);
    glVertex2f(47, 4);
    glVertex2f(45, 4);
    glEnd();

    glBegin(GL_QUADS); //main building 2
    glColor3ub(216, 174, 34);
    glVertex2f(-40, 4);
    glVertex2f(-45, 4);
    glVertex2f(-45, 20);
    glVertex2f(-40, 20);

    glColor3ub(0, 0, 0);
    glVertex2f(-40.5, 19);
    glVertex2f(-42, 19);
    glVertex2f(-42, 17);
    glVertex2f(-40.5, 17);

    glColor3ub(0, 0, 0);
    glVertex2f(-43, 19);
    glVertex2f(-44.5, 19);
    glVertex2f(-44.5, 17);
    glVertex2f(-43, 17);

    glColor3ub(0, 0, 0);
    glVertex2f(-40.5, 15.5);
    glVertex2f(-42, 15.5);
    glVertex2f(-42, 13.5);
    glVertex2f(-40.5, 13.5);

    glColor3ub(0, 0, 0);
    glVertex2f(-43, 15.5);
    glVertex2f(-44.5, 15.5);
    glVertex2f(-44.5, 13.5);
    glVertex2f(-43, 13.5);

    glColor3ub(0, 0, 0);
    glVertex2f(-40.5, 10.5);
    glVertex2f(-42, 10.5);
    glVertex2f(-42, 8.5);
    glVertex2f(-40.5, 8.5);

    glColor3ub(0, 0, 0);
    glVertex2f(-40.5, 7);
    glVertex2f(-42, 7);
    glVertex2f(-42, 5);
    glVertex2f(-40.5, 5);



    glColor3ub(246, 224, 152); //side shade
    glVertex2f(-40, 20);
    glVertex2f(-38, 18);
    glVertex2f(-38, 4);
    glVertex2f(-40, 4);

    glEnd();


}

void building_night()
{
    glBegin(GL_QUADS); //main building 1
    glColor3ub(202, 88, 31);
    glVertex2f(40, 4);
    glVertex2f(45, 4);
    glVertex2f(45, 20);
    glVertex2f(40, 20);

    glColor3ub(255, 255, 0);
    glVertex2f(40.5, 19);
    glVertex2f(42, 19);
    glVertex2f(42, 17);
    glVertex2f(40.5, 17);

    glColor3ub(255, 255, 0);
    glVertex2f(43, 19);
    glVertex2f(44.5, 19);
    glVertex2f(44.5, 17);
    glVertex2f(43, 17);

    glColor3ub(255, 255, 0);
    glVertex2f(40.5, 15.5);
    glVertex2f(42, 15.5);
    glVertex2f(42, 13.5);
    glVertex2f(40.5, 13.5);

    glColor3ub(255, 255, 0);
    glVertex2f(43, 15.5);
    glVertex2f(44.5, 15.5);
    glVertex2f(44.5, 13.5);
    glVertex2f(43, 13.5);

    glColor3ub(255, 255, 0);
    glVertex2f(40.5, 10.5);
    glVertex2f(42, 10.5);
    glVertex2f(42, 8.5);
    glVertex2f(40.5, 8.5);

    glColor3ub(255, 255, 0);
    glVertex2f(40.5, 7);
    glVertex2f(42, 7);
    glVertex2f(42, 5);
    glVertex2f(40.5, 5);



    glColor3ub(235, 149, 106); //side shade
    glVertex2f(45, 20);
    glVertex2f(47, 18);
    glVertex2f(47, 4);
    glVertex2f(45, 4);

    glEnd();

    glBegin(GL_QUADS); //main building 2
    glColor3ub(216, 174, 34);
    glVertex2f(-40, 4);
    glVertex2f(-45, 4);
    glVertex2f(-45, 20);
    glVertex2f(-40, 20);

    glColor3ub(255, 255, 0);
    glVertex2f(-40.5, 19);
    glVertex2f(-42, 19);
    glVertex2f(-42, 17);
    glVertex2f(-40.5, 17);

    glColor3ub(255, 255, 0);
    glVertex2f(-43, 19);
    glVertex2f(-44.5, 19);
    glVertex2f(-44.5, 17);
    glVertex2f(-43, 17);

    glColor3ub(255, 255, 0);
    glVertex2f(-40.5, 15.5);
    glVertex2f(-42, 15.5);
    glVertex2f(-42, 13.5);
    glVertex2f(-40.5, 13.5);

    glColor3ub(255, 255, 0);
    glVertex2f(-43, 15.5);
    glVertex2f(-44.5, 15.5);
    glVertex2f(-44.5, 13.5);
    glVertex2f(-43, 13.5);

    glColor3ub(255, 255, 0);
    glVertex2f(-40.5, 10.5);
    glVertex2f(-42, 10.5);
    glVertex2f(-42, 8.5);
    glVertex2f(-40.5, 8.5);

    glColor3ub(255, 255, 0);
    glVertex2f(-40.5, 7);
    glVertex2f(-42, 7);
    glVertex2f(-42, 5);
    glVertex2f(-40.5, 5);



    glColor3ub(246, 224, 152); //side shade
    glVertex2f(-40, 20);
    glVertex2f(-38, 18);
    glVertex2f(-38, 4);
    glVertex2f(-40, 4);

    glEnd();


}

void rain()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(10);

    glPushMatrix();
    road();
    glColor3ub(0, 153, 0);
    land();
    tree();
    fense();
    //rain-sky

    glBegin(GL_QUADS);//sky
    glColor3ub(77, 184, 255);
    glVertex2f(-50.0f, 4.0f);
    glColor3ub(224, 224, 224);
    glVertex2f(50.0f, 4.0f);

    glVertex2f(50.0f, 50.0f);
    glVertex2f(-50.0f, 50.0f);
    glEnd();

    building();
    train_track();
    train();
    fort();
    lampost_day();
    car1();
    car2();

    rain_cloud();
    helicopter();
    fortlight_day();

    //rain design & droping
    glPushMatrix();
    glTranslatef(-position, position, 0.0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    for (float x = 50.0f; x >= -50.0f; x -= 5.0f) {
        for (float y = 50.0f; y >= -50.0f; y -= 5.0f) {
            glVertex2f(x, y);
            glVertex2f(x + 2, y - 3);
        }
    }
    glEnd();
    glPopMatrix();


    glPopMatrix();
    glEnd();
    glFlush();

}
void raindrop(int value)
{
    if (position < -5)
        position = 5.0f;
    position -= rainspeed;
    glutPostRedisplay();
    glutTimerFunc(20, raindrop, 0);
}



void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(10);


    road();
    glColor3ub(0, 204, 0);
    land();
    tree();
    fense();
    sky_day();
    building();
    train_track();
    train();
    fort();
    lampost_day();
    car1();
    car2();
    sun();
    cloud();
    helicopter();
    fortlight_day();



    glEnd();
    glFlush();
}
void display_day(int value)
{
    glutDisplayFunc(display);
}

void night_display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(10);


    road();
    glColor3ub(0, 102, 0);
    land();
    tree();
    fense();
    glColor3ub(3, 0, 46);
    sky();
    star();
    building_night();
    train_track();
    train_night();
    fort();
    lampost_night();
    car1_night();
    car2_night();
    moon();
    helicopter_night();
    fortlight_night();





    glEnd();
    glFlush();
}

void display_night(int value)
{
    glutDisplayFunc(night_display);
}

void display_rain(int value)
{
    glutDisplayFunc(rain);
}



void control(unsigned char key, int x, int y) {
    switch (key) {

    case '1':           car1speed = 0;
        rimsspeed1 = 0;   break;
    case '2':           car2speed = 0;
        rimsspeed2 = 0;   break;

    case '3':           car1speed = 0.3;
        rimsspeed1 = 5.0;    break;
    case '4':           car2speed = 0.3;
        rimsspeed2 = 5.0;    break;

    case '5':           car1speed += 0.2;
        rimsspeed1 += 5;    break;
    case '6':           car2speed += 0.2;
        rimsspeed2 += 5;    break;

    case '7':           car1speed -= 0.3;
        rimsspeed1 -= 6;    break;
    case '8':           car2speed -= 0.3;
        rimsspeed2 -= 6;    break;

    case 'h':           helicopterspeed = 0;   break; //stop
    case 'j':           helicopterspeed = 0.2;
        propellerspeed = 10;    break; //start/normal
    case 'k':           helicopterspeed += 0.1;
        propellerspeed += 3;    break; //speed up

    case 't':           trainspeed = 0.0;   break;  //stop
    case 'y':           trainspeed = 0.5;   break;  //start
    case 'u':           trainspeed += 0.3;   break; //speed up

    case 'r':
        glutTimerFunc(1, display_rain, 0); break;   //rain

    }     glutPostRedisplay();

}

void SpecialInput(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        glutTimerFunc(1, display_night, 0);
        break;
    case GLUT_KEY_DOWN:
        glutTimerFunc(1, display_day, 0);
        break;
    }
    glutPostRedisplay();
}
void init()
{
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Fort knox: a fort with city view");
    init();
    glutDisplayFunc(display);

    glutTimerFunc(20, move_cloud, 0);
    glutTimerFunc(100, update_car1, 0);
    glutTimerFunc(100, update_car2, 0);
    glutTimerFunc(100, rotate_rims1, 0);
    glutTimerFunc(100, rotate_rims2, 0);

    glutTimerFunc(100, update_helicopter, 0);
    glutTimerFunc(20, rotate_propeller, 0);
    glutTimerFunc(20, update_train, 0);
    glutTimerFunc(20, raindrop, 0);
    glutKeyboardFunc(control);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;
}
