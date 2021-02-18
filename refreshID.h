#ifndef _refreshID_cpp_
#define _refreshID_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userMenu.h"

/* Function for updating userID which is automactically incremented in the database when new user is added. */
void refreshID(unsigned int handleType, const SQLHANDLE& sqlStmtHandle, User* loggedUser);

#endif 
