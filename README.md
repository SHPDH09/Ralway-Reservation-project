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
   git clone https://github.com/SHPDH09/railway-reservation-system.git


### 🖥️ Main Menu  
The program provides an intuitive menu system:  

- **1. Add Train**  
  Store train details such as name and number.  

- **2. Book Ticket**  
  Book tickets for a train, storing passenger details and generating a PNR.  

- **3. View All Tickets**  
  List all tickets booked for a specific train.  

- **4. Update Ticket**  
  Modify ticket details such as name or age using the PNR.  

- **5. View All Trains**  
  Display the list of all available trains.  

- **6. Delete Train**  
  Permanently delete a train and its associated data.  

- **7. View Ticket by PNR**  
  Search for ticket details using a PNR.  

- **8. Exit**  
  Close the program.  

---

### 🌟 Advantages  

- **Lightweight and Fast**: Designed for quick execution with minimal resource usage.  
- **Persistent Storage**: File-based system ensures data is saved and retrieved reliably.  
- **User-Friendly Interface**: Intuitive menu-based system for ease of use.  
- **Scalable**: Modular code structure allows for future enhancements.  

---

### 🛠 Future Enhancements  

- **Graphical User Interface (GUI)**: Develop a visual interface to improve user experience.  
- **Dynamic Reporting**: Generate occupancy statistics and booking trends for better insights.  
- **Advanced Search**: Enable filters to search tickets by passenger name, date, or train.  
- **Integration with Online Systems**: Sync data with an online database for real-time updates.  

---

### 👤 Author  

**Raunak Kumar**  
LNCTU, BCA in AIDA, Section C  3rd -sem

> *Note*: The developer's details are displayed in the program GUI but are hidden within the source code for security and privacy purposes.  

---

### 📜 License  

This project is **open-source** under the MIT License.  
Feel free to fork, modify, and use it for educational or personal projects. Contributions are welcome! 🎉  

