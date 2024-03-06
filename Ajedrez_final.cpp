#include <windows.h>
#include <GL/glut.h>
#include <cmath>
//Metodo que dibuja una elipse
void drawEllipse(float a, float b, int num_segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; ++i) {
        float theta = 2 * 3.1415926f * float(i) / float(num_segments);
        float x = a * cosf(theta);
        float y = b * sinf(theta);
        // Cambia el signo de x para que esté en el segundo cuadrante
        x = -x;
        glVertex2f(x, y);
    }
    glEnd();
}

//Metodo que dibuja cuadrado
void dibujarCuadrado(float x, float y, float tamano) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + tamano, y);
    glVertex2f(x + tamano, y + tamano);
    glVertex2f(x, y + tamano);
    glEnd();
    
}
void dibujarpeon(float cx, float cy, float radio, int segments){
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,1);//blanco
	for(int i = 0; i < segments; i++){
		float theta = 2.0f * 3.1415926f * float(i) / float(segments);
		float x = radio * cosf(theta);
		float y = radio * sinf(theta);
		glVertex2f(x+cx,y+cy);
	}
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glVertex2f(29.55,26.23);
	glVertex2f(32.28,43.64);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1,1,1);
	glVertex2f(49.55,26.23);
	glVertex2f(48.28,43.64);
	glEnd();
	drawEllipse(20.0f, 12.0f, 100);
	glFlush();
	
}
//Metodo para dibujar el tablero completo
void dibujarTablero() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Color de los cuadrados negros

    int numFilas = 8;
    int numColum = 8;
    float cuadradoTam = 80.0; // Tamano del cuadrado

    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numColum; ++j) {
            if ((i + j) % 2 == 0) {
                glColor3f(0.0, 0.0, 0.0); // Cuadrados negros
            } else {
                glColor3f(1.0, 1.0, 1.0); // Cuadrados blancos
            }
            dibujarCuadrado(j * cuadradoTam, i * cuadradoTam, cuadradoTam);
        }
    }
    dibujarpeon(40,50,10,100);
    
    glFlush();
    glutSwapBuffers();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 640);
    glutCreateWindow("CRISTO MAGNO");
    glutDisplayFunc(dibujarTablero);
    gluOrtho2D(0, 640, 0, 640);
    glClearColor(1,1,1,1);
    glutMainLoop();
    return 0;
}
