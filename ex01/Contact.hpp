#pragma once

#include <InputField.hpp>

#include <Validators.hpp>

class Contact
{
private:
	bool	is_empty;

public:
	TextInputField	first_name;
	TextInputField	last_name;
	TextInputField	nickname;
	TextInputField	login;
	TextInputField	postal_address;
	TextInputField	email_address;
	TextInputField	phone_number;
	DateInputField	birthday_date;
	TextInputField	favorite_meal;
	TextInputField	underwear_color;
	TextInputField	darkest_secret;

	bool	empty() const;
	bool	query_fields();
	void	print_fields() const;

	Contact();
	~Contact();
};
