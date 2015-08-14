#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

class Player
{
private:
	float vx, vy, speed, maxSpeed, friction;
public:
	Player();
	float xpos, ypos, angle;
	sf::ConvexShape ship;
	void controlSystem(float);
	void draw(sf::RenderWindow&);
};

#endif