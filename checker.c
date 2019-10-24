#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "charStack.h"

bool isMatchedType(char s1, char s2){
	if (s1 == '(' && s2 == ')'){
		return true;
	}
	if (s1 == '[' && s2 == ']'){
		return true;
	}
	if (s1 == '{' && s2 == '}'){
		return true;
	}
	
	return false;
}

bool isBalancedBracket(char str[]){
	// loop through the string. If you encounter (, [, or { then push it on the stack
	// if you encounter ), ], } then pop a bracket off the stack
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			push(str[i]);
		} 
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (isEmpty())
			{
				return false;					
			}
			
			if (!isMatchedType(pop(), str[i]))
			{
				return false;
			}
		}
	}
	
	if (isEmpty()){
		return true;
	} else {
		return false;
	}
	
}

int main(int argc, char** argv)
{
	char str[MAXSTACK];
	printf("Please enter a string: ");
	scanf("%s", str);
	
	printf("\nYou typed : %s\n\n", str);
	
	// initialize stack
	initStack();
	
	if (isBalancedBracket(str))
	{
		printf("Brackets are correct!");
	} else {
		printf("Brackets are not correct!");
	}
	
}
