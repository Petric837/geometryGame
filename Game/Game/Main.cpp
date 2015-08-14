#include <SFML/Graphics.hpp>
#include "Player.h"
#include "BulletSystem.h"
#include "Enemy.h"
#include "EnemyControl.h"
#include "ThrustAnimation.h"
#include "CollisionDetection.h"
#include <iostream>
#include <algorithm>

int main()
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");
	window.setFramerateLimit(70);

	sf::Texture backgroundImg;
	backgroundImg.loadFromFile("pics/background.jpg");
	backgroundImg.setSmooth(true);
	sf::Sprite background;
	background.setTexture(backgroundImg);

	Player player;
	BulletSystem bulletSystem;
	EnemyControl enemyControl;
	ThrustAnim thrustAnimation;
	CollisionDetection collisionDetection;

	const float desiredFrametime = 1000 / 60;
	const int maxSteps = 6;

	sf::Time prevTicks = clock.getElapsedTime();

	while (window.isOpen())
	{
		sf::Time newTicks = clock.getElapsedTime();
		sf::Time frameTime = newTicks - prevTicks;
		prevTicks = newTicks;

		float totalDeltaTime = frameTime.asMilliseconds() / desiredFrametime;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(background);

		int i = 0;
		while (totalDeltaTime > 0.0f && i < maxSteps) {

			float deltaTime = std::min(totalDeltaTime, 1.0f);

			collisionDetection.detect(player, bulletSystem, enemyControl);
			bulletSystem.run(window, player, deltaTime);
			player.controlSystem(deltaTime);
			enemyControl.run(player, deltaTime);
			thrustAnimation.run(player, deltaTime);

			totalDeltaTime -= deltaTime;
			i++;
		}

		bulletSystem.draw(window);
		thrustAnimation.draw(window);
		player.draw(window);
		enemyControl.draw(window);

		window.display();
	}

	return 0;
}