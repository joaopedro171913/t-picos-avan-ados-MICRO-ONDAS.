#include <xinu.h>
#include <stdio.h>

void action_at_time(int horas_futuras, int minutos_futuros);

process main(void) {
    int horas_futuras, minutos_futuros;

    kprintf("=== PROGRAMAR AÇÃO FUTURA ===\n");
    kprintf("Digite a hora futura para iniciar (formato 24h): ");
    horas_futuras = getnum();
    
    kprintf("Digite o minuto futuro para iniciar: ");
    minutos_futuros = getnum();

    kprintf("Programado para iniciar as %02d:%02d...\n", horas_futuras, minutos_futuros);


    resume(create(action_at_time, 1024, 20, "action_at_time", 2, horas_futuras, minutos_futuros));
    
    return OK;
}

void action_at_time(int horas_futuras, int minutos_futuros) {
    while (TRUE) {
        // Simulação de tempo no Xinu (precisa ser implementado manualmente ou com funções criadas)
        int horas = 0; // Atualizar com base no tempo do sistema (ou de uma simulação)
        int minutos = 0; // Atualizar com base no tempo do sistema

        if (horas == horas_futuras && minutos == minutos_futuros) {
            kprintf("Hora programada alcançada! Iniciando micro-ondas...\n");
            break;
        }

        sleep(1); 
    }

    kprintf("Micro-ondas funcionando...\n");
    sleep(5);
    kprintf("Micro-ondas desligado. Ciclo finalizado.\n");
}
