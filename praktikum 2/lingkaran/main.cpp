 /*Nama File  : Lingkaran
 * Deskripsi  : berisi kodingan cara membuat lingkaran
 * Pembuat    : Dewi Larasati Mumpuni / 24060123140045
 * Tanggal    : Minggu,9 Maret 2025
 */

#include <GL/glut.h>
#include <cmath>

void drawCircle() {
    float radius = 0.2f; 
    int segments = 100;
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, 0.0f); 
    drawCircle();
    
    glFlush();
}

void init() {
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lingkaran");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

