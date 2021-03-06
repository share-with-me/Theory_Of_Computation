/*Assignment Q2 - Make a DFA for given regular expression (01+001+010)*  , implemented in C language
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

	/* 1,2,3,4,5,6 and 7 are valid states */
    	/*1 is the start state*/
    	/*1, 5 and 6 are final states*/
    	/*2,3,4 and 7 are non-final states*/
    	/*0 is a null state*/
	

	int states[8][2]; 
	states[0][0] = 0; 
    	states[0][1] = 0; 
    	states[1][0] = 2;
    	states[1][1] = 0;
    	states[2][0] = 3;
    	states[2][1] = 5;
    	states[3][0] = 0;
    	states[3][1] = 1;
    	//states[4][0] = 1;
    	//states[4][1] = 0;
    	states[5][0] = 6;
    	states[5][1] = 0;
    	states[6][0] = 7;
    	states[6][1] = 5;
    	states[7][0] = 3;
    	states[7][1] = 5;

	int present=1,final;
	
	int len = strlen(s);//len variable hold length of the string
	
	/*Print the first configuration without any transitions*/
	printf("Start state configuration: (q0, ");
	for(i=0;i<len;i++)
		printf("%c",s[i]);
	printf(")\n");

	if(s[len-1] == 'e')
	{
		printf("The given input string is in the final state. Hence it follows the grammar and DFA and should be accepted.\n");
		exit(0);
	}

	/*Printing configurations by reading character by character through iteration*/

	for(i=0;i<len-1;i++)
	{
		if(s[i]!='0' && s[i]!= '1')//Check for valid language
		{
			printf("Invalid string. Entering null state.  Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}
		if(s[i]=='0') c = 0;	//Equating char 'a' to int 0 in our 2D array states 
		if(s[i]=='1') c = 1;    //Equating char 'b' to int 1 in our 2D array states 

		printf("Next character %c taken, ", s[i]);
		printf("Current state configuration: (q%d, ", states[present][c]-1);
		for(j=i+1;j<len;j++)
			printf("%c",s[j]);	//Printing rest of the string
		
		printf(")\n");
		
		if(states[present][c] == 0)	//Implies output of transition is reaching null state
		{
			printf("Invalid string. Entering null state.  Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}
			
		/*Updating states here*/
		present = states[present][c];	//Updatinf the new present state
	}

		 
	/*Now for the last character of the input*/
		if(s[len-1]!='0' && s[len-1]!='1')
		{
			printf("Invalid string. Entering null state.  Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}

		if(s[len-1] == '0') c=0;
		if(s[len-1] == '1') c=1;
	
		printf("Next character %c taken, ", s[i]);
		printf("Current state configuration: (q%d, e)\n", states[present][c]-1);//e beacuse there are no further characters to be read

		if(states[present][c] == 0)	//Implies output of transition is reaching null state
		{
			printf("Invalid string. Entering null state. Exiting the program!\n");
			exit(0);//Exit the program if input is invalid
		}

	/*Now checking whether string is in final state where it is accepted or non-final state where it is rejected*/
	
		final = states[present][c];

		if(final ==1 || final == 5|| final ==6)
		{
			printf("The given input string is in the final state. Hence it follows the given regular expression and should be accepted.\n");
		}
		else if(final == 2 || final ==3 || final == 7)
		{
			printf("The given input string is not in the final state. Hence it does not follow the given regular expression and should be rejected.\n");
		}
}
