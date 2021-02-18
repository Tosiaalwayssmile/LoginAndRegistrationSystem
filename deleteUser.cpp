#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "SQLHandle.h"
#include "userLogin.h"
#include "deleteUser.h"
#include "userMenu.h"

void deleteUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser)
{
	char userInput = 'z';

	/* Check if user is currently logged in. */
	if (loggedUser->isLoggedIn)
	{
		std::cout << "\nDELETE ACCOUNT" << std::endl;

		while (toupper(userInput) != 'Y' && toupper(userInput) != 'N')
		{
			std::cout << "Are you sure you want to delete your account? Y/n: ";
			std::cin >> userInput;

			switch (toupper(userInput))
			{
				case 'Y':
				{
					char SQLQuery[] = "DELETE FROM usersDatabase.dbo.Users WHERE UserID = ?";

					/* Binding parameters to a query so that the data is sent as a parameter along with the query. */
					SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_INTEGER, 0, 0, &loggedUser->UserID, 0, 0);

					/* Execute the delete query. */
					SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);

					/* Change user's status to 'not logged in'. */
					loggedUser->isLoggedIn = false;

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