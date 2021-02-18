#include <iostream>
#include "SQLHandle.h"
#include "displayUsers.h"
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void refreshID(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser)
{
	char SQLQuery[] = "SELECT * FROM usersDatabase.dbo.Users";

	/* Execute the select query. */
	SQLExecDirect(sqlStmtHandle, (SQLCHAR*)SQLQuery, SQL_NTS);
	
	/* Execute the fetch query in a loop. Fetches the next rowset of data from the result. */
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_C_DEFAULT, &loggedUser->UserID, sizeof(loggedUser->UserID), NULL);
		SQLGetData(sqlStmtHandle, 2, SQL_C_DEFAULT, loggedUser->LastName, sizeof(loggedUser->LastName), NULL);
		SQLGetData(sqlStmtHandle, 3, SQL_C_DEFAULT, loggedUser->FirstName, sizeof(loggedUser->FirstName), NULL);
		SQLGetData(sqlStmtHandle, 4, SQL_C_DEFAULT, &loggedUser->Age, sizeof(loggedUser->Age), NULL);
		SQLGetData(sqlStmtHandle, 5, SQL_C_DEFAULT, loggedUser->Password, sizeof(loggedUser->Password), NULL);
	}
}