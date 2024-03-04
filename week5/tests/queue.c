#include <stdbool.h>
#include <stdio.h>

int index = 0;

typedef struct
{
    int length;
    int numbers[length];
    int index;
} queue;

void enqueue(int list[], int value)
{
    // inserir no último lugar na fila
    list[index] = value;
    index++;
}

void dequeue(int list[], int lenght)
{
    // remover o primeiro da fila e atualizar index
    for (int i = 0; i < lenght - 1; i++)
    {
        list[i] = list[i + 1];
    }

    index--;
}

int main(void)
{
    // iniciar programa
    queue *list = malloc(sizeof(queue));

    printf("What is the lenght of the list?\n");
    scanf("%i", &lenght);

    int list[lenght];

    char operation;

    while (index < lenght)
    {
        printf("Choose a operation: E for enqueue or D for dequeue\n");
        scanf(" %c", &operation);

        if (operation == 'E')
        {
            int number;
            printf("What number you wanna add?\n");
            scanf("%i", &number);

            enqueue(list, number);
        }
        else if (operation == 'D')
        {
            if (index >= 0)
            {
                dequeue(list, lenght);
            }
        }
        else
        {
            printf("invalid operation\n");
            return 1;
        }

        if (index != lenght)
        {
            char choose;
            printf("Wanna add more? y or n\n");
            scanf(" %c", &choose);

            if (choose == 'n')
            {
                break; // sair do loop se 'n' for escolhido
            }
        }
    }
    printf("See the final list:\n");
    for (int i = 0; i < lenght; i++)
    {
        printf(" %i ", list[i]);
    }
    printf("\n");
}
