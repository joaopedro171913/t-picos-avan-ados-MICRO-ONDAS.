#include <xinu.h>

process main(void) {
    int porta_microondas = 0;

    kprintf("Digite 1 para porta aberta, e 0 para porta fechada: \n");

    while (1) {
        scanf("%d", &porta_microondas);

        if (porta_microondas == 1) {
            kprintf("Porta aberta: 1\n");
        } else if (porta_microondas == 0) {
            kprintf("Porta fechada: 0\n");
        } else {
            kprintf("Nao existe essa funcao, pressione 1 (para aberta) ou 0 (para fechada)\n");
        }
    }

    return OK;
}
