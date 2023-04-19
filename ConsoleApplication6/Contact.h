#pragma once
#include <iostream>
#include<string>
using namespace std;
class Contact
{
private:
	char* name;
	char* lastname;
	char* number;
public:
	Contact(const char* name, const char* lastname, const char* number) {
		this->name = name ? new char[strlen(name) + 1] : nullptr;
		this->lastname = lastname ? new char[strlen(lastname) + 1] : nullptr;
		this->number = number ? new char[strlen(number) + 1] : nullptr;

		for (int i = 0; i < strlen(name); i++) {
			this->name[i] = name[i];
		}
		for (int i = 0; i < strlen(lastname); i++) {
			this->lastname[i] = lastname[i];
		}
		for (int i = 0; i < strlen(number); i++) {
			this->number[i] = number[i];
		}
	}

	Contact() :Contact("Ivan", "Ivanov", "88005555555") {
		cout << "create contact default\n";
	};

	Contact(const Contact& contact):Contact(contact.name,contact.lastname, contact.number) {

	}

	char*& getName() {
		return this->name;
	}

	void setName(const char* name) {
		if (name && this->name) {
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name)+1, name);
		}
	}

	char*& getLastname() {
		return this->lastname;
	}

	void setLastname(const char* lastname) {
		if (lastname && this->lastname) {
			delete[] this->lastname;
			this->lastname = new char[strlen(lastname) + 1];
			strcpy_s(this->lastname, strlen(lastname)+1, lastname);
		}
	}

	char*& getNumber() {
		return this->number;
	}

	void setNumber(const char* number) {
		if (number && this->number) {
			delete[] this->number;
			this->number = new char[strlen(number) + 1];
			strcpy_s(this->number, strlen(number)+1, number);
		}
	}

	string toString() {
		string s = "";
		s.append(this->name);
		s.append(" ");
		s.append(this->lastname);
		s.append(" ");
		s.append(this->number);
		return s;
	}
	~Contact() {
		//cout << "\ndelete contact\n";
		if (this->name) {
			delete[] name;
		}
		if (this->lastname) {
			delete[] lastname;
		}
		if (this->number) {
			delete[] number;
		}
	}
};

