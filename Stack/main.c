//exercício do editor de texto

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

//editor de texto que empilha caracteres
int editor_de_texto(void) {
    elem c, x;
    int erro;
    Pilha P;
    Create(&P);
    printf("Digite seu texto: ");
    while ((c=getche())!='\r') {
          if (c=='#') {
             Pop(&P,&x,&erro);
             if (erro) printf("(erro) ");
             else printf("(%c desempilhado) ",x);
          }
          else if (c=='@') {
               Empty(&P);
               printf("(pilha esvaziada) ");
          }
          else {
               Push(&P,&c,&erro);
               if (erro) printf("(erro) ");
          }
    }
    Inverter(&P);
    printf("\n\nDesempilhando tudo: ");
    
    while (!IsEmpty(&P)) {
          Pop(&P,&x,&erro);
          if (erro) printf("erro ");
//          else printf("%c ",x);
            else putchar(x);
    }
    putchar('\n');
    system("pause");
    return 0;
}

//calculadora para processamento posfixo de expressoes
int calculadora_posfixa(void) {
    elem x, y, z;
    int erro, i;
    char exp[TamPilha], temp[2];
    
    Pilha P;
    Create(&P);

    printf("Digite sua expressao posfixa: ");
    scanf("%s",exp);

    for (i=0;i<strlen(exp);i++) {
         if ((exp[i]=='+') || (exp[i]=='-') || (exp[i]=='*') || (exp[i]=='/')) {
             Pop(&P,&x,&erro);
             Pop(&P,&y,&erro);
             if (exp[i]=='+')
                z=x+y;
             else if (exp[i]=='-')
                z=y-x;
             else if (exp[i]=='*')
                z=x*y;
             else if (exp[i]=='/')
                z=y/x;
             Push(&P,&z,&erro);
          }
          else {
               temp[0]=exp[i]; temp[1]='\0';
               z=atof(temp);
               Push(&P,&z,&erro);
          }
    }

    z=Top(&P,&erro);
    printf("O resultado da expressao e %f\n",z);
    system("pause");
    return 0;
}

int main(void) {
    //calculadora_posfixa();
    editor_de_texto();
    return 0;
}
