/****************************************************************
* File name:   game.hpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Specification file for game class. It contains 
* member variables necessary for keeping the game going, and also
* functions for running the game and displaying the game's info.
*****************************************************************/

#include "space.hpp"
#include "inner_belt.hpp"
#include "asteroid_field.hpp"
#include "alien_corridor.hpp"
#include "side_cluster.hpp"
#include "vortex.hpp"
#include "mother_ship.hpp"
#include "player.hpp"
#include <iostream>

#ifndef GAME_H
#define GAME_H

class Game
{
private:
	//checker variables for each level
	bool first_level;
	bool second_level;
	bool third_level;
	bool fourth_level;
	bool fifth_level;
	bool sixth_level;

	// extra checker variables
	bool run_game;
	bool player_won;
	bool first_check;

	//zone pointers
	Inner_Belt* inner_ptr;
	Asteroid_Field* asteroid_ptr;
	Alien_Corridor* alien_ptr;
	Side_Cluster* side_ptr;
	Vortex* vortex_ptr;
	Mother_Ship* mother_ptr;

	//player pointer
	Player* p1;

	//map pointers
	char** map1;
	char** map2;
	char** map3;
	char** map4;
	char** map5;
	char** map6;

public:
	Game();
	~Game();
	void play_game();
	void move_info();
};
#endif
