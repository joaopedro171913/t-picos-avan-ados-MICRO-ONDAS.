#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>

process main(void) {
    int ligado = 0;
    int opcao;
    int horas = 0, minutos = 0, segundos = 0;
    int escolha;

    while (1) {
        if (ligado) {
            kprintf("\nMicro-ondas esta LIGADO. Escolha uma opcao:\n");
            kprintf("1 - Desligar\n");
            kprintf("2 - Realizar outra acao\n");
            kprintf("3 - Mostrar horas\n");
            kprintf("4 - Sair\n");
            scanf("%d", &opcao);

            if (opcao == 1) {
                ligado = 0;
                kprintf("Micro-ondas desligado.\n");
            } else if (opcao == 2) {
                kprintf("Escolha um alimento para aquecer:\n");
                kprintf("1 - Frango\n");
                kprintf("2 - Peixe\n");
                kprintf("3 - Porco\n");
                kprintf("4 - Vaca\n");
                kprintf("5 - Lasanha\n");
                kprintf("6 - Pipoca\n");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:
                        horas = 0;
                        minutos = 15;
                        segundos = 0;
                        break;
                    case 2:
                        horas = 0;
                        minutos = 10;
                        segundos = 0;
                        break;
                    case 3:
                        horas = 0;
                        minutos = 20;
                        segundos = 30;
                        break;
                    case 4:
                        horas = 0;
                        minutos = 30;
                        segundos = 0;
                        break;
                    case 5:
                        horas = 0;
                        minutos = 30;
                        segundos = 0;
                        break;
                    case 6:
                        horas = 0;
                        minutos = 0;
                        segundos = 30;
                        break;
                    default:
                        kprintf("Opcao invalida, encerrando programa!\n");
                        return 1;
                }

                while (horas > 0 || minutos > 0 || segundos > 0) {
                    kprintf("Microondas: %02d:%02d:%02d\n", horas, minutos, segundos);
                    segundos--;
                    if (segundos < 0) {
                        segundos = 59;
                        minutos--;
                    }
                    if (minutos < 0) {
                        minutos = 59;
                        horas--;
                    }
                    if (horas < 0) {
                        horas = 23;
                        minutos = 59;
                        segundos = 59;
                    }
                    sleep(1);
                }

            } else if (opcao == 3) {
                int horas_atual = (time(NULL) / 3600) % 24;
                int minutos_atual = (time(NULL) / 60) % 60;
                kprintf("Hora atual: %02d:%02d\n", horas_atual, minutos_atual);
            } else if (opcao == 4) {
                kprintf("Encerrando programa. Ate logo!\n");
                break;
            } else {
                kprintf("Opcao invalida. Tente novamente.\n");
            }
        } else {
            kprintf("\nMicro-ondas esta DESLIGADO. Escolha uma opcao:\n");
            kprintf("1 - Ligar\n");
            kprintf("2 - Sair\n");
            scanf("%d", &opcao);

            if (opcao == 1) {
                ligado = 1;
                kprintf("Micro-ondas ligado.\n");
            } else if (opcao == 2) {
                kprintf("Encerrando programa. Ate logo!\n");
                break;
            } else {
                kprintf("Opcao invalida. Tente novamente.\n");
            }
        }
    }

    return OK;
}
