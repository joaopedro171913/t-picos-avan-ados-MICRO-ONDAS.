#include <xinu.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool portaAberta;
    bool luzAcesa;
    bool cozinhando;
} Microondas;

void abrirPorta(Microondas *micro);
void fecharPorta(Microondas *micro);
void iniciarCozimento(Microondas *micro, int tempo);
void pararCozimento(Microondas *micro);

void abrirPorta(Microondas *micro) {
    if (micro->cozinhando) {
        kprintf("Pare o cozimento antes de abrir a porta!\n");
    } else {
        micro->portaAberta = true;
        micro->luzAcesa = true;
        kprintf("Porta aberta. Luz acesa.\n");
    }
}

void fecharPorta(Microondas *micro) {
    if (micro->portaAberta) {
        micro->portaAberta = false;
        micro->luzAcesa = false;
        kprintf("Porta fechada. Luz apagada.\n");
    } else {
        kprintf("A porta ja esta fechada.\n");
    }
}

void iniciarCozimento(Microondas *micro, int tempo) {
    if (micro->portaAberta) {
        kprintf("Feche a porta antes de iniciar o cozimento.\n");
    } else {
        micro->cozinhando = true;
        micro->luzAcesa = true;
        kprintf("Micro-ondas esta cozinhando por %d segundos. Luz acesa.\n", tempo);

        for (int i = 0; i < tempo; i++) {
            kprintf("Cozinhando... %d segundos restantes.\n", tempo - i);
            sleep(1); 
        }

        pararCozimento(micro);
    }
}

void pararCozimento(Microondas *micro) {
    if (micro->cozinhando) {
        micro->cozinhando = false;
        micro->luzAcesa = false;
        kprintf("Cozimento finalizado. Luz apagada.\n");
    } else {
        kprintf("O micro-ondas não está cozinhando no momento.\n");
    }
}

process main(void) {

    Microondas micro = {false, false, false};

    abrirPorta(&micro);      
    fecharPorta(&micro);  
    iniciarCozimento(&micro, 10);
    abrirPorta(&micro);

    return OK;
}
