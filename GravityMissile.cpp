	#include "GravityMissile.h"
	
GravityMissile::GravityMissile(int nx, int ny, int nz, QPixmap* pixmap, MyList<QPixmap*>* animation, int moveToX, int moveToY, double speed): Missile( nx,  ny,  nz,  pixmap, animation,  moveToX,  moveToY,  speed){
	gameTime=0;
}

GravityMissile::GravityMissile(int nx, int ny, int nz, QPixmap* pixmap, int moveToX, int moveToY, double speed): Missile( nx,  ny,  nz,  pixmap,  moveToX,  moveToY,  speed){
	gameTime=0;
}
	
GravityMissile::~GravityMissile(){

}

GravityMissile::GameTime(double time){
//Sets gameTime to time in seconds.
	gameTime = time/1000;
}

void GravityMissile::Update(){
	//if the missile goes out of bounds, then destroy the Gravity missle.
	if (gX()<= -1000 || gX()>=1500|| gY()<= -1000 || gY()>=1000){
			emit Destroy(this);
	}

	//Tweek this to set a different location where the missile explodes when hitting the ground.
	if (gY()>=385){
		emit Destroy(this);
		return;
	}
	else{
	
//Animate the misssile if ther is an animation given.
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






















