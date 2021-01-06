#pragma once

#include <InputField.hpp>

#include <Validators.hpp>

class Contact
{
private:
	bool	is_empty = true;

public:
	TextInputField	first_name = TextInputField("First name", &name_validator);
	TextInputField	last_name = TextInputField("Last name", &name_validator);
	TextInputField	nickname = TextInputField("Nickname", &name_validator);
	TextInputField	login = TextInputField("Login", &name_validator);
	TextInputField	postal_address = TextInputField("Postal address", &name_validator);
	TextInputField	email_address = TextInputField("Email address", &email_validator);
	TextInputField	phone_number = TextInputField("Phone number", &phone_number_validator);
	DateInputField	birthday_date = DateInputField("Birthday date");
	TextInputField	favorite_meal = TextInputField("Favorite meal", &name_validator);
	TextInputField	underwear_color = TextInputField("Underwear color", &name_validator);
	TextInputField	darkest_secret = TextInputField("Darkest secret", &name_validator);

	bool	empty()
	{
		return (is_empty);
	}
	bool	query_fields();
	void	print_fields();
};
