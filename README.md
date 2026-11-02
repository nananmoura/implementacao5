# Sincronização do Metrô (sync_car)

Infraestrutura de Software, Implementação 4. Autora: mfomd.
Sistema: Ubuntu 22.04 (WSL2), gcc 11.4.0, make 4.3.

## Arquivos

- sync_car.h: struct station e protótipos das quatro funções.
- sync_car.c: station_init, station_load_car, station_wait_for_car, station_on_board.
- Makefile: compilação e limpeza.
- evidencias.log: gravação do terminal com compilação e testes.

O arquivo de teste (teste.c) não vem no pacote. Para testar, coloque-o na mesma pasta do código.

## Compilar

Com o teste salvo como teste.c na pasta:

    make clean
    make

Gera o executável sync_car. Sem o teste.c na pasta, o make só compila sync_car.o.

## Executar

    ./sync_car

Saída esperada: várias linhas de car entering/departed e, no final, Looks good!

## Limpar

    make clean