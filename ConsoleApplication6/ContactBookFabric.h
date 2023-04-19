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
	//ContactBook book;
public:
	ContactBookFabric(string path) {
		this->path = path;
	}

	ContactBook getContactBook() {
		ContactBook book;
		in.open(path);
		if (in.is_open()) {
			
			while (!in.eof())
			{
				string databuf[3];
				for (int i = 0; i < 3; i++) {
					string buf;
					getline(in, buf);
					databuf[i] = buf;
				}
				
				Contact c(databuf[0].c_str(), databuf[1].c_str(), databuf[2].c_str());
				book.addContact(c);
			}

		}
		in.close();
		return book;
	}
};

