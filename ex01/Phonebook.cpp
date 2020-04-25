#include <Phonebook.hpp>

std::string truncate(std::string field)
{
	if (field.length() > COLUMN_WIDTH)
		return (field.substr(0, COLUMN_WIDTH - 1) + '.');
	return (field);
}

std::ostream &operator<<(std::ostream &os, const Contact &c)
{
	os << std::setw(COLUMN_WIDTH) << truncate(c.first_name) << SEPARATOR;
	os << std::setw(COLUMN_WIDTH) << truncate(c.last_name) << SEPARATOR;
	os << std::setw(COLUMN_WIDTH) << truncate(c.nickname);
	return (os);
}

int select_index(int range)
{
	std::string selection;
	std::size_t input_index;
	int selection_index = -1;

	while (selection.empty() || input_index != selection.length() || selection_index < 0 || selection_index >= range)
	{
		std::cout << "Selection [0";
		if (range > 1)
			std::cout << " - " << std::to_string(range - 1);
		std::cout << "]: ";

		if (!getline(std::cin, selection))
			exit(0);
		try
		{
			selection_index = std::stoi(selection, &input_index);
		}
		catch (...)
		{
			selection_index = -1;
		}
	}

	return (selection_index);
}

void Phonebook::query(std::string input)
{
	if (input == "ADD")
	{
		if (index < contacts.size())
			contacts[index++].query_fields();
		else
			std::cout << "Error: Please purchase the full version of this software to save more than " << std::to_string(MAX_CONTACTS) << " contacts!" << std::endl;
	}
	else if (input == "SEARCH")
	{
		if (index == 0)
		{
			std::cout << "You didn't save any contacts yet. Use the \"ADD\" command!" << std::endl;
			return;
		}
		std::cout << std::setw(COLUMN_WIDTH) << "INDEX" << SEPARATOR;
		std::cout << std::setw(COLUMN_WIDTH) << "FIRST NAME" << SEPARATOR;
		std::cout << std::setw(COLUMN_WIDTH) << "LAST NAME" << SEPARATOR;
		std::cout << std::setw(COLUMN_WIDTH) << "NICKNAME" << std::endl;

		for (int i = 0; i < index; i++)
		{
			std::cout << std::setw(COLUMN_WIDTH) << std::to_string(i) << SEPARATOR;
			std::cout << contacts[i] << std::endl;
		}

		int selection_index = select_index(index);

		contacts[selection_index].print_fields();
	}
	else if (input == "EXIT")
		exit(0);
}