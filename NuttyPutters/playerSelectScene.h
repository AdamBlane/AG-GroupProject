#pragma once

// GLFW
#include "glew_glfw.h"

class playerSelectScene
{
public:
	// Constructors
	playerSelectScene();
	~playerSelectScene();

	// Draw stuff
	void Loop(GLFWwindow* win);
	// Input
	void Input(GLFWwindow* win);

	// Setup scene
	void Init(GLFWwindow* win);
};