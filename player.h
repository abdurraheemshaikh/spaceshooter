#include <SFML/Graphics.hpp>
#include<string.h>
#include"bullet.h"
#include<iostream>
#include<cmath>
using namespace std;
using namespace sf;

class Player{
public:
Texture tex;
Sprite sprite;
Texture hear;
Sprite heart[5];
float speed=5;
int x,y;
int positionx,positiony;
//Bullet *gun;
Player(std::string png_path)
{
hear.loadFromFile("img/299063_heart_icon.png");
for(int i=0;i<3;i++)
heart[i].setTexture(hear);
for(int i=0;i<3;i++)
heart[i].setScale(0.07, 0.07);
for (int i=0;i<3;i++)
	heart[i].setPosition(40*i+10,950);

tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=350;y=800;
positionx=x;
positiony=y;
sprite.setPosition(sf::Vector2f(x,y));
sprite.setScale(0.75,0.75);
}

Player()
{
tex.loadFromFile("img/player_ship.png");
sprite.setTexture(tex);
x=1000;y=800;
positionx=x;
positiony=y;
sprite.setPosition(sf::Vector2f(x,y));
sprite.setScale(0.75,0.75);
}


Player(int z)
{
tex.loadFromFile("img/player_ship.png");
sprite.setTexture(tex);
x=200;y=800;
positionx=x;
positiony=y;
sprite.setPosition(sf::Vector2f(x,y));
sprite.setScale(0.75,0.75);
}
void fire( Bullet *gun)
{
	gun->move();

}
void life()
{



}

void firestream( Bullet **gun,int x,int y,int num)
{
//gun=new Bullet("img/PNG/Lasers/laserRed01.png");
	for(int i=0 ;i<5;i++)
		{gun[i]=new Bullet;
	//	cout<<"hello"<<i<<endl;
				gun[i]->setposition(x+(i*50),y);
		}
/*
	for(int j=0;j<num;j++)
	{
		for(int i=0 ;i<5;i++)
			{
			stream[j][i]->move();
			}

	}
	*/
}
	void move(std::string s){
	float delta_x=0,delta_y=0;
	if(s=="l")
		//move the player left
		delta_x=-1;
	else if(s=="r")
		//move the player right
		delta_x=1;
	if(s=="u")
		delta_y=-1;
	else if(s=="d")
		delta_y=1;
	delta_x*=speed;
	delta_y*=speed;
	positionx+=delta_x;
	positiony+=delta_y;
	if(positionx<-30)
	{
		positionx=840;
		sprite.setPosition(850, positiony);
	}
	if(positionx>850)
		{
			positionx=-20;
			sprite.setPosition(-20, positiony);
		}
	if(positiony<-20)
		{
			positiony=1000;
			sprite.setPosition(positionx, 1000);

		}
	if(positiony>1000)
		{
			positiony=-20;
			sprite.setPosition(positionx, -20);
		}


	sprite.move(delta_x, delta_y);

	}


	bool contactbom(float bulx,float buly)
	{

		bool check=false;

			if ( bulx>=positionx && bulx<=(positionx+40) && buly>=positiony && buly<=(positiony+30))
				{

					check=true;
				}

		return check;
	}

	bool incontact(float bulx,float buly)
	{
		bool check=false;

			if ( bulx>=positionx && bulx<=(positionx+40) && buly>=positiony && buly<=(positiony+30))
				{

					check=true;
				}
		return check;
	}

	bool enemycollison(float bulx,float buly )
	{
		bool check=false;

					if ( bulx>=positionx && bulx<=(positionx+40) && buly>=positiony && buly<=(positiony+30))
						{

							check=true;
						}

				return check;

	}











};
