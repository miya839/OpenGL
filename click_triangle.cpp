#include<GLUT/GLUT.h>
#include<stdio.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    /*glBegin(GL_QUADS);
    glColor3d(1.0,1.0,1.0);
    glVertex2d(-0.9,-0.9);
    glColor3d(1.0,0,0.0);
    glVertex2d(0.9,-0.9);
    glColor3d(0,1.0,0.0);
    glVertex2d(0.9,0.9);
    glColor3d(0,0.0,1.0);
    glVertex2d(-0.9,0.9);
    glEnd();*/
    glFlush();
}

void resize(int w, int h){
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-0.5, (GLdouble)w - 0.5, h - 0.5, -0.5,-1.0,1.0);
} 

void init(void){
    glClearColor(0.0,0.0,1.0,1.0);
}

void mouse(int button, int state, int x, int y){
    static int x0, y0, x1, y1;
    static int num = 0;
    switch(button){
    case GLUT_LEFT_BUTTON:
        /*if(state == GLUT_UP){
            glColor3d(0.0,0.0,0.0);
            glBegin(GL_LINES);
            glVertex2i(x0,y0);
            glVertex2i(x,y);
            glEnd();
            glFlush();
        }
        else{
            printf("%d,%d\n",x,y);
            x0 = x;
            y0 = y;
        }
      break;*/
        if(state == GLUT_DOWN){
            switch(num){
                case 0:
                    x0 = x;
                    y0 = y;
                    num++;
                    break;
                case 1:
                    x1 = x;
                    y1 = y;
                    num++;
                    break;
                case 2:
                    glColor3d(0.0,0.0,0.0);
                    glBegin(GL_TRIANGLES);
                    glVertex2d(x0,y0);
                    glVertex2d(x1,y1);
                    glVertex2d(x,y);
                    glEnd();
                    glFlush();
                    num = 0;
                    break;
            }
        }

    case GLUT_RIGHT_BUTTON:
      printf("right");
      break;
    default:
      break;
    }
    /*switch(state){
    case GLUT_UP:
        printf ("up");
        break;
    case GLUT_DOWN:
        printf("down");
        break;
    default:
        break;
    }
    printf ("at(%d,%d)\n",x ,y);*/
}



int main(int argc, char *argv[])
{
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
