#include "securityStudent.h"
#include <iostream>
using namespace std;

SecurityStudent::SecurityStudent() {
	SetDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourseArray[NUM_COURSES], Degree degreeType) {
	//All the other fields are constructed in base class Student
	SetDegreeProgram(SECURITY);
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
	delete this;
}

void SecurityStudent::SetDegreeProgram(Degree degreeType) {
	this->degreeType = degreeType;
}

Degree SecurityStudent::GetDegreeProgram() {
	return SECURITY;
}

void SecurityStudent::Print() {
	Student::Print();
	cout << "SECURITY" << endl;
}
