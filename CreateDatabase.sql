USE master; 
GO 
IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'usersDatabase')
BEGIN 
CREATE DATABASE usersDatabase; 
END; 
GO 
use usersDatabase; 
CREATE TABLE Users (
UserID int IDENTITY(1,1) PRIMARY KEY NOT NULL, 
LastName varchar(255) NOT NULL, 
FirstName varchar(255) NOT NULL, 
Age int NOT NULL,
Password varchar(255) NOT NULL ); 

INSERT INTO Users (LastName, FirstName, Age, Password) VALUES ('ExampleLastName', 'ExampleFirstName', 5, 'ExamplePassword');
Select * From Users;
