/****************************************************************
* File name:   space.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for Space class. It's the abstract
* class that all the maps in the game are derived from. It 
* contains member variables for ptrs to surrounding zones, checker
* functions, and a pure abstract function that sets up the current 
* zone's map.
*****************************************************************/

#include "player.hpp"
#include <iostream>
#include <string>

#ifndef SPACE_H
#define SPACE_H

class Space
{
	protected:
		Space* top;
		Space* right;
		Space* bottom;
		Space* left;
		Player* p1;
		int total_rows;
		int total_columns;
		std::string location;
		std::string description;

		//variables for items
		bool got_fuel;
		bool got_item;
		bool got_item_2;
		int used_item;
		bool used_item_2;
		bool use_check;

	public:
		Space();
		~Space();
		
		//map functions
		virtual void set_map(char**) = 0;
		char** create_map();
		int get_rows() const;
		int get_columns() const;
		void move_player(char, char**);
		void print_map(char**);

		//description functions
		void get_location();
		void get_description();

		//pointer setters to link maps
		void set_top(Space*);
		void set_right(Space*);
		void set_bottom(Space*);
		void set_left(Space*);

		//used item functions
		bool check_used_item_2();

		//text function
		virtual void radar_text();

};
#endif