#pragma once
#include<string>

class Patient
{
public:
	Patient();
	unsigned short getId() const; //id 
	void setId(unsigned short);
	const std::string& get_name() const; //name
	std::string& set_name();
	char getSex() const;
	void setSex(char);
	unsigned short getAge() const;
	void setAge(unsigned short);
	unsigned short getHeight() const;
	void setHeight(unsigned short);
	unsigned short getWeight() const;
	void setWeight(unsigned short);
	std::string getPatientHistory() const;
	void setPatientHistory(std::string);
	unsigned short getNeckLength_() const;
	void setNeckLength_(unsigned short);
	unsigned short getNeckWaistLength() const;
	void setNeckWaistLength(unsigned short);
private:
	unsigned short id_;
	std::string name_;
	char sex_;
	unsigned short age_;
	unsigned short height_;
	unsigned short weight_;
	std::string patientHistory_;
	unsigned short neckLength_;
	unsigned short neckWaistLength_;
};

#pragma db object(Patient)
#pragma db member(Patient::email_) id