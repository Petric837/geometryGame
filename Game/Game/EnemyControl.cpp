#include "EnemyControl.h"

EnemyControl::EnemyControl() {
	clock.restart();
}

void EnemyControl::spawn() {

	float x, y;
	int section = rand() % 4;
	if (section == 0) {
		x = -30;
		y = rand() % 740;
	}
	else if (section == 1) {
		x = rand() % 1290;
		y = -40;
	}
	else if (section == 2) {
		x = 1310;
		y = rand() % 740;
	}
	else {
		x = rand() % 1290;
		y = 760;
	}

	Diamond * e = new Diamond(sf::Vector2f(x, y));
	EnemyList.push_back(e);
}

void EnemyControl::run(Player p, float deltaTime) {
	sf::Time elapsed = clock.getElapsedTime();

	if (elapsed.asMilliseconds() > 500 && EnemyList.size() < 40) {
		spawn();
		clock.restart();
	}

	for (int i = 0; i < EnemyList.size(); i++) {
		EnemyList[i]->attack(p, deltaTime);
	}
}

void EnemyControl::draw(sf::RenderWindow& window) {
	for (int i = 0; i < EnemyList.size(); i++) {
		EnemyList[i]->draw(window);
	}
}