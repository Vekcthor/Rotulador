/*
	Name: Rotulador automatico
	Author: Victor Silva Azevedo
	Date: 19/04/16 13:56
	Last change: 03/05/16 14:19

*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

main()
{
    setlocale(LC_ALL, "Portuguese");//comando usado para que o progama identifique o alfabeto latino
	
	char ing[100][100];
	int  tamanho=100;
	float quant[100];
	float porcentagem[100];
	int soma=0;
	int counter=0,linha;
	int limit=0;
	char aux2[100];

	for(;;)
	{
		printf("Escreva o Nome do %dº Ingrediente:", counter+1);
		scanf("%s", &ing[counter]);
		printf("Escreva a Quantidade Desse Ingrediente(Em gramas):");
		scanf("%f", &quant[counter]);
		printf("Se Quiser Adicionar mais Ingredientes, Digite 1, Senão 0:");
		scanf("%d", &linha);
		soma=soma+quant[counter];
		counter++;
		limit++;
		system("cls");
		if(linha==0)
		{
        break; //força a saída do loop
    	}
    }
    
    for(int contador1=limit-1; contador1 >= 1; contador1--) 
    {  
        for(int contador2=0; contador2 < contador1 ; contador2++) 
        {
            if(quant[contador2]>quant[contador2+1]) 
            {
                int aux = quant[contador2];
                quant[contador2] = quant[contador2+1];
                quant[contador2+1] = aux;
                
                strcpy (aux2,ing[contador2]);
                strcpy (ing[contador2],ing[contador2+1]);
                strcpy (ing[contador2+1],aux2);
            }
        }
    }
    for(int cont=0;cont<limit;cont++)
	{

	 porcentagem[cont]=(100*quant[cont])/soma;
 
    }
    int ingt=1;
    for(int cont=limit-1;cont>=0;cont--)
	{
		
		printf("O %dº Ingrediente é:%s Sua quantidade é:%.0fg E sua porcentagem é:%.3f%%\n", ingt, ing[cont],quant[cont],porcentagem[cont]);
		ingt=ingt++;
		
	}
	printf("Total dos Ingredientes é:%d Gramas",soma);
	getch();
   /*do
   {
   	i=linha++;
	printf("Escreva o nome do ingrediente:");
	scanf("%c",&str);
	j = strlen(str);
	sair[j]=str[j];
	ing[i][j]=sair[j];
	printf("%c\n",ing[i][j]);
	getch();
	printf("Deseja adicionar mais ingredientes?\n(Digite 1 para sim, 0 para adicionar a quantidade):");
	scanf("%i",&counter); 
	system("cls");
   }while(counter==1);
	printf("Funfou");
	getch();*/
}

