#pragma once

#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10
#define SEPARATOR '|'

#include <Contact.hpp>

#include <string>
#include <iostream>
#include <iomanip>

class Phonebook
{
private:
	Contact		contacts[MAX_CONTACTS];
	std::size_t	index;

public:
	bool	query(std::string input);

	Phonebook();
	~Phonebook();
};
