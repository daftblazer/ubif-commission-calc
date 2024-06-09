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

    int selection = 0;
    int total_services = 0;
    int total_homeplus = 0;
    int total_accessory = 0;

    // Get the current date
    get_current_date(date_str, sizeof(date_str));

    while (1) {


        printf("\n");
        printf("Make a selection: \n");
        printf("1) ATT Phone Sanitization \n");
        printf("2) ATT Performance Check \n");
        printf("3) Verizon Cleaning \n");
        printf("4) Verizon In-Person Refresh \n");
        printf("5) Home+ Sale \n");
        printf("6) Remote Tech Repair \n");
        printf("7) Add Custom Sale \n");
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
            case 7:
                double item_price;
                double custom_commission;
                clear_terminal();
                printf("Enter price of item sold: \n");
                if (scanf("%lf", &item_price) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                custom_commission = (item_price * 0.10);
                total_commission += custom_commission;

                // Debugging output
                printf("custom_commission value: %.2lf\n", custom_commission);
                printf("total_commission value: %.2lf\n", total_commission);
                printf("Press any key to continue...");
                // Clear input buffer
                while (getchar() != '\n');
                // Wait for any key press
                getchar();
                total_accessory++;
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
       if (total_accessory > 0 ) {
           printf("Total accessory sales: %d\n", total_accessory);
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





