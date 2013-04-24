#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QValidator>
#include <QGroupBox>

#include "GameObject.h"
#include "Player.h"

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 500


class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    
public slots:
    void handleTimer();
    void toggleTimer();
    void startClicked();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGridLayout *mainWin;
    
    QLineEdit *nameBar;
    QTextEdit *systemChat;
    
    QTimer *pregameTimer;
    QTimer *mainTimer;
    vector<QPixmap*> pix;
    vector<GameObject*> gameObjects;
    
};

#endif // MAINWINDOW_H
