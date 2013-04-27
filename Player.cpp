	#include "Player.h"
	
Player::Player(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=32;
	anim = animation;
	animationFrame=0;
	type="Player";
	moveSpeed=4;
}
	
Player::~Player(){

}

void Player::keyPressed(QKeyEvent* key){
	if (key->key() == Qt::Key_A){
		if (gX()>5)
				MoveDir(-20,  0,  moveSpeed*3/4);
	}else
	if (key->key() == Qt::Key_D){
		if (gX()<600)
			MoveDir( 20,  0,  moveSpeed);
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

void Player::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	for (int i=0; i<gameObjects->size(); i++){
		if (gameObjects->at(i)->getType() == "Missile"){
			gameObjects->at(i)->HandleCollision(type);
			//Implement dying here later.
			
			emit Destroy(this);
		}
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
