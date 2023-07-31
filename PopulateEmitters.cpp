#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel)
{
	vSoundEmitters.empty();

	//Keep track of the previous emitter so we don't make too many
	FloatRect previousEmitter;

	//search for the fire in level
	//(int) before the function use for type conversion
	for (int x = 0; x < (int)m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < (int)m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2) //fire is present
			{
				//skip over any fire tiles too
				//near a previous emitter
				if (!FloatRect(x* TILE_SIZE, y* TILE_SIZE, TILE_SIZE, TILE_SIZE).intersects(previousEmitter))
				{
					//Add the coordinates of the water block
					vSoundEmitters.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					//Make a rectangle of 6 x 6
					//So we don't make any more emitters
					//too close to this one
					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
				}
			}
		}
	}
	return;
}