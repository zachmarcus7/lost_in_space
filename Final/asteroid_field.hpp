/****************************************************************
* File name:   asteroid_field.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Asteroid_Field class. It's the
* second zone of the game. It's also derived from the space class.
*****************************************************************/

#include "space.hpp"

#ifndef ASTEROID_FIELD_H
#define ASTEROID_FIELD_H

class Asteroid_Field : public Space
{
	public:
		Asteroid_Field(Player*);
		~Asteroid_Field();
		virtual void set_map(char**);
		virtual void radar_text();
};
#endif