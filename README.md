Program **connecting to SQL Server database** with such features as:

1. **signing in** ```  see -> ```
[userLogin.h](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/userLogin.h) and
[userLogin.cpp](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/userLogin.cpp)
2. **signing up** ```  see -> ```
[userRegister.h](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/userRegister.h) and
[userRegister.cpp](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/userRegister.cpp)
3. **changing password**  ```  see -> ```
[changePassword.h](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/changePassword.h) and
[changePassword.cpp](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/changePassword.cpp)
4. **deleting the account** ```  see -> ```
[deleteUser.h](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/deleteUser.h) and
[deleteUser.cpp](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/deleteUser.cpp)
5.  **signing off**  ```  see -> ```
[userLogout.h](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/userLogout.h) and
[userLogout.cpp](https://github.com/Tosiaalwayssmile/LoginAndRegistrationSystem/blob/main/userLogout.cpp)

It allows **selecting**, **inserting**, **updating** and **deleting** data in the database.

**For this program to work you need to:**
1. Install sql server
2. Install Visual Studio (preferably)
3. Create database using script "CreateDatabase.sql"
4. Enable TCP/IP Connection. See this article for reference: https://knowhow.visual-paradigm.com/hibernate/solving-sql-server-connection-problem/
5. Allow Remote Connection
6. Open .sln

7. Make sure Hostname and Port are correct. 52nd line in code in SQLHandle.cpp is where possbile modifications may be needed: 
```C++
switch (SQLDriverConnectW(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;
DATABASE=usersDatabase;Trusted=true;",SQL_NTS, retConString, 1024, NULL,   SQL_DRIVER_NOPROMPT))
```

8. In project properties change the default 'Character Set' from 'Use Unicode Character Set to 'Use Multi-Byte Character Set'. 
In Polish: We właściwościach projektu zmień Właściwości konfiguracji -> Zaawansowane -> Zestaw znaków -> zmień 'Użyj kodowania Unicode' na 'Używaj wielobajtowego zestawu znaków'.
