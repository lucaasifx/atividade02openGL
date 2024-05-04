
// Interação
//     W, A, S, D: movimenta a estrutura
//     Q, E: rotaciona a partir do primeiro membro do braço robótico
//     R, T: rotaciona a partir do segundo membro do braço robótico
//     Y, W: rotaciona o terceiro membro do braço robótico  
#include <GL/glut.h>
#include <windows.h>



// Variáveis para controlar as rotações
GLfloat basetranslatex = 0.0f;
GLfloat basetranslatey = 0.0f;
GLfloat secondpartrotate = 0.0f;
GLfloat thirdpartrotate = -25.0f;
GLfloat fourthpartrotate = -45.0f;



void armPart(GLfloat x) {
    //x = 0.1
    // y = 0.4
    glBegin(GL_QUADS);
    glColor3i(0, 0, 0);
    glVertex2f(-x, 0.4f); // Canto superior esquerdo
    glVertex2f(-x, 0.0f); // Canto inferior esquerdo
    glVertex2f(x, 0.0f); // Canto inferior direito
    glVertex2f(x, 0.4f); // Canto superior direito
    glEnd();
}

void base() {
    // x = 0.8
    // y = 0.2
    glBegin(GL_QUADS);
    glColor3i(0, 0, 0);
    glVertex2f(0.0f, 0.0f); // Canto superior esquerdo
    glVertex2f(0.8f, 0.0f);  // Canto superior direito
    glVertex2f(0.8f, -0.2f);  // Canto inferior direito
    glVertex2f(0.0f, -0.2f); // Canto inferior esquerdo
    glEnd();
}

// Função para desenhar o objeto completo
void drawObject() {
    GLfloat x = 0.05;
    glPushMatrix();
    // Desenha a base
    glScalef(0.5f, 0.5f, 1.0f);
    // Base
    glTranslatef(basetranslatex, basetranslatey, 0.0);
    base();

    // Segundo objeto
    glTranslatef(0.4, -0.05, 0.0);
    glRotatef(secondpartrotate, 0.0, 0.0, 1.0);
    armPart(x);

    // terceiro
    glTranslatef(0.0, 0.3, 0.0);
    glRotatef(thirdpartrotate, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    //x = 0.1
// y = 0.4
    glColor3i(0, 0, 0);
    glVertex2f(-x, 0.4f); // Canto superior esquerdo
    glVertex2f(-x, 0.0f); // Canto inferior esquerdo
    glVertex2f(x, 0.0f); // Canto inferior direito
    glVertex2f(x, 0.4f); // Canto superior direito
    glEnd();

    //quarto
    glTranslatef(0.0, 0.35, 0.0);
    glRotatef(fourthpartrotate, 0.0, 0.0, 1.0);
    armPart(x);


    glPopMatrix();
}

// Função de desenho
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawObject();

    glutSwapBuffers();
}

void keyboardKeys(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        basetranslatey += 0.1;
        break;
    case 'a':
        basetranslatex -= 0.1;
        break;
    case 's':
        basetranslatey -= 0.1;
        break;
    case 'd':
        basetranslatex += 0.1;
        break;
    case 'q':
        secondpartrotate += 5.0;
        break;
    case 'e':
        secondpartrotate -= 5.0;
        break;
    case 'r':
        thirdpartrotate += 5.0;
        break;
    case 't':
        thirdpartrotate -= 5.0;
        break;
    case 'y':
        fourthpartrotate += 5.0;
        break;
    case 'u':
        fourthpartrotate -= 5.0;
        break;
    }
    glutPostRedisplay();
}

void initialize() {
    glClearColor(1, 1, 1, 1);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    gluOrtho2D(0.0, 0.1, 0.0, 0.1);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Articulated Arm");
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardKeys);


    initialize();
    glMatrixMode(GL_PROJECTION);
    glutMainLoop();
    return 0;
}
