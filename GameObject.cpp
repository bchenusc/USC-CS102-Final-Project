#include "GameObject.h"

GameObject::GameObject(int nx, int ny,int nz, QPixmap* pixmap): QGraphicsPixmapItem(*pixmap){
	  x = nx;
    y = ny;
    setPos(x,y);
    setZValue(nz);
    vx=0;
    vy=0;
    this->pixmap = pixmap;
    dirX=0;
    dirY=0;
}
GameObject::~GameObject(){
	
}
int GameObject::gX(){
		return x;
}
int GameObject::gY(){
	return y;
}
int GameObject:: gVX(){
	return vx;
}
int GameObject:: gVY(){
	return vy;
}
bool GameObject:: isFlipped(){
	return flipHorizontal;
}
void GameObject:: flipImg(){
	flipHorizontal=true;
	//Creating a transformation matrix. Yay linear algebra.
	QTransform transform(this->transform());
	
	transform.setMatrix(-transform.m11(), transform.m12(),transform.m13(),transform.m21(),transform.m22(),transform.m23(),transform.m31(),transform.m32(),transform.m33());
	setTransform(transform);
	setRotation(0);
}



void GameObject:: MoveTowards(double x, double y, double speed){
	//Find the Vector2 direction.
	int deltaX = x-gX();
	int deltaY = y-gY();
	
	double pi = 3.14159;
	
	double theta=0;
	
	if (deltaY!=0)
	theta = atan(deltaX/(double)deltaY)*180/pi;

	
	double vX = sin(theta*pi/180)*speed;
	double vY = cos(theta*pi/180)*speed;
	
	if (abs(deltaX)<=1){
		deltaX=0;
	}
	if (abs(deltaY)<=1){
		deltaY=0;
	}

	moveBy(vX, vY);
	this->x = QGraphicsItem::x();
	this->y = QGraphicsItem::y();

}

void GameObject:: MoveDir(double deltaX, double deltaY, double speed){

	double pi = 3.14159;
	double theta = atan(deltaX/(double)deltaY)*180/pi;
	
	 vx = sin(theta/180*pi)*speed;
	 vy = cos(theta/180*pi)*speed;
	
	if (deltaX==0 && deltaY!=0 && deltaY>0){
		vx=0;
		vy=speed;
		moveBy(0, speed);
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaX==0 && deltaY!=0 && deltaY<0){
		vx=0;
		vy=-speed;
		moveBy(0, -speed);
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX!=0 && deltaX>0){
		vx = speed;
		vy=0;
		moveBy(speed, 0);
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX!=0 && deltaX<0){
		vx= -speed;
		vy=0;
		moveBy(-speed, 0);
		this->x=QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX==0){
		vx=0;
		vy=0;
		this->x = QGraphicsItem::x();
		this->y = QGraphicsItem::y();
		return;
	}
	
	moveBy(vx, vy);
	this->x = QGraphicsItem::x();
	this->y = QGraphicsItem::y();

	
}

//SLOTS
void GameObject:: Update(){

}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
