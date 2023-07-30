#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachGoal = false;

	//Make a rect for all its parts
	FloatRect detectionZone = character.getPosition();

	//Make a FloatRect to test each block
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	//Build a zone arund thomas to detect colissions
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	//Make sure we don't test position lower than 0
	//or higher than the end of the array
	if (startX < 0)startX = 0;
	if (startX < 0)startY = 0;
	if (endX >= m_LM.getLevelSize().x)endX = m_LM.getLevelSize().x;
	if (endY >= m_LM.getLevelSize().y)endY = m_LM.getLevelSize().y;
	
	//Has the player fallen out of map?
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

	if (!character.getPosition().intersects(level))
	{
		//respawn the character
		character.spawn(m_LM.getStartPosition(), GRAVITY);
	}
	//Loop through all the blocks
	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			//Initialize the starting position of the curent block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			//Has the character burnet or drawned?
			//Use head as this allows him to sink a bit
			if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					character.spawn(m_LM.getStartPosition(), GRAVITY);

					//Which sound should be played?
					if (m_ArrayLevel[y][x] == 2) //Fire,
					{
						//Play a sound
					}
					else
					{
						//Play a sound
					}
				}
			}
			if (m_ArrayLevel[y][x] == 1)
			{
				//Is character colloiding with regular block
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					character.stopLeft(block.left);
				}
				if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
				
			}
			if (m_ArrayLevel[y][x] == 4)
			{
				//character reached his goal
				reachGoal = true;
			}
		}
			
		//Collision detection from particle effects
		
		//Has character reached goal
		
	}
	return reachGoal;
}