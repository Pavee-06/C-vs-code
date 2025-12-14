#include <iostream>
#include <vector>
#include <string>
using namespace std;


class VehicleService {
public:
int bookingId;
string customerName;
string vehicleNumber;
string vehicleType;
string serviceType;
float serviceCost;


VehicleService(int id, string cname, string vnum, string vtype, string stype, float cost) {
bookingId = id;
customerName = cname;
vehicleNumber = vnum;
vehicleType = vtype;
serviceType = stype;
serviceCost = cost;
}
};
class ServiceCenter {
private:
vector<VehicleService> bookings;


public:
void bookService() {
int id;
string cname, vnum, vtype, stype;
float cost;


cout << "Enter Booking ID: ";
cin >> id;
cin.ignore();
cout << "Enter Customer Name: ";
getline(cin, cname);
cout << "Enter Vehicle Number: ";
getline(cin, vnum);
cout << "Enter Vehicle Type (Car/Bike): ";
getline(cin, vtype);
cout << "Enter Service Type (Oil Change / General Service / Engine Check): ";
getline(cin, stype);
cout << "Enter Service Cost: ";
cin >> cost;


bookings.push_back(VehicleService(id, cname, vnum, vtype, stype, cost));
cout << "Service booked successfully!\n";
}
void displayBookings() {
if (bookings.empty()) {
cout << "No service bookings available.\n";
return;
}


cout << "\n---- Service Bookings ----\n";
for (auto &b : bookings) {
cout << "Booking ID: " << b.bookingId
<< " | Name: " << b.customerName
<< " | Vehicle No: " << b.vehicleNumber
<< " | Vehicle Type: " << b.vehicleType
<< " | Service: " << b.serviceType
<< " | Cost: " << b.serviceCost << endl;
}
}
void searchBooking() {
int id;
cout << "Enter Booking ID to search: ";
cin >> id;


for (auto &b : bookings) {
if (b.bookingId == id) {
cout << "Booking Found!\n";
cout << "Customer Name: " << b.customerName << endl;
cout << "Vehicle Number: " << b.vehicleNumber << endl;
cout << "Vehicle Type: " << b.vehicleType << endl;
cout << "Service Type: " << b.serviceType << endl;
cout << "Service Cost: " << b.serviceCost << endl;
return;
}
}
cout << "Booking not found!\n";
}
void cancelBooking() {
int id;
cout << "Enter Booking ID to cancel: ";
cin >> id;


for (auto it = bookings.begin(); it != bookings.end(); ++it) {
if (it->bookingId == id) {
bookings.erase(it);
cout << "Booking cancelled successfully!\n";
return;
}
}
cout << "Booking not found!\n";
}
};
int main() {
ServiceCenter center;
int choice;


do {
cout << "\n===== Vehicle Service Booking System =====\n";
cout << "1. Book Vehicle Service\n";
cout << "2. Display All Bookings\n";
cout << "3. Search Booking\n";
cout << "4. Cancel Booking\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
center.bookService();
break;
case 2:
center.displayBookings();
break;
case 3:
center.searchBooking();
break;
case 4:
center.cancelBooking();
break;
case 5:
cout << "Thank you! Exiting system...\n";
break;
default:
cout << "Invalid choice! Try again.\n";
}
} while (choice != 5);


return 0;
}