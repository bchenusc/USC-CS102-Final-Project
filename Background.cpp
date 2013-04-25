#include "Background.h"

Background::Background(int nx, int ny, int nz, QPixmap* pixmap):GameObject( nx,  ny, nz, pixmap){

}
Background::~Background(){

}
void Background:: Update(){
	MoveDir(-1,0,0.5);
	if (gX()<= -460 || gX()>=700 || gY()<= -1000 || gY()>=550){
			emit Destroy(this);
	}
}
