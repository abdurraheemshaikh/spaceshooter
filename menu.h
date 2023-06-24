#include <time.h>
#include <SFML/Graphics.hpp>
#include "game.h"
class Menu{
public:
	Texture M;
	Sprite menu;

	Texture a;
	Sprite about;

	Texture set;
	Sprite setting;

	Texture sh1;
	Texture sh2;
	Texture sh3;

	Sprite Ship1;
	Sprite Ship2;
	Sprite Ship3;
	Texture bul;

	Texture bul1;
		Texture bul2;
		Texture bul3;
		Sprite bullet;
		Sprite bullet1;
		Sprite bullet2;
		Sprite bullet3;

	Texture shipset;
	Sprite shipsetting;

	Bullet **gun;
	Player* p; //player

	Enemy *enmy;
	Player *q;
	//int spaceship=1;
	//int typebullet=1;
int temp=0;
int sec=0;
int runtime=0;
float move=0;bool sett;
float speed=0.04;
int var;
int sudo=0;



//add menu attributes here
Menu()
{
M.loadFromFile("img/Screenshot.png");
menu.setTexture(M);
menu.setScale(1, 1.5);
a.loadFromFile("img/Screenshot 2023-05-13 163800.png");
about.setTexture(a);
about.setScale(1.1, 1.5);

set.loadFromFile("img/Screenshot 2023-05-12 001437.png");
setting.setTexture(set);
setting.setScale(1.2,1.5);
shipset.loadFromFile("img/Screenshot 2023-05-12 005708.png");
shipsetting.setTexture(shipset);
shipsetting.setScale(1.3,1.5);

sh1.loadFromFile("img/PNG/playerShip2_red.png");
sh2.loadFromFile("img/PNG/playerShip1_green.png");
sh3.loadFromFile("img/PNG/ufoBlue.png");

bul.loadFromFile("img/PNG/Lasers/laserGreen11.png");
bul1.loadFromFile("img/PNG/Lasers/laserBlue16.png");
bul2.loadFromFile("img/PNG/Lasers/laserGreen03.png");
bul3.loadFromFile("img/PNG/Lasers/laserRed09.png");

bullet.setTexture(bul);
bullet1.setTexture(bul1);
bullet2.setTexture(bul2);
bullet3.setTexture(bul3);

bullet.setScale(2, 2);
bullet.setPosition(550,450);

bullet1.setScale(2, 2);
bullet1.setPosition(-200,450);

bullet2.setScale(2, 2);
bullet2.setPosition(-1400,450);

bullet3.setScale(2, 2);
bullet3.setPosition(-2600,450);

Ship1.setTexture(sh1);
Ship1.setPosition(-200, 450);
Ship1.setScale(1.5, 2);

Ship2.setTexture(sh2);
Ship2.setPosition(-1400, 450);
Ship2.setScale(1.5, 2);

Ship3.setTexture(sh3);
Ship3.setPosition(-2600, 450);
Ship3.setScale(1.5, 2);



p=new Player();
q=new Player(1);
sett=1;

gun=new Bullet*[500];//(p->positionx+37,p->positiony);
enmy=new Enemy;
//constructors body
}

void display_menu(int l,int b)

{

    Game g(l,b);
//display menu screen here

// add functionality of all the menu options here

//if Start game option is chosen 
    
    g.start_game();



}
 void Startmenu(int &spaceship,int &typebullet)
{
	RenderWindow Start(VideoMode(1280, 1000), title);

	 Font style;
	  		    style.loadFromFile("img/Algerian Regular.ttf");

	 Text text;
	       text.setFont(style);
	       text.setCharacterSize(50);
	       text.setFillColor(sf::Color::White);
	       text.setPosition(550, 500);

	  	 Text text1;
	  	       text1.setFont(style);
	  	       text1.setCharacterSize(50);
	  	       text1.setFillColor(sf::Color::White);
	  	       text1.setPosition(150, 700);

	  		 Text text2;
	  		       text2.setFont(style);
	  		       text2.setCharacterSize(50);
	  		       text2.setFillColor(sf::Color::White);
	  		       text2.setPosition(950, 700);


	       const string filename = "scores.txt";

	       ifstream inputFile;
	            inputFile.open(filename);



	            int topScores[3] = {0};
	            int index = 0;
	            int currentScore = 0;
	            while (inputFile >> currentScore) {
	                for (int i = 0; i < 3; i++) {
	                    if (currentScore > topScores[i]) {
	                        for (int j = 2; j > i; j--) {
	                            topScores[j] = topScores[j - 1];
	                        }
	                        topScores[i] = currentScore;
	                        break;
	                    }
	                }
	            }

	            cout << "Top 3 scores: ";
	            for (int i = 0; i < 3; i++) {
	                cout << topScores[i] << " ";
	            }


	            text.setString(std::to_string(topScores[0]));
	            text1.setString(std::to_string(topScores[1]));
	            text2.setString(std::to_string(topScores[2]));
	            inputFile.close();




	while(Start.isOpen())
	{


		Event e;
	        while (Start.pollEvent(e))
	        {
	            if (e.type == Event::Closed) // If cross/close is clicked/pressed
	                Start.close(); //close the game
	        }

		if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
		{
			Start.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) //If left key is pressed
				{
			sett=1;
						while(sett)
						{
						Start.clear(Color::Black);
						Start.draw(about);
						Start.draw(text);
						Start.draw(text2);
						Start.draw(text1);

						if (Keyboard::isKeyPressed(Keyboard::Escape)) //If left key is pressed
										{
											sett=0;
										}


						Start.display();

				}
				}

		if (Keyboard::isKeyPressed(Keyboard::S)) //If left key is pressed
				{
			sett=1;
			while(sett)
			{
			Start.clear(Color::Black);
			Start.draw(setting);

			if (Keyboard::isKeyPressed(Keyboard::Escape)) //If left key is pressed
				{
					sett=0;
				}
			if (Keyboard::isKeyPressed(Keyboard::Num1)) //If left key is pressed
				{


				sett=1;
				p->sprite.setScale(1.5, 2);
				p->sprite.setPosition(550,450);
							while(sett)
							{
							Start.clear(Color::Black);
							Start.draw(shipsetting);
							Start.draw(p->sprite);
							Start.draw(Ship1);
							Start.draw(Ship2);
							Start.draw(Ship3);

							if (Keyboard::isKeyPressed(Keyboard::Escape)) //If left key is pressed
								{
									sett=0;
									p->sprite.setScale(1, 1);
									p->sprite.setPosition(1000,800);
								}
							if (Keyboard::isKeyPressed(Keyboard::Right)) //If left key is pressed
								{
										var=1;
										sudo++;
										int t=0;
										while(t<50)
										{
										if(var<=4)
										{
										if(t%5==0)
										Glide(var);

										}
										t++;
										}
								}
							if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
								{
										var=-1;
										sudo--;
									//	if(var>=1)
										int t=0;
									    while(t<50)
										{
									    	if(var<=4)
									    	{
									    		if(t%5==0)
									    		Glide(var);

									    	}
									    	t++;
										}

								}






							if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
								{
									if(sudo>-20  &&  sudo<40)
									{
										spaceship=1;

									}
									if(sudo>80  &&  sudo<130)
									{
										spaceship=2;
									}
									if(sudo>220  &&  sudo<280)
									{
										spaceship=3;
									}
									if(sudo>360  &&  sudo<430)
									{
										spaceship=4;
									}
									sett=0;
								}

							//cout<<sudo<<endl;

				Start.display();

							}






sett=1;

				}



			if (Keyboard::isKeyPressed(Keyboard::Num2)) //If left key is pressed
							{


							sett=1;

										while(sett)
										{
										Start.clear(Color::Black);
										Start.draw(shipsetting);
										Start.draw(bullet);
										Start.draw(bullet1);
										Start.draw(bullet2);
										Start.draw(bullet3);

										if (Keyboard::isKeyPressed(Keyboard::Escape)) //If left key is pressed
											{
												sett=0;

											}
										if (Keyboard::isKeyPressed(Keyboard::Right)) //If left key is pressed
											{
													var=1;
													sudo++;
													int t=0;
													while(t<50)
													{
													if(var<=4)
													{
													if(t%5==0)
													Glide1(var);

													}
													t++;
													}
											}
										if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
											{
													var=-1;
													sudo--;
													int t=0;
												    while(t<50)
													{
												    	if(var<=4)
												    	{
												    		if(t%5==0)
												    		Glide1(var);

												    	}
												    	t++;
													}

											}

										if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
											{
												if(sudo>-20  &&  sudo<40)
												{
													typebullet=1;

												}
												if(sudo>80  &&  sudo<130)
												{
													typebullet=2;
												}
												if(sudo>220  &&  sudo<280)
												{
													typebullet=3;
												}
												if(sudo>360  &&  sudo<430)
												{
													typebullet=4;
												}
												sett=0;
											}

										//cout<<sudo<<endl;

							Start.display();

										}






			sett=1;

							}








Start.display();

			}




				}
		Start.clear(Color::Black);
		Start.draw(menu);

		enmy->menu();
		temp++;
		if(temp%2==0)
		enmy->menuMovement(move);


		if(temp%20==0)
				{
					gun[sec]=new Bullet(p->positionx+37,p->positiony);
					sec++;
					gun[sec]=new Bullet(q->positionx+37,q->positiony);
										sec++;
				}
		for (int i=0;i<sec;i++)
						p->fire(gun[i]);

				for(int i=0;i<sec;i++)
								Start.draw(gun[i]->bullet);
				for(int i=0;i<16;i++)
					Start.draw(enmy->enm[i]);



					if (runtime>=10)
						{
							move=-1;
							runtime=-10;
						}
					if(runtime>=0 && runtime<10)
						move=1;

					runtime++;
					//cout<<runtime<<endl;


					for(int i=0 ;i<500;i++);

						for(int i=0 ;i<500;i++);
						for(int i=0 ;i<500;i++);
						for(int i=0 ;i<500;i++);

						for(int i=0 ;i<500;i++);

							for(int i=0 ;i<500;i++);
							for(int i=0 ;i<500;i++);
							for(int i=0 ;i<500;i++);

							for(int i=0 ;i<500;i++);

								for(int i=0 ;i<500;i++);
								for(int i=0 ;i<500;i++);
								for(int i=0 ;i<500;i++);




		Start.draw(p->sprite);
		Start.draw(q->sprite);
		Start.display();

	}


//	return spaceship;



	//window.clear(Color::Black); //clears the screen
	//window.draw(background);

}

void Glide(int x)
	{

	float delta_x=x,delta_y=0;
	delta_x*=speed;
	delta_y*=speed;
	int time=0;
	while(time<1000)
	{

		if (time%50==0)
		{
			p->sprite.move(delta_x,delta_y);
			Ship1.move(delta_x, delta_y);
			Ship2.move(delta_x, delta_y);
			Ship3.move(delta_x, delta_y);
		}

		time++;

	}



	//Ship1.move(delta_x, delta_y);

	}

void Glide1(int x)
	{

	float delta_x=x,delta_y=0;
	delta_x*=speed;
	delta_y*=speed;
	int time=0;
	while(time<1000)
	{

		if (time%50==0)
		{
			bullet.move(delta_x,delta_y);
			bullet1.move(delta_x, delta_y);
			bullet2.move(delta_x, delta_y);
			bullet3.move(delta_x, delta_y);
		}

		time++;

	}



	//Ship1.move(delta_x, delta_y);

	}


};
