	#include "Player.h"
	
Player::Player(int nx, int ny, int nz, QPixmap* pixmap): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=10;
}
	
Player::~Player(){
	
}

void Player::Update(){
	if (animationCounter<=0){
		animationCounter=RanimationCounter;
		
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
