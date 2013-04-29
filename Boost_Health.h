#ifndef BOOSTHEALTH
#define BOOSTHEALTH
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"


class Boost_Health : public GameObject {

	Q_OBJECT
	
public:
	Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, double speed);
	~Boost_Health();
	
	void setPlayerRef(Player* player);
	
signals:
	void changeHealth(int);
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);	

private:
		Player* playerRef;
		double speed;
		bool isMovingLeft;
		
		int initialX;
		int initialY;
		
};

#endif 
