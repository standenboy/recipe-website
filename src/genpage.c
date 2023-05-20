#include<stdlib.h>
#include<stdio.h>
#include<string.h>


char *readLine(char dir[], int line){
	FILE *fptr;
	fptr = fopen(dir,"r");
	if (fptr == NULL){
		printf("failed to open file");
		exit(1); 
	}
	
	char *currentLine = malloc(300);
	int lineCount = 0;
	while(fgets(currentLine, 300, fptr)) {
		if (lineCount == line){
			return currentLine;
		}
		lineCount++;
	}	
	return NULL;
}

char *removeFirstChar(char string[]){
	memmove(string, string+1, strlen(string));	
	return string;
}

char *removeNewLine(char string[]){
	string[strcspn(string,"\n")] = '\0';
	return string;
}

char *fixString(char string[]){
	string = removeFirstChar(string);
	string = removeNewLine(string);
	return string;
}

void printHtmlTitle(char name[]){
	name = fixString(name);
	printf("<!DOCTYPE html>\n"
	"<html>\n"
	"<head>\n"
	"<title>%s</title>\n"
	"<link rel=\"stylesheet\" href=\"../src/style.css\">\n"
	"</head>\n"
	"<body>\n",name);
}

void printHtmlHeader(char name[]){
	printf("\n<h1>%s</h1>\n", name);
}


void printHtmlIngredients(){
	printf("\n<h2>Ingredients</h2>\n");
}

void printHtmlIngredientsList(char ingredient[]){
	ingredient = fixString(ingredient);
	printf("<p>-%s</p>\n", ingredient);
}

void printHtmlInstructions(){	
	printf("\n<h2>Instructions</h2>\n");
}

void printHtmlInstructionsList(char instruction[]){
	instruction = fixString(instruction);
	printf("<p>-%s</p>\n", instruction);
}

void printHtmlFooter(){
	printf("\n</body>\n"
	"</html>\n");
}

int main(int argc, char *argv[]){

	int counter = 0;

	int alreadyPrintedInstructions = 0;

	while(0 == 0){
		char *line = readLine(argv[1],counter);
		if (line == NULL){
			break;
		}
		counter++;
		switch(line[0]){
			case '#':
				printHtmlTitle(line);
				printHtmlHeader(line);
				printHtmlIngredients();
				break;
			case '*':
				printHtmlIngredientsList(line);
				break;
			case ';':
				if (alreadyPrintedInstructions == 0){
					printHtmlInstructions();
					alreadyPrintedInstructions = 1;
				}
				printHtmlInstructionsList(line);
				break;
		}
	}
	printHtmlFooter();
}


