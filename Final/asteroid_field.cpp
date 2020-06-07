/****************************************************************
* File name:   asteroid_field.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Asteroid_Field class. It's the
* second zone of the game. Its main functions are setting up the
* map and also outputting radar information when toggled.
* Unlike other zones, map has asteroids that need to be blown up.
*****************************************************************/

#include "asteroid_field.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Asteroid_Field::Asteroid_Field(Player* p1) : Space()
{
	this->p1 = p1;
	total_rows = 15;
	total_columns = 35;
	location = "Asteroid Field";
	description = "Description:\nA lot more asteroids in here.\nIt doesn't look like there's a way out.";
}


/****************************************************************
* Destructor.
*****************************************************************/

Asteroid_Field::~Asteroid_Field()
{

}


/****************************************************************
* Function that sets up the map for the Asteroid_Field area.
*****************************************************************/

void Asteroid_Field::set_map(char** arr)
{
	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			if ((column == 25 && row == 0) && (used_item_2 != false))
				arr[row][column] = ' ';
			else if ((column == 4 && row == 14))
				arr[row][column] = ' ';
			else if ((column == 27 && row == 10))
				arr[row][column] = '*';
			else if ((column == 19 && row == 11) && (got_item == false))
				arr[row][column] = '@';
			else if ((column % 3 == 0 && row % 3 == 0) && (used_item_2 == false))
				arr[row][column] = '*';
			else if ((column == 10 && row == 10))
				arr[row][column] = '*';
			else if ((column == 4 && row == 2))
				arr[row][column] = '?';
			else if ((column == 14 && row == 2))
				arr[row][column] = '*';
			else if ((column == 24 && row == 8))
				arr[row][column] = '*';
			else if ((column == 10 && row == 11))
				arr[row][column] = '*';
			else if ((column == 8 && row == 13))
				arr[row][column] = '*';
			else if ((column == 13 && row == 5))
				arr[row][column] = '*';
			else if ((column == 10 && row == 7))
				arr[row][column] = '*';
			else if ((column == 11 && row == 8))
				arr[row][column] = '*';
			else if ((column == 0 && row == 0))
				arr[row][column] = '*';
			else if (row == (total_rows - 1) && column == 0)
				arr[row][column] = '*';
			else if (row == (total_rows - 1) && column == (total_columns - 1))
				arr[row][column] = '*';
			else if (column == 0)
				arr[row][column] = '*';
			else if (row == 0)
				arr[row][column] = '*';
			else if (column == (total_columns - 1))
				arr[row][column] = '*';
			else if (row == (total_rows - 1))
				arr[row][column] = '*';
			else
				arr[row][column] = ' ';
		}
	}

	arr[p1->get_x()][p1->get_y()] = '^';
}


/****************************************************************
* Function that outputs radar text.
*****************************************************************/

void Asteroid_Field::radar_text()
{
	std::cout << "... I don't think this thing's working ... I'm holding down\n";
	std::cout << "the button! Why don't you focus on driving the ship, okay?\n";
	std::cout << "Oops, sorry if you heard that. We're having some technical difficulties\n";
	std::cout << "over here. Anyways, if you're still listening, you might want to\n";
	std::cout << "search for nearby bombs(@) that may have dropped off your ship.\n";
	std::cout << "When used, they'll destroy most of the surrounding asteroids.\n";
	std::cout << "Wait a minute, what is that? I've never seen a ship like that before ...\n";
	std::cout << "Transmission ends there." << std::endl;
	std::cout << "Press enter to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
}