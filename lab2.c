#include <stdio.h>

//DIY Lab2 by Oliver Raczka Sept, 18

int main () {

	int grade, grade_modulo;

	printf("Enter a Numeric Grade: ");
	scanf("%d" , &grade);

	grade_modulo = grade % 10;

	if (grade < 0) {
		printf("This is not possible try again with a positive integer\n");
		return 0;
	}

	if (grade <= 59) {
	  printf("You have failed ):\n");
          }

	else if (grade >= 60 && grade <= 69)
	{
	printf("Letter Grade: D");
	}
        else if (grade >= 70 && grade <= 79){
        printf("Letter Grade: C");
	}
	else if (grade >= 80 && grade <= 89){
        printf("Letter Grade: B");
        }
        else if (grade >= 90 && grade <= 100){
        printf("Letter Grade: A");
	}


	if(grade >= 60 && grade <= 100) {
 		if (grade_modulo >= 0 && grade_modulo <= 2){
		  printf("-\n");
		}
		else if (grade_modulo >= 7 && grade_modulo <= 9){
		  printf("+\n");
		}
		else
	        {
		  printf("\n");
		}
	  }

	return 0;
}
