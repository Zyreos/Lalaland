#include <iostream>
#include "raylib.h"
#include "resource_dir.h"

#include "./Headers/battle.h"
#include "./Headers/screen.h"


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
	Enemy enemy1(enemyCatBox);
	Enemy enemy2(enemyCatWitch);
	Enemy enemy3(enemyCatVampire);
	Battle battle(player, enemy1);

	Enemy* currentEnemy;
	std::unique_ptr<Battle> currentBattle;

	Screen screen(player, enemy1, GAME_START);

	GameScreen gameState = screen.getGameScreen();
	GameScreen currentFloor = screen.getGameScreen();

	while (!WindowShouldClose())	
	{

		switch (gameState)
		{
		case GAME_START:
			gameState = FLOOR_1;
			break;
		case FLOOR_1:
			currentFloor = gameState;
			gameState = screen.screenLogic(currentFloor, enemy1);
			if (gameState == BATTLE)
			{
				currentEnemy = &enemy1;
			}
			break;
		case FLOOR_2:
			currentFloor = gameState;
			gameState = screen.screenLogic(currentFloor, enemy2);
			if (gameState == BATTLE)
			{
				currentEnemy = &enemy2;
			}
			break;
		case FLOOR_3:
			currentFloor = gameState;
			gameState = screen.screenLogic(currentFloor, enemy3);
			if (gameState == BATTLE)
			{
				currentEnemy = &enemy3;
			}
			break;
		case BATTLE:

			if(!currentBattle)
			{
				currentBattle = std::make_unique<Battle>(player, *currentEnemy);
				currentBattle->Start();
			}
			else
			{
				currentBattle->Update();
			}

			if (currentBattle->getBattleState() == VICTORY)
			{
				gameState = screen.moveToNext(currentFloor);
				currentBattle.reset();
				currentEnemy = nullptr;
			}
			else if (currentBattle->getBattleState() == DEFEAT)
			{
				gameState = currentFloor;
				currentBattle.reset();
				currentEnemy = nullptr;
			}
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

			player.FloorDraw(player.getTexture(), player.getPositionX(), player.getPositionY(), 64);
			enemy1.FloorDraw(enemy1.getTexture(), enemy1.getPositionX(), enemy1.getPositionY(), 64);

			break;
		case FLOOR_2:
			for (int y = 0; y < screenY; y += bgSize)
			{
				for (int x = 0; x < screenX; x += bgSize)
				{
					DrawTexture(floorBg, x, y, WHITE);
				}
			}

			player.FloorDraw(player.getTexture(), player.getPositionX(), player.getPositionY(), 64);
			enemy2.FloorDraw(enemy2.getTexture(), enemy2.getPositionX(), enemy2.getPositionY(), 64);
			break;
		case FLOOR_3:
			for (int y = 0; y < screenY; y += bgSize)
			{
				for (int x = 0; x < screenX; x += bgSize)
				{
					DrawTexture(floorBg, x, y, WHITE);
				}
			}

			player.FloorDraw(player.getTexture(), player.getPositionX(), player.getPositionY(), 64);
			enemy3.FloorDraw(enemy3.getTexture(), enemy3.getPositionX(), enemy3.getPositionY(), 64);
			break;
		case BATTLE:

			if (currentBattle)
			{
				currentBattle->Draw(battleBg, niceCat, currentEnemy->getTexture());
			}
									
			break;
		default:
			break;
		}

		ClearBackground(RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;

}
