/*
Codificado por: Felipe de A. R. França

Versão: 1.3

Data: 30/08/2024
Hora: 22:58

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

void int_to_signed_bin(int n);

void real_to_float(float n);
void real_to_double(double n);

int main (void){

  int int_num;
  float float_num;
  double double_num;

  int choice;
  
  while(1){
    printf("===================== CALCULADORA DIDÁTICA =====================\n");

    printf("Escolha uma das seguintes opções:\n");
    printf("1 - Decimal para Binário (8bits)\n");
    printf("2 - Decimal para Octal (8bits)\n");
    printf("3 - Decimal para Hexadecimal (8bits)\n");
    printf("4 - Decimal para BCD (12bits)\n\n");
    printf("5 - Decimal para Binário com Sinal (16bits)\n\n");
    printf("6 - Decimal para Float (32bits)\n");
    printf("7 - Decimal para Double (64bits)\n\n");
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
        printf("Número escolhido excede o limite de 8bits!\n");
      }
      else if (int_num < 0){
        printf("Número escolhido é negativo!\n");
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
        printf("Número escolhido excede o limite de 8bits!\n");
      }
      else if (int_num < 0){
        printf("Número escolhido é negativo!\n");
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
        printf("Número escolhido excede o limite de 8bits!\n");
      }
      else if (int_num < 0){
        printf("Número escolhido é negativo!\n");
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
        printf("Número escolhido excede o limite de 12bits!\n");
      }
      else if (int_num < 0){
        printf("Número escolhido é negativo!\n");
      }
      else{
        int_to_bcd(int_num);
        printf("\n");
      }
    }
    else if (choice == 5){
      printf("Digite um número inteiro: ");
      scanf(" %d", &int_num);
      printf("\n");
      if (int_num > 32767){
        printf("!OVERFLOW!\n");
        printf("Número escolhido excede o limite de 16bits!\n");
      }
      else if (int_num < -32768){
        printf("!OVERFLOW!\n");
        printf("Número escolhido excede o limite de 16bits!\n");
      }
      else{
        int_to_signed_bin(int_num);
        printf("\n");
      }
    }
    else if (choice == 6){
      printf("Digite um número real: ");
      scanf(" %f", &float_num);
      printf("\n");
      real_to_float(float_num);
      printf("\n");
    } 
    else if (choice == 7){
      printf("Digite um número real: ");
      scanf(" %lf", &double_num);
      printf("\n");
      real_to_double(double_num);
      printf("\n");
    }
    else{
      printf("Opção inválida!\n");
    }




    
  }

  return 0;
  
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

void int_to_signed_bin(int n){
  int bin[16];
  for (int i = 0; i < 16; i++){
    bin[i] = 0;
  }
  int i = 0;
  int originaln = n;
  int positive;

  printf("Para a conversão de decimal para binário com sinal, é necessário primeiro checar o sinal do número.\n");
  printf("Se o número for positivo, basta converter para binário normalmente, dividindo o número até que o resultado seja 0.\n");
  printf("Se o número for negativo, será necessário fazer o complemento a 2 do mesmo número com sinal positivo.\n\n");
  
  if (n < 0){

    printf("O número escolhido é negativo, então o complemento a 2 será necessário.\n\n");
    
    positive = n * -1;

    printf("Primeiro, fazemos a conversão do número para um número positivo: %d x (-1) = %d\n\n", n, positive);

    printf("Agora, fazemos a conversão do número positivo para binário normalmente.\n\n");

    while (positive != 0){

      bin[15 - i] = positive % 2;

      printf(" %d |___2___\n", positive);
      printf(" %d   %d\n", positive % 2, positive / 2);
      printf("\n");

      positive = positive / 2;
      i++;
    }

    printf("Agora, basta escrever os restos das divisões da direita para a esquerda.\n");
    printf("Fazer isso ordena os bits em ordem de significância.\n\n");
    printf("+ significante <------------------> - significante\n\n");
    printf("Assim, obtemos: ");
    
    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf("\n\n");

    printf("Agora, para fazer o complemento a 2, primeiro invertemos os bits.\n\n");

    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf(" -> ");

    for(int i = 0; i < 16; i++){
      if (bin[i] == 0){
        bin[i] = 1;
      }
      else{
        bin[i] = 0;
      }
    }

    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf("\n\n");

    printf("Agora, somamos 1 ao número.\n\n");
    
    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf("\n");
    printf("+              1\n");
    printf("----------------\n");

    

    for(int i = 0; i < 16; i++){
      if (bin[15 - i] + 1 == 2){
        bin[15 - i] = 0;
      }
      else{
        bin[15 - i] = bin[15 - i] + 1;
        break;
      }
    }

    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf("\n\n");

    printf("O número %d em binário com sinal fica: ", originaln);
    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf("\n");
    
  }
  else if (n == 0){
    
    printf("O número escolhido é 0, então o complemento a 2 não será necessário.\n\n");
    printf("Agora, fazemos a conversão do número para binário normalmente.\n\n");

    printf(" %d |___2___\n", n);
    printf(" %d   %d\n", n % 2, n / 2);
    printf("\n");


    printf("Agora, basta escrever os restos das divisões da direita para a esquerda.\n");
    printf("Fazer isso ordena os bits em ordem de significância.\n\n");
    printf("+ significante <------------------> - significante\n\n");

    printf("O número %d em binário com sinal fica: ", originaln);

    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf("\n");
  }
  else{
    positive = n;

    printf("O número escolhido é positivo, então o complemento a 2 não será necessário.\n\n");

    printf("Agora, fazemos a conversão do número positivo para binário normalmente.\n\n");
    
    while (positive != 0){

      bin[15 - i] = positive % 2;
      
      printf(" %d |___2___\n", positive);
      printf(" %d   %d\n", positive % 2, positive / 2);
      printf("\n");

      positive = positive / 2;
      i++;
    }

    printf("Agora, basta escrever os restos das divisões da direita para a esquerda.\n");
    printf("Fazer isso ordena os bits em ordem de significância.\n\n");
    printf("+ significante <------------------> - significante\n\n");
    
    printf("O número %d em binário com sinal fica: ", originaln);
    for (int i = 0; i < 16; i++){
      printf("%d", bin[i]);
    }
    printf("\n");
  }
}

void real_to_float(float n){
  
  int signal;
  int exponent;

  float originaln = n;

  if (n < 0){
    signal = 1;
    n = n * -1;
  }
  else{
    signal = 0;
  }

  int int_part = (int)n;
  float dec_part = n - int_part;

  int int_bin[8];
  int dec_bin[23];

  for (int i = 0; i < 8; i++){
    int_bin[i] = 0;
  }

  for (int i = 0; i < 23; i++){
    dec_bin[i] = 0;
  }

  int i = 0;

  printf("Para a conversão de real para ponto flutuante, é necessário seguir alguns passos.\n\n");

  printf("1. Guardar o sinal do número.\n\n");

  if (originaln < 0){
    printf("O número escolhido é negativo, então o bit de sinal será 1.\n\n\n");
  }
  else if (originaln > 0){
    printf("O número escolhido é positivo, então o bit de sinal será 0.\n\n\n");
  }
  else{
    printf("O número escolhido é 0, então o bit de sinal será 0.\n\n\n");
  }

  printf("2. Converter o número em real para binário.\n");

  printf("Primeiro, fazemos a conversão da parte inteira para binário.\n\n");

  

  while (int_part != 0){

    int_bin[7 - i] = int_part % 2;
      printf(" %d |___2___\n", int_part);
      printf(" %d   %d\n", int_part % 2, int_part / 2);
      printf("\n");
    
    int_part = int_part / 2;
    i++;
  }
  printf("\n");

  printf("Assim obtemos: ");
  for (int i = 0; i < 8; i++){
    printf("%d", int_bin[i]);
  }
  printf("\n\n");

  printf("Agora, fazemos a conversão da parte decimal para binário.\n\n");
  printf("Para isso, fazemos a multiplicação da parte decimal por 2, até que o resultado tenha apenas uma parte inteira.\n\n");

  i = 0;
  while (dec_part != 0){
    dec_bin[i] = (int)(dec_part * 2);
    printf("%f x 2 = %f\n", dec_part, 2 * dec_part);
    dec_part = dec_part * 2 - (int)(dec_part * 2);
    i++;
  }

  printf("Agora organizamos as partes inteiras das multiplicações da esquerda para a direita.\n\n");
  printf("Assim obtemos: ");
  for (int i = 0; i < 23; i++){
    printf("%d", dec_bin[i]);
  }
  printf("\n\n");

  
  int left_zero_count = 0;
  
  if (n >= 1){
    exponent = 0;
    
    while (int_bin[left_zero_count] == 0){
      left_zero_count++;
    }

    exponent = 8 - left_zero_count - 1;
    
  }
  else{
    exponent = 0;

    while (dec_bin[exponent] == 0){
      exponent++;
    }

    exponent = -1 * (exponent + 1);
  }


  int exponent_bias = 127 + exponent;

  int exponent_bin[8];
  
  for (int i = 0; i < 8; i++){
    exponent_bin[i] = 0;
  }

  i = 0;
  while (exponent_bias != 0){
    exponent_bin[7 - i] = exponent_bias % 2;
    exponent_bias = exponent_bias / 2;
    i++;
  }

  int fraction_bin[23];

  for (int i = 0; i < 23; i++){
    fraction_bin[i] = 0;
  }

  int j = 0;

  int buffer_bin[31];

  for (int i = 0; i < 31; i++){
    if (i < 8){
      buffer_bin[i] = int_bin[i];
    }
    else{
      buffer_bin[i] = dec_bin[i - 8];
    }
  }

  while (buffer_bin[j] == 0){
    j++;
  }

  j++;

  for (int i = j; i < 31; i++){

    fraction_bin[i - j] = buffer_bin[i];
  }

  printf("\n3. Fazer o cálculo do expoente.\n\n");
  printf("Para isso, precisamos primeiro colocar o número que encontramos em notação científica na base 2.\n\n");

  for (int i = 0; i < 8; i++){
    printf("%d", int_bin[i]);
  }
  printf(".");
  for (int i = 0; i < 23; i++){
    printf("%d", dec_bin[i]);
  }
  printf("\n");
  printf("v\n");

  int flag = 0;
  for (int i = 0; i < 31; i++){
    
    printf("%d", buffer_bin[i]);
    
    if (buffer_bin[i] == 1){
      flag ++;
    }
    if (flag == 1){
      printf(".");
    }
    
  }
  printf(" x 2^%d\n", exponent);

  printf("\n");

  printf("Tendo em mãos o expoente, soma-se 127 ao expoente encontrado.\n");
  printf("Assim, obtemos o expoente com viés.\n\n");
  printf("%d + 127 = %d\n\n", exponent, 127 + exponent);

  printf("Fazemos então, a conversão do expoente para binário.\n\n");

  int exponent_biasPrint = 127 + exponent;

  int exponent_binPrint[8];

  for (int i = 0; i < 8; i++){
    exponent_binPrint[i] = 0;
  }

  int k = 0;
  
  while (exponent_biasPrint != 0){
    
    exponent_binPrint[7 - k] = exponent_biasPrint % 2;
    printf(" %d |___2___\n", exponent_biasPrint);
    printf(" %d   %d\n", exponent_biasPrint % 2, exponent_biasPrint / 2);
    printf("\n");
    exponent_biasPrint = exponent_biasPrint / 2;
    i++;
  }

  printf("Assim obtemos o expoente (parte inteira) do nosso número float: ");
  
  for (int i = 0; i < 8; i++){
    printf("%d", exponent_bin[i]);
  }

  printf("\n\n");
  
  printf("4. Fazer o cálculo da mantissa (parte fração).\n\n");

  printf("Para isso, basta separarmos a parte decimal do número que colocamos em notação científica na base 2.\n\n");

  printf("0.");
  for (int i = 0; i < 23; i++){
    printf("%d", fraction_bin[i]);
  }
  printf("\n\n");
  
  printf("Juntando tudo, obtemos o número real em ponto flutuante.\n\n");
  
  printf("Número real %f como float: ", originaln);
  printf("%d ", signal);
  for (int i = 0; i < 8; i++){
    printf("%d", exponent_bin[i]);
  }
  printf(".");
  for (int i = 0; i < 23; i++){
    printf("%d", fraction_bin[i]);
  }
}

void real_to_double(double n){
  int signal;
  int exponent;

  double originaln = n;

  if (n < 0){
    signal = 1;
    n = n * -1;
  }
  else{
    signal = 0;
  }

  int int_part = (int)n;
  double dec_part = n - int_part;

  int int_bin[11];
  int dec_bin[52];

  for (int i = 0; i < 11; i++){
    int_bin[i] = 0;
  }

  for (int i = 0; i < 52; i++){
    dec_bin[i] = 0;
  }

  int i = 0;

  printf("Para a conversão de real para double, é necessário seguir alguns passos.\n\n");

  printf("1. Guardar o sinal do número.\n\n");

  if (originaln < 0){
    printf("O número escolhido é negativo, então o bit de sinal será 1.\n\n\n");
  }
  else if (originaln > 0){
    printf("O número escolhido é positivo, então o bit de sinal será 0.\n\n\n");
  }
  else{
    printf("O número escolhido é 0, então o bit de sinal será 0.\n\n\n");
  }

  printf("2. Converter o número em real para binário.\n");

  printf("Primeiro, fazemos a conversão da parte inteira para binário.\n\n");



  while (int_part != 0){

    int_bin[10 - i] = int_part % 2;
      printf(" %d |___2___\n", int_part);
      printf(" %d   %d\n", int_part % 2, int_part / 2);
      printf("\n");

    int_part = int_part / 2;
    i++;
  }
  printf("\n");

  printf("Assim obtemos: ");
  for (int i = 0; i < 10; i++){
    printf("%d", int_bin[i]);
  }
  printf("\n\n");

  printf("Agora, fazemos a conversão da parte decimal para binário.\n\n");
  printf("Para isso, fazemos a multiplicação da parte decimal por 2, até que o resultado tenha apenas uma parte inteira.\n\n");

  i = 0;
  while (dec_part != 0){
    dec_bin[i] = (int)(dec_part * 2);
    printf("%f x 2 = %f\n", dec_part, 2 * dec_part);
    dec_part = dec_part * 2 - (int)(dec_part * 2);
    i++;
  }

  printf("Agora organizamos as partes inteiras das multiplicações da esquerda para a direita.\n\n");
  printf("Assim obtemos: ");
  for (int i = 0; i < 52; i++){
    printf("%d", dec_bin[i]);
  }
  printf("\n\n");


  int left_zero_count = 0;

  if (n >= 1){
    exponent = 0;

    while (int_bin[left_zero_count] == 0){
      left_zero_count++;
    }

    exponent = 11 - left_zero_count - 1;

  }
  else{
    exponent = 0;

    while (dec_bin[exponent] == 0){
      exponent++;
    }

    exponent = -1 * (exponent + 1);
  }


  int exponent_bias = 1023 + exponent;

  int exponent_bin[11];

  for (int i = 0; i < 11; i++){
    exponent_bin[i] = 0;
  }

  i = 0;
  while (exponent_bias != 0){
    exponent_bin[10 - i] = exponent_bias % 2;
    exponent_bias = exponent_bias / 2;
    i++;
  }

  int fraction_bin[52];

  for (int i = 0; i < 52; i++){
    fraction_bin[i] = 0;
  }

  int j = 0;

  int buffer_bin[63];

  for (int i = 0; i < 63; i++){
    if (i < 11){
      buffer_bin[i] = int_bin[i];
    }
    else{
      buffer_bin[i] = dec_bin[i - 11];
    }
  }

  while (buffer_bin[j] == 0){
    j++;
  }

  j++;

  for (int i = j; i < 63; i++){

    fraction_bin[i - j] = buffer_bin[i];
  }

  printf("\n3. Fazer o cálculo do expoente.\n\n");
  printf("Para isso, precisamos primeiro colocar o número que encontramos em notação científica na base 2.\n\n");

  for (int i = 0; i < 11; i++){
    printf("%d", int_bin[i]);
  }
  printf(".");
  for (int i = 0; i < 52; i++){
    printf("%d", dec_bin[i]);
  }
  printf("\n");
  printf("v\n");

  int flag = 0;
  for (int i = 0; i < 63; i++){

    printf("%d", buffer_bin[i]);

    if (buffer_bin[i] == 1){
      flag ++;
    }
    if (flag == 1){
      printf(".");
    }

  }
  printf(" x 2^%d\n", exponent);

  printf("\n");

  printf("Tendo em mãos o expoente, soma-se 1023 ao expoente encontrado.\n");
  printf("Assim, obtemos o expoente com viés.\n\n");
  printf("%d + 1023 = %d\n\n", exponent, 1023 + exponent);

  printf("Fazemos então, a conversão do expoente para binário.\n\n");

  int exponent_biasPrint = 1023 + exponent;

  int exponent_binPrint[11];

  for (int i = 0; i < 11; i++){
    exponent_binPrint[i] = 0;
  }

  int k = 0;

  while (exponent_biasPrint != 0){

    exponent_binPrint[10 - k] = exponent_biasPrint % 2;
    printf(" %d |___2___\n", exponent_biasPrint);
    printf(" %d   %d\n", exponent_biasPrint % 2, exponent_biasPrint / 2);
    printf("\n");
    exponent_biasPrint = exponent_biasPrint / 2;
    i++;
  }

  printf("Assim obtemos o expoente (parte inteira) do nosso número double: ");

  for (int i = 0; i < 11; i++){
    printf("%d", exponent_bin[i]);
  }

  printf("\n\n");

  printf("4. Fazer o cálculo da mantissa (parte fração).\n\n");

  printf("Para isso, basta separarmos a parte decimal do número que colocamos em notação científica na base 2.\n\n");

  printf("0.");
  for (int i = 0; i < 52; i++){
    printf("%d", fraction_bin[i]);
  }
  printf("\n\n");

  printf("Juntando tudo, obtemos o número real em double.\n\n");

  printf("Número real %lf como double: ", originaln);
  printf("%d ", signal);
  for (int i = 0; i < 11; i++){
    printf("%d", exponent_bin[i]);
  }
  printf(".");
  for (int i = 0; i < 52; i++){
    printf("%d", fraction_bin[i]);
  }
}
