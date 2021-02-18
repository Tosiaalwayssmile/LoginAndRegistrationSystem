#ifndef _userLogin_cpp_
#define _userLogin_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userMenu.h"

/* Function checking if user can be signed in and if his login data matches with according data from database. If so, then changing his isloggedIn status to true. */
void loginUser(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser);

#endif 
