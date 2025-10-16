#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30

void storeCities(char cityName[MAX_CITIES][20]); //this have to remove
void addCities(char cityName[MAX_CITIES][20],int distance[MAX_CITIES][MAX_CITIES]);
int countCities();
void readCities(char cityName[MAX_CITIES][20]);

void storeDistances(int distance[MAX_CITIES][MAX_CITIES]);
void addDistances(int distance[MAX_CITIES][MAX_CITIES],char cityName[MAX_CITIES][20]);
void readDistances(int distance[MAX_CITIES][20]);





int main()
{
    char cityName[MAX_CITIES][20];

    strcpy(cityName[0], "Colombo");
    strcpy(cityName[1], "Kandy");
    strcpy(cityName[2], "Galle");
    strcpy(cityName[3], "Jaffna");
    strcpy(cityName[4], "Anuradhapura");


    int distance[30][30] =
    {
        {0, 100, 200, 300, 400},
        {100, 0, 150, 250, 350},
        {200, 150, 0, 120, 220},
        {300, 250, 120, 0, 110},
        {400, 350, 220, 110, 0}
    };

    storeCities(cityName);//this have to remove
    storeDistances(distance);//this have to remove

    readCities(cityName);
    addCities(cityName,distance);
    readCities(cityName);

    storeDistances(distance);

    return 0;
}

void storeCities(char cityName[MAX_CITIES][20]) //this have to remove
{
    int i;
    int num_cities=5;

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

void addCities(char cityName[MAX_CITIES][20],int distance[MAX_CITIES][MAX_CITIES])
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

    //addDistances
    addDistances(distance,cityName);
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
            if (read == '\n')
            {
                count++;
            }
        }

        fclose(cities_file);
        return count;
    }
}


void readCities(char cityName[MAX_CITIES][20])
{
    int num_cities = countCities();
    if (num_cities == 0)
    {
        printf("\t***City list is empty.\n");
        return;
    }

    FILE *cities_file = fopen("cities.txt", "r");

    if (cities_file == NULL)
    {
        printf("\n\t!!!Error: Could not open cities.txt for reading.\n");
        return;
    }

    for (int i = 0; i < num_cities; i++)
    {
        fgets(cityName[i], MAX_CITIES, cities_file);

        printf("%d. %s", i + 1, cityName[i]);//new line was already added due to fgets function
    }

    printf("\t***City list (total %d) successfully read from cities.txt.\n", num_cities);
    fclose(cities_file);
}

void storeDistances(int distance[MAX_CITIES][MAX_CITIES])
{
    int num_cities=countCities();

    FILE *distances_file = fopen("distances.txt", "w");

    if (distances_file == NULL)
    {
        printf("\t!!!Error: Could not open distances.txt for writing.\n");
        return;
    }

    else
    {

        for (int i = 0; i < num_cities; i++)
        {
            for (int j = 0; j < num_cities; j++)
            {

                fprintf(distances_file, "%d ", distance[i][j]);
            }

            fprintf(distances_file, "\n");
        }

        fclose(distances_file);
        // printf("\t***City list (total %d) successfully stored to cities.txt.\n", num_cities);
    }

}

void addDistances(int distance[MAX_CITIES][MAX_CITIES],char cityName[MAX_CITIES][20])
{
    int num_cities=countCities()-1; // Since we add a new city name, countCities gives the new count. in addDistance we need previous count.

    FILE *distances_file = fopen("distances.txt", "r");

    if (distances_file == NULL)
    {
        printf("\t!!!Error: Could not open distances.txt for Adding.\n");
        return;
    }

    else
    {


        for(int i=0; i<num_cities; i++)
        {
            for(int j=0; j<num_cities; j++)
            {
                (fscanf(distances_file, "%d", &distance[i][j]));
            }
        }

        int tempDistances[num_cities]; //

        for(int i=0; i<num_cities && cityName[i] != NULL; i++)
        {

            printf("\nEnter distance to %s :",&cityName[i]);
            scanf("%d",&tempDistances[i]);

            distance[num_cities][i]=tempDistances[i];
            distance[i][num_cities]=tempDistances[i];//to create symmetrical matrix
        }
        distance[num_cities][num_cities]=0; //same city

        storeDistances(distance);

        fclose(distances_file);
        // printf("\t***City list (total %d) successfully stored to cities.txt.\n", num_cities);
    }
}
