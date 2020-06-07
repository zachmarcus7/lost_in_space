/****************************************************************
* File name:   space.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Space class. It's the abstract
* class that all the maps in the game are derived from. It contains
* a constructor, a destructor, setters, getters, a function for
* creating a 2d array to store the map on, a function for displaying
* the array, and a function for getting the user's input to
* move the player or affect the map in a certain way.
*****************************************************************/

#include "space.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Space::Space()
{
	top = nullptr;
	right = nullptr;
	bottom = nullptr;
	left = nullptr;
	total_rows = 0;
	total_columns = 0;
	got_fuel = false;
	got_item = false;
	got_item_2 = false;
	used_item = 0;
	used_item_2 = false;
	use_check = false;
	location = " ";
	description = " ";
}


/****************************************************************
* Destructor.
*****************************************************************/

Space::~Space()
{

}


/****************************************************************
* Getter for rows.
*****************************************************************/

int Space::get_rows() const
{
	return total_rows;
}


/****************************************************************
* Destructor.
*****************************************************************/

int Space::get_columns() const
{
	return total_columns;
}


/****************************************************************
* Function that outputs current location.
*****************************************************************/

void Space::get_location()
{
	std::cout << "Location: " << location;
}


/****************************************************************
* Function that outputs description of current location.
*****************************************************************/

void Space::get_description()
{
	std::cout << std::endl << description << std::endl;
}


/****************************************************************
* Function that prints the map.
*****************************************************************/

void Space::print_map(char** arr)
{
	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			std::cout << arr[row][column];
		}
		std::cout << std::endl;
	}
}


/****************************************************************
* Function that creates a dynamically allocated 2d char array
* and returns it back to the program.
*****************************************************************/

char** Space::create_map()
{
	char** map = new char* [total_rows];
	for (int i = 0; i < total_rows; i++)
		map[i] = new char[total_columns];

	return map;
}


/****************************************************************
* Function that takes user's input and moves player.
*****************************************************************/

void Space::move_player(char input, char** arr)
{
	switch (input)
	{
		case 'w':
		{
			if ((arr[p1->get_x() - 1][p1->get_y()] != '*') &&
				(arr[p1->get_x() - 1][p1->get_y()] != '~'))
			{
				if (arr[p1->get_x() - 1][p1->get_y()] == '+')
				{
					got_fuel = true;
					p1->add_item('+');
				}

				if (arr[p1->get_x() - 1][p1->get_y()] == '@')
				{
					got_item = true;
					p1->add_item('@');
				}

				if (arr[p1->get_x() - 1][p1->get_y()] == '$')
				{
					got_item_2 = true;
					p1->add_item('$');
				}

				if ((arr[p1->get_x() - 1][p1->get_y()] == '&') &&
					(used_item_2 == false))
				{
					p1->subtract_fuel(200);
				}

				p1->move(input);
				p1->subtract_fuel(1);
			}
			break;
		}
		case 'a':
		{
			if ((arr[p1->get_x()][p1->get_y() - 1] != '*') &&
				(arr[p1->get_x()][p1->get_y() - 1] != '~'))
			{
				if (arr[p1->get_x()][p1->get_y() - 1] == '+')
				{
					got_fuel = true;
					p1->add_item('+');
				}

				if (arr[p1->get_x()][p1->get_y() - 1] == '@')
				{
					got_item = true;
					p1->add_item('@');
				}

				if (arr[p1->get_x()][p1->get_y() - 1] == '$')
				{
					got_item_2 = true;
					p1->add_item('$');
				}

				if ((arr[p1->get_x()][p1->get_y() - 1] == '&') &&
					(used_item_2 == false))
				{
					p1->subtract_fuel(200);
				}

				p1->move(input);
				p1->subtract_fuel(1);
			}
			break;
		}
		case 'd':
		{
			if ((arr[p1->get_x()][p1->get_y() + 1] != '*') &&
				(arr[p1->get_x()][p1->get_y() + 1] != '~'))
			{
				if (arr[p1->get_x()][p1->get_y() + 1] == '+')
				{
					got_fuel = true;
					p1->add_item('+');
				}

				if (arr[p1->get_x()][p1->get_y() + 1] == '@')
				{
					got_item = true;
					p1->add_item('@');
				}

				if (arr[p1->get_x()][p1->get_y() + 1] == '$')
				{
					got_item_2 = true;
					p1->add_item('$');
				}

				if ((arr[p1->get_x()][p1->get_y() + 1] == '&') &&
					(used_item_2 == false))
				{
					p1->subtract_fuel(200);
				}

				p1->move(input);
				p1->subtract_fuel(1);
			}
			break;
		}
		case 's':
		{
			if ((arr[p1->get_x() + 1][p1->get_y()] != '*') &&
				(arr[p1->get_x() + 1][p1->get_y()] != '~'))
			{
				if (arr[p1->get_x() + 1][p1->get_y()] == '+')
				{
					got_fuel = true;
					p1->add_item('+');
				}
				if (arr[p1->get_x() + 1][p1->get_y()] == '@')
				{
					got_item = true;
					p1->add_item('@');
				}

				if (arr[p1->get_x() + 1][p1->get_y()] == '$')
				{
					got_item_2 = true;
					p1->add_item('$');
				}

				if ((arr[p1->get_x() + 1][p1->get_y()] == '&') &&
					(used_item_2 == false))
				{
					p1->subtract_fuel(200);
				}

				p1->move(input);
				p1->subtract_fuel(1);
			}
			break;
		}
		case 'r':
		{
			if (arr[p1->get_x() - 1][p1->get_y()] == '~')
			{
				got_item = true;
			}

			if (arr[p1->get_x() - 1][p1->get_y()] == '?')
			{
				radar_text();
			}
			break;
		}
		case 'c':
		{
			used_item = p1->use_item();

			if (used_item == 2)
			{
				if (use_check == false)
				{
					used_item_2 = true;
					use_check = true;
				}
			}
			break;
		}
		case 'y':
		{
			int answer = 0;

			std::cout << "Exit the game?" << std::endl;
			std::cout << "(1) - yes" << std::endl;
			std::cout << "(2) - no" << std::endl;

			answer = p1->check_prompt(2, 1);

			if (answer == 1)
				p1->subtract_fuel(300);
		}
		default:
		{
			std::cout << "Command not found." << std::endl;
		}
	}
	
}

/****************************************************************
* Setter for top.
*****************************************************************/

void Space::set_top(Space* top)
{
	this->top = top;
}


/****************************************************************
* Setter for right.
*****************************************************************/

void Space::set_right(Space* right)
{
	this->right = right;
}


/****************************************************************
* Setter for bottom.
*****************************************************************/

void Space::set_bottom(Space* bottom)
{
	this->bottom = bottom;
}


/****************************************************************
* Setter for left.
*****************************************************************/

void Space::set_left(Space* left)
{
	this->left = left;
}


/****************************************************************
* Getter for the variable checking if user used special item.
*****************************************************************/

bool Space::check_used_item_2()
{
	return used_item_2;
}


/****************************************************************
* Function that outputs radar text.
*****************************************************************/

void Space::radar_text()
{
	std::cout << "No signal." << std::endl;
	std::cout << "Press enter to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
}