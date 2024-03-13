#include <stdio.h>

#define NUM_OF_FLOORS 9
#define NUM_OF_FLATS_ON_FLOOR 4

void input(int *);
int calc_entr(int);
int calc_floor(int);
void output(int, int);

int main(void)
{
    int flat, entrance, floor;
    input(&flat);
    entrance = calc_entr(flat);
    floor = calc_floor(flat);
    output(entrance, floor);
    return 0;
}

void input(int *flat)
{
    printf("Enter number of flat: ");
    scanf("%d", flat);
}

int calc_entr(int flat)
{
    int entrance = (flat - 1) / (NUM_OF_FLATS_ON_FLOOR * NUM_OF_FLOORS) + 1;
    return entrance;
}

int calc_floor(int flat)
{
    int index_of_flat_in_entr = (flat - 1) % (NUM_OF_FLATS_ON_FLOOR * NUM_OF_FLOORS);
    int floor = index_of_flat_in_entr / NUM_OF_FLATS_ON_FLOOR + 1;
    return floor;
}

void output(int entrance, int floor)
{
    printf("Entrance: %d , floor: %d \n", entrance, floor);
}