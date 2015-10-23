/*Assignment Q1 - Make a finite state automaton, implemented in C language
Subject - Theory Of Computation
Course No - CS F351
*/

/*By-
	Name - Monish P. Godhia
	ID No- 2013A7PS145H
*/


/*Importing required libraries*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void make_automaton(char*); /*function prototype*/


/*main function starts here*/
int main()
{
	char s[200];
	printf("Please input the string to be read:\nIf string is null, enter $\n");
	scanf("%s",s);
	make_automaton(s);
	return 0;
}
/*main function ends here*/

/*function definition*/
void make_automaton(char* s)
{

	int i,j;//variables
	int c;
	
	/*Making use of a 2D array states[m][a]: where m represents current state and a is the input char to be read
	states[i][j] = n implies transition from state i to state n on reading input j*/

	/*If the transition output is 0 (ie n=0 for some i,j) it implies the string has reached null state*/

	/*Description of states in the following code:
		0-null,
		1-q0,
		2-q1,
		3-q2,
		4-q3,
		5-q4,
		6-q5
		7-q6*/
	/*1 is the start state, 7 is the final state*/
	/*States 1,2,3,4,5,6,7 are valid states and state 0 is the null state*/
	/*States 1,2,3,4,5,6 are non-final states*/
	

	int states[8][2]; 
	states[0][0] = 0;
	states[0][1] = 0;
	states[1][0] = 1;
    	states[1][1] = 4;
    	states[2][0] = 3;
    	states[2][1] = 6;
    	states[3][0] = 4;
    	states[3][1] = 5;
    	states[4][0] = 1;
    	states[4][1] = 6;
    	states[5][0] = 1;
    	states[5][1] = 7;
    	states[6][0] = 2;
    	states[6][1] = 5;
    	states[7][0] = 2;
    	states[7][1] = 4;

	int present=1,final;
	
	int len = strlen(s);//len variable hold length of the string
	
	/*Print the first configuration without any transitions*/
	printf("Start state configuration: (q0, ");
	for(i=0;i<len;i++)
		printf("%c",s[i]);
	printf(")\n");
	
	if(s[len-1] == 'e')
	{
		printf("The given input string is not in the final state. Hence it should be rejected.\n");
		exit(0);
	}

	/*Printing configurations by reading character by character through iteration*/

	for(i=0;i<len-1;i++)
	{
		if(s[i]!='a' && s[i]!= 'b')//Check for valid language
		{
			printf("Invalid string. Entering null state. Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}
		if(s[i]=='a') c = 0;	//Equating char 'a' to int 0 in our 2D array states 
		if(s[i]=='b') c = 1;    //Equating char 'b' to int 1 in our 2D array states 

		printf("Next character %c taken, ",s[i]);
		printf("Current state configuration: (q%d, ", states[present][c]-1);
		for(j=i+1;j<len;j++)
			printf("%c",s[j]);	//Printing rest of the string
		
		printf(")\n");
		
		if(states[present][c] == 0)	//Implies output of transition is reaching null state
		{
			printf("Invalid string. Entering null state. Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}
			
		/*Updating states here*/
		present = states[present][c];	//Updating the new present state
	}

		 
	/*Now for the last character of the input*/
		if(s[len-1]!='a' && s[len-1]!='b')
		{
			printf("Invalid string. Entering null state. Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}

		if(s[len-1] == 'a') c=0;
		if(s[len-1] == 'b') c=1;
	
		printf("Next character %c taken, ",s[i]);
		printf("Current state configuration: (q%d, e)\n", states[present][c]-1);//e beacuse there are no further characters to be read

		if(states[present][c] == 0)	//Implies output of transition is reaching null state
		{
			printf("Invalid string. Entering null state. Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}

	/*Now checking whether string is in final state where it is accepted or non-final state where it is rejected*/
	
		final = states[present][c];
		
		if(final==7)	//Since state 7 is the final state
		{
			printf("The given input string is in the final state. Hence it follows the given DFA and should be accepted.\n");
		}
		else
		{
			printf("The given input string is not in the final state. Hence it does not follow the given DFA and should be rejected.\n");
		}

}
			
