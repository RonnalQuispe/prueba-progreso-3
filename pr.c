#include <stdio.h>
#include <string.h>

// Función para crear un archivo con el nombre proporcionado
int crearArchivo(char nombreArchivo[]) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w+");  // Abre el archivo en modo lectura y escritura
    if (archivo == NULL) {
        printf("No se puede crear el archivo\n");
        return 0;
    } else {
        printf("Se ha creado el archivo, %s\n", nombreArchivo);
        fclose(archivo);
    }
    return 1;
}

// Función para abrir un archivo con el nombre proporcionado
int abrirArchivo(char nombreArchivo[]) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");  // Abre el archivo en modo lectura y escritura
    if (archivo == NULL) {
        printf("No se puede abrir el archivo. Seguramente no existe.\n");
        return 0;
    }
    fclose(archivo);
    return 1;
}

// Función para guardar nombres en un archivo
void guardarNombresArchivo(char nombreArchivo[], char nombres[5][4][50]) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");  // Abre el archivo en modo lectura y escritura
    if (archivo == NULL) {
        printf("No se puede guardar en el archivo\n");
    } else {
        for (int i = 0; i < 5; i++) {
            fprintf(archivo, "%s %s %s %s\n", nombres[i][0], nombres[i][1], nombres[i][2], nombres[i][3]);
        }
        fclose(archivo);
    }
}

// Función para leer nombres desde un archivo
void leerNombresArchivo(char nombreArchivo[]) {
    char id[50];
    char nombre[50];
    float edad;
    int estado;
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL) {
        printf("No se puede leer el archivo\n");
    } else {
        while (!feof(archivo)) {
            fscanf(archivo, "%s %s %f %d", &id, &nombre, &edad, &estado);
            printf("%s %s %.2f %d\n", id, nombre, edad, estado);
        }
        fclose(archivo);
    }
}

// Función para buscar un nombre por su ID en un archivo y devuelve la posición en el archivo
long buscarNombrePorId(char nombreArchivo[], char id[]) {
    FILE *archivo;
    char idBuscado[50];
    char nombreEncontrado[50];
    float edad;
    int estado;
    long posicion;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL) {
        printf("No se puede leer el archivo\n");
    } else {
        while (!feof(archivo)) {
            posicion = ftell(archivo);
            fscanf(archivo, "%s %s %f %d", &idBuscado, &nombreEncontrado, &edad, &estado);
            if (strcmp(idBuscado, id) == 0) {
                printf("Se encontro el id %s con el nombre %s\n", idBuscado, nombreEncontrado);
                break;
            }
        }
        fclose(archivo);
    }
    return posicion;
}

// Función para reemplazar el nombre y la edad en función del ID en un archivo
void reemplazarNombreEdadPorId(char nombreArchivo[], long posicion, char nombre[], float edad) {
    FILE *archivo;
    char id[50];
    char nombreAntiguo[50];
    float edadAntiguo;
    int estadoAntiguo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL) {
        printf("No se puede leer el archivo\n");
    } else {
        fseek(archivo, posicion, 0);
        fscanf(archivo, "%s %s %f %d", &id, &nombreAntiguo, &edadAntiguo, &estadoAntiguo);
        fseek(archivo, posicion, 0);
        fprintf(archivo, "\n%s %s %.2f %d", id, nombre, edad, estadoAntiguo);
        fclose(archivo);
    }
}

// Función para ingresar un nuevo registro en un archivo
void ingresarRegistro(char nombreArchivo[], char id[], char nombre[], float edad, int estado) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r+");
    if (archivo == NULL) {
        printf("No se puede leer el archivo\n");
    } else {
        fseek(archivo, 0, 2);
        fprintf(archivo, "\n%s %s %.2f %d", id, nombre, edad, estado);
        fclose(archivo);
    }
}

// Función principal
int main(int argc, char *argv[]) {
    char nombres[5][4][50] = {{"a01", "Carlos", "36.00", "1"},
                              {"a02", "Luis", "30.00", "1"},
                              {"a03", "Ana", "20.00", "1"},
                              {"a04", "Maria", "50.00", "1"},
                              {"a05", "Juan", "40.00", "1"}};
    char nombreArchivo[20] = "datos.txt";
    long posicion;

    // Verifica si el archivo existe
    if (abrirArchivo(nombreArchivo)) {
        printf("Lista todos los datos en el archivo\n");
        leerNombresArchivo(nombreArchivo);
        printf("\nEncuentra un registro en el archivo en función del ID\n");
        posicion = buscarNombrePorId(nombreArchivo, "a05");
        printf("\nReemplaza el nombre y edad en función del ID\n");
        reemplazarNombreEdadPorId(nombreArchivo, posicion, "JuanPerez", 34);
        printf("\nLista los nuevos datos los datos en el archivo\n");
        leerNombresArchivo(nombreArchivo);
    } else {
        crearArchivo(nombreArchivo);
        guardarNombresArchivo(nombreArchivo, nombres);
    }

    return 0;
}

fopen
/*FILE *archivo;
archivo = fopen("ejemplo.txt", "w"); // Abre el archivo "ejemplo.txt" en modo escritura
if (archivo == NULL) {
  printf("No se pudo abrir el archivo\n");
} else {
 Operaciones en el archivo...
  fclose(archivo); // Cierra el archivo
}*/
fseek
/*FILE *archivo;
archivo = fopen("ejemplo.txt", "r");
if (archivo == NULL) {
    printf("No se pudo abrir el archivo\n");
} else {
    fseek(archivo, 10, SEEK_SET); // Mueve el puntero de posición a 10 bytes desde el inicio del archivo
    // Operaciones en el archivo...
    fclose(archivo);
}
*/
fscan
/*FILE *archivo;
char cadena[50];
archivo = fopen("ejemplo.txt", "r");
if (archivo == NULL) {
    printf("No se pudo abrir el archivo\n");
} else {
    fscanf(archivo, "%s", cadena); // Lee una cadena desde el archivo
    printf("Cadena leída: %s\n", cadena);
    fclose(archivo);
}
*/
fprint
/*FILE *archivo;
archivo = fopen("ejemplo.txt", "w");
if (archivo == NULL) {
    printf("No se pudo abrir el archivo\n");
} else {
    fprintf(archivo, "Ejemplo de escritura en archivo\n");
    // Otras operaciones en el archivo...
    fclose(archivo);
}
*/
FILE
/*FILE *archivo;
archivo = fopen("ejemplo.txt", "w");
if (archivo == NULL) {
    printf("No se pudo abrir el archivo\n");
} else {
    fprintf(archivo, "Ejemplo de escritura en archivo\n");
    // Otras operaciones en el archivo...
    fclose(archivo);
}
*/
/*#include <stdio.h>

int main() {
    FILE *archivo;
    archivo = fopen("ejemplo.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
    } else {
        // Operaciones en el archivo...
        fclose(archivo);
    }
    return 0;
}
*/
