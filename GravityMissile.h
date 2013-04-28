#ifndef GRAVITYMISSILE
#define GRAVITYMISSILE
#include <QGraphicsPixmapItem>
#include "Missile.h"
#include "mylist.h"
#include <string>

class GravityMissile : public Missile {
	
public:
	GravityMissile(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed);
	GravityMissile(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed);
	
	~GravityMissile();
	
public slots:
	void Update();

private:
		void GameTime(double time);
		double gameTime;
		
};
#endif
