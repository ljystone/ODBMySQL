#pragma once
#include<string>
class Patient
{
public:
	Patient();

	const std::string& email() const;
	void email(const std::string&);

	const std::string& get_name() const;
	std::string& set_name();

	unsigned short getAge() const;
	void setAge(unsigned short);

private:
	std::string email_;
	std::string name_;
	unsigned short age_;
};

#pragma db object(person)
#pragma db member(person::email_) id