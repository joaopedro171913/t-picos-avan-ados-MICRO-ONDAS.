#include <xinu.h>
#include <stdio.h>
#include <math.h>

process main(void) {
    float temperatura_inicial = 25.0; 
    float temperatura_maxima = 100.0; 
    float fator_aquecido = 0.1;       
    int duracao_total = 60;          
    int intervalo = 1;            
    float temperatura_atual = temperatura_inicial;

    kprintf("=== CURVA DE AQUECIMENTO ===\n");
    kprintf("Temperatura inicial: %.2f°C\n", temperatura_inicial);

    for (int t = 0; t <= duracao_total; t += intervalo) {
        temperatura_atual = temperatura_inicial + 
                            (temperatura_maxima - temperatura_inicial) * 
                            (1 - exp(-fator_aquecido * t));

        kprintf("Tempo: %2d s | Temperatura: %.2f°C\n", t, temperatura_atual);

        if (temperatura_atual >= temperatura_maxima) {
            kprintf("A temperatura maxima foi atingida!\n");
            break;
        }

        sleep(intervalo); 
    }

    kprintf("Curva de aquecimento concluida.\n");
    return OK;
}
