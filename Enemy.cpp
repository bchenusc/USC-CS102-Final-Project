	#include "Player.h"
	
Enemy::Enemy(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=32;
	anim = animation;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	this->speed = speed;
}
	
Enemy::~Enemy(){

}

void Enemy::Update(){
//Animate the player
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
	
	MoveTowards(moveToPositionX,moveToPositionY,speed);
	
}
	
int Player::getHealth(){
	
}
int Player::getLives(){
	
}
int Player::getScore(){
	
}
void Player::setLives(int life){
	
}
void Player::setHealth(int health){
	
}
void Player::setScore(int score){
	
}
