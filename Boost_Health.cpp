	#include "Boost_Health.h"

Boost_Health::Boost_Health(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	initialX = nx;
	initialY = ny;
	type = "Boost_Health";
	
	isMovingLeft = true;
		
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
	
	if (isMovingLeft && gX()<initialX-50){
	cout<<isMovingLeft<<1<<endl;
	//Too Far left
		isMovingLeft = false;
		MoveDir(1,-1, speed*1.5);
	}else
	if (!isMovingLeft && gX()>initialX+50){
	//Too far right
		isMovingLeft = true;
		MoveDir(-1,-1,speed*1.5);
	}else
	if (isMovingLeft && gX()>initialX-50){
		MoveDir(1,-1, speed*1.5);
	}else
	if (!isMovingLeft && gX()<initialX+50){
		MoveDir(-1,-1,speed*1.5);
	}else
	//If hit the ground then destroy.
	if (gX()>=430)
	{
		Destroy(this);
		return;
	}
}













