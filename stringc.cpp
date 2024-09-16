// stringc.cpp : This file contains the class function.
//

#include "String.h"

// Constructor cu sir initializat
String::String(const char *st)
{
	len = strlen(st);
	str = new char[len + 1];
	strcpy(str, st);
}

// Constructor de copiere
String::String(const String &obj)
{
	len = obj.len;
	str = new char[len + 1];
	strcpy(str, obj.str);
}

// Supraincarcarea op= pentru atribuiea unui obiect altui obiect
String & String::operator=(const String &obj)
{
	if (this == &obj) //verificare daca se face atribuirea aceluiasi obiect
		return *this;

	if (str != nullptr) // Daca nu e nullptr sa se stearga str
		delete[]str;

	char* new_str = new char[obj.len + 1];
	strcpy(new_str, obj.str);

	len = obj.len;
	str = new_str;

	return *this;
}

// Supraincarcarea op+ pentru concatenarea unui obiect cu un sir
String String::operator+(const char *st)
{
	String temp;

	temp.len = len + strlen(st);
	temp.str = new char[temp.len + 1];

	strcpy(temp.str, str);
	strcat(temp.str, st);

	return temp;
}

// Supraincarcarea op+ pentru concatenarea unui obiect cu alt obiect
String String::operator+(const String &obj) {
	String temp;  
	temp.len = len + obj.len + 1;
	temp.str = new char[temp.len];

	strcpy(temp.str, str);  
	strcat(temp.str, obj.str);  

	return temp; 
}

String operator+(const char *st, String &obj)
{
	String temp;
	temp.len = strlen(st);
	temp.len += strlen(obj.str);
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, st);
	strcat(temp.str, obj.str);
	return temp;
}
// Supraincarcarea op+= pentru concatenarea unui obiect cu alt obiect
String String::operator+=(const String &obj)
{
	String temp;
	temp.len = len + obj.len + 1;
	temp.str = new char[temp.len];

	strcpy(temp.str, str);
	strcat(temp.str, obj.str);
	return operator=(temp);
}

// Supraincarcarea op+= pentru concatenarea unui obiect cu un sir
String String::operator+=(const char *st)
{
	String temp;

	temp.len = len + strlen(st);
	temp.str = new char[temp.len + 1];

	strcpy(temp.str, str);
	strcat(temp.str, st);

	return operator = (temp);
}

bool operator<(const String & obj1, const String & obj2)
{
	return obj1.str < obj2.str;
}

bool operator>(const String & obj1, const String & obj2)
{
	return obj1.str > obj2.str;
}
bool operator==(const String &obj1, const String &obj2)
{
	return !(strcmp(obj1.str, obj2.str));
}
//Functii friend pentru citire / scriere

// Scriere
std::ostream &operator<<(std::ostream &os, const String &obj)
{
	os << obj.str;
	return os;
}

// Citire
std::istream &operator>>(std::istream &is, String &obj)
{
	char temp[512]; //variabila temporara pentru salvarea sirului
	is >> temp;

	if (obj.str != nullptr)
		delete[]obj.str;

	obj.len = strlen(temp);
	obj.str = new char[obj.len + 1];
	strcpy(obj.str, temp);

	return is;
	
}
std::istream &getline(std::istream &is, String &obj)
{
	char temp[512];
	is.getline(temp, 512);
	if (obj.str != nullptr)
		delete[]obj.str;
	obj.len = strlen(temp);
	obj.str = new char[obj.len + 1];
	strcpy(obj.str, temp);
	return is;
}

std::istream &get(std::istream &is, String &obj)
{
	char temp[512];
	is.get(temp, 512);

	if (obj.str != nullptr)
		delete[]obj.str;

	obj.len = strlen(temp);
	obj.str = new char[obj.len + 1];
	strcpy(obj.str, temp);
	return is;
}