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
	
	int setNumOfBullets(int num);
	int setRSpawnBulletCounter(int num);

	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	void setPlayerRef(Player* player);
	
public slots:
	

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
