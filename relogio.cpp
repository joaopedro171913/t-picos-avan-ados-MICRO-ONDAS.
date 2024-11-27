#include <xinu.h>
#include <stdio.h>

process main(void) {
    int porta_aberta = 0;
    int cozinhando = 0;
    int tempo_restante = 0;
    int acao;

    while (1) {
        if (porta_aberta == 1) {
            kprintf("\rPorta aberta. Feche a porta para exibir o relogio.");
            sleep(60);
        } else if (cozinhando == 1) {
            if (tempo_restante > 0) {
                kprintf("\rCozinhando... Tempo restante: %02d:%02d", tempo_restante / 60, tempo_restante % 60);
                sleep(60);
                tempo_restante--;
            } else {
                kprintf("\rCozimento finalizado! Bip! Bip! Bip!");
                sleep(180);
                cozinhando = 0;
            }
        } else {
            int horas = 12;
            int minutos = 0;

            kprintf("\rRelogio: %02d:%02d", horas, minutos);
            sleep(60);
        }

        kprintf("\nDigite uma acao: 0 = fechar porta, 1 = abrir porta, 2 = iniciar cozimento, 3 = sair:\n");
        acao = getchar();

        if (acao == '0') {
            porta_aberta = 0;
        } else if (acao == '1') {
            porta_aberta = 1;
        } else if (acao == '2' && porta_aberta == 0) {
            kprintf("Digite o tempo de cozimento em segundos: ");
            tempo_restante = getchar() - '0';
            cozinhando = 1;
        } else if (acao == '3') {
            kprintf("Desligando o micro-ondas. Ate logo!\n");
            break;
        } else {
            kprintf("Acao invalida. Tente novamente.\n");
        }
    }

    return OK;
}
