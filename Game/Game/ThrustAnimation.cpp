#include "ThrustAnimation.h"

ThrustAnim::ThrustAnim() {
	clock.restart();
}

void ThrustAnim::run(Player p, float deltaTime) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		sf::Time elapsed = clock.getElapsedTime();

		if (elapsed.asMilliseconds() > 35) {
			spark * s = new spark(p.xpos, p.ypos);
			s->clock.restart();
			int newAngle = (((int)p.angle + 180) % 360 + (rand() % 70 - 35));
			s->vx = sin(newAngle * M_PI / 180) * 1.5;
			s->vy = -cos(newAngle * M_PI / 180) * 1.5;
			flames.push_back(*s);
			clock.restart();
		}

	}

	for (int i = flames.size() - 1; i >= 0; i--) {
		if (flames[i].clock.getElapsedTime() > flames[i].lifeTime) {
			flames.erase(flames.begin() + i);
		}
	}

	for (int i = 0; i < flames.size(); i++) {
		flames[i].posx += flames[i].vx * deltaTime;
		flames[i].posy += flames[i].vy * deltaTime;
		flames[i].particle.setPosition(flames[i].posx, flames[i].posy);

		flames[i].vx *= flames[i].friction;
		flames[i].vy *= flames[i].friction;
	}

}

void ThrustAnim::draw(sf::RenderWindow& window) {
	for (int i = 0; i < flames.size(); i++) {
		window.draw(flames[i].particle);
	}
}