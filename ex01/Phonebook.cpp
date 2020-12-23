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

std::size_t select_index(std::size_t range)
{
	std::string selection;
	std::size_t input_index;
	std::size_t selection_index = -1;

	while (selection.empty() || input_index != selection.length() || selection_index < 0 || selection_index >= range)
	{
		std::cout << "Selection [0";
		if (range > 1)
			std::cout << " - " << range - 1;
		std::cout << "]: ";

		if (!getline(std::cin, selection))
			exit(0);
		try
		{
			selection_index = std::stoul(selection, &input_index);
		}
		catch (...)
		{
			selection_index = -1;
		}
	}
	return (selection_index);
}

bool Phonebook::query(std::string input)
{
	if (input == "ADD")
	{
		if (index < contacts.size())
			return (contacts[index++].query_fields());
		else
			std::cout << "Error: Please purchase the full version of this software to save more than " << MAX_CONTACTS << " contacts!" << std::endl;
	}
	else if (input == "SEARCH")
	{
		if (index == 0)
			std::cout << "You didn't save any contacts yet. Use the \"ADD\" command!" << std::endl;
		else
		{
			std::cout << std::setw(COLUMN_WIDTH) << "INDEX" << SEPARATOR;
			std::cout << std::setw(COLUMN_WIDTH) << "FIRST NAME" << SEPARATOR;
			std::cout << std::setw(COLUMN_WIDTH) << "LAST NAME" << SEPARATOR;
			std::cout << std::setw(COLUMN_WIDTH) << "NICKNAME" << std::endl;

			for (std::size_t i = 0; i < index; i++)
			{
				std::cout << std::setw(COLUMN_WIDTH) << i << SEPARATOR;
				std::cout << contacts[i] << std::endl;
			}

			std::size_t selection_index = select_index(index);

			contacts[selection_index].print_fields();
		}
	}
	else if (input == "EXIT")
		return (false);
	return (true);
}