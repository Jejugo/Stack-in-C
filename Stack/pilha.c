#include "pilha.h"

void Create(Pilha *P) {
     P->topo=-1;
     return;
}

void Empty(Pilha *P) {
     P->topo=-1;
     return;
}

int IsEmpty(Pilha *P) {
    if (P->topo==-1)
       return 1;
    else return 0;
}

int IsFull(Pilha *P) {
    if (P->topo==TamPilha-1)
       return 1;
    else return 0;
}

void Push(Pilha *P, elem *X, int *erro) {
     if (!IsFull(P)) {
          *erro=0;
          P->topo++;
          P->itens[P->topo]=*X;
     }
     else *erro=1;
     return;
}

void Pop(Pilha *P, elem *X, int *erro) {
     if (!IsEmpty(P)) {
          *erro=0;
          *X=P->itens[P->topo];
          P->topo--;
     }
     else *erro=1;
     return;
}

elem Top(Pilha *P, int *erro) {
     if (!IsEmpty(P)) {
          *erro=0;
          return(P->itens[P->topo]);
     }
     else *erro=1;
     return(-1);
}


//funções extras abaixo, para exercitar a manipulação de pilhas

void Imprimir(Pilha P) {
     elem x;
     int erro;

     printf("Pilha: ");
     while (!IsEmpty(&P)) {
           Pop(&P,&x,&erro);
           printf("%d ",x);
     }
     printf("\n");

}

int Iguais(Pilha P1, Pilha P2) {
    elem x1, x2;
    int erro1, erro2;

    while ((!IsEmpty(&P1)) || (!IsEmpty(&P2))) {
       Pop(&P1,&x1,&erro1);
       Pop(&P2,&x2,&erro2);
       if ((x1!=x2) || (erro1!=erro2))
          return 0;
    }

    return(1);
}

void Inverter(Pilha *P) {
     elem x;
     int erro, i= -1, j;
     elem v[TamPilha];

     while (!IsEmpty(P)) {
           Pop(P,&x,&erro);
           i++;
           v[i]=x;
     }

     for (j=0;j<=i;j++)
         Push(P,&v[j],&erro);
     return;
}
