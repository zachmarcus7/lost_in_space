/****************************************************************
* File name:   mother_ship.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Mother_Ship class. It's 
* the final zone of the game. Its special function is for
* creating the map specific to its area. Unlike other zones,
* map has a giant alien ship that needs to be blown up.
*****************************************************************/

#include "mother_ship.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Mother_Ship::Mother_Ship(Player* p1) : Space()
{
	this->p1 = p1;
	total_rows = 12;
	total_columns = 23;
	location = "Mother Ship";
	description = "Description:\nThat gigantic alien ship is blocking the way out!\nMaybe something can be used to destroy it.";
}


/****************************************************************
* Destructor.
*****************************************************************/

Mother_Ship::~Mother_Ship()
{

}


/****************************************************************
* Function that sets up the map for the Mother_Ship area.
*****************************************************************/

void Mother_Ship::set_map(char** arr)
{

	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			if ((column == 18 && row == 0))
				arr[row][column] = ' ';
			else if ((column == 0 && row == 10))
				arr[row][column] = ' ';
			else if ((column == 17 && row == 3) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 14 && row == 3) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 14 && row == 1) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 15 && row == 3) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 14 && row == 2) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 20 && row == 3) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 19 && row == 3) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 18 && row == 3) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 16 && row == 3) && (used_item_2 == false))
				arr[row][column] = '&';
			else if ((column == 5 && row == 3))
				arr[row][column] = '*';
			else if ((column == 18 && row == 8))
				arr[row][column] = '~';
			else if ((column == 17 && row == 9))
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

void Mother_Ship::radar_text()
{
	std::cout << "No transmission.";
}