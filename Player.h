#ifndef PLAYER
#define PLAYER
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <QKeyEvent>
#define MAX_LIVES = 3;

class Player : public GameObject {
	
public:
	Player(int nx, int ny,int nz, QPixmap* pixmap, MyList<QPixmap*>* animation);
	~Player();
	
	int getHealth();
	int getLives();
	int getScore();
	void setLives(int life);
	void setHealth(int health);
	void setScore(int score); 
	
	void keyPressed(QKeyEvent* key);
	
	void Update();

public slots:
	

private:
		int health;
		int lives;
		int score;
		int moveSpeed;
		
		//Animation
		int animationSpeed;
		int animationFrame;
		int animationCounter;
		int RanimationCounter;
		MyList<QPixmap*>* anim;
		
};

#endif 
