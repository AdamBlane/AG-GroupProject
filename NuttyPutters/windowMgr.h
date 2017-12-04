#pragma once

// Externals
#include "glew_glfw.h"
#include "include\inc\fmod.hpp"


// Internals
#include "sceneMgr.h"


class windowMgr
{
	private:
		// Store singleton instance
		static windowMgr* instance;
		//the window posistion and size
		// Private constructor to avoid instancing
		windowMgr();
		// Deconstructor
		~windowMgr();
	public:
		// Static singleton access method
		static windowMgr* getInstance();
		// This class creates and deals with the window
		GLFWwindow* win;
		// Track gamestate
		sceneMgr sceneManager;

		//for mouse movement when the resoloution changes
		double windowScale = 1.0;
		//sets the window scalon the x axise by dividing by the orignal value
		void setWindowScale(int value) { windowScale = value / 1600.0; }
		// For button navigation across all menu scenes
		int button_manager = 0;
		//track mouse
		double mouse_x, mouse_y;
		// Window width and height values
		int width, height;
		// Window offset from top left point of monitor
		int PosX, PosY;
		// Input - prevent input code from reocurring every frame button is held
		bool upPressed, downPressed, leftPressed, rightPressed, enterPressed;
		bool mouseLpressed;
		
		// All textures in the game stored here
		map<std::string, Texture*> textures;
		// All number textures stored here
		vector<Texture*> numberTextures;
		// This stores images of saved levels
		vector<Texture*> savesImages;
		// General use HUD meshes
		vector<Mesh*> meshes;
		// Unique mesh for the game loading screen
		Mesh* meshSplash;
		// 2P variant world clock meshes
		vector<Mesh*> worldClock;
		// Skybox vars
		Texture* skyboxTexture;
		Mesh* skyboxMesh;
		const string posXfileName = "..\\NuttyPutters\\skyboxes\\left.png";
		const string negXfileName = "..\\NuttyPutters\\skyboxes\\right.png";
		const string posYfileName = "..\\NuttyPutters\\skyboxes\\top.png";
		const string negYfileName = "..\\NuttyPutters\\skyboxes\\bot.png";
		const string posZfileName = "..\\NuttyPutters\\skyboxes\\back.png";
		const string negZfileName = "..\\NuttyPutters\\skyboxes\\front.png";
		// GAME SCENE UNIQUE MESHES
		Mesh* player1Mesh;
		Mesh* player2Mesh;
		Mesh* p1ArrowMesh;
		Mesh* p2ArrowMesh;
		vector<Mesh*> pickupCrateMeshes;
		Texture* pickupCrateTexture;
		vector<Transform> pickupCrateTransforms;

		// All contorller related textures are stored in here
		Texture* buttonsPS[18];
		Texture* buttonsXB[14];
		Texture* buttonsKeyboardOne[99];

		// All the game functions are stored here with the index being the function and the value being the button number
		int gameFunctions[10];
		int gameKeyboardFunctions[10];
		int gameKeyboardFunctionsPOne[10];

		// KEYBOARD - One
		// Comma = 0
		// Minus = 1
		// Full stop = 2
		// Forward Slash = 3
		// Num 0 = 4
		// Num 1 = 5
		// Num 2 = 6
		// Num 3 = 7
		// Num 4 = 8
		// Num 5 = 9
		// Num 6 = 10
		// Num 7 = 11
		// Num 8 = 12
		// Num 9 = 13
		// SemiColon ; = 14
		// Equals = = 15
		// A = 16
		// B = 17 
		// C = 18
		// D = 19
		// E = 20
		// F = 21
		// G = 22
		// H = 23
		// I = 24
		// J = 25
		// K = 26
		// L = 27
		// M = 28
		// N = 29
		// O = 30
		// P = 31
		// Q = 32
		// R = 33
		// S = 34
		// T = 35
		// U = 36
		// V = 37
		// W = 38 
		// X = 39
		// Y = 40
		// Z = 41
		// Left bracket [ = 42
		// Back slash = 43
		// Right bracket ] = 44

		// ESC = 45
		// ENTER = 46
		// TAB = 47
		// BACKSPACE = 48
		// INSERT = 49
		// DELETE = 50
		// RIGHT = 51
		// LEFT = 52
		// DOWN = 53
		// UP = 54
		// PAGEUP = 55
		// PAGEDOWN = 56
		// HOME = 57
		// END = 58
		// CAPS = 59
		// SCROLL = 60
		// NUM LOCK = 61
		// PRINT SCREEN = 62 
		// PAUSE = 63
		// F1 = 64
		// F2 = 65
		// F3 = 66
		// F4 = 67
		// F5 = 68
		// F6 = 69
		// F7 = 70 
		// F8 = 71
		// F9 = 72
		// F10 = 73
		// F11 = 74
		// F12 = 75

		// PAD 0 = 76
		// PAD 1 = 77
		// PAD 2 = 78
		// PAD 3 = 79 
		// PAD 4 = 80
		// PAD 5 = 81
		// PAD 6 = 82
		// PAD 7 = 83
		// PAD 8 = 84
		// PAD 9 = 85
		// DECIMAL = 86
		// DIVIDE = 87
		// MULTIPLY = 88
		// SUBTRACT = 89
		// ADD = 90
		// ENTER = 91
		// EQUAL = 92

		// LEFT SHIFT = 93
		// LEFT CONTROL = 94
		// LEFT ALT = 95
		// RIGHT SHIFT = 96
		// RIGHT CONTROL = 97
		// RIGHT ALT = 98

		// BUTTONS
		// A/Sqaure = 0
		// B/X(PS) = 1
		// X(XB)/Circle = 2
		// Y/Triangle = 3
		// LB/L1 = 4
		// RB/R1 = 5
		// Back/L2 = 6
		// Start/R2 = 7
		// Left Stick Push/Select = 8
		// Right Stick Push/Start = 9
		// DPAD UP/Left Stick Push = 10
		// DPAD LEFT/Right Stick Push = 11
		// DPAD DOWN/PS Button =12
		// DPAD RIGHT/Pad = 13
		// /DPAD UP = 14
		// /DPAD LEFT = 15 
		// /DPAD DOWN = 16
		// /DPAD RIGHT = 17

		// FUCTIONS
		// Select/fire = 0
		// Back/Reset = 1
		// Pause = 2
		// DPAD UP = 3
		// DPAD LEFT = 4
		// DPAD DOWN = 5
		// DPAD RIGHT = 6

		// Cameras
		target_camera* HUDtargetCam;
		target_camera* PAUSEtargetCam;
		free_camera* freeCam;
		chase_camera* p1ChaseCam;
		chase_camera* p2ChaseCam;
		vector<chase_camera*> chaseCams;
		// Shaders
		Shader* textureShader;
		Shader* skyboxShader;
		Transform texShaderTransform;

		// AUDIO
		FMOD::System *system;
		FMOD::Sound *menuSelect;	
		FMOD::Sound *golfBallPutt;
		FMOD::Sound *golfBallHit;
		FMOD::Sound *golfBallJump;
		FMOD::Sound *golfBallWoodHit;
		// Store all above declared sound effects here
		map<std::string, FMOD::Sound*> soundEffects;

		//Stuff for tiles
		vector<Mesh*> tileMeshes;
		vector<Mesh*> obstacleMeshes;
		vector<Mesh*> planeMeshes;
		map<std::string, Texture*> tileTextures;


		//mutex mut;

		// Perform initial window setup
		GLFWwindow* windowMgr::Init();
		// Load textures thread
		void LoadTextures(map<std::string, Texture*> &tileTexs, GLFWwindow* window);
		// Populate savesImages vector with image files read from saves folder
		void UpdateSavesImages(string savedImagePath);
		// Ask winMgr to get thread to play given sound
		void PlayThisSound(string sound); // string is key for sfx map
		// Actual thread function that plays the sound
		void ThreadPlaySound(FMOD::System* system, FMOD::Sound* sound);
		// Game update loop
		void Update();
		// On window close
		void CleanUp();
		// Special render loop for rendiering start scene
		void RenderSplashScreen(GLFWwindow* window);
};

