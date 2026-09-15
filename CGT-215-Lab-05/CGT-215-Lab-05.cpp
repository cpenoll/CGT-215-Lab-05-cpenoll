// CGT-215-Lab-05.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector> //using vector header file (vectors store multiple elements of same data type); vector size is changeable, whereas arrays are not
#include <string>
using namespace std; //still necessary to allow use of shorthand cout and cin

//cypher vector code translation here with the name of the vector being CODE_TABLE
vector<char> CODE_TABLE = {
	'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E'
};

//the character translation function (I've named the function translateChar)
char translateChar(char c)
{
	if (c >= 65 && c <= 90) //is a capital letter (ASCII: A -> 65, Z -> 90)
	{return CODE_TABLE[c - 65]; } //if letter 'B' is input (where B=66), function will take 66-65 to = 1, then reference the code table and call 'F'

	else if (c >= 97 && c <= 122) //is a lowercase letter (ASCII: a -> 97, z -> 122)
	{
		int upperCaseLetter = c - 32; //converting the number to upper case number
		char upperCaseCode = CODE_TABLE[upperCaseLetter - 65]; //this is getting the uppercase code
		return upperCaseCode + 32; //this is converting the code back to lower case
	}
	else //if the character isn't a letter, return the same character (so if * is input, * is output/returned)
	{return c;}
}


int main() {
	string text; //stores what user inputs in this variable

	cout << "Input text to cypher: ";
	getline(cin, text); //reads the input line & stores it in text variable

string result = "";
for (int i = 0; i < text.length(); i++) //for loop
{
	result += translateChar(text[i]); //sending the line into my translateChar function to encode new line
}

cout << "Encoded Message: " << result << endl;

return 0;
}
