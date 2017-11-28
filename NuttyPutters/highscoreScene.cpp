

#include "highscoreScene.h"
#include "windowMgr.h" // to access singleton

// Constructor
highscoreScene::highscoreScene() { }
// Deconstructor
highscoreScene::~highscoreScene() { }

void highscoreScene::Init(GLFWwindow * win)
{
	// Set scale, position and size of various meshes - all unique
	// Set background
	windowMgr::getInstance()->meshes.at(0)->SetScale(9.0f, 5.0f);
	windowMgr::getInstance()->meshes.at(0)->SetPos(vec3(0.0f, 0.0f, 0.0f));
	windowMgr::getInstance()->meshes.at(0)->SetTexture(windowMgr::getInstance()->textures["loadGameBackground"]);
	// Set action label
	windowMgr::getInstance()->meshes.at(1)->SetScale(1.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(1)->SetPos(vec3(-2.7f, 1.39f, 0.0f));
	windowMgr::getInstance()->meshes.at(1)->SetTexture(windowMgr::getInstance()->textures["actionLbl"]);
	// Set button label
	windowMgr::getInstance()->meshes.at(2)->SetScale(1.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(2)->SetPos(vec3(-1.1f, 1.39f, 0.0f));
	windowMgr::getInstance()->meshes.at(2)->SetTexture(windowMgr::getInstance()->textures["buttonLbl"]);
	// Select Fire
	// Set selectfire label
	windowMgr::getInstance()->meshes.at(3)->SetScale(2.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(3)->SetPos(vec3(-2.7f, 1.07f, 0.0f));
	windowMgr::getInstance()->meshes.at(3)->SetTexture(windowMgr::getInstance()->textures["selectfireLbl"]);
	// Set selectfire button label controller button
	windowMgr::getInstance()->meshes.at(4)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(4)->SetPos(vec3(-1.1f, 1.07f, 0.0f));
	windowMgr::getInstance()->meshes.at(4)->SetTexture(windowMgr::getInstance()->buttonsXB[2]);
	// Back Reset
	// Set backreset label
	windowMgr::getInstance()->meshes.at(5)->SetScale(2.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(5)->SetPos(vec3(-2.7f, 0.75f, 0.0f));
	windowMgr::getInstance()->meshes.at(5)->SetTexture(windowMgr::getInstance()->textures["backresetLbl"]);
	// Set backreset button label controller button
	windowMgr::getInstance()->meshes.at(6)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(6)->SetPos(vec3(-1.1f, 0.75f, 0.0f));
	windowMgr::getInstance()->meshes.at(6)->SetTexture(windowMgr::getInstance()->buttonsXB[3]);
	// Pause
	// Set pause label
	windowMgr::getInstance()->meshes.at(7)->SetScale(1.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(7)->SetPos(vec3(-2.7f, 0.43f, 0.0f));
	windowMgr::getInstance()->meshes.at(7)->SetTexture(windowMgr::getInstance()->textures["pauseLbl"]);
	// Set pause button label controller button
	windowMgr::getInstance()->meshes.at(8)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(8)->SetPos(vec3(-1.1f, 0.43f, 0.0f));
	windowMgr::getInstance()->meshes.at(8)->SetTexture(windowMgr::getInstance()->buttonsXB[7]);
	// Arrows
	// Up
	windowMgr::getInstance()->meshes.at(9)->SetScale(0.35f, 0.35f);
	windowMgr::getInstance()->meshes.at(9)->SetPos(vec3(-2.7f, 0.11f, 0.0f));
	windowMgr::getInstance()->meshes.at(9)->SetTexture(windowMgr::getInstance()->textures["upLbl"]);
	// Set up controller button
	windowMgr::getInstance()->meshes.at(10)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(10)->SetPos(vec3(-1.1f, 0.11f, 0.0f));
	windowMgr::getInstance()->meshes.at(10)->SetTexture(windowMgr::getInstance()->buttonsXB[10]);
	// Left
	windowMgr::getInstance()->meshes.at(11)->SetScale(0.35f, 0.35f);
	windowMgr::getInstance()->meshes.at(11)->SetPos(vec3(-2.7f, -0.21f, 0.0f));
	windowMgr::getInstance()->meshes.at(11)->SetTexture(windowMgr::getInstance()->textures["leftLbl"]);
	// Set left controller button
	windowMgr::getInstance()->meshes.at(12)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(12)->SetPos(vec3(-1.1f, -0.21f, 0.0f));
	windowMgr::getInstance()->meshes.at(12)->SetTexture(windowMgr::getInstance()->buttonsXB[11]);
	// Down 
	windowMgr::getInstance()->meshes.at(13)->SetScale(0.35f, 0.35f);
	windowMgr::getInstance()->meshes.at(13)->SetPos(vec3(-2.7f, -0.53f, 0.0f));
	windowMgr::getInstance()->meshes.at(13)->SetTexture(windowMgr::getInstance()->textures["downLbl"]);
	// Set down controller button
	windowMgr::getInstance()->meshes.at(14)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(14)->SetPos(vec3(-1.1f, -0.53f, 0.0f));
	windowMgr::getInstance()->meshes.at(14)->SetTexture(windowMgr::getInstance()->buttonsXB[12]);
	// Right
	windowMgr::getInstance()->meshes.at(15)->SetScale(0.35f, 0.35f);
	windowMgr::getInstance()->meshes.at(15)->SetPos(vec3(-2.7f, -0.85f, 0.0f));
	windowMgr::getInstance()->meshes.at(15)->SetTexture(windowMgr::getInstance()->textures["rightLbl"]);
	// Set right controller button
	windowMgr::getInstance()->meshes.at(16)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(16)->SetPos(vec3(-1.1f, -0.85f, 0.0f));
	windowMgr::getInstance()->meshes.at(16)->SetTexture(windowMgr::getInstance()->buttonsXB[13]);
	// Jump
	windowMgr::getInstance()->meshes.at(17)->SetScale(1.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(17)->SetPos(vec3(-2.7f, -1.17f, 0.0f));
	windowMgr::getInstance()->meshes.at(17)->SetTexture(windowMgr::getInstance()->textures["jumpLbl"]);
	// Set jump controller button
	windowMgr::getInstance()->meshes.at(18)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(18)->SetPos(vec3(-1.1f, -1.17f, 0.0f));
	windowMgr::getInstance()->meshes.at(18)->SetTexture(windowMgr::getInstance()->buttonsXB[1]);
	// Zoom In
	windowMgr::getInstance()->meshes.at(19)->SetScale(2.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(19)->SetPos(vec3(-2.7f, -1.50f, 0.0f));
	windowMgr::getInstance()->meshes.at(19)->SetTexture(windowMgr::getInstance()->textures["zoomInLbl"]);
	// Set zoom in controller button
	windowMgr::getInstance()->meshes.at(20)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(20)->SetPos(vec3(-1.1f, -1.50f, 0.0f));
	windowMgr::getInstance()->meshes.at(20)->SetTexture(windowMgr::getInstance()->buttonsXB[4]);
	// Zoom Out
	windowMgr::getInstance()->meshes.at(21)->SetScale(2.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(21)->SetPos(vec3(-2.7f, -1.82f, 0.0f));
	windowMgr::getInstance()->meshes.at(21)->SetTexture(windowMgr::getInstance()->textures["zoomOutLbl"]);
	// Set zoom out controller button
	windowMgr::getInstance()->meshes.at(22)->SetScale(0.25f, 0.25f);
	windowMgr::getInstance()->meshes.at(22)->SetPos(vec3(-1.1f, -1.82f, 0.0f));
	windowMgr::getInstance()->meshes.at(22)->SetTexture(windowMgr::getInstance()->buttonsXB[5]);
	// Main Menu
	windowMgr::getInstance()->meshes.at(23)->SetScale(2.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(23)->SetPos(vec3(2.5f, 0.0f, 0.0f));
	windowMgr::getInstance()->meshes.at(23)->SetTexture(windowMgr::getInstance()->textures["mainMenuBtnUnselected"]);
	// Set the player one and player two lbls
	// P1
	windowMgr::getInstance()->meshes.at(24)->SetScale(1.8f, 0.45f);
	windowMgr::getInstance()->meshes.at(24)->SetPos(vec3(-2.0f, 1.81f, 0.0f));
	windowMgr::getInstance()->meshes.at(24)->SetTexture(windowMgr::getInstance()->textures["playerOneLbl"]);
	// P2
	windowMgr::getInstance()->meshes.at(25)->SetScale(1.8f, 0.45f);
	windowMgr::getInstance()->meshes.at(25)->SetPos(vec3(0.0f, 1.81f, 0.0f));
	windowMgr::getInstance()->meshes.at(25)->SetTexture(windowMgr::getInstance()->textures["playerTwoLbl"]);
	// Keyboard Label
	windowMgr::getInstance()->meshes.at(26)->SetScale(1.0f, 0.5f);
	windowMgr::getInstance()->meshes.at(26)->SetPos(vec3(0.5f, 1.39f, 0.0f));
	windowMgr::getInstance()->meshes.at(26)->SetTexture(windowMgr::getInstance()->textures["keyLbl"]);
	// Select fire keyboard 
	windowMgr::getInstance()->meshes.at(27)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(27)->SetPos(vec3(0.5f, 1.07f, 0.0f));
	//windowMgr::getInstance()->meshes.at(27)->SetTexture(windowMgr::getInstance()->textures["aLbl"]);
	// Back reset keyboard
	windowMgr::getInstance()->meshes.at(28)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(28)->SetPos(vec3(0.5f, 0.75f, 0.0f));
	//windowMgr::getInstance()->meshes.at(28)->SetTexture(windowMgr::getInstance()->textures["bLbl"]);
	// Pause keyboard
	windowMgr::getInstance()->meshes.at(29)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(29)->SetPos(vec3(0.5f, 0.43f, 0.0f));
	//windowMgr::getInstance()->meshes.at(29)->SetTexture(windowMgr::getInstance()->textures["cLbl"]);
	// Up keyboard
	windowMgr::getInstance()->meshes.at(30)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(30)->SetPos(vec3(0.5f, 0.11f, 0.0f));
	//windowMgr::getInstance()->meshes.at(30)->SetTexture(windowMgr::getInstance()->textures["dLbl"]);
	// Left keyboard
	windowMgr::getInstance()->meshes.at(31)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(31)->SetPos(vec3(0.5f, -0.21f, 0.0f));
	//windowMgr::getInstance()->meshes.at(31)->SetTexture(windowMgr::getInstance()->textures["eLbl"]);
	// Down keyboard
	windowMgr::getInstance()->meshes.at(32)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(32)->SetPos(vec3(0.5f, -0.53f, 0.0f));
	//windowMgr::getInstance()->meshes.at(32)->SetTexture(windowMgr::getInstance()->textures["fLbl"]);
	// Right keyboard
	windowMgr::getInstance()->meshes.at(33)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(33)->SetPos(vec3(0.5f, -0.85f, 0.0f));
	//windowMgr::getInstance()->meshes.at(33)->SetTexture(windowMgr::getInstance()->textures["gLbl"]);
	// Jump keyboard
	windowMgr::getInstance()->meshes.at(34)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(34)->SetPos(vec3(0.5f, -1.17f, 0.0f));
	//windowMgr::getInstance()->meshes.at(34)->SetTexture(windowMgr::getInstance()->textures["hLbl"]);
	// Zoom in keyboard
	windowMgr::getInstance()->meshes.at(35)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(35)->SetPos(vec3(0.5f, -1.49, 0.0f));
	//windowMgr::getInstance()->meshes.at(35)->SetTexture(windowMgr::getInstance()->textures["iLbl"]);
	// Zoom out keyboard
	windowMgr::getInstance()->meshes.at(36)->SetScale(0.7f, 0.35f);
	windowMgr::getInstance()->meshes.at(36)->SetPos(vec3(0.5f, -1.81, 0.0f));
	//windowMgr::getInstance()->meshes.at(36)->SetTexture(windowMgr::getInstance()->textures["jLbl"]);

	//**********KEYBOARD SETUP**************//
	windowMgr::getInstance()->gameKeyboardFunctions[0] = 81;
	windowMgr::getInstance()->gameKeyboardFunctions[1] = 69;
	windowMgr::getInstance()->gameKeyboardFunctions[2] = 80;
	windowMgr::getInstance()->gameKeyboardFunctions[3] = 87;
	windowMgr::getInstance()->gameKeyboardFunctions[4] = 68;
	windowMgr::getInstance()->gameKeyboardFunctions[5] = 83;
	windowMgr::getInstance()->gameKeyboardFunctions[6] = 65;
	windowMgr::getInstance()->gameKeyboardFunctions[7] = 90;
	windowMgr::getInstance()->gameKeyboardFunctions[8] = 82;
	windowMgr::getInstance()->gameKeyboardFunctions[9] = 70;

	// For all the functions
	for (int allKeyboardFunctions = 0; allKeyboardFunctions < 10; allKeyboardFunctions++)
	{
		// If keyboard function is equal to A then change texture to A
		if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 65)
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[16]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 66) // B
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[17]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 67) // C
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[18]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 68) // D
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[19]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 69) // E
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[20]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 70) // F
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[21]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 71) // G
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[22]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 72) // H
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[23]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 73) // I
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[24]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 74) // J
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[25]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 75) // K
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[26]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 76) // L
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[27]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 77) // M
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[28]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 78) // N
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[29]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 79) // O
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[30]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 80) // P
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[31]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 81) // Q
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[32]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 82) // R
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[33]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 83) // S
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[34]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 84) // T
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[35]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 85) // U
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[36]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 86) // V
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[37]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 87) // W
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[38]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 88) // X
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[39]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 89) // Y
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[40]);
		}
		else if (windowMgr::getInstance()->gameKeyboardFunctions[allKeyboardFunctions] == 90) // Z
		{
			windowMgr::getInstance()->meshes.at(27 + allKeyboardFunctions)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[41]);
		}
	}
	
	//******CONTROLLER SETUP*************//
	// Create a variable to check if the joy stick is present - 1 means true
	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);

	// If controller is connected 
	if (present == 1)
	{
		// Dected how many buttons the controller has
		int buttonCount;
		const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
		// If the amount of buttons detected is equal to 18 then 
		if (buttonCount == 18)
		{
			cout << "Controller type = PS4! " << endl;
			// Setup the functions/buttons for ps4 controller - the function being the index and button being the equal value
			// FUNCTION/BUTTONS
			windowMgr::getInstance()->gameFunctions[0] = 2;
			windowMgr::getInstance()->gameFunctions[1] = 3;
			windowMgr::getInstance()->gameFunctions[2] = 0;
			windowMgr::getInstance()->gameFunctions[3] = 14;
			windowMgr::getInstance()->gameFunctions[4] = 15;
			windowMgr::getInstance()->gameFunctions[5] = 16;
			windowMgr::getInstance()->gameFunctions[6] = 17;
			windowMgr::getInstance()->gameFunctions[7] = 1;
			windowMgr::getInstance()->gameFunctions[8] = 4;
			windowMgr::getInstance()->gameFunctions[9] = 5;
			// For all the fucntions 
			for (int allFunctions = 0; allFunctions < 10; allFunctions++)
			{
				// If the button is 0 then 
				if (windowMgr::getInstance()->gameFunctions[allFunctions] == 0)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[0]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 1)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[1]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 2)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[2]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 3)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[3]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 4)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[4]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 5)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[5]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 6)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[6]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 7)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[7]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 8)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[8]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 9)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[9]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 10)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[10]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 11)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[11]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 12)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[12]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 13)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[13]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 14)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[14]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 15)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[15]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 16)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[16]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 17)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[17]);
				}
			}
		}
		else
		{
			cout << "Controller type = XBOX360 OR OTHER! " << endl;
			// Setup the functions/buttons for xbox controller - the function being the index and button being the equal value
			// FUNCTION/BUTTONS
			windowMgr::getInstance()->gameFunctions[0] = 2;
			windowMgr::getInstance()->gameFunctions[1] = 3;
			windowMgr::getInstance()->gameFunctions[2] = 7;
			windowMgr::getInstance()->gameFunctions[3] = 10;
			windowMgr::getInstance()->gameFunctions[4] = 11;
			windowMgr::getInstance()->gameFunctions[5] = 12;
			windowMgr::getInstance()->gameFunctions[6] = 13;
			windowMgr::getInstance()->gameFunctions[7] = 1;
			windowMgr::getInstance()->gameFunctions[8] = 4;
			windowMgr::getInstance()->gameFunctions[9] = 5;
			// For all the buttons in the game 
			for (int allFunctions = 0; allFunctions < 10; allFunctions++)
			{
				// If gamefunction equals button 0 then
				if (windowMgr::getInstance()->gameFunctions[allFunctions] == 0)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[0]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 1)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[1]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 2)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[2]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 3)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[3]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 4)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[4]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 5)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[5]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 6)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[6]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 7)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[7]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 8)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[8]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 9)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[9]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 10)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[10]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 11)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[11]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 12)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[12]);
				}
				else if (windowMgr::getInstance()->gameFunctions[allFunctions] == 13)
				{
					windowMgr::getInstance()->meshes.at(4 + (allFunctions * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[13]);
				}
			}
		}
	}
}

// Draw stuff
void highscoreScene::Loop(GLFWwindow * win)
{
	// Scene background
	glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Input
	Input(win);

	// Update
	Update(win);

	// Render
	Render(win);
}

// Input 
void highscoreScene::Input(GLFWwindow* win)
{
	// If key is pressed and boolean equals false then set bool to true
	if (glfwGetKey(win, GLFW_KEY_COMMA) && !keyboardButtonPressed[0])
	{
		keyboardButtonPressed[0] = true;
	}
	// If key is no longer pressed and bool is true then
	if (!glfwGetKey(win, GLFW_KEY_COMMA) && keyboardButtonPressed[0])
	{
		updateKeyboardFunctionsList(0, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_MINUS) && !keyboardButtonPressed[1])
	{
		keyboardButtonPressed[1] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_MINUS) && keyboardButtonPressed[1])
	{
		updateKeyboardFunctionsList(1, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_PERIOD) && !keyboardButtonPressed[2])
	{
		keyboardButtonPressed[2] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_PERIOD) && keyboardButtonPressed[2])
	{
		updateKeyboardFunctionsList(2, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_SLASH) && !keyboardButtonPressed[3])
	{
		keyboardButtonPressed[3] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_SLASH) && keyboardButtonPressed[3])
	{
		updateKeyboardFunctionsList(3, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_0) && !keyboardButtonPressed[4])
	{
		keyboardButtonPressed[4] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_0) && keyboardButtonPressed[4])
	{
		updateKeyboardFunctionsList(4, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_1) && !keyboardButtonPressed[5])
	{
		keyboardButtonPressed[5] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_1) && keyboardButtonPressed[5])
	{
		updateKeyboardFunctionsList(5, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_2) && !keyboardButtonPressed[6])
	{
		keyboardButtonPressed[6] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_2) && keyboardButtonPressed[6])
	{
		updateKeyboardFunctionsList(6, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_3) && !keyboardButtonPressed[7])
	{
		keyboardButtonPressed[7] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_3) && keyboardButtonPressed[7])
	{
		updateKeyboardFunctionsList(7, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_4) && !keyboardButtonPressed[8])
	{
		keyboardButtonPressed[8] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_4) && keyboardButtonPressed[8])
	{
		updateKeyboardFunctionsList(8, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_5) && !keyboardButtonPressed[9])
	{
		keyboardButtonPressed[9] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_5) && keyboardButtonPressed[9])
	{
		updateKeyboardFunctionsList(9, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_6) && !keyboardButtonPressed[10])
	{
		keyboardButtonPressed[10] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_6) && keyboardButtonPressed[10])
	{
		updateKeyboardFunctionsList(10, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_7) && !keyboardButtonPressed[11])
	{
		keyboardButtonPressed[11] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_7) && keyboardButtonPressed[11])
	{
		updateKeyboardFunctionsList(11, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_8) && !keyboardButtonPressed[12])
	{
		keyboardButtonPressed[12] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_8) && keyboardButtonPressed[12])
	{
		updateKeyboardFunctionsList(12, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_9) && !keyboardButtonPressed[13])
	{
		keyboardButtonPressed[13] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_9) && keyboardButtonPressed[13])
	{
		updateKeyboardFunctionsList(13, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_SEMICOLON) && !keyboardButtonPressed[14])
	{
		keyboardButtonPressed[14] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_SEMICOLON) && keyboardButtonPressed[14])
	{
		updateKeyboardFunctionsList(14, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_EQUAL) && !keyboardButtonPressed[15])
	{
		keyboardButtonPressed[15] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_EQUAL) && keyboardButtonPressed[15])
	{
		updateKeyboardFunctionsList(15, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_A) && !keyboardButtonPressed[16])
	{
		keyboardButtonPressed[16] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_A) && keyboardButtonPressed[16])
	{
		updateKeyboardFunctionsList(16, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_B) && !keyboardButtonPressed[17])
	{
		keyboardButtonPressed[17] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_B) && keyboardButtonPressed[17])
	{
		updateKeyboardFunctionsList(17, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_C) && !keyboardButtonPressed[18])
	{
		keyboardButtonPressed[18] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_C) && keyboardButtonPressed[18])
	{
		updateKeyboardFunctionsList(18, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_D) && !keyboardButtonPressed[19])
	{
		keyboardButtonPressed[19] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_D) && keyboardButtonPressed[19])
	{
		updateKeyboardFunctionsList(19, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_E) && !keyboardButtonPressed[20])
	{
		keyboardButtonPressed[20] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_E) && keyboardButtonPressed[20])
	{
		updateKeyboardFunctionsList(20, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_F) && !keyboardButtonPressed[21])
	{
		keyboardButtonPressed[21] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F) && keyboardButtonPressed[21])
	{
		updateKeyboardFunctionsList(21, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_G) && !keyboardButtonPressed[22])
	{
		keyboardButtonPressed[22] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_G) && keyboardButtonPressed[22])
	{
		updateKeyboardFunctionsList(22, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_H) && !keyboardButtonPressed[23])
	{
		keyboardButtonPressed[23] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_H) && keyboardButtonPressed[23])
	{
		updateKeyboardFunctionsList(23, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_I) && !keyboardButtonPressed[24])
	{
		keyboardButtonPressed[24] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_I) && keyboardButtonPressed[24])
	{
		updateKeyboardFunctionsList(24, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_J) && !keyboardButtonPressed[25])
	{
		keyboardButtonPressed[25] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_J) && keyboardButtonPressed[25])
	{
		updateKeyboardFunctionsList(25, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_K) && !keyboardButtonPressed[26])
	{
		keyboardButtonPressed[26] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_K) && keyboardButtonPressed[26])
	{
		updateKeyboardFunctionsList(26, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_L) && !keyboardButtonPressed[27])
	{
		keyboardButtonPressed[27] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_L) && keyboardButtonPressed[27])
	{
		updateKeyboardFunctionsList(27, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_M) && !keyboardButtonPressed[28])
	{
		keyboardButtonPressed[28] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_M) && keyboardButtonPressed[28])
	{
		updateKeyboardFunctionsList(28, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_N) && !keyboardButtonPressed[29])
	{
		keyboardButtonPressed[29] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_N) && keyboardButtonPressed[29])
	{
		updateKeyboardFunctionsList(29, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_O) && !keyboardButtonPressed[30])
	{
		keyboardButtonPressed[30] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_O) && keyboardButtonPressed[30])
	{
		updateKeyboardFunctionsList(30, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_P) && !keyboardButtonPressed[31])
	{
		keyboardButtonPressed[31] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_P) && keyboardButtonPressed[31])
	{
		updateKeyboardFunctionsList(31, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_Q) && !keyboardButtonPressed[32])
	{
		keyboardButtonPressed[32] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_Q) && keyboardButtonPressed[32])
	{
		updateKeyboardFunctionsList(32, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_R) && !keyboardButtonPressed[33])
	{
		keyboardButtonPressed[33] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_R) && keyboardButtonPressed[33])
	{
		updateKeyboardFunctionsList(33, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_S) && !keyboardButtonPressed[34])
	{
		keyboardButtonPressed[34] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_S) && keyboardButtonPressed[34])
	{
		updateKeyboardFunctionsList(34, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_T) && !keyboardButtonPressed[35])
	{
		keyboardButtonPressed[35] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_T) && keyboardButtonPressed[35])
	{
		updateKeyboardFunctionsList(35, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_U) && !keyboardButtonPressed[36])
	{
		keyboardButtonPressed[36] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_U) && keyboardButtonPressed[36])
	{
		updateKeyboardFunctionsList(36, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_V) && !keyboardButtonPressed[37])
	{
		keyboardButtonPressed[37] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_V) && keyboardButtonPressed[37])
	{
		updateKeyboardFunctionsList(37, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_W) && !keyboardButtonPressed[38])
	{
		keyboardButtonPressed[38] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_W) && keyboardButtonPressed[38])
	{
		updateKeyboardFunctionsList(38, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_X) && !keyboardButtonPressed[39])
	{
		keyboardButtonPressed[39] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_X) && keyboardButtonPressed[39])
	{
		updateKeyboardFunctionsList(39, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_Y) && !keyboardButtonPressed[40])
	{
		keyboardButtonPressed[40] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_Y) && keyboardButtonPressed[40])
	{
		updateKeyboardFunctionsList(40, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_Z) && !keyboardButtonPressed[41])
	{
		keyboardButtonPressed[41] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_Z) && keyboardButtonPressed[41])
	{
		updateKeyboardFunctionsList(41, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_LEFT_BRACKET) && !keyboardButtonPressed[42])
	{
		keyboardButtonPressed[42] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_LEFT_BRACKET) && keyboardButtonPressed[42])
	{
		updateKeyboardFunctionsList(42, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_BACKSLASH) && !keyboardButtonPressed[43])
	{
		keyboardButtonPressed[43] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_BACKSLASH) && keyboardButtonPressed[43])
	{
		updateKeyboardFunctionsList(43, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_RIGHT_BRACKET) && !keyboardButtonPressed[44])
	{
		keyboardButtonPressed[44] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_RIGHT_BRACKET) && keyboardButtonPressed[44])
	{
		updateKeyboardFunctionsList(44, 49);
	}

	if (glfwGetKey(win, GLFW_KEY_ESCAPE) && !keyboardButtonPressed[45])
	{
		keyboardButtonPressed[45] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_ESCAPE) && keyboardButtonPressed[45])
	{
		updateKeyboardFunctionsList(45, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_ENTER) && !keyboardButtonPressed[46])
	{
		keyboardButtonPressed[46] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_ENTER) && keyboardButtonPressed[46])
	{
		updateKeyboardFunctionsList(46, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_TAB) && !keyboardButtonPressed[47])
	{
		keyboardButtonPressed[47] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_TAB) && keyboardButtonPressed[47])
	{
		updateKeyboardFunctionsList(47, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_BACKSPACE) && !keyboardButtonPressed[48])
	{
		keyboardButtonPressed[48] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_BACKSPACE) && keyboardButtonPressed[48])
	{
		updateKeyboardFunctionsList(48, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_INSERT) && !keyboardButtonPressed[49])
	{
		keyboardButtonPressed[49] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_INSERT) && keyboardButtonPressed[49])
	{
		updateKeyboardFunctionsList(49, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_DELETE) && !keyboardButtonPressed[50])
	{
		keyboardButtonPressed[50] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_DELETE) && keyboardButtonPressed[50])
	{
		updateKeyboardFunctionsList(50, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_RIGHT) && !keyboardButtonPressed[51])
	{
		keyboardButtonPressed[51] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_RIGHT) && keyboardButtonPressed[51])
	{
		updateKeyboardFunctionsList(51, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_LEFT) && !keyboardButtonPressed[52])
	{
		keyboardButtonPressed[52] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_LEFT) && keyboardButtonPressed[52])
	{
		updateKeyboardFunctionsList(52, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_DOWN) && !keyboardButtonPressed[53])
	{
		keyboardButtonPressed[53] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_DOWN) && keyboardButtonPressed[53])
	{
		updateKeyboardFunctionsList(53, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_UP) && !keyboardButtonPressed[54])
	{
		keyboardButtonPressed[54] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_UP) && keyboardButtonPressed[54])
	{
		updateKeyboardFunctionsList(54, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_PAGE_UP) && !keyboardButtonPressed[55])
	{
		keyboardButtonPressed[55] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_PAGE_UP) && keyboardButtonPressed[55])
	{
		updateKeyboardFunctionsList(55, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_PAGE_DOWN) && !keyboardButtonPressed[56])
	{
		keyboardButtonPressed[56] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_PAGE_DOWN) && keyboardButtonPressed[56])
	{
		updateKeyboardFunctionsList(56, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_HOME) && !keyboardButtonPressed[57])
	{
		keyboardButtonPressed[57] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_HOME) && keyboardButtonPressed[57])
	{
		updateKeyboardFunctionsList(57, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_END) && !keyboardButtonPressed[58])
	{
		keyboardButtonPressed[58] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_END) && keyboardButtonPressed[58])
	{
		updateKeyboardFunctionsList(58, 211);
	}

	if (glfwGetKey(win, GLFW_KEY_CAPS_LOCK) && !keyboardButtonPressed[59])
	{
		keyboardButtonPressed[59] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_CAPS_LOCK) && keyboardButtonPressed[59])
	{
		updateKeyboardFunctionsList(59, 221);
	}

	if (glfwGetKey(win, GLFW_KEY_SCROLL_LOCK) && !keyboardButtonPressed[60])
	{
		keyboardButtonPressed[60] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_SCROLL_LOCK) && keyboardButtonPressed[60])
	{
		updateKeyboardFunctionsList(60, 221);
	}

	if (glfwGetKey(win, GLFW_KEY_NUM_LOCK) && !keyboardButtonPressed[61])
	{
		keyboardButtonPressed[61] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_NUM_LOCK) && keyboardButtonPressed[61])
	{
		updateKeyboardFunctionsList(61, 221);
	}

	if (glfwGetKey(win, GLFW_KEY_NUM_LOCK) && !keyboardButtonPressed[62])
	{
		keyboardButtonPressed[62] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_NUM_LOCK) && keyboardButtonPressed[62])
	{
		updateKeyboardFunctionsList(62, 221);
	}

	if (glfwGetKey(win, GLFW_KEY_PAUSE) && !keyboardButtonPressed[63])
	{
		keyboardButtonPressed[63] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_PAUSE) && keyboardButtonPressed[63])
	{
		updateKeyboardFunctionsList(63, 221);
	}

	if (glfwGetKey(win, GLFW_KEY_F1) && !keyboardButtonPressed[64])
	{
		keyboardButtonPressed[64] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F1) && keyboardButtonPressed[64])
	{
		updateKeyboardFunctionsList(64, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F2) && !keyboardButtonPressed[65])
	{
		keyboardButtonPressed[65] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F2) && keyboardButtonPressed[65])
	{
		updateKeyboardFunctionsList(65, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F3) && !keyboardButtonPressed[66])
	{
		keyboardButtonPressed[66] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F3) && keyboardButtonPressed[66])
	{
		updateKeyboardFunctionsList(66, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F4) && !keyboardButtonPressed[67])
	{
		keyboardButtonPressed[67] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F4) && keyboardButtonPressed[67])
	{
		updateKeyboardFunctionsList(67, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F5) && !keyboardButtonPressed[68])
	{
		keyboardButtonPressed[68] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F5) && keyboardButtonPressed[68])
	{
		updateKeyboardFunctionsList(68, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F6) && !keyboardButtonPressed[69])
	{
		keyboardButtonPressed[69] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F6) && keyboardButtonPressed[69])
	{
		updateKeyboardFunctionsList(69, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F7) && !keyboardButtonPressed[70])
	{
		keyboardButtonPressed[70] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F7) && keyboardButtonPressed[70])
	{
		updateKeyboardFunctionsList(70, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F8) && !keyboardButtonPressed[71])
	{
		keyboardButtonPressed[71] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F8) && keyboardButtonPressed[71])
	{
		updateKeyboardFunctionsList(71, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F9) && !keyboardButtonPressed[72])
	{
		keyboardButtonPressed[72] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F9) && keyboardButtonPressed[72])
	{
		updateKeyboardFunctionsList(72, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F10) && !keyboardButtonPressed[73])
	{
		keyboardButtonPressed[73] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F10) && keyboardButtonPressed[73])
	{
		updateKeyboardFunctionsList(73, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F11) && !keyboardButtonPressed[74])
	{
		keyboardButtonPressed[74] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F11) && keyboardButtonPressed[74])
	{
		updateKeyboardFunctionsList(74, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_F12) && !keyboardButtonPressed[75])
	{
		keyboardButtonPressed[75] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_F12) && keyboardButtonPressed[75])
	{
		updateKeyboardFunctionsList(75, 226);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_0) && !keyboardButtonPressed[76])
	{
		keyboardButtonPressed[76] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_0) && keyboardButtonPressed[76])
	{
		updateKeyboardFunctionsList(76, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_1) && !keyboardButtonPressed[77])
	{
		keyboardButtonPressed[77] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_1) && keyboardButtonPressed[77])
	{
		updateKeyboardFunctionsList(77, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_2) && !keyboardButtonPressed[78])
	{
		keyboardButtonPressed[78] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_2) && keyboardButtonPressed[78])
	{
		updateKeyboardFunctionsList(78, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_3) && !keyboardButtonPressed[79])
	{
		keyboardButtonPressed[79] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_3) && keyboardButtonPressed[79])
	{
		updateKeyboardFunctionsList(79, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_4) && !keyboardButtonPressed[80])
	{
		keyboardButtonPressed[80] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_4) && keyboardButtonPressed[80])
	{
		updateKeyboardFunctionsList(80, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_5) && !keyboardButtonPressed[81])
	{
		keyboardButtonPressed[81] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_5) && keyboardButtonPressed[81])
	{
		updateKeyboardFunctionsList(81, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_6) && !keyboardButtonPressed[82])
	{
		keyboardButtonPressed[82] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_6) && keyboardButtonPressed[82])
	{
		updateKeyboardFunctionsList(82, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_7) && !keyboardButtonPressed[83])
	{
		keyboardButtonPressed[83] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_7) && keyboardButtonPressed[83])
	{
		updateKeyboardFunctionsList(83, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_8) && !keyboardButtonPressed[84])
	{
		keyboardButtonPressed[84] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_8) && keyboardButtonPressed[84])
	{
		updateKeyboardFunctionsList(84, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_9) && !keyboardButtonPressed[85])
	{
		keyboardButtonPressed[85] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_9) && keyboardButtonPressed[85])
	{
		updateKeyboardFunctionsList(85, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_DECIMAL) && !keyboardButtonPressed[86])
	{
		keyboardButtonPressed[86] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_DECIMAL) && keyboardButtonPressed[86])
	{
		updateKeyboardFunctionsList(86, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_DIVIDE) && !keyboardButtonPressed[87])
	{
		keyboardButtonPressed[87] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_DIVIDE) && keyboardButtonPressed[87])
	{
		updateKeyboardFunctionsList(87, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_MULTIPLY) && !keyboardButtonPressed[88])
	{
		keyboardButtonPressed[88] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_MULTIPLY) && keyboardButtonPressed[88])
	{
		updateKeyboardFunctionsList(88, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_SUBTRACT) && !keyboardButtonPressed[89])
	{
		keyboardButtonPressed[89] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_SUBTRACT) && keyboardButtonPressed[89])
	{
		updateKeyboardFunctionsList(89, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_ADD) && !keyboardButtonPressed[90])
	{
		keyboardButtonPressed[90] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_ADD) && keyboardButtonPressed[90])
	{
		updateKeyboardFunctionsList(90, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_ENTER) && !keyboardButtonPressed[91])
	{
		keyboardButtonPressed[91] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_ENTER) && keyboardButtonPressed[91])
	{
		updateKeyboardFunctionsList(91, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_KP_EQUAL) && !keyboardButtonPressed[92])
	{
		keyboardButtonPressed[92] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_KP_EQUAL) && keyboardButtonPressed[92])
	{
		updateKeyboardFunctionsList(92, 244);
	}

	if (glfwGetKey(win, GLFW_KEY_LEFT_SHIFT) && !keyboardButtonPressed[93])
	{
		keyboardButtonPressed[93] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_LEFT_SHIFT) && keyboardButtonPressed[93])
	{
		updateKeyboardFunctionsList(93, 230);
	}

	if (glfwGetKey(win, GLFW_KEY_LEFT_CONTROL) && !keyboardButtonPressed[94])
	{
		keyboardButtonPressed[94] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_LEFT_CONTROL) && keyboardButtonPressed[94])
	{
		updateKeyboardFunctionsList(94, 230);
	}

	if (glfwGetKey(win, GLFW_KEY_LEFT_ALT) && !keyboardButtonPressed[95])
	{
		keyboardButtonPressed[95] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_LEFT_ALT) && keyboardButtonPressed[95])
	{
		updateKeyboardFunctionsList(95, 230);
	}

	if (glfwGetKey(win, GLFW_KEY_RIGHT_SHIFT) && !keyboardButtonPressed[96])
	{
		keyboardButtonPressed[96] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_RIGHT_SHIFT) && keyboardButtonPressed[96])
	{
		updateKeyboardFunctionsList(96, 230);
	}

	if (glfwGetKey(win, GLFW_KEY_RIGHT_CONTROL) && !keyboardButtonPressed[97])
	{
		keyboardButtonPressed[97] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_RIGHT_CONTROL) && keyboardButtonPressed[97])
	{
		updateKeyboardFunctionsList(97, 230);
	}

	if (glfwGetKey(win, GLFW_KEY_RIGHT_ALT) && !keyboardButtonPressed[98])
	{
		keyboardButtonPressed[98] = true;
	}
	if (!glfwGetKey(win, GLFW_KEY_RIGHT_ALT) && keyboardButtonPressed[98])
	{
		updateKeyboardFunctionsList(98, 230);
	}

	// Create a variable to check if the joy stick is present - 1 means true
	int present = glfwJoystickPresent(GLFW_JOYSTICK_1);

	// Dected how many buttons the controller has
	int buttonCount;
	const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);

	// If controller is connected 
	if (present == 1)
	{
		// If the amount of buttons detected is equal to 18 then - ps4 configurations
		if (buttonCount == 18)
		{
			// For loop which checks to see if buttons are pressed - i buttons
			for (int buttonNumber = 0; buttonNumber < 18; buttonNumber++)
			{
				// If button i is pressed then set corresponding boolean to true
				if (GLFW_PRESS == buttons[buttonNumber] && !buttonPressed[buttonNumber])
				{
					buttonPressed[buttonNumber] = true;
					cout << "Button Pressed: " << buttonNumber << endl;
				}

				// If a button has just been pressed and is longer being pressed then
				if (buttonPressed[buttonNumber] && !GLFW_PRESS == buttons[buttonNumber])
				{
					// If there is an empty function then
					if (isFunctionEmpty)
					{
						// Find the index of the gameFunction which has a value of 99
						indexAt99 = std::distance(windowMgr::getInstance()->gameFunctions, std::find(windowMgr::getInstance()->gameFunctions, windowMgr::getInstance()->gameFunctions + 10, 99));
						// Find the index of the game function whih is assigned to the button that has just been pressed
						indexAtButton = std::distance(windowMgr::getInstance()->gameFunctions, std::find(windowMgr::getInstance()->gameFunctions, windowMgr::getInstance()->gameFunctions + 10, buttonNumber));
						// Check if button just pressed has a function assigned to it
						if (buttonNumber == windowMgr::getInstance()->gameFunctions[indexAtButton])
						{
							// Set picture to question marks and button to rogue value of 99 - 99 will mean the function now no longer has a button assigned
							windowMgr::getInstance()->meshes.at(4 + (indexAtButton * 2))->SetTexture(windowMgr::getInstance()->textures["questionMarkLbl"]);
							windowMgr::getInstance()->gameFunctions[indexAtButton] = 99;
						}

						// Make the original empty function equal to the button
						windowMgr::getInstance()->gameFunctions[indexAt99] = buttonNumber;
						windowMgr::getInstance()->meshes.at(4 + (indexAt99 * 2))->SetTexture(windowMgr::getInstance()->buttonsPS[buttonNumber]);

						// Check if a function is equal to 99
						if (windowMgr::getInstance()->gameFunctions[0] == 99 || windowMgr::getInstance()->gameFunctions[1] == 99 || windowMgr::getInstance()->gameFunctions[2] == 99 ||
							windowMgr::getInstance()->gameFunctions[3] == 99 || windowMgr::getInstance()->gameFunctions[4] == 99 || windowMgr::getInstance()->gameFunctions[5] == 99 ||
							windowMgr::getInstance()->gameFunctions[6] == 99 || windowMgr::getInstance()->gameFunctions[7] == 99 || windowMgr::getInstance()->gameFunctions[8] == 99 ||
							windowMgr::getInstance()->gameFunctions[9] == 99)
						{
							isFunctionEmpty = true; // Set bool to true if a function is empty
						}
						else
						{
							isFunctionEmpty = false; // Set bool to false if no function is empty
						}
					}
					else
					{
						// Find the function index where the button has been pressed
						indexAtButton = std::distance(windowMgr::getInstance()->gameFunctions, std::find(windowMgr::getInstance()->gameFunctions, windowMgr::getInstance()->gameFunctions + 10, buttonNumber));
						// If function is assigned to a button then
						if (windowMgr::getInstance()->gameFunctions[indexAtButton] == buttonNumber)
						{
							// Set picture to question marks and button to rogue value of 99 - 99 will mean the function now no longer has a button assigned
							windowMgr::getInstance()->meshes.at(4 + (indexAtButton * 2))->SetTexture(windowMgr::getInstance()->textures["questionMarkLbl"]);
							windowMgr::getInstance()->gameFunctions[indexAtButton] = 99;
							// Set is Function Empty to true
							isFunctionEmpty = true;
						}
					}
					// Reset button pressed
					buttonPressed[buttonNumber] = false;
				}
			}
		}
		else
		{
			// For loop which checks to see if buttons are pressed
			for (int buttonNumber = 0; buttonNumber < 14; buttonNumber++)
			{
				// If button is pressed then set corresponding boolean to true
				if (GLFW_PRESS == buttons[buttonNumber] && !buttonPressed[buttonNumber])
				{
					buttonPressed[buttonNumber] = true;
					cout << "Button Pressed: " << buttonNumber << endl;
				}

				// If a button has just been pressed and is longer being pressed then
				if (buttonPressed[buttonNumber] && !GLFW_PRESS == buttons[buttonNumber])
				{
					// If there is an empty function then
					if (isFunctionEmpty)
					{
						// Find the index of the gameFunction which has a value of 99
						indexAt99 = std::distance(windowMgr::getInstance()->gameFunctions, std::find(windowMgr::getInstance()->gameFunctions, windowMgr::getInstance()->gameFunctions + 10, 99));
						// Find the index of the game function whih is assigned to the button that has just been pressed
						indexAtButton = std::distance(windowMgr::getInstance()->gameFunctions, std::find(windowMgr::getInstance()->gameFunctions, windowMgr::getInstance()->gameFunctions + 10, buttonNumber));
						// Check if button just pressed has a function assigned to it
						if (buttonNumber == windowMgr::getInstance()->gameFunctions[indexAtButton])
						{
							// Set picture to question marks and button to rogue value of 99 - 99 will mean the function now no longer has a button assigned
							windowMgr::getInstance()->meshes.at(4 + (indexAtButton * 2))->SetTexture(windowMgr::getInstance()->textures["questionMarkLbl"]);
							windowMgr::getInstance()->gameFunctions[indexAtButton] = 99;
						}

						// Make the original empty function equal to the button
						windowMgr::getInstance()->gameFunctions[indexAt99] = buttonNumber;
						windowMgr::getInstance()->meshes.at(4 + (indexAt99 * 2))->SetTexture(windowMgr::getInstance()->buttonsXB[buttonNumber]);

						// Check if a function is equal to 99
						if (windowMgr::getInstance()->gameFunctions[0] == 99 || windowMgr::getInstance()->gameFunctions[1] == 99 || windowMgr::getInstance()->gameFunctions[2] == 99 ||
							windowMgr::getInstance()->gameFunctions[3] == 99 || windowMgr::getInstance()->gameFunctions[4] == 99 || windowMgr::getInstance()->gameFunctions[5] == 99 ||
							windowMgr::getInstance()->gameFunctions[6] == 99 || windowMgr::getInstance()->gameFunctions[7] == 99 || windowMgr::getInstance()->gameFunctions[8] == 99 ||
							windowMgr::getInstance()->gameFunctions[9] == 99)
						{
							isFunctionEmpty = true; // Set bool to true if a function is empty
						}
						else
						{
							isFunctionEmpty = false; // Set bool to false if no function is empty
						}
					}
					else
					{
						indexAtButton = std::distance(windowMgr::getInstance()->gameFunctions, std::find(windowMgr::getInstance()->gameFunctions, windowMgr::getInstance()->gameFunctions + 10, buttonNumber));
						// If function is assigned to a button then
						if (windowMgr::getInstance()->gameFunctions[indexAtButton] == buttonNumber)
						{
							// Set picture to question marks and button to rogue value of 99 - 99 will mean the function now no longer has a button assigned
							windowMgr::getInstance()->meshes.at(4 + (indexAtButton * 2))->SetTexture(windowMgr::getInstance()->textures["questionMarkLbl"]);
							windowMgr::getInstance()->gameFunctions[indexAtButton] = 99;
							// Set is Function Empty to true
							isFunctionEmpty = true;
						}
					}

					// Reset button pressed
					buttonPressed[buttonNumber] = false;
				}
			}
		}
	}
}

// Updates the keyboard function array
void highscoreScene::updateKeyboardFunctionsList(int keyboardButtonNumber, int additionalNumber)
{
	if (isFunctionEmptyKeyboard) // Check if there is an empty keyboard function
	{
		// Find the index of the gameKeyboardFunctions which has a value of 999
		indexAt99 = std::distance(windowMgr::getInstance()->gameKeyboardFunctions, std::find(windowMgr::getInstance()->gameKeyboardFunctions, windowMgr::getInstance()->gameKeyboardFunctions + 10, 999));
		// Find the index of the gameKeyboardFunctions which is assigned to the button that has just been pressed
		indexAtKey = std::distance(windowMgr::getInstance()->gameKeyboardFunctions, std::find(windowMgr::getInstance()->gameKeyboardFunctions, windowMgr::getInstance()->gameKeyboardFunctions + 10, keyboardButtonNumber + additionalNumber));
		// Check if button just pressed has a function assigned to it
		if (windowMgr::getInstance()->gameKeyboardFunctions[indexAtKey] == keyboardButtonNumber + additionalNumber)
		{
			// Set picture to question marks and button to rogue value of 99 - 99 will mean the function now no longer has a button assigned
			windowMgr::getInstance()->meshes.at(27 + indexAtKey)->SetTexture(windowMgr::getInstance()->textures["questionMarkLbl"]);
			windowMgr::getInstance()->gameKeyboardFunctions[indexAtKey] = 999;
		}

		// Make the original empty function equal to the button
		windowMgr::getInstance()->gameKeyboardFunctions[indexAt99] = keyboardButtonNumber + additionalNumber;
		windowMgr::getInstance()->meshes.at(27 + indexAt99)->SetTexture(windowMgr::getInstance()->buttonsKeyboardOne[keyboardButtonNumber]);

		// Check if a function is equal to 99
		if (windowMgr::getInstance()->gameKeyboardFunctions[0] == 999 || windowMgr::getInstance()->gameKeyboardFunctions[1] == 999 || windowMgr::getInstance()->gameKeyboardFunctions[2] == 999 ||
			windowMgr::getInstance()->gameKeyboardFunctions[3] == 999 || windowMgr::getInstance()->gameKeyboardFunctions[4] == 999 || windowMgr::getInstance()->gameKeyboardFunctions[5] == 999 ||
			windowMgr::getInstance()->gameKeyboardFunctions[6] == 999 || windowMgr::getInstance()->gameKeyboardFunctions[7] == 999 || windowMgr::getInstance()->gameKeyboardFunctions[8] == 999 ||
			windowMgr::getInstance()->gameKeyboardFunctions[9] == 999)
		{
			isFunctionEmptyKeyboard = true; // Set bool to true if a function is empty
		}
		else
		{
			isFunctionEmptyKeyboard = false; // Set bool to false if no function is empty
		}
	}
	else
	{
		// Find the function index where the button has been pressed
		indexAtKey = std::distance(windowMgr::getInstance()->gameKeyboardFunctions, std::find(windowMgr::getInstance()->gameKeyboardFunctions, windowMgr::getInstance()->gameKeyboardFunctions + 10, keyboardButtonNumber + additionalNumber));
		// If function is assigned to a button then
		if (windowMgr::getInstance()->gameKeyboardFunctions[indexAtKey] == keyboardButtonNumber + additionalNumber)
		{
			// Set picture to question marks and button to rogue value of 99 - 99 will mean the function now no longer has a button assigned
			windowMgr::getInstance()->meshes.at(27 + indexAtKey)->SetTexture(windowMgr::getInstance()->textures["questionMarkLbl"]);
			windowMgr::getInstance()->gameKeyboardFunctions[indexAtKey] = 999;
			// Set is Function Empty to true
			isFunctionEmptyKeyboard = true;
		}
	}

	keyboardButtonPressed[keyboardButtonNumber] = false;
}

void highscoreScene::Update(GLFWwindow* win)
{
	// Update target camera
	windowMgr::getInstance()->HUDtargetCam->update(0.00001);
}

void highscoreScene::Render(GLFWwindow* win)
{
	// Calculate hud view*projection
	glm::mat4 hudVP = windowMgr::getInstance()->HUDtargetCam->get_Projection() * windowMgr::getInstance()->HUDtargetCam->get_View();

	// HUD RENDERING STARTING - DONT NOT ENTER ANY OTHER CODE NOT RELATED TO HUD BETWEEN THIS AND THE END HUD COMMENT
	// Set depth range to near to allow for HUD elements to be rendered and drawn
	glDepthRange(0, 0.01);

	for (int i = 0; i < meshesInScene; i++)
	{
		windowMgr::getInstance()->meshes.at(i)->thisTexture.Bind(0);
		windowMgr::getInstance()->textureShader->Update(windowMgr::getInstance()->texShaderTransform, hudVP);
		windowMgr::getInstance()->meshes.at(i)->Draw();
	}

	// Reset the depth range to allow for objects at a distance to be rendered
	glDepthRange(0.01, 1.0);
	// HUD RENDERING ENDED - THANK YOU AND HAVE A NICE DAY

	// Render any background stuff if required here

	// Fully reset depth range for next frame - REQUIRED
	glDepthRange(0, 1.0);

	// Bind texture shader
	windowMgr::getInstance()->textureShader->Bind();

	glfwSwapBuffers(win);
	glfwPollEvents();
}
