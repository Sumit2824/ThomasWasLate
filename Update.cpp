#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		//These calls to spawn will be moved to a new
		//load level functionn soon
		loadLevel();
	}
	if (m_Playing)
	{
		//Update Thomaas
		m_Thomas.update(dtAsSeconds);

		//Update Bob
		m_Bob.update(dtAsSeconds);

		//Update collision
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			//New level
			m_NewLevelRequired = true;
			m_SM.playReachGoal();
		}
		else
		{
			//Run bob collision detection
			detectCollisions(m_Bob);
		}
		//Let bob and thomas jump on each other
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}
		//Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		//Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}
	//Check if fire sound is played
	vector<Vector2f>::iterator it;

	//Iterate through the vector of vrctor2f objects
	for (it  = m_fireEmitters.begin(); it != m_fireEmitters.end(); it++)
	{
		float posX = (*it).x;
		float posY = (*it).y;

		//Make 500 px rect around the emitter
		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		//Is the player insid elocal rect
		if (m_Thomas.getPosition().intersects(localRect))
		{
			//Play the sound and pass in the location 
			m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());

		}
	}
	


	//set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		//Center full screen around appropriate character
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}

	/*
	 *	Time to update the HUD?
	 * Increment the number of frames since
	 * the last HUD calculation
	*/
	m_FramesSinceLastHUDUpdate++;

	// Update HUD Every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{
		stringstream ssTime;
		stringstream ssLevel;

		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		ssLevel << "Level: " << m_LM.getCurrentlevel();
		m_Hud.setLevel(ssLevel.str());
		m_FramesSinceLastHUDUpdate = 0;
	}
}

