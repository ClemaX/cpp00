#include <Phonebook.hpp>

int main(void)
{
	Phonebook phonebook = Phonebook();
	std::string command;

	while (getline(std::cin, command))
		phonebook.query(command);

	return (0);
}