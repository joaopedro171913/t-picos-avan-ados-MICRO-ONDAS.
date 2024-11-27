#include <xinu.h>
#include <stdio.h>

process main(void) {
    int porta_microondas = 0;
    int luz_microondas = 0;

    kprintf("Digite 1 para porta aberta e 0 para porta fechada: \n");

    while (1) {
        scanf("%d", &porta_microondas);

        if (porta_microondas == 1) {
            luz_microondas = 1;
            kprintf("Porta aberta: 1\n");
            kprintf("Luz acesa: %d\n", luz_microondas);
        } else if (porta_microondas == 0) {
            luz_microondas = 0;
            kprintf("Porta fechada: 0\n");
            kprintf("Luz apagada: %d\n", luz_microondas);
        } else {          
            kprintf("Nao existe essa funcao, pressione 1 (para aberta) ou 0 (para fechada)\n");
        }

        sleep(1); // Pequeno atraso para não sobrecarregar o loop
    }

    return OK;
}
