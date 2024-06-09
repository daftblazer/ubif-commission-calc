#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_terminal();
void get_current_date(char *date_str, size_t max_size);
void save_to_file(double total_commission, int total_services, int total_homeplus, const char *date_str);



int main() {
    double total_commission = 0;
    int sales;
    char date_str[11]; // Buffer to hold the date string

    // Get the current date
    get_current_date(date_str, sizeof(date_str));

    while (1) {
        int selection;
        int total_services;
        int total_homeplus;

        printf("\n");
        printf("Make a selection: \n");
        printf("1) ATT Phone Sanitization \n");
        printf("2) ATT Performance Check \n");
        printf("3) Verizon Cleaning \n");
        printf("4) Verizon In-Person Refresh \n");
        printf("5) Home+ Sale \n");
        printf("6) Remote Tech Repair \n");
        printf("9) Clear Total \n");
        printf("0) Save and Exit \n");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                total_commission += 3;
                total_services++;
                break;
            case 2:
                total_commission += 4.5;
                total_services++;
                break;
            case 3:
                total_commission += 2.5;
                total_services++;
                break;
            case 4:
                total_commission += 1.5;
                total_services++;
                break;
            case 5:
                total_commission += 25;
                total_homeplus++;
                break;
            case 6:
                total_commission += 5;
                total_services++;
                break;
            case 9:
                total_commission = 0;
                total_services = 0;
                total_homeplus = 0;
                break;
            case 0:
                save_to_file(total_commission, total_services, total_homeplus, date_str);
                return 0;
            default:
                printf("Invalid Selection. Please try again. \n");
                break;

        }

        clear_terminal();


       printf("Current commission:  $%.2lf\n", total_commission);
       if (total_services > 0) {
           printf("Total services: %d\n", total_services);
       }
       if (total_homeplus > 0) {
           printf("Total home+ sales: %d\n", total_homeplus);
       }

    }


    return 0;
}

// Declaring Functions

void clear_terminal() {
    // Clear the terminal
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void get_current_date(char *date_str,size_t max_size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Format the date as YYYY-MM-DD
    strftime(date_str, max_size, "%Y-%m-%d", &tm);
}

void save_to_file(double total_commission, int total_services, int total_homeplus, const char *date_str) {
    char filename[20]; // Buffer to hold the filename string
    sprintf(filename, "commission_%s.txt", date_str);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Date: %s\n", date_str);
    fprintf(file, "\n");
    fprintf(file, "Total commission: $%.2lf\n", total_commission);
    fprintf(file, "Total services: %d\n", total_services);
    fprintf(file, "Total home+ sales: %d\n", total_homeplus);
    fclose(file);
    clear_terminal();
    printf("Today's performance was saved!\n");
    printf("Today's Performance:\n");
    printf("    Total commission: $%.2lf\n", total_commission);
    printf("    Total services: %d\n", total_services);
    printf("    Total home+ sales: %d\n", total_homeplus);
}





