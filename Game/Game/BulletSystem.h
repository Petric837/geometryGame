#ifndef BULLETSYSTEM_H
#define BULLETSYSTEM_H

#include <vector>
#include "player.h"

struct Bullet {
	float vx, vy, posx, posy;
	sf::Clock clock;
	sf::Time lifeTime;
	sf::ConvexShape bullet;
	Bullet(float posx_, float posy_) {
		posx = posx_;
		posy = posy_;
		lifeTime = sf::milliseconds((1000 + rand() % 300) - 150);
		clock.restart();
		bullet.setPointCount(4);
		bullet.setPoint(0, sf::Vector2f(0, 0));
		bullet.setPoint(1, sf::Vector2f(0, 3));
		bullet.setPoint(2, sf::Vector2f(15, 3));
		bullet.setPoint(3, sf::Vector2f(15, 0));
		bullet.setFillColor(sf::Color(255, 0, 247));
		bullet.setOutlineColor(sf::Color(255, 192, 254));
		bullet.setOutlineThickness(1.2);
		bullet.setPosition(posx, posy);
	}
};


class BulletSystem
{
private:
	sf::Clock clock;
public:
	BulletSystem();
	void run(sf::RenderWindow&, Player, float);
	void draw(sf::RenderWindow&);
	std::vector<Bullet> bullets;
};

#endif