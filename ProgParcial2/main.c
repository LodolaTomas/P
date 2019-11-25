#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char alumno[51];
    int nota;
} eParcial;

eParcial* newParcial(void);
eParcial* newParameters(int id, char* alumno, int nota);
int setId(eParcial* miParcial, int id);
int setAlumno(eParcial* miParcial, char* alumno);
int setNota(eParcial* miParcial,int nota);
void parcial_MostrarUno(eParcial* miParcial);
int guardarBinario(char* path,eParcial* miParcial);
eParcial* leerBinario(char* path);

int main()
{
    eParcial* pParcial=newParameters(10,"joaquin",10);
    eParcial* miParcial=NULL;
    int stado=0;
    parcial_MostrarUno(pParcial);
    stado=guardarBinario("data.bin",pParcial);
    if(stado==0)
    {
        printf("Guardado en Binario\n");
    }
    miParcial=leerBinario("data.bin");
    parcial_MostrarUno(miParcial);

    return 0;
}

eParcial* newParcial(void)
{
    eParcial* pParcial=(eParcial*)malloc(sizeof(eParcial));
    if(pParcial!=NULL)
    {
        pParcial->id=0;
        strcpy(pParcial->alumno,"");
        pParcial->nota=0;
    }
    return pParcial;
}
eParcial* newParameters(int id, char* alumno, int nota)
{
    eParcial* pParcial=NULL;
    pParcial=newParcial();
    if(pParcial!=NULL)
    {
        setId(pParcial,id);
        setAlumno(pParcial,alumno);
        setNota(pParcial,nota);
    }
    return pParcial;
}
int setId(eParcial* miParcial, int id)
{
    int retorno=-1;
    if(miParcial!=NULL && id >=0)
    {
        miParcial->id=id;
        retorno=0;
    }
    return retorno;
}
int setAlumno(eParcial* miParcial, char* alumno)
{
    int retorno=-1;
    if(miParcial!=NULL && alumno!=NULL)
    {
        strcpy(miParcial->alumno,alumno);
        retorno=0;
    }
    return retorno;
}
int setNota(eParcial* miParcial,int nota)
{
    int retorno=-1;
    if(miParcial!=NULL && nota >=0)
    {
        miParcial->nota=nota;
        retorno=0;
    }
    return retorno;
}
void parcial_MostrarUno(eParcial* miParcial)
{
    printf("id[%d]--alumno[%s]--nota[%d]\n",miParcial->id,miParcial->alumno,miParcial->nota);
}
int guardarBinario(char* path,eParcial* miParcial)
{
    FILE* pFile=NULL;
    int retorno=-1;
    int estado=0;
    pFile=fopen(path,"wb");
    if(pFile!=NULL)
    {
        estado=fwrite(miParcial,sizeof(eParcial),1,pFile);
        if(estado==1)
        {
            retorno=0;
            fclose(pFile);
        }
    }
    return retorno;
}
eParcial* leerBinario(char* path)
{
    FILE* pFile=NULL;
    eParcial* retorno=NULL;
    pFile=fopen(path,"rb");
    retorno=newParcial();
    if(pFile!=NULL && retorno!=NULL)
    {
        fread(retorno,sizeof(eParcial),1,pFile);
    }
    return retorno;
}
