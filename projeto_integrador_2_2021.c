/*
    SISTEMA DE MONITORAMENTO DE LOTAÇÃO DE ONIBUS
            Trabalho realizado por:
        Julia Gabrielle Cajeu Kovalski
        Livia Cristina Siegel
        Mikael Felipe Waismann
        Vicinius Pereira de Andrade
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 //define tamanho maximo do vetor

//vetor de registros para guardar as informaçoes dos onibus
typedef struct{
    int codigo;
    int codOnibus;
    char nomeOnibus[30];
    char placa[10];
    char data[30];
    char hora[30];
    int numeroAssentos;
    int assentosOcupados;
}Info_Onibus;

Info_Onibus onibus[MAX];    //cria um vetor para a struct

//login do passageiro
void LoginP(){

    system ("cls");
    char loginp[15] = "passageiro";     //guarda a informaçao do login
    char senhap[15] = "123456";         //guarda a informaçao da senha
    char loginp1[15];                    //vetor para o usuario inserir o valor e comparar depois se é igual ao login salvo
    char senhap1 [15];                   //vetor para o usuario inserir o valor e comparar depois se é igual a senha salva
   int login_efetuado = 0;              //0 - Falso e  1 - Verdadeiro
    int cont =0;                        //contador para a quantidade de tentativas de login

    while(login_efetuado == 0 && cont < 3){     //enquanto o login_efetuado for falso e o contador de tentativas menor que 3, vai repetir o login
        system ("cls");
        printf("Digite o Login: ");
        scanf("%s", loginp1);             //registra o login digitado

        printf("Digite a Senha: ");
        scanf("%s", senhap1);            //registra a senha digitada

        if (strcmp(loginp, loginp1) == 0 && strcmp(senhap, senhap1) == 0){ //compara as duas strings, o login ja salvo no sistema e o que foi inserido pelo usuario
            login_efetuado = 1;         //se tudo certo muda o login_efetuado para verdadeiro
        }
        else{
            cont ++;                    //caso contrario o contador recebe +1 por cada tentativa de login invalido, o maximo sao 3 tentativas
            printf("\n\nDADOS INVALIDOS!\n\n");
            printf("Tentativas restantes: %d\n\n", 3-cont);     //mostra ao usuario quantas tentativas de login ainda restam
            system("pause");
            if (cont == 3){             //se o contador chegar ate 3 não permite novas tentativas ao usuario
                system("cls");
                printf("Voce atingiu o maximo de tentativas permitidas para login.\n");
                exit(0);
                }
            }
        }
}

//login do motorista, funciona exatamente como o login de passageiro, muda apenas o nome dos vetores e os dados salvos dentro dele
void LoginM(){

    char loginm[15] = "motorista";
    char loginm1[15];
    char senham[15] = "ab123456";
    char senham1[15];
    int login_efetuado = 0;
    int cont = 0;

    while(!login_efetuado && cont < 3){
        system ("cls");
        printf("Digite o Login: ");
        scanf("%s", loginm1);

        printf("Digite a Senha: ");
        scanf("%s", senham1);

        if (strcmp(loginm, loginm1) == 0 && strcmp(senham, senham1) == 0){
            login_efetuado = 1;
        }
        else{
            cont ++;
            printf("\n\nDADOS INVALIDOS!\n\n");
            printf("Tentativas restantes: %d\n\n", 3-cont);
            system("pause");
            if (cont == 3){
                system("cls");
                printf("Voce atingiu o maximo de tentativas permitidas para login.\n");
                exit(0);
            }
        }
    }
}


//funçao para inicializar o registro, deixando ele zerado para receber valores
void inicializar(){
    int codigo;
    //vai rodar todo o registro, do 0 ao numero maximo definido e colocar valores em branco para ele para ficar pronto para receber
    //registros do sistema ou do usuário

    for(codigo=0; codigo< MAX; codigo++){
        onibus[codigo].codigo=codigo;
        onibus[codigo].codOnibus=0;
        strcpy(onibus[codigo].nomeOnibus, " ");
        strcpy(onibus[codigo].placa, " ");
        strcpy(onibus[codigo].data, " ");
        strcpy(onibus[codigo].hora, " ");
        onibus[codigo].numeroAssentos = 0;
        onibus[codigo].assentosOcupados = 0;
    }
}

//funçao para incluir valores no registro direto do sistema
void incluirOnibus(int codigo, int codOnibus, char *nomeOnibus, char *placa, char *data,
                    char *hora, int numeroAssentos, int assentosOcupados){ //as variaveis usadas são as que fazem parte da struct

    //ve se o codigo for maior que o numero maximo definido e verifica se a string ja esta preenchida
    if (codigo > MAX || strcmp(onibus[codigo].nomeOnibus, " " ) != 0){
        ("Erro na inclusao: codigo ja cadastrado ou fora da faixa.\n"); //se alguma dessas condiçoes for verdadeira, apresenta erro
    } else { //se o codigo tiver dentro do MAX e a string estiver sem valor, pode inserir o valor digitado no sistema
        onibus[codigo].codOnibus= codOnibus;
        strcpy(onibus[codigo].nomeOnibus, nomeOnibus); //strcpu copia a string inserida para dentro da variavel
        strcpy(onibus[codigo].placa, placa);
        strcpy(onibus[codigo].data, data);
        strcpy(onibus[codigo].hora, hora);
        onibus[codigo].numeroAssentos = numeroAssentos;
        onibus[codigo].assentosOcupados = assentosOcupados;
    }
}

//funçao para apresentar todos os valores que existem no registro
void imprimirOnibus(){
    int i;
    //definindo o espaçamento e nome de cada coluna
    printf("\n%-4s %-12s %-25s %-10s %-7s %-7s %-18s %-18s \n", "Cod", "Cod Onibus", "Nome Onibus", "Placa", "Data", "Hora", "Tot Assentos", "Assentos Ocup");
    printf("\n%-4s %-12s %-25s %-10s %-7s %-7s %-18s %-18s \n", "----", "------------", "-------------------------", "----------", "-------", "-------", "------------------", "------------------");

    for (i=0; i < MAX; i++){ //vai rodar o registro inteiro
        //apresenta apenas os valores que tem o nome do onibus preenchidos, os outros são entendidos como vazios
        if (strcmp(onibus[i].nomeOnibus, " ") !=0){
            printf("%-4d %-12d %-25s %-10s %-7s %-7s %-18d %-18d \n",
                   onibus[i].codigo, onibus[i].codOnibus,
                   onibus[i].nomeOnibus, onibus[i].placa, onibus[i].data, onibus[i].hora,
                   onibus[i].numeroAssentos, onibus[i].assentosOcupados);
        }
    }

    printf("\n\n");
    system("pause"); //aguarda o usuario dar o enter para continuar
    system("cls"); //limpa a tela
}

//funçao para o motorista inserir dados no sistema manualmente
void MotoristaInclui(){
    int codigo, codOnibus;

    //o codigo inicializa com 0 e vai ate o maximo de valores definido para o registro adicionando 1 cada vez que ler todas as variaveis
    //para rodar em todo o registro
    for(codigo = 0; codigo < MAX; codigo++){
        //o primeiro lugar que achar sem a placa preenchida vai adicionar os dados, pois indica que o registro estara vazio
        if (strcmp(onibus[codigo].placa, " " ) == 0){
            onibus[codigo].codigo == codigo;
            printf("Insira o codigo do onibus: ");
            scanf("%d%*c", &onibus[codigo].codOnibus);
            printf("Insira o nome do onibus: ");
            gets(onibus[codigo].nomeOnibus);
            fflush(stdin);
            printf("Insira a placa do onibus: ");
            scanf("%s%*c", &onibus[codigo].placa);
            printf("Insira a data (DD/MM): ");
            gets(onibus[codigo].data);
            fflush(stdin);
            printf("Insira a hora (HH/MM): ");
            gets(onibus[codigo].hora);
            printf("Insira o numero de assentos total do onibus: ");
            scanf("%d%*c", &onibus[codigo].numeroAssentos);
            printf("Insira o numero de assentos ocupados do onibus: ");
            scanf("%d%*c", &onibus[codigo].assentosOcupados);

            printf("\nDados Inseridos com Sucesso!\n");
            codigo = MAX; //define o codigo como MAX para parar de rodar o registro, uma inclusão é feita por vez
        }
    }

    printf("\n\n");
    system("pause");
    system("cls");

}

//funcao para o motorista excluir um registro especifico por seu codigo
void MotoristaExclui(){
    int codigo;
    char nome[30]; //variaveis para guardar os valores que vão ser excluidos
    char data[30];
    char hora[30];

    printf("Digite o codigo dos dados que deseja excluir: ");
    scanf("%d", &codigo);   //salva o codigo do registro a ser excluido

    //copia as informacoes do nome/data/hora da posiçao selecionada pelo codigo inserido para outra variavel,
    //isso guarda as informaçoes para serem apresentadas ao final mostrando o que foi apagado
    strcpy(nome, onibus[codigo].nomeOnibus);
    strcpy(data, onibus[codigo].data);
    strcpy(hora, onibus[codigo].hora);

    //verificando se o codigo é maior que o MAX definido ou se a placa está vazia, pois assim não há o que excluir
    if (codigo > MAX || strcmp(onibus[codigo].nomeOnibus, " " ) == 0){
            printf("Dados nao existentes.\n\n");
    }else{ //se o codigo estiver dentro do definido e tiver conteudo na placa do codigo selecionado, vai zerar os valores encontrados naquela posiçao
        onibus[codigo].codigo=codigo;
        onibus[codigo].codOnibus= 0;
        strcpy(onibus[codigo].nomeOnibus, " ");
        strcpy(onibus[codigo].placa, " ");
        strcpy(onibus[codigo].data, " ");
        strcpy(onibus[codigo].hora, " ");
        onibus[codigo].numeroAssentos = 0;
        onibus[codigo].assentosOcupados = 0;
        printf("\nExclusao com sucesso do onibus %s na data %s %s\n\n", nome, data, hora); //usa as informacoes salvas anteriormente para mostrar o que foi apagado
    }

    printf("\n\n");
    system("pause");
    system("cls");
}

//funçao para o motorista alterar algum valor do registro por seu codigo
void MotoristaAltera(){
    int codigo;
    printf("Digite o codigo dos dados que deseja alterar: ");
    scanf("%d", &codigo); //guarda o codigo do registro

    //verifica se o codigo é maior que o MAX ou se o campo esta vazio, não ha dados para alterar nesse codigo
    if(codigo > MAX || strcmp(onibus[codigo].nomeOnibus, " ") == 0){
        printf("Dados nao existentes.\n\n");
    } else { //se tiver dados dentro do codigo, pede os dados para serem incluidos na posição escolhida
        printf("Insira o codigo do onibus: ");
        scanf("%d%*c", &onibus[codigo].codOnibus);
        printf("Insira o nome do onibus: ");
        gets(onibus[codigo].nomeOnibus);
        fflush(stdin);
        printf("Insira a placa do onibus: ");
        scanf("%s%*c", &onibus[codigo].placa);
        printf("Insira a data (DD/MM): ");
        gets(onibus[codigo].data);
        fflush(stdin);
        printf("Insira a hora (HH/MM): ");
        gets(onibus[codigo].hora);
        printf("Insira o numero de assentos total do onibus: ");
        scanf("%d%*c", &onibus[codigo].numeroAssentos);
        printf("Insira o numero de assentos ocupados do onibus: ");
        scanf("%d%*c", &onibus[codigo].assentosOcupados);
        //mostra o nome, data e hora ja alterados
        printf("Alteracao realizada com sucesso do onibus %s na data %s %s \n", onibus[codigo].nomeOnibus, onibus[codigo].data, onibus[codigo].hora);
    }

    printf("\n\n");
    system("pause");
    system("cls");
}

//busca todas as informaçoes do onibus pelo codigo do onibus. Todos os dados com o codigo do onibus irão aparecer.
void BuscarCodigo(){

    int codO;

    printf("\nInforme o numero do Onibus: ");
    scanf("%d", &codO); //guarda o codigo do onibus escolhido
    printf("\n");

    usleep(2000000); //aguarda para limpar a tela
    system("cls");

    //definindo o espaçamento e nome de cada coluna
    printf("\n%-4s %-12s %-25s %-10s %-7s %-7s %-18s %-18s \n", "Cod", "Cod Onibus", "Nome Onibus", "Placa", "Data", "Hora", "Tot Assentos", "Assentos Ocup");
    printf("\n%-4s %-12s %-25s %-10s %-7s %-7s %-18s %-18s \n", "----", "------------", "-------------------------", "----------", "-------", "-------", "------------------", "------------------");

    //roda o registro inteiro e mostra apenas os dados com o codigo do onibus escolhido
    for(int i = 0; i < MAX; i++){
        //se o codigo do onibus na posiçao do registro for igual ao codigo do onibus selecionado, imprime os dados
        if(codO == onibus[i].codOnibus){
           printf("%-4d %-12d %-25s %-10s %-7s %-7s %-18d %-18d \n", //espaçamento para mostrar os dados e eles ficarem embaixo das respectivas colunas
                   onibus[i].codigo, onibus[i].codOnibus,
                   onibus[i].nomeOnibus, onibus[i].placa, onibus[i].data, onibus[i].hora,
                   onibus[i].numeroAssentos, onibus[i].assentosOcupados);
        }

    }
    printf("\n\n");
    system("pause");
    system("cls");

}

//busca todas as informaçoes do onibus pelo codigo do onibus E pela hora. Todos os dados com o codigo do onibus irão aparecer.
void BuscarCodigoHora(){

    int codO;
    char hora[30];
    int tot = 0;
    int cont = 0;
    float media = 0.0;

    printf("\nInforme o numero do Onibus: ");
    scanf("%d", &codO);     //guarda o codigo selecionado
    printf("\nInforme o horario do Onibus (HH:MM os minutos de 15 em 15): ");
    scanf("%s", &hora);     //guarda a hora selecionada
    printf("\n");

    usleep(2000000); //aguarda para limpar a tela
    system("cls");

    printf("\n%-4s %-12s %-25s %-10s %-7s %-7s %-18s %-18s \n", "Cod", "Cod Onibus", "Nome Onibus", "Placa", "Data", "Hora", "Tot Assentos", "Assentos Ocup");
    printf("\n%-4s %-12s %-25s %-10s %-7s %-7s %-18s %-18s \n", "----", "------------", "-------------------------", "----------", "-------", "-------", "------------------", "------------------");

    //roda o registro inteiro e mostra apenas os dados com o codigo do onibus E a hora escolhidos
    for(int i = 0; i < MAX; i++){
    //se o codigo do onibus for igual ao escolhido e a hora for a mesma selecionada, irá mostrar todos os seus dados
        if(codO == onibus[i].codOnibus && strcmp(hora, onibus[i].hora) == 0){
           printf("%-4d %-12d %-25s %-10s %-7s %-7s %-18d %-18d \n",
                    onibus[i].codigo, onibus[i].codOnibus,
                    onibus[i].nomeOnibus, onibus[i].placa, onibus[i].data, onibus[i].hora,
                    onibus[i].numeroAssentos, onibus[i].assentosOcupados);

                    tot = tot + onibus[i].assentosOcupados; //soma o total de todos os assentos ocupados
                    cont++; //conta a quantidade de vezes que entrou no if e mostrou dados
        }

    }

    //caso o contador for maior que 0
    if (cont > 0){
        media = tot/cont; //faz a media de quantos assentos estavam ocupados nessa busca, dividindo o total geral de assentos pelo contador
        printf("\nMedia de assentos ocupados nesse horario: %2.f", media);
    }

    printf("\n\n");
    system("pause");
    system("cls");

}

//menu de boas vindas
void Menu(){

    int codigo, codO;
    int opcao;
    int op = 0;

   while (opcao !=3){ //enquanto a opçao escolhida nao for para sair, vai mostrar a tela de login

    //mostra as opçoes do primeiro menu para o usuario, onde vai escolher se vai entrar como passageiro ou motorista
        printf("-------------------BEM VINDO-------------------\n");
        printf("Logar como:\n");
        printf("1 - Motorista\n");
        printf("2 - Passageiro\n");
        printf("3 - Sair\n");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);    //guarda a opçao escolhida

        switch(opcao){          //escolhe o que fazer pela opçao
        case 1:                 //caso Motorista seja escolhido
            system("cls");
            LoginM();       //mostra a tela de login do motorista com as opçoes de login e cadastro
            system("cls");
            printf("Login realizado como Motorista\n");       //se o login for bem sucedido, aparece a mensagem
            printf("-----------------------------------------------------------------------------------------\n\n");

            while (op != 7){    //enquanto a opçao de sair não for escolhida, vai mostrar o menu

                printf("Selecione:\n");
                printf("1 - Inserir dados sobre o onibus\n");
                printf("2 - Excluir dados sobre o onibus\n");
                printf("3 - Alterar dados sobre o onibus\n");
                printf("4 - Buscar\n");
                printf("5 - Mostrar dados\n");
                printf("6 - Voltar para tela de login\n");
                printf("7 - Sair da aplicacao\n");
                printf("\nDigite a opcao: ");
                scanf("%d", &op);

                switch(op){
                case 1:     //caso a opçao de inserir dados seja escolhida, chama a funçao para incluir dados
                    system("cls");
                    MotoristaInclui();
                    break;

                case 2:     //caso a opçao de excluir dados seja escolhida, chama a funçao para excluir dados
                    system("cls");
                    MotoristaExclui();
                    break;

                case 3:     //caso a opçao de alterar dados seja escolhida, chama a funçao para alterar dados
                    system("cls");
                    MotoristaAltera();
                    break;

                case 4:     //caso a opçao de buscar dados seja escolhida, chama a funçao para buscar dados apenas por codigo
                    system("cls");
                    BuscarCodigo();
                    break;

                case 5:     //caso a opçao de mostrar dados seja escolhida, chama a funçao para imprimir todos os dados do registro
                    system("cls");
                    imprimirOnibus();
                    break;

                case 6:     //caso a opcao de voltar para o login for escolhida, chama a propria funçao Menu
                    system("cls");
                    Menu();
                    break;

                case 7:     //caso a opçao de sair do sistema seja escolhida, aparecerá uma mensagem e vai parar o sistema
                    system("cls");
                    printf("\nAte Mais!\n\n");
                    exit(0);
                    break;
                default:
                    printf("Opcao Invalida\n\n");
                    usleep(2000000); //aguarda para limpar a tela
                    system("cls");
                    break;
                }
            }
        break;

        case 2:         //caso passageiro seja escolhido
            system("cls");
            LoginP();       //chama a funçao para escolher entre o login com os dados do sistema ou fazer o cadastro
            system("cls");
            printf("Login realizado como Passageiro\n");    //se o login for bem sucedido, aparecerá essa mensagem
            printf("-----------------------------------------------------------------------------------------\n\n");

            while (op != 4){    //enquanto a opçao for diferente da opcao de sair do sistema, vai motrar o menu
                printf("Selecione:\n");
                printf("1 - Buscar dados sobre um onibus\n");
                printf("2 - Buscar por um horario especifico do onibus\n");
                printf("3 - Voltar para tela de login\n");
                printf("4 - Sair da aplicacao\n");
                printf("\nDigite a opcao: ");
                scanf("%d", &op);

                switch(op){
                case 1:     //caso a opçao de buscar dados do onibus for escolhida, chama a funçao de buscar todos os dados do onibus por seu codigo
                    system("cls");
                    BuscarCodigo();
                    break;

                case 2:     //caso a opçao de buscar dados por horario for escolhida, chama a funçao de buscar todos os dados do onibus por codigo E hora especificos
                    system("cls");
                    BuscarCodigoHora();
                    break;

                case 3:     //caso a opcao de voltar para o login for escolhida, chama a propria funçao Menu
                    system("cls");
                    Menu();
                    break;

                case 4:     //caso deseje sair da aplicaçao, mostra apenas a mensagem e para o codigo
                    system("cls");
                    printf("\nAte Mais!\n\n");
                    exit(0);
                    break;

                default:    //caso seja uma opçao diferente das mostradas
                    printf("Opcao Invalida!\n\n");
                    usleep(2000000); //aguarda para limpar a tela
                    system("cls");
                    break;
                }
            }

        break;

        case 3:         //caso escolha sair da aplicaçao na tela inicial
            printf("\nAte Mais!\n\n");
            exit(0);
            break;

        default:        //caso escolha uma opçao diferente das mostradas
            printf("Opcao invalida!\n\n");
            usleep(2000000); //aguarda para limpar a tela
            system("cls");
            break;
        }
    }
}

//execuçao do programa
main(){
    //chama a funçao para inicializar o registro, para não ter sujeira do sistema dentro dele
    inicializar();

    //inserindo dados pelo sistema
    //deixa o codigo 0 em branco para começar do numero 1, como o nome é um espaço em branco, vai ser entendido como vazio e
    // não vai imprimir esse dado e como a placa não está vazia, não tem como incluir dados nesse lugar
    incluirOnibus(0, 0, " ", "---" , " ",  " ", 0, 0);
    incluirOnibus(1, 462, "Petropolis", "HBB5656" , "02/11",  "18:15", 25, 13);
    incluirOnibus(2, 462, "Petropolis", "HBB5656" , "08/11",  "13:15", 25, 10);
    incluirOnibus(3, 462, "Petropolis", "FGT6787" , "08/11",  "13:30", 25, 12);
    incluirOnibus(4, 462, "Petropolis", "FGT6787" , "09/11",  "18:00", 25, 22);
    incluirOnibus(5, 462, "Petropolis", "FGT6787" , "09/11",  "18:15", 25, 25);

    incluirOnibus(6, 513, "Hauer/Boqueirao", "ABC1267" , "10/11",  "08:00", 37, 23);
    incluirOnibus(7, 513, "Hauer/Boqueirao", "ABC1267" , "10/11",  "08:15", 37, 20);
    incluirOnibus(8, 513, "Hauer/Boqueirao", "ABC1267" , "11/11",  "08:30", 37, 13);
    incluirOnibus(9, 513, "Hauer/Boqueirao", "ABD9900" , "12/11",  "14:15", 37, 17);
    incluirOnibus(10, 513, "Hauer/Boqueirao", "ABD9900" , "12/11",  "14:30", 37, 18);

    incluirOnibus(11, 30, "Interbairros III", "HBG8720" , "21/10",  "09:15", 60, 35);
    incluirOnibus(12, 30, "Interbairros III", "HBG8720" , "21/10",  "09:30", 60, 49);
    incluirOnibus(13, 30, "Interbairros III", "BTF8014" , "29/10",  "09:30", 60, 43);
    incluirOnibus(14, 30, "Interbairros III", "BTF8014" , "29/10",  "10:45", 60, 17);
    incluirOnibus(15, 30, "Interbairros III", "BTF8014" , "29/10",  "11:00", 60, 22);
    incluirOnibus(16, 30, "Interbairros III", "BTF8014" , "21/10",  "09:15", 60, 32);

    incluirOnibus(17, 666, "Novo Mundo", "ATR1122" , "04/11",  "16:15", 20, 7);
    incluirOnibus(18, 666, "Novo Mundo", "ATR1122" , "04/11",  "16:30", 20, 9);
    incluirOnibus(19, 666, "Novo Mundo", "ATR1122" , "04/11",  "17:15", 20, 13);
    incluirOnibus(20, 666, "Novo Mundo", "ATR1122" , "04/11",  "17:35", 20, 13);

    incluirOnibus(21, 870, "Sao Braz", "POI3412" , "04/11",  "14:30", 25, 7);
    incluirOnibus(22, 870, "Sao Braz", "POI3412" , "04/11",  "14:45", 25, 8);
    incluirOnibus(23, 870, "Sao Braz", "POI3412" , "04/11",  "15:00", 25, 12);
    incluirOnibus(24, 870, "Sao Braz", "POI3412" , "04/11",  "15:15", 25, 10);
    incluirOnibus(25, 870, "Sao Braz", "POI3412" , "04/11",  "15:30", 25, 14);
    incluirOnibus(26, 870, "Sao Braz", "POI3412" , "05/11",  "15:30", 25, 12);

    incluirOnibus(27, 621, "Fanny", "BGP3412" , "05/11",  "20:30", 37, 10);
    incluirOnibus(28, 621, "Fanny", "BGP3412" , "05/11",  "21:00", 37, 15);
    incluirOnibus(29, 621, "Fanny", "BGP3412" , "05/11",  "21:15", 37, 12);
    incluirOnibus(30, 621, "Fanny", "BGP3412" , "05/11",  "21:30", 37, 13);

    //chama a funçao menu, onde se encontram todas as opçoes de logins e onde o usuário faz suas escolhas
    Menu();

}

