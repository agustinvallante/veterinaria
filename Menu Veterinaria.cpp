#include <stdio.h>
#include <stdlib.h>

main()
{
	int opc;
	do
	{
		system("cls");
		printf("\t\tMenu Veterinaria\n");
		printf("\t\t------------------------");
		printf("\n\t\t1. Modulo del Asistente");
		printf("\n\t\t2. Modulo Consultorio Veterinario");
		printf("\n\t\t3. Modulo Administracion");
		printf("\n\n\t\t4. Salir del Programa");
		printf("\n\t\t-----------------------");
		printf("\n\t\tOpcion: ");							scanf("%d",&opc);
		
		switch(opc)
		{
			case 1: 
				system("cls");
				system("start C:\\Users\\Teo\\OneDrive\\Escritorio\\aed\\evaluativo2\\modulo_asistente.exe");
				break;
	
			case 2: 
				system("cls");
				system("start C:\\Users\\Teo\\OneDrive\\Escritorio\\aed\\evaluativo2\\Modulo_veterinario.exe");
				break;
	
			case 3: 
				system("cls");
				system("start C:\\Users\\Teo\\OneDrive\\Escritorio\\aed\\evaluativo2\\Modulo_Administracion.exe");
				break;
			
			case 4:
				system("cls");
				printf("Saliendo... Gracias por usar el programa");
				system("pause");
				break;
		
			default:
				printf("Error, Opcion no valida.");	
		}
	}while(opc != 4);
}
