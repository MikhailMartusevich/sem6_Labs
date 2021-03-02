#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

class phoneBook {
public:
	std::string lastName = "";
	std::string street = "";
	int houseNumber = 0;
	int releaseYear = 0;
	std::string phoneNumber = "";


	friend std::istream& operator>> (std::istream& in, phoneBook& ph);
	friend std::ostream& operator<< (std::ostream& out, phoneBook& ph);

	phoneBook();
	phoneBook(const char* _lastname, const char* _street, int _number, int _year);
	
};

#endif // !PHONEBOOK_H

//	Сформировать массив на диске, содержащий сведения о телефонах абонентов. 
//  Структурный тип содержит поля: фамилия абонента, место жительства (название улицы, номер дома), год установки телефона
// 	Написать программу, которая выбирает необходимую информацию с диска и выводит на экран:
//- номер телефона по вводимой с клавиатуры фамилии абонента;
//-количество установленных телефонов с XXXX года;
//-список номеров телефонов, принадлежащих жильцам определенного дома и улицы.
//Номер года, название улицы и номер дома вводятся с клавиатуры
