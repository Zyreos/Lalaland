#pragma once
#include <string>

#include "entity.h"
#include "screen.h"

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
    RUN,
    WAIT
};

class Battle
{
private:
    Player& player;
    Enemy& enemy;

    BattleState battleState;
    BattleAction battleAction;
    int option;
    int selectedRow;

public:
    Battle(Player& player, Enemy& enemy);

    BattleState getBattleState();

    void Start();
    void Update();
    void Draw(Texture bgImg, Texture playerImg, Texture enemyImg);

};