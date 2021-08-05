#include <iostream>
using namespace std;

struct Episodios {
    int Id_Serie;
    string tituloEpisodio;
    int numeroTemporada;
    int numeroEpisodio;
    int cantidadDescargas;
    int fechaUltimaDescarga;
};

void imprimirFecha(int fechaCompleta){
    int restoFecha = 0;
    int anio = 0;
    int mes = 0;
    int dia = 0;
    restoFecha = fechaCompleta % 10000;
    anio = (fechaCompleta - restoFecha) / 10000;
    mes = (restoFecha - dia) / 100;
    dia = fechaCompleta % 100;

    cout << dia << "/" << mes << "/" << anio << endl;
    return;    
}

int main () {    

    int cantidadEpisodios = 6;   
    Episodios episodios[6] = {
        {1001,"A veces",1,1,150,20210617},
        {1001,"Generalmente",1,2,300,20210618},
        {1001,"Casi siempre",2,1,75,20210705},
        {1002,"Casi me matas",3,4,800,20210717},
        {1002,"Ahora si me mataste",4,1,200,20210808},
        {1003,"Tatuame centrado",1,1,100,20210928}
    };
    int dia = 0;
    int mes = 0;;
    int anio = 0;
    int cantidadEpisodiosTemporada = 0;
    int totalDescargasTemporada = 0;
    int totalDescargasSerie = 0;
    int totalGeneralSeries = 0;
    int totalEpisodiosSerie = 0;

    int i = 0;
    int keySerie;
    int keyTemporada;
    
    while(i < cantidadEpisodios)
    {
        keySerie = episodios[i].Id_Serie;
        totalDescargasSerie = 0;
        totalDescargasSerie = 0;

        while(i < cantidadEpisodios && keySerie == episodios[i].Id_Serie)
        {
            cantidadEpisodiosTemporada = 0;
            totalDescargasTemporada = 0;
            keyTemporada = episodios[i].numeroTemporada;
            cout << "Serie: " << episodios[i].Id_Serie << endl;
            cout << "Temporada: " << episodios[i].numeroTemporada << endl;
            cout << "N. de episodio\tTitulo del episodio\tCant. descargas\tFecha de ultima descarga" << endl;
            while(i < cantidadEpisodios && keySerie == episodios[i].Id_Serie && keyTemporada == episodios[i].numeroTemporada)
            {
                cout << episodios[i].numeroEpisodio << "\t\t" << episodios[i].tituloEpisodio << "\t\t" << episodios[i].cantidadDescargas << "\t";
                imprimirFecha(episodios[i].fechaUltimaDescarga); 
                cantidadEpisodiosTemporada++;
                totalDescargasTemporada += episodios[i].cantidadDescargas;
                i++;
            }
            cout << "Cant. Total de Episodios de la Temporada: " << cantidadEpisodiosTemporada << endl;
            cout << "Total descargas de la temporada: " << totalDescargasTemporada << endl;
            
            totalEpisodiosSerie += cantidadEpisodiosTemporada;
            totalDescargasSerie += totalDescargasTemporada;
        }
        cout << "Cant. Total de Episodios de la Serie: " << totalEpisodiosSerie << endl;
        cout << "Total descargas de la Serie: " << totalDescargasSerie << endl;
        
        totalGeneralSeries++;
    }
    cout << "Total General de series: " << totalGeneralSeries << endl;    

    system("pause");
    return 0;
}