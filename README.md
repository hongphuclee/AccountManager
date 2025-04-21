# User Management System
A simple C++ console-based User Management System with login, register, search, and administrative capabilities.

## Features
- Register new users
- Login as user or master
- Search for users by username
- Master account can: View user list, Delete users
- Regular users can only: Search for other users

## Roles
- `Master`: Full access to the system, including user list viewing and deletion.
- `User`: Limited access (can only search).
- `Nobody`: Not logged in.

## Default Master Credentials
```plaintext
Username: lehongphuc  
Password: 123456
```

## System Requirements
**Note:** This application is Windows-only as it uses the `<conio.h>` library for non-blocking keyboard input functionality. This library is specific to Windows systems and is not available on other operating systems such as Linux or macOS.

## Dependencies
- C++ compiler (Recommended: Visual Studio or MinGW for Windows)
- Windows operating system
- `conio.h` library (included in most Windows C++ compilers)
