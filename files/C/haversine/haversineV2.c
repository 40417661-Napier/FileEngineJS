#include "myfunctions.h"

int main(int argc, char **argv)
{
    char desc[1000];
    int runningSize = 1;
    char latBuffer[50];
    char longBuffer[50];
    // double *distances = NULL;
    // distances = realloc(distances,(sizeof(double)*2)*runningSize);
    printf("Please give a description of the journey: \n");
    fgets(desc, 1000, stdin);
    removeNewLine(desc);

    typedef struct coord{
        double x;
        double y;
    }coord;

    coord *c = malloc((sizeof(coord)*2)*runningSize);

    while (1)
    {

        printf("Enter Latitude followed by Longitude:\n");
        printf("Latitude: ");
        fgets(latBuffer, 50, stdin);
        printf("\nLongitude:");
        fgets(longBuffer, 50, stdin);
        printf("\n");
        removeNewLine(latBuffer);
        removeNewLine(longBuffer);

        c.x = atof(latBuffer);
        c.y = atof(longBuffer);
// to be continued
        runningSize += 1;
    }
}
