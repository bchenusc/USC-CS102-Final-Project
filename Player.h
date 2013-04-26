#ifndef PLAYER
#define PLAYER
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#define MAX_LIVES = 3;

class Player : public GameObject {
	
public:
	Player(int nx, int ny,int nz, QPixmap* pixmap);
	~Player();
	
	int getHealth();
	int getLives();
	int getScore();
	void setLives(int life);
	void setHealth(int health);
	void setScore(int score); 
	void Update();
		
		QPixmap* anim1;
		QPixmap* anim2;
		QPixmap* anim3;
	
public slots:
	

private:
		int health;
		int lives;
		int score;
		int animationSpeed;
		
		int animationCounter;
		int RanimationCounter;
};

#endif 
