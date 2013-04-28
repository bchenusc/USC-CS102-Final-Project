	#include "Missile.h"
	
Missile::Missile(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=70;
	anim = animation;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	this->speed = speed;
	type = "Missile";
	setRotation(-90);
}

Missile::Missile(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed):GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=70;
	anim=NULL;
	animationFrame=0;
	moveToPositionX=moveToX;
	moveToPositionY=moveToY;
	this->speed=speed;
	type="Missile";
	setRotation(-90);
}
	
Missile::~Missile(){

}

void Missile::HandleCollision(string type){
	//Explosion here if needed.
	if (type=="Player"){
		explosion();
	}
}

void Missile::explosion(){
	emit Destroy(this);
}

void Missile::OnCollisionEnter(MyList<GameObject*>* gameObjects){

}

void Missile::Update(){

	//Tweek this to set a different location where the missile explodes when hitting the ground.
	if (gY()>=385){
		emit Destroy(this);
		return;
	}
	else{
	
//Animate the player
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
	}
	//move missile towards target location most probably the player.
	MoveDir(moveToPositionX,moveToPositionY,speed);

}






















