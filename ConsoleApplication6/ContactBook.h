#pragma once
#include"Contact.h"
#include<string>
using namespace std;
class ContactBook
{
private:
	Contact* arrayContacts;
	int size;

	void copyContact(Contact& dst, Contact& src) {
		dst.setName(src.getName());
		dst.setLastname(src.getLastname());
		dst.setNumber(src.getNumber());
	}
public:
	ContactBook(Contact* contacts, int size) {
		if (contacts) {
			arrayContacts = new Contact[size];
			this->size = size;
			for (int i = 0; i < size; i++) {
				arrayContacts[i] = contacts[i];
			}
		}
		else {
			contacts = nullptr;
			this->size = size;
		}
	}

	ContactBook() :ContactBook(nullptr, 0) {};
	
	ContactBook(const ContactBook& book) {
		this->size = book.size;
		if (book.arrayContacts) {
			arrayContacts = new Contact[book.size];
			for (int i = 0; i < size; i++) {
				arrayContacts[i] = book.arrayContacts[i];
			}
		}
		else {
			arrayContacts = nullptr;
		}
	}
	Contact getContact(int i) {
		return this->arrayContacts[i];
	}

	void addContact(Contact& contact) {
		if (size>0) {
			Contact* temp = new Contact[size + 1];
			Contact* src = this->arrayContacts;
			for (int i = 0; i < size; i++) {
				copyContact(*(temp + i), *(src + i));
			}

			copyContact(*(temp + size), contact);
			delete[] arrayContacts;
			arrayContacts = temp;
			size++;
		}
		else {
			arrayContacts = new Contact[1]{ contact };
			size=1;
		}
		//cout << "size book"<<size;
	}

	string toString() {
		string s = "";
		for (int i = 0; i < size; i++) {
			s.append(arrayContacts[i].toString());
			s.append("\n");
		}
		return s;
	}
	~ContactBook() {
		//std::cout << "Delete book";
		if (arrayContacts) {
			delete[] arrayContacts;
		}
	}
};

