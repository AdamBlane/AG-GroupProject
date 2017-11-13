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
#include "courseGenV2.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "free_camera.h"
#include "chase_camera.h"
#include "tileBuilder.h"
#include "target_camera.h"
#include "courseGenTiles.h"

using namespace AllCamera;
using namespace std::chrono;

class gameScene
{
public:
	// Default constructor
	gameScene();
	// Deconstructor
	~gameScene();


	// General game variables
	vector<BaseTile> algTiles; // Game tiles list; these tiles have position data (by M)
	vector<Tile> tiles; // Tile meshes to be rendered, created by V
	vector<Tile> sceneryTiles; // sceneryTiles to be renederd
	vector<int> levelSeed; // This course seed; each tile has an int id
	int courseSize; // Total number of tiles this level

	// Gameplay variables
	int timeBeenInScene = 0; // Time from when the scene is fully loaded
	int timeCounter = 0;
	int strokeCounter = 0; // Counts the amount of strokes the player takes
	bool continuePressed = false; // Variable used to see if the user has pressed a key - used for HUDs
	int holeTimer = 0; // The amount time the user to get the ball in the hole
	int timeRemainingInSeconds = 0, timeRemainingInTenths = 0, timeRemainingInMinutes = 0;
	int timeSinceContinueWasPressed;  // The time since the user has pressed the continue button
	bool hasUserCompletedHole = false; // Boolean which tells the game if the user has completed the hole
	bool hasUserCompletedHoleTextures = false; // Boolean which tells the game to update the textures based on if the user has completed the hole
	bool isUserOutOfTime = false; // Boolean which tells the game if they are out of time
	bool isUserOutOfStrokes = false; // Boolean which tells the game if they are out of strokes
	int timeToThisMethod = 0; // Time to this method - used for countdown HUD

	// Player information
	int selectedDifficulty = 1; // The selected difficulty on the player select screen
	int selectedPlayers = 1; // The amount of players selected on the player select screen
	int playerOneShots = 0; // The amount of shots users one has taken
	int playerTwoShots = 0; // The amount of shots uer two has taken

	Shader* textureShader;
	Transform shaderTrans;		
	int currentTile = 0; // Tracks tile player is on 
	double lastFrame = 0;
	double thisFrame = glfwGetTime();
	float dt = 0.016; // Lock to 60fps
	bool pPressed = false; // Prevent shooting ball again whilst already moving
	float Pcounter; // This is a force counter (TODO: rename)
	bool levelSaved = false; // Prevent saving same level more than once

	// Cameras
	free_camera* freeCam;	
	float camSpeed = 2.0f; // camSpeed WAS called WASDSPEED
	chase_camera* chaseCam;
	float chaseCamAngle, cameraType = 1;// for switching on/off free/chase cam
	double cursor_x, cursor_y = 0.0;// For finding cursor pos on screen
	target_camera* tarCam;
	
	// Golf ball
	Mesh* golfBallMesh;
	Texture* golfBallTexture;
	Transform golfBallTransform;
	vec3 gbDirection; // Normalised direction vector
	vec3 gbVelocity; // Velocity is dir * speed	
	bool golfBallMoving = false; // Is golf ball moving
	float speed; // Ball speed
	// Arrow
	Mesh* arrowMesh;
	Texture* arrowTexture;
	Transform arrowTransform;

	// HUD
	// Stroke Label 
	Mesh* strokeLabelMesh;
	Transform strokeLabelTrans;
	// Power Label
	Mesh* powerLabelMesh;
	Transform powerLabelTrans;
	// Player Label
	Mesh* playerLabelMesh;
	Transform playerLabelTrans;
	// Power Bar Outline
	Mesh* powerBarOutlineDisplayMesh;
	Transform powerBarOutlineDisplayTrans;
	// Power Bar
	Mesh* powerBarMesh;
	Transform powerBarTrans;
	// Centre Information Labels
	Mesh* centreInformationHeaderLabelMesh;
	Transform centreInformationHeaderLabelTrans;
	Mesh* centreInformationFooterOneLabelMesh;
	Transform centreInformationFooterOneLabelTrans;
	Mesh* centreInformationFooterTwoLabelMesh;
	Transform centreInformationFooterTwoLabelTrans;
	// Timer information
	Mesh* timerFirstUnitLabelMesh;
	Mesh* timerSecondUnitLabelMesh;
	Mesh* timerThirdUnitLabelMesh;
	Mesh* timerForthUnitLabelMesh;
	Mesh* timerColonLabelMesh;
	Transform timerFirstUnitLabelTrans;
	Transform timerSecondUnitLabelTrans;
	Transform timerThirdUnitLabelTrans;
	Transform timerForthUnitLabelTrans;
	Transform timerColonLabelTrans;
	// Loading screen
	Mesh* loadingMesh;
	Transform loadingTrans;

	// Setup scene. Last seed params is optional; = denotes default value
	// If called from loadGameScene, requires seed value(as string)
	void Init(GLFWwindow* window, int courseLength, string seed = "seed");
	// Loads level of given size; random if no optional seed given
	void LoadGame(string seed);
	// Fills space around level with scenery tiles
	void FillScenery();
	// Translates list of alg tiles (M) into mesh tiles (V)
	void SetupTilesToBeDrawn();
	// Game loop and its functions
	void Loop(GLFWwindow* window);
	void Input(GLFWwindow* window);
	void Update(GLFWwindow* window);
	void Collisions();
	void Render(GLFWwindow* window);
};