#ifndef MAINVIEW
#define MAINVIEW

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

#include "iostream"
using namespace std;


class MainView : public QGraphicsView {
    Q_OBJECT
    
public:
     MainView(QGraphicsScene* scene);
    ~MainView();
    void mouseMoveEvent(QMouseEvent* mouseEvent);
    
signals:
	void mouse(int, int);

};

#endif // MAINWINDOW_H
