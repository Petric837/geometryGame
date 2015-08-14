#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Enemy
{
private:
	
public:
	float vx, vy;
	sf::ConvexShape body;
	sf::Vector2f position;
	virtual void attack(Player, float);
	virtual void draw(sf::RenderWindow&);
};

class Diamond : public Enemy
{
private:
	float maxSpeed, accel;
public:
	Diamond(sf::Vector2f);
	void attack(Player, float);
	void draw(sf::RenderWindow&);
};

#endif