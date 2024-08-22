#include <iostream>
using namespace std;
class LibraryItem {
protected:
 string title;
 string author;
public:
 LibraryItem(string t, string a){
 title=t;
 author=a;
 }
 void display_details() {
 cout << "Title: " << title << ", Author: " << author << endl;
 }
};
class Book : public LibraryItem {
private:
 string genre;
public:
 Book(string t, string a, string g) : LibraryItem(t, a){
 genre=g;
 };
 void display_details() {
 LibraryItem::display_details();
 cout << "Genre: " << genre << endl;
 }
};
class Magazine : public LibraryItem {
private:
 int issue_number;
public:
 Magazine(string t, string a, int issue)
 : LibraryItem(t, a), issue_number(issue) {}
 void display_details() {
 LibraryItem::display_details();
 cout << "Issue Number: " << issue_number << endl;
 }
};
class DVD : public LibraryItem {
private:
 int duration;
public:
 DVD(string t, string a, int d)
 : LibraryItem(t, a), duration(d) {}
 void display_details() {
 LibraryItem::display_details();
 cout << "Duration: " << duration << " minutes" << endl;
 }
};
class Library {
private:
 static const int MAX_ITEMS = 10;
 LibraryItem* items[MAX_ITEMS];
 int item_count;
public:
 Library() : item_count(0) {} // Constructor initializes with zero items
 void add_item(LibraryItem* item) {
 if (item_count < MAX_ITEMS) {
 items[item_count] = item; // Add item to the array
 item_count++;
 } else {
 cout << "Library is full." <<endl;
 }
 }
 void display_items() {
 cout << "Library contains the following items:" << endl;
 for (int i = 0; i < item_count; i++) {
 items[i]->display_details();
 }
 }
};
 main() {
 Library library;
 Book book1("The Hobbit", "J.R.R Tolkien", "Novel");
 Magazine magazine1("Finding Mr Wallace", "Kurt Wagner", 89);
 DVD dvd1("The Godfather", "Mario Puzo", 127);
 library.add_item(&book1);
 library.add_item(&magazine1);
 library.add_item(&dvd1);
 library.display_items();
}
