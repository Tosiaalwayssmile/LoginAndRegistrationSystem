#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <ctype.h>	// toupper

#include "SQLHandle.h"
#include "userLogout.h"
#include "systemSleep.h"

void logoutUser(User* loggedUser)
{
	char userInput = 'z';

	/* Check if user is currently logged in. */
	if (loggedUser->isLoggedIn)
	{
		std::cout << "\nSIGN OFF" << std::endl;

		while (toupper(userInput) != 'Y' && toupper(userInput) != 'N')
		{
			std::cout << "Are you sure you want to sign off? Y/n: ";
			std::cin >> userInput;

			switch (toupper(userInput))
			{
				case 'Y':
				{
					loggedUser->isLoggedIn = false;
					sleep();
					std::cout << "\nYou successfully signed off." << std::endl;
					break;
				}
				case 'N':
				{
					break;
				}
				default:
				{
					std::cout << "\nWrong input." << std::endl;
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "You are not signed in." << std::endl;
	}
}