#include <stdio.h>
#include<string.h>
#define N 50

typedef struct{
	char nombre[N];
	char apellido1[N];
	char apellido2[N];
	char grado[N];
}datos;

void valoracion(int nota);
void leerPost(FILE* auxiliar,char lectura[N]);
void escribirPost(FILE* auxiliar,char nickname[N],char escritura[N]);


int main(){
  int eleccion,conectado;   // Conectado tendra 3 valores base:  0 estamos sin estado, 1 estamos conectados, 2 decidimos salir
  char user[N];
  char pass1[N];  
  char pass2[N];
  char pass[N];
  char prueba[N];
  char prueba2[N];
  char nickname[N];
  char parabusqueda[N];
  char lectura[N]; 
  char escritura[N];   
  int cont;
  int nota;
  char comentario[N];
  datos datos[N];
  conectado=0;
  int i=0;
  FILE *us;
  FILE *os;
  FILE *matematicas;
  FILE *fisica;
  FILE *quimica;
  FILE *libre;
  printf("Bienvenido al foro de la universidad.\n");
  printf("Quieres crear un nuevo usuario o quieres acceder con uno? \n");
  printf("1- Nuevo usuario: \n");
  printf("2- Ingresar: \n");
  printf("3- Salir: \n");
  
  while(conectado==0){
  		scanf("%i", &eleccion);
  		switch(eleccion){
  			case 1:  
			  	printf("Rellena con tus datos\n");
				printf("Nombre y apellidos\n");
				scanf("%s %s %s",&datos[N].nombre, &datos[N].apellido1, &datos[N].apellido2);
				printf("Grado en ingenieria: Quimica, Electrica, Mecanica, Electronica o Diseño\n");
				scanf("%s", &datos[N].grado);				
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
								printf("Estas al limite de la password, no puedes introducir mas caracteres.\n");
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
         					printf("Las pass por ahora son: \n");
         					printf("Pass1: %s\n",pass1);
         					printf("Pass2: %s\n",pass2);
         		}
         		while(strcmp(pass1,pass2)!=0);{	
         				printf("Password correcta\n");
				 }

					us = fopen("foros/usuarios.txt", "a");
						if(us == NULL){
						printf("Error en el sistema.");
						return -1;
						}				

					fprintf(us ,"%s-%s\n", user, pass1);
					fprintf(us,"%s %s %s : Grado de %s\n",datos[N].nombre,datos[N].apellido1,datos[N].apellido2,datos[N].grado);									
				 	fclose(us);
				 	conectado=1;
				 	strcpy(nickname,user);
						while(conectado==1){
							printf("Menu.\n");  
					  		printf("1- Visualiza post: \n");
					  		printf("2- Salir: \n");
					  		scanf("%i", &eleccion);
					  		switch(eleccion){
					  			case 1:
					  				printf("Bienvenido %s !\n",nickname);						
									conectado=1;																			
								  		switch(eleccion){
								  			case 1:
								  				printf("Elige un tema para acceder al foro:\n");
  												printf("1- Fisica \n");
  												printf("2- Quimica \n");
  												printf("3- Matematicas \n");
  												printf("4- Tematica libre\n");
  												scanf("%i",&eleccion);
  												switch(eleccion){
  													case 1:
  														printf("\n Has elegido fisica\n ");
  														fisica = fopen("foros/fisica.txt","r");
  														leerPost(fisica,lectura);
  														fclose(fisica);
  														printf("\n Quieres contestar?\n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){  
														  		printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");																
  																scanf("[%^\n]",&escritura);
															  	fisica = fopen("foros/fisica.txt","a");
  																escribirPost(fisica,nickname,escritura);
  																fclose(fisica);
														}
  														break;

  													case 2:
  														printf("\n Has elegido quimica\n ");
  														quimica = fopen("foros/quimica.txt","r");
  														leerPost(quimica,lectura);
  														fclose(quimica);
  														printf("\n Quieres contestar? \n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){
  																printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");	
  																quimica = fopen("foros/quimica.txt","a");
  																escribirPost(quimica,nickname,escritura);
  																fclose(quimica);
														  }
  														break;

  													case 3:
  														printf("\n Has elegido matematicas\n ");
  														matematicas = fopen("foros/matematicas.txt","r");
  														leerPost(matematicas,lectura);
  														fclose(matematicas);
  														printf("\n Quieres contestar? \n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){
  																printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");	
  																matematicas = fopen("foros/matematicas.txt","a");
  																escribirPost(matematicas,nickname,escritura);
  																fclose(matematicas);
														  }
  														break;

  													case 4:
  														printf("\n Has elegido iniciar un nuevo tema de optativas\n ");
  														libre = fopen("foros/libre.txt","r");
  														leerPost(libre,lectura);
  														fclose(libre);
  														printf("\n Quieres contestar? \n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){
  															printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");	
  															libre = fopen("foros/libre.txt","a");
  															escribirPost(libre,nickname,escritura);
  															fclose(libre);
														  }
  														break;

  													default:
  														printf("\n Eleccion erronea");
  														break;
				  								}
								  				break;

								  			case 2:
								  				conectado=2;
								  				printf("Por ultimo, queremos saber la nota con la que valoras el foro\n");
												scanf("%d", &nota);
												printf("Dejanos alguna recomendacion para mejorar\n");
												scanf("%s", comentario);
												valoracion(nota);
								  				printf("Vuelve pronto!\n");
								  				break;

								  			default:
								  				printf("Fallo de opcion.");
								  				break;

  											}  										
					  				break;
					  			case 2:
					  				printf("Por ultimo, queremos saber la nota con la que valoras el foro\n");
									scanf("%d", &nota);
									printf("Dejanos alguna recomendacion para mejorar\n");
									scanf("%s", comentario);
									conectado=2;
									valoracion(nota);
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
            			printf("\n");
         					printf("Hemos ingresado: \n");
         					printf("usuario: %s\n",nickname);
         					printf("Pass2: %s\n",pass);         				
						us = fopen("foros/usuarios.txt", "r");						
						if(us == NULL){
						printf("Error en el sistema.");
						return -1;
						}			
						strcpy(parabusqueda, nickname);
						strcat(parabusqueda, "-");
						strcat(parabusqueda, pass);
						while (feof(us) == 0){
					 			fgets(prueba,150,us);
					 			printf("Concatenamos:  %s\n",nickname);
					 			printf("Concatenamos:  %s\n",pass);
					 			printf("Buscamos:  %s\n",parabusqueda);
					 			printf("Obtenido de fichero:  %s\n",prueba);					
					 			if(strcmp(parabusqueda,prueba)!=0){
									printf("Password incorrecta\n");
								}else{
									printf("Password correcta\n");
								}
					 		}
				 			fclose(us);		
							printf("\n");
							printf("Bienvenido %s !\n",nickname);						
									conectado=1;
										while(conectado==1){
										printf("Menu.\n");  
								  		printf("1- Visualiza post: \n");
								  		printf("2- Salir: \n");
								  		scanf("%i", &eleccion);
								  		switch(eleccion){
								  			case 1:
								  				printf("Elige un tema para acceder al foro:\n");
  												printf("1- Fisica \n");
  												printf("2- Quimica \n");
  												printf("3- Matematicas \n");
  												printf("4- Tematica libre\n");
  												scanf("%i",&eleccion);
  												switch(eleccion){
  													case 1:
  														printf("\n Has elegido fisica\n ");
  														fisica = fopen("foros/fisica.txt","r");
  														leerPost(fisica,lectura);
  														fclose(fisica);
  														printf("\n Quieres contestar? \n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){  
														  		printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");																
  																fisica = fopen("foros/fisica.txt","a");
  																escribirPost(fisica,nickname,escritura);
  																fclose(fisica);
														}
  														break;

  													case 2:
  														printf("\n Has elegido quimica\n ");
  														quimica = fopen("foros/quimica.txt","r");
  														leerPost(quimica,lectura);
  														fclose(quimica);
  														printf("\n Quieres contestar? \n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){
  																printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");	
  																quimica = fopen("foros/quimica.txt","a");
  																escribirPost(quimica,nickname,escritura);
  																fclose(quimica);
														  }
  														break;

  													case 3:
  														printf("\n Has elegido matematicas\n ");
  														matematicas = fopen("foros/matematicas.txt","r");
  														leerPost(matematicas,lectura);
  														fclose(matematicas);
  														printf("\n Quieres contestar? \n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){
  																printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");	
  																matematicas = fopen("foros/matematicas.txt","a");
  																escribirPost(matematicas,nickname,escritura);
  																fclose(matematicas);
														  }
  														break;

  													case 4:
  														printf("\n Has elegido iniciar un nuevo tema de optativas\n ");
  														libre = fopen("foros/libre.txt","r");
  														leerPost(libre,lectura);
  														fclose(libre);
  														printf("\n Quieres contestar? \n");
  														printf("1-Si \n");
  														printf("2-No \n");
  														scanf("%i",&eleccion);
  														if(eleccion==1){
  															printf("\n Estamos teniendo problemas con la letra que añade un espacio, cuando quieras indicar un espacio entre palabras usa '_' mientras lo arreglamos. \n");	
  															libre = fopen("foros/libre.txt","a");
  															escribirPost(libre,nickname,escritura);
  															fclose(libre);
														  }
  														break;

  													default:
  														printf("\n Eleccion erronea");
  														break;
				  								}
								  				break;

								  			case 2:
								  				conectado=2;
								  				printf("Por ultimo, queremos saber la nota con la que valoras el foro\n");
												scanf("%d", &nota);
												printf("Dejanos alguna recomendacion para mejorar\n");
												scanf("%s", comentario);
												valoracion(nota);
								  				printf("Vuelve pronto!\n");
								  				break;

								  			default:
								  				printf("Fallo de opcion.");
								  				break;

  											}
  									}	
		  		break;
		  	case 3:
		  			printf("Por ultimo, queremos saber la nota con la que valoras el foro\n");
		  			printf("0 si lo odias, y 10 si te encanta\n");
					scanf("%d", &nota);
					printf("Dejanos alguna recomendacion para mejorar\n");
					scanf("%s", comentario);	
					valoracion(nota);					
  					printf("Vuelve pronto!\n");
  					conectado=2;
  					break;
  			default:
  				printf("Esa opcion no es valida repite.\n");
  				break;

  		} 
  	}
}
void valoracion(int nota){
		if(nota>=5){
			printf("Nos alegra que te guste nuestro foro\n");
		}
		else
		{
			printf("Intentaremos mejorarlo lo antes posible para poder llegar a un aprobado. Gracias por tu tiempo\n");
		}
		
		printf("Nos has valorado con un %d\n",nota);	
		printf("Intentaremos incluir tus recomendaciones cuanto antes\n");
	}
  
  	void escribirPost(FILE* auxiliar,char nickname[N],char escritura[N]){	
  		fprintf(auxiliar ,"%s:\n", nickname);	
  		printf("Escribe lo que quieras añadir y termina cuando quieras pulsando enter: \n");
  		fprintf(auxiliar ,"%s\n", escritura);	
}
  
  
  void leerPost(FILE* auxiliar,char lectura[N]){
  	while (feof(auxiliar) == 0){
		fgets(lectura,150,auxiliar);		
		printf("%s\n",lectura);								
	}
	
}

		   			


