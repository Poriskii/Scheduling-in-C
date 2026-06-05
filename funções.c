#include <stdio.h>
#include <string.h>
#include "dados.h"


void limparBuffer() {
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

void removerEnter(char texto[]) {

    texto[strcspn(texto, "\n")] = '\0';
}



void Dados() {

    Consulta consulta;

    char resposta;

    printf("Digite o nome do paciente: ");
    fgets(consulta.paciente.nome,sizeof(consulta.paciente.nome),stdin);

    removerEnter(consulta.paciente.nome);

    limparBuffer();

    printf("Digite o telefone do paciente: ");
    fgets(consulta.paciente.telefone,sizeof(consulta.paciente.telefone),stdin);

    removerEnter(consulta.paciente.telefone);

    struct Medico medico [] = {
    {1, "Bruhhh", "(Sei lá)"},
    {2, "Tun tun sahur", "(Não faço ideia)"},
    {3, "Fulano", "(FAHHHHH)"},
    {4, "Cicrano", "(NUHHHH)"},   
    };

    printf("Qual o medico que voce deseja:\n");

    for(int i = 0; i < 4; i++){
        printf("%d-%s  %s\n", i, medico[i].nome, medico[i].especializacao);
    }
    
    int escolha_medico;

    printf("Escolha o Médico:");
    scanf("%d", &escolha_medico);


    strcpy(consulta.previa, "Nenhuma");

    printf("Deseja falar algo previamente para o doutor? (s/n): ");
    scanf(" %c", &resposta);

    limparBuffer();

    if(resposta == 's' || resposta == 'S') {

        printf("Escreva uma previa para o medico: ");

        fgets(consulta.previa,
              sizeof(consulta.previa),
              stdin);

        removerEnter(consulta.previa);
    }

    Horario horarios[MAX_DATA] = {
        {"22/05/2026", "08:00", 1},
        {"22/05/2026", "08:30", 1},
        {"22/05/2026", "09:00", 0},
        {"22/05/2026", "09:30", 1},
        {"23/05/2026", "10:00", 1},
        {"25/06/2026", "10:00", 1},
        {"26/06/2026", "11:30", 1}
    };

    printf("\nHorarios disponiveis:\n\n");

    for(int i = 0; i < MAX_DATA; i++) {

        if(horarios[i].disponivel == 1) {

            printf("%d - %s as %s\n", i, horarios[i].data, horarios[i].horario);
        }
    }

int escolha;

printf("\nEscolha o horario: ");
scanf("%d", &escolha);

if(horarios[escolha].disponivel == 0) {
    printf("Horario indisponivel!\n");
    return;
}

horarios[escolha].disponivel = 0;

printf("Horario reservado!\n");

strcpy(consulta.data, horarios[escolha].data);
strcpy(consulta.horario, horarios[escolha].horario);


    FILE *agendamento;

    agendamento = fopen("consulta.txt", "a");


    if(agendamento == NULL) {

        printf("Erro ao abrir arquivo!\n");
        return;
    }


    fprintf(agendamento,
            "\n==============================\n");

    fprintf(agendamento,"Nome do Paciente: %s\n",consulta.paciente.nome);
    fprintf(agendamento,"Idade do Paciente: %d\n",consulta.paciente.idade);
    fprintf(agendamento,"Telefone: %s\n",consulta.paciente.telefone);
    fprintf(agendamento,"Medico: %s  %s\n",medico[escolha_medico].nome, medico[escolha_medico].especializacao);
    fprintf(agendamento,"Previa: %s\n",consulta.previa);
    fprintf(agendamento,"Data: %s\n",consulta.data);
    fprintf(agendamento,"Horario: %s\n",consulta.horario);

    fclose(agendamento);

    printf("\nConsulta agendada com sucesso!\n");
}
