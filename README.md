# Users Authorization

[![version](https://img.shields.io/badge/Version-1.0-brightgreen.svg)](https://github.com/YuriySavchenko/UsersAuthorization/releases)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## How it works

There are two available ways for the user:
  * Authorization - it's necessary to have account which had been registered in Database.
  * Registration - it's necessary to fill all fields for input by yourself.
 
![image](https://user-images.githubusercontent.com/36791929/60384622-cef67980-9a88-11e9-87f3-cbf9da7c9364.png)

### Authorization
  
Available three cases during athorization:
 1. If account exists and login with password are correct you can see all information about yourself.
 2. If account exists but login or password is not correct then we will receive information about error.
 3. If fields are empty than we will receive error with information that fields can't be empty.
 
![image](https://user-images.githubusercontent.com/36791929/60384694-74115200-9a89-11e9-8729-85fc04f75b70.png)

### Registration

If you want to register a new own account we must fill all fields with information about yourself.

![image](https://user-images.githubusercontent.com/36791929/60385006-2565b700-9a8d-11e9-9c6b-965cfe7af955.png)

If registration finished successfully then in Database new write would be appeared for matched user.
As result we must receive the message that Registration finished successfully.
