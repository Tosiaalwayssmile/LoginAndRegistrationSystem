#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "SQLHandle.h"
#include "userLogin.h"
#include "systemSleep.h"
#include "changePassword.h"
#include "userMenu.h"

void changePassword(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User *loggedUser)
{
	/* Check if user is currently logged in. */
	if (loggedUser->isLoggedIn)
	{
		std::cout << "\nCHANGE PASSWORD" << std::endl; 

		char inputPassword[255];
		char SQLQuery[] = "UPDATE usersDatabase.dbo.Users SET Password = ? WHERE UserID = ?";
		
		/* Binding parameters to a query so that the data is sent as a parameter along with the query. */
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_VARCHAR, sizeof(loggedUser->Password), 0, loggedUser->Password, 0, 0);
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_DEFAULT, SQL_INTEGER, 0, 0, &loggedUser->UserID, 0, 0);

		std::cout << "Current password: " << loggedUser->Password;
		
		/* While loop to determine if user input is different than old data in the database. */
		bool correctPassword = 0; 
		while (!correctPassword)
		{
			std::cout << "\nInsert new password: ";
			std::cin >> inputPassword;
			if (!strcmp(loggedUser->Password, inputPassword))
			{
				std::cout << "New password must be different than the current password." << std::endl;
			}
			else
			{
				/* Copy new password to database and break the loop. */
				strcpy_s(loggedUser->Password, inputPassword); 
				correctPassword = 1;
			}
		}
		/* Execute the select query. */
		SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);		
	}
	else
	{
		std::cout << "You are not signed in." << std::endl;
	}
}
