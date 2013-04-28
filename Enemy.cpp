	#include "Enemy.h"
	
Enemy::Enemy(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	anim = animation;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	type = "Enemy";
	
	this->speed = speed;
	shootSpeed=0.2;
	
	
	
	//Counters
	animationCounter=0;
		RanimationCounter=70;
	spawnBulletCounter=800;
		RspawnBulletCounter=800;
		
		setTransformOriginPoint(0,0);
}

Enemy::Enemy(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed):GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;

	anim=NULL;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	type = "Enemy";
	
	this->speed = speed;
	shootSpeed=0.2;
	
	
	//Counters
	animationCounter=0;
		RanimationCounter=70;
	spawnBulletCounter=800;
		RspawnBulletCounter=800;
		
		setTransformOriginPoint(0,0);
}
	
Enemy::~Enemy(){

}

void Enemy::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	
}

void Enemy::Update(){

if (gX()>680 || gX()<-100){
	Destroy(this);
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
			emit Spawn(0, gX()-40, gY()+40, shootSpeed);
		}
		else {emit Spawn(0,gX()+20, gY()+40, shootSpeed);}
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

