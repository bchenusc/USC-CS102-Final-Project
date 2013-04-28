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
	
	void mousePressed(int x, int y);
	
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	
private:
	Player* player;
	double shootSpeed;
	int lockX;
	int lockY;
	
	//Cooldown timers
	int shootCounter;
	int RshootCounter;
};

#endif 
