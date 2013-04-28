#include "mainview.h"

MainView::MainView(QGraphicsScene* scene) : QGraphicsView(scene){

} 

MainView::~MainView(){

}

void MainView::mouseMoveEvent(QMouseEvent* mouseEvent){
	emit mouse(mouseEvent->x(), mouseEvent->y());
}

void MainView::mousePressEvent(QMouseEvent* mouseEvent){
	emit mousePressed(mouseEvent->x(), mouseEvent->y());
}
