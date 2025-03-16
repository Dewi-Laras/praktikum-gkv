/*Nama File  : Lengan Bergerak
  Deskripsi  : berisi atribut dan method cara membuat lengan
  Pembuat    : Dewi Larasati Mumpuni / 24060123140045
  Tanggal    : Senin, 17 Maret 2025*/

#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0;
static int finger1 = 0, finger2 = 0, finger3 = 0, finger4 = 0, thumb = 0; 

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Transformasi bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    // Menggambar bagian atas lengan (bahu - siku)
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Transformasi siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    // Menggambar bagian bawah lengan (siku - pergelangan tangan)
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Transformasi pergelangan tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    
    // Menggambar telapak tangan
    glPushMatrix();
    glScalef(1.0, 0.3, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari 1
    glPushMatrix();
    glTranslatef(0.3, 0.2, 0.0);
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari 2
    glPushMatrix();
    glTranslatef(0.3, 0.1, 0.05);
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari 3 (Tengah)
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.1);
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari 4 (Ring)
    glPushMatrix();
    glTranslatef(0.3, -0.1, 0.05);
    glRotatef((GLfloat)finger4, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari 5 (Ibu Jari)
    glPushMatrix();
    glTranslatef(0.2, -0.2, -0.1);
    glRotatef((GLfloat)thumb, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;
        case '1': finger1 = (finger1 + 5) % 360; break;
        case '!': finger1 = (finger1 - 5) % 360; break;
        case '2': finger2 = (finger2 + 5) % 360; break;
        case '@': finger2 = (finger2 - 5) % 360; break;
        case '3': finger3 = (finger3 + 5) % 360; break;
        case '#': finger3 = (finger3 - 5) % 360; break;
        case '4': finger4 = (finger4 + 5) % 360; break;
        case '$': finger4 = (finger4 - 5) % 360; break;
        case '5': thumb = (thumb + 5) % 360; break;
        case '%': thumb = (thumb - 5) % 360; break;
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan Robot");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

