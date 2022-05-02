#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define dataRecord 14
#include "file_helper.h"
#include "Record_Finder.h"

// get the category user wanna print
char getCategory(void)
{
	char a;
	char category = 0;

	printf("Which category (S, M, L): ");
	scanf("%c%*c", &a);

	if (a == 's' || a == 'S')
		category = 'S';
	else if (a == 'm' || a == 'M')
		category = 'M';
	else if (a == 'l' || a == 'L')
		category = 'L';
	return category;
}

// dispaly the menu to user and get the option
int chooseMenu(void)
{
	int option;
    printf("What would you like to do?\n");
    printf("0 - Exit\n");
    printf("1 - Print top 3 skiers in a category\n");
    printf("2 - Print all skiers in a category\n");
    printf("3 - Print last 3 skiers in a category\n");
    printf("4 - Print winners in all categories\n");
    printf(":");
	scanf("%d%*c", &option);
	return option;
}

//display the skier list based on option
void display_ski(int option, char category, struct SortRecord sort_record[])
{
	int i;
	int hour, min, count1 = 0, count3 = 0;
	// print the top 3 skiers 
	if (option == 1)
	{
		printf("Skier                     Age Group Time\n");
		printf("----------------------------------------\n");
		for (i = 0; i < dataRecord; i++)
		{
			hour = sort_record[i].time_difference;
			min = (sort_record[i].time_difference - hour) * 60 + 0.5;
			if (count1 < 3)
			{
				
				if ((category == sort_record[i].raceLength) && (sort_record[i].withdrawn != 1) )
				{
					if (min < 10)
					{
						printf("%-18s%15s   %d:0%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
						count1++;
					}
					else
					{ 
						printf("%-18s%15s   %d:%d\n", sort_record[i].name, sort_record[i].age_group,hour,min );
					}
					count1 ++;
				}
			}
		}
	}
	else if (option == 3)  // print the last 3 skiers 
	{
		printf("Skier                     Age Group Time\n");
		printf("----------------------------------------\n");
		for (i = dataRecord - 1; i > 0; i--)
		{
			hour = sort_record[i].time_difference;
			min = (sort_record[i].time_difference - hour) * 60 + 0.5;
			if (count3 < 3)
			{
				if (category == sort_record[i].raceLength && (sort_record[i].withdrawn != 1))
				{
					if (min < 10)
					{
						printf("%-18s%15s   %d:0%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
					}
					else
					{
						printf("%-18s%15s   %d:%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
					}
					count3++;
				}
			}
		}
	}
	else if (option == 2) //print all skiers in one category
	{
		printf("Skier                     Age Group Time Withdrew\n");
		printf("-------------------------------------------------\n");
		for (i = 0; i < dataRecord; i++)
		{
			hour = sort_record[i].time_difference;
			min = (sort_record[i].time_difference - hour) * 60 + 0.5;
			if (category == sort_record[i].raceLength)
			{
				if (sort_record[i].withdrawn == 0)
				{
					if (min < 10)
					{
						printf("%-18s%15s   %d:0%d   No\n", sort_record[i].name, sort_record[i].age_group, hour, min);
					}
					else
					{
						printf("%-18s%15s   %d:%d   No\n", sort_record[i].name, sort_record[i].age_group, hour, min);
					}
				}
			}
		}
		for (i = 0; i < dataRecord; i++)
		{
			if (sort_record[i].withdrawn == 1)
			printf("%-18s%15s    N/A   Yes\n", sort_record[i].name, sort_record[i].age_group);
		}
	}
	else if (option == 4)  //print all the winner in each category
	{
		printf("Skier                     Age Group Category Time\n");
		printf("-------------------------------------------------\n");
		for (i = 0; i < dataRecord; i++)
		{
			hour = sort_record[i].time_difference;
			min = (sort_record[i].time_difference - hour) * 60 + 0.5;
			if (sort_record[i].raceLength == 'S' && (sort_record[i].withdrawn != 1)) // print winner in 10km
			{
				if (min < 10)
				{
					printf("%-18s%15s    10 km  %d:0%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
				}
				else
				{
					printf("%-18s%15s    10 km  %d:%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
				}
				i = dataRecord + 1;
			}
		}
		for (i = 0; i < dataRecord; i++)
		{
			hour = sort_record[i].time_difference;
			min = (sort_record[i].time_difference - hour) * 60 + 0.5;
			if (sort_record[i].raceLength == 'M' && (sort_record[i].withdrawn != 1)) // print winner in 25km
			{
				if (min < 10)
				{
					printf("%-18s%15s    25 km  %d:0%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
				}
				else
				{
					printf("%-18s%15s    25 km  %d:%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
				}
				i = dataRecord + 1;
			}
		}
		for (i = 0; i < dataRecord; i++)
		{
			hour = sort_record[i].time_difference;
			min = (sort_record[i].time_difference - hour) * 60 + 0.5;
			if (sort_record[i].raceLength == 'L' && (sort_record[i].withdrawn != 1)) // print winner in 50km
			{
				if (min < 10)
				{
					printf("%-18s%15s    50 km  %d:0%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
				}
				else
				{
					printf("%-18s%15s    50 km  %d:%d\n", sort_record[i].name, sort_record[i].age_group, hour, min);
				}
				i = dataRecord + 1;
			}
		}

	}
}

// define age group, 16-20 is Juniour, 21-34 is Adult, 35+ is Senior 
int age_group(struct SkierInfo* info)
{
	int age_group = 0;

	if ( (info->age) <= 20 && (info->age) >= 16)
	{
		age_group = 1;
	}
	else if ((info->age) <= 34 && (info->age) >= 21)
	{
		age_group = 2;
	}
	else if (35 <= info->age)
	{
		age_group = 3;
	}
	return age_group;
}

// Read the data from file, sort the data and display the list based on user's option
void SkierManagSystem( char filename[])
{
	int i, option;
	char category = '1';
	struct SortRecord sort_record[100 * 14] = { { 0 } };
	struct SkierInfo ski_info[100 * 14] = { { 0 } };
	
	// Read the file and store data in to a structure
	FILE* fp = fopen(filename, "r");
	if (fp != NULL)
	{
		for (i = 0; i < dataRecord; i++)
		{
			readFileRecord(fp, &ski_info[i]);
		}
		fclose(fp);
		fp = NULL;
	}
	else
	{
		printf("Sorry, Cannot open the file!\n");
	}

	

	option = chooseMenu();
	while (option != 0)
	{

		switch (option)
		{
		case 1:
			printf("\n");
			category = getCategory();
			printf("\n");
			sortSkier(ski_info, sort_record,option, category);
			break;
		case 2:
			printf("\n");
			category = getCategory();
			printf("\n");
			sortSkier(ski_info, sort_record, option, category);
			break;
		case 3:
			printf("\n");
			category = getCategory();
			printf("\n");
			sortSkier(ski_info, sort_record, option, category);
			break;
		case 4:
			printf("\n");
			sortSkier(ski_info, sort_record, option, category);
			break;
		}
		printf("\n");
		option = chooseMenu();
	}
	printf("Keep on Skiing!\n\n");
}


// Sort all the record in struct, copy and change age to age group, startTime midwayTime finishTime to timedifference
void sortSkier(struct SkierInfo info[], struct SortRecord sortrecord[], int option, char category)
{
	int i, j, a;
	char temp_name[30 * dataRecord] = { 0 };
	int temp_age;
	char temp_raceLength, temp_withdraw;
	double temp_time;
	for (i = 0; i < dataRecord; i++)
	{
		for (j = i + 1; j < dataRecord; j++)
		{
			if ((info[j].finishTime - info[j].startTime) < (info[i].finishTime - info[i].startTime))
			{
				strcpy(temp_name, info[j].name);
				strcpy(info[j].name, info[i].name);
				strcpy(info[i].name, temp_name);
				
				temp_age = info[j].age;
				info[j].age = info[i].age;
				info[i].age = temp_age;
				
				temp_raceLength = info[j].raceLength;
				info[j].raceLength = info[i].raceLength;
				info[i].raceLength = temp_raceLength;
				
				temp_time = info[j].startTime;
				info[j].startTime = info[i].startTime;
				info[i].startTime = temp_time;
				
				temp_time = info[j].midwayTime;
				info[j].midwayTime = info[i].midwayTime;
				info[i].midwayTime = temp_time;
				
				temp_time = info[j].finishTime;
				info[j].finishTime = info[i].finishTime;
				info[i].finishTime = temp_time;
				
				temp_withdraw = info[j].withdrawn;
				info[j].withdrawn = info[i].withdrawn;
				info[i].withdrawn = temp_withdraw;
				
				
			}
		}
	}

	for (i = 0; i < dataRecord; i++)
	{
		strcpy(sortrecord[i].name, info[i].name);
		sortrecord[i].raceLength = info[i].raceLength;
		sortrecord[i].time_difference = info[i].finishTime - info[i].startTime;
		sortrecord[i].withdrawn = info[i].withdrawn;
		a = age_group(&info[i]);
		if (a == 1)
			strcpy(sortrecord[i].age_group, "Juniors");
		else if (a == 2)
			strcpy(sortrecord[i].age_group, "Adults");
		else if (a == 3)
			strcpy(sortrecord[i].age_group, "Seniors");
	}
	display_ski(option, category, sortrecord);
}