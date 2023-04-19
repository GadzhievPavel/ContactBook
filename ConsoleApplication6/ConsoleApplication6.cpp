// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ContactBook.h"
#include "Contact.h"
#include "ContactBookFabric.h"
Contact createContact() {
    char name[50], lastname[50], number[10];
    cout << "enter new contact";
    cin >> name;
    cin >> lastname;
    cin >> number;

    return Contact(name, lastname, number);
}

int main()
{
    /*Contact* arr = new Contact[3]{ {"Ivan","Ivanov","88005553535"},
        {"Peter","Petrov","909075"},{"Sidor","Sidoorov","241141"}};
    ContactBook book = ContactBook(arr,3);
    std::cout << book.toString();*/
    
    ContactBookFabric fabricBook("book.txt");
    ContactBook book = fabricBook.getContactBook();
    std::cout << book.toString();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
