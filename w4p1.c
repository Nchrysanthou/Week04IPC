// Cstd macro
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
//macros
#define MAX_ITEMS 10

int main(void)
{
    //vars
    const double MIN = 500.00, MAX = 400000.00;
    int forcastedItems;
    double income;
    bool valid = false;

    double Cost[MAX_ITEMS], Finance[MAX_ITEMS];
    int Prio[MAX_ITEMS];
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    // get income
    do
    {
        printf("Enter your monthly NET income: ");
        scanf("%lf", &income);
        if (income >= MIN && income <= MAX)
        {
            valid = true;
        }
        else if (income < MIN)
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        else
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");

    } while (!valid);

    // reset condition
    valid = false;

    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%lf", &forcastedItems);
        if (forcastedItems > 0 && forcastedItems < MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            valid = true;
        }
    } while (!valid);

    return 0;
}

/* Example Output:

Enter your monthly NET income: $0
ERROR: You must have a consistent monthly income of at least $500.00
Enter your monthly NET income: $500000
ERROR: Liar! I'll believe you if you enter a value no more than $400000.00
Enter your monthly NET income: $6500.50
How many wish list items do you want to forecast?: 0
ERROR: List is restricted to between 1 and 10 items.
How many wish list items do you want to forecast?: 11
ERROR: List is restricted to between 1 and 10 items.
How many wish list items do you want to forecast?: 3
Item-1 Details:
 Item cost: $39030.15
 How important is it to you? [1=must have, 2=important, 3=want]: 0
 ERROR: Value must be between 1 and 3
 How important is it to you? [1=must have, 2=important, 3=want]: 4
 ERROR: Value must be between 1 and 3
 How important is it to you? [1=must have, 2=important, 3=want]: 1
 Does this item have financing options? [y/n]: N
 ERROR: Must be a lowercase 'y' or 'n'
 Does this item have financing options? [y/n]: Y
 ERROR: Must be a lowercase 'y' or 'n'
 Does this item have financing options? [y/n]: k
 ERROR: Must be a lowercase 'y' or 'n'
 Does this item have financing options? [y/n]: n
Item-2 Details:
 Item cost: $99.99
 ERROR: Cost must be at least $100.00
 Item cost: $1200000
 How important is it to you? [1=must have, 2=important, 3=want]: 3
 Does this item have financing options? [y/n]: y
Item-3 Details:
 Item cost: $350500.25
 How important is it to you? [1=must have, 2=important, 3=want]: 2
 Does this item have financing options? [y/n]: n
Item Priority Financed Cost
---- -------- -------- -----------
 1 1 n 39030.15
 2 3 y 1200000.00
 3 2 n 350500.25
---- -------- -------- -----------
 $ 1589530.40
Best of luck in all your future endeavours!
*/