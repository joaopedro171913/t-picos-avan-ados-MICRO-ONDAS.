#include <xinu.h>
#include <stdio.h>

process main(void) {
    int horas = 0, minutos = 0, segundos = 0;
    int escolha;

    kprintf("Escolha uma opcao de alimentos:\n");
    kprintf("1 - Frango\n");
    kprintf("2 - Peixe\n");
    kprintf("3 - Porco\n");
    kprintf("4 - Vaca\n");
    kprintf("5 - Lasanha\n");
    kprintf("6 - Pipoca\n");

    escolha = getnum();

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
            return OK; 
    }


    while (horas > 0 || minutos > 0 || segundos > 0) {
        kprintf("\rMicro-ondas: %02d:%02d:%02d", horas, minutos, segundos);
        sleep(1); 

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
    }

    kprintf("\nBip bip bip bip bip bip bip bip bip bip bip bip.....!!\n");

    return OK;
}
