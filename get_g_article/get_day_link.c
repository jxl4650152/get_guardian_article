#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add_day_to_link(char *base_link, int day);

	

void add_day_to_link(char *base_link, int day)
{

	char day_str[3];
	char *zero = "0";

	sprintf(day_str, "%d", day);


	if (day < 10)
		strcat(strcat(base_link, zero), day_str);
	else
		strcat(base_link, day_str);



}



