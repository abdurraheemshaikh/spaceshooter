/*
 * dangersign.h
 * [  *  Created on: May 10, 2023
 *      Author: abdur
 */

#ifndef DANGERSIGN_H_
#define DANGERSIGN_H_
#include <SFML/Graphics.hpp>
#include<string.h>
#include <time.h>
#include<cstdlib>
using namespace sf;


class dangersign {
public:
Texture h;
Sprite warning;


	dangersign()
{
		// TODO Auto-generated constructor stub
	h.loadFromFile("img/images.jpeg");
	warning.setTexture(h);
	warning.setPosition(100, 400);
}
 ~dangersign(){}


};

#endif /* DANGERSIGN_H_ */
