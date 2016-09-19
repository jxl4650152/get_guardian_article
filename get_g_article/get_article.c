#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OUT 0
#define IN 1
#define NAME_LEN 128
#define ATTR_NUM 16
#define ATTR_LEN 1024


void get_tag(FILE *p, struct Tag *tag);
char *get_tag_attr_content(struct Tag tag, char *tag_attr);


struct Tag {
	char tag_name[NAME_LEN];
	char attr_name[ATTR_NUM][ATTR_LEN];
	char attr_content[ATTR_NUM][ATTR_LEN];
};

void get_tag(FILE *p, struct Tag *tag) {


	char c;

	for (int i = 0; (c = fgetc(p) != ' ')&&(c != '>'); i++)
		tag->tag_name[i] = c;

	for (int i_name = 0; c != '>'; i_name++) {

		int j_name = 0;

		while (c = fgetc(p) != '=') {
			tag->attr_name[i_name][j_name++] = c;
		}

		if (c = fgetc(p) == '\"')
			;
		while (c = fgetc(p) != '\"') {
			tag->attr_content[i_name][j_name++] = c;
		}

		if (c = fgetc(p) == ' ')
			;
	}

	
}


char *get_tag_attr_content(struct Tag tag, const char *tag_attr) {
	int i;
	for (i = 0; tag.attr_name[i] != NULL; i++) {
		if (strcmp(tag_attr, tag.attr_name[i]) == 0)
			break;
	}

	return tag.attr_content[i];
}










void main() {


	char target_attr_content[] = "content__article-body from-content-api js-article__body";
	char target_end_tag_name[] = "/div";
	char target_tag_name[] = "div";
	char target_attr_name[] = "class";

	



	FILE *p;
	FILE *new;
	char c;
	static struct Tag tag;
	int num;

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

	/*find start_tag*/


	while (c = fgetc(p) != EOF) {
		if (c != "<")
			;
		else {
			get_tag(p, &tag);
			if (strcmp(tag.tag_name, target_tag_name) == 0) {
				if (strcmp(target_attr_content, get_tag_attr_content(tag, target_attr_name)) == 0)
					printf("start tag is found/n");
				break;
			}

			memset(&tag, 0, sizeof(struct Tag));
		}
	}

	/*skip CFNL etc.*/

	while (c = fgetc(p) != '<')
		;

	num = 1;

	while(num != 0){
		get_tag(p, &tag);
		if (strcmp(tag.tag_name, target_tag_name) == 0)
			num++;
		if (strcmp(tag.tag_name, target_end_tag_name) == 0)
			num--;
		while(c = fgetc(p) != '<')



	



	




