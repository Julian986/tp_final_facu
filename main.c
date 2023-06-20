#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include <time.h>
//#include "clientes.h"
#define ClientesRandom "clientes.dat"
#define DIM 200


typedef struct{
    //int id;
    //int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char telefono[12];
    //int eliminado;
} stCliente;

//int randomRango(int min, int max);
int numRandom();
void getName(char n[]);
void getLastname(char l[]);
void getDni(char d[]);
void getEmail(char e[]);
void getDomicilio(char d[]);
void getTelefono(char t[]);
void cargaClientesAleatorios(char archivo[]);
void muestraClientesAleatorios(char archivo[]);

int main()
{
    srand(time(NULL));

    cargaClientesAleatorios(ClientesRandom);
    muestraClientesAleatorios(ClientesRandom);
}

// Funciones que obtienen datos aleatorios

/*int randomRango(int min, int max){
    return rand()%(max-min)+min;
}*/

int numRandom(){
    static int suma = 1;
    suma++;
    int num = 0;
    srand(time(NULL));
    num = rand()%12;
    return num+suma;
}

void getName(char n[]){
    char names[][20]={"Amalio","Juan","Roberto","Antonio","Pedro","Fernando","Jacinto","Anibal","Antonio","Atalayo",
                           "Bertino","Anastasio","Amor","Arturo","Diego","Mario","Tamaro","Adolfo","Alfonso","Pedro","Alfredo",
                           "Rolando","Mauro","Amancio","Benicio","Bertin","Ildefonso","Amilcar","Cuchuflito","Jazmino",
                           "Remilgo"};
    //strcpy(n, names[randomRango(0,(sizeof(names)/sizeof(char))*20)]);
    strcpy(n, names[numRandom()]);
}

void getLastname(char l[]){
    char lastNames[][20]={"Fernandez","Garcia","Perez","Martinez","Gomez","Diaz","Sosa","Torres","Ruiz","Suarez",
                           "Castro","Gimenez","Vazquez","Acosta","Gutierrez","Ramirez","Flores","Benitez","Aguirre","Molina","Ortiz",
                           "Medina","Herrera","Dominguez","Moreno","Rojas","Peralta","Silva","Morales","Luna",
                           "Mendez"};

    strcpy(l, lastNames[numRandom()-1]);
}


void getDni(char d[]){
    char dnis[][20]={"28740858","29651813","40184442","26104249","32997809","35794895","27589790","38354542","34180521","24021740",
                           "30462341","39294102","27810158","26978925","31489645","30170275","41543371","29233430","23010622","23278318","36174131",
                           "27711944","37790238","29343879","27116347","38697631","35025026","31928840","37681104","37977745",
                           "29810168"};

    strcpy(d, dnis[numRandom()-2]);
}

void getEmail(char e[]){
    char emails[][20]={"amalio_32@gmail.com","juan1993@gmail.com","perez@gmail.com","martinez2001@gmail.com","pedrio_81@gmail.com","fer23@gmail.com","jacintoo2@gmail.com","anibal54@gmail.com","antonio_192@gmail.com","atalavo2001@gmail.com",
                           "ccastro@gmail.com","gimenezAnastasio732@gmail.com","vazquezAmor@gmail.com","acosta536@gmail.com","diego_183@gmail.com","ramirezMario1993@gmail.com","flores4@gmail.com","benitez_76@gmail.com","alffonso_37@gmail.com","ppedroo@gmail.com","36174131",
                           "alfredo19@gmail.com","herreraMauro@gmail.com","mauro_82@gmail.com","moreno_ush@gmail.com","rojass41@gmail.com","peraltaIldefonso_76@gmail.com","silva21_@gmail.com","moraless_37@gmail.com","lunna41@gmail.com",
                           "mendez_scum@gmail.com"};

    strcpy(e, emails[numRandom()-3]);
}

void getDomicilio(char d[]){
    char domicilios[][20]={"AV. 5 DE MAYO 1634","CALLE IGNACIO RAYON NO.949","AV. 5 DE MAYO NO. 1226","AV. 20 DE NOVIEMBRE NO 1046","CALLE ALDAMA NO 156","INDEPENDENCIA 748","5 DE MAYO 1660","AV. JESUS CARRANZA NO. 60","OCAMPO NO. 231","CALLE HIDALGO NO.96",
                           "CALLE MORELOS NO.426","HIDALGO NO 689","CALLE MATAMOROS NO. 147","INDEPENDENCIA 85","DANIEL SOTO NO.370","CALLE ALDAMA NO.233-A","PONCIANO ARRIAGA NO. 43","AV. 5 DE MAYO NO.1544","OCAMPO 38","AV 5 DE MAYO 659","CALLE OCAMPO NO.266",
                           "CALLE ALDAMA NO.53","20 DE NOVIEMBRE NO 1422","AV. LIBERTAD NO. 1207","	CALLE ARTEAGA NO. 1027","MATAMOROS NO. 225","INDEPENDENCIA NO. 377","AV. INDEPENDENCIA NO. 427","	AV. 5 DE MAYO NO 1189","BENITO JUAREZ NO 568",
                           "FRANCISCO I. MADERO NO. 182"};

    strcpy(d, domicilios[numRandom()-4]);
}

void getTelefono(char t[]){
    char telefonos[][20]={"2235347689","2234134567","2235768543","2236768956","2235345654","2235346123","2235879345","2234456879","2234234657","2236579243",
                           "2236143245","2234476897","2235243567","2235568093","2235768567","2235365789","2235478090","2235037067","2235254089","2237524049","2236254054",
                           "2235451083","2232254586","2235354084","2236284287","2235654253","2238557086","2235557059","2235254247","2235274268",
                           "2239257283"};

    strcpy(t, telefonos[numRandom()-5]);
}

void cargaClientesAleatorios(char archivo[]){

    stCliente cliente;
    FILE *archi = fopen(ClientesRandom, "wb");
    int i = 0;

    if(archi){
        while(i<5){
            getName(cliente.nombre);
            getLastname(cliente.apellido);
            getDni(cliente.dni);
            getEmail(cliente.email);
            getDomicilio(cliente.domicilio);
            getTelefono(cliente.telefono);

            fwrite(&cliente, sizeof(stCliente), 1, archi);
            i++;
        }
        fclose(archi);
    }


}

void muestraClientesAleatorios(char archivo[]){

    stCliente cliente;
    FILE *archi = fopen(archivo, "rb");
    int i = 0;

    if(archi){
        while(fread(&cliente, sizeof(stCliente), 1, archi) > 0){

                //printf("\n ID:.................: %d", cliente.id);
                printf("\n Nombre y Apellido:..: %s %s", cliente.nombre, cliente.apellido);
                printf("\n Dni:................: %s", cliente.dni);
                printf("\n Email:..............: %s", cliente.email);
                printf("\n Domicilio:..........: %s", cliente.domicilio);
                printf("\n Telefono:...........: %s", cliente.telefono);
                printf("\n==================================\n");

        }
            fclose(archi);
    }
}

