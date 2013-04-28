#ifndef ENEMY
#define ENEMY
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"
#include "Missile.h"


class Enemy : public GameObject {
	
public:
	Enemy(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed, double shootSpeed);
	Enemy(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed, double shootSpeed);
	~Enemy();
	
	int getHealth();
	void setHealth(int health);
	
	void setNumOfBullets(int num);
	void setRSpawnBulletCounter(int num);

	void setPlayerRef(Player* player);
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
private:
		int health;
		
	  double speed;
	  double shootSpeed;
	  int numberOfBullets;
		
		//Animation
		int animationSpeed;
		int animationFrame;
		int animationCounter;
		int RanimationCounter;
		MyList<QPixmap*>* anim;
		
		int spawnBulletCounter;
		int RspawnBulletCounter;
		
		int moveToPositionX;
		int moveToPositionY;
		
		Player* playerRef;
		
};

#endif 
