
struct unDisco {
  char titulo[33];
  char artista[26];
  int fecha;
  char formato [3];
  float precio;
};

int iniciar(struct unDisco *tabla,int *numero);
int finalizar(struct unDisco *tabla,int numero);
int validanum(char numero[]);
void listar(struct unDisco *tabla, int numero);
int agregar(struct unDisco *tabla, int *numero);
int ver(struct unDisco *tabla, int numero);
int eliminar(struct unDisco *tabla, int *numero);
int modificar(struct unDisco *tabla, int numero);
void todos(struct unDisco *tabla, int numero);
void salir(char frase[], int *salir, struct unDisco *tabla,int numero);

