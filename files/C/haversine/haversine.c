#include "myfunctions.h"

int main(int argc, char **argv)
{
    char buffer[20];
    char desc[1000];
    printf("Please give a description of the journey: \n");
    fgets(desc, 1000, stdin);
    removeNewLine(desc);
    printf("How many co-ordinates do you want to enter?\n");
    fgets(buffer, 20, stdin);
    removeNewLine(buffer);
    int iterations = atoi(buffer); // n - 1 when calculating distnaces between vertex is done in < iterations (for loop)
    double calculation = 0;
    double distances[iterations][2];
    char latbuffer[100];
    char longBuffer[100];

    for (int i = 0; i < iterations; i++)
    {

        printf("Enter Latitude followed by Longitude:\n");
        printf("Latitude: ");
        fgets(latbuffer, 100, stdin);
        printf("\nLongitude:");
        fgets(longBuffer, 100, stdin);
        printf("\n");
        removeNewLine(latbuffer);
        removeNewLine(longBuffer);
        distances[i][0] = atof(latbuffer);
        distances[i][1] = atof(longBuffer);
    }

    for (int i = 0; i < iterations - 1; i++)
    {
        calculation += dist(distances[i][0], distances[i][1], distances[i + 1][0], distances[i + 1][1]);
    }
    printf("%s\n", desc);
    printf("dist: %.1f km (%.1f mi.)\n", calculation, calculation / 1.609344);
}
