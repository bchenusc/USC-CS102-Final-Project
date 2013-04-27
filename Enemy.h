#ifndef ENEMY
#define ENEMY
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <string>

class Enemy : public GameObject {
	
public:
	Enemy(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed);
	Enemy(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed);
	~Enemy();
	
	int getHealth();
	void setHealth(int health);
	void setScore(int score); 
	void Update();
		
		
	
public slots:
	

private:
		int health;
		
	  double speed;
		
		//Animation
		int animationSpeed;
		int animationFrame;
		int animationCounter;
		int RanimationCounter;
		MyList<QPixmap*>* anim;
		
		int moveToPositionX;
		int moveToPositionY;
		
};

#endif 
