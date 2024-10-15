#include <GL/glut.h>
#include <cmath>

#include "CameraManagement.h"

#define PaintWhite glColor3f(1, 1, 1);

GLUquadricObj *solids = gluNewQuadric();

float headAngle = 0.0f;
float headSpeed = 5.0f;

float torsoAngleX = 0;

float rightArmAngle = 0;
float leftArmAngle = 0;
float rightLegAngle = 0;
float leftLegAngle = 0;

float rightForearmAngle = 0;
float leftForearmAngle = 0;
float rightCalfAngle = 0;
float leftCalfAngle = 0;

float rightFootAngle = 0;
float leftFootAngle = 0;

float gripperAngle = 0.0f;
float gripperSpeed = 5.0f;

float torsoDirection = 1;

void init() {
    glClearColor(0.7f, 0.7f, 0.7f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    gluQuadricDrawStyle(solids, GLU_LINE);
}

void drawAxes() {
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(50, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 50, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 50);

    glEnd();
}

void drawRobot() {
	// Head
	glPushMatrix();
	PaintWhite;
	glRotatef(90, 0, 1, 0);
	glRotatef(headAngle, 0, 1, 0);
	glTranslatef(0, 6, 0);
	glutWireSphere(1.9f, 8, 8);

	glPushMatrix();
	PaintWhite;
	glTranslatef(0, 2, 0);
	glRotatef(90, 1, 0, 0);
	glutWireTorus(0.4, 1.8, 8, 8);

	glPopMatrix();
	glPopMatrix();

	// Torso
    glPushMatrix();
    PaintWhite;
    glRotatef(torsoAngleX, 1, 0, 0);
    glPushMatrix();
    glScalef(1.1f, 2, 0.6f);
    glutWireCube(4);
    glPopMatrix();

    // Right arm
    glPushMatrix();
    PaintWhite;
    glTranslatef(3, 3, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(-rightArmAngle, 1, 0, 0);
    gluCylinder(solids, 0.7, 0.6, 3, 8, 8);
    
    // Right forearm
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0, 3);
    glRotatef(std::min(rightForearmAngle, 0.0f), 1, 0, 0);
    gluCylinder(solids, 0.6, 0.5, 2.5, 8, 8);

    // Right hand (gripper)
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0, 3);
    glRotatef(-rightForearmAngle / 2, 1, 0, 0);

    glPushMatrix();
    glTranslatef(0, 0.2, 0);  // Adjust position
    glRotatef(90, 0, 0, 1);  // Adjust orientation
    glRotatef(gripperAngle, 0, 1, 0);  // Apply gripper open/close angle
    glScalef(0.1f, 0.8f, 1.0f);  // Flat shape
    glutWireCube(1.0f);  // Gripper part
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.2, 0);  // Adjust position
    glRotatef(90, 0, 0, 1);  // Adjust orientation
    glRotatef(-gripperAngle, 0, 1, 0);  // Apply gripper open/close angle
    glScalef(0.1f, 0.8f, 1.0f);  // Flat shape
    glutWireCube(1.0f);  // Gripper part
    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Left arm
    glPushMatrix();
    PaintWhite;
    glTranslatef(-3, 3, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(-leftArmAngle, 1, 0, 0);
    gluCylinder(solids, 0.7, 0.6, 3, 8, 8);

    // Left forearm
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0, 3);
    glRotatef(std::min(leftForearmAngle, 0.0f), 1, 0, 0);
    gluCylinder(solids, 0.6, 0.5, 2.5, 8, 8);

    // Left hand (gripper)
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0, 3);
    glRotatef(-leftForearmAngle / 2, 1, 0, 0);

    glPushMatrix();
    glTranslatef(0, 0.2, 0);  // Adjust position
    glRotatef(90, 0, 0, 1);  // Adjust orientation
    glRotatef(gripperAngle, 0, 1, 0);  // Apply gripper open/close angle
    glScalef(0.1f, 0.8f, 1.0f);  // Flat shape
    glutWireCube(1.0f);  // Gripper part
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.2, 0);  // Adjust position
    glRotatef(90, 0, 0, 1);  // Adjust orientation
    glRotatef(-gripperAngle, 0, 1, 0);  // Apply gripper open/close angle
    glScalef(0.1f, 0.8f, 1.0f);  // Flat shape
    glutWireCube(1.0f);  // Gripper part
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Right leg
    glPushMatrix();
    PaintWhite;;
    glTranslatef(1.2f, -4, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(leftLegAngle, 1, 0, 0);
    gluCylinder(solids, 1, 0.9, 4, 8, 8);

    // Right calf
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0, 4);
    glRotatef(-std::min(rightCalfAngle, 0.0f), 1, 0, 0);
    gluCylinder(solids, 0.9, 0.7, 3, 8, 8);

    // Right foot
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0.5, 2.7);
    glRotatef(rightFootAngle, 1, 0, 0);
    glScalef(1.0f, 2.5f, 1.0f);
    glutWireCube(1.0f);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Left leg
    glPushMatrix();
    PaintWhite;
    glTranslatef(-1.2f, -4, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(rightLegAngle, 1, 0, 0);
    gluCylinder(solids, 1, 0.9, 4, 8, 8);

    // Left calf
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0, 4);
    glRotatef(-std::min(leftLegAngle, 0.0f), 1, 0, 0);
    gluCylinder(solids, 0.9, 0.7, 3, 8, 8);

    // Left foot
    glPushMatrix();
    PaintWhite;
    glTranslatef(0, 0.5, 2.7);
    glRotatef(leftFootAngle, 1, 0, 0);
    glScalef(1.0f, 2.5f, 1.0f);
    glutWireCube(1.0f);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void keyManagement(unsigned char key, int x, int y) {
	switch(key)	{
        case '1':
            currentCam = cam1;
            break;
        case '2':
            currentCam = cam2;
            break;
        case '3':
            currentCam = cam3;
            break;
	    case '4':
            currentCam = cam4;
            break;
	    case 'o':  // Open gripper
	        if (gripperAngle < 20.0f) {  // Limit max opening angle
	            gripperAngle += gripperSpeed;
	        }
	    break;
	    case 'c':  // Close gripper
	        if (gripperAngle > -15.0f) {  // Limit minimum closing angle
	            gripperAngle -= gripperSpeed;
	        }
	    break;
		case 'a':  // Move head left
			if (headAngle > -45.0f) {  // Limit head rotation
				headAngle -= headSpeed;
			}
		break;
		case 'd':  // Move head right
			if (headAngle < 45.0f) {  // Limit head rotation
				headAngle += headSpeed;
			}
		break;
        case 'q':
            exit(0);
        default: ;
    }
	glutPostRedisplay();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    currentCam.lookAt();

    drawAxes();
    drawRobot();

    glutSwapBuffers();
}

void reshapeWindow(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, static_cast<float>(w) / static_cast<float>(h), 1, 100);
}

void moveTorso(int i) {
    // Subtle movement, reducing the multipliers
    torsoAngleX += torsoDirection;
    if (torsoAngleX <= -5) torsoDirection = 1;
    if (torsoAngleX >= 5) torsoDirection = -1;


    // Alternate movement of legs and arms
    rightLegAngle = torsoAngleX * 4;
    rightCalfAngle = rightLegAngle / 2;
    leftLegAngle = -torsoAngleX * 4;
    leftCalfAngle = leftLegAngle / 2;

    rightArmAngle = -rightLegAngle;
    rightForearmAngle = rightArmAngle * 0.5f;

    leftArmAngle = -leftLegAngle;
    leftForearmAngle = leftArmAngle * 0.5f;

    glutPostRedisplay();
    glutTimerFunc(150, moveTorso, 0);  // Smoother movement
}



int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Robot");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeWindow);
	glutTimerFunc(50, moveTorso, 0);

    glutKeyboardFunc(keyManagement);

	glutMainLoop();
	return 0;
}
