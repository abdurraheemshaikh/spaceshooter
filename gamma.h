#include <SFML/Graphics.hpp>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;
using namespace sf;

class Gamma
{

public:
	Texture emy;
	Texture enm2;
	Texture enm3;
	Sprite enm[40];
	float speed=0.35;
	int x,y,z;
	float positionx[40],positiony[40];

	Gamma()
	{
			emy.loadFromFile("img/enemy_2.png");
			enm2.loadFromFile("img/enemy_1.png");
			enm3.loadFromFile("img/enemy_3.png");
		for(int i=0;i<30;i++)
		{
			if(i%3==0)
			enm[i].setTexture(emy);
			else if(i%2==0)
				enm[i].setTexture(enm3);
			else
					enm[i].setTexture(enm2);
			//enm[i].setScale(0.1,0.1);
		}

	}

	void bombdrop(Bullet *bomb)
	{
		bomb->movebomb();

	}

	void rect()
	{

		x=50;y=350,z=x;
						positionx[0]=x;
						positiony[0]=y;
						for(int i=0;i<8;i++)
						{
								positionx[i]=x+(100*i);
								positiony[i]=y;
						}
						for (int i=8,j=0; i<16; i++,j++)
						{
							positionx[i]=x+(100*j);
							positiony[i]=y-200;
						}
						positionx[16]=x+700;
						positiony[16]=y-100;
						positionx[17]=x;
						positiony[17]=y-100;
						for(int i=0;i<8;i++)
						{
						enm[i].setPosition(sf::Vector2f(x+(100*i),y));
						enm[i].setScale(0.35,0.35);
						}
						for (int i=8,j=0; i<16; i++,j++)
						{
						enm[i].setPosition(sf::Vector2f(x+(100*j),y-200));
						enm[i].setScale(0.35,0.35);
						}
						enm[16].setPosition(sf::Vector2f(x+(700),y-100));
						enm[16].setScale(0.35,0.35);
						enm[17].setPosition(sf::Vector2f(x,y-100));
						enm[17].setScale(0.35,0.35);

	}

	void menu()
	{
		x=850;
		y=400;

		for(int i=0; i<4;i++)
		{
			enm[i].setPosition(x+(i*100), y);
			enm[i].setScale(0.4, 0.4);
		}
		for(int i=4,j=0; i<8;i++,j++)
		{
			enm[i].setPosition(x+(j*100), y+100);
			enm[i].setScale(0.4, 0.4);
		}
x=50;
		for(int i=8,j=0; i<12;i++,j++)
			{
				enm[i].setPosition(x+(j*100), y);
				enm[i].setScale(0.4, 0.4);
			}
			for(int i=12,j=0; i<16;i++,j++)
			{
				enm[i].setPosition(x+(j*100), y+100);
				enm[i].setScale(0.4, 0.4);
			}

	}


	void triangle()
	{
		x=150;y=550,z=x;
		for(int i=0;i<6;i++)
		{
				positionx[i]=x+(100*i);
				positiony[i]=y;
				enm[i].setPosition(sf::Vector2f(x+(100*i),y));
				enm[i].setScale(0.35,0.35);
		}

		for (int i=0,j=6;i<5;i++,j++)
		{
			positiony[j]=y-(100*i);
			positionx[j]=x+(50*i);
			enm[j].setPosition(sf::Vector2f(x+(50*i),y-(100*i)));
			enm[j].setScale(0.35,0.35);
		}
		y-=500;
		x+=250;
		for(int i=0,j=11;i<5;i++,j++)
		{
			positionx[j]=x+(50*i);
			positiony[j]=y+(100*i);
			enm[j].setPosition(sf::Vector2f(x+(50*i),y+(100*i)));
			enm[j].setScale(0.35,0.35);
		}




	}


	void cross()
		{

		x=150;y=550,z=x;
			for (int i=0,j=0;i<10;i++,j++)
			{
				positiony[j]=y-(50*i);
				positionx[j]=x+(50*i);
				enm[j].setPosition(sf::Vector2f(x+(50*i),y-(50*i)));
				enm[j].setScale(0.35,0.35);
			}
			y-=550;
			//x+=250;
			for(int i=0,j=10;i<10;i++,j++)
			{
				positionx[j]=x+(50*i);
				positiony[j]=y+(50*i);
				enm[j].setPosition(sf::Vector2f(x+(50*i),y+(50*i)));
				enm[j].setScale(0.35,0.35);
			}




		}

	void circle()
	{
	    int radius = 250; // set the radius of the circle
	    int numPositions = 20; // set the number of positions in the circle
	    float centerX = 450; // set the x-coordinate of the center of the circle
	    float centerY = 350; // set the y-coordinate of the center of the circle
	    float angleStep = 360.0f / numPositions; // calculate the angle between each position in the circle

	    // loop through each position in the circle and calculate its x and y coordinates based on the angle
	    for (int i = 0; i < numPositions; i++)
	    {
	        float angle = i * angleStep;
	        float x = centerX + radius * cos(angle * 3.14159f / 180.0f);
	        float y = centerY + radius * sin(angle * 3.14159f / 180.0f);

	        cout<<x<<"   "<<y<<endl;
	        positionx[i] = x;
	        positiony[i] = y;
	        enm[i].setPosition(sf::Vector2f(x, y)); // set the position of the corresponding circle object
	        enm[i].setScale(0.35, 0.35);



	    }
	}


	void filledcircle()
	{

		 int radius = 250; // set the radius of the circle
			    int numPositions = 15; // set the number of positions in the circle
			    float centerX = 450; // set the x-coordinate of the center of the circle
			    float centerY = 350; // set the y-coordinate of the center of the circle
			    float angleStep = 360.0f / numPositions; // calculate the angle between each position in the circle

			    // loop through each position in the circle and calculate its x and y coordinates based on the angle
			    for (int i = 0; i < numPositions; i++)
			    {
			        float angle = i * angleStep;
			        float x = centerX + radius * cos(angle * 3.14159f / 180.0f);
			        float y = centerY + radius * sin(angle * 3.14159f / 180.0f);

			        cout<<x<<"   "<<y<<endl;
			        positionx[i] = x;
			        positiony[i] = y;
			        enm[i].setPosition(sf::Vector2f(x, y)); // set the position of the corresponding circle object
			        enm[i].setScale(0.35, 0.35);
			    }
			    radius=150;
			    for (int i = 0,j=15; i < 15; j++,i++)
			  			    {
			  			        float angle = i * angleStep;
			  			        float x = centerX + radius * cos(angle * 3.14159f / 180.0f);
			  			        float y = centerY + radius * sin(angle * 3.14159f / 180.0f);

			  			        cout<<x<<"   "<<y<<endl;
			  			        positionx[j] = x;
			  			        positiony[j] = y;
			  			        enm[j].setPosition(sf::Vector2f(x, y)); // set the position of the corresponding circle object
			  			        enm[j].setScale(0.35, 0.35);
			  			    }





/*

			    	positionx[15] =350;
			    	positiony[15] = 350;
			    	enm[15].setPosition(sf::Vector2f(350, 350)); // set the position of the corresponding circle object
			    	enm[15].setScale(0.35, 0.35);
			    	positionx[16] =350;
			    	positiony[16] = 450;
			    	enm[16].setPosition(sf::Vector2f(350, 450)); // set the position of the corresponding circle object
			    	enm[16].setScale(0.35, 0.35);
			    	positionx[17] =450;
			    	positiony[17] = 450;
			    	enm[17].setPosition(sf::Vector2f(450, 450)); // set the position of the corresponding circle object
			    	enm[17].setScale(0.35, 0.35);
			    	positionx[18] =450;
			    	positiony[18] = 350;
			    	enm[18].setPosition(sf::Vector2f(450, 350)); // set the position of the corresponding circle object
			    	enm[18].setScale(0.35, 0.35);

			    	positionx[19] =550;
			    	positiony[19] = 450;
			    	enm[19].setPosition(sf::Vector2f(550, 450)); // set the position of the corresponding circle object
			    	enm[19].setScale(0.35, 0.35);
			    	positionx[20] =350;
			    	positiony[20] = 250;
			    	enm[20].setPosition(sf::Vector2f(350, 250)); // set the position of the corresponding circle object
			    	enm[20].setScale(0.35, 0.35);
			    	positionx[21] =450;
			    	positiony[21] = 250;
			    	enm[21].setPosition(sf::Vector2f(450, 250)); // set the position of the corresponding circle object
			    	enm[21].setScale(0.35, 0.35);

			    	positionx[22] =250;
			    	positiony[22] = 350;
			    	enm[22].setPosition(sf::Vector2f(250, 350)); // set the position of the corresponding circle object
			    	enm[22].setScale(0.35, 0.35);

			    	*/

			    }
/*
		positionx[20] = 550;
		positiony[20] = 350;
		enm[20].setPosition(sf::Vector2f(550, 350)); // set the position of the corresponding circle object
		enm[20].setScale(0.35, 0.35);
		positionx[21] = 650;
		positiony[21] = 350;
		enm[21].setPosition(sf::Vector2f(650, 350)); // set the position of the corresponding circle object
		enm[21].setScale(0.35, 0.35);
		*/




	void diamond()
	{
		x=250;y=50,z=x;
								positionx[0]=x;
								positiony[0]=y;
								for(int i=0;i<4;i++)
								{
										positionx[i]=x+(100*i);
										positiony[i]=y;
										enm[i].setPosition(x+(100*i),y);
										enm[i].setScale(0.35,0.35);
								}
								for (int i=4,j=1; i<7; i++,j++)
								{
									positionx[i]=x-(25*j);
									positiony[i]=y+(50*j);
									enm[i].setPosition(x-(25*j),y+50*j);
									enm[i].setScale(0.35,0.35);
								}
								x+=300;
								for (int i=7,j=1; i<10; i++,j++)
								{
									positionx[i]=x+(25*j);
									positiony[i]=y+(50*j);
									enm[i].setPosition(x+(25*j),y+(50*j));
									enm[i].setScale(0.35,0.35);
								}
								x=z;
								x-=100;
								y=300;

								for (int i=10,j=0; i<14; i++,j++)
								{
									positionx[i]=x+(75*j);
									positiony[i]=y+(100*j);
									enm[i].setPosition(x+(75*j),y+100*j);
									enm[i].setScale(0.35,0.35);
								}
								x=z;
								x=650;
								//x+=800;
								for (int i=14,j=0; i<18; i++,j++)
								{
									positionx[i]=x-(75*j);
									positiony[i]=y+100*j;
									enm[i].setPosition(x-(75*j),y+100*j);
									enm[i].setScale(0.35,0.35);
								}




	}

	void heart()
	{

		x=250;y=50,z=x;
										positionx[0]=x;
										positiony[0]=y;
									//	for(int i=0;i<4;i++)

												positionx[0]=x;
												positiony[0]=y;
												enm[0].setPosition(x,y);
												enm[0].setScale(0.35,0.35);
												positionx[1]=x+100;
												positiony[1]=y+100;
												enm[1].setPosition(x+100,y+100);
												enm[1].setScale(0.35,0.35);
												positionx[2]=x+200;
												positiony[2]=y+100;
												enm[2].setPosition(x+200,y+100);
												enm[2].setScale(0.35,0.35);
												positionx[3]=x+300;
												positiony[3]=y;
												enm[3].setPosition(x+300,y);
												enm[3].setScale(0.35,0.35);
										for (int i=4,j=1; i<7; i++,j++)
										{
											positionx[i]=x-(25*j);
											positiony[i]=y+(50*j);
											enm[i].setPosition(x-(25*j),y+50*j);
											enm[i].setScale(0.35,0.35);
										}
										x+=300;
										for (int i=7,j=1; i<10; i++,j++)
										{
											positionx[i]=x+(25*j);
											positiony[i]=y+(50*j);
											enm[i].setPosition(x+(25*j),y+(50*j));
											enm[i].setScale(0.35,0.35);
										}
										x=z;
										x-=100;
										y=300;

										for (int i=10,j=0; i<14; i++,j++)
										{
											positionx[i]=x+(75*j);
											positiony[i]=y+(100*j);
											enm[i].setPosition(x+(75*j),y+100*j);
											enm[i].setScale(0.35,0.35);
										}
										x=z;
										x=650;
										//x+=800;
										for (int i=14,j=0; i<18; i++,j++)
										{
											positionx[i]=x-(75*j);
											positiony[i]=y+100*j;
											enm[i].setPosition(x-(75*j),y+100*j);
											enm[i].setScale(0.35,0.35);
										}

	}

	void Movement(float x)
	{

		//if(x)
		float delta_x=x,delta_y=0;
		delta_x*=speed;
		delta_y*=speed;
		for(int i=0;i<18;i++)
		{
			if(i%2==0)
			{
				enm[i].move(sf::Vector2f(delta_x, delta_y));
				positionx[i]+=delta_x;
			}
			else
			{
				enm[i].move(sf::Vector2f(-delta_x, delta_y));
				positionx[i]+=-delta_x;
			}

		}




	}
	void menuMovement(float x)
	{

		//if(x)
		float delta_x=x,delta_y=0;
		delta_x*=speed;
		delta_y*=speed;
		for(int i=0;i<16;i++)
		{
			if(i%2==0)
			{
				enm[i].move(delta_x, delta_y);
			}
			else
			{
				enm[i].move(sf::Vector2f(-delta_x, delta_y));
			}

		}




	}

	bool contact(float bulx,float buly,int*array,int &num,int numenm)
	{

		bool check=false;
		//cout<<buly<<endl;
		//cout<<positiony[2]<<endl;
		for(int i=0;i<numenm;i++)
		{
			if ( bulx>=positionx[i] && bulx<=(positionx[i]+40) && buly>=positiony[i] && buly<=(positiony[i]+30))
				{
				for(int j=0;j<numenm;j++)
				{
					if(array[j]==i)
						break;
					if(array[j]!=i && array[j]==-1)
					{
						array[j]=i;
						num++;
						break;
					}
				}
					check=true;
				}
		}

		return check;
	}

	bool contactbom(float bulx,float buly)
	{

		bool check=false;
		//cout<<"hello im in"<<endl;
		for(int i=0;i<18;i++)
		{
			if ( bulx>=positionx[i] && bulx<=(positionx[i]+40) && buly>=positiony[i] && buly<=(positiony[i]+30))
				{
					//cout<<check<<endl;

					check=true;
				}
		}

		return check;
	}

	~Gamma()
	{

	}
};


