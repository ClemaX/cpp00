#include <Validators.hpp>

const char	*name_validator(std::string &value)
{
	const char	*error = NULL;

	if (value.empty())
		error = "cannot be empty!";
	return (error);
}

const char	*phone_number_validator(std::string &value)
{
	std::string::const_iterator	it = value.cbegin();
	const char					*error = NULL;

	if (value.empty() || (*it == '+' && ++it == value.cend()))
		error = "cannot be empty!";
	else
	{
		while(it != value.cend() && isdigit(*it))
			it++;
		if (it != value.cend())
			error = "may start with '+', and can only contain digits!";
	}
	return (error);
}

const char	*address_validator(std::string &value)
{
	const char	*error = NULL;

	if (value.empty())
		error = "cannot be empty!";
	return (error);
}

const char	*email_validator(std::string &value)
{
	const char	*error = NULL;

	if (value.empty())
		error = "cannot be empty!";
	else
	{	
		std::string::const_iterator	it = value.cbegin();

		while (isalnum(*it))
			it++;
		if (it == value.cbegin())
			error = "must start with letters or digits!";
		else if (*it != '@')
			error = "must contain '@'!";
		else
		{
			if (++it == value.cend())
				error = "hostname cannot be empty!";
			else
			{
				while (isalnum(*it) || *it == '.' || *it == '-' || *it == '_')
					it++;
				if (it != value.cend())
					error = "hostname can only contain letters, digits, dots or dashes!";
			}
		}
	}
	return (error);
}
