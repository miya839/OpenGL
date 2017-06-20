#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<GLUT/glut.h>

#include"cube.h"

#define ANGLE 0.2
#define PI 3.1415926535
#define Width 640
#define Height 480

static int r = 0;
static float posx = 0.0;
static float posy = 0.0;
static float posz = 0.0;


GLfloat translateT[] = {
    1.0,0.0,0.0,0.0,
    0.0,1.0,0.0,0.0,
    0.0,0.0,1.0,0.0,
    0.0,0.0,0.0,1.0};

void Translate(float x, float y, float z){
    translateT[12] = x;
    translateT[13] = y;
    translateT[14] = z;
    glMultMatrixf(translateT);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    gluLookAt(1.0,2.0,3.0,0.0,0.0,0.0,0.0,1.0,0.0);
    glTranslated(posx,posy,posz);
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0); 
    for(int i = 0;i<6;++i){
        for(int j = 0; j<4; ++j){
            glVertex3dv(vetex[face[i][j]]);
        }
    }

    glTranslated(posx+5,posy,posz);
    for(int i = 0;i<6;++i){
        for(int j = 0; j<4; ++j){
            glVertex3dv(vetex[face[i][j]]);
        }
    }
    glEnd();
    glFlush();

    glutSwapBuffers();
}

void Reset(){
    translateT[3] = 1.0;
    translateT[7] = 1.0;
    translateT[11] = 1.0;

    posx = posy = posz = 1.0;

    glLoadIdentity();
    glutPostRedisplay();
}
void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(1000,timer,0);
}

void reshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90,Width/Height,1,1000);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'q':
        case 'Q':
            posy +=  1;
            glLoadIdentity();
            glutPostRedisplay();
            break;
        case 'e':
        case 'E':
            posy -= 1.0;
            glLoadIdentity();
            glutPostRedisplay();
            break;
        case 'a':
        case 'A':
            posx += 1.0;
            glLoadIdentity();
            glutPostRedisplay();
            break;
        case 'd':
        case 'D':
            posx -= 1.0;
            glLoadIdentity();
            glutPostRedisplay();
            break;
        case 'w':
        case 'W':
            posz += 1.0;
            glLoadIdentity();
            glutPostRedisplay();
            break;
        case 's':
        case 'S':
            posz -= 1.0;
            glLoadIdentity();
            glutPostRedisplay();
            break;
        case 'r':
        case 'R':
            Reset();
            break;
        case '\033':
            exit(0);
        default:
            break;
    }
}

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

int main(int argc, char * argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    //glutTimerFunc(100,timer,0);

    init();
    glutMainLoop();
    return 0;
}
