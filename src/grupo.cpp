#include "../include/grupo.h"

struct rep_grupo
{
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    TPersona personas[MAX_PERSONAS];
    int tope = 0;
    /****** Fin de parte Parte 5.1 *****/
};

TGrupo crearTGrupo()
{
    TGrupo grupo = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    grupo = new rep_grupo;

    /****** Fin de parte Parte 5.2 *****/
    return grupo;
}

// Función para agregar una persona a un grupo
// Recibe un elemento de tipo TGrupo y un elemento de tipo TPersona y lo agrega al grupo en orden por fecha de nacimiento (de menor a mayor)
// Si dos personas tienen la misma fecha de nacimiento, deben ordenarse por orden de ingreso al grupo, de más nuevo a más antiguo
// Si la cantidad de personas en el grupo es igual a MAX_PERSONAS, la función no tiene efecto
void agregarAGrupo(TGrupo &grupo, TPersona persona)
{

    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (grupo->tope != MAX_PERSONAS)
    {
        grupo->tope++;
        for (int i = 0; i <= grupo->tope; i++)
        {
            TFecha fecha1 = fechaNacimientoTPersona(grupo->personas[i]);
            TFecha fecha2 = fechaNacimientoTPersona(persona);
            if (i == grupo->tope)
            {
                grupo->personas[i] = persona;
            }
            else if (compararTFechas(fecha1, fecha2) == 0 || !esMasJoven(grupo->personas[i], persona))
            {
                for (int j = grupo->tope; j > i; j--)
                {
                    grupo->personas[j] = grupo->personas[j - 1];
                };
                grupo->personas[i] = persona;
                break;
            }
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}
// Función para imprimir todas las personas de un grupo
// Recibe un elemento de tipo TGrupo e imprime sus personas en orden cronológico
// El formato en el que se debe imprimir el grupo es utilizando de forma secuencial la función imprimirTPersona
// Si el grupo está vacío no imprime nada
void imprimirTGrupo(TGrupo grupo)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (grupo->tope > 0)
    {
        for (int i = 0; i < grupo->tope; i++)
        {
            imprimirTPersona(grupo->personas[i]);
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}

// Función para liberar un grupo
// Recibe una referencia a un elemento de tipo TGrupo y libera su memoria
// Libera además la memoria de cada una de las personas en el grupo
void liberarTGrupo(TGrupo &grupo)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    for (int i = 0; i < grupo->tope; i++)
    {
        liberarTPersona(grupo->personas[i]);
    }
    delete grupo;
    grupo = NULL;
    /****** Fin de parte Parte 5.2 *****/
}

// Función para verificar si un elemento de tipo TPersona existe en un grupo
// Recibe un grupo y la cédula de la persona y regresa un booleano indicando su existencia
bool estaEnGrupo(TGrupo grupo, int cedula)
{
    bool esta = false;
    /************ Parte 5.3 ************/
    /*Escriba el código a continuación */
    int i = 0;
    while (!esta)
    {
        if (cedulaTPersona(grupo->personas[i]) == cedula)
        {
            esta = true;
        }
    }

    /****** Fin de parte Parte 5.3 *****/
    return esta;
}

// Esta función remueve la persona con ci "cedula" del grupo "grupo"
void removerDeGrupo(TGrupo &grupo, int cedula)
{
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
    for (int i = 0; i < grupo->tope; i++)
    {
        if (cedulaTPersona(grupo->personas[i]) == cedula)
        {
            liberarTPersona(grupo->personas[i]);
        }
    }
    grupo->tope--;

    /****** Fin de parte Parte 5.4 *****/
}

// Función para verificar si hay, al menos, una persona en el grupo que tenga la fecha de nacimiento "fecha"
// Debe implementarse utilizando búsqueda binaria
bool hayPersonasFecha(TGrupo grupo, TFecha fecha)
{
    bool hay = false;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    int idx = grupo->tope / 2;
    while (!hay)
    {
        if (compararTFechas(fechaNacimientoTPersona(grupo->personas[idx]), fecha) == 0)
        {
            hay = true;
            break;
        }
        else if (idx / 2 > 0)
        {
            if (compararTFechas(fechaNacimientoTPersona(grupo->personas[idx]), fecha) == 1)
            {
                idx = idx / 2;
            }
            else
            {
                idx += idx / 2;
            }
        }
        else
        {
            break;
        }
    }

    /****** Fin de parte Parte 5.5 *****/
    return hay;
}

// Imprime en pantalla las personas del grupo que tengan la fecha de nacimiento "fecha"
void imprimirPersonasFecha(TGrupo grupo, TFecha fecha)
{
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    bool masViejo = false;
    int i = 0;
    while (!masViejo)
    {
        if (compararTFechas(fechaNacimientoTPersona(grupo->personas[i]), fecha) == 0)
        {
            imprimirTPersona(grupo->personas[i]);
        }
        if (compararTFechas(fechaNacimientoTPersona(grupo->personas[i]), fecha) == 1)
        {
            masViejo = true;
        }
        i++;
    }

    /****** Fin de parte Parte 5.5 *****/
}
