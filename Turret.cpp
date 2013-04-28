	#include "Turret.h"
	
Turret::Turret(int nx, int ny, int nz, QPixmap* pixmap, Player* player): GameObject( nx,  ny, nz, pixmap){
	type="Turret";
	this->player = player;
	flipImg(true);
	setTransformOriginPoint(20,70);
}
	
Turret::~Turret(){

}

void Turret::setLockX(int nx){
	lockX=nx;
}

void Turret::setLockY(int ny){
	lockY=ny;
}

void Turret::mouseFollow(int mx, int my){
	int mouseX = mx;
	int mouseY = my;
	double pi = 3.14159;
	double theta=rotation();
	
	if (mouseX > player->gX() && mouseY<player->gY()){
		theta = acos((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))+pi;
	}
	else
	if (mouseX>player->gX() && mouseY>player->gY())theta =-asin((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))-pi/2;
	else 
		theta = -acos((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))+pi;
	
	

	setRotation(theta*180/pi);
	
}

void Turret::Update(){
	setPos(player->gX()+lockX, lockY);
}

void Turret::OnCollisionEnter(MyList<GameObject*>* gameObjects){

}
