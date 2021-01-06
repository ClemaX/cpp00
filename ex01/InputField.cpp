#include <InputField.hpp>

bool TextInputField::query()
{
	const char	*validation_error;

	do
	{
		std::cout << name << ": ";
		if (std::cin.eof() || !getline(std::cin, value))
			return (false);
		if ((validation_error = validator(value)))
			std::cout << name << ' ' << validation_error << std::endl;
	} while (validation_error);

	return (true);
}

void TextInputField::print() const
{
	std::cout << name << ": " << value << std::endl;
}

TextInputField::operator std::string() const
{
	return (value);
}

const char	*DateInputField::validate()
{
	const char	*error = NULL;

	if (day == 0 || day > 31)
		error = "day must be in the range 1-31!";
	else if (month == 0 || month > 12)
		error = "month must be in the range 1-12!";
	return (error);
}

bool DateInputField::query()
{
	std::string	line;
	const char	*validation_error;

	while (!std::cin.eof())
	{
		validation_error = "must be in the format DD/MM/YYYY!";
		std::cout << name << ": ";
		if (!getline(std::cin, line))
			return (false);
		std::istringstream	line_stream(line);
		line_stream >> day;
		if (line_stream.get() == '/')
		{
			line_stream >> month;
			if (line_stream.get() == '/')
			{
				line_stream >> year;
				if (!(validation_error = validate()))
					return (true);
			}
		}
		std::cout << name << ' ' << validation_error << std::endl;
	}
	return (false);
}

void DateInputField::print() const
{
	std::cout << "day: " << day << '\n';
	std::cout << "month: " << month << '\n';
	std::cout << "year: " << year << '\n';
}

DateInputField::operator std::string() const
{
	return ("TIME");
}
