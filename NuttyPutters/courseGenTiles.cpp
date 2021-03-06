
#include "courseGenTiles.h"
#include "windowMgr.h"
// THIS file includes collision check functions for each tile type
// These tiles are used in the algorithm to generate a course


// Set coords of this tile
void BaseTile::SetCoords(vec3 coords) {	thisCoords = coords; }

// Set next coords of this tile
void BaseTile::SetNextCoords(vec3 coords) {	nextCoords = coords; }

// Getter of next coords
vec3 BaseTile::GetNextCoords() { return nextCoords; }

// Getter of this coords
vec3 BaseTile::GetThisCoords() { return thisCoords; }

bool BaseTile::SphereRectCollision(Player player, vec3 rectCenter, vec3 rectSize)
{
	float sphereXDistance = abs(player.transform.getPos().x - rectCenter.x);
	float sphereYDistance = abs(player.transform.getPos().y - rectCenter.y);
	float sphereZDistance = abs(player.transform.getPos().z - rectCenter.z);

	if (sphereXDistance >= (rectSize.x + player.radius)) { return false; }
	if (sphereYDistance >= (rectSize.y + player.radius)) { return false; }
	if (sphereZDistance >= (rectSize.z + player.radius)) { return false; }

	if (sphereXDistance < (rectSize.x))
	{
		return true;
	}
	if (sphereYDistance < (rectSize.y))
	{
		return true;
	}
	if (sphereZDistance < (rectSize.z))
	{
		return true;
	}

	float cornerDistance_sq = ((sphereXDistance - rectSize.x) * (sphereXDistance - rectSize.x)) +
		((sphereYDistance - rectSize.y) * (sphereYDistance - rectSize.y) +
		((sphereYDistance - rectSize.z) * (sphereYDistance - rectSize.z)));

	return (cornerDistance_sq < (player.radius * player.radius));
}

// This is called on each tile; spatial partitioning method, returns true if player is on this tile
bool BaseTile::isPlayerOnTile(Player &player)
{
	// Look at player height first (could be below tile)
	if (player.transform.getPos().y >= floorLevel + 0.5f)
	{
		//player.floorLevel = 0.5f + player.radius;
		// Match on x first
		if (player.transform.getPos().x > thisCoords.x - 5 && player.transform.getPos().x < thisCoords.x + 5)
		{
			// Then on z
			if (player.transform.getPos().z > thisCoords.z - 5 && player.transform.getPos().z < thisCoords.z + 5)
			{
				// Player is on this tile
				return true;
			}
		}
	}
	//else
	//	player.floorLevel = -490.0f;

	return false;
}

// Collision check for start tile
void StartTile::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Check on X axis - boundaries either side
	if (player.transform.getPos().x > thisCoords.x + (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x + (4 - player.radius);
		// Hit boundary, revert x axis
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	else if (player.transform.getPos().x < thisCoords.x - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x - (4 - player.radius);
		// Hit boundary, reflect on x
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check on z axis - just one boundary
	if (player.transform.getPos().z < thisCoords.z - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z - (4 - player.radius);
		// hit, revert z axis
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
}

// Collision check for straight vertical tile
void StraightTile_V::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Check on X axis - boundaries either side
	if (player.transform.getPos().x > thisCoords.x + (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x + (4 - player.radius);
		// Hit boundary, revert x axis
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	else if (player.transform.getPos().x < thisCoords.x - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x - (4 - player.radius);
		// Hit boundary, revert x axis
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");

	}

}

// Collision check for straight horizontal tile
void StraightTile_H::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Check on X axis - boundaries either side
	if (player.transform.getPos().z > thisCoords.z + (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z + (4 - player.radius);
		// Hit boundary, revert x axis
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	else if (player.transform.getPos().z < thisCoords.z - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z - (4 - player.radius);
		// Hit boundary, revert x axis
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}

}

// Collision check for bottom left corner tile
void CornerTile_BL::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Check on X axis - left boundary
	if (player.transform.getPos().x < thisCoords.x - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x - (4 - player.radius);
		// hit left boundary
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check x axis - left side of cube corner boundary
	else if (player.transform.getPos().x > thisCoords.x + (4 - player.radius) && // Far enough to the right on x to hit square
		player.transform.getPos().z > thisCoords.z - 5 && // Between upper limit of tile/square
		player.transform.getPos().z < thisCoords.z - 4) // and lower limit of square
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x + (4 - player.radius);
		// Hit going right, reflect on x
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower boundary
	if (player.transform.getPos().z > thisCoords.z + (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z + (4 - player.radius);
		// hit middle
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower side of cube corner boundary
	else if (player.transform.getPos().z < thisCoords.z - (4 - player.radius) &&
		player.transform.getPos().x > thisCoords.x + 4 &&
		player.transform.getPos().x < thisCoords.x + 5)
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z - (4 - player.radius);
		// Hit going up, reflect on z
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}

}

// Collision check for bottom right corner tile
void CornerTile_BR::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Axis seems odd since tile has been rotated
	// Check on X axis - left boundary
	if (player.transform.getPos().x > thisCoords.x + (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x + (4 - player.radius);
		// hit left boundary
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check x axis - left side of cube corner boundary
	else if (player.transform.getPos().x < thisCoords.x - (4 - player.radius) && // Far enough to the right on x to hit square
		player.transform.getPos().z > thisCoords.z - 5 && // Between upper limit of tile/square
		player.transform.getPos().z < thisCoords.z - 4) // and lower limit of square
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x - (4 - player.radius);
		// Hit going right, reflect on x
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower boundary
	if (player.transform.getPos().z  > thisCoords.z + (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z + (4 - player.radius);
		// hit middle
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower side of cube corner boundary
	else if (player.transform.getPos().z < thisCoords.z - (4 - player.radius) &&
		player.transform.getPos().x > thisCoords.x - 5 &&
		player.transform.getPos().x < thisCoords.x - 4)
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z - (4 - player.radius);
		// Hit going up, reflect on z
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}

}

// Collision check for top left corner tile
void CornerTile_TL::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Axis seems odd since tile has been rotated
	// Check on X axis - left boundary
	if (player.transform.getPos().x < thisCoords.x - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x - (4 - player.radius);
		// hit left boundary
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check x axis - left side of cube corner boundary
	else if (player.transform.getPos().x > thisCoords.x + (4 - player.radius) && // Far enough to the right on x to hit square
		player.transform.getPos().z > thisCoords.z + 4 && // Between upper limit of tile/square
		player.transform.getPos().z < thisCoords.z + 5) // and lower limit of square
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x + (4 - player.radius);
		// Hit going right, reflect on x
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower boundary
	if (player.transform.getPos().z < thisCoords.z - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z - (4 - player.radius);
		// hit middle
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower side of cube corner boundary
	else if (player.transform.getPos().z > thisCoords.z + (4 - player.radius) &&
		player.transform.getPos().x > thisCoords.x + 4 &&
		player.transform.getPos().x < thisCoords.x + 5)
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z + (4 - player.radius);
		// Hit going up, reflect on z
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}

}

// Collision check for top right corner tile
void CornerTile_TR::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Reset player floor level in case just came from gap/bridge tile
	if (player.transform.getPos().y >= 0.5f)
		player.floorLevel = 0.5f + player.radius;
	// Check on X axis - right boundary
	if (player.transform.getPos().x > thisCoords.x + (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x + (4 - player.radius);
		// hit left boundary
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check x axis - left side of cube corner boundary
	else if (player.transform.getPos().x < thisCoords.x - (4 - player.radius) && // Far enough to the right on x to hit square
		player.transform.getPos().z > thisCoords.z + 4 && // Between upper limit of tile/square
		player.transform.getPos().z < thisCoords.z + 5) // and lower limit of square
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().x = thisCoords.x - (4 - player.radius);
		// Hit going right, reflect on x
		player.velocity.x = -player.velocity.x;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower boundary
	if (player.transform.getPos().z < thisCoords.z - (4 - player.radius))
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z - (4 - player.radius);
		// hit middle
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}
	// Check z axis - lower side of cube corner boundary
	else if (player.transform.getPos().z > thisCoords.z + (4 - player.radius) &&
		player.transform.getPos().x > thisCoords.x - 5 &&
		player.transform.getPos().x < thisCoords.x - 4)
	{
		// Move away from boundary so as not to retrigger this
		player.transform.getPos().z = thisCoords.z + (4 - player.radius);
		// Hit going up, reflect on z
		player.velocity.z = -player.velocity.z;
		// Play SFX
		windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
	}

}

// Ramp - set y position of player on ramp accordingly
float UpRampDown::SetPlayerHeight(Player player)
{
	// First find how much to increment y for every 1 in z
	float yInc = thisCoords.y / (size / 2);
	// Then find distance travelled along tile
	float difference = player.transform.getPos().z - thisCoords.z;
	// Make relative to tile coords by adding half size
	float y = yInc * (difference + (size / 2));
	// We now have the exact y position to match in z, so player is level on floor
	// Updating player position manually places him there
	//player.transform.getPos().y = y + 1;

	// This is also dy, which needs to be scaled by dt to add an impulse in y direction
	// this is the alternate; forcibly pushing the player upwards to appear level
	return y + 1; // was return player
}
// Ramp - set y position of player on ramp accordingly
float DownRampDown::SetPlayerHeight(Player player)
{
	// First find how much to increment y for every 1 in z
	float yInc = thisCoords.y / (size / 2);
	// Then find distance travelled along tile
	float difference = player.transform.getPos().z - thisCoords.z;
	// Make relative to tile coords by adding half size
	float y = yInc * (difference - (size / 2));
	// We now have the exact y position to match in z, so player is level on floor
	// Updating player position manually places him there
	//player.transform.getPos().y = y + 1;

	// This is also dy, which needs to be scaled by dt to add an impulse in y direction
	// this is the alternate; forcibly pushing the player upwards to appear level
	return y + 1; // was return player
}

void Bridge_V::CheckCollisions(Player &player)
{
	// If player isn't on bridge
	if (player.transform.getPos().x > thisCoords.x + (0.75 + (player.radius / 3)) ||
		player.transform.getPos().x < thisCoords.x - (0.75 - (player.radius / 3)))
	{
		// Set floor level to bottom of skybox
		player.floorLevel = -490.0f; 
	}
	else
		// Otherwise, floor is that of bridge (0.5 is thickness)
		player.floorLevel = 0.5f + player.radius;
}
// Affect floor level when player is on this tile
void GapTile::CheckCollisions(Player &player)
{
	
	vec3 boxPos = vec3(thisCoords.x, thisCoords.y + 0.5f, thisCoords.z);
	vec3 boxSize = vec3(1.5f - (player.radius / 3), 0.5f, 1.5f - (player.radius / 3));

	bool intersect = SphereRectCollision(player, boxPos, boxSize);

	if (intersect)
	{
		// On tile, set floor level accordingly
		player.floorLevel = 0.0f + player.radius;
	}
	else
	{
		// Off tile, set floor to skybox
 		player.floorLevel = -490.0f;
	}
}

// Collisions check for end tile
void EndTile::CheckCollisions(Player &player)
{
	// Reset player floor level in case just came from gap/bridge tile
	//if (player.transform.getPos().y >= 0.5f)
	//	player.floorLevel = 0.5f + player.radius;
	// Based on velocity
	if (outDir.going_up)
	{
		// Check on X axis - boundaries either side
		if (player.transform.getPos().x > thisCoords.x + (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().x = thisCoords.x + (4 - player.radius);
			// Hit boundary, revert x axis
			player.velocity.x = -player.velocity.x;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		else if (player.transform.getPos().x < thisCoords.x - (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().x = thisCoords.x - (4 - player.radius);
			// Hit boundary, revert x axis
			player.velocity.x = -player.velocity.x;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		// Check on z axis - just one boundary
		if (player.transform.getPos().z < thisCoords.z - (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().z = thisCoords.z - (4 - player.radius);
			// hit, revert z axis
			player.velocity.z = -player.velocity.z;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
	}
	else if (outDir.going_down)
	{
		// Check on X axis - boundaries either side
		if (player.transform.getPos().x > thisCoords.x + (4 - player.radius)) 
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().x = thisCoords.x + (4 - player.radius);
			// Hit boundary, revert x axis
			player.velocity.x = -player.velocity.x;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		else if (player.transform.getPos().x < thisCoords.x - (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().x = thisCoords.x - (4 - player.radius);
			// Hit boundary, revert x axis
			player.velocity.x = -player.velocity.x;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		// Check on z axis - just one boundary
		if (player.transform.getPos().z > thisCoords.z + (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().z = thisCoords.z + (4 - player.radius);
			// hit, revert z axis
			player.velocity.z = -player.velocity.z;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
	}
	else if (outDir.going_left)
	{
		// Check on z axis - boundaries either side
		if (player.transform.getPos().z < thisCoords.z - (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().z = thisCoords.z - (4 - player.radius);
			// hit, revert z axis
			player.velocity.z = -player.velocity.z;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		else if (player.transform.getPos().z > thisCoords.z + (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().z = thisCoords.z + (4 - player.radius);
			// hit, revert z axis
			player.velocity.z = -player.velocity.z;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		// Check on x - boundary to left
		if (player.transform.getPos().x < thisCoords.x - (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().x = thisCoords.x - (4 - player.radius);
			// hit, revert on x
			player.velocity.x = -player.velocity.x;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
	}
	else if (outDir.going_right)
	{
		// Check on z axis - boundaries either side
		if (player.transform.getPos().z < thisCoords.z - (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().z = thisCoords.z - (4 - player.radius);
			// hit, revert on z
			player.velocity.z = -player.velocity.z;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		else if (player.transform.getPos().z > thisCoords.z + (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().z = thisCoords.z + (4 - player.radius);
			// hit, revert on z
			player.velocity.z = -player.velocity.z;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
		// Check on x - boundary to right
		if (player.transform.getPos().x > thisCoords.x + (4 - player.radius))
		{
			// Move away from boundary so as not to retrigger this
			player.transform.getPos().x = thisCoords.x + (4 - player.radius);
			// hit, reflect on x
			player.velocity.x = -player.velocity.x;
			// Play SFX
			windowMgr::getInstance()->PlayThisSound("golfBallWoodHit");
		}
	}
	
	
	// Check if over end hole
	if (player.transform.getPos().x > thisCoords.x - 0.75 && player.transform.getPos().x < thisCoords.x + 0.75 &&
		player.transform.getPos().z > thisCoords.z - 0.75 && player.transform.getPos().z < thisCoords.z + 0.75)
	{
		// If not moving so fast, allow to fall into hole
		if (length(player.velocity) < 2.0f)
		{
			// Flip flag
			player.ballInHole = true;
			// Set floor level to bottom of skybox
			player.floorLevel = -490.0f;
		}

	}
	else if (!player.ballInHole)
		// Not ended yet, remain on tile
		player.floorLevel = 0.5f + player.radius;

}