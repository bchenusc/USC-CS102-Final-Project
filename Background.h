#ifndef BACKGROUND
#define BACKGROUND
#include <QGraphicsPixmapItem>
#include "GameObject.h"

#include <iostream>

using namespace std;

class Background : public GameObject {
	
public:
	Background(int nx, int ny, int nz, QPixmap* pixmap);
	~Background();

	void setSpeed(int i);
	
public slots:
	void Update();
	void OnCollisionEnter(MyList<GameObject*>* gameObjects);

private:
	int speed;
	
};

#endif 
