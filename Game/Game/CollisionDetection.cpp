#include "CollisionDetection.h"

void CollisionDetection::detect(Player& p, BulletSystem& b, EnemyControl& e) {

	// Bullet Collision
	for (int i = b.bullets.size()-1; i >= 0; i--) {
		for (int j = e.EnemyList.size()-1; j >= 0; j--) {
			if (b.bullets[i].bullet.getGlobalBounds().intersects(e.EnemyList[j]->body.getGlobalBounds())) {
				b.bullets.erase(b.bullets.begin() + i);
				e.EnemyList.erase(e.EnemyList.begin() + j);
			}
		}
	}
}