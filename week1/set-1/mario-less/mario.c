#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 1. Declarar a variável 'tall'
    int tall;

    do
    {
        // 2. Receber a altura
        tall = get_int("Height: ");
    }
    while (tall < 1 || tall > 8); // 3. Enquanto a altura for menor que 1 ou maior que 8, repetir o passo 2

    // 4. Enquanto 'l' for menor ou igual a 'tall'
    for (int l = 1; l <= tall; l++)
    {
        // 5. Calcular o número de espaços como 'tall' - 'l'
        int space = tall - l;

        // 6. Enquanto 'space' for maior que 0, imprimir um espaço
        for (; space > 0; space--)
        {
            printf(" ");
        }

        // 7. Enquanto 'b' for menor ou igual a 'l', imprimir "#"
        for (int b = 1; b <= l; b++)
        {
            printf("#");
        }

        // 8. Imprimir uma nova linha
        printf("\n");
    }
}
