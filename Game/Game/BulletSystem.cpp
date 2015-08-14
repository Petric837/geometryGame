#include "BulletSystem.h"

float calculateAngle(sf::Vector2i point1, sf::Vector2i point2) {
	float angle;
	float xDiff = point2.x - point1.x;
	float yDiff = point2.y - point1.y;
	angle = atan(yDiff / xDiff) * 180 / M_PI;

	if (point1.x > point2.x)  angle += 270;
	else  angle += 90;

	return angle;
}


BulletSystem::BulletSystem() {
	clock.restart();
}


void BulletSystem::run(sf::RenderWindow& window, Player p, float deltaTime) {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Time elapsed = clock.getElapsedTime();

		if (elapsed.asMilliseconds() > 60) {
			Bullet * b = new Bullet(p.xpos, p.ypos);
			float tmpAngle = calculateAngle(sf::Vector2i(p.xpos, p.ypos), sf::Mouse::getPosition(window));
			int newAngle = (tmpAngle + (rand() % 18 - 9));
			b->bullet.setRotation(newAngle + 90);
			b->vx = sin(newAngle * M_PI / 180) * 7;
			b->vy = -cos(newAngle * M_PI / 180) * 7;
			bullets.push_back(*b);
			clock.restart();
		}

	}

	for (int i = bullets.size() - 1; i >= 0; i--) {
		if (bullets[i].clock.getElapsedTime() > bullets[i].lifeTime) {
			bullets.erase(bullets.begin() + i);
		}
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].posx += bullets[i].vx  * deltaTime;
		bullets[i].posy += bullets[i].vy  * deltaTime;
		bullets[i].bullet.setPosition(bullets[i].posx, bullets[i].posy);

	}
}


void BulletSystem::draw(sf::RenderWindow& window) {
	for (int i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i].bullet);
	}
}
