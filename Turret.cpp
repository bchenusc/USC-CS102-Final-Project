	#include "Turret.h"
	
Turret::Turret(int nx, int ny, int nz, QPixmap* pixmap): GameObject( nx,  ny, nz, pixmap){
	animationSpeed=1;
	animationCounter=0;
	RanimationCounter=32;
	animationFrame=0;
	type="Turret";
}
	
Turret::~Turret(){

}

void Turret::mouseFollow(QGraphicsSceneMouseEvent* event){
	int mouseX = event->scenePos().x();
	int mouseY = event->scenePos().y();
	double pi = 3.14159;
	double theta = atan((mouseX-gX())/(double)(mouseY-gY()))*180/pi;
	setRotation(theta);
	
}

void Turret::Update(){
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

void Turret::OnCollisionEnter(MyList<GameObject*>* gameObjects){

}
