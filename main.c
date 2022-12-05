#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
} eVehiculo;

eVehiculo* vehiculo_newParametros(char *idStr, char *marcaStr, char *tipoStr,char *pesoStr);
eVehiculo* vehiculo_new();
int vehiculo_setPeso(eVehiculo *this, float peso);
int vehiculo_setId(eVehiculo *this, int id);
int vehiculo_getId(eVehiculo *this, int *id);
int vehiculo_setMarca(eVehiculo *this,char *marca);
int vehiculo_getMarca(eVehiculo *this,char *marca);
int vehiculo_setTipo(eVehiculo *this,int tipo);
int vehiculo_getTipo(eVehiculo *this,int *tipo);
int vehiculo_setPeso(eVehiculo *this, float peso);
int vehiculo_getPeso(eVehiculo *this, float *peso);




int main()
{
    eVehiculo Vehiculo1= {1,"marcaPrueba",0,80.5};
    FILE *f;
    f =fopen("texto.txt","w");
    if(f != NULL)
    {
        // esto se hace con getter no llegue
        fprintf(f,"%d,%s,%d,%f",Vehiculo1.id,Vehiculo1.marca,Vehiculo1.tipo,Vehiculo1.peso);
    }

    fclose(f);
    return 0;
}
eVehiculo* vehiculo_new()
{
    eVehiculo *auxVehiculo = NULL;
    auxVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));
    return auxVehiculo;
}

eVehiculo* vehiculo_newParametros(char *idStr, char *marcaStr, char *tipoStr,
                                  char *pesoStr)
{
    eVehiculo *auxVehiculo;
    auxVehiculo = vehiculo_new();
    if (auxVehiculo != NULL && idStr != NULL && marcaStr != NULL
            && tipoStr != NULL && pesoStr != NULL )
    {
        if (!(vehiculo_setPeso(auxVehiculo,atof(pesoStr)))
                && vehiculo_setId(auxVehiculo, atoi(idStr))
                && vehiculo_setMarca(auxVehiculo,marcaStr)
                && vehiculo_setTipo(auxVehiculo,atoi(tipoStr)))
        {
            puts("Hubo un problema al crear el vehiculo");
            free(auxVehiculo);
            auxVehiculo = NULL;
            system("pause");
        }

    }
    return auxVehiculo;
}

int vehiculo_setId(eVehiculo *this, int id)
{
    int validado = 0;
    if (this != NULL && id > -1)
    {
        this->id = id;
        validado = 1;
    }
    return validado;
}
int vehiculo_getId(eVehiculo *this, int *id)
{
    int validado = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        validado = 1;
    }
    return validado;
}
;
int vehiculo_setMarca(eVehiculo *this,char *marca)
{
    int validado = 0;
    if (this != NULL )
    {
        strcpy(this->marca, marca);
        validado = 1;
    }
    return validado;
}
int vehiculo_getMarca(eVehiculo *this,char *marca)
{
    int validado = 0;
    if (this != NULL)
    {
        strcpy( marca,this->marca);
        validado = 1;
    }
    return validado;
}
int vehiculo_setTipo(eVehiculo *this,int tipo)
{
    int validado = 0;
    if (this != NULL )
    {
        this->tipo= tipo;
        validado = 1;
    }
    return validado;
}
int vehiculo_getTipo(eVehiculo *this,int *tipo)
{
    int validado = 0;
    if (this != NULL )
    {
        *tipo=this->tipo;
        validado = 1;
    }
    return validado;
}

int vehiculo_setPeso(eVehiculo *this, float peso)
{
    int validado = 0;
    if (this != NULL)
    {
        this->peso = peso;
        validado = 1;
    }
    return validado;
}
int vehiculo_getPeso(eVehiculo *this, float *peso)
{
    int validado = 0;
    if (this != NULL )
    {
        *peso = this->peso;
        validado = 1;
    }
    return validado;
}
;
