#include "GameObject.h"

GameObject::GameObject(int nx, int ny,int nz, QPixmap* pixmap): QGraphicsPixmapItem(*pixmap){
	  x = nx;
    y = ny;
    setPos(x,y);
    setZValue(nz);
    vx=0;
    vy=0;
    this->pixmap = pixmap;
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
	
}
void GameObject:: MoveTowards(double x, double y, double speed){

}

void GameObject:: MoveDir(double x, double y, double speed){

	//Find the Vector2 direction.
	int deltaX = x-gX();
	int deltaY = x-gY();
	
	double theta = atan(deltaX/(double)deltaY);
	
	vX = sin(theta)*speed;
	vY = sin(theta)*speed;
	
	if (deltaX==0 && deltaY!=0 && deltaY>0){
		moveBy(0, speed);
		this->x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (deltaX==0 && deltaY!=0 && deltaY<0){
		moveBy(0, -speed);
		x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX!=0 && deltaX>0){
		moveBy(speed, 0);
		x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX!=0 && deltaX<0){
		moveBy(-speed, 0);
		this->x=QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (deltaY==0 && deltaX==0){
		x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	
	moveBy(speedX, speedY);
	x = QGraphicsItem::x();
	y = QGraphicsItem::y();

	
}

//SLOTS
void GameObject:: Update(){

}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
