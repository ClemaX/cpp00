#include <string>
#include <iostream>

std::string strupper(const char *in)
{
	std::string out = in;

	for (char &c : out)
		c = toupper(c);
	return (out);
}

int main(int ac, const char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < ac; i++)
			std::cout << strupper(av[i]);
	std::cout << "\n";
	return (0);
}