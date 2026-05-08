# laboratorio-programacao-avancada7

## 1. Objetivo
Exercitar a manipulação de arquivos e dados binários através da leitura de um arquivo PNG para extrair metadados, como o tamanho e o tipo de cada bloco (chunk), além de informações específicas de largura e altura da imagem.

## 2. Estrutura de Dados
### 2.1 O Cabeçalho do Chunk
Cada bloco no PNG começa com um cabeçalho fixo de 8 bytes, contendo o tamanho dos dados e o tipo do bloco. É essencial usar o atributo packed para garantir que o mapeamento binário seja exato.
```c
// read_png.h
struct png_chunk_hdr {
    int length;       // 4 bytes: Tamanho do "Chunk Data"
    char type[5];     // 4 bytes: Tipo do chunk (IHDR, IDAT, etc.)
} __attribute__ ((packed));
```
### 2.2 Dados do IHDR
O primeiro bloco obrigatório (IHDR) contém as propriedades físicas da imagem. Campos menores que 4 bytes devem ser declarados como unsigned char para respeitar o tamanho de 1 byte cada.
```c
struct png_ihdr {
    int width;                // 4 bytes
    int height;               // 4 bytes
    unsigned char bit_depth;  // 1 byte
    unsigned char color_type; // 1 byte
    unsigned char compression;// 1 byte
    unsigned char filter;     // 1 byte
    unsigned char interlace;  // 1 byte
} __attribute__ ((packed));
```
## 3. Processamento e Navegação
### 3.1 Ordem de Bytes (Endianness)
Todos os números inteiros no arquivo PNG (como length, width e height) estão no formato big-endian. Devem ser convertidos para o formato local da máquina usando a função ntohl.
### 3.2 Algoritmo de Leitura
- **Pulo Inicial**: Deve-se saltar os primeiros 8 bytes do arquivo, que correspondem à assinatura fixa do PNG.
- **Leitura Sequencial:** O programa lê o `png_chunk_hdr`, imprime os dados e utiliza o campo `length` para saltar o conteúdo e o CRC (4 bytes) usando `fseek`.
- **Fim do Loop:** A leitura encerra ao encontrar o tipo de chunk "`IEND`" ou o fim do arquivo.
## 4. Fluxo de Execução e Interface
### 4.1 Parâmetros de Entrada
O executável deve receber o nome do arquivo PNG via terminal. `./program Teste.png`
### 4.2 Saída Esperada

O programa lista os chunks sequencialmente, detalhando largura e altura apenas para o IHDR:
```bash
Lendo chunk 1:
 --> Tamanho: 13
 --> Tipo: IHDR
 --> Largura: 160
 --> Altura: 80
Lendo chunk 2:
 --> Tamanho: 6
 --> Tipo: bKGD
...
```

## 5. Limpeza

Execute:

```bash
make clean
```