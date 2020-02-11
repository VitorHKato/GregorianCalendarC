#include <stdio.h>  //Mostra o calendário do mês escolhido, levando o ano em consideração
                    //Autor: Vitor Kato

//Protótipos
int calculaDiaDaSemana(int mes, int ano);           //Funcao para descobrir o dia da semana( retorna de 0-6 )
void funcaoFev(int mes, int ano);                   //Procedimento para o mes de Fevereiro
void funcao31e30dias(int mes, int ano);             //Procedimento para meses de 30 e 31 dias
void funcaoTitulo(int mes, int ano);                //Mostra o título do calendário na tela, seleciona e chama a próxima função

//Função principal
main()
{
    int mes, ano;

    //Interacao com o usuario
    printf("Digite o ano.\n");
    scanf("%d", &ano);
    printf("Digite o mes.\n");
    scanf("%d", &mes);

    funcaoTitulo(mes, ano);                         //Chamada da função inicial

}
void funcaoTitulo(int mes, int ano)
{
    if(mes==1){
        printf("         Janeiro de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==2){
        printf("         Fevereiro de %d\n\n", ano);
        funcaoFev(mes, ano);
    }
    else if(mes==3){
        printf("         Marco de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==4){
        printf("         Abril de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==5){
        printf("         Maio de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==6){
        printf("         Junho de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==7){
        printf("         Julho de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==8){
        printf("         Agosto de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==9){
        printf("         Setembro de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==10){
        printf("         Outubro de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==11){
        printf("         Novembro de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    else if(mes==12){
        printf("         Dezembro de %d\n\n", ano);
        funcao31e30dias(mes, ano);
    }
    //Conscistencia de dados
    else{
        printf("Mes invalido.\n");
    }
}
int calculaDiaDaSemana(int mes, int ano){

    int dia=7, //constante usada na fórmula
    i, //valor de retorno (representa o dia da semana)
    x;

    //Difere o cálculo para janeiro e fevereiro por causa dos anos bissextos
    if(mes>2){
        mes=mes-2;
        x=8;
    }
    else{
        ano=ano-1;
        x=13;
    }
    //Fórmula para calcular o dia da semana de qualquer data
    i=(x+dia+(mes*2)+((7*mes)/12)+ano%7+ano/4%7-(3*(1+ano/100))/4%7)%7;

    if(i==0)
        return 6;
    else
        return i;
}
void funcaoFev(int mes, int ano){

    int i, //Contador para os dias de cada semana
        f, //Valor de retorno da função que calcula o dia da semana
        dia=0; //Contador dos dias da semana

    f=calculaDiaDaSemana(mes, ano); //Dia da semana q vai começar o caledário

    printf(" DOM SEG TER QUA QUI SEX SAB\n");
    //Se o ano for bissexto
    if(ano%4==0 && (ano%100!=0 || ano%400==0)){
        /*Primeira linha do calendario, inicia em 0 e começa a mostrar e contar os dias a partir do valor f encontrado, antes
        disso mostra espaços em branco*/
        for(i=0;i<=6;i++){
            if(i==f){
                dia=dia+1;
                printf("  %2d", dia);
                f++;
            }
            else{
                printf("    ");
            }
        }
        printf("\n");
        //Linhas seguintes
        while(dia<29){
            for(i=0;i<=6;i++){
                dia=dia+1;
                printf("  %2d",dia);
                if(dia==29 && i==6){
                    printf("\n");
                }
                //Completa o restante da semana com espaços em branco
                else if(dia==29 && i<6){
                    printf("  ");
                }
                //Evita que ultrapasse os 29 dias
                if(dia==29){
                    break;
                }
            }
            printf("\n"); //Pula uma linha depois que acaba a semana
        }
    }
    //Caso nao for bissexto
    else{
        //Primeira linha do calendario
        for(i=0;i<=6;i++){
            if(i==f){
                dia=dia+1;
                printf("  %2d", dia);
                f++;
            }
            else{
                printf("    ");
            }
        }
        printf("\n");
        //Linhas seguintes
        while(dia<28){
            for(i=0;i<=6;i++){
                dia=dia+1;
                printf("  %2d",dia);
                if(dia==28 && i==6){
                    printf("\n");
                }
                else if(dia==28 && i<6){
                    printf("  ");
                }
                if(dia==28){
                    break;
                }
            }
            printf("\n");
        }
    }
}
void funcao31e30dias(int mes, int ano){

    int dia=0, i, f,
        quantDias;  //30 ou 31 dias conforme o mes

    f=calculaDiaDaSemana(mes, ano);

    printf(" DOM SEG TER QUA QUI SEX SAB\n");
    //Determina o valor da variável conforme o mes digitado
    if(mes==4 || mes==6 || mes==9 || mes==11)
        quantDias=30;
    else
        quantDias=31;
    //Primeira linha
    for(i=0;i<=6;i++){
        if(i==f){
            dia=dia+1;
            printf("  %2d", dia);
            f++;
        }
        else{
            printf("    ");
        }
    }
    printf("\n");
    while(dia<quantDias){
        for(i=0;i<=6;i++){
            dia=dia+1;
            printf("  %2d",dia);
            if(dia==quantDias){
                break;
            }
        }
        printf("\n");
    }
}


