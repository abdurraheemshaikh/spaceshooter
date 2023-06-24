/*
 * addon.cpp
 *
 *  Created on: May 10, 2023
 *      Author: abdur
 */
#include<iostream>
using namespace std;
#include "addon.h"

addons::addons() {
	// TODO Auto-generated constructor stub
	cout<<"helle"<<endl;

}

addons::~addons() {
	// TODO Auto-generated destructor stub
}


class danger:public addons
{

public:



	danger()
	{
		tes.loadFromFile("img/PNG/UI/numeralX.png");
		addon.setTexture(tes);
		addon.setPosition(randomx,randomy);
		addon.setScale(2,2);
		//cout<<"danger const"<<endl;
	}
	virtual void movedanger()
		{
			float delta_x=0,delta_y=+1;
					delta_x*=speed;
					delta_y*=speed;
					randomy+=delta_y;
					randomx+=delta_x;
					positionx+=delta_x;
					positiony+=delta_y;
					addon.move(delta_x, delta_y);
		}



};

class Extralife:public addons
{

public:
//Sprite extralife;
float lifex=randomx,lifey=randomy;

	Extralife()
	{
		tes.loadFromFile("img/PNG/Power-ups/pill_green.png");
		addon.setTexture(tes);
		addon.setPosition(randomx,randomy);
		addon.setScale(2,2);



	}
	virtual void movedanger()
		{
			float delta_x=0,delta_y=+1;
					delta_x*=speed;
					delta_y*=speed;
					randomy+=delta_y;
					randomx+=delta_x;
					positionx+=delta_x;
					positiony+=delta_y;
					addon.move(delta_x, delta_y);
		}




};


class MultiBullet:public addons
{

public:


	MultiBullet()
	{
		tes.loadFromFile("img/PNG/Power-ups/powerupYellow_bolt.png");
		addon.setTexture(tes);
		addon.setPosition(randomx,randomy);
		addon.setScale(1,1);

	}
	virtual void movedanger()
		{
			float delta_x=0,delta_y=+1;
					delta_x*=speed;
					delta_y*=speed;
					randomy+=delta_y;
					randomx+=delta_x;
					positionx+=delta_x;
					positiony+=delta_y;
					addon.move(delta_x, delta_y);
		}

};

