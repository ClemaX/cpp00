#include <Contact.hpp>

void Contact::query_field(std::string &field, std::string field_name, std::string default_value)
{
	std::cout << field_name << ": [" << default_value << "] ";
	if (!getline(std::cin, field))
		exit(0);
	if (field.empty())
		field = default_value;
}

void Contact::query_fields()
{
	query_field(first_name, "First name", "");
	query_field(last_name, "Last name", "");
	query_field(nickname, "Nickname", "");
	query_field(login, "Login", "");
	query_field(postal_address, "Postal address", "");
	query_field(email_address, "Email address", "");
	query_field(phone_number, "Phone number", "");
	query_field(birthday_date, "Birthday date", "");
	query_field(favorite_meal, "Favorite meal", "");
	query_field(underwear_color, "Underwear color", "");
	query_field(darkest_secret, "Darkest secret", "");
	is_empty = false;
}

void Contact::print_field(std::string &field, std::string field_name) {
	std::cout << field_name << ": " << field << std::endl;
}

void Contact::print_fields() {
	print_field(first_name, "First name");
	print_field(last_name, "Last name");
	print_field(nickname, "Nickname");
	print_field(login, "Login");
	print_field(postal_address, "Postal address");
	print_field(email_address, "Email address");
	print_field(phone_number, "Phone number");
	print_field(birthday_date, "Birthday date");
	print_field(favorite_meal, "Favorite meal");
	print_field(underwear_color, "Underwear color");
	print_field(darkest_secret, "Darkest secret");
}