	#include "Boost_Health.h"

Boost_Health::Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed):GameObject( nx,  ny, nz, pixmap){
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	type = "Boost_Health";
	
	movingUp = true;
		
	setTransformOriginPoint(0,0);
}
	
Boost_Health::~Boost_Health(){

}

void Boost_Health::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	
}

void Boost_Health::setPlayerRef(Player *player){

}

void Missile::HandleCollision(string type){
	//Explosion here if needed.
	if (type=="PlayerMissile"){
		emit Destroy(this);
	}
}

void Boost_Health::Update(){

if (gX()>680 || gX()<-100){
	emit Destroy(this);
	return;
}

//------------------------
//The health boost oscillates in the air.

	if (gY()<moveToPositionY-50){
		movingUp = false;
	}
	else movingUp = true;

	int moveHereY=0;
	if (movingUp){
		moveHereY = moveToPositionY-50; //Powerup move up.
	}
	else
		moveHereY = moveToPositionY+50; //Powerup move down.
	
	// Move in a set direction.
	MoveDir(moveToPositionX,moveHereY,speed);
}













