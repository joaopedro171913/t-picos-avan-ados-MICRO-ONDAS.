#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>

process main(void) {

    int ligado = 1;
    int temperatura = 30;
    int klystron = 120;

    kprintf("Micro-ondas ligado, monitorando temperatura...\n");

    while (1) {
        temperatura += (rand() % 5);

        if (temperatura >= klystron) {
            ligado = 0;
            kprintf("Temperatura alta, (%d°C) desligando micro-ondas\n", temperatura);
            break;
        }

        kprintf("Temperatura atual: %d°C\n", temperatura);
        sleep(2);
    }

    kprintf("Aguardando resfriamento...\n");

    while (temperatura > 30) {
        temperatura -= 5;
        kprintf("Temperatura atual: %d°C\n", temperatura);
        sleep(2);
    }

    kprintf("Temperatura segura, micro-ondas pode ser ligado novamente.\n");

    return OK;
}
