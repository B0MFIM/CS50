#include <stdio.h>
#include <stdint.h>

/* Esse código foi um exemplo de como podemos copiar o conteúdo de um arquivo
   para outro arquivo. Ele mostra como podemos abrir um arquivo, ler o conteúdo
   do arquivo e escrever o conteúdo em outro arquivo. */

// Definir um tipo BYTE para representar um byte de dados
typedef uint8_t BYTE;
// uint8_t é um tipo de dado definido em stdint.h que representa um byte de dados

int main(int argc, char *argv[])
{
    // Declarar um ponteiro para um arquivo de origem
    FILE *src = fopen(argv[1], "rb");
    // Declarar um ponteiro para um arquivo de destino
    FILE *dst = fopen(argv[2], "wb");

    // Variável para armazenar um byte de dados
    BYTE b;

    // Ler um byte de dados do arquivo de origem e escrever no arquivo de destino, até o final do arquivo
    while(fread(&b, sizeof(b), 1, src) != 0)
    {
        // Escrever o byte de dados no arquivo de destino
        fwrite(&b, sizeof(b), 1, dst);
    }

    // Fechar os arquivos
    fclose(dst);
    fclose(src);
}