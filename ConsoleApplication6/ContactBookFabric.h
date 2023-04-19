#pragma once
#include <string>
#include <fstream>
#include "ContactBook.h"
using namespace std;
class ContactBookFabric
{
private:
	string path;
	ofstream out;//for write
	ifstream in; // for read
	ContactBook book;
public:
	ContactBookFabric(string path) {
		this->path = path;
	}

	ContactBook& getContactBook() {
		in.open(path);
		if (in.is_open()) {
			string buf;
			int countLine = 0;
			Contact contact;
			while (getline(in, buf))
			{

				switch (++countLine)
				{
				case 1:
					contact.setName(buf.c_str());
					break;
				case 2:
					contact.setLastname(buf.c_str());
					break;
				case 3:
					contact.setNumber(buf.c_str());
					break;
				default:
					countLine = 0;
					book.addContact(contact);
					break;
				}
			}

		}
		in.close();
		return book;
	}
};

