#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OUT 0
#define IN 1
#define NAME_LEN 128
#define ATTR_NUM 128
#define ATTR_LEN 1024


struct Tag get_tag(FILE *p, struct Tag tag);

struct Tag {
	char tag_name[NAME_LEN];
	char attr_name[ATTR_NUM][ATTR_LEN];
	char attr_content[ATTR_NUM][ATTR_LEN];
};

struct Tag get_tag(FILE *p, struct Tag tag) {


	char c;

	for (int i = 0; c = fgetc(p) != ' '; i++)
		tag.tag_name[i] = c;

	for (int i_name = 0; c != '>'; i_name++) {

		int j_name = 0;

		while (c = fgetc(p) != '=') {
			tag.attr_name[i_name][j_name++] = c;
		}

		if (c = fgetc(p) == '\"')
			;
		while (c = fgetc(p) != '\"') {
			tag.attr_content[i_name][j_name++] = c;
		}

		if (c = fgetc(p) == ' ')
			;
	}

	return tag;
}














void main() {


	char tag_start[] = "<div class=\"content__article-body";
	char tag_end[] = "</div>";
	char tag_div[] = "<div ";

	int state_start = OUT;
	int state_end = OUT;



	FILE *p;
	FILE *new;
	char c;

	int i_start = 0;
	int i_end = 0;
	int i_tag = 0;

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



	



	




