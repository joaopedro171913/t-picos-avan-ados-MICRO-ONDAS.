#include <xinu.h>
#include <stdio.h>

process main(void) {
    int ciclos, duracao, pausa;

    kprintf("=== CICLOS DE AQUECIMENTO ===\n");
    kprintf("Digite o numero de ciclos de aquecimento: ");
    ciclos = getnum();

    kprintf("Digite a duracao de cada ciclo (em segundos): ");
    duracao = getnum();

    kprintf("Digite o tempo de pausa entre os ciclos (em segundos): ");
    pausa = getnum();

    for (int i = 1; i <= ciclos; i++) {
        kprintf("Ciclo %d iniciado...\n", i);
        sleep(duracao);
        kprintf("Ciclo %d concluido. Pausa...\n", i);

        if (i < ciclos) {
            sleep(pausa);
        }
    }

    kprintf("Todos os ciclos de aquecimento foram concluidos!\n");

    return OK;
}
