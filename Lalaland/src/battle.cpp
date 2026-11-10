#include<iostream>
#include <string>
#include "./Headers/battle.h"

Battle::Battle(Player& player, Enemy& enemy)
	: player(player), 
	enemy(enemy),
	battleState(PLAYER_TURN),
	battleAction(WAIT),
	option(0),
	selectedRow(0)
{}

BattleState Battle::getBattleState()
{
	return battleState;
}

void Battle::Start()
{
	battleState = PLAYER_TURN;
	player.setHealth();
	player.resetDefense();

	enemy.setHealth();
	enemy.resetDefense();
}

void Battle::Update()
{

	switch (battleState)
	{
	case PLAYER_TURN:
		if (IsKeyPressed(KEY_DOWN))
		{
			option++;
			if (option == 3)
				option = 0;
		}
		else if (IsKeyPressed(KEY_UP))
		{
			option--;
			if (option == 0)
				option = 3;
		}


		if (IsKeyPressed(KEY_ENTER))
		{
			if (option == 0)
				battleAction = ATTACK;
			else if (option == 1)
				battleAction = DEFEND;
			else if (option == 2)
				battleAction = HEAL;
			else if (option == 3)
				battleAction = RUN;
		}

		switch (battleAction)
		{
		case ATTACK:
			player.Attack(player, enemy);
			option = 0;
			if (enemy.IsAlive())
			{
				battleState = ENEMY_TURN;
			}
			else
			{
				battleState = VICTORY;
			}
			battleAction = WAIT;
			break;
		case HEAL:
			player.Heal();
			option = 0;
			battleState = ENEMY_TURN;
			battleAction = WAIT;
			break;
		case DEFEND:
			player.setDefense();
			option = 0;
			battleState = ENEMY_TURN;
			battleAction = WAIT;
			break;
		case RUN:
			// TODO
			// Reset Screen & Stats
			break;
		default:
			break;
		}
		break;
	case ENEMY_TURN:
		enemy.Attack(enemy, player);
		if (player.IsAlive())
		{
			battleState = PLAYER_TURN;
		}
		else
		{
			battleState = DEFEAT;
		}
		break;
	case VICTORY:
		player.GainXp(enemy.getXpAmount());
		break;
	case DEFEAT:
		player.LoseXp(enemy.getXpAmount());

		break;
	default:
		break;
	}

}

void Battle::Draw(Texture bgImg, Texture playerImg, Texture enemyImg)
{
	DrawTexture(bgImg, 0, 0, WHITE);

	player.BattleDraw(playerImg, 50, 400, 256);

	enemy.BattleDraw(enemyImg, 450, 50, 256);


	int x = 300;
	int y = 400;
	int spacing = 180;


			DrawText("ATTACK", x, y, 30,
				option == 0 ? YELLOW : WHITE);

			DrawText("DEFEND", x, y + spacing, 30,
				option == 1 ? YELLOW : WHITE);

			DrawText("HEAL", x, y + spacing*2, 30,
				option == 2 ? YELLOW : WHITE);

			DrawText("RUN", x, y + spacing*3, 30,
				option == 3 ? YELLOW : WHITE);

			DrawText(TextFormat("Score: %d", player.getCurrentHp()), 200, 200, 40, MAROON);

}

void Battle::DrawMenu()
{

}

