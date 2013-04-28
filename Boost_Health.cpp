	#include "Boost_Health.h"

Boost_Health::Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	initialX = nx;
	initialY = ny;
	type = "Boost_Health";
	
	movingUp = true;
		
	setTransformOriginPoint(0,0);
	
	this->speed = speed;
}
	
Boost_Health::~Boost_Health(){

}

void Boost_Health::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	
}

void Boost_Health::setPlayerRef(Player *player){
	playerRef = player;
}

void Boost_Health::HandleCollision(string type){
	//Explosion here if needed.
	if (type=="PlayerMissile"){
		playerRef->setHealth(playerRef->getHealth()+1);
		emit Destroy(this);
		return;
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
	if (gX()<initialX-50){
	//Too Far left
		MoveDir(1,-1, speed);
	}
	if (gX()>initialX+50){
	//Too far right
		MoveDir(-1,-1,speed);
	}
	//If hit the ground then destroy.
	if (gX()>=430)
	{
		Destroy(this);
		return;
	}
}













