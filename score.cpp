#include "score.h"
#include "player.h"
#include "digit.h"
#include "mainwindow.h"

#include <QFont>

Score::Score(int nx, int ny, MainWindow *main, QGraphicsScene *sc, Player *p) : QGraphicsRectItem(nx, ny, 150, 30)
{
	window = main;
	player = p;
	scene = sc;
	width = 150;
	height = 30;
	x = nx;
	y = ny;
	this->setTransformOriginPoint (x + width/2.0, y + height/2.0);
	zeroIMG = new QPixmap("zero.png", "png", Qt::AutoColor);
	oneIMG = new QPixmap("one.png", "png", Qt::AutoColor);
	this->setPos(nx, ny);
//	setBrush(Qt::NoBrush);
	points = 0;
	s = "Score";
	scoreDisplay = new QGraphicsSimpleTextItem(this);
	scoreDisplay->setText(s);
	scoreDisplay->setPos(x-50, y+5);
	scoreDisplay->show();
	/** Use the string to store the actual score value */
	s.setNum(points);
	QFont newFont("Courier", 20, QFont::Bold, true);
	pointDisplay = new QGraphicsSimpleTextItem(this);
	pointDisplay->setFont(newFont);
	pointDisplay->setText(s);
	pointDisplay->setPos(x-10, y-2);
	pointDisplay->show();
}

void Score::updateScore()
{
	s.setNum(points);
	binary();
	pointDisplay->setText(s);
	
	for(unsigned int i = 0; i < digits.size(); i++){
		if(digits[i] != NULL){
			scene->removeItem(digits[i]);
			delete digits[i];
			digits.erase(std::find(digits.begin(), digits.end(), digits[i]));
		}
	}
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0'){
			digit = new Digit(i*16 + x + 242, y- 28, 14, 24, 0, 0, player, this);
			scene->addItem(digit);
			digit->setBin(false);
			digits.push_back(digit);
		}
		else{
			digit = new Digit(i*16 + x + 242, y - 28, 14, 24, 0, 0, player, this);
			scene->addItem(digit);
			digit->setBin(true);
			digits.push_back(digit);
		}
	}
}

void Score::draw()
{
	QPointF p(x, y);
	QRectF r(rect());
	r.moveTo(p);
	setRect(r);
}

QString Score::toBinary(int num, bool rev)
{
    QString s;  
    while(num != 0)
    {
       s += (num & 1) ? '1' : '0';
       num >>= 1;
    }

    if(!rev)        
        std::reverse(s.begin(),s.end());

    return s;
}

void Score::binary()
{
	bool b = false;
	s = toBinary(points, b);
}

void Score::setPoints(int p)
{
	points = p;
}

void Score::addPoints(int p)
{
 points += p;
}

int Score::getPoints()
{
	return points;
}

int Score::getX()
{
	return x;
}

int Score::getY()
{
	return y;
}
