#include <iostream>
#include "raylib.h"
#include "resource_dir.h"

#include "./Headers/battle.h"

enum GameState
{
	GAME_START,
	FLOOR_1,
	FLOOR_2,
	FLOOR_3,
	BATTLE,
};

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	int screenX = 800;
	int screenY = 800;
	int bgSize = 64;
	InitWindow(screenX, screenY, "CatGame");

	SearchAndSetResourceDir("resources");

	Texture2D floorBg			= LoadTexture("background1.png");
	Texture2D battleBg			= LoadTexture("BattleBKG.png");
	Texture2D niceCat			= LoadTexture("cat_nice.png");
	Texture2D enemyCatBox		= LoadTexture("EvilBox1.png");
	Texture2D enemyCatWitch		= LoadTexture("WitchFlying.png");
	Texture2D enemyCatVampire	= LoadTexture("VampireAmgry.png");


	Player player;
	Enemy enemy(enemyCatBox);
	Battle battle(player, enemy);

	GameState gameState = FLOOR_1;

	while (!WindowShouldClose())	
	{

		switch (gameState)
		{
		case GAME_START:
			break;
		case FLOOR_1:
			player.Move();
			if (player.getPositionX() == enemy.getPositionX() &&
				player.getPositionY() == enemy.getPositionY())
			{
				gameState = BATTLE;
			}
			break;
		case FLOOR_2:
			player.Move();
			break;
		case FLOOR_3:
			player.Move();
			break;
		case BATTLE:
			battle.Update();
			break;
		default:
			break;
		}

		BeginDrawing();

		DrawTexture(floorBg, 10, 10, WHITE);

		switch (gameState)
		{
		case GAME_START:
			break;
		case FLOOR_1:
			for (int y = 0; y < screenY; y += bgSize)
			{
				for (int x = 0; x < screenX; x += bgSize)
				{
					DrawTexture(floorBg, x, y, WHITE);
				}
			}

			player.FloorDraw(niceCat, player.getPositionX(), player.getPositionY());
			enemy.FloorDraw(enemyCatBox, enemy.getPositionX(), enemy.getPositionY());
			break;
		case FLOOR_2:
			break;
		case FLOOR_3:
			break;
		case BATTLE:
			battle.Draw(battleBg, niceCat, enemyCatBox);
			break;
		default:
			break;
		}


		ClearBackground(RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;


	//Player player;
	//Enemy enemy;

	//Battle battle(player, enemy);

	//battle.Start();
	//battle.Update();

	//std::cin.get();

}
