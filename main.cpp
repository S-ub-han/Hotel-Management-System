#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer {
    string name;
    int id;
    string contact;

public:
    Customer(string n, int i, string c) : name(n), id(i), contact(c) {}

    int getID() const {
        return id;
    }

    void display() const {
        cout << "Customer ID: " << id << ", Name: " << name << ", Contact: " << contact << endl;
    }
};

class Room {
    int roomNumber;
    string type; // e.g., Single, Double, Suite
    bool available;

public:
    Room(int num, string t) : roomNumber(num), type(t), available(true) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailability(bool avail) {
        available = avail;
    }

    void display() const {
        cout << "Room Number: " << roomNumber << ", Type: " << type << ", Available: " << (available ? "Yes" : "No") << endl;
    }
};

class Reservation {
    int reservationID;
    int customerID;
    int roomNumber;
    string checkInDate;
    string checkOutDate;

public:
    Reservation(int resID, int custID, int roomNum, string checkIn, string checkOut)
        : reservationID(resID), customerID(custID), roomNumber(roomNum), checkInDate(checkIn), checkOutDate(checkOut) {}

    void display() const {
        cout << "Reservation ID: " << reservationID << ", Customer ID: " << customerID
             << ", Room Number: " << roomNumber << ", Check-In Date: " << checkInDate
             << ", Check-Out Date: " << checkOutDate << endl;
    }
};

class Hotel {
    vector<Room> rooms;
    vector<Customer> customers;
    vector<Reservation> reservations;

public:
    void addRoom(int roomNumber, string type) {
        rooms.push_back(Room(roomNumber, type));
    }

    void addCustomer(string name, int id, string contact) {
        customers.push_back(Customer(name, id, contact));
    }

    void createReservation(int resID, int custID, int roomNumber, string checkIn, string checkOut) {
        for (auto &room : rooms) {
            if (room.getRoomNumber() == roomNumber && room.isAvailable()) {
                reservations.push_back(Reservation(resID, custID, roomNumber, checkIn, checkOut));
                room.setAvailability(false);
                cout << "Reservation created successfully.\n";
                return;
            }
        }
        cout << "Room not available.\n";
    }

    void displayRooms() const {
        for (const auto &room : rooms) {
            room.display();
        }
    }

    void displayCustomers() const {
        for (const auto &customer : customers) {
            customer.display();
        }
    }

    void displayReservations() const {
        for (const auto &reservation : reservations) {
            reservation.display();
        }
    }
};

int main() {
    Hotel hotel;
    int choice;
    string name, contact, checkIn, checkOut;
    int id, roomNumber, resID;

    while (true) {
        cout << "1. Add Room\n2. Add Customer\n3. Create Reservation\n4. Display Rooms\n5. Display Customers\n6. Display Reservations\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter room type (Single, Double, Suite): ";
            cin >> name;
            hotel.addRoom(roomNumber, name);
            break;
        case 2:
            cout << "Enter customer ID: ";
            cin >> id;
            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter contact number: ";
            cin >> contact;
            hotel.addCustomer(name, id, contact);
            break;
        case 3:
            cout << "Enter reservation ID: ";
            cin >> resID;
            cout << "Enter customer ID: ";
            cin >> id;
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter check-in date (YYYY-MM-DD): ";
            cin >> checkIn;
            cout << "Enter check-out date (YYYY-MM-DD): ";
            cin >> checkOut;
            hotel.createReservation(resID, id, roomNumber, checkIn, checkOut);
            break;
        case 4:
            hotel.displayRooms();
            break;
        case 5:
            hotel.displayCustomers();
            break;
        case 6:
            hotel.displayReservations();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}