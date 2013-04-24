#include "GameObject.h"

GameObject::GameObject(int nx, int ny, int w, int h, QPixmap* pixmap): QGraphicsPixmapItem(*pixmap){
	  x = nx;
    y = ny;
    setPos(x,y);
    width = w;
    height = h;
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
void GameObject:: MoveTowards(int x, int y, int speed){

}
void GameObject:: MoveDir(int x, int y, int speed){

}

//SLOTS
void GameObject:: Update(){

}
void GameObject:: OnCollisionEnter(){

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
