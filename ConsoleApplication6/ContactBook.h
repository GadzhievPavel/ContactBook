#pragma once
#include"Contact.h"
#include<string>
using namespace std;
class ContactBook
{
private:
	Contact* arrayContacts;
	int size;

	void copyContact(Contact* dst, Contact* src) {
		dst->setName(src->getName());
		dst->setLastname(src->getLastname());
		dst->setNumber(src->getNumber());
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

	void addContact(Contact contact) {
		Contact* temp = new Contact[size + 1];
		Contact* src = this->arrayContacts;
		for (int i = 0; i < size; i++) {
			//temp[i] = this->arrayContacts[i];
			/*strcpy_s(temp->getName(), strlen(arrayContacts[i].getName()) + 1, arrayContacts[i].getName());
			strcpy_s(temp->getLastname(), strlen(arrayContacts[i].getLastname()) + 1, arrayContacts[i].getLastname());
			strcpy_s(temp->getNumber(), strlen(arrayContacts[i].getNumber()) + 1, arrayContacts[i].getNumber());*/
			copyContact(temp++, src++);
		}

		copyContact(temp, &contact);
		delete[] arrayContacts;
		arrayContacts = temp-size;
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

