#include <stdio.h>
#define N 5000

	
// void implica que main *no* devuelve nada
int main()
{
  int eleccion,conectado;   // Conectado tendra 3 valores base:  0 estamos sin estado, 1 estamos conectados, 2 decidimos salir
  char user[N];
  char pass[N];  
  conectado=0;
  int i=0;
  FILE *us;
  printf("Bienvenido al foro de la universidad.\n");
  printf("Quieres crear un nuevo usuario o quieres acceder con uno? \n");
  printf("1- Nuevo usuario: \n");
  printf("2- Acceder: \n");
  printf("3- Salir: \n");
  while(conectado==0){
  		scanf("%i", &eleccion);
  		switch(eleccion){
  			case 1:
  				printf("Introduce tu usuario:\n");
  				scanf("%s", user);
  				printf("El usuario es %s\n",user);
  				printf("Introduce tu password (Maximo 10 caracteres):\n");
  				 for(i=0; i<10;i++){
     				   pass[i]=getch();
        				printf("*");
        					if(pass[i]=='\r') //check if enter key is pressed
            				break;
        					
						if(i==9){
							printf("Estas al limite de la contraseña, no puedes introducir mas caracteres.\n");
							break;
						}
         		}				         		
				 //Escrito en el fichero.	
				us = fopen("C:/Foro/usuarios.txt", "a");
				if(us == NULL){
					printf("Error en el sistema.");
					return -1;
				}				
					fprintf(us ,"%s", user);
					fprintf(us ,"%s", pass);							
				 	fclose(us);
				 	conectado=1;
  				break;
  			case 2: 
			   while(conectado==1){
					printf("Menu.\n");  
  					printf("1- Visualiza post: \n");
  					printf("2- Crea Post: \n");
  					printf("3- Salir: \n");
  					scanf("%i", &eleccion);
  						switch(eleccion){
  							case 1:
  								break;
  							case 2:
  								break;
  							case 3:
  								conectado=2;
  								printf("Adios.\n");
  								break;
  							default:
  								printf("Fallo de opcion.");
  								break;
  		}
		}
  			  us = fopen("C:/Foro/usuarios.txt", "r");
			  printf("Bienvenido %s\n", user);
			  	
			 			
  				break;
  			case 3:
  				printf("Vuelve pronto!\n");
  				conectado=2;
  				break;
  			default:
  				printf("Esa opcion no es valida repite.\n");
  				break;
  		}  	
	}
	while(conectado==1){
		printf("Menu.\n");  
  		printf("1- Visualiza post: \n");
  		printf("2- Crea Post: \n");
  		printf("3- Salir: \n");
  		scanf("%i", &eleccion);
  		switch(eleccion){
  			case 1:
  				break;
  			case 2:
  				break;
  			case 3:
  				conectado=2;
  				printf("Adios.\n");
  				break;
  			default:
  				printf("Fallo de opcion.");
  				break;
  		}
		}		
}
