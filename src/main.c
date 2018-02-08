#include <stdio.h>

int main()
{
    // Single Dimensional Arrays
    printf("Single Dimesnional Array Access\n");
    int single_dimension_array[8] = {0,1,2,3,4,5,6,7};
    //*p_single_dimension_array = &single_dimension_array[0]
    int *p_single_dimension_array = single_dimension_array;
    // printing using array indexes
    for(int i = 0 ; i < 8; i++)
    {
        printf("%i " , single_dimension_array[i]);
    }
    printf("\n");
    for(int i = 0 ; i < 8; i++)
    {
        printf("%i " , *( p_single_dimension_array + i));
    }
    printf("\n");
    
    // Mulit Dimensional Arrays
    printf("Multi Dimesnional Array Access\n");
    int two_dimension_array[2][4] = {{0,1,2,3},{4,5,6,7}}; // row major form
    // columns are 4 wide, aka "stride"
    // 0, 1, 2, 3
    // 4, 5 ,6, 7
    
    // Looks like this in memory
    // 0, 1, 2, 3, | 4, 5 ,6, 7
    
    int *p_two_dimension_array = (int*) two_dimension_array;
    // printing using array indexes
    for(int i = 0 ; i < 2; i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            printf("%i " , two_dimension_array[i][j]);
        }
    }
    printf("\n");
    // p_two_dimension_array is element 0
    // add length of row * row number to access first element of that row
    // add column number j to get offset to that column
    // two_dimension_array[1, 1] is p_two_dimension_array + (1 * ROW_LENGTH) + 1
    // 0, 1, 2, 3, | 4, 5 ,6, 7
    for(int i = 0 ; i < 2; i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            printf("%i " , *( p_two_dimension_array + (i * 4) + j));
        }
    }
    printf("\n");
    
    printf("Multi Dimesnional Array Access with single dimensional array\n");
    p_single_dimension_array = (int*) two_dimension_array;
    for(int i = 0 ; i < 8; i++)
    {
        // using an array pointer like an array
        printf("%i " , p_single_dimension_array[i]);
    }
    printf("\n");
    return 0;
}
