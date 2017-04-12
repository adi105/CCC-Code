#pragma once
#include <string>

class Student {
public:
	//constructor
	Student(std::string stuName, char stuLetterGrade);
	Student();

	//operator overloads
	friend bool operator== (const Student& stu1, const Student& stu2);
	friend std::ostream& operator<< (std::ostream& stream, const Student& student);
	friend bool operator!= (const Student& stu1, const Student& stu2);

private:
	std::string name;
	char letterGrade;
};

//operator overloads (provided because they aren’t covered in detail until CS202)
bool operator== (const Student& stu1, const Student& stu2)
{
	if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade)
		return true;
	else
		return false;
}
std::ostream& operator<< (std::ostream& stream, const Student& student)
{
	stream << student.name;
	stream << " (" << student.letterGrade << ") ";
	return stream;
}

//added an operator overload for != because it is used inside of the
//remove function and was throwing errors
bool operator!= (const Student& stu1, const Student& stu2) {
	if (stu1.name != stu2.name && stu1.letterGrade != stu2.letterGrade)
		return true;
	else
		return false;
}

//sets the student's name as the given string and the student's
//gpa as the given char
Student::Student(std::string stuName, char stuLetterGrade) {
	name = stuName;
	letterGrade = stuLetterGrade;
}

//sets the default values for the student
//as an empty name and empty gpa
Student::Student() {
	name = "";
	letterGrade = '\0';
}
