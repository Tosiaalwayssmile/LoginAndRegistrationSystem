#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "systemSleep.h"
#include "SQLHandle.h"
#include "userLogin.h"

void loginUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser)
{
	/* Check if user is currently logged in. */
	if (!loggedUser->isLoggedIn)
	{
		char SQLQuery[] = "SELECT * FROM Users";

		/* Execute the select query. */
		SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);

		char inputLastName[255];
		char inputPassword[255];

		std::cout << "\nSIGN IN" << std::endl;

		std::cout << "Insert your last name: ";
		std::cin >> inputLastName;

		std::cout << "Insert your password: ";
		std::cin >> inputPassword;
		
		/* Boolean flag to see if user's input matches result from database. */
		bool isInDatabase = false;

		/* Execute the fetch query in a loop. Fetches the next rowset of data from the result. */
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			/* Compare input char array with data from the result. If not equal move on to next rowset of data and compare again. */
			/* Function strcmp returns 0 if both strings are equal. */
			if (!strcmp(loggedUser->LastName, inputLastName) && !strcmp(loggedUser->Password, inputPassword))
			{
				/* When the appropriate match is found break the loop. */
				isInDatabase = true;
				break;
			}
			/* Get the data in segment (retrieve data for a single column in the result set).  */
			SQLGetData(sqlStmtHandle, 1, SQL_C_DEFAULT, &loggedUser->UserID, sizeof(loggedUser->UserID), NULL);
			SQLGetData(sqlStmtHandle, 2, SQL_C_DEFAULT, loggedUser->LastName, sizeof(loggedUser->LastName), NULL);
			SQLGetData(sqlStmtHandle, 3, SQL_C_DEFAULT, loggedUser->FirstName, sizeof(loggedUser->FirstName), NULL);
			SQLGetData(sqlStmtHandle, 4, SQL_C_DEFAULT, &loggedUser->Age, sizeof(loggedUser->Age), NULL);
			SQLGetData(sqlStmtHandle, 5, SQL_C_DEFAULT, loggedUser->Password, sizeof(loggedUser->Password), NULL);
		}
		if (isInDatabase)
		{
			sleep();
			loggedUser->isLoggedIn = true;
			std::cout << "You are signed in." << std::endl;
			sleep();

			std::cout << "Info from database: " << "UserID: " << loggedUser->UserID << ", Last name: " << loggedUser->LastName
				<< ", First name: " << loggedUser->FirstName << std::endl;
			
		}
		else if (!isInDatabase)
		{
			sleep();
			std::cout << "No such user data in the database." << std::endl;
		}
	}
	else
	{
		std::cout << "You are alredy signed in." << std::endl;
	}
}
