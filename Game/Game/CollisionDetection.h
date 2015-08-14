#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include "Player.h"
#include "BulletSystem.h"
#include "EnemyControl.h"

class CollisionDetection
{
private:
	
public:
	void detect(Player&, BulletSystem&, EnemyControl&);
};

#endif