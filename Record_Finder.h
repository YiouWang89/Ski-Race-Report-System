#include <stdio.h>


struct SortRecord
{
	char name[30];
	char age_group[11];
	char raceLength;
	double time_difference;
	char withdrawn;
};

char getCategory(void);

int chooseMenu(void);

void display_ski(int option, char category, struct SortRecord sort_record[]);

int age_group(struct SkierInfo* info);

void SkierManagSystem(char filename[]);

void sortSkier(struct SkierInfo info[], struct SortRecord sortrecord[], int option, char category);



