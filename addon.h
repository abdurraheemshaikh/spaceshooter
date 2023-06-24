/*
 * addon.h
 *
 *  Created on: May 10, 2023
 *      Author: abdur
 */

#ifndef ADDON_H_
#define ADDON_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include <time.h>
#include<cstdlib>
using namespace sf;

class addons{
public:

	Texture tes;
	Sprite addon;
	int randomx=350,randomy=-20;
	float positionx=350,positiony=-20;
			int speed=1;

	 addons();
	virtual ~addons();
	virtual void movedanger()=0;

};




#endif /* ADDON_H_ */
