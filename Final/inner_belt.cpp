/****************************************************************
* File name:   inner_belt.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Inner_Belt class. It's the
* starting zone for the player. Its special functions are one
* that sets up the map and another that outputs radar info.
* Unlike the other zones, map has debris that must be moved.
*****************************************************************/

#include "inner_belt.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Inner_Belt::Inner_Belt(Player* p1) : Space()
{
	this->p1 = p1;
	total_rows = 15;
	total_columns = 25;
	location = "Inner Belt";
	description = "Description:\nThe radar seems to be picking up a signal(?) nearby.\nIf the ship toggles near its bottom, the message can be receieved.";
}


/****************************************************************
* Destructor.
*****************************************************************/

Inner_Belt::~Inner_Belt()
{

}


/****************************************************************
* Function that sets up the map for the Inner_Belt area.
*****************************************************************/

void Inner_Belt::set_map(char** arr)
{

	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			if ((column == 6 && row == 0))
				arr[row][column] = ' ';
			else if ((column == 6 && row == 1) && (got_item == false))
				arr[row][column] = '~';
			else if ((column == 6 && row == 1) && (got_item == true))
				arr[row][column] = ' ';
			else if ((column == 7 && row == 1) && (got_item == true))
				arr[row][column] = '~';
			else if ((column == 15 && row == 7))
				arr[row][column] = '*';
			else if ((column == 4 && row == 10))
				arr[row][column] = '?';
			else if ((column == 20 && row == 3) && (got_fuel == false))
				arr[row][column] = '+';
			else if ((column == 5 && row == 5))
				arr[row][column] = '*';
			else if ((column == 7 && row == 12))
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

void Inner_Belt::radar_text()
{
	std::cout << "Copy? ... Hello? ... We're not picking up a signal on this end,\n";
	std::cout << "but if you can hear this, that means you survived crashing \n";
	std::cout << "into those asteroids. We're not sure where you are, but if you're \n";
	std::cout << "surrounded you might want to try moving nearby debris(~) to see\n";
	std::cout << "if you can find a way out. Try toggling near the bottom of the debris.\n";
	std::cout << "Also, you can gather any fuel you might've lost by moving over (+).\n";
	std::cout << "To add it to the ship's tank, press (c) to open storage, then enter\n";
	std::cout << "the slot number that it's stored in.\n";
	std::cout << "Transmission ends there." << std::endl;
	std::cout << "Press enter to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
}