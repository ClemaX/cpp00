#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

class Contact
{
private:
	bool is_empty = true;

	void query_field(std::string &field, std::string field_name, std::string default_value);
	void print_field(std::string &field, std::string field_name);

public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;

	bool empty()
	{
		return (is_empty);
	}

	void query_fields();
	void print_fields();
};

#endif