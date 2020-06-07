/****************************************************************
* File name:   inner_belt.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Inner_Belt class. It's the
* starting zone for the player. It's also derived from the Space
* class.
*****************************************************************/

#include "space.hpp"

#ifndef INNER_BELT_H
#define INNER_BELT_H

class Inner_Belt : public Space
{
	public:
		Inner_Belt(Player*);
		~Inner_Belt();
		virtual void set_map(char**);
		virtual void radar_text();
};
#endif