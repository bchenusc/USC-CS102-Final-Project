#ifndef DEADLYHAMSTER
#define DEADLYHAMSTER
#include <QGraphicsPixmapItem>
#include <string>
#include "GameObject.h"
#include "mylist.h"
#include "Player.h"
#include "Missile.h"


class DeadlyHamster : public GameObject {

	Q_OBJECT
	
public:
	DeadlyHamster(int nx, int ny, int nz, QPixmap* pixmap, double speed);
	~DeadlyHamster();
	
	void setPlayerRef(Player* player);
	
signals:
	void addScore(int);
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
private:
	  double speed;
		Player* playerRef;
		
};

#endif 
