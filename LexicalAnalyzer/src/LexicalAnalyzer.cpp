/**
 * @file LexicalAnalyzer.cpp
 * @brief This file contains the implementation of a lexical analyzer for PL/0.
 * 
 * @details
 * The lexical analyzer reads the source code character by character, groups characters into tokens, and assigns a type to each token.
 * It handles different types of tokens such as keywords, identifiers, numbers, and operators. It also manages errors for unrecognized characters
 * and handles special cases like comments and whitespace.
 * 
 * The main functions in this file are:
 * void scaner(): This function performs the lexical analysis by reading characters from the source code, grouping them into tokens, and assigning types.
 * void read(): This function reads the entire source code from a file into a buffer.
 * int main(): The main function that drives the lexical analysis process, reads the source code, calls the scanner, and outputs the results.
 *
 * The results of the lexical analysis are written to an output file specified by the `RESULT` macro.
 * 
 * No need and no ability to deal with mistakes! 
 *
 * @author CheeseSilly
 * @date 2024-10-16
 */
#include "../include/util.h"
void array_check(char ch){
	if (ch =='(') {
		//check whether it is a number index or else
		int i=0;
		strcpy(token, arr_value);
        m = arr_num;
        token[m++] = ch;
        ch = prog[p++];
		//eg. a[1:2]...
		if((ch >= '0'&&ch <= '9')){
			while (ch != ')' && ch != '\0') {
            token[m++] = ch;
            ch = prog[p++];
			if(ch==' '){
				ch=prog[p++];
			}
        }
		i=0;
		}else{ //eg. a[b[1:2]]...
			while (ch != ')' && ch != '\0') {
            token[m++] = ch;
            ch = prog[p++];
			if(ch==' '){
				ch=prog[p++];
			}
		}
		i=1;
		}
        token[m++] = ch; 
		// add')' for '}' in string's case
		if(i==1){
			token[m++]=')';
			p++;
		}
        token[m] = '\0';
        syn = 30;
		arr_flag = 0;
		arr_num = 0;
    }
}

void scaner()
{
	
    //initialize the token array
	for (n = 0; n<10; n++) 
		token[n] = '\0';
	ch = prog[p++];

	//skip the space
	// while (ch == ' ')
	// {
	// 	ch = prog[p];
	// 	p++;
	// }

	//skip the comment and space
    while (ch == ' ' || ch == '{')
    {
        if (ch == '{') {
            //skip the comment
            while (ch != '}' && ch != '\0') {
				if(prog[p]=='}'&&((prog[p+1]>='a'&&prog[p+1]<='z')||(prog[p+1]>='A'&&prog[p+1]<='Z'))){
					ch=prog[p++];
				}
                ch = prog[p++];
            }
            ch = prog[p++];
        } else {
            ch = prog[p++];
        }
    }

	//scan the token
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))  
	{
		//Initialize m to 0,which is used to track the index of the token array
		m = 0;
		while ((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		{
			token[m++] = ch;
			ch = prog[p++];
		}
		auto tp_ch=ch;
		//end the token array
		if(ch!='('){
			token[m++] = '\0';
			p--;
			syn=10;
		}else{
		strcpy(arr_value, token);
		arr_num=m;
		if(arr_flag){
		array_check(tp_ch);
		arr_flag=0;
		}
		}
		

        //check if the token is a reserved word,all reserved words are lowercase
		for (n = 0; n<7; n++)  
			if (token==rwtab1[n])
			{
				syn = n + 1;
				break;
			}
		for (n = 0; n < 4;n++)
		{
			if (token==rwtab2[n])
			{	
				if(n==1)
				{
					arr_flag=1;
				}
				syn = n + 31;
				break;
			}
		}
	}
	

	else if ((ch >= '0'&&ch <= '9'))  //store the number with the sum
	{
		sum = 0;
		while ((ch >= '0'&&ch <= '9'))
		{
            //only support the integer
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		p--;
		syn = 11;
		//max=32767
		if (sum>32767)
			syn = -1;
	}
	//check the operator and delimiter
	else switch (ch)   
	{
	case '<':
		m = 0; 
		token[m++] = ch;
		ch = prog[p++];
		if (ch == '>')
		{
			//for <>
			syn = 21;
			token[m++] = ch;
		}
		else if (ch == '=')
		{
			//for <=
			syn = 22;
			token[m++] = ch;
		}
		else
		{
			//for <
			syn = 23;
			//back to the front of <
			p--;
		}
		break;
	case '>':
		m = 0; 
		token[m++] = ch;
		ch = prog[p++];
		if (ch == '=')
		{
			syn = 24;
			token[m++] = ch;
		}
		else
		{
			syn = 20;
			p--;
		}
		break;
	case ':':
		m = 0; 
		token[m++] = ch;
		ch = prog[p++];
		if (ch == '=')
		{
			//:=
			syn = 18;
			token[m++] = ch;
		}
		else
		{
			//:
			syn = 17;
			p--;
		}
		break;
	case '*':
		syn = 13; 
		token[0] = ch; 
		break;
	case '/':
		syn = 14; 
		token[0] = ch; 
		break;
	case '+':
		syn = 15; 
		token[0] = ch; 
		break;
	case '-':
		syn = 16; 
		token[0] = ch; 
		break;
	case '=':
		syn = 25; 
		token[0] = ch; 
		break;
	case ';':
		syn = 26; 
		token[0] = ch; 
		break;
	case '(':
		syn = 27; 
		token[0] = ch; 
		break;
	case ')':
		syn = 28; 
		token[0] = ch; 
		break;
	case ',':
		syn = 29;
		token[0] = ch;
		break;
	case '!':
		syn = 30;
		token[0] = ch;
		break;
	case '.':
		//end.
		syn = 0;
		token[0] = ch; 
		break;
	case '\n':
		//change the line,line++
		syn = -2; 
		break;
	default: 
		//undefined character,return error
		syn = -1; 
		break;
	}
}

void read()
{
	FILE *fp;
	fp = fopen(CODE, "r");
	//get the size of the file
	fseek(fp, 0, SEEK_END);
	int file_size;
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	prog = new char[file_size*sizeof(char)];	
	//read the file
	fread(prog, file_size, sizeof(char), fp);
	fclose(fp);
}

int main()
{
	int p = 0;
	int line = 1;
	std::ofstream outfile(RESULT);
	read();
	p = 0;
	do
	{
		scaner();
		switch (syn)
		{
		//output number
		case 11: 
			outfile << "(" << syn << "," << sum << ")" << std::endl;
			break;
		//output error
		case -1: 
			outfile << "Error in line" << line << "!" << std::endl;
			break;
		//handle the line change
		case -2: 
			line = line++; 
			break;
		case 30:
            outfile << "Array definition:("<< syn <<"," << token<<")" << std::endl;
            break;
		//output the reserved word
		default: 
			outfile << "(" << syn << "," << token << ")" << std::endl;
			break;
		}
	} while (syn != 0);

	outfile.close();

	std::cout << "complete!check it in the result.txt" << std::endl;

	system("pause");
	return 0;
}