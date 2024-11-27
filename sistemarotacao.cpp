#include <xinu.h>

shellcmd xsh_microondas(int argc, char *argv[]) {
    int rotacao, tempo, horas, minutos, segundos;

    kprintf("Digite o valor das horas: ");
    scanf("%d", &horas);
    kprintf("Digite o valor dos minutos: ");
    scanf("%d", &minutos);
    kprintf("Digite o valor de segundos: ");
    scanf("%d", &segundos);

    kprintf("Digite o tempo de rotação em segundos: ");
    scanf("%d", &rotacao);

    for (tempo = 0; tempo < 5; tempo++) { 
        kprintf("Prato esta girando\n");
        sleep(rotacao); 
    }

    while (horas > 0 || minutos > 0 || segundos > 0) {
        kprintf("Prato esta girando\n");
        kprintf("Micro-ondas: %02d:%02d:%02d\n", horas, minutos, segundos);

        segundos--;
        if (segundos < 0) {
            segundos = 59;
            minutos--;
            sleep(1);
        }
        if (minutos < 0) {
            minutos = 59;
            horas--;
            sleep(1);
        }
        if (horas < 0) {
            horas = 23;
            minutos = 59;
            sleep(1);
        }
    }

    kprintf("Bip bip bip bip bip bip bip bip!!!\n");
    return 0;
}
