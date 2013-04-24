#include "Background.h"

Background::Background(int nx, int ny, int w, int h, QPixmap* pixmap):GameObject( nx,  ny,  w, h, pixmap){

}
Background::~Background(){

}
void Background:: Update(){
	MoveDir(-1,0,0.5);
	cout<<gX()<<endl;
	if (gX()<=-50){
	//Destroy Self.
		cout<<"YAY"<<endl;
		return;
	}
}
