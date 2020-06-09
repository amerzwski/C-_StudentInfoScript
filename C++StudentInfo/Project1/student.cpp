#include "student.h"
#include <iostream>
using namespace std;

//Default constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	this->daysInCourseArray = new int[NUM_COURSES];
	for (int i = 0; i < NUM_COURSES; ++i) {
		this->daysInCourseArray[i] = 0;
	}
	//degreeType will only be assigned in subclass
}

//Overloaded constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourseArray[], Degree degreeType) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysInCourseArray = new int[NUM_COURSES];
	for (int i = 0; i < NUM_COURSES; ++i) {
		this->daysInCourseArray[i] = daysInCourseArray[i];
		}
	//degreeType will only be assigned in subclass
}

//Accessor functions:
string Student::GetStudentID() const {
	return studentID;
}
string Student::GetFirstName() const {
	return firstName;
}
string Student::GetLastName() const {
	return lastName;
}
string Student::GetEmail() const {
	return emailAddress;
}
int Student::GetStudentAge() const {
	return studentAge;
}
int* Student::GetDaysToComplete() const {
	return daysInCourseArray;
}

//Mutator functions:
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmail(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::SetAge(int studentAge) {
	this->studentAge = studentAge;
}
void Student::SetDaysToComplete(int* daysInCourseArray) {
	if (this->daysInCourseArray != nullptr) {
		delete[] this->daysInCourseArray;
		this->daysInCourseArray = nullptr;
	}
	this->daysInCourseArray = new int[NUM_COURSES];

	for (int i = 0; i < NUM_COURSES; ++i) {
		this->daysInCourseArray[i] = daysInCourseArray[i];
	}
}

//Print student info
void Student::Print() {
	cout << this->GetStudentID() << "\t";
	cout << "First Name: " << this->GetFirstName() << "\t";
	cout << "Last Name: " << this->GetLastName() << "\t";
	cout << "Age: " << this->GetStudentAge() << " \t";
	cout << "Days in course: {" << this->daysInCourseArray[0] << ", " << this->daysInCourseArray[1] << ", " << this->daysInCourseArray[2] << "} " << "\t";
	cout << "Degree Program: ";
	//degreeType will be printed out by the derived class Print()
}

//Destructor
Student::~Student() {
	if (daysInCourseArray != nullptr) {
		delete[] daysInCourseArray;
		daysInCourseArray = nullptr;
	}
}
