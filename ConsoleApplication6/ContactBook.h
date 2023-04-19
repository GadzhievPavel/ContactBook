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
		arrayContacts = new Contact[size];
		this->size = size;
		for (int i = 0; i < size; i++) {
			arrayContacts[i] = contacts[i];
		}
	}

	Contact getContact(int i) {
		return this->arrayContacts[i];
	}

	void addContact(Contact& contact) {
		Contact* temp = new Contact[size + 1];
		Contact* src = this->arrayContacts;
		for (int i = 0; i < size; i++) {
			copyContact(*(temp+i), *(src+i));
		}

		copyContact(*(temp+size), contact);
		delete[] arrayContacts;
		arrayContacts = temp;
		size++;
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
		if (arrayContacts) {
			delete[] arrayContacts;
		}
	}
};

