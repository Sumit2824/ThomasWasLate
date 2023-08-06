#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	ParticleSystem m_PS;

	Thomas m_Thomas;
	Bob m_Bob;
	LevelManager m_LM;
	SoundManager m_SM;
	HUD m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	//The force pushing the character down
	const int GRAVITY = 300;

	//A regular Render Window
	RenderWindow m_Window;

	//The main views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	//Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_HudView;

	//Declare a sprite and a Texture for the ground
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//Is the game currently playing?
	bool m_Playing = false;

	//Is Character 1 or 2 is current focus?
	bool m_Character1 = true;

	//Start in full screen (not split) mode
	bool m_SplitScreen = false;

	//Time left in current level(seconds)
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//Is it time for new/first level?
	bool m_NewLevelRequired = true;

	//The vertex Array for the level Tiles
	VertexArray m_VALevel;

	//A 2D array with the map for the level
	int** m_ArrayLevel = NULL;

	//Texture for level tiles
	Texture m_TextureTiles;

	//Private function for internal use
	void input();
	void update(float dtAsSeconds);
	void draw();

	//Load a new level
	void loadLevel();

	bool detectCollisions(PlayableCharacter& character);

	//Make a vector of a best places to emit sound from
	void populateEmitters(vector<Vector2f>& vSoundEmitters, int** arraylevel);
	
	//A vector of vector2f for the fire emitter locations
	vector<Vector2f> m_fireEmitters;

public:
	//The engine constructor
	Engine();

	//Run will call all the private functions
	void run();



};