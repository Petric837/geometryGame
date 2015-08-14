#ifndef THRUSTANIMATION_H
#define THRUSTANIMATION_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

struct spark {
	sf::ConvexShape particle;
	float vx, vy, posx, posy, friction;
	sf::Time lifeTime;
	sf::Clock clock;
	spark(float posx_, float posy_) {
		posx = posx_; posy = posy_;
		vx = 0; vy = 0;
		friction = .98f;
		lifeTime = sf::milliseconds((400 + rand() % 400) - 200);
		particle.setPointCount(4);
		particle.setPoint(0, sf::Vector2f(0.f, 0.f));
		particle.setPoint(1, sf::Vector2f(4.f, 0.f));
		particle.setPoint(2, sf::Vector2f(4.f, 4.f));
		particle.setPoint(3, sf::Vector2f(0.f, 4.f));
		particle.setRotation(rand() % 360);
		particle.setFillColor(sf::Color(255, 128, 0));
		particle.setOutlineColor(sf::Color(255, 230, 0));
		particle.setOutlineThickness(.2);
		particle.setOrigin(sf::Vector2f(0, 0));
		particle.setPosition(posx, posy);
	}
};

class ThrustAnim
{
private:
	std::vector<spark> flames;
	sf::Clock clock;
	int clk;
public:
	ThrustAnim();
	void run(Player, float);
	void draw(sf::RenderWindow&);
};


#endif