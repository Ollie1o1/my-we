#include <stdio.h> 

int main () {

	int hours, minutes, minutes_left;

	printf("Enter the number of minutes: ");
	scanf("%d" , &minutes);

	hours = minutes / 60;
	minutes_left = minutes % 60;

	printf("%d minutes = %d hours(s) %d minute(s)\n", minutes , hours, minutes_left);

return 0;

}
// DIY Lab1 Oliver Raczka
