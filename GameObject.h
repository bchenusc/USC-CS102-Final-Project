#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <QGraphicsPixmapItem>
#include <math.h>
#include <string>

#include <iostream>
using namespace std;

class GameObject : public QObject, public QGraphicsPixmapItem {

	Q_OBJECT
	
public:
	explicit GameObject(int nx, int ny, int nz, QPixmap* pixmap);
	~GameObject();
	int gX();
	int gY();
	int gVX();
	int gVY();
	bool isFlipped();
	void flipImg();
	void MoveTowards(double x, double y, double speed);
	void MoveDir(double x, double y, double speed);
	virtual void Update();
	
signals:
	void Destroy(GameObject*);
	void Spawn(GameObject*);
	
public slots:
	
protected :
		double x;
		double y;
		double vx;
		double vy;
		int width;
		int height;
		bool flipHorizontal;
		double dirX;
		double dirY;
		string type;
		
		QPixmap* pixmap;
		
		
};

#endif 
