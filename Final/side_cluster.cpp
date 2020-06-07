/****************************************************************
* File name:   side_cluster.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Side_Cluster class. It's the
* fourth zone in the game. Its special functions are setting up
* its specific map and also showing its specific radar message.
* Unlike other zones, there's no next zone to advance to from this 
* one. Player must get items from this zone to advance in others.
*****************************************************************/

#include "side_cluster.hpp"

/****************************************************************
* Default constructor.
*****************************************************************/

Side_Cluster::Side_Cluster(Player* p1) : Space()
{
	this->p1 = p1;
	total_rows = 10;
	total_columns = 17;
	location = "Side Cluster";
	description = "Description:\nThis way doesn't look any better than the last.\nAt least there are no strange ships in here.";
}


/****************************************************************
* Destructor.
*****************************************************************/

Side_Cluster::~Side_Cluster()
{

}


/****************************************************************
* Function that sets up the map for the Side_Cluster area.
*****************************************************************/

void Side_Cluster::set_map(char** arr)
{

	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			if ((column == 16 && row == 8))
				arr[row][column] = ' ';
			else if ((column == 3 && row == 4))
				arr[row][column] = '~';
			else if ((column == 14 && row == 2) && got_item_2 == false)
				arr[row][column] = '$';
			else if ((column % 4 == 1 && row % 4 == 1))
				arr[row][column] = '*';
			else if ((column == 6 && row == 2))
				arr[row][column] = '*';
			else if ((column == 13 && row == 7))
				arr[row][column] = '~';
			else if ((column == 4 && row == 7))
				arr[row][column] = '?';
			else if ((column == 15 && row == 7))
				arr[row][column] = '*';
			else if ((column == 10 && row == 6))
				arr[row][column] = '*';
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

void Side_Cluster::radar_text()
{
	std::cout << "Mayday! Mayday! We're under attack!\n";
	std::cout << "Watch out for any alien ships(&), if you get too close to them\n";
	std::cout << "they'll shoot at your fuel tank ... (Someone talking frantically in the distance).\n";
	std::cout << "... Yes, I just told them that! Didn't you hear me? ...\n";
	std::cout << "Oh yeah, that might help too. If you're still listening,\n";
	std::cout << "try to use any radar jammers($) near the alien ships, that way\n";
	std::cout << "they won't be able to target you. But remember to use the jammer\n";
	std::cout << "near the ships! They don't have much reach ...\n";
	std::cout << "Transmission ends there." << std::endl;
	std::cout << "Press enter to continue." << std::endl;
	std::cin.ignore();
	std::cin.get();
}