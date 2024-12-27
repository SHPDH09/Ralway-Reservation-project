Railway Reservation System
Overview
The Railway Reservation System is a command-line application designed for efficient management of train bookings. It allows users to add trains, book tickets, view booked tickets, update ticket details, and manage train records. Developed in C++, this project implements file handling, data storage, and basic error handling for a smooth user experience.

Features
Add Train

Allows users to add up to 10 unique trains.
Stores train details in a file for persistent storage.
Book Tickets

Enables ticket booking for available trains.
Generates an 8-digit unique PNR (Passenger Name Record) for each ticket.
Supports multiple bookings in one session.
View Tickets by Train

Displays all tickets booked for a specific train.
Reads and displays data directly from the train's file.
Update Ticket Details

Allows updating the passenger's name and age using the PNR.
Logs updates with a timestamp.
View All Trains

Displays a list of all stored trains with their names and numbers.
Delete Train

Removes a train and all associated ticket data permanently.
Search Ticket by PNR

Quickly locates and displays ticket details using the PNR.
Time and Date Tracking

Logs all ticketing and update operations with the current date and time.
How It Works
1. Train Management
Add Train: Stores the train's name and number in a central file and creates an individual file for ticket data.
View All Trains: Lists all available trains by reading the Train Number.txt file.
Delete Train: Deletes the train file and removes its entry from the central list.
2. Ticket Booking
Books tickets for a train by writing passenger details to the respective train's file.
Generates a unique PNR for each booking.
Tracks available seat counts (up to 50 per train).
3. Ticket Management
View Tickets: Displays all tickets for a selected train.
Update Ticket: Modifies passenger details using the PNR.
Search by PNR: Fetches ticket details quickly for a given PNR.
Getting Started
Prerequisites
A C++ compiler such as GCC or Clang.
Basic understanding of C++ file handling.
Installation
Clone the repository:
bash
Copy code
git clone https://github.com/yourusername/railway-reservation-system.git
Compile the program:
bash
Copy code
g++ -o railway railway.cpp
Run the executable:
bash
Copy code
./railway
File Structure
Train Number.txt: Stores the train number and name for all trains.
<TrainNumber>.txt: Individual files for each train to log ticket details.
Program Flow
Main Menu:

Displays all available actions (Add Train, Book Ticket, etc.).
User chooses an option by entering the corresponding number.
File Management:

Files are dynamically created and updated for persistent storage of train and ticket information.
User Interaction:

Input validations ensure that operations like adding trains or booking tickets are error-free.
Advantages
Lightweight and portable application.
File-based storage eliminates the need for database setup.
Simple yet robust interface for railway reservation tasks.
Future Enhancements
Integrate a graphical user interface (GUI) for improved usability.
Add a reporting feature for train occupancy statistics.
Support for more advanced search filters (e.g., by date or passenger name).
Author
Raunak Kumar
LNCTU, BCA in AIDA, Section C

Developer details are shown in the program but hidden in the source code for minimal footprint.

Feel free to fork or contribute to this project!
