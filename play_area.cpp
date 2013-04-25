#include "play_area.h"
#include "mainwindow.h"
#include <iostream>

PlayArea::PlayArea(int nx, int ny, int w, int h, MainWindow *window) : QGraphicsRectItem(nx, ny, w, h)
{ 
	main = window;
}

void PlayArea::mousePressEvent(QGraphicsSceneMouseEvent *clicked)
{
	if(clicked->button() == Qt::LeftButton){
		main->shoot();
	}
}