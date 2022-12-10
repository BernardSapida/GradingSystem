#include <iostream>
#include <string>
using namespace std;

int grades[50][5];
int index = -1;

void displayTable() {
	cout << "\n==========================================\n\n";
	if(index == -1) {
		cout << "Table is empty!";
	}
	else {
		cout << "\tID\tAD\tHOA\tQ\tME\n";
		cout << "HPS\t#\t60\t60\t30\t50\n";
		

		for (int i = 0; i <= index; i++) {
			cout << "TRS";
			cout << "\t" << grades[i][0];
			cout << "\t" << grades[i][1];
			cout << "\t" << grades[i][2];
			cout << "\t" << grades[i][3];
			cout << "\t" << grades[i][4] << endl;
		}
	}
	cout << "\n\n==========================================\n\n";
}

void addStudentGrade() {
	int AD, HOA, Q, ME;

	cout << "\n==========================================\n\n";

	index++;

	cout << "Assignment/Discussion: ";
	cin >> AD;
	cout << "Hands-On-Activity: ";
	cin >> HOA;
	cout << "Quizzes: ";
	cin >> Q;
	cout << "Major Exams: ";
	cin >> ME;

	grades[index][0] = index+1;
	grades[index][1] = AD;
	grades[index][2] = HOA;
	grades[index][3] = Q;
	grades[index][4] = ME;
	cout << "Grade was successfully added!";
	cout << "\n\n==========================================\n\n";
	
}

void modifyStudentGrade() {
	int id, grade;
	string column;

	cout << "\n==========================================\n\n";


	if (index == -1) {
		cout << "Modify operation couldn't perform! Table was empty.";
	}
	else {
		displayTable();
		cout << "Enter ID to modify: ";
		cin >> id;

		while (true) {
			cout << "Enter column to modify (AD/HOA/Q/ME): ";
			cin >> column;
			if (column == "AD" || column == "HOA" || column == "Q" || column == "ME") break;
			cout << "Invalid input! Please try again.\n";
		}

		cout << "Enter grade: ";
		cin >> grade;

		if (column == "AD") grades[id - 1][1] = grade;
		if (column == "HOA") grades[id - 1][2] = grade;
		if (column == "Q") grades[id - 1][3] = grade;
		if (column == "ME") grades[id - 1][4] = grade;

		cout << "Grade was successfuly updated!";
		cout << "\n\n==========================================\n\n";
	}
}

void deleteStudentGrade() {
	int id;

	cout << "\n==========================================\n\n";

	if (index == -1) {
		cout << "Delete operation couldn't perform! Table was empty.";
	}
	else {
		displayTable();

		cout << "\nEnter row id to delete: ";
		cin >> id;

		for (int i = 0; i <= index; i++) {
			if (id >= i) {
				grades[i][0] = grades[i + 1][0] - 1;
				grades[i][1] = grades[i + 1][1];
				grades[i][2] = grades[i + 1][2];
				grades[i][3] = grades[i + 1][3];
				grades[i][4] = grades[i + 1][4];
			}
		}

		index--;

		cout << "Row " << id << " was successfully deleted!";
		cout << "\n\n==========================================\n\n";
	}
}

void displayFinalGrade() {
	int id;

	cout << "\n==========================================\n\n";

	if (index == -1) {
		cout << "Display final grade operation couldn't perform! Table was empty.";
	}
	else {
		displayTable();

		cout << "\nEnter row id: ";
		cin >> id;

		for (int i = 0; i <= index; i++) {
			if(id-1 == i) {
				double AD = (double) grades[i][1] / 60 * 0.15 * 100;
				double HOA = (double) grades[i][2] / 60 * 0.15 * 100;
				double Q = (double) grades[i][3] / 30 * 0.2 * 100;
				double ME = (double) grades[i][4] / 50 * 0.5 * 100;
				double FINAL = AD + HOA + Q + ME;

				cout << "\nAD_GRADE = " << AD << endl;
				cout << "HOA_GRADE = " << HOA << endl;
				cout << "Q_GRADE = " << Q << endl;
				cout << "ME_GRADE = " << ME << endl;
				cout << "FINAL GRADE = " << round(FINAL) << endl;
			}
		}
	}
	cout << "\n\n==========================================\n\n";
}

void displayTerminal() {
	string choice;

	cout << "Options:\n";
	cout << "[1] Display Table\n";
	cout << "[2] Add Student Grade\n";
	cout << "[3] Modify Student Grade\n";
	cout << "[4] Delete Student Grade\n";
	cout << "[5] Compute Final Grade\n";
	cout << "Choice: ";
	cin >> choice;

	if (choice == "1") displayTable();
	else if (choice == "2") addStudentGrade();
	else if (choice == "3") modifyStudentGrade();
	else if (choice == "4") deleteStudentGrade();
	else if (choice == "5") displayFinalGrade();
	else cout << "\nInput is invalid! Please try again.\n";
}

int main() {
	while(true) displayTerminal();
	return 0;
}
