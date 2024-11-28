// new_math_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct strquestion {
	int number1;
	int number2;
};
int number_question() {
	cout << "\n\nEnter number of questions : ";
	int value;
	cin >> value;
	return value;
}
int level_question() {
	int level;
	do {
		cout << "\nlevels ..........\n";
		cout << "\n[1] easy , [2] medium , [3] hard .\n ";
		cout << "\nEnter the level of difficulty : ";
		cin >> level;
	} while (level < 0||level >= 4);
	return level;
}
char type_operation() {
	
		cout << "\n\noperations .............\n";
		cout << "\nMult , Addition , Subtraction , Division";
		cout << "\n\nChoose the type of operation : ";
		char letter;
		cin >> letter;
		
	
	return letter;
}
strquestion prepare(int level ) {
	strquestion question;
	switch (level)
	{
	case 1:
		question.number1 = rand() % 10 + 1;
		question.number2 = rand() % 10 + 1;
		break;
	case 2:
		question.number1 = rand() % 100 + 1;
		question.number2 = rand() % 100 + 1;
		break;
	case 3:
		question.number1 = rand() % 1000;
		question.number2 = rand() % 1000;
		break;
	default:
		
		break;
	}
	return question;
}
int computer_answer(strquestion question,char operation) {
	switch (operation) {
	case '+':
		return question.number1 + question.number2;
		break;
	case '*':
		return question.number1 * question.number2;
		break;
	case '-':
		return question.number1 - question.number2;
		break;
	case '/':
		return question.number1 / question.number2;
		break;
	default:
		cout << "\nWorng input !!!!!!!\n";
	}
}
int user_input(strquestion question,char operation) {
	cout << question.number1 << "\n";
	cout << operation << endl;
	cout << question.number2 << endl;
	cout << "_____________________\n";
	int value;
	cin >> value;
	return value;
}
void start_our_game() {
	cout << "\n\t\t\t Hello , Our math game :) \n";
	int turns = number_question();
	char letter = type_operation();
	int level = level_question();
	strquestion question;
	while (turns--) {
		question = prepare(level);
		int user = user_input(question, letter);
		int computer = computer_answer(question, letter);
		if (computer == user) {
			cout << "\nGood Job , continue :) . \n\n";
		}
		else {
			cout << "\nWorng answer , try again :( . \n\n";
		}
	}

}
int main()
{
	srand((unsigned)time(NULL));
	start_our_game();
}

