/* Nama File  : mobil
 * Deskripsi  : berisi koding membuat mobil
 * Pembuat    : Dewi Larasati Mumpuni / 24060123140045
 * Tanggal    : Minggu,9 Maret 2025
 */

#include <GL/glut.h>
#include <cmath>

void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawCircle(float cx, float cy, float radius) {
    int num_segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawRoad() {
    glColor3f(0.3f, 0.3f, 0.3f);
    drawRectangle(-1.0f, -0.4f, 2.0f, 0.3f);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float i = -0.9f; i < 1.0f; i += 0.3f) {
        drawRectangle(i, -0.25f, 0.1f, 0.05f);
    }
}

void drawCar() {
    // Badan mobil
    glColor3f(0.0f, 0.0f, 9.0f);
    drawRectangle(-0.3f, -0.1f, 0.6f, 0.2f);
    
    // Atap mobil
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.15f, 0.2f);
    glVertex2f(-0.15f, 0.2f);
    glEnd();
    
    // Roda kiri
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(-0.2f, -0.15f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.05f);
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.2f, -0.15f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.05f);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    drawRoad();
    drawCar();
    
    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mobil");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

