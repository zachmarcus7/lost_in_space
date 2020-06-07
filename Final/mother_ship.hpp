/****************************************************************
* File name:   mother_ship.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Mother_Ship class. It's the
* final zone of the game. It's also derived from the Space class.
*****************************************************************/

#include "space.hpp"

#ifndef MOTHER_SHIP_H
#define MOTHER_SHIP_H

class Mother_Ship : public Space
{
public:
	Mother_Ship(Player*);
	~Mother_Ship();
	virtual void set_map(char**);
	virtual void radar_text();
};
#endif
