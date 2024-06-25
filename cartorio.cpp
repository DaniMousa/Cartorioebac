#include <stdio.h> //bliblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca nde alocaçoões de texto por região
#include <string.h> //biblioteca de strings

int registro() //Função responsavel por cadastar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuásrio
	scanf("%s", cpf);//"%s" refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");// cria o arquivo ("w" significa "escrever")
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");//Adiciona uma virgula e um espaço, para facilitação da leitura
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
		printf("Arquivo não localizado.\n");
	}
	
	while(fgets (conteudo, 200, file) != NULL) //cria um laço de repetição
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário  a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)//caso o cpf inserido não exista
	{
		printf("Usuário não encontrado.\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)//caso o cpf inserido exista
	{
		printf("Usuário deletado com sucesso.\n");
		system("pause");
	}

	
	

}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{

		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//Definindo a limguagem
	
		printf("### cartório da EBAC ###\n\n");//Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar momes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair\n");
		printf("\n	opção:");//Fim do menu
	
		scanf("%d", &opcao);//Armazenamento da escolha do usuário
	
		system("cls");
		
		switch(opcao)//Inicio da seleção do menu
		{
			case 1:
			registro();//chamada de função
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nossos seviços!\n");
			return 0;
			break;
			
			default:
			printf("Esta opção não esta disponivel.\nPor favor escolha uma opção de 1 a 3.\n");
			system("pause");
			break;//fim da seleção
		}

	}
}
