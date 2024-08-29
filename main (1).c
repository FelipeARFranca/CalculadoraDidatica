/*
Codificado por: Felipe de A. R. França

Versão: 1.0

Data: 29/08/2024
Hora: 18:13

Descrição: Calculadora didática de conversão entre bases.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void int_to_bin(int n);
void int_to_oct(int n);
void int_to_hex(int n);
void int_to_bcd(int n);

int main (void){

  int int_num;
  float float_num;

  int choice;
  
  while(1){
    printf("===================== CALCULADORA DIDÁTICA =====================\n");

    printf("Escolha uma das seguintes opções:\n");
    printf("1 - Decimal para Binário (8bits)\n");
    printf("2 - Decimal para Octal (8bits)\n");
    printf("3 - Decimal para Hexadecimal (8bits)\n");
    printf("4 - Decimal para BCD (12bits)\n");
    printf("\n0 - Sair\n");
    
    printf("===============================================================\n");
    printf("\n\n");
    printf("> ");
    scanf("%d", &choice);

    if(choice == 0){
      printf("Saindo...\n");
      break;
    }
    else if (choice == 1){
      printf("Digite um número inteiro: ");
      scanf(" %d", &int_num);
      printf("\n");

      if (int_num > 255){
        printf("!OVERFLOW!\n");
        printf("Numero escolhido excede o limite de 8bits!\n");
      }
      else{
        int_to_bin(int_num);
        printf("\n");
      }
    }
    else if (choice == 2){
      printf("Digite um número inteiro: ");
      scanf(" %d", &int_num);
      printf("\n");
      if (int_num > 255){
        printf("!OVERFLOW!\n");
        printf("Numero escolhido excede o limite de 8bits!\n");
      }
      else{
        int_to_oct(int_num);
        printf("\n");
      }
    }
    else if (choice == 3){
      printf("Digite um número inteiro: ");
      scanf(" %d", &int_num);
      printf("\n");
      if (int_num > 255){
        printf("!OVERFLOW!\n");
        printf("Numero escolhido excede o limite de 8bits!\n");
      }
      else{
        int_to_hex(int_num);
        printf("\n");
      }
      
    }
    else if (choice == 4){
      printf("Digite um número inteiro: ");
      scanf(" %d", &int_num);
      printf("\n");
      if (int_num > 999){
        printf("!OVERFLOW!\n");
        printf("Numero escolhido excede o limite de 12bits!\n");
      }
      else{
        int_to_bcd(int_num);
        printf("\n");
      }
    }




    
  }


  
}

void int_to_bin(int n){

  int bin[8];

  for (int i = 0; i < 8; i++){
    bin[i] = 0;
  }

  printf("Para a conversão de decimal para binário, é necessário dividir o número por 2 até que o resultado seja 0.\n\n");
  
  int i = 0;
  int originaln = n;

  if (n == 0){
    printf(" %d |___2___\n", n);
    printf(" %d   %d\n", n % 2, n / 2);
    printf("\n");
  }
  
  while (n != 0){
  
    bin[7 - i] = n % 2;

    printf(" %d |___2___\n", n);
    printf(" %d   %d\n", n % 2, n / 2);
    printf("\n");
    
    n = n / 2;
    i++;
  }

  printf("Agora, basta escrever os restos das divisões da direita para a esquerda.\n");
  printf("Fazer isso ordena os bits em ordem de significância.\n\n");
  printf("+ significante <------------------> - significante\n\n");
  printf("O número %d em binário fica: ", originaln);
  

  for (int i = 0; i < 8; i++){
    printf("%d", bin[i]);
  }
  printf("\n");
}

void int_to_oct(int n){
  int oct[3];
  
  for (int i = 0; i < 3; i++){
    oct[i] = 0;
  }

  printf("Para a conversão de decimal para octal, é necessário dividir o número por 8 até que o resultado seja 0.\n\n");
  
  int i = 0;
  int originaln = n;

  if (n == 0){
    printf(" %d |___8___\n", n);
    printf(" %d   %d\n", n % 8, n / 8);
    printf("\n");
  }
  
  while (n != 0){
    
    oct[2 - i] = n % 8;

    printf(" %d |___8___\n", n);
    printf(" %d   %d\n", n % 8, n / 8);
    printf("\n");
    
    n = n / 8;
    i++;

  }

  printf("Agora, basta escrever os restos das divisões da direita para a esquerda.\n\n");
  printf("O número %d em octal fica: ", originaln);
  
  for (int i = 0; i < 3; i++){
    printf("%d", oct[i]);
  }
  printf("\n");
}

void int_to_hex(int n){
  int hex[2];
  
  for (int i = 0; i < 2; i++){
    hex[i] = 0;
  }
  printf("Para a conversão de decimal para hexadecimal, é necessário dividir o número por 16 até que o resultado seja 0.\n\n");
  
  int i = 0;
  int originaln = n;

  if (n == 0){
    printf(" %d |___16___\n", n);
    printf(" %d   %d\n", n % 16, n / 16);
    printf("\n");
  }
  
  while (n != 0){
    
    hex[1 - i] = n % 16;
    printf(" %d |___16___\n", n);
    printf(" %d   %d\n", n % 16, n / 16);
    printf("\n");
    
    n = n / 16;
    i++;
  }
  
  printf("Agora, basta escrever os restos das divisões da direita para a esquerda, substituindo os números de 10 a 15 por A a F, respectivamente.\n\n");
  printf("O número %d em hexadecimal fica: ", originaln);
  
  for (int i = 0; i < 2; i++){
    if (hex[i] < 10){
      printf("%d", hex[i]);
    }
    else if (hex[i] == 10){
      printf("A");
    }
    else if (hex[i] == 11){
      printf("B");
    }
    else if (hex[i] == 12){
      printf("C");
    }
    else if (hex[i] == 13){
      printf("D");
    }
    else if (hex[i] == 14){
      printf("E");
    }
    else if (hex[i] == 15){
      printf("F");
    }
  }
  printf("\n");
}

void int_to_bcd(int n){
  
  int cent = n / 100;
  int dez = (n - (cent * 100)) / 10;
  int uni = n - (cent * 100) - (dez * 10);

  int originalcent = cent;
  int originaldez = dez;
  int originaluni = uni;
  

  int binC[4];
  int binD[4];
  int binU[4];

  for (int i = 0; i < 4; i++){
    binC[i] = 0;
    binD[i] = 0;
    binU[i] = 0;
  }

  printf("Para a conversão de decimal para BCD, é necessário converter cada dígito individualmente para binário.\n\n");

  printf("Para o número %d, temos os dígitos: %d, %d e %d\n\n", n, cent, dez, uni);

  int i = 0;

  if (cent == 0){
    printf(" %d |___2___\n", cent);
    printf(" %d   %d\n", cent % 2, cent / 2);
    printf("\n");
  }

  while (cent != 0){

    binC[3 - i] = cent % 2;
    
    printf(" %d |___2___\n", cent);
    printf(" %d   %d\n", cent % 2, cent / 2);
    printf("\n");

    cent = cent / 2;
    i++;
  }

  printf("%d -> ",originalcent);
  for (int i = 0; i < 4; i++){
    printf("%d", binC[i]);
  }
  printf("\n\n");
  printf("----------------------\n");
  
  i = 0;

  if (dez == 0){
    printf(" %d |___2___\n", dez);
    printf(" %d   %d\n", dez % 2, dez / 2);
    printf("\n");
  }
  
  while (dez != 0){

    binD[3 - i] = dez % 2;
    
    printf(" %d |___2___\n", dez);
    printf(" %d   %d\n", dez % 2, dez / 2);
    printf("\n");

    dez = dez / 2;
    i++;
  }
  
  printf("%d -> ",originaldez);
  for (int i = 0; i < 4; i++){
    printf("%d", binD[i]);
  }
  printf("\n\n");
  printf("----------------------\n");
  

  i = 0;

  if (uni == 0){
    printf(" %d |___2___\n", uni);
    printf(" %d   %d\n", uni % 2, uni / 2);
    printf("\n");
  }
  
  while (uni != 0){

    binU[3 - i] = uni % 2;

    printf(" %d |___2___\n", uni);
    printf(" %d   %d\n", uni % 2, uni / 2);
    printf("\n");

    uni = uni / 2;
    i++;
  }

  printf("%d -> ",originaluni);
  for (int i = 0; i < 4; i++){
    printf("%d", binU[i]);
  }
  printf("\n\n");
  printf("----------------------\n\n");

  printf("Agora, basta escrever as conversões em binário na ordem dos dígitos originais.\n\n");
  printf("O número %d em BCD fica: ", n);

  for (int i = 0; i < 4; i++){
    printf("%d", binC[i]);
  }
  for (int i = 0; i < 4; i++){
    printf("%d", binD[i]);
  }
  for (int i = 0; i < 4; i++){
    printf("%d", binU[i]);
  }
  printf("\n");
}