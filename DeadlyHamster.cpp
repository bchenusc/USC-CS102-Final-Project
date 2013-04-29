	#include "DeadlyHamster.h"
	

DeadlyHamster::DeadlyHamster(int nx, int ny, int nz, QPixmap* pixmap, double speed):GameObject( nx,  ny, nz, pixmap){
	type = "EnemyHamster";
	this->speed = speed;
	setTransformOriginPoint(0,0);
}
	
DeadlyHamster::~DeadlyHamster(){

}

void DeadlyHamster::HandleCollision(string type){
	if (type == "Player"){
		Destroy(this);
		return;
	}
}

void DeadlyHamster::OnCollisionEnter(MyList<GameObject*>* gameObjects){
	for (int i=0; i<gameObjects->size(); i++){
		if (gameObjects->at(i)->getType() == "PlayerMissile"){
			if (collidesWithItem(gameObjects->at(i))){
					gameObjects->at(i)->HandleCollision(type);
					emit addScore(10);
					emit Destroy(this);
					return;
				}
			}
		}
}

void DeadlyHamster::Update(){

if (gX()>680 || gX()<-100){
	emit Destroy(this);
	return;
}

	// Move in a set direction.
	MoveDir(-1,0,speed);
}










