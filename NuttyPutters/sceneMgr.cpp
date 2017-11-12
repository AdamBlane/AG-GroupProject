
#include "sceneMgr.h"
#include "windowMgr.h"
/// Scene Manager is a property of windowMgr
/// It tracks gamestate, called by scene files on particular input

// Constructor
sceneMgr::sceneMgr()
{
	// On construction, first scene is start menu
	curScene = 1;
}

// Deconstructor
sceneMgr::~sceneMgr() { }

// Update game state to new scene, initialise the new scene
void sceneMgr::changeScene(unsigned int newScene, int courseLength, string seed)
{
	// Change current scene tracker to new scene
	curScene = newScene;

	// Initialise the new scene
	switch (curScene)
	{
	// Exit
	case 0: break;
	// Start scene
	case 1: 
		// Setup, pass in window held by winMgr
		startScene.Init(windowMgr::getInstance()->win);
		break;
	// Player select
	case 2:
		playerSelectScene.Init(windowMgr::getInstance()->win);
		break;
	// Load game
	case 3:
		loadGameScene.Init(windowMgr::getInstance()->win);
		break;
	// Highscore
	case 4:
		highscoreScene.Init(windowMgr::getInstance()->win);
		break;
	// Options
	case 5:
		optionsScene.Init(windowMgr::getInstance()->win);
		break;
	// Game scene
	case 6:
		// This can take 2 optional params - course size, seed string
		gameScene.Init(windowMgr::getInstance()->win, courseLength, seed);
		break;
	}
}

// Returns current scene number
unsigned int sceneMgr::getScene()
{
	return curScene;
}


