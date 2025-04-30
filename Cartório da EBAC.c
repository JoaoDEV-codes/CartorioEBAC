#include <stdio.h>    // biblioteca de comunica��o com o usu�rio
#include <stdlib.h>   // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>   // biblioteca de aloca��o de texto por regi�o 
#include <string.h>   // biblioteca respons�vel por cuidar das string



int Registro()     //Fun��o respons�vel por cadastrar usu�rios no sistema 
{
	
	setlocale(LC_ALL, "Portuguese");      //Definindo linguagem
	
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF para cadastro aqui: ");   //solicitando o dado de usu�rio (id "chave" principal) 
	scanf("%s", cpf);    // %s refere-se a string
	
	strcpy(arquivo, cpf);     //reponsav�l por copiar valores da string
	
	FILE *file;     // cria o arquivo no banco de dados( no caso esse do proprio cumputador)
	file = fopen(arquivo, "w"); //cria o arquivo "w" significa escrever 
	fprintf(file,cpf);    // salva o valor da variavel
	fclose(file);           // fecha o arquivo
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informa��es do usu�rio 
    fclose(file);                //fecha o arquivo 
    
    printf("Digite o nome para cadastro aqui: ");      //mensagem para usu�rio
    scanf("%s", nome);          // Tipo de string/informa��o
    
    file = fopen(arquivo,"a");   // "a" serve para atualizar o arquivo
    fprintf(file,nome);          //comando para colocar o nome no arquivo
    fclose(file);                //fecha o arquivo
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informa��es do usu�rio
    fclose(file);                //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado aqui: ");       // mensagem para o usu�rio
    scanf("%s", sobrenome);       //tipo de string/informa��o
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
	fprintf(file,sobrenome);      //comando para colocar o sobrenome no arquivo
	fclose(file);                //fecha o arquivo
	
	file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informa��es do usu�rio
    fclose(file);                //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");          //mensagem para o usu�rio
    scanf("%s", cargo);          //tipo de string/informa��o
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,cargo);          //comando para colocar o cargo no arquivo
    fclose(file);                //fecha o arquivo
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informa��es do usu�rio
    fclose(file);                //fecha o arquivo
    
    system("pause");             //pausa o programa 
    
    
}

int Consultar()   //Fun��o respons�vel por consultar os informa��es solicitadas
{
	setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
	//inicio da cria��o de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o das variaveis/string
	printf("Digite aqui o CPF a ser consultado: ");                 //mensagem para o usu�rio
	scanf("%s", cpf);                     //refere-se a string 
	
	FILE *file;         //
	file = fopen(cpf, "r");            //comando para ler o arquivo 
	
	if(file == NULL)        //caso nao achar o arquivo 
	{
		printf("N�o foi possivel localizar esse CPF ou Usu�rio!.\n");   // mensagem para o usu�rio
	}
	
	while(fgets(conteudo, 300, file) != NULL)          //fun��o 
	{
		printf("\nEssas s�o as informa��es do usu�rio:");   //mensagem para usu�rio
		printf("%s", conteudo);  //refere-se a string
		printf("\n\n");   //comando para pular 2 linhas
	}
	
	system("pause");                 //pausa o programa 
}

int Deletar()    //Fun��o respons�vel por deletar os usu�rios do banco de dados   
{
	setlocale(LC_ALL, "Portuguese");    //definindo linguagem
	
	//inicio da cria��o de variaveis/string
	char cpf[40];
	//fim da cria��o de variaveis/string
	
	printf("Digite o CPF a ser deletado: ");         //mensagem para usu�rio
	scanf("%s",cpf);                //refere-se a string
	
	
	FILE *file;                    
	file = fopen(cpf,"r");        //comando para abrir e ler o arquivo
	
	if(file == NULL)           //caso n�o achar o arquivo
	{
		printf("O usu�rio n�o foi encontrado no sistema!.\n");   //mensagem para usu�rio
		system("pause");    //pausa o programa
	}
	
	else       //caso achar o arquivo 
	{
	
	fclose(file); // Fecha o arquivo, pois ele existe
    remove(cpf); // Agora voc� pode remover o arquivo

    printf("Usu�rio deletado!\n");   //mensagem ao usu�rio
    system("pause");                // pausa a tela 
	}
	
	
}




int main()
{
	int opcao=0;    // Definindo vari�vel
	int x=1;
	
	for(x=1;x=1;)
	{
	
        system("cls");     //responsav�l por limpar a tela 
    
        setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
    
        printf("### Cart�rio da EBAC ###\n\n");  //Inicio do menu
        printf("Escolha a op��o desejada no menu\n\n");
        printf("\t1 - Resgistrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��o: ");  // Fim do menu
        
        scanf("%d", &opcao);  //Armazenando a escolha do usu�rio
        
        system("cls");        //Respons�vel por limpar a tela 
        
        
        switch(opcao)          //inicio da sele��o de menu
        {
        	case 1:
        	Registro();       //chamada de fun��o
        	break;
        		
        	case 2:
        	Consultar();       //chamada de fun��o
        	break;
        		
        	case 3:
        	Deletar();       //chamada de fun��o
        	break;
        		
        	default:
        	printf("Essa op��o n�o esta disponivel\n");     //mensagem para usu�rio    
			system("pause");        // pausa a tela 
			break;
				// fim da se��o
        		
		}
     }
}

