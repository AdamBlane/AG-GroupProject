#include <random>
#include "glew_glfw.h"
#include "GameLogicMgr.h"
#include "windowMgr.h"

// Setup start of game HUD
void GameLogicMgr::Setup(int numPlayers, int diff)
{
	// Set number of players this game
	players = numPlayers;
	gameEnded = false;

	// Set this level time limit in seconds
	switch (diff)
	{
	// Easy 
	case 8:
		// decide easy time limit
		timeLimit = 90;
		break;
	// Medium
	case 12:
		// decide med time limit
		timeLimit = 120;
		break;
	case 16:
		// decide hard time limit
		timeLimit = 180;
		break;
	default: 
		// decide default behaviour
		timeLimit = 120;
		break;
	}

	// Invoke UImgr to perform its setup
	if (players == 1)
	{
		uiMgr.p1Setup();
	}
	else if (players == 2)
	{
		uiMgr.p2Setup();
	
	}


}

// Start tracking time for this game
void GameLogicMgr::StartGameClock()
{
	// This marks the start time
	startTime = glfwGetTime();
}

// Called after a player fired a shot
// Checks against stroke limit if this is 1 player mode
// Updates UI to refelct increase to strokeCounter
void GameLogicMgr::PlayerFired(int playerIndex, Player &player)
{
	// Only allows for 2 digits of stroke count
	if (player.strokeCounter < 100)
	{
		// Is this a 1 player game? 
		if (players == 1)
		{
			// If so, need to check for fail condition (no more shots allowed)
			// TODO

			// Update UI - tell it which player to update for and its stroke value
			uiMgr.UpdateStrokeCounter(playerIndex, player.strokeCounter);
		}
		else if (players == 2)
		{

			// Update UI
			uiMgr.UpdateStrokeCounter(playerIndex, player.strokeCounter);
		}
	}
	

}

// Keep clocks ticking...
void GameLogicMgr::Update()
{
	// Update elapsed timer clock
	// Time from current subtract start time
	lastFrameTime = elapsedTime;
	elapsedTime = glfwGetTime() - startTime;
	
	// Only update the UI every second
	if (elapsedTime > lastFrameTime)
	{
		// TODO - P1 - check if time is up
		if (players == 1 && !gameEnded)
		{
			// Work out how much time is left given this game's time limit
			int timeRemaining = timeLimit - elapsedTime;
			uiMgr.UpdateHUDClock(timeRemaining);
		}
		else if (players == 2 && !gameEnded)
		{
			uiMgr.UpdateWorldClock(elapsedTime);
		}
		
	}
}


// Update power bar
void GameLogicMgr::UpdatePowerBar(Player player)
{
	// Check which player this is
	if (player.id == 1)
	{
		// Update p1 power bar
	}
	else if (player.id == 2)
	{
		// Update p2 power bar
	}
}

// When a player finishes, mark their total time
void GameLogicMgr::SetEndTime(Player &player)
{
	player.totalTime = elapsedTime;
}

// Used in demo (no leaderboard yet)
void GameLogicMgr::PrintPlayerScore(Player player)
{
	// Print score for this player
	switch (player.id)
	{
	case 1:
	{
		if (!p1Finished)
		{
			cout << "##### Player " << player.id << " #####" << endl;
			cout << "Total time: " << player.totalTime << " seconds" << endl;
			cout << "Total strokes: " << player.strokeCounter << endl;
			p1Score = player.totalTime * player.strokeCounter;
			cout << "Final score: " << p1Score << endl;
			// Set bool for this player to finished 
			p1Finished = true;
			if (players == 1)
				cout << "To return to main menu, pause game (P) then hit C!" << endl;
		}
		break;
	}
	case 2:
	{
		if (!p2Finished)
		{
			cout << "##### Player " << player.id << " #####" << endl;
			cout << "Total time: " << player.totalTime << " seconds" << endl;
			cout << "Total strokes: " << player.strokeCounter << endl;
			p2Score = player.totalTime * player.strokeCounter;
			cout << "Final score: " << p2Score << endl;
			// Set bool for this player to finished 
			p2Finished = true;
		}
	}
		break;
	default: cout << "Error in GameLogicMgr::PrintPlayerScore" << endl; break;
	}
	

	// if 2 players and both players finished, compute and print score
	if (p1Finished && p2Finished && !gameEnded)
	{
		if (p1Score > p2Score)
			cout << "Player 2 is the winner!" << endl;
		else if (p2Score > p1Score)
			cout << "Player 1 is the winner!" << endl;
		else if (p1Score == p2Score)
			cout << "Both players draw!" << endl;

		cout << "To return to main menu, pause game (P) then hit C!" << endl;
		gameEnded = true;
	}
	
}

// Randomly choose and assign a power to player
void GameLogicMgr::RandomPowerup(Player &player)
{
	// Pick random number between 1 and number of available pickups 
	default_random_engine rng(random_device{}());
	uniform_int_distribution<int> distribution(1, 2);
	int choice = distribution(rng);
	
	// Enact powerup 
	switch (choice)
	{
	// Player gets big!
	case 1:
	{
		player.transform.getScale() = vec3(0.7);
		player.radius = 0.75;
		player.mass = 1.4;
	}
		break;
	// Player gets small!
	case 2:
	{
		player.transform.getScale() = vec3(0.3);
		player.radius = 0.3;
		player.mass = 1.0;
	}
		break;
	
	default: break;
	}
}