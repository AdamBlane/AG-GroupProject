#pragma once
#include "Transform.h"
#include <string>
#include "glew_glfw.h"

using namespace std;

class Player
{
public:
	Player() {}
	Player(string inputConfigFilePath);
	~Player() {}

	// Physics related properties
	Transform transform;
	Transform arrowTransform;
	glm::dvec3 velocity; // added to position in transform each frame
	glm::dvec3 impulse; // direction * power 
	glm::dvec3 direction; // dir camera is facing
	double power; // accumulated counter from holding fire
	double mass = 1.2;
	double radius = 0.5;

	// Movement
	int currentTile = 0; // For spatial partitioning
	bool isMoving = false; // Physics is only applied when moving
	bool ballInHole = false; // Has the player reached end hole
	bool isFalling = false;
	bool camFollow = true;
	double chaseCamAngle;

	// Gameplay
	int id;
	int strokeCounter = 0;
	int currentPowerup = 0;
	int totalTime = 0;

	// Input
	// Action isPressed flags
	bool firePressed = false;
	bool jumpPressed = false;
	bool upPressed = false;
	bool downPressed = false;
	bool leftPressed = false;
	bool rightPressed = false;
	bool zoomInPressed = false;
	bool zoomOutPressed = false;

	// Keyboard input members
	int fireButtton, jumpButton, upButton,
		downButton, leftButton, rightButton,
		zoomInButton, zoomOutButton;
	int fireButtonC;

	// Setup GLFW joystick button input - required for doing anything with buttons
	int buttonCount;
	const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
	// Create a array of 10 values
	int arr[10];
};