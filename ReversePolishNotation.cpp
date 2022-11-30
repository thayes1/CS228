//Reverse Polish Notation.cpp
//Tyler Hayes
//Prof. Vanecek 
//11.29.22

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

//Declaring the stack and infix using arrays 
#define SIZE 40		//Defined SIZE to 40
char infix[SIZE];	//Infix array holds up to 40 characters
char stack[50];		//Stack can hold up to 50 characters
int top = -1;		//Stack is empty to begin with so top is pointing to -1


//Checks if stack is empty
bool isEmpty(int top)
{
	if (top == -1)		//-1 is the place top points to indicate the stack is empty
		return true;
	else
		return false;
}

//Checks if stack is full
bool isFull(int top)
{
	if (top == 49)		//49 is the very top of the stack
		return true;
	else
		return false;
}

//Pushes values onto the stack
void push(int value, char stack[], int& top)
{
	if (isFull(top))
		cout << "Stack is full!" << endl; //If the stack is full cout this message to avoid stack overflow
	else
	{
		top++;				//Increment the top of the stack by 1
		stack[top] = value;	//Pushes value to the top of the stack
	}
}

//Pops characters off the stack
char pop(char stack[], int& top)
{
	char x;
	if (top != NULL)
	{
		x = stack[top];	//x holds the character that is on the top of the stack
		top--;			//Decrement the top value by 1 essentially removing/popping the value
		return x;		//return x back to the main code
	}
	else
	{
		return 0;
	}

}

//Displays the contents of the stack
void displayStack(char stack[], int top)
{
	for (int i = 0; i <= top; i++)		//Starts at the bottom of the stack at '0' and iterates until it gets to the 'top' of the stack
		cout << stack[i] << " ";		//Prints out the contents of the stack
		cout << "\n";
}

//Gets priority of operators
int getPriority(char value)
{
	if (value == '$')			//$ is the dummy character pushed onto the stack in the beggining. The latter code will always take precedence over this dummy character.
		return 0;

	if (value == '(')			
		return 1;

	if (value == '+' || value == '-')
		return 2;

	if (value == '/' || value == '*')
		return 3;

	if (value == '^')
		return 4;
}

//Returns the top of the stack
char displayTop(char stack[], int top)
{
	char x;				
	x = stack[top];		//x = the top of the stack
	return x;			//Return the top of the stack back to the main code
}

int main()
{
	//Declerations
	int arrLength;
	string output = "";
	char unit, x, y;
	int i, priorityU, priorityS;

	//RPN Screen
	cout << "Reverse Polish Notation Calculator" << endl;
	cout << "----------------------------------" << endl;

	//Placing a 'dummy' operator on the stack
	push('$', stack, top);

	//Get user input & get length of input
	cout << "Enter Math Equation: ";
	cin.getline(infix, SIZE);
	arrLength = strlen(infix);


	//For loop iterates through the input string until it is finished
	for (i = 0; i < arrLength; i++)
	{
		//The current charcter is called unit
		unit = infix[i];

		//Check if unit is a variable
		if (isalnum(unit))
		{ 
			//Add the variable to the output
			output = output + unit;

			//Increment to get the next unit
			unit = infix[i + 1];
			i = i + 1;
		}

		//Check if unit is a closing parenthesis
		if (unit == ')')
		{
			//If it is a closing parenthesis pop it off the stack
			x = pop(stack, top);

			//While the characters inside the parenthesis are not a opening parenthesis...
			while (x != '(')
			{
				//Add the character to the output
				output = output + x;
				
				//Pop character off the stack and store it in x
				x = pop(stack, top);
			}
		}

		else
		{
			//Call functions to get precedence of the unit and the stack
			priorityU = getPriority(unit);
			priorityS = getPriority(stack[top]);

			//While unit precedence is <= stack precedence and unit is not a opening parenthesis 
			while (priorityU <= priorityS && unit != '(')
			{
				//Pop character off stack
				x = pop(stack, top);

				//Add chacter to output stream
				output = output + x;
				
				//Get the precedence of the stack
				priorityS = getPriority(stack[top]);
			}
			//Push unit onto the stack
			push(unit, stack, top);
		}

	}

	//If the top is not empty then pop characters until it is
	if (top != -1)
	{
		//Pop character and add it to output stream
		x = pop(stack, top);
		output = output + x;
	}

	//Print out the answer
	cout << "Equation in RPN -> " << output << endl;

}
