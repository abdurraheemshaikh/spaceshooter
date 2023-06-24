/*
 * Dragon.h
 *
 *  Created on: May 14, 2023
 *      Author: abdur
 */

#ifndef DRAGON_H_
#define DRAGON_H_
#include"Enemy.h"
class Dragon:public Enemy
{

public:
	Texture drag;
	Sprite monster;
	Texture las;
	Sprite laser;



	float monsterpositionx;
	float monsterpositiony;


	Dragon()
	{

		las.loadFromFile("img/PNG/Lasers/laserBlue04.png");
		drag.loadFromFile("img/monster.png");
		monster.setTexture(drag);
		monster.setScale(0.3, 0.3);
		laser.setTexture(las);
		laser.setScale(2,22);
		monsterpositionx=50;
	    monsterpositiony=0;
	    laser.setPosition(monsterpositionx+250,200);
		monster.setPosition(monsterpositionx, monsterpositiony);

	}



	void moving(float x)
	{
				float delta_x=0,delta_y=0;
		if (x>350)
		{	delta_x=1;
		speed=2;
				delta_x*=speed;
				monsterpositionx+=delta_x;
				if (monsterpositionx<300 && monsterpositionx>0)
				{laser.setPosition(monsterpositionx+200,100);
				monster.move(sf::Vector2f(delta_x, 0));


				}
				}
		else
		{
			delta_x=-1;
			speed=1;
			delta_x*=speed;
			monsterpositionx+=delta_x;
			if (monsterpositionx<300 && monsterpositionx>0)
			{
				laser.setPosition(monsterpositionx+200,100);

			monster.move(sf::Vector2f(delta_x, 0));

			}
		}


	}



void displayfire(int x)
{
laser.setScale(10, x*6);



}



bool lasercollision(float playerx,float playery)
{

	bool check=false;


		if ( playerx>=(laser.getPosition().x) && playerx<=(laser.getPosition().x+30) && playery>=laser.getPosition().y && playery<=(laser.getPosition().y+1000))
			{
				check=true;
			}



	return check;



}


};
#endif /* DRAGON_H_ */
