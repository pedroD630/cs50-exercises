// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // confere se o user digitou o numero certo de parametros
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // abre o arquivo ja existente no mode de leitura
    FILE *input = fopen(argv[1], "r");
    // se o ponteiro para o arquivo estiver vazio segnifica que ele não existe
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // cria um arquivo de saída no modo escrita
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // recebe o valor pelo qual multiplicar os samples
    float factor = atof(argv[3]);

    // Copia o cabeçalho de 44 pixels passando ( onde ler, bytes do que ler, quantos bytes ler a cada vez, pointer de arquvo para
    // ler)
    uint8_t header[44];
    fread(&header, HEADER_SIZE, 1, input);
    fwrite(&header, HEADER_SIZE, 1, output);

    // Cria uma variavel de 16-bits para armazenar cada sample, já que WAV usa 2bytes para cada sample
    int16_t samples;

    // ler cada sample enquanto fread for != 0, ou seja, true e já executa a função lendo o sample para o buffer
    while (fread(&samples, sizeof(uint16_t), 1, input))
    {
        // Multiplica o sample armazenado no buffer pelo factor
        samples = samples * factor;

        // Escreve o sample multiplicado no arquivo de escrita
        fwrite(&samples, sizeof(uint16_t), 1, output);

    } // não prcisamos nos preocupar com salvar onde estamos no arquivo e onde "voltar" para ler porque o fread
    // nunca lê uma parte que já leu a menos que peçamos para fazer isso usando outra função

    // fecha os arquivos para que não sejam utilizados simultaneamente por outro programa
    fclose(input);
    fclose(output);
}
