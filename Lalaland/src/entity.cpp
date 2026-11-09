#include <iostream>
#include <string>

#include "raylib.h"
#include "resource_dir.h"

#include "./Headers/entity.h"


Entity::Entity()
	: name("Neutral"),
	maxHp(300),
	currentHp(300),
	attack(30),
	defense(0),
	healPower(90),
	position(0, 0),
	texture(LoadTexture("cat_nice.png"))
{ }


void Entity::BattleDraw(Texture texture, float posX, float posY, float size)
{
	DrawTexturePro(texture,
		{ 0,0,(float)texture.width, (float)texture.height },
		{ posX,posY,size,size },
		{ 0,0 },
		0.0f, WHITE);
}


int Entity::getMaxHp()
{
	return maxHp;
}

int Entity::getCurrentHp()
{
	return currentHp;
}

int Entity::getAttack()
{
	return attack;
}

int Entity::getDefense()
{
	return defense;
}

int Entity::getPositionX()
{
	return position.x;
}

int Entity::getPositionY()
{
	return position.y;
}

int Entity::getTextureWidth()
{
	return texture.width;
}

int Entity::getTextureHeight()
{
	return texture.height;
}

void Entity::setPositionX(int posX)
{
	position.x = posX;
}

void Entity::setPositionY(int posY)
{
	position.y = posY;
}

void Entity::setHealth()
{
	currentHp = maxHp;
}

void Entity::setDefense()
{
	defense += 3;
}

void Entity::resetDefense()
{
	defense = 0;
}


bool Entity::IsAlive()
{
	if (getCurrentHp() <= 0)
	{
		return false;
	}
	return true;
}

void Entity::TakeDamage(int attackDmg, int defenseMitig)
{
	currentHp = currentHp - (attackDmg - defenseMitig);
	if (currentHp < 0)
	{
		currentHp = 0;
	}
}

void Entity::Heal()
{
	currentHp = currentHp + healPower;
	if (currentHp > maxHp)
	{
		currentHp = maxHp;
	}
}

void Entity::Attack(Entity& attacker, Entity& defender)
{
	int attackDamage		= attacker.getAttack();
	int attackMitigation	= defender.getDefense();

	defender.TakeDamage(attackDamage, attackMitigation);
	defender.resetDefense();
}


Player::Player()
	: level(1), currentXp(0), maxXp(300)
{
	name		= "Player";
	position.x	= 400;
	position.y	= 300;
}

void Player::Update()
{
	// TODO
}

void Player::FloorDraw(Texture texture, int posX, int posY)
{
	DrawTexture(texture, posX, posY, WHITE);
}

void Player::Move()
{
	if (IsKeyDown(KEY_RIGHT)) position.x += 2.0f;
	if (IsKeyDown(KEY_LEFT)) position.x -= 2.0f;
	if (IsKeyDown(KEY_UP)) position.y -= 2.0f;
	if (IsKeyDown(KEY_DOWN)) position.y += 2.0f;
	if (position.x < 0) position.x = 800;
	if (position.x > 800) position.x = 0;
	if (position.y < 0) position.y = 800;
	if (position.y > 800) position.y = 0;

}

int Player::getLevel()
{
	return level;
}

int Player::getXp()
{
	return currentXp;
}

int Player::getMaxXp()
{
	return maxXp;
}

void Player::GainXp(int xp)
{
	currentXp += xp;
	if (currentXp >= maxXp)
	{
		level		+= 1;
		currentXp	= currentXp - maxXp;
		maxHp		+= 100;
		currentHp	= maxHp;
		attack		+= 25;
		defense		+= 1;
		healPower	+= 3;
	}

}

void Player::LoseXp(int xp)
{
	currentXp -= xp;
	if (currentXp < 0)
	{
		currentXp = 0;
	}
}

Enemy::Enemy()
	: xpAmount(30)
{
	name		= "Enemy";
	position.x	= 400;
	position.y	= 100;
}

Enemy::Enemy(Texture loadTexture)
	: xpAmount(30)
{
	name		= "Enemy";
	texture		= loadTexture;
	position.x	= 400;
	position.y	= 100;
}

void Enemy::Update()
{
	//TODO
}

void Enemy::FloorDraw(Texture texture, int posX, int posY)
{
	DrawTexture(texture, posX, posY, WHITE);
}

int Enemy::getXpAmount()
{
	return xpAmount;
}
Texture Enemy::getTexture()
{
	return texture;
}

void Enemy::setNextLevel(Texture texture)
{
	maxHp		+= 100;
	currentHp	= maxHp;
	attack		+= 30;
	defense		+= 1;
	healPower	+= 3;
	xpAmount	+= 30;
}

void Enemy::setPrevLevel(Texture texture)
{
	maxHp		-= 100;
	currentHp	= maxHp;
	attack		-= 30;
	defense		-= 1;
	healPower	-= 3;
	xpAmount	-= 30;
}
