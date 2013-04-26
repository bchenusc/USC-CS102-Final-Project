	#include "Player.h"
	
Player::Player(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=30;
	anim = animation;
	animationFrame=0;
}
	
Player::~Player(){
	//delete [] anim;
}

void Player::Update(){
	if (animationCounter<=0){
		animationCounter=RanimationCounter;
		//cout<<animationFrame<<endl;
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
