#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

struct matriculas
{
	int numMatriculas[100];
	int cantidadTurnos[100];
};

struct vets
{
	int vetEnMes;
	matriculas ingresoMatriculas[50]; 	
};

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
	user asistente;
	user veter;
	mascota masc;
	turnos tur;
	veterinario vete;
};

void reg_veterinario(FILE *vet,usuarios veterinaria);
void reg_asistente(FILE *vet,usuarios veterinaria);
int autenticacion_vet(usuarios veterinaria, char aux_user[10]);
int verif_user_v(char aux_user[10],int leng_user,int &p, int &c);
int an_contra(int leng_password, char aux_pass[32],int &k,int &b_1);
int autenticacion_asistente(usuarios veterinaria,char aux_user[10]);
void atencionVet(FILE *vet,usuarios veterinaria);
void ranking_vet_atenciones(FILE *vet, usuarios veterinaria);


main()
{
	FILE *vet;
	usuarios veterinaria;
	int opc;
	do
	    {
	        system("cls");
			system("COLOR 70");        
			printf("\n\t\t\t\tModulo Administraci%cn",162);
    	    printf("\n\t\t\t\t==============================");
    		printf("\n\t\t\t\t1.- Registrar Veterinario");
	        printf("\n\t\t\t\t2.- Registrar Usuario Asistente");
	        printf("\n\t\t\t\t3.- Atenciones por Veterinarios");
			printf("\n\t\t\t\t4.- Ranking de Veterinarios por Atenciones");
			printf("\n\n\t\t\t\t5.- Cerrar la Aplicaci%cn",162);
			
 		  	printf("\n\n\t\t\t\tIngrese una opci%cn: ",162);
   		    scanf("%d",&opc);
   		    
	        switch (opc)
	        {
	            case 1:
	            	reg_veterinario(vet,veterinaria);
					printf("\n\n\t\t\t");
					system("pause");
					break;
	            case 2:
	            	reg_asistente(vet,veterinaria);
					printf("\n\n\t\t\t");
					system("pause");
					break;
				case 3:
					atencionVet(vet,veterinaria);
					printf("\n\n\t\t\t");
					system("pause");
					break;	            
				case 4:
					ranking_vet_atenciones(vet,veterinaria);
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


void ranking_vet_atenciones(FILE *vet, usuarios veterinaria)
{
	    system("CLS");

	    vet = fopen("veterinaria.dat", "r+b");
		fread(&veterinaria, sizeof(usuarios), 1, vet); 	   

		vets registro;
		int mayor=0;
		int ganadorRanking=0;	 


		printf("\n\t Bienvenidos al ranking de veterinarios!\n\t");
		printf("\n\t-----------------------------------------\n\n");


		printf("\n\tPara la medicion del ranking del veterinario con mayor atencion \n\ten el periodo debera ingresar la matricula de todos los \n\tveterinarios que trabajaron en el mes.\n\n");

		printf("\n\tPrimer paso");
		printf("\n\t-----------\n\n");

		printf("\n\tIngrese la cantidad de veterinarios que trabajaron en el mes:");
		scanf("%d",&registro.vetEnMes);


		_flushall();

		for(int i=1 ; i<=registro.vetEnMes ; i++)
		{
			printf("\n\tIngrese la matricula del veterinario %d: ",i);
			scanf("%d",&registro.ingresoMatriculas[i].numMatriculas[i]);

			printf("\n\tIngrese la cantidad de turnos atendidos del veterinario %d: ",i);
			scanf("%d",&registro.ingresoMatriculas[i].cantidadTurnos[i]);

			printf("\n\n");

		}

		printf("\n\n\tPor favor espere un momento...\n\t");
		getchar();


		for(int i=1 ; i<=registro.vetEnMes ; i++)
		{	
			if(registro.ingresoMatriculas[i].cantidadTurnos[i] > mayor)
			{
				mayor = registro.ingresoMatriculas[i].cantidadTurnos[i];
				ganadorRanking = registro.ingresoMatriculas[i].numMatriculas[i];


			}
		}
			printf("\n\t--->El veterinario con mayor ranking de atenciones es el\n\tque posee la matricula numero: %d",ganadorRanking);
			printf("\n");

		printf("\n\n\n");

		printf("\n\t******************************************************************");    
		printf("\n\n\t|GANADOR DEL BONO MENSUAL: DOCTOR MATRICULADO CON MATRICULA %d|\n", ganadorRanking);		
		printf("\n\t******************************************************************");


	 system("pause");

	 fclose(vet);

}


void atencionVet(FILE *vet,usuarios veterinaria)		//Atenciones por veterinario
{
	vet = fopen("Turnos.dat","r+b");
	
	if(vet == NULL)
	{
		system("cls");

		printf("\nERROR, no hay atenciones registradas\n");
	}
	else
	{
		system("cls");
		printf("\t\tListado de turnos\n");
		printf("\t\t~~~~~~~~~~~~~~~~~\n");
		printf("\tFecha\t\t\t\tVeterinario\n");
		fread(&veterinaria,sizeof(usuarios),1,vet);
		while(!feof(vet))
		{
			printf("\t%d/%d/%d\t\t\t\t%d\n",veterinaria.tur.turno.dia,veterinaria.tur.turno.mes,veterinaria.tur.turno.anio,veterinaria.tur.matricula);
			fread(&veterinaria,sizeof(usuarios),1,vet);
		}	
	}
	
	fclose(vet);
}

void reg_asistente(FILE *vet,usuarios veterinaria) //realiza el registro de usuario asistente
{
	vet = fopen("Usuarios.dat","w+b");
	int leng_user,leng_password,b = 0,x,p,c,cant_dig;
	int b_p = 0,an_contr,k,b_1;
	char aux_user[10],aux_pass[32];
	
	do
	{	
		system("cls");
		printf("\tRegistrar Asistente\n");
		_flushall();
		printf("Nombre de Usuario(6-10): ");					gets(aux_user);
		_flushall();
		printf("Contrase%ca(6-32): ",164);						gets(aux_pass);
		leng_user = strlen(aux_user);
		leng_password = strlen(aux_pass);
		
		
		//////////////////////////////////////////////////////////////////////////////////////////analisis de usuario
		cant_dig = verif_user_v(aux_user,leng_user,p,c);
		
		if(leng_user > 5 && leng_user < 11)
		{
			if(p == 1)
			{
				if(c >= 2)
				{
					if(cant_dig <= 3)
					{
						b = 1;
					}
					else
					{
						printf("\nERROR, El nombre de usuario debe contener como maximo 3 digitos numericos\n");
					}
				}
				else
				{
					b = 0;
					printf("\nERROR, El nombre de usuario debe contener al menos dos mayusculas\n");
				}
			}
			else
			{
				b = 0;
				printf("\nERROR, El nombre de usuario debe comenzar con una letra minuscula\n");
			}
		}
		else
		{
			b = 0;
			printf("\nERROR, La longitud del nombre de usuario debe ser entre 6 y 10 caracteres\n");
		}
		x = autenticacion_asistente(veterinaria,aux_user);
		if(x == 1)
		{
			printf("\nERROR, El usuario ingresado ya fue registrado\n");
			b = 0;
		}	
		/////////////////////////////////////////////////////////////////////////////////////////////analisis de contraseña
		an_contr = an_contra(leng_password,aux_pass,k,b_1);
		
		if(leng_password > 5 && leng_password < 33 )
		{
			if(an_contr == 1)
			{
				if(k == 1)
				{
					if(b_1 == 1)
					{
						b_p = 1;	
					}
					else
					{
						printf("\nERROR, la contrase%ca no debe tener 3 numeros consecutivos ni 2 letras consecutivas\n",164);
						b_p = 0;
					}
				}
				else
				{
					printf("\nERROR, la contrase%ca debe contener al menos una mayuscula, una minuscula y un numero\n",164);
					b_p = 0;
				}
			}
			else
			{
				printf("\nERROR, La contrase%ca no debe contener espacios ni simbolos, solo caracteres alfanumericos\n",164);
				b_p = 0;
			}
		}
		else
		{
			printf("\nERROR, La longitud del nombre de usuario debe ser entre 6 y 10 caracteres\n");
			b_p = 0;
		}
		system("pause");
	}while (b == 0 || b_p == 0);
	
	printf("\nAsistente Registrado correctamente\n");
	strcpy(veterinaria.asistente.username,aux_user);
	strcpy(veterinaria.asistente.username,aux_pass);
	fwrite(&veterinaria,sizeof(usuarios),1,vet);
	
	fclose(vet);
}


int autenticacion_asistente(usuarios veterinaria,char aux_user[10]) //verifica que el usuario no haya sido registrado anteriormente
{
	FILE *aux_vet;
	
	aux_vet = fopen("veterinaria.dat","r+b");
	int b = 0;
	fread(&veterinaria,sizeof(usuarios),1,aux_vet);
	
	while(!feof(aux_vet))
	{
		if(strcmp(veterinaria.asistente.username,aux_user) == 0)
		{
			b = 1;
		}
		fread(&veterinaria,sizeof(usuarios),1,aux_vet);
	}
	
	fclose(aux_vet);
	return b;
}



int autenticacion_vet(usuarios veterinaria,char aux_user[10]) //comprueba que el usuario veterinario no haya sido registrado anteriormente
{
	FILE *aux_vet;
	
	aux_vet = fopen("veterinaria.dat","r+b");
	int b = 0;
	fread(&veterinaria,sizeof(usuarios),1,aux_vet);
	
	while(!feof(aux_vet))
	{
		if(strcmp(veterinaria.veter.username,aux_user) == 0)
		{
			b = 1;
		}
		fread(&veterinaria,sizeof(usuarios),1,aux_vet);
	}
	

	fclose(aux_vet);
	return b;
}


int verif_user_v(char aux_user[10],int leng_user,int &p, int &c) //verifica las condiciones para el ingreso del usuario
{
	int cant_dig = 0;
	char letra;
	c = 0;
	letra = aux_user[0];
	
	
	if(letra >= 'A' && letra <= 'Z')
    {
		p = 0;
	}
	
    else if(letra >= 'a' && letra <= 'z')
	{
    	p = 1;
	}
        
    else
    {
		p = 2;
	}
	
	for(int i = 0 ; i < leng_user ; i++)
	{
		if(aux_user[i] >= 'A' && aux_user[i] <= 'Z')
		{
			c++;
		}
	}
	
	for(int i = 0 ; i < leng_user ; i++)
	{
		if(isdigit(aux_user[i]))
		{
			cant_dig++;
		}
	}
	
	return cant_dig;
}


int an_contra(int leng_password, char aux_pass[32], int &k,int &b_1) //analiza las condiciones de la contraseña del veterinario
{
	int letras = 0,numeros = 0, simbolos = 0,espacios = 0;
	int b = 0,mayus = 0,minus = 0;
	char letra,arreglo[32];
	int consec_num = 1,consec_let = 1;
	
	strcpy(arreglo,aux_pass);
	strlwr(arreglo);
	for(int i = 1; i < leng_password; i++)
	{
		if(isdigit(arreglo[i]))
		{
			if((arreglo[i] - 1) == arreglo[i - 1])
			{
				consec_num ++;
			}	
		}
		else
		{
			if((arreglo[i] - 1) == arreglo[i - 1])
			{
				consec_let ++;
			}
		}
	}
	b_1 = 0;
	if(consec_num <= 3 && consec_let <= 2)
	{
		b_1 = 1;
	}
	
	
	for(int i = 0 ; i < leng_password ; i++)
	{
		if(isdigit(aux_pass[i]))
		{
			numeros++;
		}
		else if(isalpha(aux_pass[i]))
		{
			letras++;
		}
		else if(isgraph(aux_pass[i]))
		{
			simbolos++;
		}
		else
		{
			espacios++;
		}
		
	}
	k = 0;
	if(simbolos == 0 && espacios == 0)
	{
		b = 1;
		for(int j = 0; j < leng_password ; j++)
		{
			letra = aux_pass[j];
			if(letra >= 'A' && letra <= 'Z')
		    {
				mayus++;
			}
		    else if(letra >= 'a' && letra <= 'z')
			{
		    	minus++;
			}
			
		}
		if(mayus > 0 && minus > 0 && numeros > 0)
		{
			k = 1;
		}
	}
	return b;
}


void reg_veterinario(FILE *vet,usuarios veterinaria)	//registra al usuario veterinario
{
	vet = fopen("Usuarios.dat","w+b");
	int leng_user,leng_password,b = 0,x,p,c,cant_dig;
	int b_p = 0,an_contr,k,b_1;
	char aux_user[10],aux_pass[32];
	
	do
	{	
		system("cls");
		printf("\tRegistrar Veterinario\n");
		_flushall();
		printf("Nombre de Usuario(6-10): ");					gets(aux_user);
		_flushall();
		printf("Contrase%ca(6-32): ",164);						gets(aux_pass);
		leng_user = strlen(aux_user);
		leng_password = strlen(aux_pass);
		
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////analisis de usuario
		cant_dig = verif_user_v(aux_user,leng_user,p,c);
		
		if(leng_user > 5 && leng_user < 11)
		{
			if(p == 1)
			{
				if(c >= 2)
				{
					if(cant_dig <= 3)
					{
						b = 1;
					}
					else
					{
						printf("\nERROR, El nombre de usuario debe contener como maximo 3 digitos numericos\n");
					}
				}
				else
				{
					b = 0;
					printf("\nERROR, El nombre de usuario debe contener al menos dos mayusculas\n");
				}
			}
			else
			{
				b = 0;
				printf("\nERROR, El nombre de usuario debe comenzar con una letra minuscula\n");
			}
		}
		else
		{
			b = 0;
			printf("\nERROR, La longitud del nombre de usuario debe ser entre 6 y 10 caracteres\n");
		}
		x = autenticacion_vet(veterinaria,aux_user);
		if(x == 1)
		{
			printf("\nERROR, El usuario ingresado ya fue registrado\n");
			b = 0;
		}	
		/////////////////////////////////////////////////////////////////////////////////////////////analisis de contraseña
		an_contr = an_contra(leng_password,aux_pass,k,b_1);
		
		if(leng_password > 5 && leng_password < 33 )
		{
			if(an_contr == 1)
			{
				if(k == 1)
				{
					if(b_1 == 1)
					{
						b_p = 1;	
					}
					else
					{
						printf("\nERROR, la contrase%ca no debe tener 3 numeros consecutivos ni 2 letras consecutivas\n",164);
						b_p = 0;
					}
				}
				else
				{
					printf("\nERROR, la contrase%ca debe contener al menos una mayuscula, una minuscula y un numero\n",164);
					b_p = 0;
				}
			}
			else
			{
				printf("\nERROR, La contrase%ca no debe contener espacios ni simbolos, solo caracteres alfanumericos\n",164);
				b_p = 0;
			}
		}
		else
		{
			printf("\nERROR, La longitud del nombre de usuario debe ser entre 6 y 10 caracteres\n");
			b_p = 0;
		}
		system("pause");
	}while (b == 0 || b_p == 0);
	
	printf("\nVeterinario Registrado correctamente\n");
	strcpy(veterinaria.veter.username,aux_user);
	strcpy(veterinaria.veter.password,aux_pass);
	fwrite(&veterinaria,sizeof(usuarios),1,vet);
	
	fclose(vet);
}

