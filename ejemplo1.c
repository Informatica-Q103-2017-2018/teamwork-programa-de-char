
#include <stdio.h>

int main(){
  FILE *pf;
  int vals[3] = {1, 2, 3};
  // Abrimos fichero para escritura
  pf = fopen("datos.txt", "w");
  if (pf == NULL) 
    {// Si el resultado es NULL mensaje de error 
      printf("Error al abrir el fichero.\n");
      return -1;
    }
  else
    {// Si ha funcionado, comienza escritura
      fprintf(pf, "%i, %i, %i",
	      vals[0], vals[1], vals[2]);
      fclose(pf); // Cerramos fichero
      return 0;
    }
}

