#include "mainwindow.h"


void MainWindow::handleTimer() {
	
	emit CollisionChecker(&gameObjects);
	
	//Keep spawning backgrounds;
	if (bgSpawnCounter<=0){
		bgSpawnCounter=RbgSpawnCounter;
		Background* background = new Background(1279,0, -10, pix[0]);
		background->setSpeed(1);
		QObject::connect(background, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
		connect(mainTimer, SIGNAL(timeout()), background, SLOT(Update()));
		connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), background, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
		scene->addItem(background);
		gameObjects.push_back(background);
	}
	
	//Spawn enemies
	if (startIsClicked && !playerIsDead){
			if (enemySpawnCounter<=0){
				enemySpawnCounter = RenemySpawnCounter;
				Enemy* enemy;
				//Randomize between spawning left or right. Right=1, Left=2
				int random = rand()%2+1;
				if (random==1){
					//Spawn planes on the right side of the screen.
					enemy = new Enemy(679, rand()%250+2, 0, pix[4], enemyAnim, -1, 0, gameSpeed/6*(rand()%2+1)/10, gameSpeed/10+0.05);
						//Change Enemy Settings if needed.
						enemy->flipImg(false);
						enemy->setPlayerRef(mainPlayer);
						enemy->setNumOfBullets(numberOfBulletsSpawnedByEnemies);
						enemy->setRSpawnBulletCounter(1000 - gameSpeed*100);
					QObject::connect(enemy, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
					QObject::connect(enemy, SIGNAL(Spawn(int, int, int, double)), this, SLOT(Spawn(int, int, int, double)));
					connect(mainTimer, SIGNAL(timeout()), enemy, SLOT(Update()));
					connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), enemy, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
						//Add Enemy to the Scene
					scene->addItem(enemy);
					gameObjects.push_back(enemy);
				}else
				if (random==2){
					//Spawn planes on the left side of the screen.
					enemy = new Enemy(-30, rand()%250+2, 0, pix[4], enemyAnim, 1, 0, gameSpeed/6*(rand()%2+1)/10,gameSpeed/10+0.05);
						//Change Enemy Settings if need be.
						enemy->flipImg(true);
						enemy->setPlayerRef(mainPlayer);
						enemy->setNumOfBullets(numberOfBulletsSpawnedByEnemies);
						enemy->setRSpawnBulletCounter(1000 - gameSpeed*100);
					QObject::connect(enemy, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
					QObject::connect(enemy, SIGNAL(Spawn(int, int, int, double)), this, SLOT(Spawn(int, int, int, double)));
					connect(mainTimer, SIGNAL(timeout()), enemy, SLOT(Update()));
					connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), enemy, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
						//Add enemy to the scene
					scene->addItem(enemy); 
					gameObjects.push_back(enemy);
				}
			}
		}
		

		
	//increaseSpeed of spawn, bullets every 10 seconds
	//also spawn a health boost.
	if (gameTime%(1000*15)==0 && gameTime>(1000*15)){
		numberOfBulletsSpawnedByEnemies++;
		gameSpeed = gameSpeed+ (1+(gameTime/pow((1000*10),2)/10));
		
		//Spawn a health boost every 15 seconds.
		cout<<"Spawned health"<<endl;
					Boost_Health* healthboost = new Boost_Health(679, rand()%250+2, 0, pix[23], gameSpeed/6*(rand()%2+1)/10);
						//Change boost settings if needed.
						healthboost->setPlayerRef(mainPlayer);
					QObject::connect(healthboost, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
					connect(mainTimer, SIGNAL(timeout()), healthboost, SLOT(Update()));
						//Add boost to the Scene
					scene->addItem(healthboost);
					gameObjects.push_back(healthboost);
	}
	
	
	//Update all the timer counter variables
	if (bgSpawnCounter>0){
		bgSpawnCounter--; 
	}
	if (enemySpawnCounter>0){
		enemySpawnCounter--;
	}
	
	if (startIsClicked)
		gameTime++;
}

void MainWindow:: Destroy(GameObject* toDestroy){

	gameObjects.remove(toDestroy);
	
	scene->removeItem(toDestroy);
	
	delete toDestroy;
}

void MainWindow::Lose(){
	playerIsDead=true;
	gameTime=1;
	
	int atPosition=0;
	int objectsLeftToCheck = gameObjects.size();
	
	while(objectsLeftToCheck>0){
			if (gameObjects.at(atPosition)->getType()!="Player" && gameObjects.at(atPosition)->getType()!="Background"){
				Destroy (gameObjects.pop(atPosition));
				objectsLeftToCheck--;
			}
			else {
				objectsLeftToCheck--;
				atPosition++;
			}
	}
	if (playerIsSpawned){
		Destroy(mainPlayer);
		playerIsSpawned=false;
		delete healthLabel;
	}
}

void MainWindow::Spawn(int type, int xPos, int yPos, double speed){

	switch(type){
//0 - Missile
		case 0: 
		{
			Missile* newMissile = new Missile(xPos, yPos, 1, pix[16], rand()%500-xPos, 400, speed); 
			QObject::connect(newMissile, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
			newMissile->setType("EnemyMissile");
			connect(mainTimer, SIGNAL(timeout()), newMissile, SLOT(Update()));
			connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), newMissile, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
			scene->addItem(newMissile); 
			gameObjects.push_back(newMissile);
			break;
		}
//Turret		
		case 1:
		{
			Turret* myTurret = new Turret(xPos, yPos, -1, pix[22], mainPlayer);
			mainTurret = myTurret;
			mainTurret->setLockX(xPos);
			mainTurret->setLockY(yPos);
			QObject::connect(myTurret, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
			QObject::connect(myTurret, SIGNAL(Spawn(int, int , int , double)), this, SLOT(Spawn(int, int ,int ,double)));
			connect(mainTimer, SIGNAL(timeout()), myTurret, SLOT(Update()));
			scene->addItem(myTurret); 
			gameObjects.push_back(myTurret);
			break;
		}
//Spawn Player Bullets	
		case 2:
		{
			Missile* playerMissile = new Missile(mainPlayer->gX()+10, mainPlayer->gY()+13, -2, pix[24], xPos-mainPlayer->gX()-1, yPos-mainPlayer->gY()+13, speed);
			playerMissile->setType("PlayerMissile"); 
			QObject::connect(playerMissile, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
			connect(mainTimer, SIGNAL(timeout()), playerMissile, SLOT(Update()));
			connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), playerMissile, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
			scene->addItem(playerMissile); 
			gameObjects.push_back(playerMissile);
			break;
		}

		default: break;
	}
}

MainWindow::MainWindow() {
		QFrame *frame = new QFrame();
		setCentralWidget(frame);
		
		//------------------------------------------------------------------------------------------    

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    mainTimer = new QTimer(this);
    mainTimer->setInterval(1);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(handleTimer()));

		//Set the main window size.
		setFixedSize(1000,530);

    //We need a scene and a view to do graphics in QT
    mainWin = new QGridLayout();	//This is your main layout bg window.
    scene = new QGraphicsScene(0,0,WINDOW_MAX_X, WINDOW_MAX_Y);
    view = new MainView( scene );
    QObject::connect(view, SIGNAL(mouse(int,int)), this, SLOT(handleMouse(int, int)));
    QObject::connect(view, SIGNAL(mousePressed(int,int)), this, SLOT(mousePressed(int, int)));
    mainWin->addWidget(view, 0, 0, 10, 1);
    
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X+2, WINDOW_MAX_Y+2);
    view->setWindowTitle( "Sheep With A Turret");
    
    frame->setLayout(mainWin);
    
//------------------------------------------------------------------------------------------

		//Create Group Boxes:	
		QGroupBox* profileGB = new QGroupBox(tr("Profile"));
		QGroupBox* gameGB = new QGroupBox(tr("Options"));
		QGroupBox* sysGB = new QGroupBox(tr("System"));
		
		//Create Layouts for Group Boxes
		QGridLayout *profileLO = new QGridLayout();
		QGridLayout *gameLO = new QGridLayout();
		QGridLayout *sysLO = new QGridLayout();

			//Set the Layouts
			profileGB->setLayout(profileLO);
			gameGB->setLayout(gameLO);
			sysGB->setLayout(sysLO);
			
			//Add the Layouts
			mainWin->addWidget(profileGB,1,1,1,2);
			mainWin->addWidget(gameGB, 2,1,1,2);
			mainWin->addWidget(sysGB, 3,1,1,2);

    //Create a Start button.
    start = new QPushButton("Start"); 
    QObject::connect(start, SIGNAL(clicked()), this, SLOT(startClicked()));
    gameLO->addWidget(start, 1,0,1,1);
    
    //Create a Pause button.
    QPushButton *pause = new QPushButton("Pause"); 
    QObject::connect(pause, SIGNAL(clicked()), this, SLOT(toggleTimer()));
    gameLO->addWidget(pause, 2,0,1,1);
    
    //Create a message box.
    systemChat = new QTextEdit();
    sysLO->addWidget(systemChat,0,0,2,1);
    systemChat->setReadOnly(true);
    
    //Labels the namebar
    QLabel *nameLabel = new QLabel("Name:");
    profileLO->addWidget(nameLabel,0,0,1,1);
    
    //Create name bar
    nameBar = new QLineEdit();
    nameBar->setMaxLength(13);
    nameBar->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]{0,255}")));
    profileLO->addWidget(nameBar,0,1,1,1);
    nameBar->clear();
    
//Game settings
		gameSpeed = 1;
		gameTime = 0;
		startIsClicked = false;
		playerIsDead = false;
		numberOfBulletsSpawnedByEnemies = 1;
    
//Load All Images
		//0 : Background img.
		QPixmap *bgImg = new QPixmap ("sprites/background_1.png");
		pix.push_back(bgImg);
		//1-5 : Player Run Animation.
		playerAnim = new MyList<QPixmap*>();
			playerAnim->push_back(new QPixmap("sprites/player_01.png"));
			playerAnim->push_back(new QPixmap("sprites/player_03.png"));
			playerAnim->push_back(new QPixmap("sprites/player_02.png"));
			playerAnim->push_back(new QPixmap("sprites/player_03.png"));
			playerAnim->push_back(new QPixmap("sprites/player_01.png"));
			for(int i=0; i<5; i++){
				pix.push_back(playerAnim->at(i));
			}
		//6-15 : Enemy Animation
		enemyAnim = new MyList<QPixmap*>();
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_01.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_02.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_03.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_04.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_05.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_05.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_04.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_03.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_02.png"));
			enemyAnim->push_back(new QPixmap("sprites/enemy_plane_01.png"));
			for(int i=0; i<10; i++){
				pix.push_back(enemyAnim->at(i));
			}
			//16 : Missile
			pix.push_back(new QPixmap("sprites/missile_type01_01.png"));
			//17-20 : Health Bars
			pix.push_back(new QPixmap("sprites/HealthBar_01.png"));
			pix.push_back(new QPixmap("sprites/HealthBar_02.png"));
			pix.push_back(new QPixmap("sprites/HealthBar_03.png"));
			pix.push_back(new QPixmap("sprites/HealthBar_04.png"));
			//21 : Intro Picture / wooden board.
			pix.push_back(new QPixmap("sprites/introPic.png"));
			//22 : Cannon / turret pic.
			pix.push_back(new QPixmap("sprites/turret_01.png"));
			//23 : health boost icon
			pix.push_back(new QPixmap("sprites/healthboost.png"));
			//24 : player bullet
			pix.push_back(new QPixmap("sprites/playerbullet.png"));
    
//CREATE SCROLLY BACKGROUND

		Background* background = new Background(0,0, 10, bgImg);
		background->setSpeed(gameSpeed);
		QObject::connect(background, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
		QObject::connect(mainTimer, SIGNAL(timeout()), background, SLOT(Update()));
		
		QObject::connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), background, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
		scene->addItem(background);
		gameObjects.push_back(background);
		
		Background* background2 = new Background(640,0, -10, bgImg);
		background2->setSpeed(gameSpeed);
		QObject::connect(background2, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
		QObject::connect(mainTimer, SIGNAL(timeout()), background2, SLOT(Update()));
		QObject::connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), background2, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
		scene->addItem(background2);
		gameObjects.push_back(background2);
		
		introPic = new GameObject(100,20, 0, pix[21]);
		QObject::connect(introPic, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
		scene->addItem(introPic);
		gameObjects.push_back(introPic);

		spawnNewUI();
		
		RbgSpawnCounter = 1275;
		bgSpawnCounter=0;
		
		RenemySpawnCounter=5000;
		enemySpawnCounter=0;
		
		Boost_Health* healthboost = new Boost_Health(200, 0, 0, pix[23], gameSpeed/6*(rand()%2+1)/10);
						//Change boost settings if needed.
						healthboost->setPlayerRef(mainPlayer);
					QObject::connect(healthboost, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
					connect(mainTimer, SIGNAL(timeout()), healthboost, SLOT(Update()));
						//Add boost to the Scene
					scene->addItem(healthboost);
					gameObjects.push_back(healthboost);
		
//------------------------------------------------------------------------------------------

	//!!!!!!!!!!!!!!!!!!!!!!!!!FOCUS IS SET HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		view->setFocus();
		view->setMouseTracking(true);
		srand(time(NULL));
		mainTimer->start();
		gameIsPaused=false;
}

void MainWindow::spawnNewUI(){

//Spawns the player
		Player* player = new Player(100,350,0, pix[1], playerAnim); 
		mainPlayer = player;
		QObject::connect(player, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
		QObject::connect(player, SIGNAL(Spawn(int, int,int,double)), this, SLOT(Spawn(int, int, int, double)));
		QObject::connect(player, SIGNAL(Lose()), this, SLOT(Lose()));
		QObject::connect(mainTimer, SIGNAL(timeout()), player, SLOT(Update()));	
		QObject::connect(this, SIGNAL(CollisionChecker(MyList<GameObject*>*)), player, SLOT(OnCollisionEnter(MyList<GameObject*>*)));
		player->spawnTurret();
		scene->addItem(player);
		gameObjects.push_back(player);
		playerIsSpawned=true;

//Create Health Bars:
		healthBar = new GameObject(200,420, 2, pix[17]);
		QObject::connect(healthBar, SIGNAL(Destroy(GameObject*)), this, SLOT(Destroy(GameObject*)));
		QObject::connect(mainPlayer, SIGNAL(changeHealth(int)), this, SLOT(changeHealthBar(int)));
		scene->addItem(healthBar);
		gameObjects.push_back(healthBar);
//Create a QLabel to label the health bar.
		healthLabel= new QGraphicsSimpleTextItem(nameBar->text());
		healthLabel->setPos(235,430);
		healthLabel->setZValue(2);
		scene->addItem(healthLabel);

}

void MainWindow::changeHealthBar(int newHealth){
	switch(newHealth){
		case 0: {healthBar->setPixmap(*pix[20]); break;}
		case 1: {healthBar->setPixmap(*pix[19]); break;}
		case 2: {healthBar->setPixmap(*pix[18]); break;}
		case 3: {healthBar->setPixmap(*pix[17]); break;}
		default: break;
	}
}

void MainWindow::mousePressed(int x, int y){
	if (gameIsPaused) return;
	if (!playerIsSpawned) return;
	if (!startIsClicked) return;
	mainTurret->mousePressed(x,y);
}

void MainWindow::keyPressEvent(QKeyEvent* key){
	if (gameIsPaused) return;
	if (!playerIsSpawned) return;
	if (!startIsClicked) return;
	mainPlayer->keyPressed(key);
}

//-------------------SLOTS-------------------------------------------
void MainWindow::toggleTimer(){
	if (mainTimer->isActive()){
	  mainTimer->stop();
	  gameIsPaused=true;
	}
	else {
		mainTimer->start();
		gameIsPaused=false;
	}
}

void MainWindow::handleMouse(int mx, int my){
	if (gameIsPaused) return;
	if (!playerIsSpawned) return;
	if (!startIsClicked) return;
	mainTurret->mouseFollow(mx,my);
}

void MainWindow::startClicked(){
	if (!startIsClicked){
		startIsClicked = true;
		
		//---------------------------------------------------
		//Check if nameBar was edited.
		if (nameBar->text()<=0){
		startIsClicked=false;
			systemChat->append("Please Input an Alphanumeric Name.");
			return;
		}
		healthLabel->setText(nameBar->text());
		nameBar->setReadOnly(true);
		systemChat->append("Welcome "+nameBar->text()+" to S.W.A.T.");
		systemChat->append("Your goal is to help Mr. Fluffles escape the government.");
		systemChat->append("W, A, D to move Mr. Fluffles.");
		systemChat->append("Click to shoot.");
		//Change the start button to a restart button
		start->setText("Restart");
		if (introPic!=NULL){
			Destroy(introPic);
		}
	}else
	{ 
		//Restart
		Lose();
		if (playerIsDead){
			//Spawn player and health
			spawnNewUI();
			gameSpeed=1;
     	gameTime=1;
    	 numberOfBulletsSpawnedByEnemies=1;
			playerIsDead=false;
			startIsClicked=true;
			enemySpawnCounter=0;
			playerIsSpawned=true;
		}
	}
}

MainWindow::~MainWindow()
{
    mainTimer->stop();
    //delete playerAnim;
    delete mainTimer;
    delete scene;
    delete view;
}

