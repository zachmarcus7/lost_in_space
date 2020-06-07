/****************************************************************
* File name:   alien_corridor.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Alien_Corridor class. It's the
* third zone of the game. It's also derived from the Space class.
*****************************************************************/

#include "space.hpp"

#ifndef ALIEN_CORRIDOR_H
#define ALIEN_CORRIDOR_H

class Alien_Corridor : public Space
{
public:
	Alien_Corridor(Player*);
	~Alien_Corridor();
	virtual void set_map(char**);
	virtual void radar_text();
};
#endif
