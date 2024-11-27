#include <xinu.h>
#include <stdlib.h>

process main(void) {
    int temperatura = 40; 
    int limite_superior = 80; 
    int limite_inferior = 40; 

    kprintf("=== INICIANDO FUNCAO DE REFRIGERACAO ===\n");

    while (1) {
        temperatura += rand() % 10; 
        kprintf("Temperatura atual: %d°C\n", temperatura);

        if (temperatura >= limite_superior) {
            kprintf("Temperatura alta! Iniciando resfriamento...\n");
            while (temperatura > limite_inferior) {
                temperatura -= 5;
                kprintf("Refrigerando... Temperatura atual: %d°C\n", temperatura);
                sleep(1);
            }
            kprintf("Temperatura segura alcancada. Pronto para operar novamente.\n");
            break;
        }

        sleep(1);
    }

    return OK;
}
