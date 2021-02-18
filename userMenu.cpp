#include <iostream>

#include "changePassword.h"
#include "deleteUser.h"
#include "displayUsers.h"
#include "refreshID.h"
#include "SQLHandle.h"
#include "systemSleep.h"
#include "userLogin.h"
#include "userLogout.h"
#include "userMenu.h"
#include "userRegister.h"

void userMenu()
{
	int userChoice = 0;
	int repeatIndicator = 1;
	User loggedUser;
	loggedUser.isLoggedIn = false;

	/* Function displaying all users that are currently in database, you can uncomment this for testing. */
	//sqlHandler(&loggedUser, displayAllUsers);

	while (repeatIndicator)
	{
		sleep();
		std::cout << "\nAvailable operations: "
					 "\n1. Sign in."
					 "\n2. Sign up."
					 "\n3. Change password."
					 "\n4. Delete account."
					 "\n5. Sign off."
					 "\n6. Exit."
					 "\nInsert operation number (1-6): ";
		std::cin >> userChoice;

		switch (userChoice)
		{
			case 1:  //login
			{
				sleep(); 
				sqlHandler(&loggedUser, loginUser);
				break;
			}
			case 2:	//register
			{
				sleep();
				sqlHandler(&loggedUser, registerUser);
				sqlHandler(&loggedUser, refreshID);
				break;
			}
			case 3:	//change password
			{
				sleep(); 
				sqlHandler(&loggedUser, changePassword);
				break;
			}
			case 4:	//delete account
			{
				sleep(); 
				sqlHandler(&loggedUser, deleteUser);
				sqlHandler(&loggedUser, refreshID);
				break;
			}
			case 5:	//logout
			{
				sleep(); 
				logoutUser(&loggedUser);
				break;
			}
			default: //exit
			{
				repeatIndicator = 0;
				break;
			}
		}
	}
	std::cout << "\nPress any key to exit...";
}