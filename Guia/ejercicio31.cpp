#include <iostream>
using namespace std;

void leer(string mensaje, string &valor){
    cout << mensaje << endl;
    cin >> valor;  
}

void leer(string mensaje, char &valor){
    cout << mensaje << endl;
    cin >> valor;    
}

void leer(string mensaje, int &valor){
    cout << mensaje << endl;
    cin >> valor;
}

bool completoEstudiosPrimarios (char nivelEstudios, char indicadorNivelEstudio ){
    return (!(nivelEstudios == 'N' || (nivelEstudios == 'P' && indicadorNivelEstudio == 'I')));
}

string imprimirDatosIntegrante(string nombre, string apellido, char sexo, char nivelEstudios, char indicadorNivelEstudio) {
    
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Sexo: " << sexo << endl;    
    cout << "Nivel de estudios: " << nivelEstudios << endl;
    cout << "Indicador de nivel de estudio: "  << indicadorNivelEstudio << endl;
}

bool esAnalfabeto(char nivelEstudios, int edad){
    return nivelEstudios == 'N' && edad > 10;
}

float calcularPromedio(float numerador, float denominador){        
    return numerador/denominador;
}

float calcularPorcentaje(float numerador, float denominador){
    return numerador/denominador * 100;
}

int main() {

    string nombre = "";
    string apellido = "";
    char sexo = 0;
    char nivelEstudios = 0;
    char indicadorNivelEstudio = 0;
    char tipoVivienda = 0;
    int integrantes = 0;
    int cantidadFamilias = 0;
    int edad = 0;
    string domicilioFamilia = "";
    string numeracionDomicilio = "";
    int cantidadAnalfabetos = 0;
    int encuestados = 0;
    string domicilioConMasIntegrantes = "";
    string numeracionDomicilioConMasIntegrantes = "";
    float porcentajeAnalfabetismo = 0;
    int mayorCantidadIntegrantes = 0;
    int sumaEdadesFamilia = 0;
    int sumaEdadesCiudad = 0;
    float promedioEdadFamiliar = 0;
    float promedioEdadCiudad = 0;
    int cantidadPrimarioIncompleto = 0;
    int cantidadSecundarioIncompleto = 0;
    int cantidadTerciarioIncompleto = 0;
    int cantidadUniversitarioIncompleto = 0;
    int encuestadosSexoMasculino = 0;
    int encuestadosSexoFemenino = 0;
    float porcentajeSexoMasculino = 0;
    float porcentajeSexoFemenino = 0;
 
    leer("Ingrese la cantidad de integrantes de la familia: ", integrantes);    

    while(integrantes > 0)
    {
        cantidadFamilias++;

        leer("Ingrese el domicilio de la familia: ", domicilioFamilia); 

        leer("Ingrese la numeracion del domicilio de la familia: ", numeracionDomicilio);

        leer("Ingrese el tipo de vivienda (C o D): ", tipoVivienda);
        
        for(int i = 0; i < integrantes; i++)
        {
            leer("Ingrese el sexo del integrante (M o F): ", sexo);
            
            leer("Ingrese el nombre del integrante: ", nombre);
            
            leer("Ingrese el apellido del integrante: ", apellido);

            leer("Ingrese la edad del integrante: ", edad);
            
            leer("Ingrese el nivel de estudios (N, P, S, T o U): ", nivelEstudios);
            
            if(nivelEstudios != 'N')
            {
                leer("Ingrese si el nivel de estudios es Completo (C) o Incompleto (I): ", indicadorNivelEstudio);
            }            
            
            if(completoEstudiosPrimarios(nivelEstudios, indicadorNivelEstudio))
            {                
                imprimirDatosIntegrante(nombre, apellido, sexo, nivelEstudios, indicadorNivelEstudio);
            }

            if(esAnalfabeto(nivelEstudios, edad))
            {
                cantidadAnalfabetos++;
            }           
           
            if(tipoVivienda == 'D' && integrantes > mayorCantidadIntegrantes)
            {
                mayorCantidadIntegrantes = integrantes;
                domicilioConMasIntegrantes = domicilioFamilia;
                numeracionDomicilioConMasIntegrantes = numeracionDomicilio;
            }
           
            sumaEdadesFamilia += edad;

            if(indicadorNivelEstudio == 'I')
            {
                switch(nivelEstudios)
                {
                case 'P':
                    cantidadPrimarioIncompleto++;
                    break;
                case 'S':
                    cantidadSecundarioIncompleto++;
                    break;
                case 'T':
                    cantidadTerciarioIncompleto++;
                    break;
                case 'U':
                    cantidadUniversitarioIncompleto++;
                    break;
                default:
                    break;
                }
            }            

           if(sexo == 'M')
           {
               encuestadosSexoMasculino++;
           }
           else 
           {
               encuestadosSexoFemenino++;
           }
            
        }    
           
        promedioEdadFamiliar = calcularPromedio(sumaEdadesFamilia, integrantes);
        cout << "Promedio edad familiar: " << promedioEdadFamiliar << endl;
        
        sumaEdadesCiudad+= sumaEdadesFamilia;

        encuestados += integrantes;

        sumaEdadesFamilia = 0;

        leer("Ingrese la cantidad de integrantes de la familia: ", integrantes);
    }

    porcentajeAnalfabetismo = calcularPorcentaje(cantidadAnalfabetos, encuestados);
    promedioEdadCiudad = calcularPromedio(sumaEdadesCiudad, encuestados);
    porcentajeSexoMasculino = calcularPorcentaje(encuestadosSexoMasculino, encuestados);
    porcentajeSexoFemenino = calcularPorcentaje(encuestadosSexoFemenino, encuestados);

    cout << "Domicilio de familia con mas integrantes que viven en departamento: " << domicilioConMasIntegrantes + " " + numeracionDomicilioConMasIntegrantes << endl;
    cout << "Porcentaje de analfabetismo: " << porcentajeAnalfabetismo << "%" << endl;
    cout << "Promedio edades de la ciudad: " << promedioEdadCiudad << endl;
    cout << "Cantidad de encuestados con estudios primarios incompleto: " << cantidadPrimarioIncompleto << endl;
    cout << "Cantidad de encuestados con estudios secundarios incompleto: " << cantidadSecundarioIncompleto << endl;
    cout << "Cantidad de encuestados con estudios terciarios incompleto: " << cantidadTerciarioIncompleto << endl;
    cout << "Cantidad de encuestados con estudios universitarios incompleto: " << cantidadUniversitarioIncompleto << endl;
    cout << "Porcentaje de encuestados del sexo masculino: " << porcentajeSexoMasculino << "%" << endl;
    cout << "Porcentaje de encuestados del sexo femenino: " << porcentajeSexoFemenino << "%" << endl;

 system("pause");
 return 0;
}