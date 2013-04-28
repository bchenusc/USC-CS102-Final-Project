	#include "Turret.h"
	
Turret::Turret(int nx, int ny, int nz, QPixmap* pixmap, Player* player): GameObject( nx,  ny, nz, pixmap){
	type="Turret";
	this->player = player;
	setTransformOriginPoint(20,78);
}
	
Turret::~Turret(){

}

void Turret::mouseFollow(int mx, int my){
	int mouseX = mx;
	int mouseY = my;
	double pi = 3.14159;
	double theta = atan((mouseX-gX())/(double)(mouseY-gY()));
	if (my<gY()-80)
	setRotation(-theta*180/pi);
	
}

void Turret::Update(){
	setPos(player->gX(), player->gY());
}

void Turret::OnCollisionEnter(MyList<GameObject*>* gameObjects){

}
