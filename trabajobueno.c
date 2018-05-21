#include <stdio.h>
#include<string.h>
#define N 5000

	
// void implica que main *no* devuelve nada
int main()
{
  int eleccion,conectado;   // Conectado tendra 3 valores base:  0 estamos sin estado, 1 estamos conectados, 2 decidimos salir
  char user[N];
  char pass1[N];  
  char pass2[N];
  char pass[N];
  char nickname[N];
  int cont;
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
     				   pass1[i]=getch();
        				printf("*");
        					if(pass1[i]=='\r')
            					break;
							if(i==9){
								printf("Estas al limite de la contraseña, no puedes introducir mas caracteres.\n");
								break;
									}
         						}
         					printf("\n");
         		do{
				printf("Introduce otra vez tu password (Maximo 10 caracteres):\n");
  				 for(i=0; i<10;i++){	
     				   pass2[i]=getch();
        				printf("*");
        					if(pass2[i]=='\r')
            				break;
         			}
         					printf("\n");
         			}
         		while(strcmp(pass1,pass2)!=0);{	
         				printf("Password correcta\n");
				 }

					us = fopen("C:/Foro/usuarios.txt", "a");
						if(us == NULL){
						printf("Error en el sistema.");
						return -1;
						}				
					fprintf(us ,"%s %s", user, pass1);							
				 	fclose(us);
				 	conectado=1;
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
					  				printf("Vuelve pronto!\n");
					  				break;
					  			default:
					  				printf("Fallo de opcion.");
					  				break;
  								}
  							}
  					
  				break;
  			case 2: 	
					conectado=0;
					printf("Inicia sesion:\n");
					printf("Nickname:\n");
					scanf("%s",nickname);
					printf("Password:\n");
					for(i=0; i<10;i++){	
     				   pass[i]=getch();
        				printf("*");
        					if(pass[i]=='\r')
            				break;
            		}
						us = fopen("C:/Foro/usuarios.txt", "a");
						if(us == NULL){
						printf("Error en el sistema.");
						return -1;
						}				
							fprintf(us ,"%s %s", nickname, pass);							
				 			fclose(us);
							 	
						us = fopen("C:/Foro/usuarios.txt", "r");
						if(us == NULL){
						printf("Error en el sistema.");
						return -1;
						}	
						else{
						while((strcmp(user,nickname))!=0||(strcmp(pass,pass2)!=0)){
							printf("Contraseña incorrecta\n");
						}
							printf("\n");
									printf("Bienvenido %s !\n",nickname);
						fclose(us);
									conectado=1;
										while(conectado==1){
										printf("Menu.\n");  
								  		printf("1- Visualiza post: \n");
								  		printf("2- Salir: \n");
								  		scanf("%i", &eleccion);
								  		switch(eleccion){
								  			case 1:
								  				printf("Elige un tema para acceder al foro:\n");
  												printf("1- Futbol \n");
  												printf("2- Coche \n");
  												printf("3- General \n");
  												printf("4- Iniciar un tema nuevo \n");
  												scanf("%i",&eleccion);
  												switch(eleccion){
  													case 1:
  														printf("\n Has elegido fisica");
  														futbol = fopen("C:/Foro/futbol.txt","a");
  														break;
  													case 2:
  														printf("\n Has elegido quimica");
  														coches = fopen("C:/Foro/coches.txt","a");
  														break;
  													case 3:
  														printf("\n Has elegido matematicas");
  														matematicas = fopen("C:/Foro/general.txt","a");
  														break;
  													case 4:
  														printf("\n Has elegido iniciar un nuevo tema de optativas");
  														libre = fopen("C:/Foro/libre.txt","a");
  														break;
  													default 
  														printf("\n Eleccion erronea");
  														break;
				  								}
								  				break;
								  			case 2:
								  				conectado=2;
								  				printf("Vuelve pronto!\n");
								  				break;
								  			default:
								  				printf("Fallo de opcion.");
								  				break;
  											}
  									}
						}
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
}
