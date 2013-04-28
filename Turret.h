#ifndef TURRET
#define TURRET
#include <QGraphicsPixmapItem>
#include "GameObject.h"
#include "mylist.h"
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

class Turret :  public GameObject {
	Q_OBJECT
		
public:
	explicit Turret(int nx, int ny,int nz, QPixmap* pixmap);
	~Turret();

	void mouseFollow(QGraphicsSceneMouseEvent* event);
	
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);
	
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
