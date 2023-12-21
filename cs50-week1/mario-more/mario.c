#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //recebe altura
    int tall;
    do {

        tall = get_int("Height: ");

    } while (tall < 1 || tall > 8); //evita que seja um numero negativo ou muito grande

    //cria um linha
    for (int lines = 1; lines <= tall; lines++)
    {
        //numa mesma linha devem ter espacoes e blocos sendo que espacos vem antes dos blocos
        //espacos = tall - line
        //os espacos sao exibidos em todas as ocasioes menos quando tall - line = 0
        for (int spaces = tall-lines; spaces>0; spaces --)
        {
            printf(" ");
        }
        //print # alina na direita
        for (int blocks = 1; blocks<=lines; blocks++)
        {
            //se blocks == lines -1 ( ultimo bloco da linha )
                //print "#  "
            if (blocks == lines){
                printf("#  ");
            } else {
                printf("#");
            }
        }
        //print # alinhado na esquerda
        for (int blocks = 1; blocks <= lines; blocks ++)
        {
            printf("#");
        }
        //print "\n" e gera uma nova linha
        //soma +1 ao loop de linha e repete ate que tenha a altura
        printf("\n");
    }
}
