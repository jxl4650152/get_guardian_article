#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OUT 0
#define IN 1


void main() {


	char tag_start[] = "<div class=\"content__article-body";
	char tag_end[] = "</div>";

	int state_start = OUT;
	int state_end = OUT;

	char line_start[sizeof(tag_start)] = { 0 };
	char line_end[sizeof(tag_end)] = { 0 };


	FILE *p;
	FILE *new;
	char c;
	int i_start = 0;
	int i_end = 0;

	/*open 1.txt and 2.txt*/

	p = fopen("1.txt", "r");

	if (!p)
	{
		printf("Failed to open 1.txt file\n");
		exit(1);
	}
	else
		printf("open 1.txt file\n");

	new = fopen("2.txt", "w");

	if (!new)
	{
		printf("Failed to open 2.txt file\n");
		exit(1);
	}
	else
		printf("open 2.txt file\n");
	printf("%d\n", sizeof(tag_start));


	/*find the tag_start*/

	while (((c = fgetc(p)) != EOF) ) {
		
		
		if (c == tag_start[i_start]) {
			printf("%c", c);
			if (i_start != (sizeof(tag_start) - 2)) {
				
				i_start++;
			}
			else {
				printf("tag_start found with %d\n", i_start);
				break;
			}
				
		}
		else {
			if (i_start != 0)
				i_start = 0;
			 
				
			
				
				
		}

	}

	
		

	/*skip the remaining of tag_start*/

	while ((c = fgetc(p)) != '>')
		;
	printf("%c\n", c);


	/*copy c to 2.txt until tag_end*/

	while ((c = fgetc(p)) != EOF) {
		if(state_end == OUT){
			if(c == tag_end[i_end]){
				state_end = IN;
				

		
	

	fclose(p);
	fclose(new);
	getchar();
	}

	




