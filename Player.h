#ifndef PLAYER
#define PLAYER
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <QKeyEvent>
#define MAX_LIVES = 3;

class Player :  public GameObject {
	Q_OBJECT
		
public:
	explicit Player(int nx, int ny,int nz, QPixmap* pixmap, MyList<QPixmap*>* animation);
	~Player();
	
	int getHealth();
	int getLives();
	void setLives(int life);
	void setHealth(int health);
	void spawnTurret();
	
	void keyPressed(QKeyEvent* key);

signals:
	void Lose();
	void changeHealth(int);
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	

private:
		int health;
		int lives;
		int moveSpeed;

		//Animation
		int animationSpeed;
		int animationFrame;
		int animationCounter;
		int RanimationCounter;
		MyList<QPixmap*>* anim;
		
};

#endif 
