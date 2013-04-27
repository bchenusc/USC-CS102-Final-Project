	#include "Enemy.h"
	
Enemy::Enemy(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=50;
	anim = animation;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	this->speed = speed;
}

Enemy::Enemy(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed):GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=64;
	anim=NULL;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	this->speed=speed;
}
	
Enemy::~Enemy(){

}

void Enemy::Update(){
//Animate the player
	if (anim!=NULL){
		if (animationCounter<=0){
			animationCounter=RanimationCounter;
			if (animationFrame<anim->size()){
				setPixmap(*(anim->at(animationFrame)));
			}
			else{
				animationFrame=-1;
			}	
			animationFrame++;
		}
		if (animationCounter>0){
			animationCounter--;

		}
	}
	MoveDir(moveToPositionX,moveToPositionY,speed);
	
}
	
int Enemy::getHealth(){
	
}

void Enemy::setHealth(int health){
	
}

