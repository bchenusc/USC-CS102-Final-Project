#ifndef BACKGROUND
#define BACKGROUND
#include <QGraphicsPixmapItem>
#include "GameObject.h"

#include <iostream>

using namespace std;

class Background : public GameObject {
	
public:
	Background(int nx, int ny, int w, int h, QPixmap* pixmap);
	~Background();
	void Update();
	
public slots:
	//void Update();

private:
};

#endif 
