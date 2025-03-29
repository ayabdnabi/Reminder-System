# Reminder System
A C program that manages daily reminders with persistent storage and robust error handling. Features automatic calendar generation, multi-reminder support per day, and graceful shutdown during interruptions.

Key Features
- Automatic date detection using <time.h>
- Linked list storage for unlimited reminders per day
- Persistent storage via file I/O operations
- Signal handling for SIGINT, SIGTERM, and SIGSEGV
- Input validation for dates and user commands

### How to run?
Prerequisites
- GCC compiler
- Linux environment (for signal handling)

### Building program:
First download all files
-  gcc -o reminder_app *.c
-  ./reminder_app

or you can do:
- make
- ./reminders
  
### Key Commands
- add [day] [message] - Add reminder
- view [day] - View daily reminders
- exit - Save and quit
