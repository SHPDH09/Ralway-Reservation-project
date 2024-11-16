#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<vector>
#include <chrono>
#include <thread>



using namespace std;
string time_date(){
      

    auto now = time(0);
    char* dt = ctime(&now); 
    string dat=string(dt);
    return dat;

}

string tname[10];
int trainnumber[10];
int seat = 0;
int tname_position = 0;
const int max_seat = 50;
string pname_store[max_seat];
int page_store[max_seat];
int record = 0;
int record_pdetails = 0;

bool search_file(const string &filename) {
    ifstream file(filename);
    return file.good(); // ReTurns true iF the fiLe exIsts
}

int pnr_generate() {
    srand(time(0));
    return (rand() % 90000000) + 10000000;
}

void addtrain() {
    int tnumber;
    string name;
    int n;

    cout << "Enter No. Of Trains to Store (Max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Error: Cannot store more than 10 trains!\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter train number: ";
        cin >> tnumber;

        string filename = to_string(tnumber) + ".txt"; // ConsTruct the fUll filename

        if (search_file(filename)) {
            cout << "Train Number Already AlloTted to another Train: " << tnumber << endl;
            continue;
        } else {
            cout << "Congratulations! This Train Number Is Valid: " << tnumber << endl;
        }

        cout << "Enter the train name: ";
        cin.ignore();
        getline(cin, name);
        
        tname[record] = name;
        trainnumber[record] = tnumber;
        record++; // Train Number Position Store

        // Store Train NuMber in a File
        ofstream trainno("Train Number.txt", ios::app);
        if (trainno.is_open()) {
            trainno << "\n" << tnumber << " - " << name;
            trainno.close();
        } else {
            cout << "Error creating file for Train Number";
        }

        // Create a fIle for each trAin to store tickets
        ofstream trainFile(to_string(tnumber) + ".txt");
        if (trainFile.is_open()) {
            trainFile << "Train Name: " << name << "\n\n";
            trainFile << "Train Number: " << tnumber << "\n";
            trainFile<<"   Passenger Name             Age              PNR Number            Date & Time                          Modify Statues\n";
            trainFile.close();
        } else {
            cout << "Error creating file for train " << tnumber << "\n";
        }
    }
}

void trainnamefind(int a) {
    for (int i = 0; i < 10; i++) {
        if (a == trainnumber[i]) {
            tname_position = i;
            return;
        }
    }
    tname_position = -1;
}

int trainname_find_on_file(int tnumber) { // Find thE Train Name in tHe first line
    string firstline;
    ifstream trainFile(to_string(tnumber) + ".txt");
    if (trainFile.is_open()) {
        getline(trainFile, firstline);
        cout << firstline << endl;
        trainFile.close();
        return 1;
    } else {
        cout << "This Train Number Is not Valid. Train Not Found.\n";
        return 0;
    }
}

void addtkt() {
    int tnumber1;
    string pname;
    int age;
    int a;
    int pnrno = pnr_generate(); // Generate PNR for tHe boOking

    cout << "Enter No. Of Seats to Book: ";
    cin >> a;

    for (int i = 0; i < a; i++) {
        if (seat >= max_seat) {
            cout << "Sorry, seats are full\n";
            return;
        }

        cout << "Enter train number for ticket " << i + 1 << ": ";
        cin >> tnumber1;
        if (trainname_find_on_file(tnumber1) == 0) {
            break;
             // If train is not valId, exit the loop
        }

        cout << "Enter Passenger Name " << i + 1 << ": ";
        cin.ignore();
        getline(cin, pname);
        pname_store[record_pdetails] = pname;

        cout << "Enter Age of Passenger " << i + 1 << ": ";
        cin >> age;
        page_store[record_pdetails] = age;

        // AdD passEnger detaIls to the train's file
        string datetime1=time_date();
        ofstream trainFile(to_string(tnumber1) + ".txt", ios::app);
        if (trainFile.is_open()) {
            trainFile <<i+1<< "  " << pname << "             " << age << "         , PNR: " << pnrno <<"             "<<datetime1<<"";
            trainFile.close();
        } else {
            cout << "Error writing to file for train " << tnumber1 << "\n";
        }

        seat++;
        record_pdetails++;
    }
    cout << a << " Ticket(s) Booking Confirmed! Congratulations!\n";
    cout << "PNR Number IS: " << pnrno << endl;
}

void view_tiket() {
    int train_number;
    cout << "Enter the Train Number: ";
    cin >> train_number;

    if (trainname_find_on_file(train_number) == 0) {
        return;
    } else {
        ifstream trainFile(to_string(train_number) + ".txt");
        if (trainFile.is_open()) {
            string line;
            while (getline(trainFile, line)) {
                cout << line << endl;
            }
            trainFile.close();
        } else {
            cout << "Error opening file for train " << train_number << "\n";
        }
    }
}



void view_all_train() {
    ifstream trainFile("Train Number.txt");
    if (trainFile.is_open()) {
        string line;
        while (getline(trainFile, line)) {
            cout << line << endl;
        }
        trainFile.close();
    } else {
        cout << "No Record Found\n";
    }
}

void delete_train() {
    int trains;
    cout << "Enter Train Number To Delete: ";
    cin >> trains;

    string trainfilename = to_string(trains) + ".txt";
    if (remove(trainfilename.c_str()) == 0) {
        cout << "Train Hasbeen Permanent Terminated or Delete All Data\n";
    } else {
        cout << "Error deleting train file.\n";
    }

    // Remove frOm TrAin Number fIle
    ifstream infile("Train Number.txt");
    ofstream temp("temp.txt");

    string line;
    while (getline(infile, line) ) {
        if (line.find(to_string(trains)) == string::npos) {
            temp << line << endl;
        }
    }
    infile.close();
    temp.close();
    remove("Train Number.txt");
    rename("temp.txt", "Train Number.txt");
}
int view_tkt_pnr() {
    
    int trains, pnr;
    cout << "Enter Train Number: ";
    cin >> trains;
    cout << "Enter PNR Number: ";
    cin >> pnr;

    string trainFileName = to_string(trains) + ".txt";
    ifstream infile(trainFileName);

    if (!infile) {
        cout << "Train file not found for train number " << trains << ".\n";
        return 0;
    }

    string line;
    bool found = false;
    // read the DaTa
    while (getline(infile, line)) {
        if (line.find("PNR: " + to_string(pnr)) != string::npos) {
            found = true;
            cout << "\nTicket Details:\n";
            cout << line << endl; // Display the PNR line with passenger details

            // Read subsequent lines for name and age if formatted on separate lines
            while (getline(infile, line) && !line.empty()) {
                cout << line << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "No ticket found with PNR " << pnr << " for train " << trains << ".\n";
    }

    infile.close();
    return found ? 1 : 0;
}
int update_tkt_details() {
    int train_number, pnr;
    string datetime1=time_date();
    cout << "Enter Train Number: ";
    cin >> train_number;
    cout << "Enter PNR Number: ";
    cin >> pnr;
    int a=0;
    string trainFileName = to_string(train_number) + ".txt";
    ifstream infile(trainFileName);
    if (!infile) {
        cout << "Train file not found for train number " << train_number << ".\n";
        return 0;
    }

    // Read all lines and look for the line with the specified PNR
    vector<string> fileLines;
    string line;
    bool found = false;

    while (getline(infile, line)) {
        a+=1;
        if (line.find("PNR: " + to_string(pnr)) != string::npos) {
            found = true;
            cout << "Current Ticket Details:\n" << line << endl;

            // Prompt for updated passenger information
            cout << "Enter new Passenger Name: ";
            string newName;
            cin.ignore();
            getline(cin, newName);

            cout << "Enter new Age: ";
            int newAge;
            cin >> newAge;
            
            // Update the line with new details
            line = a+"  " + newName + "              " + to_string(newAge) + ", PNR: " + to_string(pnr)+"             "+datetime1+"         Updated";
        }
        fileLines.push_back(line);
    }
    infile.close();

    // If PNR not found
    if (!found) {
        cout << "No ticket found with PNR " << pnr << " for train " << train_number << ".\n";
        return 0;
    }

    // Write the updated information back to the file
    ofstream outfile(trainFileName);
    for (const auto& updatedLine : fileLines) {
        outfile << updatedLine << endl;
    }
    outfile.close();

    cout << "Ticket details updated successfully.\n";
    return 1;
}


int main() {
    int choice;
    
    while (true) {
        cout<<"Date and Time  : "<<time_date();
     
        cout<<"\nWelcome To Ralway Reservation System !\n";

        cout << "\n        1. Add Train\n        2. Book Ticket\n        3. View All Ticket\n        4. Update Ticket\n        5. View All Train        \n        6. Delete Train        \n        7. View TKT\n        8. exit\n";
        cout<<"\nPlease Enter Your Choice >>";
        cin >> choice;
        switch (choice) {
            case 1: addtrain(); break;
            
            case 2: addtkt(); break;
            case 3: view_tiket(); break;
            case 4: update_tkt_details();break;
            case 5: view_all_train(); break;
            case 6: delete_train(); break;
            case 7: view_tkt_pnr(); break;
            case 8: return 0; break;
            default: cout << "Invalid choice\n";

        }

    }
}
