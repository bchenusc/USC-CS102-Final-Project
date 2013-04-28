#ifndef BOOSTHEALTH
#define BOOSTHEALTH
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"


class Boost_Health : public GameObject {
	
public:
	Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed);
	~Boost_Health();

	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	void setPlayerRef(Player* player);
	
public slots:
	

private:
		Player* playerRef;
		double speed;
		bool movingUp;
		
		int moveToPositionX;
		int moveToPositionY;
		
};

#endif 
