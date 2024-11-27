#include <xinu.h>
#include <stdio.h>

void exibir_tempo(int minutos, int segundos) {
    kprintf("\rTempo configurado: %02d:%02d", minutos, segundos);
}

process main(void) {
    int minutos = 0, segundos = 0, botao;

    kprintf("Pressione os botoes de 0 a 9 para configurar o tempo do micro-ondas.\n");
    while (TRUE) {
        kprintf("\nPressione um botao (0-9 para configurar, -1 para iniciar): ");
        botao = getnum();

        if (botao == -1) {
            if (minutos == 0 && segundos == 0) {
                kprintf("\nNenhum tempo configurado. Configure o tempo antes de iniciar.\n");
            } else {
                kprintf("\nMicro-ondas iniciado com o tempo: %02d:%02d\n", minutos, segundos);
                break;
            }
        } else if (botao >= 0 && botao <= 9) {
            segundos = segundos * 10 + botao;
            if (segundos >= 60) {
                minutos += segundos / 60;
                segundos %= 60;
            }
            if (minutos > 59 || (minutos == 59 && segundos > 59)) {
                minutos = 59;
                segundos = 59;
                kprintf("\nTempo máximo atingido: 59:59\n");
            }
            exibir_tempo(minutos, segundos);
        } else {
            kprintf("\nBotao invalido. Digite um numero de 0 a 9 ou -1 para iniciar.\n");
        }
    }

    return OK;
}
