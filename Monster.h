/*
 * Monster.h
 *
 *  Created on: May 14, 2023
 *      Author: abdur
 */

#ifndef MONSTER_H_
#define MONSTER_H_
#include"Enemy.h"

class Monster:public Enemy
{
public:
	Texture drag;
	Sprite monster;
	Texture las;
	Sprite laser;
	Texture mini1;
	Texture mini2;
	Sprite head1;
	Sprite head2;
	Sprite laser2;
	Sprite laser1;


	float monsterpositionx;
	float monsterpositiony;

	Monster()
	{

		las.loadFromFile("img/PNG/Effects/fire06.png");
		drag.loadFromFile("img/dragon2.png");
		monster.setTexture(drag);
		mini1.loadFromFile("img/dragon1.png");
		mini2.loadFromFile("img/dragon.png");
		laser1.setTexture(las);
		laser2.setTexture(las);
		laser1.rotate(25);
		laser2.rotate(-25);
		head1.setTexture(mini1);
		head1.setScale(0.5, 0.5);
		head2.setTexture(mini2);
		head2.setScale(0.5, 0.5);
		head1.rotate(25);
		head2.rotate(-25);
		head1.setPosition(monsterpositionx-10, 400);
		head2.setPosition(monsterpositionx+300, 350);
		laser.setTexture(las);
		laser.setScale(10,8);
		laser1.setScale(10,8);
		laser2.setScale(10,8);
		monster.setScale(0.6,0.6);
		monsterpositionx=50;
	    monsterpositiony=0;
	    laser.setPosition(monsterpositionx+104,400);
		monster.setPosition(monsterpositionx, monsterpositiony);
		laser1.setPosition(monsterpositionx+120,450);
		laser1.setPosition(monsterpositionx+330,450);
		laser2.setPosition(monsterpositionx+120,450);
		laser2.setPosition(monsterpositionx+330,450);

	}



	void moving(float x)
	{
				float delta_x=0,delta_y=0;
		if (x>350)
		{	delta_x=1;
				delta_x*=speed;
				monsterpositionx+=delta_x;
				if (monsterpositionx<300 && monsterpositionx>0)
				{laser.setPosition(monsterpositionx+104,400);
				monster.move(sf::Vector2f(delta_x, 0));
				head1.setPosition(monsterpositionx, 300);
				head2.setPosition(monsterpositionx+330, 400);
				laser1.setPosition(monsterpositionx-70,400);
				laser2.setPosition(monsterpositionx+370,520);

				}
				}
		else
		{
			delta_x=-1;
			delta_x*=speed;
			monsterpositionx+=delta_x;
			if (monsterpositionx<300 && monsterpositionx>0)
			{
				laser.setPosition(monsterpositionx+104,400);

			monster.move(sf::Vector2f(delta_x, 0));
			head1.setPosition(monsterpositionx, 300);
			head2.setPosition(monsterpositionx+330, 400);
			laser1.setPosition(monsterpositionx-70,400);
			laser2.setPosition(monsterpositionx+370,520);
			}
		}


	}
void displayfire(int x)
{
laser.setScale(10, x*6);
laser1.setScale(10,x*6);
laser2.setScale(10,x*6);


}

bool lasercollision(float playerx,float playery)
{

	bool check=false;


		if ( playerx>=(laser.getPosition().x) && playerx<=(laser.getPosition().x+50) && playery>=laser.getPosition().y && playery<=(laser.getPosition().y+800))
			{
				check=true;
			}
		if ( playerx>=(laser1.getPosition().x-100) && playerx<=(laser1.getPosition().x-200) && playery>=laser1.getPosition().y && playery<=(laser1.getPosition().y+800))
					{
						check=true;
					}

		if ( playerx>=(laser2.getPosition().x+100) && playerx<=(laser2.getPosition().x+2000) && playery>=laser2.getPosition().y && playery<=(laser2.getPosition().y+800))
					{
						check=true;
					}


	return check;



}

};

#endif /* MONSTER_H_ */
