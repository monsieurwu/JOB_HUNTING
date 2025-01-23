#include "hash_table_linear_probing.h"

int main(void)
{
    
    hash_table_t hash_table;
    init_hash_table(&hash_table);

    insert(&hash_table, 27, 5000);
    insert(&hash_table, 17, 6000);  
    insert(&hash_table, 345, 7000);
    insert(&hash_table, 99, 8000);
    insert(&hash_table, 37, 9000);  
    insert(&hash_table, 1, 10000);
    insert(&hash_table, 33, 10000);

    printf("\n");
    printf("员工27: %d\n", search(&hash_table, 27));
    printf("员工17: %d\n", search(&hash_table, 17));
    printf("员工345: %d\n", search(&hash_table, 345));
    printf("员工99: %d\n", search(&hash_table, 99));
    printf("员工37: %d\n", search(&hash_table, 37));
    printf("员工1: %d\n", search(&hash_table, 1));
    printf("员工33: %d\n", search(&hash_table, 33));
    
    return 0;
}