#include "Engine.h"

void Engine::loadLevel()
{
	m_Playing = false;

	//Delete the previous allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[]m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	//Load the next 2D array with the map for the level
	//And repoppulate the vertex array
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);
	m_TimeRemaining = m_LM.getTimeLimit();
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);
	m_NewLevelRequired = false;
}


