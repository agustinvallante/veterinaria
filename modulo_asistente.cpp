#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct veterinario
{
	char apeynom[60];
	int matricula; 
	char contrasenia[10]; 
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
	fecha turno;
	int DNI_duenio;
	char atencion[380];
};

struct user
{
	char username[10];	
 	char password[32];
 	char apeynom[60];
};

struct usuarios
{
	user asistente;
	user veter;
	mascota masc;
	turnos tur;
	veterinario vete;
};

void iniciar_sesion(FILE *vet,usuarios veterinaria);
void registrar_mascota(FILE *vet,usuarios veterinaria);
void registrar_turno(FILE *vet,usuarios veterinaria);
void listado(FILE *vet,usuarios veterinaria);

main()
{
	usuarios veterinaria;
	
	FILE *vet;
	
	int opc;
	do
	    {
	        system("cls");      
			system("COLOR 0E");  
			printf("\n\t\t\t\tModulo del asistente");
    	    printf("\n\t\t\t\t==============================");
    		printf("\n\t\t\t\t1.- Iniciar Sesi%cn",162);
	        printf("\n\t\t\t\t2.- Registrar Mascota");
	        printf("\n\t\t\t\t3.- Registrar Turno");
			printf("\n\t\t\t\t4.- Listado de Atenciones por Veterinario y fecha");
			printf("\n\n\t\t\t\t5.- Cerrar la Aplicaci%cn",162);
			
 		  	printf("\n\n\t\t\t\tIngrese una opci%cn: ",162);
   		    scanf("%d",&opc);
   		    
	        switch (opc)
	        {
	            case 1:
	            	iniciar_sesion(vet,veterinaria);
  					printf("\n\n\t\t\t");
					system("pause");
					break;
	            case 2:
	            	registrar_mascota(vet,veterinaria);
					printf("\n\n\t\t\t");
					system("pause");
					break;
				case 3:
					registrar_turno(vet,veterinaria);
					printf("\n\n\t\t\t");
					system("pause");
					break;	            
				case 4:
					listado(vet,veterinaria);
					printf("\n\n\t\t\t");
					system("pause");
					break;
	            case 5:
	                printf("\n\t\t\tSaliendo... Gracias por usar el programa :)");
	                printf("\n\n\t\t\t");
	                system("pause");
					break;
	                
	            default:
					printf("\n\t\t\tERROR, opcion no valida");
					printf("\n\n\t\t\t");
					system("pause");
					break;
	        }
	        
	    }while(opc != 5);
	    
}


void listado(FILE *vet,usuarios veterinaria)
{
	vet = fopen("Turnos.dat","r+b");
	
	system("cls");
	printf("\t\tListado de turnos\n");
	printf("\t\t~~~~~~~~~~~~~~~~~\n");
	printf("\tFecha\t\t\tVeterinario\n");
	fread(&veterinaria,sizeof(usuarios),1,vet);
	while(!feof(vet))
	{
		printf("\t%d/%d/%d\t\t%d\n",veterinaria.tur.turno.dia,veterinaria.tur.turno.mes,veterinaria.tur.turno.anio,veterinaria.tur.matricula);
		fread(&veterinaria,sizeof(usuarios),1,vet);
	}
	
	fclose(vet);
}



void registrar_turno(FILE *vet,usuarios veterinaria)
{
	vet = fopen("Turnos.dat","a+b");
	
	system("cls");
	printf("\tRegistrar Turno\n");
	printf("\t~~~~~~~~~~~~~~~\n\n");
	printf("Matr%ccula: ",161);						scanf("%d",&veterinaria.tur.matricula);
	printf("Fecha de turno\n");
	printf("D%ca: ",161);							scanf("%d",&veterinaria.tur.turno.dia);
	printf("Mes: ");								scanf("%d",&veterinaria.tur.turno.mes);
	printf("A%co: ",164);									scanf("%d",&veterinaria.tur.turno.anio);
	printf("DNI del due%co: ",164);					scanf("%d",&veterinaria.tur.DNI_duenio);
	_flushall();
	printf("Atenci%cn: ",162);						gets(veterinaria.tur.atencion);
	
	fwrite(&veterinaria,sizeof(usuarios),1,vet);
	
	fclose(vet);
}



void registrar_mascota(FILE *vet,usuarios veterinaria)
{
	vet = fopen("Mascotas.dat","a+b");
	system("cls");
	printf("\tRegistrar Mascota\n");
	printf("\t~~~~~~~~~~~~~~~~~\n\n");
	_flushall();
	printf("Apellido y nombre: ");					gets(veterinaria.masc.apeynom);
	printf("Domicilio: ");							gets(veterinaria.masc.domicilio);
	printf("DNI del due%co: ",164);					scanf("%d",&veterinaria.masc.DNI_duenio);
	_flushall();
	printf("Localidad: ");							gets(veterinaria.masc.localidad);
	printf("Fecha de nacimiento\n");
	printf("A%co: ",164);							scanf("%d",&veterinaria.masc.nacimiento.anio);
	printf("Mes: ");								scanf("%d",&veterinaria.masc.nacimiento.mes);
	printf("D%ca: ",161);							scanf("%d",&veterinaria.masc.nacimiento.dia);
	printf("Peso: ");								scanf("%f",&veterinaria.masc.peso);
	_flushall();
	printf("Tel%cfono: ",130);						gets(veterinaria.masc.telefono);
	
	fwrite(&veterinaria,sizeof(usuarios),1,vet);
	fclose(vet);
}


void iniciar_sesion(FILE *vet,usuarios veterinaria)
{
	bool b = false;
	char aux_user[10],aux_password[32],aux_apeynom[60];
	vet = fopen("Usuarios.dat","r+b");
	
	system("cls");
	printf("\tIniciar Sesi%cn\n\t~~~~~~~~~~~~~~~~\n",162);
	_flushall();
	printf("Ingrese su nombre de usuario: ");					gets(aux_user);
	_flushall();
	printf("Ingrese su contrase%ca: ",164);						gets(aux_password);
	
	fread(&veterinaria,sizeof(usuarios),1,vet);
	while(!feof(vet))
	{
		
		if((strcmp(veterinaria.asistente.username,aux_user) == 0)	&& (strcmp(veterinaria.asistente.password,aux_password) == 0))
		{
			b = true;
			strcpy(aux_apeynom,veterinaria.asistente.apeynom);
		}
		else
		{
			b = false;
		}
		fread(&veterinaria,sizeof(usuarios),1,vet);
	}
	
	if(b == true)
	{
		printf("Bienvenido ");									puts(aux_apeynom);	
	}
	else
	{
		printf("ERROR, Nombre de usuario y contraseña no coinciden");
	}
	system("pause");
	fclose(vet);
}

