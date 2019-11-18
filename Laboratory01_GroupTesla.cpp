// Laboratory01_GroupTesla.cpp 
//Group Tesla  : Dushan Chanuka s3775906
//				 Janani Kahahena s3634652
//				 Thisakya Ransarani s3697331

//2 Argument Calculator

#include <iostream>
using namespace std;

bool isValidInteger(char* inpInt) {

	char* temp = inpInt;	//temporary pointer to the input digit 
	int decPointLocation = -1;  //variable to keep track of the location of the decimal point
	unsigned int index = 0; //variable to keep the index of the charcter array
	bool intAfterDecPoint = 0; //flag to check whether there are non-zero values after decimal point
	bool negativeFlag = 0; //Flag to check whether the number is negative

	//Setting the negativeFlag flag if the first character of the array is a negative sign
	if (*temp == '-') {
		temp++;
		index++;
		negativeFlag = 1;
	}

	while ((*temp) != '\0')
	{
		//Return false when there are multiple negative signs after the initial one at the beginning
		if (*temp == '-' && negativeFlag == 1) {
			return false;
		}

		//Returning false when there are multiple decimal points 
		if (*temp == '.' && decPointLocation != -1) {
			return false;
		}

		//Setting the decimal point location 
		if (*temp == '.' && decPointLocation == -1) {
			decPointLocation = index;
			temp++;
		}

		//checking whether the value contain non numerical values 
		if (*temp < '0' || *temp > '9')
		{
			return false;
		}

		//returning false if there are non zero digits after the decimal place
		if (*temp != '0' && decPointLocation != -1) {
			return false;
		}

		




	}



}

int main(int argc, char* argv[])
{

	//Terminating the program on EXIT command 
	if (argv[1][0] == 'E' && argv[1][1] == 'x' && argv[1][2] == 'i' && argv[1][3] == 't')
	{
		return 0;
	}
	//performing checks for invalid inputs

	//Check 01 : Checking whether user has entered valid no of arguments
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
	if (argv[2][0] != 37 && argv[2][0] != 42 && argv[2][0] != 43 && argv[2][0] != 45 && argv[2][0] != 47)
	{
		cout << "Invalid Operator" << endl;
		return 1;
	}

	//Performing checks on the integer inputs
	
}

