#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <time.h>
#include "player.h"
#include"addon.cpp"
#include"Enemy.h"
#include<sstream>
#include"dangersign.h"
#include<string.h>
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player 
Bullet **gun;
Bullet ***stream;
Bullet **bomb;
Enemy *enmy;
int idx;
Sprite levelu;
Texture lv;
addons *sign;
Extralife *life;
addons *multifire;
Monster *monster;
Dragon *dragon;
dangersign hoe;
Texture paus;
Sprite Pause;
int sometime=0;
int sometemp=0;
Texture game;
Sprite over;
Texture collision1;
Sprite coll1;
Texture collision2;
Sprite coll2;
Texture collision3;
Sprite coll3;
string type;
Texture sm;
Sprite sidemenu;

Texture n1;
Texture n2;
Texture n3;
Sprite num1;
Sprite num2;
Sprite num3;




Game(int lou,int blt)
{
	switch(lou)
	{
	case 1:
		p=new Player("img/player_ship.png");
		break;
	case 2:
			p=new Player("img/PNG/playerShip2_red.png");
			break;
	case 3:
			p=new Player("img/PNG/playerShip1_green.png");
			break;
	case 4:
			p=new Player("img/PNG/ufoBlue.png");
			break;

	}
	switch(blt)
		{
		case 1:
			type="img/PNG/Lasers/laserGreen11.png";
			break;
		case 2:
			type="img/PNG/Lasers/laserBlue16.png";
				break;
		case 3:
				type="img/PNG/Lasers/laserGreen03.png";
				break;
		case 4:
				type="img/PNG/Lasers/laserRed09.png";
				break;

		}

	sm.loadFromFile("img/dark-theme-black-and-white-dragon-smoke-pshayshvnvw3dif5.jpg");
	sidemenu.setTexture(sm);
	sidemenu.setPosition(900, 0);
	sidemenu.setScale(0.35, 0.5);
//gun=new Bullet ;//("img/PNG/Lasers/laserRed01.png");
gun=new Bullet*[500];//(p->positionx+37,p->positiony);
stream=new Bullet**[500];
bomb=new Bullet*[500];
enmy=new Enemy;
monster=new Monster;
dragon=new Dragon;
sign=new danger;
life=new Extralife;
multifire=new MultiBullet;
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(1.1, 2);
lv.loadFromFile("img/pngtree-game-level-completed-design-vector-png-image_2910929.jpg");
levelu.setTexture(lv);
idx=0;

paus.loadFromFile("img/Screenshot 2023-05-11 112615.png");
Pause.setTexture(paus);
Pause.setScale(1, 1.5);
game.loadFromFile("img/astronaut-1920x1080-space-4k-23165.jpg");
over.setTexture(game);
over.setScale(1, 1);
collision1.loadFromFile("img/PNG/Damage/playerShip3_damage3.png");
 coll1.setTexture(collision1);
 coll1.setPosition(-100, -100);
 collision2.loadFromFile("img/PNG/Damage/playerShip1_damage2.png");
 coll2.setTexture(collision2);
 coll2.setPosition(-100, -100);
 collision3.loadFromFile("img/PNG/Damage/playerShip1_damage1.png");
 coll3.setTexture(collision3);
 coll3.setPosition(-100, -100);

 n1.loadFromFile("img/PNG/UI/numeral1.png");
 	n2.loadFromFile("img/PNG/UI/numeral2.png");
 	n3.loadFromFile("img/PNG/UI/numeral3.png");
 	num1.setTexture(n1);
 	num2.setTexture(n2);
 	num3.setTexture(n3);
 	num1.setPosition(470, 400);
 	num2.setPosition(470, 400);
 	num3.setPosition(470, 400);
 	num1.setScale(15, 12);
 	num2.setScale(15, 12);
 	num3.setScale(15, 12);




}
~Game()
{
	delete[]gun;
	delete enmy;
	delete p;
	delete[] bomb;
}
void start_game()
{
    srand(time(0));




    RenderWindow window(VideoMode(1280, 1000), title);

    Clock clock;
    float timer=0;
    int Score=0,destroyed=0;
    int multiplier=1;
    int sec=0;
    int temp=0;
    float move=0;
    int runtime=0;
    int enmynum=0;
    int temp2=0;
    int b=0;
    int timesec=0;
    int l,y=0;
    int monruntime=0;
    bool monsterincoming=true;
    bool dragoncoming=true;
    bool lasercolion=false;
    int lives=3;
    bool bom;
    bool timedekh=1;
    bool powerup=0;
    bool powerup2=0;
    bool powerup3=0;
    int temp3;
    int temp4;
    bool firechala=1;
    bool firee=1;
    bool resume=1;
    int numenemy=18;
    int temp5=0;
    bool enemycolion=0;
    int res1=0,res2=0;




    if (temp==13)
    			{
    			}



    Font style;
  		    style.loadFromFile("img/Algerian Regular.ttf");
  		 ;
  		

  		         

    bool check=false;
    bool bombcheck=false;




    if (temp==9)
    		{

    		}




    /*________________score displayy_______________________*/




       Text text;
       text.setFont(style);
       text.setCharacterSize(50);
       text.setFillColor(sf::Color::White);
       text.setPosition(1050, 200);
       Text score;
           score.setFont(style);
           score.setCharacterSize(50);
           score.setFillColor(sf::Color::White);
           score.setString("..SCORE..");
           score.setPosition(975, 100);

           Text Time;
                      Time.setFont(style);
                      Time.setCharacterSize(50);
                      Time.setFillColor(sf::Color::White);
                      Time.setString("....Time....");
                      Time.setPosition(975, 850);

           Text Timee;
                      Timee.setFont(style);
                      Timee.setCharacterSize(50);
                      Timee.setFillColor(sf::Color::White);
                     // score.setString("..Time..");
                      Timee.setPosition(1070, 900);
           sf::Text gameover;
               gameover.setFont(style);
               gameover.setCharacterSize(50);
               gameover.setFillColor(sf::Color::White);
               gameover.setString("...Game Over...");
               gameover.setPosition(450, 200);

               sf::Text line1;
               line1.setFont(style);
               line1.setCharacterSize(50);
               line1.setFillColor(sf::Color::White);
               line1.setString("YOUR A");
               line1.setPosition(550, 300);

               sf::Text a;
               a.setFont(style);
               a.setCharacterSize(50);
               a.setFillColor(sf::Color::White);
               a.setString("CASUAL ACHIEVER");
               a.setPosition(400, 400);

               sf::Text highscore;
               highscore.setFont(style);
               highscore.setCharacterSize(50);
               highscore.setFillColor(sf::Color::White);
               highscore.setString("Your Score");
               highscore.setPosition(450, 500);





   //---------------------------------------------------------------

//---------------------------@@@@@@@@@@file handling #######---------------------------------

               const string filename = "scores.txt";
                    ofstream outputFile;






               bool restart=0;

    int array[100];
    for(int i=0;i<100;i++)
     array[i]=-1;
    cout<<"HELLO"<<endl;
    enmy->rect();
    bool levelup=false;
    int level=1;

 sf:: Music musicgame;
  		     musicgame.openFromFile("img/Tetris-Theme-Tetris-Soundtrack.wav");

  		     musicgame.setVolume(300);

    //#################################-------------------------------------###########################################



    while (window.isOpen())
    {	levelup=true;


  		         musicgame.play();
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //player will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
	if (Keyboard::isKeyPressed(Keyboard::P)) // If down key is pressed
	{
		bool dik=1;
			resume=1;
			res2=0;

		while(resume)
		{
			window.clear();
			window.draw(Pause);
			window.display();
			if (Keyboard::isKeyPressed(Keyboard::R)) // If down key is pressed
			{
				while(res2!=4)
								{window.clear();
								window.draw(background);
								window.draw(sidemenu);

									float time = clock.getElapsedTime().asSeconds();
									        clock.restart();
									        timer += time;
								if(dik)
								{dik=0;
								res1=timer;
								}
								res2=timer-res1;
								switch (res2)
								{
								case 1:
									window.draw(num3);

									break;

								case 2:
									window.draw(num2);

									break;

								case 3:
									window.draw(num1);
								//resume=0;
									break;
								case 4:
									window.draw(num3);
									resume=0;
									break;



								}
								if (Keyboard::isKeyPressed(Keyboard::Escape)) // If down key is pressed
										{       window.close();
										resume=0;
										}

				window.display();
								}
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) // If down key is pressed
					           window.close();

		}



	}
	if(lives<=0)
	{resume=1;

			outputFile.open(filename, ios::app);
			outputFile << Score << endl;
	                    outputFile.close();


		while (resume)
		{
			window.clear();
					window.draw(over);
					if (Keyboard::isKeyPressed(Keyboard::R)) // If down key is pressed
					{resume=0;
					level=0;
					text.setPosition(1050, 200);
					Score=0;
					restart=1;
					lives=3;
					temp=0;
					powerup=0;
					powerup2=0;
					powerup3=0;
					monsterincoming=true;
					dragoncoming=true;
					sometime=0;

					}
					if (Keyboard::isKeyPressed(Keyboard::Escape)) // If down key is pressed
							           window.close();
					text.setPosition(550,600);

					window.draw(gameover);
					window.draw(line1);
					window.draw(a);
					window.draw(highscore);
					window.draw(text);
					window.display();
					text.setPosition(1050, 200);

		}
	}

	Timee.setString(std::to_string(temp));
	 text.setString(std::to_string(Score));

	

            
	////////////////////////////////////////////////
	/////  Call your functions here            ////
	//////////////////////////////////////////////
if(level==8)
	sometemp=temp;
if(level>=8)
{
	sometime=temp-sometemp;
	if(sometime==10)
	monsterincoming=false;
	if (sometime==50)
	{
		monsterincoming=true;
		if (lives>0)
			Score+=50;
		sometime=0;
	}
}

if(level==5)
	sometemp=temp;
if(level>=4 )
{
cout<<sometime<<endl;
	sometime=temp-sometemp;
	if(sometime==10)
	dragoncoming=false;
	if (sometime==50)
	{
		dragoncoming=true;
		if(lives>0)
			Score+=40;
		sometime=0;
	}
}
if(level>=7)
	dragoncoming=1;

	temp2++;
	temp=timer;

	if(temp>13)
	sign->movedanger();
	powerup=p->incontact(sign->positionx, sign->positiony);

		if(temp>9)
		life->movedanger();
	powerup2=p->incontact(life->positionx,life->randomy);


			if(temp>5)
			multifire->movedanger();
			if(firee)
	powerup3=p->incontact(multifire->positionx, multifire->positiony);
if(firee)
	firechala=powerup3;
	if(temp2%150==0)
		{

		for(int i=0;i<18;i++)
			{bombcheck=1;

				for (int j=0;j<18;j++)
				{
					if(i==array[j])
					bombcheck=0;
				}


								if(i%2==0)
				if(temp%3==0)
								{
								if(bombcheck)
								{
									bomb[b]=new Bullet(enmy->positionx[i]+37,enmy->positiony[i],type);
											b++;
								}
								}

				else if(i%3==0)
				 if(temp%5==0)
								{
								if(bombcheck)
								{
									bomb[b]=new Bullet(enmy->positionx[i]+37,enmy->positiony[i],type);
											b++;
								}
								}
				else


										{
										if(bombcheck)
										{
											bomb[b]=new Bullet(enmy->positionx[i]+37,enmy->positiony[i],type);
													b++;
										}
										}
			}

		}







	/*-----------------multiple	 bullet----------------------*/
if(firechala==1)
{
	if (firee==1)
	{
		temp3=temp;
		firee=0;
		//cout<<temp3<<endl;
	}
 if(powerup3==1)
 {

	if(temp2%10==0)
		{
	stream[y]=new Bullet*[5];
	l=p->positionx-63;
	//for(int i=0;i<y;i++)
		p->firestream(stream[y],l,p->positiony,y);
			y++;
		}

	for( int i=0;i<y;i++)
		for(int j=0;j<4;j++)
				check=enmy->contact(stream[i][j]->positionx,stream[i][j]->positiony,array,destroyed,numenemy);
	Score+=(10*destroyed*multiplier);
			destroyed=0;
 }
 if(temp==temp3+5)
 {
	 firechala=0;
 }

}


	/*------------multiple bullet end--------------------*/






	for(int j=0;j<y;j++)
		{
			for(int i=0 ;i<5;i++)
				{
				stream[j][i]->move();
				}

		}




	enmy->Movement(move);
	//cout<<enemycolion<<endl;
	if(!enemycolion)
	{
	for(int i=0;i<numenemy;i++)
	{
	enemycolion=p->enemycollison(enmy->positionx[i], enmy->positiony[i]);
	if (enemycolion)
	{
break;
	}

	}
    }

	if(enemycolion)
	{
		if(!temp5)
		{
			temp5=temp;
			lives--;
		}

		if(temp-temp5==0)
		{
			coll1.setPosition(p->positionx, p->positiony+100);

		}
		if(temp-temp5==1)
				{

			coll1.setPosition(p->positionx, p->positiony+200);

				}
		if(temp-temp5==2)
				{

			coll1.setPosition(p->positionx, p->positiony+300);
				}
		if(temp-temp5==3)
		{
			enemycolion=0;
			temp5=0;
			p->sprite.setPosition(p->x, p->y);
			p->positionx=p->x;
			p->positiony=p->y;
		}

	}






	//window.draw(monster->monster);

	window.clear(Color::Black); //clears the screen

	window.draw(background);  // setting background
	if(!enemycolion)
	window.draw(p->sprite);
	window.draw(sidemenu);
	window.draw(text);
	window.draw(score);
	window.draw(Time);
	window.draw(Timee);
	if(temp-temp5<=0)
	window.draw(coll1);
	if(temp-temp5<=1)
	window.draw(coll2);
	if( temp - temp5<=3)
	window.draw(coll3);

	if (temp>13)
	window.draw(sign->addon);

	if (temp>9)
		window.draw(life->addon);
	if(!firechala)
	if (temp>5)
		window.draw(multifire->addon);




	// setting player on screen
	for(int i=0;i<y;i++)
	{
		for( int j=0;j<5;j++)
		window.draw(stream[i][j]->bullet);
	}




	/*--------------enemy display_______*/
	if( monsterincoming && dragoncoming)
	{
		for(int i=0;i<lives;i++)
				window.draw(p->heart[i]);
		for(int i=0;i<b;i++)
				window.draw(bomb[i]->bomb);
		for(int i=0;i<b;i++)
					enmy->bombdrop(bomb[i]);



		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@---------------- bulllett firrreeeee--------------------------------
		if(!enemycolion)
		{

		if (firechala==0)
		{
		if(temp2%10==0)
		{
			gun[sec]=new Bullet(p->positionx+37,p->positiony,type);
			sec++;
		}
		for (int i=0;i<sec;i++)
				p->fire(gun[i]);

		for(int i=0;i<sec;i++)
						window.draw(gun[i]->bullet);


		for( int i=0;i<sec;i++)
					check=enmy->contact(gun[i]->positionx,gun[i]->positiony,array,destroyed,numenemy);
		Score+=(10*destroyed*multiplier);
		destroyed=0;

		}
		}




		for( int i=0;i<b;i++)
		{bom	=p->contactbom(bomb[i]->positionx,bomb[i]->positiony);
		if (timedekh==1)
		{
		if (bom==1)
		{	lives--;
		timedekh=0;
		temp3=temp;
		}
		if (powerup==1)
		{
			lives--;
			timedekh=0;
			temp3=temp;
		}
		if (powerup2==1)
		{
			lives++;
			timedekh=0;
					temp3=temp;
		}
		}

		if(timedekh==0)
			if(temp==temp3+2)
				timedekh=1;
		}


	for(int i=0;i<numenemy;i++)
	{check=1;

	for (int j=0;j<numenemy;j++)
	{
		if(i==array[j])
			check=0;

	}

		if(check)
		{
		window.draw(enmy->enm[i]);
		levelup=false;
		}


	}


	if(levelup || restart)
	{	level++;

	switch(level)
	{
	case 1:
		restart=0;
		enmy->rect();
		for(int i=0;i<20;i++)
				     array[i]=-1;
		break;

	case 2:
enmy->triangle();
		for(int i=0;i<20;i++)
		     array[i]=-1;
		break;
	case 3:

		enmy->cross();
		for(int i=0;i<20;i++)
		     array[i]=-1;
		break;

	case 4:
	level++;
	break;

	case 5:
		enmy->circle();
		for(int i=0;i<20;i++)
		array[i]=-1;
		multiplier=2;
				break;
		case 6:
				enmy->diamond();
				for(int i=0;i<20;i++)
				     array[i]=-1;
				break;
		case 7:
				enmy->heart();
				for(int i=0;i<20;i++)
				     array[i]=-1;
				break;
		case 8:
			numenemy=30;
					enmy->filledcircle();
						for(int i=0;i<20;i++)
						     array[i]=-1;
						break;
		case 9:
						enmy->heart();
						for(int i=0;i<20;i++)
						     array[i]=-1;
						break;
		case 10:
						enmy->heart();
						for(int i=0;i<20;i++)
						     array[i]=-1;
						break;

	}

	}


	}

	//----------------------------------------dragon --------------------------------------------

if(sometime>10 && sometime<50)
{


	if (!monsterincoming)
	{
		for(int i=0;i<lives;i++)
				window.draw(p->heart[i]);
		window.draw(monster->monster);
		//window.draw(monster->laser1);
		//window.draw(monster->laser2);
		window.draw(monster->head1);
		window.draw(monster->head2);
		monster->moving(p->positionx);
		if(sometime==10  || sometime==25 || sometime==35  ||  sometime ==43)
		{monster->displayfire(1);
			window.draw(monster->laser);
			window.draw(monster->laser1);
			window.draw(monster->laser2);
		}
		if (sometime>10 && sometime<=11  || sometime>25 && sometime<=26  ||  sometime>=35 && sometime<=36  ||  sometime>43 && sometime<=44)
		{
			monster->displayfire(2);
			window.draw(monster->laser);
			window.draw(monster->laser1);
			window.draw(monster->laser2);
		}
		if (sometime>11  &&  sometime<16 || sometime>26 && sometime<30 ||  sometime>36 && sometime<=40  ||  sometime>44 && sometime<=48)
			{
				monster->displayfire(3);
				window.draw(monster->laser);
				window.draw(monster->laser1);
				window.draw(monster->laser2);
				if (temp2%40==0)
		lasercolion=monster->lasercollision(p->positionx, p->positiony);
			}



		//cout<<lasercolion;

		if (temp2%40==0)

		if(lasercolion)
		{
			lives--;
		}

		lasercolion=false;
	}
}


	/*---------------------------------*/



//------------------------------------monsterr------------------------------------------




if(sometime>10 && sometime<50)
{


	if (!dragoncoming)
	{
		for(int i=0;i<lives;i++)
				window.draw(p->heart[i]);
		window.draw(dragon->monster);

		dragon->moving(p->positionx);
		if(sometime==10  || sometime==25 || sometime==35  ||  sometime ==43)
		{monster->displayfire(1);
			window.draw(dragon->laser);

		}
		if (sometime>10 && sometime<=11  || sometime>25 && sometime<=26  ||  sometime>=35 && sometime<=36  ||  sometime>43 && sometime<=44)
		{
			monster->displayfire(2);
			window.draw(dragon->laser);

		}
		if (sometime>11  &&  sometime<16 || sometime>26 && sometime<30 ||  sometime>36 && sometime<=40  ||  sometime>44 && sometime<=48)
			{
				monster->displayfire(3);
				window.draw(dragon->laser);

				if (temp2%40==0)
		lasercolion=dragon->lasercollision(p->positionx,p->positiony);
			}


		//cout<<lasercolion;

		if (temp2%40==0)

		if(lasercolion)
		{
			lives=0;
		}

		lasercolion=false;
	}
}









	if (runtime>=100)
		{
			move=-1;
			runtime=-100;
		}
	if(runtime>=0 && runtime<100)
		move=1;

	runtime++;
//	cout<<runtime;






	window.display();
    }



}


};
