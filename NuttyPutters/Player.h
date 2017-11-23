#pragma once
#include "Transform.h"

class Player
{
public:
	Transform transform;
	Transform arrowTransform;
	glm::vec3 velocity; // added to position in transform each frame
	glm::vec3 impulse; // direction * power 
	glm::vec3 direction; // dir camera is facing
	float power; // accumulated counter from holding fire
	float mass = 1;
	float radius = 0.5;
	bool isMoving = false; // Physics is only applied when moving
	bool ballInHole = false;
	// Action variables
	bool firePressed = false;
};