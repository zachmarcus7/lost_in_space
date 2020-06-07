/****************************************************************
* File name:   menu.cpp
* Assignment:  Final Project
* Author:      Zach Marcus
* Date:        8/6/2019
* Description: Implementation file for Menu class. It contains
* functions for starting the game and exiting it.
*****************************************************************/

#include "menu.hpp"


/****************************************************************
* Default constructor.
*****************************************************************/

Menu::Menu()
{

}


/****************************************************************
* Destructor.
*****************************************************************/

Menu::~Menu()
{

}


/****************************************************************
* Function that provides start and end prompt for game.
*****************************************************************/

void Menu::run()
{
	std::cout << "::: Lost in Space :::" << std::endl;
	std::cout << "(1) - start game" << std::endl;
	std::cout << "(2) - exit" << std::endl;
	std::cout << "Enter choice:" << std::endl;

	int answer = check_prompt(2, 1);

	while (answer == 1)
	{
		Game g1;
		g1.play_game();

		answer = end_prompt();
	}

	std::cout << "Exiting ..." << std::endl;
}


/****************************************************************
* Function that checks if the user entered a number between min and max.
*****************************************************************/

int Menu::check_prompt(int max, int min)
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
* Function that displays at end.
*****************************************************************/

int Menu::end_prompt()
{
	int answer = 0;

	std::cout << "Play again?" << std::endl;
	std::cout << "(1) - yes" << std::endl;
	std::cout << "(2) - no" << std::endl;
	std::cout << "Enter choice:" << std::endl;

	answer = check_prompt(2,1);

	return answer;
}