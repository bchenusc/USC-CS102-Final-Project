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
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QValidator>
#include <QGroupBox>
#include <QFrame>
#include <QGraphicsSimpleTextItem>
#include <QMouseEvent>


#include <time.h>
#include <stdlib.h>


#include "GameObject.h"
#include "Background.h"
#include "mylist.h"
#include "Player.h"
#include "Enemy.h"
#include "Missile.h"
#include "Turret.h"
#include "mainview.h"
#include "Boost_Health.h"
#include "DeadlyHamster.h"


#include "iostream"
using namespace std;


#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
     MainWindow();
    ~MainWindow();
    void keyPressEvent(QKeyEvent* key);
    
signals:
	void CollisionChecker(MyList<GameObject*>* gameObjects);
    
public slots:
    void handleTimer();
    void toggleTimer();
    void startClicked();
    void Destroy(GameObject *toDestroy);
    void Spawn(int type, int x, int y, double newSpeed);
    void Lose();
    void changeHealthBar(int change);
    void handleMouse(int mx, int my);
   	void mousePressed(int x, int y);
   	void AddToScore(int nScore);
    
private:
		
		bool playerIsDead;
		bool startIsClicked;
		bool playerIsSpawned;
		bool gameIsPaused;
		
		void spawnNewUI();
		
    QGraphicsScene *scene;
    MainView *view;
    QGridLayout *mainWin;
    
    QLineEdit *nameBar;
    QTextEdit *systemChat;
    
    //Buttons / UI
    QPushButton *start;
    GameObject* healthBar;
    QGraphicsSimpleTextItem* healthLabel;
    GameObject* introPic;
    QLabel *scoreNumLabel;
    
    //Timers
    QTimer *mainTimer;
    
    //Pics and Objects
    MyList<QPixmap*> pix;
    MyList<GameObject*> gameObjects;
    
    //Player && Turret
    Player* mainPlayer;
    Turret* mainTurret;
    int score;
    
    //Animations
    MyList<QPixmap*>* playerAnim;
    MyList<QPixmap*>* enemyAnim;
    
    //Settings
    double gameSpeed;
    int gameTime;
    int numberOfBulletsSpawnedByEnemies;
    
    int bgSpawnCounter;
    int RbgSpawnCounter;
    
    int RenemySpawnCounter;
    int enemySpawnCounter;
    
    GameObject* losePic;
    
};

#endif // MAINWINDOW_H
