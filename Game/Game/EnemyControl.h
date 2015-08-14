#ifndef ENEMYCONTROL_H
#define ENEMYCONTROL_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
#include <vector>

class EnemyControl
{
private:
	sf::Clock clock;
public:
	EnemyControl();
	std::vector<Enemy*> EnemyList;
	void spawn();
	void run(Player, float);
	void draw(sf::RenderWindow&);
};

#endif