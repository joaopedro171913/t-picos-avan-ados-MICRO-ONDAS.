#include <xinu.h>
#include <stdio.h>

process main(void) {
    int tempo_total, cancelar = 0;
    
    kprintf("Digite o tempo de cozimento em segundos: ");
    tempo_total = getnum();

    kprintf("Pressione 1 e ENTER para cancelar o cozimento.\n");

    for (int i = tempo_total; i > 0; i--) {
        kprintf("\rTempo restante: %02d:%02d", i / 60, i % 60);
        
        sleep(1);
        if (cancelar == 1) {
            kprintf("\nCozimento cancelado.\n");
            break;
        }

        if (i % 1 == 0) { 
            kprintf("\nPressione 1 para cancelar...\n");
            char botao = getch(); 

            if (botao == '1') {
                cancelar = 1;
                break;
            }
        }
    }

    if (cancelar == 0) {
        kprintf("\nCozimento finalizado.\n");
    }

    return OK;
}
