#ifndef GameObject
#define GameObject
#include <QGraphicsPixmapItem>

class GameObject : public QObject, public QGraphicsPixmapItem {

	Q_OBJECT
	
public:
	GameObject(int nx, int ny, int w, int h, QPixmap* pixmap);
	~GameObject();
	int gX();
	int gY();
	int gVX();
	int gVY();
	bool isFlipped();
	void flipImg();
	void MoveTowards(int x, int y, int speed);
	void MoveDir(int x, int y, int speed);
	
public slots:
	void Update();
	void OnCollisionEnter();
	

protected:
		int x;
		int y;
		int vx;
		int vy;
		int width;
		int height;
		bool flipHorizontal;
		
		QPixmap* pixmap;
		
		
};

#endif 
