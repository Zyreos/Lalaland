#pragma once
#include <string>

#include "raylib.h"
#include "resource_dir.h"

struct Position
{
	float x, y;
};

class Entity
{
protected:

	std::string name;

	int maxHp;
	int currentHp;
	int attack;
	int defense;
	int healPower;
	Position position;

	Texture texture;

public:
	Entity();

	virtual void Update() = 0;
	virtual void FloorDraw(Texture texture, int posX, int posY) = 0;
	void BattleDraw(Texture texture, float posX, float posY, float size);

	int getMaxHp();
	int getCurrentHp();
	int getAttack();
	int getDefense();
	int getPositionX();
	int getPositionY();
	int getTextureWidth();
	int getTextureHeight();
		
	void setPositionX(int posX);
	void setPositionY(int posY);
	void setHealth();
	void setDefense();
	void resetDefense();

	bool IsAlive();
	void TakeDamage(int attackDmg, int defenseMitig);
	void Heal();

	void Attack(Entity& attacker, Entity& defender);

	virtual ~Entity() = default;

};	

class Player : public Entity
{
private:
	int level;
	int currentXp;
	int maxXp;

public:
	Player();

	void Update() override;
	void FloorDraw(Texture texture, int posX, int posY) override;
	
	void Move();

	int getLevel();
	int getXp();
	int getMaxXp();

	void GainXp(int xp);
	void LoseXp(int xp);

};

class Enemy : public Entity
{
private:
	int xpAmount;

public:
	Enemy();
	Enemy(Texture loadTexture);

	void Update() override;
	void FloorDraw(Texture texture, int posX, int posY) override;

	int getXpAmount();
	Texture getTexture();

	void setNextLevel(Texture texture);
	void setPrevLevel(Texture texture);
};
