#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Book {
protected:
  vector<vector<string>> books = {{"The Alchemist", "1", "200"},
                                  {"The Great Gatsby", "2", "300"},
                                  {"To Kill a Mockingbird", "3", "400"},
                                  {"Pride and Prejudice", "4", "500"},
                                  {"1984", "5", "600"},
                                  {"The Catcher in the Rye", "6", "700"}};

public:
  void display_books() {
    cout << "Book Details" << endl << endl;
    cout << "Book 1:" << endl << endl;
    for (int i = 0; i < books.size(); i++) {
      for (int j = 0; j < books[i].size(); j++) {
        cout << books[i][j] << '\n';
      }
      cout << endl << endl;
      cout << "Book" << i + 1 << ":" << endl << endl;
    }
  }
};

class Account { // Account class//
public:
  string account_name;
  char password[30];
  string email;
  string address;
  char verify_password[30];
  string file_name;

  void login() { // login function//

    cout << "\nEnter your account name: ";
    cin >> account_name;
    cout << "\nEnter your password: ";
    cin >> password;
    file_name = account_name + ".txt";
    ifstream user_file(file_name);
    if (user_file.is_open()) {
      user_file.getline(verify_password, 30);
      if (strcmp(password, verify_password) == 0) {
        cout << "Login Successful" << endl;
      } else {
        cout << "Login Failed" << endl;
        login();
      }
    } else {
      cerr << "Account does not exist" << endl;
      cout << "Sign up" << endl;
      sign_up();
    }
  }

  void sign_up() { // sign up function//

    cout << "Enter your email id:";
    cin >> email;
    cout << "\nEnter your account name: ";
    cin >> account_name;
    cout << "\nEnter your password: ";
    cin >> password;
    cout << "\nenter your password again: ";
    cin >> verify_password;
    cout << "\nEnter your address: ";
    cin >> address;
    if (strcmp(password, verify_password) == 0) {
      file_name = account_name + ".txt";
      ofstream user_file(file_name);
      user_file << verify_password << endl;
      user_file << account_name << endl;
      user_file << email << endl;
      user_file << address << endl; 
      user_file << endl;
      user_file << "Books Rented: " << endl;
      user_file << endl;
      user_file.close();
      cout << "Account created successfully" << endl;
    } else {
      cout << "Passwords do not match" << endl;
    }
  }

  void change_account_name() { // to change account name//

    string line;
    int line_number = 0;
    string new_file_txt = "input.txt";
    string new_account_name;

    cout << "Enter your new account name: ";
    cin >> new_account_name;

    ifstream user_file(file_name);
    ofstream new_file(new_file_txt);

    while (getline(user_file, line)) {
      line_number++;
      if (account_name == line) {
        new_file << new_account_name << endl;
        cout << "\nAccount name changed successfully" << endl;
      } else {
        new_file << line << endl;
      }
    }
    user_file.close();
    new_file.close();
    remove(file_name.c_str());
    rename(new_file_txt.c_str(), file_name.c_str());
  }

  void change_password() { // to change password//
    string line;
    int line_number = 0;
    string new_file_txt = "input.txt";
    char new_password[30];

    cout << "Enter your new password: ";
    cin >> new_password;

    ifstream user_file(file_name);
    ofstream new_file(new_file_txt);

    while (getline(user_file, line)) {
      line_number++;
      if (password == line) {
        new_file << new_password << endl;
        cout << "\nPassword changed successfully" << endl;
      } else {
        new_file << line << endl;
      }
    }
    user_file.close();
    new_file.close();
    remove(file_name.c_str());
    rename(new_file_txt.c_str(), file_name.c_str());
  }

  void change_email() { // to change email//
    string line;
    int line_number = 0;
    string new_file_txt = "input.txt";
    string new_email;

    cout << "Enter your new email: ";
    cin >> new_email;

    ifstream user_file(file_name);
    ofstream new_file(new_file_txt);

    while (getline(user_file, line)) {
      line_number++;
      if (email == line) {
        new_file << new_email << endl;
        cout << "\nEmail changed successfully" << endl;
      } else {
        new_file << line << endl;
      }
    }
    user_file.close();
    new_file.close();
    remove(file_name.c_str());
    rename(new_file_txt.c_str(), file_name.c_str());
  }
};

class Library_System : public Account, public Book {

public:
  Library_System() {
    cout << "Welcome to the library" << endl;
    cout << "_______ __ ___ _______" << endl;
    int confirmation;
    cout << "\n1)Do you want to sign up?\n2)Do you want to login?\n";
    cin >> confirmation;
    if (confirmation == 1) {
      cout << "\nSign up" << endl;
      sign_up();
      display();
    } else {
      cout << "You can login now" << endl;
      login();
      display();
    }
  }

  void display() {
    cout << "\n\n1)Rent a book\n2)Return a book\n3)Change Account "
            "Name\n4)Change Password\n5)Change Email\n6)Exit"
         << endl;
    int confirmation;
    cin >> confirmation;
    if (confirmation == 1) {
      display_books();
      book_rent();
    } else if (confirmation == 2) {
      display_books();
      book_return();
    } else if (confirmation == 3) {
      change_account_name();
      display();
    } else if (confirmation == 4) {
      change_password();
      display();
    } else if (confirmation == 5) {
      change_email();
      display();
    } else if(confirmation ==6 ) {
        cout << "Thank you for visiting" << endl;
    }
  }

  void book_rent() {
    string book_id;
    string confirmation1;
    int found = 0;
    cout << "Enter the id of the book you want to rent: ";
    cin >> book_id;
    ofstream user_file(file_name, ios::app);

    for (int i = 0; i < books.size(); i++) {
      if (books[i][1] == book_id) {
        user_file << books[i][0] << endl;
        cout << books[i][0] << " has been rented successfully" << endl<<endl;
        cout<< "The Rented Book will be delivered to the given Address! " << endl;
        found = 1;
      }
    }
    user_file.close();

    if (found == 0) {
      cout << "Book not found" << endl << endl;
      display();
    } else {
      display();
    }
  }

  void book_return() {
    string book_name;
    string confirmation2;
    string line;
    int line_number = 0;
    string new_file_txt = "input.txt";
    int found = 0;

    ifstream user_file(file_name);
    ofstream new_file(new_file_txt);

    cout << "\nEnter the book name you want to return: ";
    cin >> book_name;

    while (getline(user_file, line)) {
      if (line.find(book_name) != string::npos) {
        cout << "\nBook returned successfully" << endl << endl;
        found = 1;
      } else {
        new_file << line << endl;
      }
      line_number++;
    }
    user_file.close();
    new_file.close();
    remove(file_name.c_str());
    rename(new_file_txt.c_str(), file_name.c_str());

    if (found == 0) {
      cout << "Book not found" << endl << endl;
      cout << "Do you want to return a book? (y/n): ";
      cin >> confirmation2;
      if(confirmation2 == "y") {
        book_return();
      }else{
        display();
      }
    }else{
      display();
    }
    }
  };

int main() { 
  Library_System library;
}