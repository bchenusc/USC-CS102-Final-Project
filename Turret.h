#ifndef TURRET
#define TURRET
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include "Player.h"

class Turret :  public GameObject {
	Q_OBJECT
		
public:
	explicit Turret(int nx, int ny,int nz, QPixmap* pixmap, Player* player);
	~Turret();
	void setLockX(int nx);
	void setLockY(int ny);
	void mouseFollow(int mx, int my);
	
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	
private:
	Player* player;
	int lockX;
	int lockY;
};

#endif 
