#include<stdlib.h>
#include<stdio.h>
#include<dirent.h>

char *lsdir(char dir[], int position){
	struct dirent *de; 

	DIR *dr = opendir(dir);

	if (dr == NULL){
        	printf("Could not open directory\n" );
        	exit(1);
    	}
	position = position+2;
    	int counter = 0;
    	while ((de = readdir(dr)) != NULL){
    		if (counter == position){
			return de->d_name;
		}
		counter++;
    	}
   	closedir(dr);
	return NULL;
}

void printHtmlTitle(){
        printf("<!DOCTYPE html>\n"
        "<html>\n"
        "<head>\n"
        "<title>recipe-website</title>\n"
        "<link rel=\"stylesheet\" href=\"./src/style.css\">\n"
        "</head>\n"
        "<body>\n");
}

void printHtmlHeader(){
        printf("\n<h1>no nonsense cooking</h1>\n"
	"<p>for people who hate web bloat</p>\n");
}

void printHtmlContents(){
	int counter = 0;

	while (0 == 0){
		char *contents = lsdir("./htmlRecipes", counter); 
		if (contents == NULL){
			break;
		}	
		printf("<a href=\"./htmlRecipes/%s\">%s</a>\n", contents, contents);
		counter++;
	}
}

void printHtmlFooter(){
        printf("\n</body>\n"
        "</html>\n");
}

int main(){
	printHtmlTitle();
	printHtmlHeader();
	printHtmlContents();	
	printHtmlFooter();
}


