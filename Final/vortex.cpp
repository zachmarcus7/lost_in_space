/****************************************************************
* File name:   vortex.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Vortex class. It's the
* fifth zone of the game. Its special functions are setting up
* its specific map and displaying its specific message.
*****************************************************************/

#include "vortex.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Vortex::Vortex(Player* p1) : Space()
{
	this->p1 = p1;
	total_rows = 19;
	total_columns = 40;
	location = "Vortex";
	description = "Description:\nMore alien ships have flown in.\nWatch out for them, the radar jammer didn't reach this far.";

}
/****************************************************************
* Destructor.
*****************************************************************/

Vortex::~Vortex()
{

}


/****************************************************************
* Function that sets up the map for the Vortex area.
*****************************************************************/

void Vortex::set_map(char** arr)
{

	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			if ((column == 39 && row == 4))
				arr[row][column] = ' ';
			else if ((column == 4 && row == 18))
				arr[row][column] = ' ';
			else if ((column % 4 == 0) && (row % 4 == 0))
				arr[row][column] = '*';
			else if ((column == 8 && row == 9))
				arr[row][column] = '&';
			else if ((column == 34 && row == 13))
				arr[row][column] = '?';
			else if ((column == 27 && row == 15))
				arr[row][column] = '*';
			else if ((column == 25 && row == 3))
				arr[row][column] = '*';
			else if ((column == 3 && row == 2) && (got_item == false))
				arr[row][column] = '@';
			else if ((column == 31 && row == 7))
				arr[row][column] = '&';
			else if ((column == 20 && row == 10) && (got_fuel == false))
				arr[row][column] = '+';
			else if ((column == 21 && row == 14))
				arr[row][column] = '~';
			else if ((column == 15 && row == 7))
				arr[row][column] = '*';
			else if ((column == 27 && row == 15))
				arr[row][column] = '*';
			else if ((column == 20 && row == 5))
				arr[row][column] = '&';
			else if ((column == 5 && row == 5))
				arr[row][column] = '*';
			else if ((column == 10 && row == 13))
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

void Vortex::radar_text()
{
	std::cout << "... It looks like I might be picking up a signal now,\n";
	std::cout << "that must mean you're getting closer to the exit.\n";
	std::cout << "Be careful, though, there is a massive alien ship that just flew\n";
	std::cout << "past us, and it looks like it was headed that way!\n";
	std::cout << "If you have any bombs left, you might want to try detonating\n";
	std::cout << "them nearby. I wish you all the best of luck, but we have to jump\n";
	std::cout << "back into hyper-space now so that we don't end up in your position ...\n";
	std::cout << "Anyways, hope you make it out! See you on the other side!\n";
	std::cout << "Transmission ends there." << std::endl;
	std::cout << "Press enter to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
}