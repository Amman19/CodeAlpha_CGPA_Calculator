#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numcourses;
	string name;
	char grade;
	int credithours;
	int totalcredithours = 0;
	float gradepoints = 0;
	float totalgradepoints = 0.0;
	float GPA;

	cout << "---------------------------------------------" << endl;
	cout << "     Grade to Grade Points Reference" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "  A: 4.0 points" << endl;
	cout << "  B: 3.0 points" << endl;
	cout << "  C: 2.5 points" << endl;
	cout << "  D: 2.0 points" << endl;
	cout << "  F: 0.0 points" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "How many courses in current semester ?" << endl;
	cin >> numcourses;
	cin.ignore();
	string *courses;
	char* grades;
	courses = new string[numcourses];
	grades = new char[numcourses];
	for (int i = 0; i < numcourses; i++)
	{
		cout << "Enter course name: ";
		getline(cin, name);
		courses[i] = name;
		cout << "Enter grade of course: ";
		cin >> grade;
		grades[i] = grade;
		cout << "Enter credit hours of course: ";
		cin >> credithours;
		if (grade == 'A')
		{
			gradepoints = 4.0 * static_cast<float>(credithours);
		}
		else if (grade == 'B')
		{
			gradepoints = 3.0 * static_cast<float>(credithours);
		}
		else if (grade == 'C')
		{
			gradepoints = 2.5 * static_cast<float>(credithours);
		}
		else if (grade == 'D')
		{
			gradepoints = 2.0 * static_cast<float>(credithours);
		}
		else if (grade == 'F')
		{
			gradepoints = 0.0 * static_cast<float>(credithours);
		}
		totalgradepoints = totalgradepoints + gradepoints;
		totalcredithours = totalcredithours + credithours;
		cin.ignore();
	}
	GPA = totalgradepoints / totalcredithours;
	cout << "\n--- Semester GPA Report ---\n";
	for (int i = 0; i < numcourses; i++)
	{
		cout << courses[i] << ": " << grades[i];
		cout << endl;
	}
	cout << "GPA: " << GPA << endl;

	//ask user the number of previously attended semesters and calculate gradepoints and credithours
	cout << endl;
	cout << endl;
	int numsemesters;
	float prevgpa;
	float prevch;
	float cumulativegradepoint = 0.0, cumulativecredithours = 0.0;
	cout << "How many semesters you have previously attended ?" << endl;
	cin >> numsemesters;
	for (int i = 0; i < numsemesters; i++)
	{
		cout << "Enter GPA of Semester " << i + 1 << ": ";
		cin >> prevgpa;
		cout << "Enter Total Credit Hours for Semester " << i + 1 << ": ";
		cin >> prevch;
		cumulativegradepoint = cumulativegradepoint + (prevgpa * prevch);
		cumulativecredithours = cumulativecredithours + prevch;
	}
	cumulativegradepoint = cumulativegradepoint + totalgradepoints;
	cumulativecredithours = cumulativecredithours + static_cast<float>(totalcredithours);
	float CGPA;
	CGPA = cumulativegradepoint / cumulativecredithours;
	cout << endl;
	cout << "===========================================" << endl;
	cout << "Final CGPA:         " << CGPA << endl;
	cout << "Total Credit Hours: " << cumulativecredithours << endl;
	cout << "===========================================";

	delete[] courses;
	delete[] grades;
	return 0;
}