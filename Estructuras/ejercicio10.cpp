#include <iostream>
using namespace std;

struct LibroLocal {
    int codigoLibro;
    string autor;
    int stock;
    string tituloLibro;
    string editorial;
    string genero;
};

struct LibroDeposito {
    int codigoLibro;
    int stock;
};

void imprimirListado(LibroLocal stockEnLocal[], LibroDeposito stockEnDeposito[]){

    int totalLibrosEnFalta = 0;

    cout << "Libros faltantes" << endl;
    cout << "Codigo\tObservacion" << endl;
    for (int i = 0; i < 3; i++)
    {
        if(stockEnLocal[i].stock == 0 && stockEnDeposito[i].stock == 0)
        {
            cout << stockEnDeposito[i].codigoLibro << "\t" << "Falta en local y en deposito." << endl;
            totalLibrosEnFalta++;
        }
        else if(stockEnLocal[i].stock == 0)
        {
            cout << stockEnLocal[i].codigoLibro << "\t" << "Falta en local." << endl;
            totalLibrosEnFalta++;
        }
        else if(stockEnDeposito[i].stock == 0)
        {
            cout << stockEnDeposito[i].codigoLibro << "\t" << "Falta en deposito." << endl;
            totalLibrosEnFalta++;
        }
    }
    cout << "Total de libros en falta: " << totalLibrosEnFalta << endl;

    return;
}

int main () {
 
    LibroLocal libroEnLocal;
    LibroDeposito libroEnDeposito;
    int stockLocal = 3;
    int stockDeposito = 3;
    int cantidadLibros = 3;    

    LibroLocal stockEnLocal[3] = {
        {23,"J.K. Rowling",10,"Harry Potter y la piedra filosofal", "Salamandra","Literatura Fantastica"},
        {25,"Ernest Hemingway",0,"The Old Man and the Sea", "Arenal","Novela"},
        {26,"Robert Fisher",0,"El caballero de la armadura oxidada","Ediciones Obelisco","Autoayuda" }
    }; 

    LibroDeposito stockEnDeposito[3] = {
        {23,0},
        {25,0},
        {26,2}
    };
   
    imprimirListado(stockEnLocal, stockEnDeposito);            

    system("pause");
    return 0;
}