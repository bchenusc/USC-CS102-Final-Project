	#include "DeadlyHamster.h"
	

DeadlyHamster::DeadlyHamster(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	type = "Enemy";
	this->speed = speed;
	setTransformOriginPoint(0,0);
		
}
	
DeadlyHamster::~DeadlyHamster(){

}

void Enemy::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	for (int i=0; i<gameObjects->size(); i++){
		if (gameObjects->at(i)->getType() == "PlayerMissile"){
			if (collidesWithItem(gameObjects->at(i))){
				gameObjects->at(i)->HandleCollision(type);
				setHealth(getHealth()-1);
				if (health<=0){
				//Implement dying here later.
					emit addScore(25);
					emit Destroy(this);
					return;
				}
			}
		}
	}
}

void Enemy::Update(){

if (gX()>680 || gX()<-100){
	emit Destroy(this);
	return;
}

//Animate the enemy
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
//------------------------

	//Shoot bullets
	if (spawnBulletCounter<=0){
		spawnBulletCounter = RspawnBulletCounter;
		//Make a new bullet.
		if (isFlipped()){
			for (int i=0; i<numberOfBullets; i++){
				emit Spawn(0, gX()-40, gY()+30, shootSpeed);
			}
		}
		else {
			for (int i=0; i<numberOfBullets; i++){
				emit Spawn(0,gX()+20, gY()+30, shootSpeed);
				}
		}
	}
	if(spawnBulletCounter>0){
		spawnBulletCounter--;
	}

	// Move in a set direction.
	MoveDir(moveToPositionX,moveToPositionY,speed);
}

void Enemy::setPlayerRef(Player* player){
	playerRef = player;
}
	
int Enemy::getHealth(){
	return health;
}

void Enemy::setHealth(int health){
	this->health = health;
}

void Enemy::setNumOfBullets(int num){
	numberOfBullets=num;
}

void Enemy::setRSpawnBulletCounter(int num){
	RspawnBulletCounter = num;
}












