#include <Windows.h>
#include <iostream>
#include "geometry_builder.h"
#include "tile.h"
//
#include "glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <gl/GL.h>
#include <gl/GLU.h>


using namespace std;

const GLint WIDTH = 800, HEIGHT = 600;

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
GLfloat rotationZ = 0.0f;

void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	//std::cout << key << std::endl;

	const GLfloat rotationSpeed = 10;

	// actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_UP:
			rotationX -= rotationSpeed;
			break;
		case GLFW_KEY_DOWN:
			rotationX += rotationSpeed;
			break;
		case GLFW_KEY_RIGHT:
			rotationY += rotationSpeed;
			break;
		case GLFW_KEY_LEFT:
			rotationY -= rotationSpeed;
			break;
		case GLFW_KEY_A:
			rotationZ -= rotationSpeed;
			break;
		case GLFW_KEY_D:
			rotationZ += rotationSpeed;
			break;
		}


	}
}

//old function
void createCubeOLD(GLfloat startPosX, GLfloat startPosY, GLfloat startPosZ, GLfloat edgeLength)
{

	GLfloat vertices[] =
	{
		// front face
		startPosX - edgeLength, startPosY + edgeLength, startPosZ + edgeLength, // top left
		startPosX + edgeLength, startPosY + edgeLength, startPosZ + edgeLength, // top right
		startPosX + edgeLength, startPosY - edgeLength, startPosZ + edgeLength, // bottom right
		startPosX - edgeLength, startPosY - edgeLength, startPosZ + edgeLength, // bottom left

		// back face
		startPosX - edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // top left
		startPosX + edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // top right
		startPosX + edgeLength, startPosY - edgeLength, startPosZ - edgeLength, // bottom right
		startPosX - edgeLength, startPosY - edgeLength, startPosZ - edgeLength, // bottom left

		// left face
		startPosX - edgeLength, startPosY + edgeLength, startPosZ + edgeLength, // top left
		startPosX - edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // top right
		startPosX - edgeLength, startPosY - edgeLength, startPosZ - edgeLength, // bottom right
		startPosX - edgeLength, startPosY - edgeLength, startPosZ + edgeLength, // bottom left

		// right face
		startPosX + edgeLength, startPosY + edgeLength, startPosZ + edgeLength, // top left
		startPosX + edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // top right
		startPosX + edgeLength, startPosY - edgeLength, startPosZ - edgeLength, // bottom right
		startPosX + edgeLength, startPosY - edgeLength, startPosZ + edgeLength, // bottom left

		// top face
		startPosX - edgeLength, startPosY + edgeLength, startPosZ + edgeLength, // top left
		startPosX - edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // top right
		startPosX + edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // bottom right
		startPosX + edgeLength, startPosY + edgeLength, startPosZ + edgeLength, // bottom left

		// bottom face
		startPosX - edgeLength, startPosY - edgeLength, startPosZ + edgeLength, // top left
		startPosX - edgeLength, startPosY - edgeLength, startPosZ - edgeLength, // top right
		startPosX + edgeLength, startPosY - edgeLength, startPosZ - edgeLength, // bottom right
		startPosX + edgeLength, startPosY - edgeLength, startPosZ + edgeLength  // bottom left
	};

	GLfloat colour[] =
	{
		255, 0, 0,
		0, 255, 0,
		0, 0, 255
	};

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(colour[0], colour[1], colour[2] );
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawArrays(GL_QUADS, 0, 24);

	glDisableClientState(GL_VERTEX_ARRAY);
}


//void createCube(GLfloat startPosX, GLfloat startPosY, GLfloat startPosZ, GLfloat edgeLength)
//{
//
//	GLfloat vertices[] =
//	{
//		// front face
//		startPosX, startPosY + edgeLength, startPosZ, // top left
//		startPosX + edgeLength, startPosY + edgeLength, startPosZ, // top right
//		startPosX + edgeLength, startPosY, startPosZ, // bottom right
//		startPosX, startPosY, startPosZ, // bottom left
//
//		// back face
//		startPosX, startPosY + edgeLength, startPosZ - edgeLength, // top left
//		startPosX + edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // top right
//		startPosX + edgeLength, startPosY, startPosZ - edgeLength, // bottom right
//		startPosX, startPosY, startPosZ - edgeLength, // bottom left
//
//		// left face
//		startPosX, startPosY + edgeLength, startPosZ, // top left
//		startPosX, startPosY + edgeLength, startPosZ - edgeLength, // top right
//		startPosX, startPosY, startPosZ - edgeLength, // bottom right
//		startPosX, startPosY, startPosZ, // bottom left
//
//		// right face
//		startPosX + edgeLength, startPosY + edgeLength, startPosZ, // top left
//		startPosX + edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // top right
//		startPosX + edgeLength, startPosY, startPosZ - edgeLength, // bottom right
//		startPosX + edgeLength, startPosY, startPosZ, // bottom left
//
//		// top face
//		startPosX, startPosY + edgeLength, startPosZ, // top left
//		startPosX, startPosY + edgeLength, startPosZ - edgeLength, // top right
//		startPosX + edgeLength, startPosY + edgeLength, startPosZ - edgeLength, // bottom right
//		startPosX + edgeLength, startPosY + edgeLength, startPosZ, // bottom left
//
//		// bottom face
//		startPosX, startPosY, startPosZ, // top left
//		startPosX, startPosY, startPosZ - edgeLength, // top right
//		startPosX + edgeLength, startPosY, startPosZ - edgeLength, // bottom right
//		startPosX + edgeLength, startPosY, startPosZ  // bottom left
//	};
//
//	GLfloat colour[] =
//	{
//		255, 0, 0,
//		0, 255, 0,
//		0, 0, 255
//	};
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(colour[0], colour[1], colour[2] );
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(3, GL_FLOAT, 0, vertices);
//
//	glDrawArrays(GL_QUADS, 0, 24);
//
//	glDisableClientState(GL_VERTEX_ARRAY);
//}
//
//void createCuboid(GLfloat startPosX, GLfloat startPosY, GLfloat startPosZ, GLfloat side1, GLfloat side2)
//{
//
//	GLfloat vertices[] =
//	{
//		// front face
//		startPosX, startPosY + side1, startPosZ, // top left
//		startPosX + side2, startPosY + side1, startPosZ, // top right
//		startPosX + side2, startPosY, startPosZ, // bottom right
//		startPosX, startPosY, startPosZ, // bottom left
//
//		// back face
//		startPosX, startPosY + side1, startPosZ - side2, // top left
//		startPosX + side2, startPosY + side1, startPosZ - side2, // top right
//		startPosX + side2, startPosY, startPosZ - side2, // bottom right
//		startPosX, startPosY, startPosZ - side2, // bottom left
//
//		// left face
//		startPosX, startPosY + side1, startPosZ, // top left
//		startPosX, startPosY + side1, startPosZ - side2, // top right
//		startPosX, startPosY, startPosZ - side2, // bottom right
//		startPosX, startPosY, startPosZ, // bottom left
//
//		// right face
//		startPosX + side2, startPosY + side1, startPosZ, // top left
//		startPosX + side2, startPosY + side1, startPosZ - side2, // top right
//		startPosX + side2, startPosY, startPosZ - side2, // bottom right
//		startPosX + side2, startPosY, startPosZ, // bottom left
//
//		// top face
//		startPosX, startPosY + side1, startPosZ, // top left
//		startPosX, startPosY + side1, startPosZ - side2, // top right
//		startPosX + side2, startPosY + side1, startPosZ - side2, // bottom right
//		startPosX + side2, startPosY + side1, startPosZ, // bottom left
//
//		// bottom face
//		startPosX, startPosY, startPosZ, // top left
//		startPosX, startPosY, startPosZ - side2, // top right
//		startPosX + side2, startPosY, startPosZ - side2, // bottom right
//		startPosX + side2, startPosY, startPosZ  // bottom left
//
//	};
//
//	GLfloat colour[] =
//	{
//		255, 0, 0,
//		0, 255, 0,
//		0, 0, 255
//	};
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(colour[0], colour[2], colour[2]);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(3, GL_FLOAT, 0, vertices);
//
//	glDrawArrays(GL_QUADS, 0, 24);
//
//	glDisableClientState(GL_VERTEX_ARRAY);
//}

int main(int argc, char **argv)
{

	// Create window
	GLFWwindow* window;
	// Set error callbackc function
	glfwSetErrorCallback(error_callback);

	// Initialise GLFW
	if (!glfwInit())
		exit(EXIT_FAILURE);
	// Initialise the window, check for error after
	window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle Simulator 2017", NULL, NULL);
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	// Assign context
	glfwMakeContextCurrent(window);
	// Assign key callback function for close on ESC
	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	// While window is not to be closed...
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		float ratio;
		int width, height;

		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;

		glViewport(0, 0, WIDTH, HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, WIDTH, 0, HEIGHT, -1000, 1000);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();

		glPushMatrix();


		//geometry_builder *box = new geometry_builder(geometry_builder::CUBOID);

		//box->setPosition(500.0f, 150.0f, 0.0f);
		//box->size(2.0f, 100.0f);

		tile *newTile = new tile();

		glTranslatef(newTile->getPosition().x, newTile->getPosition().y, 0);
		//X, Y, Z rotation
		glRotatef(rotationX, 1, 0, 0);
		glRotatef(rotationY, 0, 1, 0);
		glRotatef(rotationZ, 0, 0, 1);
		glTranslatef(-(newTile->getPosition().x), -(newTile->getPosition().y), 0);

		//box->draw();
		//newTile->drawTile();

		//cout << box->getPosition().x << ", " << box->getPosition().y << ", " << box->getPosition().z << endl;

		glPopMatrix();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);



	return 0;
}