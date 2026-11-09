#include<iostream>
#include <string>
#include "./Headers/battle.h"

Battle::Battle(Player& player, Enemy& enemy)
	: player(player),  enemy(enemy), battleState(PLAYER_TURN)
{}

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

	while (player.IsAlive() && enemy.IsAlive())
	{

		if (battleState == PLAYER_TURN)
		{
			// TODO
			// Get Player's imput

			std::cout << "Select Battle Action: 1-Attack 2- Heal 3- Defend" << std::endl;
						
			BattleAction battleAction;
			int action;
			std::cin >> action;
			battleAction = static_cast<BattleAction>(action);

			switch (battleAction)
			{
			case ATTACK:
				player.Attack(player, enemy);
				std::cout << "Player Attack" << std::endl;
				std::cout << player.getCurrentHp() << std::endl;
				break;
			case HEAL:
				player.Heal();
				std::cout << "Player Heal" << std::endl;
				std::cout << player.getCurrentHp() << std::endl;
				break;
			case DEFEND:
				player.setDefense();
				std::cout << "Player Defend" << std::endl;
				std::cout << player.getCurrentHp() << std::endl;
				break;
			case FLEE:
				// TODO
				// Reset Screen & Stats
				break;
			default:
				break;
			}

			battleState = ENEMY_TURN;
		}
		else if (battleState == ENEMY_TURN)
		{
			enemy.Attack(enemy, player);
			std::cout << "Enemy Attack" << std::endl;
			std::cout << player.getCurrentHp() << std::endl;
			battleState = PLAYER_TURN;
		}
		
	}
	if (player.IsAlive() && !enemy.IsAlive())
	{
		battleState = VICTORY;
		std::cout << "WIN" << std::endl;
		Win();
	}
	else if (!player.IsAlive() && enemy.IsAlive())
	{
		battleState = DEFEAT;
		std::cout << "DEFEAT" << std::endl;
		Lose();
	}

}

void Battle::Draw(Texture bgImg, Texture playerImg, Texture enemyImg)
{
	DrawTexture(bgImg, 0, 0, WHITE);

	player.BattleDraw(playerImg, 50, 400, 256);

	enemy.BattleDraw(enemyImg, 450, 50, 256);

}

void Battle::RunAway()
{
	// TODO
	// Return to Previous Screen
}

void Battle::Win()
{
	player.GainXp(enemy.getXpAmount());
	MoveNextArea();
}

void Battle::Lose()
{
	player.LoseXp(enemy.getXpAmount());
	ResetArea();
}

void Battle::ReturnPreviousArea()
{
	std::cout << "Suposedly Return Previous Area" << std::endl;
	// TODO
}

void Battle::MoveNextArea()
{
	std::cout << "Suposedly Move Next Area" << std::endl;
	// TODO
}

void Battle::ResetArea()
{
	std::cout << "Suposedly Reset Area" << std::endl;
	// TODO
}
