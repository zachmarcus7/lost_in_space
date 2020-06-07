/****************************************************************
* File name:   menu.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Menu class. It contains
* the functions for starting the game and exiting.
*****************************************************************/

#include "game.hpp"

#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	Menu();
	~Menu();
	void run();
	int check_prompt(int, int);
	int end_prompt();
};
#endif