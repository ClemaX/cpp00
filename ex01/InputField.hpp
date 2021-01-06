#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <ctime>

typedef	const char	*(*text_validator)(std::string &);

class InputField
{
public:
	const std::string	name;

	bool query();
	void print();

	operator std::string() const;

	InputField(const std::string name)
		: name(name) {};
};

class TextInputField : InputField
{
private:
	std::string				value;
	const text_validator	validator;

public:
	bool query();
	void print();
 
	operator std::string() const;

	TextInputField(const std::string name, const text_validator validator)
		: InputField(name), validator(validator) {};
};

class DateInputField : public InputField
{
private:
	unsigned	day;
	unsigned	month;
	unsigned	year;

public:
	bool		query();
	const char	*validate();
	void		print();

	operator std::string() const;

	DateInputField(const std::string name)
		: InputField(name) {};
};
