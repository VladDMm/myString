#pragma once
#ifndef STRING_H_
#define STRING_H
#include <iostream>
#include <cstring>

class String
{
public:
	String() : str(nullptr), len(0) {};//Constructor implicit
	String(const char *st); //Constructor de creare prin initializare
	String(const String &); // Constructor copiere
	String &operator=(const String &obj); // Supraincarcarea op= de atriubuire un sir altui
	String operator+(const String &obj); // Supraincarcarea op+ de concatenare unui obiect cu alt obiect
	String operator+(const char *st); // concatenare un obiect cu un sir
	friend String operator+(const char *st, String &obj);
	String operator+=(const char *st); // Supraincarcare op+= pentru sir
	String operator+=(const String &obj); //Supraincarcare op+= pentru obiect
	friend bool operator<(const String &obj1, const String &obj2);
	friend bool operator>(const String &obj1, const String &obj2);
	friend bool operator==(const String &obj1, const String &obj2);
	// functii friend pentru operatorii >> && <<
	
	friend std::ostream &operator<<(std::ostream &os,const String &obj); // functie de afisare
	friend std::istream &operator>>(std::istream &is, String &obj); // functie de introducere
	friend std::istream &getline(std::istream &is, String &obj); // functie de introducere
	friend std::istream &get(std::istream &is, String &obj); // functie de introducere

	~String() { delete[]str; };

private:
	char * str; // pointer catre sir
	int len; // marimea sirului
};


#endif