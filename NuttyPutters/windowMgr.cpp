// Externals
#include <iostream>

// Internals
#include "windowMgr.h"

/// windowMgr is a singleton class, accessed by all the scene files
/// It initialises and sets up the window, & contains the main game loop
/// On window close, it runs through closing steps
/// Called from main.cpp

// Private Constructor
windowMgr::windowMgr() { }
// Private Deconstructor
windowMgr::~windowMgr() { }


// Set instance to NULL initially, since it'll be created on demand in main
windowMgr* windowMgr::instance = NULL;

// Return windowMgr singleton instance
windowMgr* windowMgr::getInstance()
{
	// If it doesn't exist, create it
	if (instance == NULL)
		instance = new windowMgr();
	
	// Return created/existing instance
	return instance;
}

// Setup; GLFW stuff, creates window
GLFWwindow* windowMgr::Init()
{
	// Initialise GLFW libraries
	if (!glfwInit())
		exit(EXIT_FAILURE);


	width = 1600, height = 900;
	PosX = 100, PosY = 100;
	// Create window
	win = glfwCreateWindow(width, height, "Nutty Putters", NULL, NULL);
	glfwSetWindowPos(win, PosX, PosY);

	// Check window was created successfully
	if (!win)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Make window the current context
	glfwMakeContextCurrent(win);

	// Initialise GLEW 
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		std::cout << "Glew failed to initialise!" << std::endl;
	}

	// Setup texture shader
	textureShader = new Shader("..\\NuttyPutters\\textureShader");


	// Initialise general use HUD meshes
	for (int i = 0; i < 10; ++i)

	{
		Mesh* mesh = new Mesh(Mesh::RECTANGLE, vec3(0.0f, 0.0f, -1.0f), 1.0f, 1.0f); // This scale value is abritray, since it'll always be reset in each scene it's used
		meshes.push_back(mesh);
	}
	// Initialise unique meshes
	// Player meshes
	player1Mesh = new Mesh("..\\NuttyPutters\\sphere.obj");
	arrowMesh = new Mesh(Mesh::CUBOID, vec3(1.8f, 3.6f, 0.0f), 3.0f, 0.5f, 0.5f);
	// Initialise all textures, then add to the textures map
	Texture* startBackground = new Texture("..\\NuttyPutters\\Mainmenu\\startBackground.png");
	textures.insert(std::pair<std::string, Texture*>("startBackground", startBackground));

	Texture* startGameBtnSelected = new Texture("..\\NuttyPutters\\Mainmenu\\startSelected.png");
	textures.insert(std::pair<std::string, Texture*>("startGameBtnSelected", startGameBtnSelected));

	Texture* startGameBtnUnselected = new Texture("..\\NuttyPutters\\Mainmenu\\startUnselected.png");
	textures.insert(std::pair<std::string, Texture*>("startGameBtnUnselected", startGameBtnUnselected));

	Texture* loadGameBtnSelected = new Texture("..\\NuttyPutters\\Mainmenu\\loadSelected.png");
	textures.insert(std::pair<std::string, Texture*>("loadGameBtnSelected", loadGameBtnSelected));

	Texture* loadGameBtnUnselected = new Texture("..\\NuttyPutters\\Mainmenu\\loadUnselected.png");
	textures.insert(std::pair<std::string, Texture*>("loadGameBtnUnselected", loadGameBtnUnselected));

	Texture* highscoresBtnSelected = new Texture("..\\NuttyPutters\\Mainmenu\\HighScoreSelected.png");
	textures.insert(std::pair<std::string, Texture*>("highscoresBtnSelected", highscoresBtnSelected));

	Texture* highscoresBtnUnselected = new Texture("..\\NuttyPutters\\Mainmenu\\HighScoreUnselected.png");
	textures.insert(std::pair<std::string, Texture*>("highscoresBtnUnselected", highscoresBtnUnselected));
	Texture* optionsBtnSelected = new Texture("..\\NuttyPutters\\Mainmenu\\optionsSelected.png");
	textures.insert(std::pair<std::string, Texture*>("optionsBtnSelected", optionsBtnSelected));
	Texture* optionsBtnUnselected = new Texture("..\\NuttyPutters\\Mainmenu\\optionsUnselected.png");
	textures.insert(std::pair<std::string, Texture*>("optionsBtnUnselected", optionsBtnUnselected));
	Texture* internetBtnSelected = new Texture("..\\NuttyPutters\\Mainmenu\\InternetSelected.png");
	textures.insert(std::pair<std::string, Texture*>("internetBtnSelected", internetBtnSelected));
	Texture* internetBtnUnselected = new Texture("..\\NuttyPutters\\Mainmenu\\InternetUnselected.png");
	textures.insert(std::pair<std::string, Texture*>("internetBtnUnselected", internetBtnUnselected));
	Texture* exitBtnSelected = new Texture("..\\NuttyPutters\\Mainmenu\\exitSelected.png");
	textures.insert(std::pair<std::string, Texture*>("exitBtnSelected", exitBtnSelected));
	Texture* exitBtnUnselected = new Texture("..\\NuttyPutters\\Mainmenu\\exitUnselected.png");
	textures.insert(std::pair<std::string, Texture*>("exitBtnUnselected", exitBtnUnselected));
	Texture* loadGameBackground = new Texture("..\\NuttyPutters\\highscore\\optbackground.png");
	textures.insert(std::pair<std::string, Texture*>("loadGameBackground", loadGameBackground));

	// Textrures used exclusively in player select screen
	Texture* playerSelectBackground = new Texture("..\\NuttyPutters\\grass.png");
	textures.insert(std::pair<std::string, Texture*>("playerSelectBackground", playerSelectBackground));

	Texture* playersLabel = new Texture("..\\NuttyPutters\\players.png");
	textures.insert(std::pair<std::string, Texture*>("playersLabel", playersLabel));

	Texture* oneBtnUnselected = new Texture("..\\NuttyPutters\\none.png");
	textures.insert(std::pair<std::string, Texture*>("oneBtnUnselected", oneBtnUnselected));
	Texture* oneBtnSelected = new Texture("..\\NuttyPutters\\noneUnderlined.png");
	textures.insert(std::pair<std::string, Texture*>("oneBtnSelected", oneBtnSelected));

	Texture* twoBtnUnselected = new Texture("..\\NuttyPutters\\ntwo.png");
	textures.insert(std::pair<std::string, Texture*>("twoBtnUnselected", twoBtnUnselected));
	Texture* twoBtnSelected = new Texture("..\\NuttyPutters\\ntwoUnderlined.png");
	textures.insert(std::pair<std::string, Texture*>("twoBtnSelected", twoBtnSelected));

	Texture* difficultyLabel = new Texture("..\\NuttyPutters\\difficulty.png");
	textures.insert(std::pair<std::string, Texture*>("difficultyLabel", difficultyLabel));

	Texture* easyBtnUnselected = new Texture("..\\NuttyPutters\\easy.png");
	textures.insert(std::pair<std::string, Texture*>("easyBtnUnselected", easyBtnUnselected));
	Texture* easyBtnSelected = new Texture("..\\NuttyPutters\\easyUnderlined.png");
	textures.insert(std::pair<std::string, Texture*>("easyBtnSelected", easyBtnSelected));

	Texture* medBtnUnselected = new Texture("..\\NuttyPutters\\med.png");
	textures.insert(std::pair<std::string, Texture*>("medBtnUnselected", medBtnUnselected));
	Texture* medBtnSelected = new Texture("..\\NuttyPutters\\medUnderlined.png");
	textures.insert(std::pair<std::string, Texture*>("medBtnSelected", medBtnSelected));

	Texture* hardBtnUnselected = new Texture("..\\NuttyPutters\\hard.png");
	textures.insert(std::pair<std::string, Texture*>("hardBtnUnselected", hardBtnUnselected));
	Texture* hardBtnSelected = new Texture("..\\NuttyPutters\\hardUnderlined.png");
	textures.insert(std::pair<std::string, Texture*>("hardBtnSelected", hardBtnSelected));

	Texture* startGameBtnUnselectedPS = new Texture("..\\NuttyPutters\\startgame.png");
	textures.insert(std::pair<std::string, Texture*>("startGameBtnUnselectedPS", startGameBtnUnselectedPS));
	Texture* startGameBtnSelectedPS = new Texture("..\\NuttyPutters\\startgameUnderlined.png");
	textures.insert(std::pair<std::string, Texture*>("startGameBtnSelectedPS", startGameBtnSelectedPS));

	Texture* mainMenuBtnUnselected = new Texture("..\\NuttyPutters\\mainmenu.png");
	textures.insert(std::pair<std::string, Texture*>("mainMenuBtnUnselected", mainMenuBtnUnselected));
	Texture* mainMenuBtnSelected = new Texture("..\\NuttyPutters\\mainmenuUnderlined.png");
	textures.insert(std::pair<std::string, Texture*>("mainMenuBtnSelected", mainMenuBtnSelected));

	Texture* optionsBackground = new Texture("..\\NuttyPutters\\highscore\\background.png");
	textures.insert(std::pair<std::string, Texture*>("optionsBackground", optionsBackground));
	Texture* backBtnUnselected = new Texture("..\\NuttyPutters\\highscore\\back.png");
	textures.insert(std::pair<std::string, Texture*>("backBtnUnselected", backBtnUnselected));
	Texture* backBtnSelected = new Texture("..\\NuttyPutters\\highscore\\back(1).png");
	textures.insert(std::pair<std::string, Texture*>("backBtnSelected", backBtnSelected));
	Texture* windowBtnUnselected = new Texture("..\\NuttyPutters\\highscore\\wiw.png");
	textures.insert(std::pair<std::string, Texture*>("windowBtnUnselected", windowBtnUnselected));
	Texture* windowBtnSelected = new Texture("..\\NuttyPutters\\highscore\\wiw(1).png");
	textures.insert(std::pair<std::string, Texture*>("windowBtnSelected", windowBtnSelected));
	Texture* fullscreenBtnUnselected = new Texture("..\\NuttyPutters\\highscore\\full.png");
	textures.insert(std::pair<std::string, Texture*>("fullscreenBtnUnselected", fullscreenBtnUnselected));
	Texture* fullscreenBtnSelected = new Texture("..\\NuttyPutters\\highscore\\full(1).png");
	textures.insert(std::pair<std::string, Texture*>("fullscreenBtnSelected", fullscreenBtnSelected));
	// Player textures
	Texture* playerRedTexture = new Texture("..\\NuttyPutters\\ballRed.jpg");
	textures.insert(std::pair<std::string, Texture*>("playerRedTexture", playerRedTexture));

	Texture* arrowTexture = new Texture("..\\NuttyPutters\\ballBlue.jpg");
	textures.insert(std::pair<std::string, Texture*>("arrowTexture", arrowTexture));


	// Setup start scene
	sceneManager.startScene.Init(win);


	return win;
}

// Switches on current scene, calls on appropriate file to render/read input
void windowMgr::Update()
{	
	// While window is open...
	while (!glfwWindowShouldClose(win))
	{
		// Scene manager (property of winMgr) tracks game state
		switch (sceneManager.curScene)
		{
		// Exit game
		case 0:
			CleanUp();
			break;
		// Start scene
		case 1:
			// Draw content
			sceneManager.startScene.Loop(win);			
			break;
		// Player Select scene
		case 2:
			// Draw content
			sceneManager.playerSelectScene.Loop(win);
			break;
		// Load Game scene
		case 3:
			// Draw content
			sceneManager.loadGameScene.Loop(win);
			break;
		// Highscore scene
		case 4:
			// Draw content
			sceneManager.highscoreScene.Loop(win);
			break;
		// Options scene
		case 5:
			// Draw content
			sceneManager.optionsScene.Loop(win);
			break;
		// Game scene
		case 6:
			// Draw
			sceneManager.gameScene.Loop(win);
			break;
		default: break;
		}

		// DEBUG - for testing, write our current scene
		//std::cout << sceneManager.curScene << std::endl;
	}

		
}

// On window close
void windowMgr::CleanUp()
{
	glfwDestroyWindow(win); // Runs when commented out - why?
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
