#include <Contact.hpp>

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

void	Contact::print_fields() {
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