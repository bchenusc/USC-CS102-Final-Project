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
	
	//Ratio of deltaY/deltaX = speedY/speedX
	//speed = sqrt(speedY^2 + speedX^2)
	//speed^2 = speedY^2 + speedX^2
	//speedY = deltY/deltX * speedX
	//speed^2 = (deltY/deltX)^2 * (speedX)^2 + (speedX)^2
	//speed^2/(deltY/deltX)^2 + 1) = (speedX)^2
	
	if (x==0 && y!=0 && y>0){
		moveBy(0, speed);
		this->x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (x==0 && y!=0 && y<0){
		moveBy(0, -speed);
		x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (y==0 && x!=0 && x>0){
		moveBy(speed, 0);
		x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (y==0 && x!=0 && x<0){
		moveBy(-speed, 0);
		this->x=QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}
	if (y==0 && x==0){
		x = QGraphicsItem::x();
		y = QGraphicsItem::y();
		return;
	}

	
}

//SLOTS
void GameObject:: Update(){

}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
