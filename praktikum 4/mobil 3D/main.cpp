/* Nama File  : Mobil 3D OpenGL
 * Deskripsi  : Membuat model mobil 3D tampak dari samping menggunakan OpenGL dengan pencahayaan dan depth
 * Pembuat    : Dewi Larasati Mumpuni / 24060123140045
 * Tanggal    : Senin, 24 Maret 2025
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Variabel global untuk sudut rotasi
double rotAngle = 10;  
double rotAngle1 = 10; 

void init() {
    glClearColor(1.0, 0.3, 0.3, 1.0); 
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void drawSolidCube(float width, float height, float depth) {
    glPushMatrix();
    glScalef(width, height, depth);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawSolidCylinder(float radius, float height) {
    GLUquadric *quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluCylinder(quad, radius, radius, height, 20, 20);
    gluDisk(quad, 0, radius, 20, 1);
    glTranslatef(0.0, 0.0, height);
    gluDisk(quad, 0, radius, 20, 1);
    gluDeleteQuadric(quad);
}

void drawCar() {
    // Badan mobil
    glColor3f(0.0, 0.0, 0.9);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    drawSolidCube(1.5, 0.6, 3.0);
    glPopMatrix();
    
    // Cup atas mobil
    glColor3f(0.0, 0.7, 0.8);
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    drawSolidCube(1.2, 0.4, 1.5);
    glPopMatrix();
    
    // Roda kiri depan
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.7, -0.5, 1.0);
    glRotatef(90, 0, 1, 0);
    drawSolidCylinder(0.3, 0.2);
    glPopMatrix();
    
    // Roda kiri belakang
    glPushMatrix();
    glTranslatef(-0.9, -0.5, 1.0);
    glRotatef(90, 0, 1, 0);
    drawSolidCylinder(0.3, 0.2);
    glPopMatrix();
    
    // Roda kanan depan
    glPushMatrix();
    glTranslatef(0.7, -0.5, -1.0);
    glRotatef(90, 0, 1, 0);
    drawSolidCylinder(0.3, 0.2);
    glPopMatrix();
    
    // Roda kanan belakang
    glPushMatrix();
    glTranslatef(-0.9, -0.5, -1.0);
    glRotatef(90, 0, 1, 0);
    drawSolidCylinder(0.3, 0.2);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3, 1.5, 3, 0, 0, 0, 0, 1, 0);
    
    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);
    glRotated(rotAngle1, 1, 0, 0);
    drawCar();
    glPopMatrix();
    
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char k, int x, int y) {
    switch (k) {
        case 'a': rotAngle += 5; break;
        case 'l': rotAngle -= 5; break;
        case 'y': rotAngle1 += 5; break;
        case 'b': rotAngle1 -= 5; break;
        case 'q': exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mobil 3D");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}

