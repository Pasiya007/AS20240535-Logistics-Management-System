#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30

void storeCities(char cityName[MAX_CITIES][20], int num_cities);
int addCities(char cityName[MAX_CITIES][20], int num_cities);
void getCities(char cityName[MAX_CITIES][20], int num_cities);




int main()
{
    char cityName[MAX_CITIES][20];
    int num_cities=6;

    strcpy(cityName[0], "Colombo");
    strcpy(cityName[1], "Kandy");
    strcpy(cityName[2], "Galle");
    strcpy(cityName[3], "Jaffna");
    strcpy(cityName[4], "Anuradhapura");
    strcpy(cityName[5], "Polonnaruwa");

    storeCities(cityName,num_cities);
    getCities(cityName,num_cities);
    num_cities= addCities(cityName,num_cities);
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
            fprintf(cities_file, "%s\n",cityName[i]);
        }

        fclose(cities_file);
        printf("City list (total %d) successfully stored to cities.txt.\n", num_cities);
    }
}

int addCities(char cityName[MAX_CITIES][20], int num_cities)
{
    char newCity[20];

    FILE *cities_file = fopen("cities.txt", "a");

    printf("\nEnter city name: ");
    fgets(newCity,20,stdin);

    if (cities_file == NULL)
    {
        printf("Error: Could not open cities.txt for append.\n");
        return 0;
    }

    else
    {
        int i=0;

        fprintf(cities_file, "%s",newCity);
        num_cities++;

        fclose(cities_file);
        printf("City list (total %d) successfully Added to cities.txt.\n", num_cities);

        return num_cities;
    }
}

void getCities(char cityName[MAX_CITIES][20], int num_cities)
{
    FILE *cities_file = fopen("cities.txt", "r");

    if (cities_file == NULL)
    {
        printf("Error: Could not open cities.txt for reading.\n");
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

