#pragma once

#include<string>
#include "entity.h"

enum GameScreen
{
	GAME_START = 0,
	FLOOR_1 = 1,
	FLOOR_2 = 2,
	FLOOR_3 = 3,
	COUNT = 4,
	BATTLE = 5,
};

class Screen
{
protected:
	Player& player;
	Enemy& enemy;
	GameScreen screen;

public:

	Screen(Player& player, Enemy& enemy, GameScreen screen);

	Player& getPlayer();
	Enemy& getEnemy();
	GameScreen getGameScreen();

	GameScreen moveToNext(GameScreen curScreen);
	GameScreen goBack(GameScreen curScreen);

	GameScreen screenLogic(GameScreen currentFloor, Enemy& enemy);

};
