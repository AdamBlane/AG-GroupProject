// Internals
#include "gameScene.h"
#include "windowMgr.h" // to access singleton
#include "courseGenV2.h"
#include "UI.h"


// Default constructor
gameScene::gameScene() { }
// Deconstructor
gameScene::~gameScene() 
{
	// Delete everything in alg tiles since it was declared on heap
	for (auto &t : algTiles)
	{
		delete(t);
	}

}

// Setup scene; seed is an optional param passed in by loadGameScene
void gameScene::Init(GLFWwindow* window, int courseLength, int playerCount, string seed)
{
	// Set GL properties 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	// Hide cursor
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// Get initial cursor pos
	glfwSetCursorPos(window, cursor_x, cursor_y);
	// Scene background
	glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
	// LEVEL GEN
	//courseGenV2 cg(12);
	//algTiles = cg.run();

	// Record desired course size 
	courseSize = courseLength;

	// Load game, takes a seed (either given or default)
	LoadGame(seed); // Results in filled algTiles and levelSeed lists

	// Take alg tiles, turn into render tiles
	SetupTilesToBeDrawn();

	// Setup scenery tiles
	FillScenery();

	
	// Save player count
	numPlayers = playerCount;

	// Setup players 
	for (int p = 0; p < playerCount; ++p)
	{
		// Player setup
		// Create input config filename for this player
		string path = "..\\NuttyPutters\\input\\p" + to_string(p + 1) + "input.txt";
		Player player(path);
		player.transform.getScale() = vec3(0.5);
		player.transform.getPos() = vec3(-2.0 + p * 4, 1.0f, 0.0f);
		// Arrow setup	
		player.arrowTransform.getScale() = vec3(0.5);
		player.arrowTransform.getPos() = vec3(player.transform.getPos().x, player.transform.getPos().y - 1.6, player.transform.getPos().z);
		// Chase cam setup	
		windowMgr::getInstance()->chaseCams[p]->set_target_roation(vec3(0.0f, 0.0f, 0.0f));
		windowMgr::getInstance()->chaseCams[p]->set_target_pos(vec3(player.transform.getPos()));	
		
		// Add to players list
		players.push_back(player);
	}
	// Assign arrow textures for both player arrows
	windowMgr::getInstance()->p1ArrowMesh->SetTexture(windowMgr::getInstance()->textures["playerBlueTexture"]); //?
	windowMgr::getInstance()->p2ArrowMesh->SetTexture(windowMgr::getInstance()->textures["playerRedTexture"]);



	// Set camera startup properties
	cameraType = 1; // Want chase cam by default	
	windowMgr::getInstance()->freeCam->set_Posistion(vec3(0, 10, -10));
	windowMgr::getInstance()->freeCam->set_Target(vec3(0, 0, 0));
	windowMgr::getInstance()->PAUSEtargetCam->set_Posistion(pauseCamPos);
	windowMgr::getInstance()->PAUSEtargetCam->set_Target(pauseCamTarget);

	// Initiate UI
	uiMgr.Init();

	// Set the amount of time the user has to complete the hole
	holeTimer = 80;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// Loads either random level of certain size, or level by seed
void gameScene::LoadGame(string seed)
{
	// Create the course gen object
	courseGenV2 cgSystem;
	// Setup the seed (either given or default)
	levelSeed = cgSystem.SetupSeed(seed);

	// Use seed to generate the algorithm tiles list
	algTiles = cgSystem.SetupAlgTiles(levelSeed);

	// Testing
	level2seed = cgSystem.SetupSeed(seed);
	level2algTiles = cgSystem.SetupAlgTiles(level2seed);
}

// Populates scenery tiles
void gameScene::FillScenery()
{

		// Get boundary positions of level tiles in x and z
		float xMax2 = 0;
		float xMin2 = 0;
		float zMax2 = 0;
		float zMin2 = 0;
		float yMin2 = 0;
		for (auto &t : level2algTiles)
		{
			if (t->thisCoords.x > xMax2)
				xMax2 = t->thisCoords.x;
			if (t->thisCoords.x < xMin2)
				xMin2 = t->thisCoords.x;

			if (t->thisCoords.z > zMax2)
				zMax2 = t->thisCoords.z;
			if (t->thisCoords.z < zMin2)
				zMin2 = t->thisCoords.z;

			if (t->thisCoords.y < yMin2)
				yMin2 = t->thisCoords.y;
		}
		// Add another tile's width to boundaries
		xMin2 -= 10; // To add another layer to the boundary, add 10 to each value
		zMin2-= 20;
		xMax2 += 20;
		zMax2 += 10;
		// Set the pause target cam pos and target, now that we know level dimensions
		pauseCamPos.x = xMin2, pauseCamPos.y = 30.0f, pauseCamPos.z = zMin2;
		pauseCamTarget.x = (xMax2 + xMin2) / 2.0f, pauseCamTarget.y = 1.0f, pauseCamTarget.z = (zMax2 + zMin2) / 2.0f;


		// Starting in corner, fill with scenery tile if not already filled by level tile
		// Z
		for (int zPos = zMax2; zPos > zMin2; zPos -= 10) // 10 = tile size
		{
			// Work in rows; every x for a single z
			for (int xPos = xMin2; xPos < xMax2; xPos += 10)
			{
				vec3 thisPos = vec3(xPos, 0.0f, zPos); // Not dealing with ramps for now
													   // Check if this pos is already taken by a level tile
				bool posTaken = false;
				// Contains search; there will only be one match
				for (int i = 0; i < level2algTiles.size(); ++i)
				{
					if (level2algTiles.at(i)->thisCoords == thisPos)
					{
						// We have a match
						posTaken = true;
					}
				}
				// If able to create a scenery tile...
				if (!posTaken)
				{
					// Create straight tile
					//Mesh lava(Mesh::QUAD, "..\\NuttyPutters\\box.jpg", thisPos, 10.0f, 10.0f, 10.0f);
					Tile tile(Tile::SCENERY, thisPos, 0);
					//tile.transform.getRot().x = -0.785398;
					// Add to list of tiles to be rendered
					level2sceneryTiles.push_back(tile);
				}
			} // end x block
		} // end z block

		// Get boundary positions of level tiles in x and z
		float xMax = 0;
		float xMin = 0;
		float zMax = 0;
		float zMin = 0;
		float yMin = 0;
		for (auto &t : algTiles)
		{
			if (t->thisCoords.x > xMax)
				xMax = t->thisCoords.x;
			if (t->thisCoords.x < xMin)
				xMin = t->thisCoords.x;

			if (t->thisCoords.z > zMax)
				zMax = t->thisCoords.z;
			if (t->thisCoords.z < zMin)
				zMin = t->thisCoords.z;

			if (t->thisCoords.y < yMin)
				yMin = t->thisCoords.y;
		}
		// Add another tile's width to boundaries
		xMin -= 10; // To add another layer to the boundary, add 10 to each value
		zMin -= 20;
		xMax += 20;
		zMax += 10;
		// Set the pause target cam pos and target, now that we know level dimensions
		pauseCamPos.x = xMin, pauseCamPos.y = 30.0f, pauseCamPos.z = zMin;
		pauseCamTarget.x = (xMax + xMin) / 2.0f, pauseCamTarget.y = 1.0f, pauseCamTarget.z = (zMax + zMin) / 2.0f;


		// Starting in corner, fill with scenery tile if not already filled by level tile
		// Z
		for (int zPos = zMax; zPos > zMin; zPos -= 10) // 10 = tile size
		{
			// Work in rows; every x for a single z
			for (int xPos = xMin; xPos < xMax; xPos += 10)
			{
				vec3 thisPos = vec3(xPos, 0.0f, zPos); // Not dealing with ramps for now
													   // Check if this pos is already taken by a level tile
				bool posTaken = false;
				// Contains search; there will only be one match
				for (int i = 0; i < algTiles.size(); ++i)
				{
					if (algTiles.at(i)->thisCoords == thisPos)
					{
						// We have a match
						posTaken = true;
					}
				}
				// If able to create a scenery tile...
				if (!posTaken)
				{
					// Create straight tile
					//Mesh lava(Mesh::QUAD, "..\\NuttyPutters\\box.jpg", thisPos, 10.0f, 10.0f, 10.0f);
					Tile tile(Tile::SCENERY, thisPos, 0);
					//tile.transform.getRot().x = -0.785398;
					// Add to list of tiles to be rendered
					sceneryTiles.push_back(tile);
				}
			} // end x block
		} // end z block
	

}

// Creates tile classes to be drawn
void gameScene::SetupTilesToBeDrawn()
{
	int index = 0;


		// TILE CREATION
		for (auto &t : level2algTiles)
		{
			int obstacleID = 0;
			bool hasObstacle = false;

			// Ramp testing
			// Ramp up when dir is down
			if (t->id == 7)
			{
				//hasObstacle = Tile::randomNumber(0, 1);
				//if (hasObstacle)
				//{
				//	obstacleID = Tile::randomNumber(1, 2);
				//	//save this tile position in algTiles
				//	obstacles.push_back(index);
				//	obstacles.push_back(obstacleID);
				//}
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, 0);
				// Rotate on x
				tile.transform.getRot().x = -0.349066;
				tile.transform.getPos().y += 1.8;
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			// Ramp down when dir is up
			if (t->id == 8)
			{
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, obstacleID);
				// Rotate on x
				tile.transform.getRot().x = -0.349066;
				tile.transform.getPos().y -= 1.8;
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			if (t->id == 0) // Start
			{
				// Create start tile
				Tile tile(Tile::START, t->thisCoords, obstacleID);
				// Start tile needs rotating 180 (should always face down)
				tile.transform.getRot().y = 3.14159;
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			else if (t->id == 1) // Straight V
			{
				hasObstacle = Tile::randomNumber(0, 1);
				if (hasObstacle)
				{
					obstacleID = Tile::randomNumber(1, 2);
					//save this tile position in algTiles
					obstacles.push_back(index);
					obstacles.push_back(obstacleID);
				}
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, 0);
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			else if (t->id == 2) // Straight H
			{
				hasObstacle = Tile::randomNumber(0, 1);
				if (hasObstacle)
				{
					obstacleID = Tile::randomNumber(1, 2);
					//save this tile position in algTiles
					obstacles.push_back(index);
					obstacles.push_back(obstacleID);
				}
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, 0);
				// Straight needs rotating by 90, since it's vertical by default
				tile.transform.getRot().y = 1.5708;
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			else if (t->id == 3) // Corner BL
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Corner needs rotating by 90
				tile.transform.getRot().y = 1.5708;
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			else if (t->id == 4) // Corner BR
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Corner needs rotating by 90
				tile.transform.getRot().y = 3.14159;
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			else if (t->id == 5) // Corner TL
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			else if (t->id == 6) // Corner TR
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Corner needs rotating by 90
				tile.transform.getRot().y = -1.5708;
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
			else if (t->id == 9) // end
			{
				// Create start tile
				Tile tile(Tile::END, t->thisCoords, obstacleID);
				// Consult direction to determine how much to rotate
				if (t->outDir.going_up)
				{
					tile.transform.getRot().y = 3.14159;
				}
				else if (t->outDir.going_down)
				{
					// No rotation needed
				}
				else if (t->outDir.going_left)
				{
					tile.transform.getRot().y = -1.5708;
				}
				else if (t->outDir.going_right)
				{
					tile.transform.getRot().y = 1.5708;
				}
				// Add to list of tiles to be rendered
				level2tiles.push_back(tile);
			}
		}

		// TILE CREATION
		for (auto &t : algTiles)
		{
			int obstacleID = 0;
			bool hasObstacle = false;

			// Ramp testing
			// Ramp up when dir is down
			if (t->id == 7)
			{
				//hasObstacle = Tile::randomNumber(0, 1);
				//if (hasObstacle)
				//{
				//	obstacleID = Tile::randomNumber(1, 2);
				//	//save this tile position in algTiles
				//	obstacles.push_back(index);
				//	obstacles.push_back(obstacleID);
				//}
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, 0);
				// Rotate on x
				tile.transform.getRot().x = -0.349066;
				tile.transform.getPos().y += 1.8;
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			// Ramp down when dir is up
			if (t->id == 8)
			{
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, obstacleID);
				// Rotate on x
				tile.transform.getRot().x = -0.349066;
				tile.transform.getPos().y -= 1.8;
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			if (t->id == 0) // Start
			{
				// Create start tile
				Tile tile(Tile::START, t->thisCoords, obstacleID);
				// Start tile needs rotating 180 (should always face down)
				tile.transform.getRot().y = 3.14159;
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			else if (t->id == 1) // Straight V
			{
				hasObstacle = Tile::randomNumber(0, 1);
				if (hasObstacle)
				{
					obstacleID = Tile::randomNumber(1, 2);
					//save this tile position in algTiles
					obstacles.push_back(index);
					obstacles.push_back(obstacleID);
				}
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, 0);
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			else if (t->id == 2) // Straight H
			{
				hasObstacle = Tile::randomNumber(0, 1);
				if (hasObstacle)
				{
					obstacleID = Tile::randomNumber(1, 2);
					//save this tile position in algTiles
					obstacles.push_back(index);
					obstacles.push_back(obstacleID);
				}
				// Create straight tile
				Tile tile(Tile::STRAIGHT, t->thisCoords, 0);
				// Straight needs rotating by 90, since it's vertical by default
				tile.transform.getRot().y = 1.5708;
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			else if (t->id == 3) // Corner BL
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Corner needs rotating by 90
				tile.transform.getRot().y = 1.5708;
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			else if (t->id == 4) // Corner BR
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Corner needs rotating by 90
				tile.transform.getRot().y = 3.14159;
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			else if (t->id == 5) // Corner TL
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			else if (t->id == 6) // Corner TR
			{
				// Create corner tile
				Tile tile(Tile::CORNER, t->thisCoords, obstacleID);
				// Corner needs rotating by 90
				tile.transform.getRot().y = -1.5708;
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
			else if (t->id == 9) // end
			{
				// Create start tile
				Tile tile(Tile::END, t->thisCoords, obstacleID);
				// Consult direction to determine how much to rotate
				if (t->outDir.going_up)
				{
					tile.transform.getRot().y = 3.14159;
				}
				else if (t->outDir.going_down)
				{
					// No rotation needed
				}
				else if (t->outDir.going_left)
				{
					tile.transform.getRot().y = -1.5708;
				}
				else if (t->outDir.going_right)
				{
					tile.transform.getRot().y = 1.5708;
				}
				// Add to list of tiles to be rendered
				tiles.push_back(tile);
			}
		}
	


}

// Main game loop 
void gameScene::Loop(GLFWwindow* window)
{
	// Clear buffer bits (should this be done here?)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Input
	Input(window);

	// Update
	Update(window);

	// Collisions
	Collisions();

	// Render
	Render(window);
}

// Act on input
void gameScene::Input(GLFWwindow* window)
{
	// Loop around players and their inputs for both keyboard and controller
	int thisPlayer = 0;
	for (auto &p : players)
	{
		// Jump
		if (glfwGetKey(window, p.jumpButton))
		{
			p.jumpPressed = true;
		}
		if (!glfwGetKey(window, p.jumpButton))
		{
			if (p.jumpPressed)
			{
				physicsSystem.Jump(p, 5.0f); // Arbitrary jump value
				p.isMoving = true;
				// Flip
				p.jumpPressed = false;
			}
		}
			
		// Pause
		if (glfwGetKey(window, GLFW_KEY_P))
		{
			// Change to pause target cam
			cameraType = 2;
			Render(window); // Render it
			// Quick screenshot - need to do this twice; once here, again on Save
			// Alt press below ensures only game window is captured
			keybd_event(VK_MENU, 0, 0, 0); //Alt Press
			keybd_event(VK_SNAPSHOT, 0, 0, 0); //PrntScrn Press
			keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); //PrntScrn Release
			keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0); //Alt Release

			cout << "game paused" << endl;
			bool paused = true;
			while (paused)
			{
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
				// Need this to listen for further key presses
				glfwPollEvents();
				// Exit game 
				if (glfwGetKey(window, GLFW_KEY_B))
				{
					// Scene 0 is no scene - it runs winMgr.CleanUp() and closes app
					windowMgr::getInstance()->sceneManager.changeScene(0);
					break;
				}

				// Save this level 
				if (glfwGetKey(window, GLFW_KEY_S))
				{
					// Only save if not previously saved/loaded a saved level
					if (!levelSaved)
					{
						// Open file to append level seed 
						ofstream saves("saves.csv", ofstream::app);
						// ID of each tile makes up seed
						for (auto &t : algTiles)
						{
							saves << t->id;
						}
						saves << endl;
						cout << "Level saved" << endl;
						levelSaved = true;

						// Also save image of level
						// Alt press below ensures only game window is captured
						keybd_event(VK_MENU, 0, 0, 0); //Alt Press
						keybd_event(VK_SNAPSHOT, 0, 0, 0); //PrntScrn Press
						keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); //PrntScrn Release
						keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0); //Alt Release


						//// The above saves the game window capture to clipboard
						//// Retrieve image from clipboard, taken from https://www.experts-exchange.com/questions/24769725/Saving-a-clipboard-print-screen-image-to-disk-in-a-jpg-or-bmp-file-format.html
						HWND hwnd = GetDesktopWindow();
						if (!OpenClipboard(hwnd))
							cout << "Error with HWND" << endl;
						OpenClipboard(NULL);
						HBITMAP hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);
						if (hBitmap == NULL)
							cout << "Error with clipboard bmp data" << endl;
						CloseClipboard();
						CImage image;
						image.Attach(hBitmap);
						// Build string to save with level seed name
						string fileName = "..\\NuttyPutters\\savesImages\\";
						for (auto &i : levelSeed)
						{
							fileName += to_string(i);
						}
						fileName += ".bmp";
						image.Save(fileName.c_str(), Gdiplus::ImageFormatBMP);
						cout << "course image saved as " << fileName << endl;

						// Tell winMgr to update its saved images list
						windowMgr::getInstance()->UpdateSavesImages(fileName.c_str());
					} // end level saving code

				}

				// Unpause
				if (glfwGetKey(window, GLFW_KEY_U))
				{
					glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
					cameraType = 1;
					paused = false;
					break;
				}

				// Exit to main menu
				//This function resets the scene to an empty screen
				if (glfwGetKey(window, GLFW_KEY_C))
				{
					// glLoadIdentity(); might need this later
					windowMgr::getInstance()->sceneManager.changeScene(1);
					break;
				}

			} // end while paused
			cout << "Unpaused" << endl;
		} // end pause

		// If button one is pressed change to free camera
		if (glfwGetKey(window, GLFW_KEY_1))
		{
			// Set camera version to free camera
			cout << "Free Camera selected" << endl;
			cameraType = 0;
			// Set the free cam position to where the chasecam stopped moving for debugging can me changed later
			windowMgr::getInstance()->freeCam->set_Posistion(windowMgr::getInstance()->chaseCams[0]->get_Posistion());
		}

		// If button two is pressed change to chase camera
		if (glfwGetKey(window, GLFW_KEY_2))
		{
			// Set camera version to chase camera
			cout << "Chase Camera selected" << endl;
			cameraType = 1;
		}

		// If the X button is pressed then continue on with game -used for HUD elements
		if (glfwGetKey(window, GLFW_KEY_X))
		{
			continuePressed = true;
		}

		// FREE CAM controls
		if (cameraType == 0)
		{
			// Create vector to apply to current cam pos
			vec3 freeCamPos = vec3(0, 0, 0);

			// Camera controls
			if (glfwGetKey(window, GLFW_KEY_W))
			{
				freeCamPos = (vec3(0, 0, camSpeed * dt));
			}
			if (glfwGetKey(window, GLFW_KEY_A))
			{
				freeCamPos = (vec3(-camSpeed * dt, 0, 0));
			}
			if (glfwGetKey(window, GLFW_KEY_S))
			{
				freeCamPos = (vec3(0, 0, -camSpeed * dt));
			}
			if (glfwGetKey(window, GLFW_KEY_D))
			{
				freeCamPos = (vec3(camSpeed * dt, 0, 0));
			}
			if (glfwGetKey(window, GLFW_KEY_Q))
			{
				freeCamPos = (vec3(0, camSpeed * dt, 0));
			}
			if (glfwGetKey(window, GLFW_KEY_E))
			{
				freeCamPos = (vec3(0, -camSpeed * dt, 0));
			}
			if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT))
			{
				camSpeed = 10.0f;
			}
			else
				camSpeed = 2.0f;

			// Move camera by new pos after input
			windowMgr::getInstance()->freeCam->move(freeCamPos);
		}
		// CHASE CAM controls
		else if (cameraType == 1)
		{
			// If ball is not moving then allow for angle on chase camera to be changed
			if (!p.isMoving)
			{
				// controls in the chase camera 
				if (glfwGetKey(window, p.rightButton))
				{
					//function to rotate 
					windowMgr::getInstance()->chaseCams[thisPlayer]->yaw_it(camSpeed * dt * 0.5); // TODO - make camSpeed a variable to allow sensitivity settings
					// Decrease chase camera angle (out of 360 degrees)
					p.chaseCamAngle -= (camSpeed * dt * 0.5);
				}
				if (glfwGetKey(window, p.leftButton))
				{
					windowMgr::getInstance()->chaseCams[thisPlayer]->neg_yaw_it(camSpeed * dt * 0.5);
					// Increase chase camera angle (out of 360 degrees)
					p.chaseCamAngle += (camSpeed * dt * 0.5);
				}
			}

		

			// Camera movement
			if (glfwGetKey(window, p.downButton))
			{
				windowMgr::getInstance()->chaseCams[thisPlayer]->neg_pitch_it(camSpeed * dt * 0.5, p.transform.getPos(), windowMgr::getInstance()->chaseCams[thisPlayer]->get_Posistion(), windowMgr::getInstance()->chaseCams[thisPlayer]->get_pos_offset().y);
			}
			if (glfwGetKey(window, p.upButton))
			{
				windowMgr::getInstance()->chaseCams[thisPlayer]->pitch_it(camSpeed * dt * 0.5, p.transform.getPos(), windowMgr::getInstance()->chaseCams[thisPlayer]->get_Posistion(), windowMgr::getInstance()->chaseCams[thisPlayer]->get_pos_offset().y);
			}
			if (glfwGetKey(window, p.zoomOutButton))
			{
				//function to rotate 
				windowMgr::getInstance()->chaseCams[thisPlayer]->zoom_out(camSpeed * dt * 0.5);
			}
			if (glfwGetKey(window, p.zoomInButton))
			{
				windowMgr::getInstance()->chaseCams[thisPlayer]->zoom_in(camSpeed * dt * 0.5);
			}

			
			// If chase camera angle is greater than 360 reset to 0
			if (p.chaseCamAngle > 6.28319)
			{
				p.chaseCamAngle = 0.0;
			}
			// If chase camera angle is less than 0 then reset to 360
			else if (p.chaseCamAngle < 0)
			{
				p.chaseCamAngle = 6.28319;
			}

			
		} // end chase camera controls

		// Player fire
		if (continuePressed)
		{
			// If Fire is pressed 
			if (glfwGetKey(window, p.fireButtton))
			{
				if (!p.isMoving)
				{
					// Increment power counter as long as fire is held
					p.power += 0.2f;

					// Update the power bar based on the the fireCounter value 
					//powerBarTrans.getPos().x -= (fireCounter/5.0f) * powerBarMesh->getGeomPos().x;

					//powerBarTrans.getPos().x += fireCounter /100.0f; // This value has has to be 20 times the dividing value as the scale extends both ways not just in a positive direction
					//powerBarTrans.getScale().x += fireCounter/5.0f; // Update the scale based on the fireCounter value

					//############################### CODE FOR POWER BAR WILL GO HERE ########################

					// SET DIRECTION BASED ON CHASE CAM ANGLE
					// If camera angle is between 0 and 90
					if (p.chaseCamAngle >= 0 && p.chaseCamAngle < 1.5708)
					{
						// x = -sin(theta), z = cos(theta)
						p.direction = normalize(vec3(-sin(p.chaseCamAngle), 0.0, cos(p.chaseCamAngle)));
					}
					// If camera angle is between 90 and 180
					else if (p.chaseCamAngle > 1.5709 && p.chaseCamAngle < 3.14159)
					{
						// x = -cos(theta - 90), z = -sin(theta - 90)
						p.direction = normalize(vec3(-cos(p.chaseCamAngle - 1.5708), 0.0, -sin(p.chaseCamAngle - 1.5708)));
					}
					// If camera angle is between 180 and 270
					else if (p.chaseCamAngle > 3.1416 && p.chaseCamAngle < 4.71239)
					{
						// x = sin(theta - 180), z = -cos(theta - 180)
						p.direction = normalize(vec3(sin(p.chaseCamAngle - 3.1416), 0.0, -cos(p.chaseCamAngle - 3.1416)));
					}
					// If camera angle is anything else
					else if (p.chaseCamAngle > 4.724 && p.chaseCamAngle <= 6.28319)
					{
						// x = cos(theta - 270), z = sin(theta- 270)
						p.direction = normalize(vec3(cos(p.chaseCamAngle - 4.71239), 0.0, sin(p.chaseCamAngle - 4.71239)));
					}
					p.firePressed = true;
				}
			}			
		}
		// When Fire is realesed
		if (!glfwGetKey(window, p.fireButtton)) 
		{
			// Only work if fire button was just released
			if (p.firePressed)
			{
				// Power measure accumulated by holding space is impulse magnitude
				// Normal of impulse is direction
				physicsSystem.Fire(p, p.power);
				// Reset fire power counter
				p.power = 0;
				// And we're off! 
				p.isMoving = true;



				// M - update power bar hud stuff here (invoke UI class method)
				//repeat until fireCounter is reset to 0
	// M - This essentially blocks all other code!
		/*		while (fireCounter > 0.0)
				{
					//This just inverts the increasing in size and positions done before when P was pressed
					//powerBarTrans.getPos().x += (fireCounter / 5.0f) * powerBarMesh->getGeomPos().x;
					//powerBarTrans.getPos().x -= fireCounter / 100.0f;
					//powerBarTrans.getScale().x -= fireCounter / 5.0f;
					//Decrease fireCounter until reaches 0
					fireCounter -= 0.5;
				} */

				// Increment stroke counter by one
				strokeCounter += 1;
				// Call update stroke mesh in UI.cpp to check if user is out of strokes
				isUserOutOfStrokes = uiMgr.updateStrokeMesh(strokeCounter);

				// Flip
				p.firePressed = false;
			}
		} // End if (p is released)

		// Input loop complete; increase thisPlayer counter
		thisPlayer++;
	}
}

// Update positions
void gameScene::Update(GLFWwindow* window)
{
	if (players[0].transform.getPos().y < -100.0f)
		onLevel2 = true;

	if (onLevel2)
	{
		if (players[0].transform.getPos().y > 50.0f)
			players[0].transform.getPos().x = players[0].transform.getPos().z = 0.0f;
	}
	// Spatial partitioning
	// TODO Consider using threads to update current tiles
	//int tileTracker = 0;
	// Check which tile player is on (do this every n frames, not each tick)
	// TODO - improve performance (even if set at start of alg tiles list, 
	// this will continue to look through each tile against both players)
	// escape bools 
	// In every tile
	if (onLevel2)
	{
		int tileTracker = 0;
		for (auto &t : level2algTiles)
		{
			// For every player
			for (auto &p : players)
			{
				// Is this player on this tile?
				if (t->isPlayerOnTile(p.transform.getPos()))
				{
					// Update player's personal current tile property
					p.currentTile = tileTracker;
					cout << "player on tile: " << p.currentTile << endl;
				}
			}
			// Increase the tile tracker counter
			tileTracker++;
		}
	}
	else
	{
		int tileTracker = 0;
		for (auto &t : algTiles)
		{
			// For every player
			for (auto &p : players)
			{
				// Is this player on this tile?
				if (t->isPlayerOnTile(p.transform.getPos()))
				{
					// Update player's personal current tile property
					p.currentTile = tileTracker;
				}
			}
			// Increase the tile tracker counter
			tileTracker++;
		}
	}


	// Free cam stuff
	static double ratio_width = quarter_pi<float>() / 1600.0;
	static double ratio_height = (quarter_pi<float>() * (1600 / 900)) / static_cast<float>(1600);
	double current_x, current_y;
	glfwGetCursorPos(window, &current_x, &current_y);
	// Calc delta
	double delta_x = current_x - cursor_x;
	double delta_y = current_y - cursor_y;
	// Multiply deltas by ratios
	delta_x *= ratio_width;
	delta_y *= ratio_height * -1; // -1 to invert on y axis
								  // Rotate camera by delta
	windowMgr::getInstance()->freeCam->rotate(delta_x, delta_y);
	windowMgr::getInstance()->freeCam->update(0.001);
	// Update cursor pos
	cursor_x = current_x;
	cursor_y = current_y;

	// Update chase cams
	if (numPlayers == 1)
	{
		windowMgr::getInstance()->chaseCams[0]->update(0.00001);
		windowMgr::getInstance()->chaseCams[0]->move(players[0].transform.getPos(), players[0].transform.getRot());
	}
	else if (numPlayers == 2)
	{
		windowMgr::getInstance()->chaseCams[0]->update(0.00001);
		windowMgr::getInstance()->chaseCams[0]->move(players[0].transform.getPos(), players[0].transform.getRot());

		windowMgr::getInstance()->chaseCams[1]->update(0.00001);
		windowMgr::getInstance()->chaseCams[1]->move(players[1].transform.getPos(), players[1].transform.getRot());
	}


	// Update hud target camera
	windowMgr::getInstance()->HUDtargetCam->update(0.00001);

	// Update pause target camera
	windowMgr::getInstance()->PAUSEtargetCam->update(0.00001);


	// Calculate dt
	double newTime = glfwGetTime();
	double frameTime = newTime - currentTime;
	currentTime = newTime;

	accumulator += frameTime;
	// Calculate fps
	double fps = 1.0 / frameTime;
	if (accumulator > 1.0f)
		//cout << "FPS:" << fps << endl;
	

	if (onLevel2)
	{
		// Update each player
		for (auto &p : players)
		{
			// Only apply physics if it's moving
			if (p.isMoving)
			{
				// Special case for on a ramp tile (ignored for now)
				//if (algTiles.at(p.currentTile)->id == 7)
				//{
				/* Instantiate in order to call member functions
				UpRampDown ramp;
				// Set deets
				ramp.SetCoords(algTiles.at(p1CurrentTile)->GetThisCoords());
				// Raise it a bit
				ramp.thisCoords.y += 1.8;
				// Find floor level at this point on ramp
				float floorPos = ramp.SetPlayerHeight(players[0]);
				// Work out whether to apply gravity or not (is player on the floor/in air)
				physicsSystem.ApplyGravity(players[0], floorPos);
				// Add impulse which is ramp resistance; only applied if on ground
				if (physicsSystem.gravFlag == 0)
				{
				// These numbers need tweaking
				physicsSystem.epsilon = 0.0001f;
				players[0] = physicsSystem.RampResistance(players[0], -1.0f);
				}
				// Perform physics step
				if (accumulator >= dt)
				{
				// Update position
				players[0] = physicsSystem.Integrate(players[0], dt, floorPos);
				accumulator -= dt;
				}*/
				//}

				// Ensure correct slowdown/stop margin
				physicsSystem.epsilon = 0.5f;
				// Work out whether to apply gravity or not (is player on the floor/in air)
				physicsSystem.ApplyGravity(p, level2algTiles.at(p.currentTile)->thisCoords.y + 1.0f); // 1 is floor gap
																								// If time to perform another physics step																						 // Perform physics step	
				if (accumulator >= dt)
				{
					// Update position
					physicsSystem.Integrate(p, dt, level2algTiles.at(p.currentTile)->thisCoords.y + 1);
					accumulator -= dt;
				}
			}
			// Update p1 arrow mesh position to follow player
			p.arrowTransform.getPos() = vec3(p.transform.getPos().x, p.transform.getPos().y - 1.6, p.transform.getPos().z);
		}
	}


	else
	{
		// Update each player
		for (auto &p : players)
		{
			// Only apply physics if it's moving
			if (p.isMoving)
			{
				// Special case for on a ramp tile (ignored for now)
				//if (algTiles.at(p.currentTile)->id == 7)
				//{
				/* Instantiate in order to call member functions
				UpRampDown ramp;
				// Set deets
				ramp.SetCoords(algTiles.at(p1CurrentTile)->GetThisCoords());
				// Raise it a bit
				ramp.thisCoords.y += 1.8;
				// Find floor level at this point on ramp
				float floorPos = ramp.SetPlayerHeight(players[0]);
				// Work out whether to apply gravity or not (is player on the floor/in air)
				physicsSystem.ApplyGravity(players[0], floorPos);
				// Add impulse which is ramp resistance; only applied if on ground
				if (physicsSystem.gravFlag == 0)
				{
				// These numbers need tweaking
				physicsSystem.epsilon = 0.0001f;
				players[0] = physicsSystem.RampResistance(players[0], -1.0f);
				}
				// Perform physics step
				if (accumulator >= dt)
				{
				// Update position
				players[0] = physicsSystem.Integrate(players[0], dt, floorPos);
				accumulator -= dt;
				}*/
				//}

				// Ensure correct slowdown/stop margin
				physicsSystem.epsilon = 0.5f;
				// Work out whether to apply gravity or not (is player on the floor/in air)
				physicsSystem.ApplyGravity(p, algTiles.at(p.currentTile)->thisCoords.y + 1.0f); // 1 is floor gap
																								// If time to perform another physics step																						 // Perform physics step	
				if (accumulator >= dt)
				{
					// Update position
					physicsSystem.Integrate(p, dt, algTiles.at(p.currentTile)->thisCoords.y + 1);
					accumulator -= dt;
				}
			}
			// Update p1 arrow mesh position to follow player
			p.arrowTransform.getPos() = vec3(p.transform.getPos().x, p.transform.getPos().y - 1.6, p.transform.getPos().z);
		}
	}


	
	





	// HUD TIMER RELATED INFORMATION
	// If the time been in scene is equal to zero then
	if (timeBeenInScene == 0)
	{
		// Get the amount of time been in scene
		timeBeenInScene = glfwGetTime();
	}
	// Increment time Counter - used for splash screen
	timeCounter++;

	// If the continue button is pressed 
	if (continuePressed)
	{
		// If the time taken to reach this method is zero then
		if (timeToThisMethod == 0)
		{
			// Get the time to this method
			timeToThisMethod = glfwGetTime();
		}

		// If at least a second has passed
		if (timeSinceContinueWasPressed < glfwGetTime() - timeToThisMethod)
		{
			isUserOutOfTime = uiMgr.updateTimer(timeSinceContinueWasPressed, timeToThisMethod, holeTimer);
		}
	}
}

// Tracks current tile player is on 
// Calls collision checking code of tile player is on
void gameScene::Collisions()
{
	if (onLevel2)
	{
		// Check collisions for the tile each player is on only
		for (auto &p : players)
		{
			level2algTiles.at(p.currentTile)->CheckCollisions(p);
		}
	}
	else
	{
		// Check collisions for the tile each player is on only
		for (auto &p : players)
		{
			algTiles.at(p.currentTile)->CheckCollisions(p);
		}
	}


	// TODO Determine if this can be done more cheapply, and less hardcoded
	// If players are on the same tile, check for collisions with each other
	if (numPlayers == 2)
	{
		if (players[0].currentTile == players[1].currentTile)
		{
			// Find distance between players
			vec3 distance = abs(players[0].transform.getPos() - players[1].transform.getPos());
			float magnitude = (distance.x * distance.x) + (distance.y * distance.y) + (distance.z * distance.z);
			// If less than two radii apart
			if (magnitude < players[0].radius * 2)
			{
				// First normalize the distance vector; the collision normal
				vec3 collisionNormal = players[0].transform.getPos() - players[1].transform.getPos();
				collisionNormal = normalize(collisionNormal);
				// Find the length of the component of each movement vector on collision normal
				float a1 = dot(players[0].velocity, collisionNormal);
				float a2 = dot(players[1].velocity, collisionNormal);
				// Using optimized version according to https://www.gamasutra.com/view/feature/131424/pool_hall_lessons_fast_accurate_.php?page=3
				float optimizedP = (2.0 * (a1 - a2)) / (players[0].mass + players[1].mass);
				// Calculate new veloctiy for each player
				vec3 v1New = players[0].velocity - optimizedP * players[1].mass * collisionNormal;
				vec3 v2New = players[1].velocity + optimizedP * players[0].mass * collisionNormal;
				// Set players velocity to 0, then assign new velocities
				players[0].velocity = v1New;
				players[1].velocity = v2New;
			}

		}

	}

} // end collisions function

// Draw stuff
void gameScene::Render(GLFWwindow* window)
{
	// Check whether to render for 1 or 2 players
	if (numPlayers == 1)
	{
		glViewport(0, 0, 1600, 900); // TODO - remove hardcoded values, use winMgr members
	}
	else if (numPlayers == 2)
	{
		// Player 1 has left hand side of screen
		glViewport(0, 0, 800, 900);
	}


	// Calculate mvp matrix
	mat4 mvp;
	// If camera type is free camera then
	if (cameraType == 0)
	{
		mvp = windowMgr::getInstance()->freeCam->get_Projection() * windowMgr::getInstance()->freeCam->get_View();
	}
	// Else camera type is chase camera
	else if (cameraType == 1)
	{
		mvp = windowMgr::getInstance()->chaseCams[0]->get_Projection() * windowMgr::getInstance()->chaseCams[0]->get_View();
	}
	// Else if camera type is pause camera
	else if (cameraType == 2)
	{
		mvp = windowMgr::getInstance()->PAUSEtargetCam->get_Projection() * windowMgr::getInstance()->PAUSEtargetCam->get_View();
	}

	// Generat vp of HUD target camera
	glm::mat4 hudVP = windowMgr::getInstance()->HUDtargetCam->get_Projection() * windowMgr::getInstance()->HUDtargetCam->get_View();

	// HUD RENDERING STARTING - DONT NOT ENTER ANY OTHER CODE NOT RELATED TO HUD BETWEEN THIS AND THE END HUD COMMENT
	// Set depth range to near to allow for HUD elements to be rendered and drawn
	glDepthRange(0, 0.01);

	// If timeCounter - which is a variable that increases as of when the scene has loaded is less than the time been in scene + a value that can be changed then
	if (timeCounter < timeBeenInScene + 300)
	{
		// Display splash screen
		windowMgr::getInstance()->meshes.at(19)->thisTexture.Bind(0);
		windowMgr::getInstance()->textureShader->Update(windowMgr::getInstance()->texShaderTransform, hudVP);
		windowMgr::getInstance()->meshes.at(19)->Draw();
	}

	// If user has completed the hole or if the continue button hasnt been pressed of if the user has run out of time or if the user has run out of strokes
	if (players[0].ballInHole || !continuePressed || isUserOutOfTime || isUserOutOfStrokes)
	{
		// For loop which goes through all the information elements and binds, updates and draws them.
		for (int i = 10; i < 14; i++)
		{
			windowMgr::getInstance()->meshes.at(i)->thisTexture.Bind(0);
			windowMgr::getInstance()->textureShader->Update(windowMgr::getInstance()->texShaderTransform, hudVP);
			windowMgr::getInstance()->meshes.at(i)->Draw();
		}
	}
	// Else then display remaining gameplay HUDs
	else
	{
		// For loop which goes through all 10 HUD elements and binds, updates anbd draws the meshes.
		for (int i = 0; i < 10; i++)
		{
			windowMgr::getInstance()->meshes.at(i)->thisTexture.Bind(0);
			windowMgr::getInstance()->textureShader->Update(windowMgr::getInstance()->texShaderTransform, hudVP);
			windowMgr::getInstance()->meshes.at(i)->Draw();
		}
	}

	// Reset the depth range to allow for objects at a distance to be rendered
	glDepthRange(0.01, 1.0);
	// HUD RENDERING ENDED - THANK YOU AND HAVE A NICE DAY

	// Skybox 
	windowMgr::getInstance()->skyboxShader->Bind();
	windowMgr::getInstance()->skyboxShader->Update(windowMgr::getInstance()->texShaderTransform, mvp);
	windowMgr::getInstance()->skyboxMesh->Draw();
	// Bind texture shader
	windowMgr::getInstance()->textureShader->Bind();

	if (onLevel2)
	{
		// DRAW all level tiles
		for (auto &t : level2tiles)
		{
			t.drawTile(windowMgr::getInstance()->textureShader, mvp);
		}
		// DRAW all scenery tiles
		for (auto &t : level2sceneryTiles)
		{
			t.drawTile(windowMgr::getInstance()->textureShader, mvp);
		}
	}
	else
	{
		// DRAW all level tiles
		for (auto &t : tiles)
		{
			t.drawTile(windowMgr::getInstance()->textureShader, mvp);
		}
		// DRAW all scenery tiles
		for (auto &t : sceneryTiles)
		{
			t.drawTile(windowMgr::getInstance()->textureShader, mvp);
		}
	}


	// If there are two players...
	if (numPlayers == 2)
	{
		// Render player 2
		windowMgr::getInstance()->textures["playerBlueTexture"]->Bind(0);
		windowMgr::getInstance()->textureShader->Update(players[1].transform, mvp);
		windowMgr::getInstance()->player1Mesh->Draw();
		// Putting the above code below the arrow rendering gives odd behaviour of arrow
		// Perhaps due to reuse of texture being rebound?
	}


	// Render player 1
	windowMgr::getInstance()->textures["playerRedTexture"]->Bind(0);
	windowMgr::getInstance()->textureShader->Update(players[0].transform, mvp);
	windowMgr::getInstance()->player2Mesh->Draw();


	// Render player 1 arrow
	windowMgr::getInstance()->p1ArrowMesh->thisTexture.Bind(0);
	windowMgr::getInstance()->textureShader->Update(players[0].arrowTransform, mvp);
	// Rotate the arrow on the Y axis by - camera angle minus 90 degrees
	players[0].arrowTransform.setRot(glm::vec3(0, -players[0].chaseCamAngle - 1.5708, 0));

	// If ball is not moving draw arrow (ie dont draw arrow when ball moving as not needed)
	if (!players[0].isMoving) // was !golfBallMoving
	{
		// Draw the arrow
		windowMgr::getInstance()->p1ArrowMesh->Draw();
	}

	// Update texture shader for free cam
	windowMgr::getInstance()->textureShader->Update(windowMgr::getInstance()->texShaderTransform, (windowMgr::getInstance()->freeCam->get_Projection() * windowMgr::getInstance()->freeCam->get_View()));


	// ################### PLAYER 2 SCREEN ################### //
	if (numPlayers == 2)
	{
		// Player 2 has the right hand vertical half of the screen
		glViewport(800, 0, 800, 900);

		// model view projection matrix for p2 cam
		mat4 mvp2;

		// Render player 2's chase camera
		mvp2 = windowMgr::getInstance()->chaseCams[1]->get_Projection() * windowMgr::getInstance()->chaseCams[1]->get_View();

		// Skybox 
		windowMgr::getInstance()->skyboxShader->Bind();
		windowMgr::getInstance()->skyboxShader->Update(windowMgr::getInstance()->texShaderTransform, mvp2);
		windowMgr::getInstance()->skyboxMesh->Draw();

		// Bind texture shader
		windowMgr::getInstance()->textureShader->Bind();
		// DRAW all level tiles
		for (auto &t : tiles)
		{
			t.drawTile(windowMgr::getInstance()->textureShader, mvp2);
		}
		// DRAW all scenery tiles
		for (auto &t : sceneryTiles)
		{
			t.drawTile(windowMgr::getInstance()->textureShader, mvp2);
		}


		// Render player 1
		windowMgr::getInstance()->textures["playerRedTexture"]->Bind(0);
		windowMgr::getInstance()->textureShader->Update(players[0].transform, mvp2);
		windowMgr::getInstance()->player1Mesh->Draw();
		// Can't seem to draw p1 arrow... though it seems fitting that you can't
		// see the other player's direction


		// Render player 2
		windowMgr::getInstance()->textures["playerBlueTexture"]->Bind(0);
		windowMgr::getInstance()->textureShader->Update(players[1].transform, mvp2);
		windowMgr::getInstance()->player2Mesh->Draw();

		// Render player 2 arrow
		windowMgr::getInstance()->p2ArrowMesh->thisTexture.Bind(0);
		windowMgr::getInstance()->textureShader->Update(players[1].arrowTransform, mvp2);
		players[1].arrowTransform.setRot(glm::vec3(0, -players[1].chaseCamAngle - 1.5708, 0));
		// Only draw if player 2 is still
		if (!players[1].isMoving)
		{
			windowMgr::getInstance()->p2ArrowMesh->Draw();
		}
	}



	// Fully reset depth range for next frame - REQUIRED
	glDepthRange(0, 1.0);

	glfwSwapBuffers(window);
	glfwPollEvents();
}