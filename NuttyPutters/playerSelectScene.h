#pragma once
// Externals
#include "glew_glfw.h"
#include <map>
#include <time.h>
#include <iostream>
#include <sstream>
#include <chrono>
#include <random>
#include <sstream>
// Internals
#include "Mesh.h"
#include "Transform.h"
#include "target_camera.h"
#include "Shader.h"

class playerSelectScene
{
public:
	// Constructors
	playerSelectScene();
	~playerSelectScene();

	// Gameplay 
	int selectedPlayers = 0;
	int selectedDifficulty = 0;

	// Getters
	inline bool selectedAmountOfPlayers() { return selectedPlayers; }
	inline bool selectedChosenDifficulty() { return selectedDifficulty; }


	float total_time = 0.0f;
	int previousMenuItem, currentMenuItem;

	// Booleans for key pressing - used to make sure players cant change options rapidly
	bool keyDown = false;
	bool keyUp = false;
	bool keyLeft = false;
	bool keyRight = false;
	bool keyEnter = false;

	// Background Mesh		 0
	// PlayersLabel Mesh     1
	// OnePlayerBtn Mesh	 2
	// TwoPlayerBtn Mesh	 3
	// DifficultyLabel Mesh  4
	// EasyBtn				 5
	// MediumBtn			 6
	// HardBtn				 7
	// StartGameBtn			 8
	// MainMenuBtn			 9

	// Used for selection of labels
	int playerSelect = 1;
	int difficultySelect = 1;
	int buttonSelect = 1;
	int playerChoice = 0;
	int difficultyChoice = 0;
	int numberOfHoles = 1;

	// Difficulty; number of tiles in level - NOT SURE WHAT THIS IS
	int courseLength = 12;

	// Draw stuff
	void Loop(GLFWwindow* win);
	// Input 
	void Input(GLFWwindow* win);
	// Setup
	void Init(GLFWwindow* win);
	// Update
	void Update(GLFWwindow* window);
	// Render
	void Render(GLFWwindow* window);
	//to track and change textures
	void ChangeTexutes(GLFWwindow* win);
	//for action keys
	void Click_or_Enter(GLFWwindow* window);
	void Track_Mouse(GLFWwindow* win);
};