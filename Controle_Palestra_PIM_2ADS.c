#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"
#define SIZE 53

//Defini��o das vari�veis

char nome [SIZE][50];
char email [SIZE][50];
int datanasc [SIZE];
int cpf [SIZE];
char convidado [SIZE][1];
char especial [SIZE][1];
int op,t,opcaomp,encontrou;
int j;
int verifica_senha=0;
int verifica_user=0;
char login[10];
char senha[8];

//int status_es[3];
//int status_cv[10];
//int status_pt[40];

int status[53];

int assento[SIZE];

//Defini��o das vari�veis de fun��es

void incluir();
void excluir();
void listar_livres();
//void listar_todos();
void lista_todos();
void valida_senha();
void gerenciar_visitante();

//Rotina principal

int main(void)
{

setlocale(LC_ALL, "Portuguese");

do
{
    system("cls");
    system("color 0a");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t +============================================================+");
    printf("\n\t\t\t\t\t\t |                                                            |\n");
    printf("\t\t\t\t\t\t |        xxxx  xxxx  xxxx     xxxx  xxxx  xxxxxxxxxx         |\n");
    printf("\t\t\t\t\t\t |        xxxx  xxxx  xxxxxx   xxxx  xxxx  xxxx  xxxx         |\n");
    printf("\t\t\t\t\t\t |        xxxx  xxxx  xxxx xx  xxxx  xxxx  xxxx  xxxx         |\n");
    printf("\t\t\t\t\t\t |        xxxx  xxxx  xxxx  xx xxxx  xxxx  xxxxxxxxxx         |\n");
    printf("\t\t\t\t\t\t |        xxxxxxxxxx  xxxx   xxxxxx  xxxx  xxxx               |\n");
    printf("\t\t\t\t\t\t |        xxxxxxxxxx  xxxx    xxxxx  xxxx  xxxx               |\n");
    printf("\t\t\t\t\t\t |                                                            |\n");
    printf("\t\t\t\t\t\t |                                                            |\n");
    printf("\t\t\t\t\t\t |                   UNIVERSIDADE PAULISTA                    |\n");
    printf("\t\t\t\t\t\t |                                                            |\n");
    printf("\t\t\t\t\t\t |                                                            |\n");
    printf("\t\t\t\t\t\t |                 PALESTRA DIREITOS HUMANOS                  |\n");
    printf("\t\t\t\t\t\t |                                                            |\n");
    printf("\t\t\t\t\t\t +============================================================+");
    printf("\n\n\t\t\t\t\t\t                  USU�RIO......... : ");
    gets(login);
    strupr(login);
    printf("\n\n\t\t\t\t\t\t                  SENHA........... : ");

    //Chama fun��o para validar a senha
    valida_senha();

    if(verifica_senha==1)
    {
        opcaomp = 0;

        //Setar todos os assentos como livres
        for(j=0;j<52;j++)
        {
          status[j] = 0;    //0 - Assento livre -> 1 - Assento ocupado
        }


        //Apresenta tela de menu principal

        while(opcaomp!=4)
        {
            system("color 0a");
            verifica_senha = 1;
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t\t\t\t +==============================================================+");
            printf("\n\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                UNIP - UNIVERSIDADE PAULISTA                  |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                   **** MENU PRINCIPAL ****                   |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                1 - Gerenciar Visitante                       |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                2 - Realizar Sorteio                          |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                3 - Enviar Comunicado por E-mail              |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                4 - Sair                                      |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t |                                                              |\n");
            printf("\t\t\t\t\t\t +==============================================================+\n\n");
            printf("\t\t\t\t\t\t                  Digite a op��o desejada...... : ");
            scanf("%d",&opcaomp);
            switch (opcaomp)
            {

                case 1:
                    gerenciar_visitante();
                    break;

                case 2:
                    realizar_sorteio();
                    break;

                case 3:
                    enviar_email();
                    break;

                case 4:
                    system("exit");
                    break;

                default:
                    printf("\n\t\t\t\t\t\t\t\t *** Op��o Inv�lida ! ***");
                    getch();

            } //Switch
        }//while(opcaomp!=4)
    }//if(verifica_senha==1)

}while (t!=3 && verifica_senha==0);

} //Main

//Fun��o Valida Senha e Usuario

void valida_senha()
{
    int i,u;
    char c;
    char l;
    u=0;
    i=0;

    while ((c=getch())!= 13)
    {
       senha[i]=c;
       login[u]=l;
       u++;
       i++;
       printf("*");
    }

    login[u]='\0';
    senha[i]='\0';
    i=0;
    u=0;
    l = strcmp(login,"ADM");
    c = strcmp(senha,"1");

    if(c==1 && l==1) //Senha e usuario Inv�lida
    {
        printf("\n\n\t\t\t\t\t *** Senha ou Us�ario inv�lido ! Tente novamente *** \n\n");
        t = t + 1;
        system("color 0c");
        getch();
    }
    else//Senha e Usuario Correta
    {
        verifica_user = 1;
        verifica_senha = 1;
    }
    if(t==3)
    {
      //system("cls");
      printf("\n\n\t\t\t\t\t *** Acesso Negado ! *** \n\n");
      getch();
    }
} //Fim da Fun��o Valida Senha e Usuario

//Fun��o Gerenciar Visitante

void gerenciar_visitante()
{

    int j,op;

    op = 1;

    while(op!=5)
    {
       system("cls");
       printf("\n\n\n\n\n\n\t\t\t\t\t\t +==============================================================+");
       printf("\n\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                UNIP - UNIVERSIDADE PAULISTA                  |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                1 - Incluir Participante                      |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                2 - Excluir Participante                      |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                3 - Listar Lugares Livres                     |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                4 - Mostrar Todos os Lugares                  |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                5 - Retornar ao Menu Principal                |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t +==============================================================+\n\n");
       printf("\t\t\t\t\t\t                  Digite a op��o desejada...... : ");
       scanf("%d",&op);

       switch (op)
       {
          case 1:  //Incluir o participante
             incluir();
             break;

          case 2:
             excluir();
             break;

          case 3:
            listar_livres();
            break;

          case 4:
            listar_todos();
            break;

          case 5:
            break;

          default:
            printf("\n\t\t\t\t\t\t\t\t *** Op��o Inv�lida ! ***");
            getch();
            break;

       } //Switch
    }//while(opcao!=5)
}//Fim da Fun��o Gerenciar Visitante

//Fun��o incluir participantes

void incluir ()
{
    static int linha;

    int j,encontrou,tc,i,v;
    linha=0;

    do{

       encontrou = 0;
       tc = 0;

       //Mostrar tela para digita��o das informa��es do participante

       system("cls");
       printf("\n\n\n\n\n\n\t\t\t\t\t\t\t***   Cadastro de Participantes   ***\n\n\n");
       printf("\n\t\t\t\t\t\t Nome................................... : ");
       fflush(stdin);
       gets(nome[linha]);
       strupr(nome);
       printf("\n\t\t\t\t\t\t N�mero do CPF.......................... : ");
       scanf("%d", &cpf[linha]);
       printf("\n\t\t\t\t\t\t Data de nascimento..................... : ");
       scanf("%d", &datanasc[linha]);
       printf("\n\t\t\t\t\t\t E-mail................................. : ");
       fflush(stdin);
       gets(email[linha]);
       printf("\n\t\t\t\t\t\t � convidado do palestrante (S/N) ?..... : ");
       scanf("%s", &convidado[linha]);
       printf("\n\t\t\t\t\t\t Necessita de lugar especial (S/N) ?.... : ");
       scanf("%s", &especial[linha]);

       //Verifica assentos reservados e reserva assento dispon�vel

       system("cls");

       //Assento Especial
       tc=strcmp(especial[linha],"S");
       if(tc==0)
       {
       for(j=0;j<3;j++)
          {
           if(status[j]==0)
            {
               printf("\n\n\n\n\n\n\t\t\t\t\t\t Ol� %s",nome[linha]);
               printf("\n\n\t\t\t\t\t\t Seu assento � n�mero : %d",j+1);
               printf("\n\n\t\t\t\t\t\t Esperamos que aproveite a Paletra !!!");
               status[j]=1;
               cpf[j]=cpf[linha];
               getch();
               j = 3;
               encontrou = 1;
               op=0;
            }
          }
       }

       else
       {
       //Convidado do Palestrante
       tc=strcmp(convidado[linha],"S");
       if(tc==0)
       {
          for(j=3;j<13;j++)
          {
            if(status[j]==0)
            {
               printf("\n\n\n\n\n\n\t\t\t\t\t\t Ol� %s",nome[linha]);
               printf("\n\n\t\t\t\t\t\t Seu assento � n�mero : %d",j+1);
               printf("\n\n\t\t\t\t\t\t Esperamos que aproveite a Paletra !!!");
               status[j]=1;
               cpf[j]=cpf[linha];
               getch();
               j = 14;
               encontrou = 1;
               op=0;
            }
          }
       }
       else
       {

       //Participante

          for(j=13;j<52;j++)
          {
            //i=pt[j];
            if(status[j]==0)
            {
               printf("\n\n\n\n\n\n\t\t\t\t\t\t Ol� %s",nome[linha]);
               printf("\n\n\t\t\t\t\t\t Seu assento � n�mero : %d",j+1);
               printf("\n\n\t\t\t\t\t\t Esperamos que aproveite a Paletra !!!");
               cpf[j]=cpf[linha];
               status[j]=1;
               getch();
               j = 53;
               encontrou = 1;
               op=0;
            }
          }
       }

    }
    if(encontrou==0)
    {
       printf("*** Todos os assentos est�o ocupados ! ***");
       getch();
    }

    linha++;
    printf("%d %d", cpf[linha],linha);
    }while(op==1);
} //Fim da fun��o incluir

//Fun��o excluir participante liberando o assento
void excluir()
{
    int cpfPesquisa;
    int i;

    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\tInforme o CPF do participante que deseja excluir : ");
    scanf("%d" ,&cpfPesquisa);
    for(i=0;i<SIZE;i++)
    {
       if(cpf[i]==cpfPesquisa)
       {
          status[i]=0;
          cpf[i]=0;
          datanasc[i]=0;
          i=54;
          printf("\n\n\n\t\t\t\t\t\t\t*** Registro exclu�do com sucesso ! ***");
          getch();
       }
    }
}//Fim da fun��o excluir participante


//Fun��o Listar lugares livres no audit�rio

void listar_livres()
{
    int j;

    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t***   Lugares Livres   ***\n\n\n");
    encontrou = 0;  //Flag para saber se existe pelo menos um assento livre

    printf("\n\n\n\t\t\t\t\t\tAssentos Especiais\n\n");
    printf("\t\t\t\t\t\tFileira A");
    for(j=0;j<3;j++)
    {
        if(status[j]==0)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tAssentos para Convidados do Palestrante\n\n");
    printf("\t\t\t\t\t\tFileira B");
    for(j=3;j<13;j++)
    {
        if(status[j]==0)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tAssentos para Participantes\n\n");
    printf("\t\t\t\t\t\tFileira C");
    for(j=13;j<23;j++)
    {
        if(status[j]==0)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tFileira D");
    for(j=23;j<33;j++)
    {
        if(status[j]==0)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tFileira E");
    for(j=33;j<43;j++)
    {
        if(status[j]==0)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tFileira F");
    for(j=43;j<53;j++)
    {
        if(status[j]==0)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    getch();
 }

 //Fun��o Lista todos os lugares do audit�rio

void listar_todos()
{
    int j;
    system("cls");

    printf("\n\n\n\n\t\t\t\t\t\t\t     Todos os Lugares    \n");
    printf("\t\t\t\t\t\t +============================================================+");
    encontrou = 0;  //Flag para saber se existe pelo menos um assento livre
    printf("\n\t\t\t\t\t\t\t  ***   Livres  ***  \n");
    printf("\n\n\t\t\t\t\t\tAssentos Especiais\n");
    printf("\t\t\t\t\t\tA ");
    for(j=0;j<3;j++)
    {
        if(status[j]==0)
        {
            printf(" [%d] ", j+1);
            encontrou =1;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tConvidados do Palestrante\n");
    printf("\t\t\t\t\t\tB ");
    for(j=3;j<13;j++)
    {
        if(status[j]==0)
        {
            printf(" [%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tParticipantes\n");
    printf("\t\t\t\t\t\tC ");
    for(j=13;j<23;j++)
    {
        if(status[j]==0)
        {
            printf(" [%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tD ");
    for(j=23;j<33;j++)
    {
        if(status[j]==0)
        {
            printf(" [%d] ", j+1);
            encontrou = 1;
        }
    }
    printf("\n");
    printf("\t\t\t\t\t\tE ");
    for(j=33;j<43;j++)
    {
        if(status[j]==0)
        {
            printf(" [%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tF ");
    for(j=43;j<53;j++)
    {
        if(status[j]==0)
        {
            printf(" [%d] ", j+1);
            encontrou = 1;
        }
    }

    // fun��o para ver todos os ocupados
    printf("\n\n\n\t\t\t\t\t\t+===================================================+");
    encontrou = 0;  //Flag para saber se existe pelo menos um assento livre
    printf("\n\t\t\t\t\t\t\t  ***   Ocupados  ***  \n");
    printf("\n\t\t\t\t\t\tAssentos Especiais\n");
    printf("\t\t\t\t\t\tA ");
    for(j=0;j<3;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 0;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tConvidados do Palestrante\n");
    printf("\t\t\t\t\t\tB ");
    for(j=3;j<13;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 0;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tParticipantes\n");
    printf("\t\t\t\t\t\tC ");
    for(j=13;j<23;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tD ");
    for(j=23;j<33;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tE ");
    for(j=33;j<43;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tF ");
    for(j=43;j<53;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    getch();

}


void enviar_email()
{

        int opM;
    opM = 1;

    while(opM!=3)
    {
        system("cls");
       printf("\n\n\n\n\n\n\t\t\t\t\t\t +==============================================================+");
       printf("\n\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                UNIP - UNIVERSIDADE PAULISTA                  |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                1 - Todos os Visitantes                       |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                2 - Escolher Visitante                        |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                3 - Retornar ao Menu Principal                |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t +==============================================================+\n\n");
       printf("\t\t\t\t\t\t                  Digite a op��o desejada...... : ");
       scanf("%d",&opM);

            switch (opM)
            {

                case 1:
                    mail_todos();
                    break;

                case 2:
                    mail_um();
                    break;

                case 3:
                    break;

                default:
                    printf("\n\t\t\t\t\t\t\t\t *** Op��o Inv�lida ! ***");
                    getch();
            }
    }
}

void mail_todos()
{

        system("cls");
       printf("\n\n\n\n\n\n\t\t\t\t\t\t +==============================================================+");
       printf("\n\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                Palestra Direito Humanos                      |\n");
       printf("\t\t\t\t\t\t |                  Dr. Ramiro                                  |\n");
       printf("\t\t\t\t\t\t |     Cont�udo da Palestra: Direitos Humanos                   |\n");
       printf("\t\t\t\t\t\t |     Motivo: Informativo                                      |\n");
       printf("\t\t\t\t\t\t |     Data: 13/12/2018             Hor�rio: 18:30              |\n");
       printf("\t\t\t\t\t\t |     Local: Unip - Chacara St. Antonio                        |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                        Resumo                                |\n");
       printf("\t\t\t\t\t\t |   Hoje em dia as pessoas torcem o nariz para palavra         |\n");
       printf("\t\t\t\t\t\t |   �Direitos Humanos�, pois aqui no Brasil ela sempre         |\n");
       printf("\t\t\t\t\t\t |   sempre est� ligada ao crime e viol�ncia e nunca            |\n");
       printf("\t\t\t\t\t\t |   est� ao lado da v�tima, mas sim daqueles que               |\n");
       printf("\t\t\t\t\t\t |   causaram o Dano. Por�m o que ningu�m sabe que              |\n");
       printf("\t\t\t\t\t\t |   na d�cada de 40 em uma reuni�o em paris, foram             |\n");
       printf("\t\t\t\t\t\t |   lan�ados 30 artigos no rastro da segunda Guerra            |\n");
       printf("\t\t\t\t\t\t |   Mundial, pois a falta de puni��o contra governos           |\n");
       printf("\t\t\t\t\t\t |   autorit�rios, trabalho escravo, tortura, discrimina��o,    |\n");
       printf("\t\t\t\t\t\t |   fome e pobreza violava todos os dias a vida dos seres      |\n");
       printf("\t\t\t\t\t\t |   humanos da �poca.                                          |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t +==============================================================+\n\n");
       getch();
}

void mail_um()
{
    int as;
    printf("\t\t\t\t\t\t Escolha o Assento abaixo, Assim o email ser� enviado para pessoa que est� sentada no mesmo. \n");
    encontrou = 0;  //Flag para saber se existe pelo menos um assento livre
    printf("\n\t\t\t\t\t\tAssentos Especiais\n");
    printf("\t\t\t\t\t\tA ");
    for(j=0;j<3;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 0;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tConvidados do Palestrante\n");
    printf("\t\t\t\t\t\tB ");
    for(j=3;j<13;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 0;
        }
    }

    printf("\n\n\n\t\t\t\t\t\tParticipantes\n");
    printf("\t\t\t\t\t\tC ");
    for(j=13;j<23;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tD ");
    for(j=23;j<33;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tE ");
    for(j=33;j<43;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n");
    printf("\t\t\t\t\t\tF ");
    for(j=43;j<53;j++)
    {
        if(status[j]==1)
        {
            printf("[%d] ", j+1);
            encontrou = 1;
        }
    }

    printf("\n\t\t\t\t\t\t\t\tNecess�rio apenas o n�mero do assento \n");
    printf("\t\t\t\t\t\t\t\tAssento...... : ");
    scanf("%d",&as);

    system("cls");
    if(as > 0 && as < 54){

       printf("\n\n\n\n");
       printf("\n\n\n\n\t\t\t\t\t\t Assento: %d \n",as);
       printf("\t\t\t\t\t\t Email Enviado com Sucesso!!! \n\n");
       printf("\t\t\t\t\t\t Conte�do: \n");
       printf("\t\t\t\t\t\t +==============================================================+");
       printf("\n\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                Palestra Direito Humanos                      |\n");
       printf("\t\t\t\t\t\t |                  Dr. Ramiro                                  |\n");
       printf("\t\t\t\t\t\t |     Cont�udo da Palestra: Direitos Humanos                   |\n");
       printf("\t\t\t\t\t\t |     Solicita��o do Assento: %d                               |\n",as);
       printf("\t\t\t\t\t\t |     Motivo: Para Envio do Informativo                        |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |     Data: 13/12/2018             Hor�rio: 18:30              |\n");
       printf("\t\t\t\t\t\t |     Local: Unip - Chacara St. Antonio                        |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t |                        Resumo                                |\n");
       printf("\t\t\t\t\t\t |   Hoje em dia as pessoas torcem o nariz para palavra         |\n");
       printf("\t\t\t\t\t\t |   �Direitos Humanos�, pois aqui no Brasil ela sempre         |\n");
       printf("\t\t\t\t\t\t |   sempre est� ligada ao crime e viol�ncia e nunca            |\n");
       printf("\t\t\t\t\t\t |   est� ao lado da v�tima, mas sim daqueles que               |\n");
       printf("\t\t\t\t\t\t |   causaram o Dano. Por�m o que ningu�m sabe que              |\n");
       printf("\t\t\t\t\t\t |   na d�cada de 40 em uma reuni�o em paris, foram             |\n");
       printf("\t\t\t\t\t\t |   lan�ados 30 artigos no rastro da segunda Guerra            |\n");
       printf("\t\t\t\t\t\t |   Mundial, pois a falta de puni��o contra governos           |\n");
       printf("\t\t\t\t\t\t |   autorit�rios, trabalho escravo, tortura, discrimina��o,    |\n");
       printf("\t\t\t\t\t\t |   fome e pobreza violava todos os dias a vida dos seres      |\n");
       printf("\t\t\t\t\t\t |   humanos da �poca.                                          |\n");
       printf("\t\t\t\t\t\t |                                                              |\n");
       printf("\t\t\t\t\t\t +==============================================================+\n\n");

       getch();

    }
    else{
       printf("\t\t\t\t\t\t Assento Inv�lido \n");
       getch();
    }
       getch();

}

void realizar_sorteio()
{
    srand(time(0)); // escolhe sequencia de numeros aleatorios
    int valores[] = {1, 2, 3, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};
    int n = sizeof valores / sizeof *valores;
    valores[rand()%n];
    printf("\t\t\t\t\t\t\t\t +================================+ \n");
    printf("\t\t\t\t\t\t\t\t PARAB�NS !!!! \n");
    printf("\t\t\t\t\t\t\t\t ***Assento:%d ***\n",valores[rand()%n]);
    printf("\t\t\t\t\t\t\t\t Voc� foi Sorteado!!!!!");
    getch();



}
