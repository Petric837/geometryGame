#include "Player.h"

Player::Player() {
	xpos = 1280 / 2;
	ypos = 720 / 2;
	angle = 0.f;
	vx = 0; vy = 0;
	speed = .2;
	maxSpeed = 3;
	friction = .95;

	ship.setPointCount(4);
	ship.setPoint(0, sf::Vector2f(0.f, 20.f));
	ship.setPoint(1, sf::Vector2f(7.f, 0.f));
	ship.setPoint(2, sf::Vector2f(15.f, 20.f));
	ship.setPoint(3, sf::Vector2f(7.f, 13.f));
	ship.setOutlineColor(sf::Color::White);
	ship.setOutlineThickness(3);
	ship.setFillColor(sf::Color::Transparent);
	ship.setPosition(xpos, ypos);
	ship.setOrigin(sf::Vector2f(7.f, 10.f));

}

void Player::controlSystem(float deltaTime){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (angle != 45) {
			if (angle <= 225 && angle > 45) {
				angle -= 7.5;
				ship.setRotation(angle);
			}
			else {
				if (angle == 360) { angle = 0; }
				angle += 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (angle != 135) {
			if (angle <= 315 && angle > 135) {
				angle -= 7.5;
				ship.setRotation(angle);
			}
			else {
				if (angle == 360) { angle = 0; }
				angle += 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (angle != 225) {
			if (angle >= 45 && angle < 225) {
				angle += 7.5;
				ship.setRotation(angle);
			}
			else {
				if (angle == 0) { angle = 360; }
				angle -= 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (angle != 315) {
			if (angle >= 135 && angle < 315) {
				angle += 7.5;
				ship.setRotation(angle);
			}
			else {
				if (angle == 0) { angle = 360; }
				angle -= 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (angle != 0) {
			if (angle <= 180) {
				angle -= 7.5;
				ship.setRotation(angle);
			}
			else {
				if (angle == 360) { angle = 0; }
				angle += 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (angle != 90) {
			if (angle <= 270 && angle > 90) {
				angle -= 7.5;
				ship.setRotation(angle);
			}
			else {
				if (angle == 360) { angle = 0; }
				angle += 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (angle != 180) {
			if (angle >= 0 && angle < 180) {
				angle += 7.5;
				ship.setRotation(angle);
			}
			else {
				angle -= 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (angle != 270) {
			if (angle >= 90 && angle < 270) {
				angle += 7.5;
				ship.setRotation(angle);
			}
			else {
				if (angle == 0) { angle = 360; }
				angle -= 7.5;
				ship.setRotation(angle);
			}
		}
		else {
			vx += sin(angle * M_PI / 180) * speed;
			vy += -cos(angle * M_PI / 180) * speed;
		}
	}
	else {
		vx *= friction;
		vy *= friction;
	}

	int currentSpeed = sqrt((vx*vx) + (vy*vy));
	if (currentSpeed > maxSpeed) {
		vx *= maxSpeed / currentSpeed;
		vy *= maxSpeed / currentSpeed;
	}

	xpos += vx * deltaTime;
	ypos += vy * deltaTime;

	if (xpos < 0) { xpos = 0; }
	else if (xpos > 1280) { xpos = 1280; }
	if (ypos < 0) { ypos = 0; }
	else if (ypos > 720) { ypos = 720; }

	ship.setPosition(sf::Vector2f(xpos, ypos));
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(ship);
}