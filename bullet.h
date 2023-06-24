#include <SFML/Graphics.hpp>
#include<string.h>
#include <time.h>

using namespace sf;
using namespace std;

class Bullet
{
public :
	Texture bul;
	Sprite bullet;
	Texture bom;
	Sprite bomb;

	float speed=5;
	int x,y;
	float positionx,positiony;
	Bullet(){
		bul.loadFromFile("img/PNG/Lasers/laserRed01.png");
				bullet.setTexture(bul);
				bom.loadFromFile("img/PNG/Lasers/laserBlue08.png");
				bomb.setTexture(bom);
	}

	Bullet(int x,int y,string type)
	{
		bul.loadFromFile(type);
		bullet.setTexture(bul);
		bom.loadFromFile("img/PNG/Lasers/laserBlue08.png");
		bomb.setTexture(bom);

		this->x=x+100;this->y=y;
		positionx=x,positiony=y;
		bomb.setPosition(sf::Vector2f(x,y));
		bomb.setScale(0.5,0.5);
		bullet.setPosition(sf::Vector2f(x,y));
		bullet.setScale(1,1);
	}
	Bullet(int x,int y)
		{
			bul.loadFromFile("img/PNG/Lasers/laserGreen11.png");
			bullet.setTexture(bul);
			bom.loadFromFile("img/PNG/Lasers/laserBlue08.png");
			bomb.setTexture(bom);

			this->x=x+100;this->y=y;
			positionx=x,positiony=y;
			bomb.setPosition(sf::Vector2f(x,y));
			bomb.setScale(0.5,0.5);
			bullet.setPosition(sf::Vector2f(x,y));
			bullet.setScale(1,1);
		}
	Bullet(std::string png_path,int x,int y)
	{
		bul.loadFromFile(png_path);
		bullet.setTexture(bul);
		this->x=x+100;this->y=y;
				positionx=x,positiony=y;
		bullet.setPosition(sf::Vector2f(x,y));
		bullet.setScale(0.05,0.05);
	}
	void setposition(int x,int y)
	{
		this->x=x+100;this->y=y;
				positionx=x,positiony=y;
				bomb.setPosition(sf::Vector2f(x,y));
				bomb.setScale(0.5,0.5);
				bullet.setPosition(sf::Vector2f(x,y));
				bullet.setScale(1,1);

	}

	void move(){
	float delta_x=0,delta_y=-2;
	delta_x*=speed;
	delta_y*=speed;
	positiony+=delta_y;
	positionx+=delta_x;
	bullet.move(sf::Vector2f(delta_x, delta_y));

	}

	void movebomb(){
		float delta_x=0,delta_y=+1;
		delta_x*=speed;
		delta_y*=speed;
		positiony+=delta_y;
		positionx+=delta_x;
		bomb.move(delta_x, delta_y);

		}


};


