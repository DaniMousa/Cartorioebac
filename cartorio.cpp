#include <stdio.h> //bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca nde aloca�o�es de texto por regi�o
#include <string.h> //biblioteca de strings

int registro() //Fun��o responsavel por cadastar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�srio
	scanf("%s", cpf);//"%s" refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo ("w" significa "escrever")
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");//Adiciona uma virgula e um espa�o, para facilita��o da leitura
	fclose(file);
	
	printf("Digite o primeiro nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) 
	{
		printf("Arquivo n�o localizado.\n");
	}
	
	while(fgets (conteudo, 200, file) != NULL) //cria um la�o de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio  a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)//caso o cpf inserido n�o exista
	{
		printf("Usu�rio n�o encontrado.\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)//caso o cpf inserido exista
	{
		printf("Usu�rio deletado com sucesso.\n");
		system("pause");
	}

	
	

}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{

		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//Definindo a limguagem
	
		printf("### cart�rio da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar momes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair\n");
		printf("\n	op��o:");//Fim do menu
	
		scanf("%d", &opcao);//Armazenamento da escolha do usu�rio
	
		system("cls");
		
		switch(opcao)//Inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��o
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nossos sevi�os!\n");
			return 0;
			break;
			
			default:
			printf("Esta op��o n�o esta disponivel.\nPor favor escolha uma op��o de 1 a 3.\n");
			system("pause");
			break;//fim da sele��o
		}

	}
}
