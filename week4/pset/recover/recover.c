#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

bool allZero(unsigned char buffer[]);
bool isNew(unsigned char buffer[]);

int main(int argc, char *argv[])
{
    // se os argumentos não estiverem corretos printar a usabilidade e retornar 1
    // se tiver mais ou menos de 2 argumentos
    if (argc != 2)
    {
        printf("Correct usage: ./program [name-of-raw-file]\n");
        return 1;
    }

    // receber na linha de comando o nome do arquivo
    char *filename = argv[1];

    // abrir o arquivo do card para leitura ( fopen )
    FILE *rawfile = fopen(filename, "r");

    // se o arquivo nao puder ser aberto ( == NULL ) printar e retornar 1
    if (rawfile == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    // ler um bloco ( 512 bits ) do arquivo aberto num buffer até chegar no fim do raw ( fread retornar 0 )
    unsigned char buffer[BLOCK_SIZE];

    int file_num = 0;
    char imagename[8];

    FILE *image = NULL;

    while (fread(&buffer, sizeof(char), BLOCK_SIZE, rawfile))
    {

        // se os primeiros bits forem os endereços

        if (isNew(buffer))
        {
            if (image != NULL)
            {
                fclose(image);
            }

            // abrir arquivo de imagem novo

            // gerar arquivos com nomes começando com 000.jpg e ir contando a cada um usar sprintf()

            sprintf(imagename, "%03i.jpg", file_num);
            image = fopen(imagename, "w");

            file_num++;
        }

        if (image != NULL)
        {
            fwrite(&buffer, sizeof(char), BLOCK_SIZE, image);
        }
    }

    if (image != NULL)
    {
        fclose(image);
    }

    fclose(rawfile);
}
bool allZero(unsigned char buffer[])
{
    // porcorrer tudo
    // se achar um valor diferente de 0 retorna false
    // se nao retorna true
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        if (buffer[i] != 0)
        {
            return false;
        }
    }

    return true;
}
bool isNew(unsigned char buffer[])
{
    // procura se os primeiros são os padrões
    // se sim retorna true
    // senao retorna false
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
    {
        return true;
    }
    return false;
}
