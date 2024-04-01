#include <stdio.h>

int main()
{
    int d;
    scanf("%d", &d);

    int north, east, south, west;
    west = d%10;
    south = (d/10)%10;
    east = (d/100)%10;
    north = d/1000;
    // printf("Danger levels: %d %d %d %d\n", north, east, south, west);
    
    int stronger = 0;
    int sum = north + east + south + west;
    printf("Captain CJ, we must go towards ");
    if(north > south)
    {
        printf("north");
        stronger += north;
    }
    else
    {
        printf("south");
        stronger += south;
    }
    if(east > west)
    {
        printf("east");
        stronger += east;
    }
    else
    {
        printf("west");
        stronger += west;
    }
    printf("\n");
    // printf("strong: %d, sum: %d\n",stronger,sum);
    float average = (float)stronger/sum;
    printf("The strength of wind is only %.2f captain!\n",average);
}