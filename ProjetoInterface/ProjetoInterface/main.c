#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>  // Necessário para getch()

float custo_por_pessoa;
float total_custos;
int total_pessoas;
float conta;

// Criar funcao de X e Y

void XY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



// case 1
int ADDPessoas()
{
	int Pessoa;
	system("CLS");
	XY(40, 8);
	printf("Quantas pessoas deseja adicionar?");
	XY(1, 29);
	scanf_s("%d", &Pessoa);
	Sleep(2);
	system("CLS");
	return total_pessoas += Pessoa;
}
// case 2
float ADDCustos()
{
	float custo;
	system("CLS");
	XY(40, 8);
	printf("Qual o valor do custo adicional?");
	XY(1, 29);
	scanf_s("%f", &custo);
	Sleep(2);
	system("CLS");
	return total_custos += custo;
}
// case 3
int GarconTotalCustos(float* total_custos, float* conta)
{
	int ValorGarcon = 10;

	// Calculo da gorgeta
	*conta = (*total_custos * ValorGarcon) / 100;

	system("CLS");
	XY(1, 28);
	printf("Total da Nota Fiscal: %.2f", *total_custos);
	XY(1, 29);
	printf("Gorjeta: %.2f", *conta);
	Sleep(4000);
	system("CLS");
	return *conta;
}
//case 4
float TotalAPagarPorPessoa(int* total_pessoas, float* total_custos, float* conta)
{
	system("CLS");
	if (*total_pessoas > 0)
	{
		XY(40, 8);
		printf("O valor total consumido: R$ %.2f", *total_custos);
		XY(40, 9);
		printf("Gorjeta do Garson: %.2f", *conta);
		XY(40, 10);
		printf("Total da Nota Fiscal + Gorjeta: %.2f", *total_custos + *conta);
		XY(40, 11);
		printf("==========================================");
		custo_por_pessoa = (*total_custos + *conta) / *total_pessoas;
		XY(40, 12);
		printf("Cada pessoa deve pagar: R$ %.2f", custo_por_pessoa);
		Sleep(6500);
		system("CLS");
	}
	else {
		XY(1, 29);
		printf("Nao foi possivel dividir conta para (%d) pessoas!!", *total_pessoas);
		Sleep(6500);
		system("CLS");
		return ADDPessoas();
	}

	return 0;
}








int main()
{
	int Escolha;
	int x;
	int y;
	char tecla;

	// laço de repeticao MENU

	while (1)
	{
		XY(36, 4); // XY (X: linha Y: coluna)
		printf("-- MENU GERENCIAMENTO CONTA DE BAR --");
		XY(40, 8);
		printf("Adicionar mais pessoas");
		XY(40, 9);
		printf("Adicionar mais custos");
		XY(40, 10);
		printf("Contultar o total de custo da mesa");
		XY(40, 11);
		printf("Dividir a conta");
		XY(40, 12);
		printf("SAIR");
		Escolha = 0;
		y = 8;
		XY(36, y);
		printf("-->");

		while (1) // loop para mover a seta
		{
			setvbuf(stdin, NULL, _IONBF, 0); // limpa o buffer de entrada
			tecla = _getch(); // capitura a tecla e add na variavel tecla

			if (tecla == 13) // codigo 13 é a tecla ENTER no caso estou verificando se foi pressionado tecla ENTER	
			{
				if (Escolha == 0) ADDPessoas();
				if (Escolha == 1) ADDCustos();
				if (Escolha == 2) GarconTotalCustos(&total_custos, &conta);
				if (Escolha == 3) TotalAPagarPorPessoa(&total_pessoas, &total_custos, &conta);
				if (Escolha == 4) return 0;

				break;
			}

			if (tecla == 72 || tecla == 80) // tecla cima 72 && tecla baixo 80
			{
				XY(36, y);
				printf("    "); // Apaga a seta atual
				// configurar setas para cima e para baixo
				if (tecla == 72) Escolha--; // Seta para baixo
				else if (tecla == 80) Escolha++; // Seta para cima

				// configurar o limite das setas manter no padrao do menu
				if (Escolha == -1) Escolha = 4;
				else if (Escolha == 5) Escolha = 0;

				// ajustar a posicao da minha seta conforme a base da escolha
				if (Escolha == 0) y = 8;
				else if (Escolha == 1) y = 9;
				else if (Escolha == 2) y = 10;
				else if (Escolha == 3) y = 11;
				else if (Escolha == 4) y = 12;
				XY(36, y);
				printf("-->");
			}
		}
	}
}


/*
Códigos ASCII para teclas comuns:
Enter: 13
Espaço (Space): 32
Escape (Esc): 27
Backspace: 8
Tab: 9
Códigos para letras e números:
Letras maiúsculas (A-Z): 65 - 90
Letras minúsculas (a-z): 97 - 122
Números (0-9): 48 - 57
Códigos para teclas de controle (modificadas):
As teclas de controle, como as setas, têm dois códigos: um prefixo (224 ou 0) e o código da tecla em si. Portanto, ao capturar uma dessas teclas com _getch(), você terá que chamar _getch() duas vezes.

Exemplo de códigos de setas:
Seta para esquerda: 224, 75
Seta para direita: 224, 77
Seta para cima: 224, 72
Seta para baixo: 224, 80
Exemplo de códigos de teclas de função (F1 - F12):
F1: 0, 59
F2: 0, 60
F3: 0, 61
F4: 0, 62
F5: 0, 63
F6: 0, 64
F7: 0, 65
F8: 0, 66
F9: 0, 67
F10: 0, 68
F11: 224, 133
F12: 224, 134
*/