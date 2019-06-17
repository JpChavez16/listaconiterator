#include <iostream>
using namespace std;

template <typename T>
class nodo
{
	T data;
	nodo<T> *siguiente;
    
    public:
	nodo(){this->data=NULL,this->siguiente=NULL;}
	nodo(T data_){this->data=data_,this->siguiente=NULL;}
	void setsiguiente(nodo<T> *sig){siguiente=sig;}
	void setdata(T data){this->data=data;}
	nodo<T>* getsiguiente(){return siguiente;}
	T getdata(){return data;}
	~nodo();	
};

template <class T>
class ListaEnlazada{
	
	nodo<T> *head;
	int size;
	
	public:
		class Iterator
        {
            private:
                nodo<T>* ptr;
            public:
                Iterator(){}
                bool operator!= (nodo<T>*  o)
                {
                    bool igual = ptr == o;
                    return !igual;
                }
                Iterator& operator =(nodo<T>* begin) 
                {
                    ptr = begin;
                    return *this;
                }
                Iterator& operator ++ ()
                {
                    ptr = ptr->getsiguiente();
                    return *this; 
                }
                nodo<T>* get() {return ptr;}
        };
		ListaEnlazada(){this->head=NULL,this->size=0;}
		ListaEnlazada(nodo<T> head_){
			head= new nodo<T>(head_);
			size=1;
		}
		void agregar(T data_ ){
		nodo<T> *nuevo_nodo = new nodo<T> (data_);
		nodo<T> *aux=head;
		
		if(!head){
			head=nuevo_nodo;
		}else{
			nuevo_nodo->setsiguiente(head);
			head=nuevo_nodo;
		}
		size++;
		}	
			
		void eliminar(T data_)
		{
		    nodo<T> *aux = head;
		    nodo<T> *aux1 = head->getsiguiente();
		 
		    int cont = 0;
		 
		    if (head->getdata() == data_) {
		        head = aux->getsiguiente();
		    } else {
		        while (aux1) {
		            if (aux1->getdata() == data_) {
		                nodo<T> *aux_node = aux1;
		                aux->setsiguiente(aux1);
		                delete aux_node;
		                cont++;
		                size--;
		            }
		            aux = aux->getsiguiente();
		            aux1 = aux1->getsiguiente();
		        }
		    }
		 
		    if (cont == 0) {
		        cout << "No existe el dato " << endl;
		    }
		}
		
		void buscar(T data_)
		{
			nodo<T> *aux = head;
		    int cont = 1;
		    int cont1 = 0;
		 
		    while (aux) {
		        if (aux->getdata() == data_) {
		            cout << "El dato se encuentra en la posicion: " << cont << endl;
		            cont1++;
		        }
		        aux = aux->getsiguiente();
		        cont++;
		    }
		 
		    if (cont1 == 0) {
		        cout << "No existe el dato " << endl;
		    }
		    cout << endl << endl;
		}
		
		void imprimir(){
			nodo<T> *aux=head;
			if (!head){
				cout<<"La lista esta vacia "<<endl;
			}else {
				while(aux){
					cout<<aux->getdata()<<" ";
					if(!aux->getsiguiente())cout<<"NULL";
					    aux=aux->getsiguiente();
				}
			}
			cout<<endl<<endl;
		}
		
		nodo<T>* begin(){return head;}
		
		nodo<T>* end(){
			nodo<T>* aux = head;
		    while(aux->getsiguiente() != NULL)
		        aux = aux->getsiguiente();
		    return aux->getsiguiente();
		}
	        ~ListaEnlazada(){
			for(int i=0;i<size;i++)
			{
				nodo<T>* eliminado=head;
				head=head->getsiguiente();
				delete eliminado;
			}
			cout<<"Memoria liberada"<<endl;
		}
};

template <class T>
class IteratorList 
{
    private:
        nodo<T>* cursor;
    public:
        IteratorList(){cursor=NULL;}
        bool hasNext(){return cursor->getsiguiente();}
        IteratorList& next(){
                cursor = cursor->getsiguiente();
                return *this;  
        }

        IteratorList& operator++(){return next();}
        IteratorList& operator=(nodo<T>* o){
                cursor = o;
                return *this;
        }
        bool operator!=(nodo<T>* o){return cursor!=o;} 

        T get(){return cursor->getdata();}       
};


int main()
{

	ListaEnlazada<int>listaEnlazada_1;
	listaEnlazada_1.agregar(4);
	listaEnlazada_1.agregar(9);
	listaEnlazada_1.agregar(10);
	listaEnlazada_1.agregar(25);
	listaEnlazada_1.imprimir();
    
	listaEnlazada_1.buscar(10);
	
	IteratorList<int> a;
	for(a=listaEnlazada_1.begin(); a!=listaEnlazada_1.end(); a.next())
		cout<<a.get()<<' ';
	cout<<endl;
	
}


