#include <iostream>

using namespace std;

enum enQsLevel
{
	Easy = 1,
	Medium = 2,
	Hard = 3,
	Mixed = 4
};
enum enQsOperation
{
	Add = 1,
	Subtract = 2,
	Divide = 3,
	Multiplication = 4
};
struct stGameInfo
{
	int NumberOfQs = 0;
	enQsLevel QsLevel = Easy;
	enQsOperation Op = Add;
	int RightAnswers = 0;
	int WrongAnswers = 0;
};
stGameInfo MyGameInfo;
void ShowLevels()
{
	cout << "Easy [ 1 ], Medium [ 2 ], Hard [ 3 ], Mixed [ 4 ]\n";
}
int ReadNumberInRange(string msg, int from, int to)
{
	int num;
	do
	{
		cout << msg;
		cin >> num;
	} while (num > to || num < from);
	return num;
}
int RandomNumberInRange(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

string PrintLevel(enQsLevel UserLevel)
{
	string levels[] = { "Easy", "Medium", "Hard" , "Mixed" };
	return levels[UserLevel - 1];
}
string PrintOperationName(enQsOperation UserOp)
{
	string operation[] = { "Add", "Subtract", "Divide" , "Multiplication" };
	return operation[UserOp - 1];
}
string OpSymbol(enQsOperation UserOp)
{
	string OpSympols[] = { " + ", " - ", " / " , " * " };
	return OpSympols[UserOp - 1];
}

int GenerateQsWithRange(enQsOperation Operation, int from, int to)
{
	int num1, num2;
	num1 = RandomNumberInRange(from, to);
	num2 = RandomNumberInRange(from, to);
	while (num2 == 0)num2 = RandomNumberInRange(from, to);
	cout << num1 << OpSymbol(Operation) << num2 << " = ";

	switch (Operation)
	{
	case Add:
		return num1 + num2;
	case Subtract:
		return num1 - num2;
	case Divide:
		return num1 / num2;
	case Multiplication:
		return num1 * num2;
	}

	// defualt 
	return RandomNumberInRange(from, to) + RandomNumberInRange(from, to);
}
int GenerateQuestion(enQsLevel level, enQsOperation Operation)
{
	switch (level)
	{
	case Easy:return GenerateQsWithRange(Operation, 1, 10);
	case Medium:return GenerateQsWithRange(Operation, 10, 50);
	case Hard:return GenerateQsWithRange(Operation, 50, 100);
	case Mixed:return GenerateQsWithRange(Operation, 1, 100);

	}
	// defualt 
	return GenerateQsWithRange(Operation, 1, 10);
}
int ReadNum()
{
	int num;
	cin >> num;
	return num;
}
void ShowFinalResults(stGameInfo Info)
{
	cout << "--------------------------------\n";
	cout << "Number Of Questions : " << Info.NumberOfQs << endl;
	cout << "Right Answers       : " << Info.RightAnswers << endl;
	cout << "Wrong Answers       : " << Info.WrongAnswers << endl;
	cout << "Operation Type      : " << PrintOperationName(Info.Op) << endl;
	cout << "Question Level      : " << PrintLevel(Info.QsLevel) << endl;
	cout << "Success Rate        : " << float(Info.RightAnswers / Info.NumberOfQs  * 100) << endl;
	cout << "--------------------------------\n";
}
bool CheckAnswer(int UserAnswer, int RealAnswer)
{
	return UserAnswer == RealAnswer;
}

bool ContinueOrNot()
{
	char MyChar;
	cout << "Do you want play again (Yes = y , No = n) : ";
	cin >> MyChar;
	return (MyChar == 'Y' || MyChar == 'y');
}
void ShowOperation()
{
	cout << "Add [1], Subtract [2], Divide [3], Multilication [4]\n";
}
void MathGame()
{
	int YourAnswer;
	MyGameInfo.WrongAnswers = 0;
	MyGameInfo.RightAnswers = 0;
	for (int i = 1; i <= MyGameInfo.NumberOfQs; i++)
	{
		cout << "Question [" << i << "/" << MyGameInfo.NumberOfQs << "]\n\n";
		int result = GenerateQuestion(MyGameInfo.QsLevel, MyGameInfo.Op);
		YourAnswer = ReadNum();

		if (CheckAnswer(YourAnswer, result))
		{
			cout << "Right Answer :-)" << endl;
			MyGameInfo.RightAnswers++;
		}
		else
		{
			cout << "Wrong Answer :-(" << endl;
			cout << "The Right Answer is :" << result << endl;
			MyGameInfo.WrongAnswers++;
		}
		cout << "---------------\n";
	}
}

int main()
{
	// the seed of the random generator
	srand((unsigned)time(NULL));
	do
	{
		cout << "\n\n\n\t\t\t\t";
		MyGameInfo.NumberOfQs = ReadNumberInRange("Enter the number of Qs you want ( 1: 10 ) : ", 1, 10); cout << endl;
		ShowLevels();
		MyGameInfo.QsLevel = (enQsLevel)ReadNumberInRange("Enter Qs Level : ", 1, 4); cout << endl;
		ShowOperation();
		MyGameInfo.Op = (enQsOperation)ReadNumberInRange("Enter Operation Type : ", 1, 4);

		MathGame();
		ShowFinalResults(MyGameInfo);
	} while (ContinueOrNot());

	return 0;
}
