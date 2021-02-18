#ifndef _SQLHandle_cpp_
#define _SQLHandle_cpp_

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#include "userMenu.h"

/* Function connecting and disconnecting the database. Takes a function pointer as a parameter and is used everytime when the database is needed. */
typedef void (*ExampleFunctionPointer)(unsigned int, const SQLHANDLE&, User*);

void sqlHandler(User *loggedUser, ExampleFunctionPointer ex);

#endif 
