#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

struct veterinario
{
	char apeynom[60];
	int matricula; //usado
	char contrasenia[10]; //usado
	int dni;
	char telefono[25];
		
};

struct fecha
{
	int dia,mes,anio;	
};


struct mascota 
{
	char apeynom[60];
	char domicilio[60];
	int DNI_duenio;
	char localidad[60];
	fecha nacimiento;
	float peso;
	char telefono[25];
	
};

struct turnos
{
	int matricula;
	int DNI_duenio;
	char atencion[380];
	fecha turno;
	
};

struct user
{
	char username[10];
	char password[32];
	char apeynom[60];
	
};

struct usuarios
{
	//char user[10];	
 	//char password[32];
 	//char apeynom[60];
	user asistente;
	user veter;
	mascota masc;
	turnos tur;
	veterinario vete;
};

void identificacion(FILE *vet,usuarios veterinaria);
void llamarmascota(FILE *vet,usuarios veterinaria);
void evolucion(FILE *vet,usuarios veterinaria,int longitud);

main()
{
	int opc,carga1,llamada1,longitud;
	usuarios veterinaria;
	
	FILE *vet;
	
	vet=fopen("veterinaria.dat","a+b");
	
	
	do
	{
		system("CLS");
		system("COLOR 0B");
		printf("\n\t\t\t\tModulo Consultorio Veterinario");		
		printf("\n\t\t\t\t==============================");	
		printf("\n\t\t\t\t1.- Iniciar Sesi%cn",162);
		printf("\n\t\t\t\t2.- Visualizar Lista de Espera de Turnos (informe)");
		printf("\n\t\t\t\t3.- Registrar Evoluci%cn de la Mascota",162);
		printf("\n\n\t\t\t\t4.- Cerrar la aplicaci%cn.",162);					
		printf("\n\t\t\t\tIngrese una opci%cn: ",162);
		scanf("%d",&opc);
		
		
		switch(opc)
		{
			case 1: 
					identificacion(vet,veterinaria);
					break;
			
			case 2:	
					llamarmascota(vet,veterinaria);
					break;
			
			
			case 3: evolucion(vet,veterinaria,longitud);
					
					break;
			
			
			case 4:
					system("CLS");
					printf("\n!Muchas Gracias por utilizar %cste programa :)\n",130);
					break;	
			
			
			default: printf("\n\t\t\t\tIngreso de una opci%cn NO valida, Por favor intente nuevamente\n\n\n",162);
					 system("PAUSE");
					 break;	
		}
		
		
		
	}while(opc != 4);

} //cierre del main
	
void identificacion(FILE *vet,usuarios veterinaria)
{
	bool b = false;
	char aux_user[10],aux_password[32],aux_apeynom[60];
	
	vet=fopen("veterinaria.dat","r+b");
	
	system("CLS");
	
	Sleep(1000);
	printf("\n\t\t\t\tCargando para Iniciar Sesi%cn......",162);
	Sleep(1000);
	printf("\n\t\t\t\tUn poco m%cs....",160);
	Sleep(1000);
	printf("\n\t\t\t\tCarga exitosa!\n");
	Sleep(900);
	
	system("CLS");

	printf("********************************************************\n");
	printf("*Para Iniciar Sesi%cn debe ingresar los siguientes datos*\n",162);
	printf("*");
	printf("*******************************************************\n");
	
	_flushall();
	printf("\n\t\tNombre de Usuario -->  ");
	gets(aux_user);

	_flushall();
	printf("\n\t\tContrase%ca -->  ",164);
	gets(aux_password);
		
	fread(&veterinaria,sizeof(usuarios),1,vet);

	while(!feof(vet))
	{
		if((strcmp(veterinaria.veter.username,aux_user) == 0)	&& (strcmp(veterinaria.veter.password,aux_password) == 0))
		{
			b = true;
			strcpy(aux_apeynom,veterinaria.veter.apeynom);
		}
		else
		{
			b = false;
		}
		fread(&veterinaria,sizeof(usuarios),1,vet);
	}
	
	if(b == true)
	{
		Sleep(1000);
		printf("Bienvenido ");								puts(aux_apeynom);	
	}
	else
	{
		printf("ERROR, Nombre de usuario y contrase%ca no coinciden",164);
	}
	system("pause");
	fclose(vet);
}

void llamarmascota(FILE *vet,usuarios veterinaria)
{
	int llamada;
	char aux_apeynom[60];
	
	vet=fopen("Mascotas.dat","r+b");
	
	if(vet == NULL)
	{
		system("cls");
		printf("ERROR, no hay ninguna mascota registrada");
	}
	else
	{
		system("CLS");
		
		printf("\nLISTADO DE MASCOTAS\n");
		fread(&veterinaria,sizeof(usuarios),1,vet);
		while(!feof(vet))
		{
			_flushall();
			puts(veterinaria.masc.apeynom);
			
			fread(&veterinaria,sizeof(usuarios),1,vet);
			
		}
		system("PAUSE");
		rewind(vet);
		printf("\nIngrese un nombre a llamar: ");		gets(aux_apeynom);
		
		fread(&veterinaria,sizeof(usuarios),1,vet);
		while(!feof(vet))
		{
			if(strcmp(veterinaria.masc.apeynom,aux_apeynom) == 0)
			{
				printf("\nApellido y nombre: ");		puts(veterinaria.masc.apeynom);
				printf("\nDNI del due%co: %d",164,veterinaria.masc.DNI_duenio);
				printf("\nLocalidad: ");				puts(veterinaria.masc.localidad);
				printf("\nEdad: %d a%cos",veterinaria.masc.nacimiento.anio,164);
				printf("\nPeso: %dkg",veterinaria.masc.peso);
				fread(&veterinaria,sizeof(usuarios),1,vet);
			}
		}
	}
	
	fclose(vet);
	getch();
}

void evolucion(FILE *vet,usuarios veterinaria,int longitud)
{
	
	
	vet=fopen("Mascotas.dat","w+b");
	system("CLS");
	
	Sleep(1000);
	printf("\nRealice en un texto de NO MAS de (380) caracteres la evolucion de la Mascota\n");
	Sleep(1000);
	printf("\nDireccionando a Evolucion de Mascota\n");
	
	if(vet == NULL)
	{
		printf("\nERROR AL ABRIR EL ARCHIVO\n");
		exit(1);
		
	}	
	else
	{
		_flushall();
		printf("\nINFO: ");
		gets(veterinaria.tur.atencion);
		longitud = strlen(veterinaria.tur.atencion);

		if(longitud <= 380)
		{
			Sleep(1000);
			printf("\nEvoluci%cn de la Mascota REGISTRADA\n",162);
			Sleep(1000);
		
			Sleep(1000);
			printf("\nLa cadena de registro de atenci%cn posee %d caracteres\n",162,longitud);
			Sleep(1000);
			printf("\nEL REGISTRO DE EVOLUCION DE LA MASCOTA FUE EXITOSO\n");
			exit(1);
			printf("\n");
			fwrite(&veterinaria,sizeof(usuarios),1,vet);
		
		}
		else 
		{
			printf("\nLA CANTIDAD DE CARACTERES (380) HA SIDO SUPERADA\n");
			printf("\nPOR FAVOR INGRESE NUEVAMENTE LA CANTIDAD DE CARACTERES PEDIDA ANTERIORMENTE\n");
		}
		
	}	
	system("PAUSE");
	fclose(vet);
	

}	

