#include <xinu.h>

shellcmd xsh_microondas(int argc, char *argv[]) {
    int horas, minutos, segundos;

    kprintf("Digite o valor das horas: ");
    scanf("%d", &horas);
    kprintf("Digite o valor dos minutos: ");
    scanf("%d", &minutos);
    kprintf("Digite o valor de segundos: ");
    scanf("%d", &segundos);

    while (horas > 0 || minutos > 0 || segundos > 0) {
        kprintf("Micro-ondas: %02d:%02d:%02d\n", horas, minutos, segundos);

        segundos--;
        if (segundos < 0) {
            segundos = 59;
            minutos--;
        }
        if (minutos < 0) {
            minutos = 59;
            horas--;
        }
        if (horas < 0) {
            horas = 23;
            minutos = 59;
        }

        sleep(1);
    }

    kprintf("Bip bip bip bip bip bip bip bip!!!\n");

    return 0;
}
