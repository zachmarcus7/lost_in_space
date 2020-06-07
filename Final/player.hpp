/****************************************************************
* File name:   player.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for player class. It contains
* member variables for the player's current coordinates, also
* current fuel, and items in storage. There are function
* declarations for a constructor, destructor, setters, getters,
* and check functions.
*****************************************************************/

#include <iostream>
#include <climits>
#include <iomanip>
#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		int fuel;
		int x;
		int y;
		char storage[5][1];		

	public:
		Player();
		~Player();

		//fuel functions
		void add_fuel(int);
		void subtract_fuel(int);
		int get_fuel() const;
		void display_fuel();

		//coordinate functions
		void set_x(int);
		void set_y(int);
		int get_x();
		int get_y();
		void move(char);

		//storage functions
		void display_storage();
		void add_item(char);
		int use_item();
		int check_prompt(int, int);

		bool is_alive();

};
#endif