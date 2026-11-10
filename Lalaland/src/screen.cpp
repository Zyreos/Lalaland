#include <iostream>

#include "./Headers/screen.h"


Screen::Screen(Player& player, Enemy& enemy, GameScreen screen)
	: player(player), enemy(enemy), screen(screen)
{ }

Player& Screen::getPlayer()
{
	return player;
}

Enemy& Screen::getEnemy()
{
	return enemy;
}

GameScreen Screen::getGameScreen()
{
	return screen;
}

GameScreen Screen::moveToNext(GameScreen curScreen)
{
	return static_cast<GameScreen>((curScreen + 1) % COUNT);
}

GameScreen Screen::goBack(GameScreen curScreen)
{
	return static_cast<GameScreen>((curScreen - 1) % COUNT);
}

GameScreen Screen::screenLogic(GameScreen currentFloor, Enemy& enemyF)
{
	GameScreen prevFloor = goBack(currentFloor);
	GameScreen nextFloor = moveToNext(currentFloor);
	GameScreen targetState;

	player.Move();
	if (player.getPositionX() == enemyF.getPositionX() &&
		player.getPositionY() == enemyF.getPositionY())
	{
		player.setPosition();
		return targetState = BATTLE;

	}
	else if (player.getPositionX() == 0 &&
			 player.getPositionY() == 0 &&
			 currentFloor != FLOOR_3)
	{
		player.setPosition();
		return targetState = nextFloor;
	}
	else if (player.getPositionX() == 800 &&
			 player.getPositionY() == 800 &&
			 currentFloor != FLOOR_1)
	{
		player.setPosition();
		return targetState = prevFloor;
	}
	else
	{
		return currentFloor;
	}
}




