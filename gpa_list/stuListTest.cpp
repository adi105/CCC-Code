#include "student.h"
#include "studentList.h"
#include <iostream>
using namespace std;


int main() {
	StudentList list;
	Student* student;

	//test data
	char* names[] = { "Adam", "Bob", "Clara", "Dot", "Ed", "Frank",
		"Greg", "Hiedi", "Ida", "Joe", "Kay" };
	float gpas[] = { 3.5,    3.6,   3.7,     3.8,   3.9,  4.0,
		2.0,    2.5,     2.6,   2.7,   2.8 };

	//try inserting 11.
	for (int x = 0; x < 11; x++) {
		student = new Student(gpas[x], names[x]);
		if (list.insert(student) == false) {
			cout << "Error - student insert failed" << endl;
			delete student;
		}
	}
	list.print();

	//remove a few
	list.remove("Adam");
	list.remove("Frank");
	list.remove("Joe");
	list.print();

	//insert two more (note: they won’t be in order)
	student = new Student(1.0, "zed");
	student->changeName("Zorro");
	list.insert(student);
	list.insert(new Student(1.1, "Zorro2"));
	list.print();

	return 1;
}