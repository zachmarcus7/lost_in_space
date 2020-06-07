/****************************************************************
* File name:   alien_corridor.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Alien_Corridor class. It's the
* third zone of the game. Its main function is setting up the map.
* Unlike other zones, map has aliens that need to be snuck by.
*****************************************************************/

#include "alien_corridor.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Alien_Corridor::Alien_Corridor(Player* p1) : Space()
{
	this->p1 = p1;
	total_rows = 19;
	total_columns = 7;
	location = "Alien Corridor";
	description = "Description:\nThose are strange looking ships ahead.\nProbably best to stay away from them, they look dangerous.";
}


/****************************************************************
* Destructor.
*****************************************************************/

Alien_Corridor::~Alien_Corridor()
{

}


/****************************************************************
* Function that sets up the map for the Alien_Corridor area.
*****************************************************************/

void Alien_Corridor::set_map(char** arr)
{

	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			if ((column == 4 && row == 0))
				arr[row][column] = ' ';
			else if ((column == 2 && row == 18))
				arr[row][column] = ' ';
			else if ((column == 2 && row == 2)) 
				arr[row][column] = '&';
			else if ((column == 3 && row == 2)) 
				arr[row][column] = '&';
			else if ((column == 4 && row == 2))
				arr[row][column] = '&';
			else if ((column == 0 && row == 14))
				arr[row][column] = ' ';
			else if ((column == 3 && row == 10))
				arr[row][column] = '*';
			else if ((column == 2 && row == 15))
				arr[row][column] = '*';
			else if ((column == 2 && row == 8))
				arr[row][column] = '*';
			else if ((column == 2 && row == 8))
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

void Alien_Corridor::radar_text()
{
	std::cout << "No signal.";
}