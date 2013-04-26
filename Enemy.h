#ifndef PLAYER
#define PLAYER
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#define MAX_LIVES = 3;

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
