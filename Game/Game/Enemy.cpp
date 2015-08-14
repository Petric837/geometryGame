#include "Enemy.h"
#include <iostream>

float calculateAngle2(sf::Vector2f point1, sf::Vector2f point2) {
	float angle;
	float xDiff = point2.x - point1.x;
	float yDiff = point2.y - point1.y;
	angle = atan(yDiff / xDiff) * 180 / M_PI;

	if (point1.x > point2.x)  angle += 270;
	else  angle += 90;

	return angle;
}

void Enemy::attack(Player p, float deltaTime) {
	std::cout << "wrong function" << std::endl;
}

void Enemy::draw(sf::RenderWindow& window) {
	std::cout << "wrong function" << std::endl;
}

Diamond::Diamond(sf::Vector2f pos) {
	position = pos;
	vx = 0; vy = 0;
	maxSpeed = 1 + (rand() % 5 * .1) + .3;
	accel = (rand() % 6 * .1) + .3;
	body.setPointCount(4);
	body.setPoint(0, sf::Vector2f(0, 18));
	body.setPoint(1, sf::Vector2f(9, 37));
	body.setPoint(2, sf::Vector2f(18, 18));
	body.setPoint(3, sf::Vector2f(9, 0));
	body.setFillColor(sf::Color::Transparent);
	body.setOutlineColor(sf::Color(0, 255, 255));
	body.setOutlineThickness(4);
	body.setPosition(position);
}

void Diamond::attack(Player p, float deltaTime) {

	float tmpAngle = calculateAngle2(position, sf::Vector2f(p.xpos, p.ypos));
	vx += sin(tmpAngle * M_PI / 180) * accel;
	vy += -cos(tmpAngle * M_PI / 180) * accel;

	int currentSpeed = sqrt((vx*vx) + (vy*vy));
	if (currentSpeed > maxSpeed) {
		vx *= maxSpeed / currentSpeed;
		vy *= maxSpeed / currentSpeed;
	}

	position.x += vx * deltaTime;
	position.y += vy * deltaTime;

	body.setPosition(position);
}

void Diamond::draw(sf::RenderWindow& window) {
	window.draw(body);
}