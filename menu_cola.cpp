#include <iostream>
using namespace std;
struct nodo
{
    int nro;
    struct nodo *sgte;
};
struct cola
{
    nodo *delante;
    nodo *atras  ;
};
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     
}
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          // libera memoria a donde apuntaba aux
     
     return num;
}
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}
int sumatoria_elementos(struct cola q)
{
	struct nodo *aux;
	aux = q.delante;
	int suma = 0;
	while(aux!= NULL)
	{
		suma += aux->nro;
		aux = aux->sgte;
	}
	return suma;
}
int buscar(struct cola q)
{
	struct nodo *aux;
	int valor, band = 0;
	int i=0, a=0;
	cout<<"\n\n digite el numero a buscar: ";
	cin>>q->delante;
	if(q==NULL)
	{
		cout<<"\n\n Cola vacia";
	}
	else
	{
		aux = q->delante;
		do{
		aux=aux->sgte
		cout<<aux->nro>>"numero"<<i<<endl;
		i++;
		}while(aux!=q);
	}
}
void menu()
{
    cout<<"\n\t IMPLEMENTACION DE COLAS EN C++\n\n";
    cout<<" 1. ENCOLAR                               "<<endl;
    cout<<" 2. DESENCOLAR                            "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. SUMATORIA                             "<<endl;
    cout<<" 6. BUSCAR                                "<<endl;
    cout<<" 7. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
int main()
{
    struct cola q;
   
    q.delante = NULL;
    q.atras   = NULL;
   
   
    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop
    int R;
    int B;
   
    system("color 0b");
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A ENCOLAR: "; cin>> dato;
                 encolar( q, dato );
                 cout<<"\n\n\t\tNumero " << dato << " encolado...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tNumero "<< x <<" desencolado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tCola vacia...!"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\n\n\t\tHecho...\n\n";
            break;
            
            case 5: R = sumatoria_elementos(q);
            cout<<"la suma es: "<<R;
            break;
            
            case 6: B = buscar(q);
            cout<<"el numero que busco es: "<<B;
            break;
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=7);
   
   
    return 0;
}
