#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30

void storeCities(char cityName[MAX_CITIES][20], int num_cities);
void getCities(char cityName[MAX_CITIES][20], int num_cities);


int main()
{
    char cityName[MAX_CITIES][20];
    int num_cities=30;

     strcpy(cityName[0], "Colombo");
     strcpy(cityName[1], "Kandy");
     strcpy(cityName[2], "Galle");
     strcpy(cityName[3], "Jaffna");
     strcpy(cityName[4], "Anuradhapura");
     strcpy(cityName[5], "Polonnaruwa");
     strcpy(cityName[6], "Negombo");
     strcpy(cityName[7], "Gampaha");
     strcpy(cityName[8], "Ratnapura");
     strcpy(cityName[9], "Kurunegala");
     strcpy(cityName[10], "Matara");
     strcpy(cityName[11], "Hambantota");
     strcpy(cityName[12], "Batticaloa");
     strcpy(cityName[13], "Trincomalee");
     strcpy(cityName[14], "Nuwara Eliya");
     strcpy(cityName[15], "Badulla");
     strcpy(cityName[16], "Dambulla");
     strcpy(cityName[17], "Kalutara");
     strcpy(cityName[18], "Mannar");
     strcpy(cityName[19], "Vavuniya");
     strcpy(cityName[20], "Kilinochchi");
     strcpy(cityName[21], "Ampara");
     strcpy(cityName[22], "Monaragala");
     strcpy(cityName[23], "Kegalle");
     strcpy(cityName[24], "Chilaw");
     strcpy(cityName[25], "Puttalam");
     strcpy(cityName[26], "Bandarawela");
     strcpy(cityName[27], "Tangalle");
     strcpy(cityName[28], "Hatton");
     strcpy(cityName[29], "Beruwala");

     storeCities(cityName,num_cities);
    getCities(cityName,num_cities);

    return 0;
}

void storeCities(char cityName[MAX_CITIES][20], int num_cities)
{
    int i;

    FILE *cities_file = fopen("cities.txt", "w");

    if (cities_file == NULL)
    {
        printf("Error: Could not open cities.txt for writing.\n");
        return;
    }

    else
    {

        for (i = 0; i < num_cities; i++)
        {
            fprintf(cities_file, "\n%s",cityName[i]);
        }

        fclose(cities_file);
        printf("City list (total %d) successfully saved to cities.txt.\n", num_cities);
    }
}

void getCities(char cityName[MAX_CITIES][20], int num_cities)
{
    FILE *cities_file = fopen("cities.txt", "r");

    if (cities_file == NULL)
    {
        printf("Error: Could not open cities.txt for writing.\n");
        return;
    }

    else
    {
        for (int i = 0; i <num_cities ; i++)
        {

            fscanf(cities_file, "%s",cityName[i]);
            printf("\n %d.\t%s",i+1,cityName[i]);
        }


        fclose(cities_file);
    }
}

