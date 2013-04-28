#include "Background.h"

Background::Background(int nx, int ny, int nz, QPixmap* pixmap):GameObject( nx,  ny, nz, pixmap){
	speed=1;
	type="Background";
}
Background::~Background(){

}
void Background:: Update(){
	MoveDir(-1,0,0.5*speed);
	if (gX()<= -1000 || gX()>=1500|| gY()<= -1000 || gY()>=1000){
			emit Destroy(this);
	}
}

void Background::setSpeed(int i){
	speed = i;
}

void Background::OnCollisionEnter(MyList<GameObject*>* gameObjects){

}
