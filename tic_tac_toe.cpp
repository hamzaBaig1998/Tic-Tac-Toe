#include<iostream>
#include<string>
using namespace std;

int computer()
{
	int val=rand()%9+1;
	return val;
}
int winner(char a[10])
{
	if (a[1] == a[4] && a[1] == a[7])
	{
		//cout << "Winner" << endl;
		return 1;
	}
	else if (a[1] == a[2] && a[1] == a[3])
	{
		//cout << "Winner" << endl;
		return 1;
	}
	else if (a[2] == a[5] && a[2] == a[8])
	{
		//cout << "Winner" << endl;
		return 1;
	}
	else if (a[3] == a[6] && a[3] == a[9])
	{
		//cout << "Winner" << endl;
		return 1;
	}
	else if (a[4] == a[5] && a[4] == a[6])
	{
		//cout << "Winner" << endl;
		return 1;
	}
	else if (a[7] == a[8] && a[7] == a[9])
	{
		//cout << "Winner" << endl;
		return 1;
	}
	else if (a[1] == a[5] && a[1] == a[9])
	{
		//cout << "Winner" << endl;
		return 1;
	}
	else if (a[3] == a[5] && a[3] == a[7])
	{
		return 1;
	}
	return 0;
}
void clrscr()
{
	system("cls");
}
int nextPlayer(int prev)
{
	if (prev == 1)
	{
		return 2;
	}
	else if (prev == 2)
	{
		return 1;
	}
}
int empty(char a)
{
	if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9')
	{
		return 1;
	}
	return 0;
}
int full(char a[10])
{
	if (a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9')
	{
		return 1;
	}
	return 0;
}
void main()
{
	int loop = 0;
	char player1 = 'X';
	char player2 = 'O';
	int score = 0;
	int player = 2;
	int choice;
	//char a1='1',a2='2',a3='3',a4='4',a5='5',a6='6',a7='7',a8='8',a9='9';
	char a[10] = { '0','1','2','3','4','5','6','7','8','9' };

	while (loop == 0)
	{
		//system("CLS");
		clrscr();
		cout << "The computer is not so smart!!" << endl;
		cout << "Tic Tac Toe" << endl;
		cout << "Player 1 will be X" << endl;
		cout << "Player 2 will be O" << endl;
		cout << "          -------------------" << endl;
		cout << "          |     |     |     |" << endl;
		cout << "          |  " << a[1] << "  |  " << a[2] << "  | " << a[3] << "   |" << endl;
		cout << "          |-----|-----|-----|" << endl;
		cout << "          |     |     |     |" << endl;
		cout << "          |  " << a[4] << "  |  " << a[5] << "  | " << a[6] << "   |" << endl;
		cout << "          |-----|-----|-----|" << endl;
		cout << "          |     |     |     |" << endl;
		cout << "          |  " << a[7] << "  |  " << a[8] << "  | " << a[9] << "   |" << endl;
		cout << "          -------------------" << endl;

		player = nextPlayer(player);
	ReturnHere:
		if (player == 1)
		{
			cout << "Player " << player << ": where to insert? insert at: "; cin >> choice;
			for (int i = 1; i < 10; i++)
			{
				if (choice == i)
				{
					if (empty(a[i]) == 0)
					{
						if (player == 1)
						{
							cout << "Already contains a value" << endl;
						}
						goto ReturnHere;
					}
					if (player == 1)
					{
						a[i] = 'X'; break;
					}
					if (player == 2)
					{
					gethere:
						a[i] = 'O'; break;
					}
				}
			}
			if (winner(a) == 1)
			{
				loop = 1;
			}
		}


		//computer
		if (player == 2)
		{
			ReturnHere2:
			//cout << "Player " << player << ": where to insert? insert at: "; cin >> choice;
			choice = computer();
			for (int i = 1; i < 10; i++)
			{
				if (choice == i)
				{
					if (empty(a[i]) == 0)
					{
						if (player == 1)
						{
							cout << "Already contains a value" << endl;
						}
						goto ReturnHere2;
					}
					if (player == 1)
					{
						a[i] = 'X'; break;
					}
					if (player == 2)
					{
					
						a[i] = 'O'; break;
					}
				}
			}
			if (winner(a) == 1)
			{
				loop = 1;
			}
		}




		if (full(a) == 1)
		{
			loop = 2;
		}
	}
	if (loop == 1)
	{
		cout << "          -------------------" << endl;
		cout << "          |     |     |     |" << endl;
		cout << "          |  " << a[1] << "  |  " << a[2] << "  | " << a[3] << "   |" << endl;
		cout << "          |-----|-----|-----|" << endl;
		cout << "          |     |     |     |" << endl;
		cout << "          |  " << a[4] << "  |  " << a[5] << "  | " << a[6] << "   |" << endl;
		cout << "          |-----|-----|-----|" << endl;
		cout << "          |     |     |     |" << endl;
		cout << "          |  " << a[7] << "  |  " << a[8] << "  | " << a[9] << "   |" << endl;
		cout << "          ------------------" << endl;
		if (player == 2)
		{
			cout << "Computer Wins" << endl;
		}
		else
		{
			cout << "Player: " << player << " Winner!! " << endl;
		}
	}
	if (loop == 2)
	{
		cout << "Draw" << endl;
	}
	system("pause");
}