#include <stdio.h>
#include <cs50.h>

int calculateYears(long numberLhamas, long goalLhamas);

int main(void){
    //perguntar numero inicial de lhamas
    long numberLhamas, goalLhamas;

    do {
        numberLhamas = get_long("How many lhamas you have? ");
        if ( numberLhamas < 9 ){
            printf("If you start with less than 9 Llamas the population will be stagnant in less than a year! Please re-type\n\n");
        }
    } while (numberLhamas < 9);

    //perguntar qual a meta de lhamas
    do {
        goalLhamas = get_long("What's the number of lhamas that you want reach? ");
        if ( goalLhamas <= numberLhamas ){
            printf("Type a number bigger then than the actual number of llamas! We want GROWTH!!!\n");
        }
    } while (goalLhamas < numberLhamas);

    int years = calculateYears(numberLhamas, goalLhamas);
    printf("Years: %i\n", years);

}

int calculateYears(long numberLhamas, long goalLhamas){

    int years = 0;

    while (numberLhamas < goalLhamas){

        long newLhamas = numberLhamas/3;
        long passLhamas = numberLhamas/4;

        numberLhamas = numberLhamas + (newLhamas - passLhamas);

        years ++;
    }
    return years;

}
