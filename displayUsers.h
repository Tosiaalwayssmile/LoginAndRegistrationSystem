#ifndef _displayUsers_cpp_
#define _displayUsers_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userMenu.h"

/* Function just for testing the program. It displays all users info. */
void displayAllUsers(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser);

#endif 
