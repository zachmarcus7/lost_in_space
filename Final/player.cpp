/****************************************************************
* File name:   player.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for player class. There's a 
* constructor, destructor, functions for adding fuel and items,
* functions for displaying the player's information, a function
* for moving the character, and a check prompt.
*****************************************************************/

#include "player.hpp"


/****************************************************************
* Default constructor. Fuel is set at 300. Blank inventory slots
* are set to -. x and y coordinates set to 12 and 18.
*****************************************************************/

Player::Player()
{
	fuel = 300;
	x = 12;
	y = 18;
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 1; j++)
			storage[i][j] = '-';
}


/****************************************************************
* Destructor.
*****************************************************************/

Player::~Player()
{

}


/****************************************************************
* Function for adding fuel.
*****************************************************************/

void Player::add_fuel(int more_fuel)
{
	fuel += more_fuel;
}


/****************************************************************
* Function for subtracting fuel.
*****************************************************************/

void Player::subtract_fuel(int less_fuel)
{
	fuel -= less_fuel;

	if (fuel < 0)
		fuel = 0;
}


/****************************************************************
* Function that returns the amount of fuel the player has left.
*****************************************************************/

int Player::get_fuel() const
{
	return fuel;
}


/****************************************************************
* Function for displaying remaining fuel.
*****************************************************************/

void Player::display_fuel()
{
	std::cout << "::: Dashboard :::" << std::endl;
	std::cout << "Fuel: " << fuel << "(+)" << std::endl;
}


/****************************************************************
* Setter for x coordinate.
*****************************************************************/

void Player::set_x(int x)
{
	this->x = x;
}


/****************************************************************
* Setter for y coordinate.
*****************************************************************/

void Player::set_y(int y)
{
	this->y = y;
}


/****************************************************************
* Getter for x coordinate.
*****************************************************************/

int Player::get_x()
{
	return x;
}


/****************************************************************
* Getter for y coordinate.
*****************************************************************/

int Player::get_y()
{
	return y;
}


/****************************************************************
* Function for moving player.
*****************************************************************/

void Player::move(char input)
{
	switch (input)
	{
	case 'w':
		x--;
		break;
	case 'a':
		y--;
		break;
	case 'd':
		y++;
		break;
	case 's':
		x++;
		break;
	}
}


/****************************************************************
* Function that displays items in storage.
*****************************************************************/

void Player::display_storage()
{
	std::cout << "Storage: ";

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 1; j++)
			std::cout << i + 1 << "." << storage[i][j] << " ";
	}

	std::cout << std::endl;
}


/****************************************************************
* Function that adds item to storage.
*****************************************************************/

void Player::add_item(char item)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 1; j++)
			if (storage[i][j] == '-')
			{
				storage[i][j] = item;
				return;
			}

	}
}


/****************************************************************
* Function that uses item in storage.
*****************************************************************/

int Player::use_item()
{
	int choice = 0;

	std::cout << "Which item would you like to use?" << std::endl;
	std::cout << "Enter (1-5):" << std::endl;

	choice = check_prompt(5,1);

	//if user chooses to use item 1
	if (choice == 1)
	{
		if (storage[0][0] == '+')
		{
			fuel += 50;
			storage[0][0] = '-';
			return 1;
		}
		else if (storage[0][0] == '-')
		{
			return 0;
		}
		else if (storage[0][0] == '@')
		{
			storage[0][0] = '-';
			return 2;
		}
		else if (storage[0][0] == '$')
		{
			storage[0][0] = '-';
			return 2;
		}
		else
			return 0;
	}
	else if (choice == 2)
	{
		if (storage[1][0] == '+')
		{
			fuel += 50;
			storage[1][0] = '-';
			return 1;
		}
		else if (storage[1][0] == '-')
		{
			return 0;
		}
		else if (storage[1][0] == '@')
		{
			storage[1][0] = '-';
			return 2;
		}
		else if (storage[1][0] == '$')
		{
			storage[1][0] = '-';
			return 2;
		}
		else
			return false;
	}
	else if (choice == 3)
	{
		if (storage[2][0] == '+')
		{
			fuel += 50;
			storage[2][0] = '-';
			return 1;
		}
		else if (storage[2][0] == '-')
		{
			return 0;
		}
		else if (storage[2][0] == '@')
		{
			storage[2][0] = '-';
			return 2;
		}
		else if (storage[2][0] == '$')
		{
			storage[2][0] = '-';
			return 2;
		}
		else
			return 0;
	}
	else if (choice == 4)
	{
		if (storage[3][0] == '+')
		{
			fuel += 50;
			storage[3][0] = '-';
			return 1;
		}
		else if (storage[3][0] == '-')
		{
			return 0;
		}
		else if (storage[3][0] == '@')
		{
			storage[3][0] = '-';
			return 2;
		}
		else if (storage[3][0] == '$')
		{
			storage[3][0] = '-';
			return 2;
		}
		else
			return 0;
	}
	else if (choice == 5)
	{
		if (storage[4][0] == '+')
		{
			fuel += 50;
			storage[4][0] = '-';
			return 1;
		}
		else if (storage[4][0] == '-')
		{
			return 0;
		}
		else if (storage[4][0] == '@')
		{
			storage[4][0] = '-';
			return 2;
		}
		else if (storage[4][0] == '$')
		{
			storage[4][0] = '-';
			return 2;
		}
		else
			return 0;
	}
	else
		return false;
	
}


/****************************************************************
* Function that checks if the user entered a number between min and max.
*****************************************************************/

int Player::check_prompt(int max, int min)
{
	int answer = 0;

	std::cin >> std::setw(1) >> answer;

	while ((!std::cin.good()) || (!(answer >= min)) || (!(answer <= max)))
	{
		std::cout << "Invalid value entered." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Enter correct value:" << std::endl;
		//make sure only one integer is accepted
		std::cin >> std::setw(1) >> answer;
	}

	//clear the buffer
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	return answer;
}


/****************************************************************
* Function that returns a boolean depending on amount of fuel.
*****************************************************************/

bool Player::is_alive()
{
	if (fuel > 0)
		return true;
	else
		return false;
}