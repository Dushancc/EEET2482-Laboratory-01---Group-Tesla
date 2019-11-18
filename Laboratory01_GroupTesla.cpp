// Laboratory01_GroupTesla.cpp 
//Group Tesla  : Dushan Chanuka s3775906
//				 Janani Kahahena s3634652
//				 Thisakya Ransarani s3697331

//2 Argument Calculator

//maximum length of the single line input
#define max_input_length 75

#include <iostream>
using namespace std;

//function to check whether the given number is a valid integer
bool isValidInteger(char* inpInt) {

	char* temp = inpInt;	//temporary pointer to the input digit 
	bool decPointFlag = 0;  //variable to keep track of the location of the decimal point
	bool negativeFlag = 0; //Flag to check whether the number is negative

	//Setting the negativeFlag flag if the first character of the array is a negative sign
	if (*temp == '-') {
		temp++;
		negativeFlag = 1;
	}

	while ((*temp) != '\0')
	{
		//Return false when there are multiple negative signs after the initial one at the beginning
		if (*temp == '-' && negativeFlag == 1) {
			return false;
		}

		//Returning false when there are multiple decimal points 
		if (*temp == '.' && decPointFlag == 1) {
			return false;
		}

		//Setting the decimal point flag
		if (*temp == '.' && decPointFlag == 0) {
			decPointFlag= 1;
			temp++;
		}

		//checking whether the value contain non numerical values 
		if (*temp < '0' || *temp > '9')
		{
			return false;
		}

		//returning false if there are non zero digits after the decimal place
		if (*temp != '0' && decPointFlag == 1) {
			return false;
		}	

		temp++;
	}

	//returning true if none of the error checks triggers
	return true;

}

//function to check whether an array is empty
bool isEmpty(char* x)
{
	char* value = x;
	uint8_t count = 0;

	for (int i = 0; i < max_input_length; i++) {
		if (*value != '\0') {
			count++;
		}
		value++;
	}
	if (count > 0) {
		return false;
	}
	return true;
}


int main(int argc, char* argv[])
{
	//Declaring variables for keeping the two integer values
	__int64 number1 = 0;
	__int64 number2 = 0;

	//Program status flag to exit the program whe user type 'Exit'
	bool exitFlag = 1;

	while (exitFlag) 
	{
		//character array for the single line input
		char input[max_input_length + 2] = { NULL };


		//character arrays for user inputs
		char arguments[3][max_input_length] = { NULL };
		
		//Obtaining the user input
		cin.getline(input,max_input_length);

		//seperating the three inputs
		uint8_t count = 0;
		uint8_t position = 0;

		for (int i = 0; i < max_input_length;i++)
		{
			if (input[i] == 32) {
				position = 0;
				count++; i++;
				if (count >= 3) {
					position = i;
					break;
				}
			}
			arguments[count][position] = input[i];
			position++;
		}

		//checking for empty inputs
		if (isEmpty(input)) {
			cout << "Enter input arguments" << endl;
			continue;
		}



	}

	/*

	//Terminating the program on EXIT command 
	if (argv[1][0] == 'E' && argv[1][1] == 'x' && argv[1][2] == 'i' && argv[1][3] == 't')
	{
		return 0;
	}
	//performing checks for invalid inputs

	//Check 01 : Checking whether user has entered valid no of arguments (dummy variables)
	if (argc != 4) {
		cout << "Invalid no of user inputs" << endl;
		return 1;
	}

	//Check 02 : Checking whether the length of the operator is valid
	if (argv[2][1] != '\0')
	{
		cout << "Invalid operator length" << endl;
		return 1;
	}

	//Check 03 : Checking whether user has entered a valid operator
	if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '%')
	{
		cout << "Invalid Operator" << endl;
		return 1;
	}

	//Performing checks on the integer inputs
	if (!isValidInteger(argv[1]) && !isValidInteger(argv[3]))
	{
		cout << "Invalid integer inputs" << endl;
		return false;
	}

	//converting the two character arrays to integer values
	number1 = atoi(argv[1]);
	number2 = atoi(argv[3]);

	//Checking whether the numbers are within the range
	if ((number1 > 32767 || number1 < -32768) && (number2 > 32767 || number2 < -32768))
	{
		cout << "Inputs are out of allowed range";
		return 0;
	}


	switch ()
	{
	case '+':
		cout << number1 + number2 << endl;
		break;
	case '-':
		cout << number1 - number2 << endl;
		break;
	case '*':
		cout << number1 * number2 << endl;
		break;
	case '/':
		if (number2 != 0)
		{
			cout << number1 + number2 << endl;
		}
		else {
			cout << "Division by Zero is not allowed" << endl;
		}
		break;
	case '%':
		cout << number1 % number2 << endl;
		break;
	}*/

	return 0;
}

