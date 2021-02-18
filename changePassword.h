#ifndef _changePassword_cpp_
#define _changePassword_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userMenu.h"

/* Function checking if user is allowed to change the password and if so, then sending the new password to database. */
void changePassword(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser);

#endif 
