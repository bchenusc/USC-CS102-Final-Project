#ifndef MISSILE
#define MISSILE
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <string>

class Missile : public GameObject {
	
public:
	Missile(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed);
	~Missile();



	void HandleCollision(string type);
	
public slots:
	virtual void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	
private:
		void explosion(); //Makes the explosion animation for this class;
		
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
