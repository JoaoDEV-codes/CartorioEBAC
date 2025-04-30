#include <stdio.h>    // biblioteca de comunicação com o usuário
#include <stdlib.h>   // biblioteca de alocação de espaço em memória
#include <locale.h>   // biblioteca de alocação de texto por região 
#include <string.h>   // biblioteca responsável por cuidar das string



int Registro()     //Função responsável por cadastrar usuários no sistema 
{
	
	setlocale(LC_ALL, "Portuguese");      //Definindo linguagem
	
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF para cadastro aqui: ");   //solicitando o dado de usuário (id "chave" principal) 
	scanf("%s", cpf);    // %s refere-se a string
	
	strcpy(arquivo, cpf);     //reponsavél por copiar valores da string
	
	FILE *file;     // cria o arquivo no banco de dados( no caso esse do proprio cumputador)
	file = fopen(arquivo, "w"); //cria o arquivo "w" significa escrever 
	fprintf(file,cpf);    // salva o valor da variavel
	fclose(file);           // fecha o arquivo
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informações do usuário 
    fclose(file);                //fecha o arquivo 
    
    printf("Digite o nome para cadastro aqui: ");      //mensagem para usuário
    scanf("%s", nome);          // Tipo de string/informação
    
    file = fopen(arquivo,"a");   // "a" serve para atualizar o arquivo
    fprintf(file,nome);          //comando para colocar o nome no arquivo
    fclose(file);                //fecha o arquivo
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informações do usuário
    fclose(file);                //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado aqui: ");       // mensagem para o usuário
    scanf("%s", sobrenome);       //tipo de string/informação
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
	fprintf(file,sobrenome);      //comando para colocar o sobrenome no arquivo
	fclose(file);                //fecha o arquivo
	
	file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informações do usuário
    fclose(file);                //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");          //mensagem para o usuário
    scanf("%s", cargo);          //tipo de string/informação
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,cargo);          //comando para colocar o cargo no arquivo
    fclose(file);                //fecha o arquivo
    
    file = fopen(arquivo, "a");    // "a" serve para atualizar o arquivo
    fprintf(file,",");            // para colocar "," entre as informações do usuário
    fclose(file);                //fecha o arquivo
    
    system("pause");             //pausa o programa 
    
    
}

int Consultar()   //Função responsável por consultar os informações solicitadas
{
	setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
	
	//inicio da criação de variaveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação das variaveis/string
	printf("Digite aqui o CPF a ser consultado: ");                 //mensagem para o usuário
	scanf("%s", cpf);                     //refere-se a string 
	
	FILE *file;         //
	file = fopen(cpf, "r");            //comando para ler o arquivo 
	
	if(file == NULL)        //caso nao achar o arquivo 
	{
		printf("Não foi possivel localizar esse CPF ou Usuário!.\n");   // mensagem para o usuário
	}
	
	while(fgets(conteudo, 300, file) != NULL)          //função 
	{
		printf("\nEssas são as informações do usuário:");   //mensagem para usuário
		printf("%s", conteudo);  //refere-se a string
		printf("\n\n");   //comando para pular 2 linhas
	}
	
	system("pause");                 //pausa o programa 
}

int Deletar()    //Função responsável por deletar os usuários do banco de dados   
{
	setlocale(LC_ALL, "Portuguese");    //definindo linguagem
	
	//inicio da criação de variaveis/string
	char cpf[40];
	//fim da criação de variaveis/string
	
	printf("Digite o CPF a ser deletado: ");         //mensagem para usuário
	scanf("%s",cpf);                //refere-se a string
	
	
	FILE *file;                    
	file = fopen(cpf,"r");        //comando para abrir e ler o arquivo
	
	if(file == NULL)           //caso não achar o arquivo
	{
		printf("O usuário não foi encontrado no sistema!.\n");   //mensagem para usuário
		system("pause");    //pausa o programa
	}
	
	else       //caso achar o arquivo 
	{
	
	fclose(file); // Fecha o arquivo, pois ele existe
    remove(cpf); // Agora você pode remover o arquivo

    printf("Usuário deletado!\n");   //mensagem ao usuário
    system("pause");                // pausa a tela 
	}
	
	
}




int main()
{
	int opcao=0;    // Definindo variável
	int x=1;
	
	for(x=1;x=1;)
	{
	
        system("cls");     //responsavél por limpar a tela 
    
        setlocale(LC_ALL, "Portuguese");  // Definindo a linguagem
    
        printf("### Cartório da EBAC ###\n\n");  //Inicio do menu
        printf("Escolha a opção desejada no menu\n\n");
        printf("\t1 - Resgistrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");  // Fim do menu
        
        scanf("%d", &opcao);  //Armazenando a escolha do usuário
        
        system("cls");        //Responsável por limpar a tela 
        
        
        switch(opcao)          //inicio da seleção de menu
        {
        	case 1:
        	Registro();       //chamada de função
        	break;
        		
        	case 2:
        	Consultar();       //chamada de função
        	break;
        		
        	case 3:
        	Deletar();       //chamada de função
        	break;
        		
        	default:
        	printf("Essa opção não esta disponivel\n");     //mensagem para usuário    
			system("pause");        // pausa a tela 
			break;
				// fim da seção
        		
		}
     }
}

