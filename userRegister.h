#ifndef _userRegister_cpp_
#define _userRegister_cpp_

#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userMenu.h"

/* Function checking if user is not signed in and sending his input data to database. */
void registerUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser);

#endif 
