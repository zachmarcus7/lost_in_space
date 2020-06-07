/****************************************************************
* File name:   vortex.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Vortex class. It's the
* fifth zone of the game. It's also derived from the Space class.
*****************************************************************/

#include "space.hpp"

#ifndef VORTEX_H
#define VORTEX_H

class Vortex : public Space
{
public:
	Vortex(Player*);
	~Vortex();
	virtual void set_map(char**);
	virtual void radar_text();
};
#endif