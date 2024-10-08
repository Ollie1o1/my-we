/************************RaczkaOliverA1.c**************
Student Name: oliver Raczka Email Id: oraczka
Due Date: October 4 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.
********************************************************/
/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc lastnameFirstnameA2.c -std=c99 -Wall
OR
gcc lastnameFirstnameA1.c -std=c99 -Wall -o assn1
Running the Program
Running: ./a.out
*********************************************************/
#include <stdio.h>
#include <math.h> // for math function

// calculate the cost method so that i dont need 400 lines for repeated if else statements for the hotels
void calculateCost(int numDays, int hotelCostPerNight, int rideCost, int cost_placeholder) {
    int birthdate, hotelCost, total, total_discount;
    
    hotelCost = numDays * hotelCostPerNight;
    total = hotelCost + cost_placeholder + rideCost;
    total_discount = total;

    printf("Now enter your day of birth to see if you qualify for a discount: ");
    scanf("%d", &birthdate);

    printf("Total Cost comes to:\n\n");
    printf("Cost of closest departure flight: $ %d\n", cost_placeholder);
    printf("Cost of Hotel for %d days: $ %d\n", numDays, hotelCost);
    printf("Cost of Ride: $%d\n\n", rideCost);
    printf("Total Cost before tax: $ %d\n\n", total);

    // Applying discounts
    float discount_check = 0;
    if(total_discount % 11 == 0) {
        discount_check = total_discount * 0.05;
        total_discount -= discount_check;
        printf("You Recieved a 5 percent discount because your total was a multiple of 11 (:\n");
    } else {
        printf("Sorry - you missed out on a 5 percent discount because the total cost was not a multiple of 11\n");
    }

    int day_of_birth = birthdate % 100; 
    int sum_of_digits = (day_of_birth / 10) + (day_of_birth % 10); 

    if (sum_of_digits > 0 && (total_discount % sum_of_digits == 0)) {
        total_discount -= total_discount * 0.05; 
        printf("You recieved a 5 percent discount because your total cost was a multiple sum of the digits in your day of birth (:\n\n");
    } else {
        printf("Sorry - you missed out on the additional 5 percent discount because the total cost after discount 1 was not a multiple of the sum of digits in your day of birth\n\n");
    }

    printf("Total Cost after discounts 1 and 2: $ %d\n\n", total_discount);

    float tax = total_discount * 0.13;
    float final_total = total_discount + tax;
    printf("Finally, your total cost after taxes: $ %.2f\n", final_total);
}
// start of the main function 
int main () {

    int input, input_toMin;
    int departure_times[] = {435, 495,55,615,675,915,975,1035};
    int arrival_times[] = {505, 565, 625, 685, 745, 985, 1045, 1105};
    int flightCost[] = {231, 226, 226, 283, 283, 226, 226, 401};
    int size = sizeof(departure_times) / sizeof(departure_times[0]);
    printf("Would you like to Enter your time in the 12-hour format (enter 1), or the 24-hour format (enter 2): ");
    scanf("%d", &input);

    if(input == 1) {

        int hour, minute;
        char apm;

        printf("Please enter a value for the hour: ");
        scanf("%d", &hour);
        if(hour > 12 || hour < 1){ 
            printf("You did not enter a valid input for the hour, please try again!!\n");
            return 0;
        }
        printf("Please enter a value for the minute: ");
        scanf("%d", &minute); 
        if(minute > 59 || minute < 0){// fix this for later !!!!!!!!!!!!!!!!!!!!!!!
            printf("You did not enter a valid input for the minute, please try again!!\n");
            return 0;
        }
        printf("Please enter a for am or p for pm: ");
        scanf(" %c", &apm);  // space needs to be there so go to newline
         if(apm != 'a' && apm != 'p'){
            printf("You did not choose either a or p, please try again!!\n");
            return 0;
        }
        for(int i = 0; i < 30; i++){  // this is the for loop for the line 
            printf("-");
        }

        printf("\n");

        if(apm == 'a')     // this is to show the user their inputted time
        {
            printf("You entered the time: %02d:%02d AM\n", hour, minute);   //02 after the % in order to have a 0 before or after the number to make the time correct   
        }
        else if(apm =='p')
        {
             printf("You entered the time: %02d:%02d PM\n", hour, minute);
        }

        if(apm == 'a') {  // what the users time would have been if it was in 24 hour format
            if(hour == 12) {
                hour = 0;
                printf("In the 24 Hour format - you entered: %02d:%02d AM\n", hour, minute);
            }
            else{
                printf("In the 24 Hour fomrmat - you entred: %02d:%02d AM\n", hour, minute);
            }
        }
        else if(apm == 'p'){
            if(hour != 12){
                hour += 12;
            }
            printf("In the 24 Hour format - you entered: %02d:%02d PM\n", hour, minute);
        }
        for(int i = 0; i < 30; i++){  // this is the closing for loop for the line
            printf("-");
        }
        printf("\n");

    //Now find out the closest departure time
    input_toMin = hour * 60 + minute;

    int departure_placeholder = -1;
    int arrival_placeholder = -1;
    int cost_placeholder = -1;
        // this is where teh closest departure time is found by sifting through the 3 arrays and getting the proper values
     for (int i = 0; i < size; i++) {
        if (departure_times[i] >= input_toMin) {
            departure_placeholder = departure_times[i];
            arrival_placeholder = arrival_times[i];
            cost_placeholder = flightCost[i];
            break; // make sure it actually stops when it finds a time that is finially greater than the input 
        }
     }
    if(departure_placeholder == -1) // if the placeholder doesnt change then it means there is no close departure time 
    {
        printf("There are currently no flights available at your current time.\n");
        return 0;
    }
    int departureHour = departure_placeholder / 60;
    int departureMinute = departure_placeholder % 60;
    char departureApm = (departure_placeholder >= 720) ? 'P' : 'A'; // must be 720 because that is MINUTES
    // cooler way of writing if else statement
    //if the condition is true p is the result for PM and if false AM 
    if (departureHour > 12){
        departureHour -= 12;  // Convert to 12-hour format
    } 
    else if (departureHour == 0) {
        departureHour = 12; //this is just for if its 12 AM or PM
    }
    // this next set is the same as the one above but for arrivals
    int arrivalHour = arrival_placeholder / 60;
    int arrivalMinute = arrival_placeholder % 60;
    char arrivalApm = (arrival_placeholder >= 720) ? 'P' : 'A';  // must be 720 because that is MINUTES
    // cooler way of writing if else statement
    //if the condition is true p is the result for PM and if false AM 

    if (arrivalHour > 12){
        arrivalHour -= 12;  // Convert to 12-hour format
    } 
    else if(arrivalHour == 0) {
       arrivalHour = 12; //this is just for if its 12 AM or PM
    }

    printf("Closest departure time is %02d:%02d %cM, ", departureHour, departureMinute, departureApm);
    printf("arriving at %02d:%02d %cM\n", arrivalHour, arrivalMinute, arrivalApm);
    //now we ask for the hotels 
    int hotel_input;
    printf("Would you like a hotel in Montreal - enter 0 for no and 1 for yes: ");
    scanf("%d", &hotel_input);

    if(hotel_input == 1){
        printf("There are 3 Hotels:\n");
        printf("1. Mariott: $248 per night\n");
        printf("2. Sheraton: $90 per night\n");
        printf("3. Double Tree: $128 per night\n");

        int hotel_choice, numDays, ride_choice;
        printf("Your Choice?: ");
        scanf("%d", &hotel_choice);
        
        printf("How many days in Montreal?: ");
        scanf("%d", &numDays);
        
        printf("\n");

        printf("Would you like a ride from the airport to the hotel? - enter 0 for no and 1 for yes: ");
        scanf("%d", &ride_choice);

        int rideCost = (ride_choice == 1) ? (hotel_choice == 1 ? 0 : (hotel_choice == 2 ? 25 : 20)) : 0;
        int hotelCostPerNight = (hotel_choice == 1) ? 248 : (hotel_choice == 2) ? 90 : 128;

        printf("\n");

        calculateCost(numDays, hotelCostPerNight, rideCost, cost_placeholder);
    }
    else if(hotel_input == 0)
    {
        int numDays, hotelCostPerNight, rideCost;
        numDays = 0;
        hotelCostPerNight = 0;
        rideCost = 0;
        calculateCost(numDays, hotelCostPerNight, rideCost, cost_placeholder);
    }
    // this next part is if the person chooses to use the 12 hour format!!!!
    }
    else if(input == 2){
            
        int hour, minute;
        char apm;

        printf("Please enter a value for the hour: ");
        scanf("%d", &hour);
        if(hour > 23 || hour < 0)
        {
            printf("Please enter a valid input for the hour and try again!!!\n");
            return 0;
        }
        printf("Please enter a value for the minute: ");
        scanf("%d", &minute);
        if(minute > 59 || minute < 0){
            printf("You did not enter a valid input for the minutes, please try again!!\n");
            return 0;
        }
      
        for(int i = 0; i < 30; i++){  // this is the for loop for the line 
            printf("-");
        }

        printf("\n");

        if(hour >= 12) {
        apm = 'P';  // It's PM if the hour is 12 or more
        } else {
        apm = 'A';  // Otherwise, it's AM
        }
        
        printf("You entered the time: %02d:%02d %cM\n", hour, minute, apm);     
        
        if(apm == 'A') {  // what the users time would have been if it was in 24 hour format
            if(hour <= 12 && hour >= 0) {
                printf("In the 12 Hour format - you entered: %02d:%02d AM\n", hour, minute);
            }
            else{
                printf("You did not enter a proper time in for the morning (AM) please try again!!\n");
                return 0;
            }
        }
        else if(apm == 'P'){
            if(hour <= 24 && hour > 12){
                int hour_convert;
                hour_convert = hour - 12;
                printf("In the 12 Hour format - you entered: %02d:%02d PM\n", hour_convert, minute);
            }
            else{
                printf("You did not enter the time in the 24 hour format please try again!!\n");
                return 0;
            }
        }


     for(int i = 0; i < 30; i++){  // this is the closing for loop for the line
            printf("-");
        }
        printf("\n");

    //Now find out the closest departure time
    input_toMin = hour * 60 + minute;

    int departure_placeholder = -1;
    int arrival_placeholder = -1;
    int cost_placeholder = -1;

        // this is where teh closest departure time is found by sifting through the 3 arrays and getting the proper values
     for (int i = 0; i < size; i++) {
        if (departure_times[i] >= input_toMin) {
            departure_placeholder = departure_times[i];
            arrival_placeholder = arrival_times[i];
            cost_placeholder = flightCost[i];
            break; // make sure it actually stops when it finds a time that is finially greater than the input 
        }
     }

    if(departure_placeholder == -1) // if the placeholder doesnt change then it means there is no close departure time 
    {
        printf("There are currently no flights available at your current time.\n");
        return 0;
    }

    int departureHour = departure_placeholder / 60;
    int departureMinute = departure_placeholder % 60;
    char departureApm = (departure_placeholder >= 720) ? 'P' : 'A'; // must be 720 because that is MINUTES
    // cooler way of writing if else statement
    //if the condition is true p is the result for PM and if false AM 

    if (departureHour > 12){
        departureHour -= 12;  // Convert to 12-hour format
    } 
    else if (departureHour == 0) {
        departureHour = 12; //this is just for if its 12 AM or PM
    }

    // this next set is the same as the one above but for arrivals

    int arrivalHour = arrival_placeholder / 60;
    int arrivalMinute = arrival_placeholder % 60;
    char arrivalApm = (arrival_placeholder >= 720) ? 'P' : 'A';  // must be 720 because that is MINUTES
    // cooler way of writing if else statement
    //if the condition is true p is the result for PM and if false AM 

    if (arrivalHour > 12){
        arrivalHour -= 12;  // Convert to 12-hour format
    } 
    else if(arrivalHour == 0) {
       arrivalHour = 12; //this is just for if its 12 AM or PM
    }


    printf("Closest departure time is %02d:%02d %cM, ", departureHour, departureMinute, departureApm);
    printf("arriving at %02d:%02d %cM\n", arrivalHour, arrivalMinute, arrivalApm);


    //now we ask for the hotels 
    int hotel_input;
    printf("Would you like a hotel in Montreal - enter 0 for no and 1 for yes: ");
    scanf("%d", &hotel_input);

    if(hotel_input == 1){
        printf("There are 3 Hotels:\n");
        printf("1. Mariott: $248 per night\n");
        printf("2. Sheraton: $90 per night\n");
        printf("3. Double Tree: $128 per night\n");

        int hotel_choice, numDays, ride_choice;
        printf("Your Choice?: ");
        scanf("%d", &hotel_choice);
        
        printf("How many days in Montreal?: ");
        scanf("%d", &numDays);
        
        printf("\n");

        printf("Would you like a ride from the airport to the hotel? - enter 0 for no and 1 for yes: ");
        scanf("%d", &ride_choice);

        int rideCost = (ride_choice == 1) ? (hotel_choice == 1 ? 0 : (hotel_choice == 2 ? 25 : 20)) : 0;
        int hotelCostPerNight = (hotel_choice == 1) ? 248 : (hotel_choice == 2) ? 90 : 128;

        printf("\n");

        calculateCost(numDays, hotelCostPerNight, rideCost, cost_placeholder);
    }
    else if(hotel_input == 0)
    {
        int numDays, hotelCostPerNight, rideCost;
        numDays = 0;
        hotelCostPerNight = 0;
        rideCost = 0;
        calculateCost(numDays, hotelCostPerNight, rideCost, cost_placeholder);
    }
    }
    else {
        printf("Please enter a valid input and try again!\n");
        return 0;
    }
        return 0;   
} 
