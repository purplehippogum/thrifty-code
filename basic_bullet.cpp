#include "basic_bullet.h"
#include <iostream>
#include <cmath>

BasicBullet::BasicBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp, int d)
	: AbstractObject(pm, nx, ny, w, h, hp)
{
	initX = nx;
	initY = ny;
	finX = vx;
	finY = vy;
	damage = d;
	strikeCount = 0;
	inEnemy = false;
}

BasicBullet::~BasicBullet()
{

}

int BasicBullet::getDamage()
{
	return damage;
}

void BasicBullet::move(double vx, double vy)// double vx, double vy
{
//	std::cout << "\nbullet x " << x << std::endl;
//	std::cout << "fin x " << finX << std::endl;

	if(vx > 0)
		moveRight(1);

	else if(vx < 0)
		moveLeft(1);
/*
*/
	if(vy < 0)
		moveUp(1);

	else if(vy > 0)
		moveDown(1);
}

void BasicBullet::setInEnemy(bool b)
{
	inEnemy = b;
}
bool BasicBullet::getInEnemy()
{
	return inEnemy;
}
void BasicBullet::decStrike()
{
	strikeCount--;
}

int BasicBullet::getStrike()
{
	return strikeCount;
}

void BasicBullet::setBomb(bool b){
	bomb = b;
}
bool BasicBullet::getBomb(){
	return bomb;
}
