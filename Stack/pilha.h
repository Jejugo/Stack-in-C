#define TamPilha 100

typedef float elem;

typedef struct {
			int topo;
			elem itens[TamPilha];
} Pilha;

void Create(Pilha*);
void Empty(Pilha*);
int IsEmpty(Pilha*);
int IsFull(Pilha*);
void Push(Pilha*, elem*, int*);
void Pop(Pilha*, elem*, int*);
elem Top(Pilha*, int*);

//funções extras, para exercitar apenas
void Imprimir(Pilha);
int Iguais(Pilha, Pilha);
void Inverter(Pilha*); //poderia usar outras pilhas
