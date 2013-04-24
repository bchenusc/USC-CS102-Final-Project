#include "mainwindow.h"


void MainWindow::handleTimer() {
	for (unsigned int i=0; i<gameObjects.size(); i++){
		gameObjects[i]->Update();
	}
}

MainWindow::MainWindow()  {
		//Set the main window size.
		setFixedSize(1000,530);

    //We need a scene and a view to do graphics in QT
    mainWin = new QGridLayout();	//This is your main layout bg window.
    scene = new QGraphicsScene(0,0,WINDOW_MAX_X, WINDOW_MAX_Y);
    view = new QGraphicsView( scene );
    mainWin->addWidget(view, 0, 0, 10, 1);
    
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X+2, WINDOW_MAX_Y+2);
    view->setWindowTitle( "Sheep With A Turret");
    
    setLayout(mainWin);
    
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
    QPushButton *start = new QPushButton("Start"); 
    QObject::connect(start, SIGNAL(clicked()), this, SLOT(startClicked()));
    gameLO->addWidget(start, 1,0,1,1);
    
    //Create a Pause button.
    QPushButton *pause = new QPushButton("Pause"); 
    QObject::connect(pause, SIGNAL(clicked()), this, SLOT(toggleTimer()));
    gameLO->addWidget(pause, 2,0,1,1);
    
    //Create a message box.
    systemChat = new QTextEdit();
    sysLO->addWidget(systemChat,0,0,2,1);
    
    //Labels the namebar
    QLabel *nameLabel = new QLabel("Name:");
    profileLO->addWidget(nameLabel,0,0,1,1);
    
    //Create name bar
    nameBar = new QLineEdit();
    nameBar->setMaxLength(13);
    nameBar->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]{0,255}")));
    nameBar->clear();
    profileLO->addWidget(nameBar, 0,1,1,1);
    
//CREATE SCROLLY BACKGROUND

		QPixmap *bgImg = new QPixmap ("background.png");
		Background* background = new Background(0,0,640,500, bgImg);
		scene->addItem(background);
		gameObjects.push_back(background);
    

//------------------------------------------------------------------------------------------    

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    mainTimer = new QTimer(this);
    mainTimer->setInterval(1);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(handleTimer()));

//------------------------------------------------------------------------------------------
		//Load All Images
		pix.push_back(new QPixmap("temp.png"));
		
		mainTimer->start();
}


//-------------------SLOTS-------------------------------------------
void MainWindow::toggleTimer(){
	if (mainTimer->isActive()){
	  mainTimer->stop();
	}
	else mainTimer->start();
}

void MainWindow::startClicked(){
	//---------------------------------------------------
	//Check if nameBar was edited.
	if (nameBar->text()<=0){
		systemChat->append("Please Input an Alphanumeric Name.");
		return;
	}
	nameBar->setReadOnly(true);
	systemChat->append("Welcome "+nameBar->text()+" to S.W.A.T.");
	systemChat->append("Your goal is to help Mr. Fluffles escape the government.");
	systemChat->append("W, A, D to move Mr. Fluffles.");
	systemChat->append("Click to shoot.");
}

MainWindow::~MainWindow()
{
    mainTimer->stop();
    delete mainTimer;
    delete scene;
    delete view;
}

