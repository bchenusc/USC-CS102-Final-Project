#ifndef MAINVIEW
#define MAINVIEW

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class MainView : public QGraphicsView {
    Q_OBJECT
    
public:
     MainView(QGraphicsScene* scene);
    ~MainView();
    void mouseMoveEvent(QMouseEvent* mouseEvent);
   	void mousePressEvent(QMouseEvent* mouseEvent);
    
signals:
	void mouse(int, int);
	void mousePressed(int, int);

};

#endif // MAINWINDOW_H
