	#include "Player.h"
	
Player::Player(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=32;
	anim = animation;
	animationFrame=0;
	
	moveSpeed=4;
}
	
Player::~Player(){

}

void Player::keyPressed(QKeyEvent* key){
	if (key->key() == Qt::Key_A){

		MoveDir(-20,  0,  moveSpeed/2);
	}else
	if (key->key() == Qt::Key_D){
		MoveDir( 20,  0,  moveSpeed);
	}else
	if (key->key() == Qt::Key_W){
	
	}
}

void Player::Update(){
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
