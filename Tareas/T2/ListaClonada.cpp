#include <iostream>
using namespace std;
 
class nodo {
   public:
    nodo(int v, nodo *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    int valor;
    nodo *siguiente;
        
   friend class lista;
};
 
typedef nodo *pnodo;
 
class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();
    
    void Clonar(pnodo nodoraiz);
    
   private:
    pnodo primero;
    pnodo actual;
};
 
lista::~lista() {
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

//metodo Clonar
void lista::Clonar(pnodo nodoraiz){
    pnodo aux = nodoraiz; // constante = 1
    while(aux->siguiente!=NULL){ // ciclo while = log(n)
        if(ListaVacia()){
            primero = aux; // constante = 1
            actual = primero; // constante = 1
        }else{
            actual->siguiente=aux; // constante = 1
            actual=aux; // constante = 1
        }
        aux=aux->siguiente; // constante = 1
    }
}
// T(n) = 1 + 5log(n)
// T(n) = log(n)
// O(log(n))

int main() {

   return 0;
}
