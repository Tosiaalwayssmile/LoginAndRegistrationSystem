#ifndef _deleteUsers_cpp_
#define _deleteUsers_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userMenu.h"

/* Function retrieving active user info and then deleting his data in database. */
void deleteUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser);

#endif 
