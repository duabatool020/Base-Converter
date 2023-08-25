#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

};

class BaseConverter
{
private:
	Node* head;
public:
	BaseConverter()
	{
		head = NULL;
	}
	void insertInteger(int value)
	{
		Node* temp;
		if (head == NULL)
		{
			temp = new Node;
			temp->data = value;
			temp->next = NULL;
			head = temp;
		}
		else
		{
			temp = new Node;
			temp->data = value;
			temp -> next = head;
			head = temp;

		}
	}
	
	void generateRandomNo()
	{
		char ch;
		ofstream myfile;
		int num;
		myfile.open("file.txt");
		if (!myfile)
		{
			cout << "File not found" << endl;
			exit(0);
		}

			for (int i = 0;i < 6;i++)
			{
				myfile << rand() % 9;
			}
		
		myfile.close();
	}

	void getInput()
	{
		char ch;
		int base, num;
		string temp = "";
		ifstream file;
		file.open("file.txt");
		if (!file)
		{
			cout << "File not found" << endl;
			exit(0);
		}
		while (!file.eof())
		{
			file.get(ch);
			temp = temp + ch;
		}
		file.close();
		num = stoi(temp);
		cout << "Number is: " << num << endl;
		cout << "Enter the base to convert: ";
		cin >> base;
		if (base == 16)
		{
			HexConverter(num, base);
		}
		else
		{
			converter(num, base);
		}

	}

	void HexConverter(int num, int base)
	{
		string temp = "";
		int remainder, quotient;
		while (base <= num)
		{
			remainder = num % base;

			switch (remainder)
			{
			case 10:
				temp = temp + 'A';
				break;
			case 11:
				temp = temp + 'B';
				break;
			case 12:
				temp = temp + 'C';
				break;
			case 13:
				temp = temp + 'D';
				break;
			case 14:
				temp = temp + 'E';
				break;
			case 15:
				temp = temp + 'F';
				break;
			default:
				temp = temp+to_string(remainder);
				break;
			}
			quotient = num / base;
			num = quotient;
			if (num < base)
			{
				temp=temp+to_string(num);
			}
		}
		cout << "Number in base 16" << " is: ";
		for(int i=temp.length();i>=0;i--)
		{
			cout << temp[i];
		}
	}

	void converter(int num, int base)
	{
		int remainder, quotient;
		while (base<=num)
		{
			remainder = num % base;
			insertInteger(remainder);
			quotient = num / base;
			num = quotient;
			if (num < base)
			{
				insertInteger(num);
			}
		}
		display(base);

	}

	void display(int base)
	{
		cout << "Number in base "<<base<<" is: ";
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;
		}
	}

	
};

int main()
{
	BaseConverter b;
	b.generateRandomNo();
	b.getInput();
	return 0;

}
