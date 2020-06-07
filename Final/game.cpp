/****************************************************************
* File name:   game.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for game class. It contains
* a constructor, a destructor, a function to run the game, and
* a function that displays information for user's options.
*****************************************************************/

#include "game.hpp"


/****************************************************************
* Default constructor.
*****************************************************************/

Game::Game()
{
	//checker variables for each level
	first_level = false;
	second_level = false;
	third_level = false;
	fourth_level = false;
	fifth_level = false;
	sixth_level = false;

	//extra checker variables
	run_game = true;
	player_won = false;
	first_check = true;

	//zone pointers
	inner_ptr = NULL;
	asteroid_ptr = NULL;
	alien_ptr = NULL;
	side_ptr = NULL;
	vortex_ptr = NULL;
	mother_ptr = NULL;

	//map pointers
	map1 = NULL;
	map2 = NULL;
	map3 = NULL;
	map4 = NULL;
	map5 = NULL;
	map6 = NULL;

	//player pointer
	p1 = NULL;
}


/****************************************************************
* Destructor.
*****************************************************************/

Game::~Game()
{
	//delete level pointers and corresponding map arrays;
	if (inner_ptr != NULL)
	{
		for (int row = 0; row < inner_ptr->get_rows(); row++)
		{
			delete[] map1[row];
		}
		delete[] map1;

		delete inner_ptr;
		inner_ptr = NULL;
	}

	if (asteroid_ptr != NULL)
	{
		for (int row = 0; row < asteroid_ptr->get_rows(); row++)
		{
			delete[] map2[row];
		}
		delete[] map2;

		delete asteroid_ptr;
		asteroid_ptr = NULL;
	}

	if (alien_ptr != NULL)
	{
		for (int row = 0; row < alien_ptr->get_rows(); row++)
		{
			delete[] map3[row];
		}
		delete[] map3;

		delete alien_ptr;
		alien_ptr = NULL;
	}

	if (side_ptr != NULL)
	{
		for (int row = 0; row < side_ptr->get_rows(); row++)
		{
			delete[] map4[row];
		}
		delete[] map4;

		delete side_ptr;
		side_ptr = NULL;
	}

	if (vortex_ptr != NULL)
	{
		for (int row = 0; row < vortex_ptr->get_rows(); row++)
		{
			delete[] map5[row];
		}
		delete[] map5;

		delete vortex_ptr;
		vortex_ptr = NULL;
	}

	if (mother_ptr != NULL)
	{
		for (int row = 0; row < mother_ptr->get_rows(); row++)
		{
			delete[] map6[row];
		}
		delete[] map6;

		delete mother_ptr;
		mother_ptr = NULL;
	}


	//deallocate player
	delete p1;
	p1 = NULL;
}


/****************************************************************
* Function for playing game.
*****************************************************************/

void Game::play_game()
{
	//output intro
	std::cout << "You're the captain of a ship that was part of a fleet\n";
	std::cout << "making its way towards an earth-like planet to build a new\n";
	std::cout << "society. However, just as the fleet entered into unprotected\n";
	std::cout << "territory, there were some unexpected engine failures, and\n";
	std::cout << "before anyone on board knew what had happened, the ship plunged\n";
	std::cout << "into a sea of asteroids. It's now up to you to make it out of the\n";
	std::cout << "asteroid sea and safely return to the fleet.\n";
	std::cout << "Press enter to continue." << std::endl;
	std::cin.get();


	//initialize player
	p1 = new Player;

	//initialize first map
	inner_ptr = new Inner_Belt(p1);
	map1 = inner_ptr->create_map();
	first_level = true;

	//print initial position and starting area
	inner_ptr->set_map(map1);
	inner_ptr->print_map(map1);
	p1->display_fuel();
	inner_ptr->get_location();
	inner_ptr->get_description();
	p1->display_storage();
	move_info();

	char answer = ' ';


	while (run_game == true && p1->is_alive() == true)
	{
		while (first_level == true)
		{

			if (p1->is_alive() == false)
			{
				first_level = false;
				run_game = false;
			}
			else if ((p1->get_x() == 0) && (p1->get_y() == 6)) // if player makes it to next level
			{
				first_level = false;
				second_level = true;

				//if asteroid_ptr hasn't been initialized 
				if (asteroid_ptr == NULL)
				{
					asteroid_ptr = new Asteroid_Field(p1);
					map2 = asteroid_ptr->create_map();

					//link the zones
					inner_ptr->set_top(asteroid_ptr);
					asteroid_ptr->set_bottom(inner_ptr);
				}
				p1->set_x(13);
				p1->set_y(4);
			}
			else
			{
				if (first_check == true)
				{
					//get answer and move player
					std::cin >> answer;
					inner_ptr->move_player(answer, map1);
				}

				//output info
				inner_ptr->set_map(map1);
				inner_ptr->print_map(map1);
				p1->display_fuel();
				inner_ptr->get_location();
				inner_ptr->get_description();
				p1->display_storage();
				move_info();
				first_check = true;
				std::cout << std::endl;

			}


		}
		while (second_level == true)
		{
			if (p1->is_alive() == false)
			{
				second_level = false;
				run_game = false;
			}
			else if ((p1->get_x() == 0) && (p1->get_y() == 25)) //if player makes it to next level
			{
				second_level = false;
				third_level = true;

				//if next ptr hasn't been initialized 
				if (alien_ptr == NULL)
				{
					alien_ptr = new Alien_Corridor(p1);
					map3 = alien_ptr->create_map();

					//link the zones
					alien_ptr->set_bottom(asteroid_ptr);
					asteroid_ptr->set_top(alien_ptr);
				}
				p1->set_x(17);
				p1->set_y(2);
			}
			else if ((p1->get_x() == 14) && (p1->get_y() == 4)) //if player goes back
			{
				second_level = false;
				first_level = true;
				p1->set_x(1);
				p1->set_y(6);
				first_check = false;
			}
			else
			{
				asteroid_ptr->set_map(map2);
				asteroid_ptr->print_map(map2);
				p1->display_fuel();
				asteroid_ptr->get_location();
				asteroid_ptr->get_description();
				p1->display_storage();
				move_info();

				//get answer and move player
				std::cin >> answer;
				asteroid_ptr->move_player(answer, map2);

				asteroid_ptr->set_map(map2);
				asteroid_ptr->print_map(map2);
				p1->display_fuel();
				asteroid_ptr->get_location();
				asteroid_ptr->get_description();
				p1->display_storage();
				move_info();
			}

		}
		while (third_level == true)
		{
			if (p1->is_alive() == false)
			{
				third_level = false;
				run_game = false;
			}
			else if ((p1->get_x() == 18) && (p1->get_y() == 2)) //if player goes back
			{
				third_level = false;
				second_level = true;
				p1->set_x(1);
				p1->set_y(25);
			}
			else if ((p1->get_x() == 14) && (p1->get_y() == 0)) //if player goes into side_cluster
			{
				third_level = false;
				fourth_level = true;

				//if next ptr hasn't been initialized 
				if (side_ptr == NULL)
				{
					side_ptr = new Side_Cluster(p1);
					map4 = side_ptr->create_map();

					//link the zones
					alien_ptr->set_left(side_ptr);
					side_ptr->set_right(alien_ptr);
				}
				p1->set_x(8);
				p1->set_y(15);
			}
			else if ((p1->get_x() == 0) && (p1->get_y() == 4)) //if player goes into vortex
			{
				third_level = false;
				fifth_level = true;

				//if next ptr hasn't been initialized 
				if (vortex_ptr == NULL)
				{
					vortex_ptr = new Vortex(p1);
					map5 = vortex_ptr->create_map();

					//link the zones
					alien_ptr->set_top(vortex_ptr);
					vortex_ptr->set_bottom(alien_ptr);
				}
				p1->set_x(17);
				p1->set_y(4);
			}
			else
			{
				alien_ptr->set_map(map3);
				alien_ptr->print_map(map3);
				p1->display_fuel();
				alien_ptr->get_location();
				alien_ptr->get_description();
				p1->display_storage();
				move_info();

				//get answer and move player
				std::cin >> answer;
				alien_ptr->move_player(answer, map3);

				alien_ptr->set_map(map3);
				alien_ptr->print_map(map3);
				p1->display_fuel();
				alien_ptr->get_location();
				alien_ptr->get_description();
				p1->display_storage();
				move_info();
			}
		}
		while (fourth_level == true)
		{

			if (p1->is_alive() == false)
			{
				fourth_level = false;
				run_game = false;
			}
			else if ((p1->get_x() == 8) && (p1->get_y() == 16)) //if player goes back
			{
				fourth_level = false;
				third_level = true;
				p1->set_x(14);
				p1->set_y(1);
			}
			else
			{
				side_ptr->set_map(map4);
				side_ptr->print_map(map4);
				p1->display_fuel();
				side_ptr->get_location();
				side_ptr->get_description();
				p1->display_storage();
				move_info();

				//get answer and move player
				std::cin >> answer;
				side_ptr->move_player(answer, map4);

				side_ptr->set_map(map4);
				side_ptr->print_map(map4);
				p1->display_fuel();
				side_ptr->get_location();
				side_ptr->get_description();
				p1->display_storage();
				move_info();
			}
		}
		while (fifth_level == true)
		{
			if (p1->is_alive() == false)
			{
				fifth_level = false;
				run_game = false;
			}
			else if ((p1->get_x() == 18) && (p1->get_y() == 4)) //if player goes back
			{
				fifth_level = false;
				third_level = true;
				p1->set_x(1);
				p1->set_y(4);
			}
			else if ((p1->get_x() == 4) && (p1->get_y() == 38)) //if player goes into final area
			{
				fifth_level = false;
				sixth_level = true;

				//if next ptr hasn't been initialized 
				if (mother_ptr == NULL)
				{
					mother_ptr = new Mother_Ship(p1);
					map6 = mother_ptr->create_map();

					//link the zones
					mother_ptr->set_left(vortex_ptr);
					vortex_ptr->set_right(mother_ptr);
				}
				p1->set_x(10);
				p1->set_y(1);
			}
			else
			{
				vortex_ptr->set_map(map5);
				vortex_ptr->print_map(map5);
				p1->display_fuel();
				vortex_ptr->get_location();
				vortex_ptr->get_description();
				p1->display_storage();
				move_info();

				//get answer and move player
				std::cin >> answer;
				vortex_ptr->move_player(answer, map5);

				vortex_ptr->set_map(map5);
				vortex_ptr->print_map(map5);
				p1->display_fuel();
				vortex_ptr->get_location();
				vortex_ptr->get_description();
				p1->display_storage();
				move_info();
			}
		}
		while (sixth_level == true)
		{
			if (p1->is_alive() == false)
			{
				sixth_level = false;
				run_game = false;
			}
			else if ((p1->get_x() == 10) && (p1->get_y() == 0)) //if player goes back
			{
				sixth_level = false;
				fifth_level = true;
				p1->set_x(4);
				p1->set_y(37);
			}
			else if ((p1->get_x() == 0) && (p1->get_y() == 18)) //if player makes it to end
			{
				sixth_level = false;
				run_game = false;
				player_won = true;
			}
			else
			{
				mother_ptr->set_map(map6);
				mother_ptr->print_map(map6);
				p1->display_fuel();
				mother_ptr->get_location();
				mother_ptr->get_description();
				p1->display_storage();
				move_info();

				//get answer and move player
				std::cin >> answer;
				mother_ptr->move_player(answer, map6);

				mother_ptr->set_map(map6);
				mother_ptr->print_map(map6);
				p1->display_fuel();
				mother_ptr->get_location();
				mother_ptr->get_description();
				p1->display_storage();
				move_info();
			}
		}


	}

	//end display
	if (p1->is_alive() == false)
	{
		std::cout << std::endl << "Game over ..." << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "You've won the game!\n";
		std::cout << "After getting out of the sea of asteroids and making it past\n";
		std::cout << "the horde of alien ships, your ship will be able\n";
		std::cout << "to safely make it back to the rest of the remaining fleet\n";
		std::cout << "and, eventually, to a new planet." << std::endl << std::endl;
	}
}


/****************************************************************
* Function that outputs movement information.
*****************************************************************/

void Game::move_info()
{
	std::cout << "(w)-up (a)-left (s)-down (d)-right (r)-toggle (c)-use item (y)-exit" << std::endl;
}