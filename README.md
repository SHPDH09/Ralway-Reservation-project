# Railway Reservation System

## 🚆 Overview
The **Railway Reservation System** is a command-line application developed in C++ for efficiently managing train reservations. It includes functionalities to add trains, book tickets, view and update ticket details, and manage train records. File handling is used for persistent storage, ensuring data is saved across sessions.

---

## ✨ Features
- **Add Train**  
  Add up to 10 trains with unique train numbers and names. Validations ensure no duplication of train numbers.

- **Book Tickets**  
  - Book tickets for a train by specifying passenger details.  
  - Automatically generates an 8-digit unique Passenger Name Record (PNR).  
  - Support for multiple bookings in a single session.  

- **View Tickets by Train**  
  View the list of all tickets booked for a specific train.

- **Update Ticket Details**  
  Modify passenger details (name and age) using the unique PNR.

- **View All Trains**  
  Display a list of all available trains with their numbers and names.

- **Delete Train**  
  Permanently delete a train and all associated ticket data.

- **Search Ticket by PNR**  
  Locate and display ticket details using the unique PNR.

- **Date and Time Integration**  
  Logs the date and time for ticket bookings and updates for traceability.

---

## 🗂 File Structure
The system uses file handling to store and retrieve data.  

- **`Train Number.txt`**  
  Stores the list of train numbers and names.  

- **`<TrainNumber>.txt`**  
  Individual files for each train containing passenger details, PNR, and booking status.  

---

## 🚀 How It Works
1. **Train Management**  
   - Add train records with train numbers and names.  
   - Delete trains, ensuring no stale data.  

2. **Ticket Booking**  
   - Book tickets for passengers by entering their name, age, and train number.  
   - Automatically assign a unique PNR to every booking.  

3. **Ticket Management**  
   - View all tickets for a train.  
   - Update or search ticket details using the PNR.  

4. **File Integration**  
   - Persistent data storage ensures records are maintained even after restarting the program.  

---

## 🛠 Requirements
To run the program, you need:
- A C++ compiler (e.g., GCC, Clang).  
- Basic knowledge of running command-line programs.  

### Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/railway-reservation-system.git
