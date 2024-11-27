#include <xinu.h>

shellcmd xsh_respiracao(int argc, char *argv[]) {
    int tempo_operacao = 10;
    int pausa = 5;
    int ciclos = 3;

    kprintf("=== INICIANDO FUNCAO DE RESPIRACAO ===\n");

    for (int i = 1; i <= ciclos; i++) {
        kprintf("Operacao continua por %d segundos...\n", tempo_operacao);
        sleep(tempo_operacao);
        kprintf("Pausa para respiracao por %d segundos...\n", pausa);
        sleep(pausa);
    }

    kprintf("Todos os ciclos de respiracao foram concluidos.\n");

    return 0;
}
