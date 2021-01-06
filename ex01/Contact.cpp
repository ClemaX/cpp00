#include <Contact.hpp>

Contact::Contact(void)
:	is_empty(true),
	first_name("First name", &name_validator),
	last_name("Last name", &name_validator),
	nickname("Nickname", &name_validator),
	login("Login", &name_validator),
	postal_address("Postal address", &name_validator),
	email_address("Email address", &email_validator),
	phone_number("Phone number", &phone_number_validator),
	birthday_date("Birthday date"),
	favorite_meal("Favorite meal", &name_validator),
	underwear_color("Underwear color", &name_validator),
	darkest_secret("Darkest secret", &name_validator)
{
}

Contact::~Contact(void) {}

bool	Contact::empty() const
{
	return (is_empty);
}

bool	Contact::query_fields()
{
	is_empty = !(
		first_name.query()
		&& last_name.query()
		&& nickname.query()
		&& login.query()
		&& postal_address.query()
		&& email_address.query()
		&& phone_number.query()
		&& birthday_date.query()
		&& favorite_meal.query()
		&& underwear_color.query()
		&& darkest_secret.query()
	);

	return (!is_empty);
}

void	Contact::print_fields() const
{
	if (!is_empty)
	{
		first_name.print();
		last_name.print();
		nickname.print();
		login.print();
		postal_address.print();
		email_address.print();
		phone_number.print();
		birthday_date.print();
		favorite_meal.print();
		underwear_color.print();
		darkest_secret.print();
	}
}
