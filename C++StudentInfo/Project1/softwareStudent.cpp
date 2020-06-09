#include "softwareStudent.h"
#include <iostream>
using namespace std;

SoftwareStudent::SoftwareStudent() {
	SetDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourseArray[NUM_COURSES], Degree degreeType) {
	//All the other fields are constructed in base class Student
	SetDegreeProgram(SOFTWARE);
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
	delete this;
}

void SoftwareStudent::SetDegreeProgram(Degree degreeType) {
	this->degreeType = degreeType;
}

Degree SoftwareStudent::GetDegreeProgram() {
	return SOFTWARE;
}

void SoftwareStudent::Print() {
	Student::Print();
	cout << "SOFTWARE" << endl;
}