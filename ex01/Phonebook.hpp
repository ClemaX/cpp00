#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10
# define SEPARATOR '|'

# include <Contact.hpp>

# include <string>
# include <iostream>
# include <iomanip>

class Phonebook
{
private:
	std::array<Contact, MAX_CONTACTS> contacts;
	std::size_t index = 0;

public:
	void query(std::string input);
};

#endif