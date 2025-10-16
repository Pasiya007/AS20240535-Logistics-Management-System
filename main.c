#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30

void storeCities(char cityName[MAX_CITIES][20]);
void addCities(char cityName[MAX_CITIES][20]);
int countCities();
void readCities(char cityName[MAX_CITIES][20]);




int main()
{
    char cityName[MAX_CITIES][20];

    strcpy(cityName[0], "Colombo");
    strcpy(cityName[1], "Kandy");
    strcpy(cityName[2], "Galle");
    strcpy(cityName[3], "Jaffna");
    strcpy(cityName[4], "Anuradhapura");
    strcpy(cityName[5], "Polonnaruwa");

    //storeCities(cityName);
    readCities(cityName);
    addCities(cityName);
    readCities(cityName);

    return 0;
}

void storeCities(char cityName[MAX_CITIES][20])
{
    int i;
    int num_cities=6;

    FILE *cities_file = fopen("cities.txt", "w");

    if (cities_file == NULL)
    {
        printf("\t!!!Error: Could not open cities.txt for writing.\n");
        return;
    }

    else
    {

        for (i = 0; i < num_cities; i++)
        {
            fprintf(cities_file, "%s\n",cityName[i]);
        }

        fclose(cities_file);
        printf("\t***City list (total %d) successfully stored to cities.txt.\n", num_cities);
    }
}

void addCities(char cityName[MAX_CITIES][20])
{
    int num_cities=countCities();
    char newCity[20];

    FILE *cities_file = fopen("cities.txt", "a");

    printf("\nEnter city name: ");
    fgets(newCity,20,stdin);

    if (cities_file == NULL)
    {
        printf("\t!!!Error: Could not open cities.txt for append.\n");
        return;
    }

    else
    {
        fprintf(cities_file, "%s",newCity);

        fclose(cities_file);
        printf("\t***City list (total %d) successfully Added to cities.txt.\n", num_cities+1);
    }
}

int countCities()
{
    FILE *cities_file = fopen("cities.txt", "r");

    if (cities_file == NULL)
    {
        printf("\t!!!Error: Could not open cities.txt for count cities.\n");
        return 0;
    }

 else
    {
        int read = '\0';
        int count=0;
        while ((read = fgetc(cities_file))!= EOF)
        {
            if (read == '\n') {
            count++;
        }
        }

        fclose(cities_file);
        return count;
    }
}


void readCities(char cityName[MAX_CITIES][20])
{
    int num_cities=countCities();

    FILE *cities_file = fopen("cities.txt", "r");

    if (cities_file == NULL)
    {
        printf("\n\t!!!Error: Could not open cities.txt for writing.\n");
        return;
    }

    else
    {
        printf("\n");

        int read = '\0';
        while ((read = fgetc(cities_file))!= EOF)
        {
            printf("%c",read);
        }

        printf("\t***City list (total %d) successfully read from cities.txt.\n", num_cities);
        fclose(cities_file);
    }
}

