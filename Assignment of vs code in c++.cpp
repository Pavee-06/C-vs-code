#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Book {
public:
int id;
string title;
string author;
float price;
int quantity;


Book(int i, string t, string a, float p, int q) {
id = i;
title = t;
author = a;
price = p;
quantity = q;
}
};
class BookShop {
private:
vector<Book> books;


public:
void addBook() {
int id, qty;
float price;
string title, author;


cout << "Enter Book ID: ";
cin >> id;
cin.ignore();
cout << "Enter Title: ";
getline(cin, title);
cout << "Enter Author: ";
getline(cin, author);
cout << "Enter Price: ";
cin >> price;
cout << "Enter Quantity: ";
cin >> qty;


books.push_back(Book(id, title, author, price, qty));
cout << "Book added successfully!\n";
}
void displayBooks() {
if (books.empty()) {
cout << "No books available.\n";
return;
}
cout << "\nAvailable Books:\n";
for (auto &b : books) {
cout << "ID: " << b.id
<< ", Title: " << b.title
<< ", Author: " << b.author
<< ", Price: " << b.price
<< ", Quantity: " << b.quantity << endl;
}
}
void searchBook() {
int id;
cout << "Enter Book ID to search: ";
cin >> id;
for (auto &b : books) {
if (b.id == id) {
cout << "Book Found!\n";
cout << "Title: " << b.title
<< ", Author: " << b.author
<< ", Price: " << b.price
<< ", Quantity: " << b.quantity << endl;
return;
}
}
cout << "Book not found!\n";
}


void sellBook() {
int id, qty;
cout << "Enter Book ID to sell: ";
cin >> id;
cout << "Enter Quantity: ";
cin >> qty;


for (auto &b : books) {
if (b.id == id) {
if (b.quantity >= qty) {
b.quantity -= qty;
cout << "Sale successful! Total cost = " << (b.price * qty) << endl;
} else {
cout << "Insufficient stock!\n";
}
return;
}
}
cout << "Book not found!\n";
}
};


int main() {
BookShop shop;
int choice;


do {
cout << "\n===== Book Shop Management System =====\n";
cout << "1. Add Book\n";
cout << "2. Display Books\n";
cout << "3. Search Book\n";
cout << "4. Sell Book\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;


switch (choice) {
case 1:
shop.addBook();
break;
case 2:
shop.displayBooks();
break;
case 3:
shop.searchBook();
break;
case 4:
shop.sellBook();
break;
case 5:
cout << "Thank you! Exiting...\n";
break;
default:
cout << "Invalid choice!\n";
}
} while (choice != 5);


return 0;
}