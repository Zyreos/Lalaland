#pragma once
#include <string>

#include "entity.h"

enum BattleState
{
    PLAYER_TURN,
    ENEMY_TURN,
    VICTORY,
    DEFEAT,
};

enum BattleAction
{
    ATTACK = 1,
    HEAL,
    DEFEND,
    FLEE
};

class Battle
{
private:
    Player& player;
    Enemy& enemy;

    BattleState battleState;

public:
    Battle(Player& player, Enemy& enemy);

    void Start();
    void Update();
    void Draw(Texture bgImg, Texture playerImg, Texture enemyImg);

    void RunAway();

    void Win();
    void Lose();
    void ReturnPreviousArea();
    void MoveNextArea();
    void ResetArea();

};