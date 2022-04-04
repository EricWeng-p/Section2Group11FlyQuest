#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"interface.h"
void checkFor() {
	int n;
	//char x = ' ';
	printf("What type of ticket you are looking for?\n");
	printf("1) One Way\n");
	printf("2) Two Way\n");

	printf("My choice is ");
	scanf_s("%d", &n);

	printf("\nWhere you want to go?\n");

	if (n == 1) {
		printf("1) Flight A: Toronto to Montreal\n");
		printf("2) Flight B: Toronto to New York\n");
		printf("My choice is ");
		scanf_s("%d", &n);
	}
	else {
		printf("1) Flight A: Toronto to Montreal and Montreal to Toronto\n");
		printf("2) Flight B: Toronto to New York and New York to Toronto\n");
		printf("My choice is ");
		scanf_s("%d", &n);
	}
}

void printOption() {
	int n;
	printf("\nChoose the service that you want from us.....\n");
	printf("1) Number of empty seats in a plane\n");
	printf("2) List of empty seats\n");
	printf("3) Book my ticket\n");
	printf("4) View my ticket\n");
	printf("5) Check flight status\n");
	printf("6) Cancel my flight\n");
	printf("7) Save\n");
	printf("8) Quit\n");

	printf("My choice is ");
	scanf_s("%d", &n);

}
void welcome() {
	printf("           Welcome         \n");
	printf("             To            \n");
	printf("          FlyQuest         \n\n");
}

