#include <Phonebook.hpp>

int main(int ac, const char **av)
{
	Phonebook phonebook = Phonebook();
	std::string command;

	while (getline(std::cin, command))
		phonebook.query(command);

	return (0);
}