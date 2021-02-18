#ifndef _userMenu_cpp_
#define _userMenu_cpp_

/* Create structure User including all user data */
struct User
{
	int UserID;
	char LastName[255];
	char FirstName[255];
	int Age;
	char Password[255];
	bool isLoggedIn;
};

/* Function acting as a starting menu. Passes the right function (chosen by user) while calling database connection function (SQLHandler). */
void userMenu();

#endif 
