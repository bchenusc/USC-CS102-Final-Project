	#include "Boost_Health.h"

Boost_Health::Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	initialX = nx;
	initialY = ny;
	type = "HealthBoost";
	
	isMovingLeft = true;
		
	setTransformOriginPoint(0,0);
	
	this->speed = speed;
}
	
Boost_Health::~Boost_Health(){

}

void Boost_Health::setPlayerRef(Player *player){
	playerRef = player;
}


void Boost_Health::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	for (int i=0; i<gameObjects->size(); i++){
		if (gameObjects->at(i)->getType() == "PlayerMissile"){
			if (collidesWithItem(gameObjects->at(i))){
				gameObjects->at(i)->HandleCollision(type);
				playerRef->setHealth(playerRef->getHealth()+1);
				emit changeHealth(playerRef->getHealth());
				emit Destroy(this);
				return;
				}
			}
		}
}

void Boost_Health::Update(){

if (gX()>680 || gX()<-100){
	emit Destroy(this);
	return;
}

//------------------------
//Health oscillates horizontally moving between + or - 50 from its original location.
//disappears if the health touches the ground.
	
	if (isMovingLeft && (gX()<=initialX-150 ||gX()<=5)){
	//Too Far left
		isMovingLeft = false;
		MoveDir(1,-1, speed);
	}else
	if (!isMovingLeft && (gX()>=initialX+150 || gX()>=450)){
	//Too far right
		isMovingLeft = true;
		MoveDir(-1,-1,speed);
	}else
	if (isMovingLeft && gX()>initialX-150){
	//Moving Left
		MoveDir(1,-1, speed);
	}else
	if (!isMovingLeft && gX()<initialX+150){
		MoveDir(-1,-1,speed);
	}
	//If hit the ground then destroy.
	if (gY()>=400)
	{
		Destroy(this);
		return;
	}
}













