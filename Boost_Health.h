#ifndef BOOSTHEALTH
#define BOOSTHEALTH
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"


class Boost_Health : public GameObject {
	
public:
	Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, double speed);
	~Boost_Health();

	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	void setPlayerRef(Player* player);
	
	void HandleCollision(string type);
	
public slots:
	

private:
		Player* playerRef;
		double speed;
		bool isMovingLeft;
		
		int initialX;
		int initialY;
		
};

#endif 
