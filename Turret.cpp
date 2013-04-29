	#include "Turret.h"
	
Turret::Turret(int nx, int ny, int nz, QPixmap* pixmap, Player* player): GameObject( nx,  ny, nz, pixmap){
	type="Turret";
	this->player = player;
	flipImg(true);
	setTransformOriginPoint(18,59);
	shootSpeed=0.5;
	
	//Cooldown timers
	shootCounter =0;
	RshootCounter = 800;
}
	
Turret::~Turret(){

}

void Turret::setLockX(int nx){
	lockX=nx;
}

void Turret::setLockY(int ny){
	lockY=ny;
}

void Turret::mousePressed(int mx, int my){
	if (shootCounter==0){
		shootCounter=RshootCounter;
		if ((mx>player->gX() && my >player->gY()) || (mx<player->gX() && my>player->gY())){
			emit addScore(-5);
			emit Spawn(2, mx, my, shootSpeed*2);
			return;
			}
		else{
			emit addScore(-5);
			emit Spawn(2,mx, my, -shootSpeed*2);
		return;
		}
	}
}

void Turret::mouseFollow(int mx, int my){
	int mouseX = mx;
	int mouseY = my;
	double pi = 3.14159;
	double theta=rotation();

//Calculate the angle made by the player's x-axis.
	if (mouseX > player->gX() && mouseY<player->gY()){
		theta = acos((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))+pi;
	}
	else
	if (mouseX>player->gX() && mouseY>player->gY())theta =-asin((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))-pi/2;
	else 
		theta = -acos((mouseY-player->gY())/(double)sqrt((double)pow(mouseY-player->gY(),2) + pow(mouseX-player->gX(),2)))+pi;

//Rotating the turret using the angle made by the player's x-axis.
	setRotation(theta*180/pi);
}

void Turret::Update(){
	//Follow the player
	setPos(player->gX()+lockX, lockY);
	x = player->gX()+lockX;
	y=player->gY()+lockY;
	
	if(shootCounter>0){
		shootCounter--;
	}
}

void Turret::OnCollisionEnter(MyList<GameObject*>* gameObjects){

}
