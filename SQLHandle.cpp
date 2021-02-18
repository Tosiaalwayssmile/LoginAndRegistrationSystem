#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userLogin.h"
#include "userLogout.h"
#include "userRegister.h"
#include "displayUsers.h"
#include "userMenu.h"
#include "SQLHandle.h"

typedef void (*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, User*);

void sqlHandler(User* loggedUser, ExampleFunctionPointer myFunction)
{
	/* Define handles and variables */
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE sqlConnHandle = NULL;
	SQLHANDLE sqlStmtHandle = NULL;
	SQLRETURN retCode = 0;

	#define SQL_RESULT_LEN 240
	#define SQL_RETURN_CODE_LEN 2000	// 1000

	do {
		/* Initialize the ODBC environment handle.*/
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
		{
			goto COMPLETED;
		}
		/* Set the ODBC version to version 3 (the highest version). */
		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		{
			goto COMPLETED;
		}
		/* Allocate the connection handle. */
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &sqlConnHandle))
		{
			goto COMPLETED;
		}
		/* Set attributes that govern aspects of connections. */
		if (SQL_SUCCESS != SQLSetConnectAttr(sqlConnHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
		{
			goto COMPLETED;
		}
		/* Conection string */
		SQLWCHAR retConString[SQL_RETURN_CODE_LEN];

		/* Connect to the database using the connection string (not the ODBC DSN definition which is also cool). */
		switch (SQLDriverConnectW(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=usersDatabase;Trusted=true;",SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
		{
			case SQL_SUCCESS:
			{
				break;
			}
			case SQL_SUCCESS_WITH_INFO:
			{
				break;
			}
			case SQL_INVALID_HANDLE:
			{
				goto COMPLETED;
			}
			case SQL_ERROR:
			{
				goto COMPLETED;
			}
			default:
			{
				break;
			}
		}
		/* If there is a problem connecting then exit application. */
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		{
			goto COMPLETED;		// Allocates the statement
		}
		/* Executes SQL-query in function that myFunction is a pointer to */
		myFunction(SQL_HANDLE_STMT, sqlStmtHandle, loggedUser);
		goto COMPLETED;

	} while (FALSE);

	COMPLETED:
	/* Frees the resources and disconnects */
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);

	/* Disconnect from the database. */
	SQLDisconnect(sqlConnHandle);

	/* Free the connection handle. */
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);

	/* Free the environment handle. */
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}
