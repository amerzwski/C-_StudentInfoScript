#include "roster.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	Roster* classRoster = new Roster();
	Degree degreeType;
	string studentArray[9];
	string dataElement = "";

	cout << "C867 - Scripting and Programming (C++)" << endl;
	cout << "Andrew Merzwski - ID#000913380" << endl << endl;

	//Parse studentData strings and store as string array studentArray
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		string dataHolder = studentData[i];
		istringstream inStudentData(dataHolder);
		string studentArray[9];
		string dataElement = "";
		
		int j = 0;
		while (getline(inStudentData, dataElement, ',')) { //Uses comma delimiter to parse each substring
			studentArray[j] = dataElement;
			++j;
		}
		
		//Assign an enumerated type (from degree.h) to degreeType
		if (studentArray[8] == "NETWORK") {
			degreeType = NETWORK;
		}
		else if (studentArray[8] == "SECURITY") {
			degreeType = SECURITY;
		}
		else if (studentArray[8] == "SOFTWARE") {
			degreeType = SOFTWARE;
		}
		else {
			cout << "Error setting degree type." << endl;
		}
	
		//Add one student at a time to classRosterArray, determining which Student subtype based on degreeType
		classRoster->add(studentArray[0], studentArray[1], studentArray[2], studentArray[3], stoi(studentArray[4]), stoi(studentArray[5]), stoi(studentArray[6]), stoi(studentArray[7]), degreeType);
	}

	
	classRoster->printAll(); //Print student info from classRosterArray
	cout << endl;
	classRoster->printInvalidEmails(); //Print all invalid instances of emailAddress in classRosterArray
	cout << endl;

	//For each student, print out the average # days spent in given 3 courses
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentID());
    }
	cout << endl;

	//Print all student info for given degreeType
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	
	classRoster->remove("A3"); //Remove student from classRosterArray
	classRoster->remove("A3"); //Error expected if student no longer exists in classRosterArray

	delete classRoster; //Delete Roster and Student objects

	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Static variables:
int Roster::addCounter = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Roster::Roster() {
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Roster::Roster(int studentNum) {	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Roster::~Roster() {
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			this->classRosterArray[i]->~Student(); //Call destructor for Student objects
		}
	}
	
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Each call to add will create a new Student object and store in classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
	int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	while (this->classRosterArray[addCounter] == nullptr) {
		if (degreeType == NETWORK) {
			this->classRosterArray[addCounter] = new NetworkStudent(studentID, firstName, lastName, emailAddress, studentAge, daysInCourseArray, degreeType);
			this->classRosterArray[addCounter]->SetDegreeProgram(degreeType);
		}
		else if (degreeType == SECURITY) {
			this->classRosterArray[addCounter] = new SecurityStudent(studentID, firstName, lastName, emailAddress, studentAge, daysInCourseArray, degreeType);
			this->classRosterArray[addCounter]->SetDegreeProgram(degreeType);
		}
		else if (degreeType == SOFTWARE) {
			this->classRosterArray[addCounter] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, studentAge, daysInCourseArray, degreeType);
			this->classRosterArray[addCounter]->SetDegreeProgram(degreeType);
		}
		else {
			cout << "Error creating new student (Roster::add)" << endl;
		}

		this->classRosterArray[addCounter]->SetStudentID(studentID);
		this->classRosterArray[addCounter]->SetFirstName(firstName);
		this->classRosterArray[addCounter]->SetLastName(lastName);
		this->classRosterArray[addCounter]->SetEmail(emailAddress);
		this->classRosterArray[addCounter]->SetAge(studentAge);
		this->classRosterArray[addCounter]->SetDaysToComplete(daysInCourseArray);
	}

	++addCounter; //Static variable for incrementing each time function is called
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//Remove student entry from the roster by given studentID
void Roster::remove(string studentID) {
	bool foundStudent = false;
	string deletedFName = ""; //Stores name for cout after entry is removed
	string deletedLName = "";

	//Remove student from classRosterArray if found
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			foundStudent = true;
			deletedFName = classRosterArray[i]->GetFirstName();
			deletedLName = classRosterArray[i]->GetLastName();

			delete this->classRosterArray[i];
			this->classRosterArray[i] = classRosterArray[NUM_STUDENTS - 1]; //Place last entry into 'i' 
	
			cout << "Removed student " << studentID << " (" << deletedFName << " " << deletedLName << ")." << endl;
			break;
		}
	}

	//Print error if student doesn't exist/has already been removed
	if (foundStudent == false) {
		cout << "Error: Student " << studentID << " not found." << endl;
	}
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Print list of all student data
void Roster::printAll() {
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		this->classRosterArray[i]->Print();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Print average time spent per course for given studentID
void Roster::printAverageDaysInCourse(string studentID) {
	int totalDays = 0;
	int *averageArray = nullptr; //Local array to store daysInCourse values

	for (int i = 0; i < NUM_STUDENTS; ++i) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			averageArray = classRosterArray[i]->GetDaysToComplete();
		}
	}

	//Sum of daysInCourse values
	for (int j = 0; j < NUM_COURSES; ++j) {
		totalDays = totalDays + averageArray[j];
	}
	
	cout << "Student " << studentID << "'s average # of days per course: " << (totalDays / NUM_COURSES) << endl;
}  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Verify email addresses and print all invalid emails
//Project validity rules: "A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')."
void Roster::printInvalidEmails() {
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		string testEmail = "";
		testEmail = classRosterArray[i]->GetEmail();

		//Test to find whitespace
		if (testEmail.find(' ') != string::npos) {
			cout << "Error: " << testEmail << " is an invalid address." << endl;
		}

		//Test to find presence of '@'
		if (testEmail.find('@') == string::npos) {
			cout << "Error: " << testEmail << " is an invalid address." << endl;
		}

		//Test to find presence of '.' AFTER '@'
		if (testEmail.find('@') != string::npos) {
			string emailDomain = testEmail.substr(testEmail.find('@'), testEmail.size() - testEmail.find('@'));
		
			if (emailDomain.find('.') == string::npos) {
				cout << "Error: " << testEmail << " is an invalid address." << endl;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Print student info by degree type
void Roster::printByDegreeProgram(Degree degreeType) {
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeType) {
			classRosterArray[i]->Print();
		}
		continue; //Print EACH element of array matching specified degreeType
	}
}


