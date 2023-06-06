# Projeto - Playlists

Autor: Pedro Vinícius Oliveira Maciel Pinho

# Descrição

O programa permite a criação de músicas e playlists, e também permite 
"tocar" as músicas de uma playlist, mostrando sempre qual a próxima
música a ser tocada. As músicas e playlists criadas são armazenadas
em um arquivo de texto para execuções posteriores.

Uma limitação do programa é que não é possível ter duas músicas
diferentes com mesmo nome, mesmo que o autor das duas seja diferente.

Há um [**arquivo**](example.txt) com playlists e músicas de exemplo para
demonstrar as funcionalidades do programa.

# Documentação

A documentação doxygen do projeto está disponível na pasta [**docs/html**](docs/html)
e pode ser acessada abrindo o arquivo [**index.html**](docs/html/index.html) com
um navegador.

# Compilação

Na pasta principal do projeto, utilize os comandos a seguir:

```
cmake -B build
cmake --build build
```

# Execução

Para executar o programa, utilize o comando a seguir.
No arquivo selecionado, serão salvas as músicas e playlists
para a próxima execução.

```
./build/program <nome-do-arquivo.txt>
```
Se quiser utilizar o arquivo de exemplo, utilize:
```
./build/program example.txt
```
