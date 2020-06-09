#include "networkStudent.h"
#include <iostream>
using namespace std;

NetworkStudent::NetworkStudent() {
	SetDegreeProgram(NETWORK);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourseArray[NUM_COURSES], Degree degreeType) {
	//All the other fields are constructed in base class Student
	SetDegreeProgram(NETWORK);
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}

void NetworkStudent::SetDegreeProgram(Degree degreeType) {
	this->degreeType = degreeType;
}

Degree NetworkStudent::GetDegreeProgram() {
	return NETWORK;
}

void NetworkStudent::Print() {
	Student::Print();
	cout << "NETWORK" << endl;
}
