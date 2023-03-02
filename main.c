/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 04 - Structures and Pointers
 *   Hari dan Tanggal    : Rabu, 01 Maret 2023
 *   Nama (NIM)          : Daven Darmawan Sendjaya (13221062)
 *   Nama File           : main.c
 *   Deskripsi           : Membuat program untuk mencari karakter Pokemon
 */

// #include <shlwapi.h>
// #define strcasestr StrStrIA 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef struct Pokemon {
   char id[MAX_LEN];
   char name[MAX_LEN];
   char type[MAX_LEN];
} Pokemon;

// Fungsi untuk melakukan print sesuai input structure
void printPokemon(Pokemon *p) {
   printf("\nID: %s\nNama: %s\nType: %s\n", p -> id, p -> name, p -> type);
}

// Fungsi untuk melakukan pencarian ID pada array structure
void searchID(Pokemon *p, int n, int ID) {
   char str_ID[MAX_LEN];
   sprintf(str_ID, "%d", ID);

   int count = 0;

   for (int i = 0; i < n; i++){
      if (strcasestr(p[i].id, str_ID)){
         printPokemon(&p[i]);
         count++;
      }
   }

   if (count == 0){
      printf("\nPokemon yang memiliki ID %d belum ditangkap!", ID);
   }
}

// Fungsi untuk melakukan pencarian name pada array structure
void searchName(Pokemon *p, int n, char name[]) {
   int count = 0;

   for (int i = 0; i < n; i++){
      if (strcasestr(p[i].name, name) != NULL){
         printPokemon(&p[i]);
         count++;
      }
   }

   if (count == 0){
         printf("\nPokemon dengan nama %s belum ditangkap!", name);
         count = 0;
   }
}

//Fungsi untuk melakukan pencarian type pada array structure
void searchType(Pokemon *p, int n, char type[]) {
   int count = 0;

   for (int i = 0; i < n; i++){
      if (strcasestr(p[i].type, type)){
         printPokemon(&p[i]);
         count++;
      }
   }

   if (count == 0){
      printf("\nPokemon dengan type %s belum ditangkap!", type);
   }
}

int main() {
   // Mendeklarasikan nama file
   char filename[MAX_LEN];

   // Menginput nama file ke dalam program
   printf("Masukkan nama file input: ");
   scanf("%s", filename);

   // Membuka file
   FILE *stream = fopen(filename, "r");

   // Deklarasi line dalam file
   char line[MAX_LEN];
   fgets(line, MAX_LEN, stream);

   // Memasukkan pilihan pencarian
   char pil[MAX_LEN];
   int n_pil = strlen(line);
   strncpy(pil, line, n_pil-1);

   int bil_pil = atoi(pil);
   
   // Inisiasi array dinamis structure
   int n = 0;
   Pokemon *chr;
   chr = (Pokemon*) malloc ((n+1) * sizeof(Pokemon));

   // Deklarasi token
   char* token;

   // Parsing ke array dinamis
   while (fgets(line, MAX_LEN, stream)){
      chr = realloc(chr, (n+1) * sizeof(Pokemon));
      
      token = strtok(line, ";");
      strcpy(chr[n].id, token);
      
      token = strtok(NULL, ";");
      strcpy(chr[n].name, token);

      token = strtok(NULL, "\n");
      strcpy(chr[n].type, token);
      
      n += 1;
   }

   // Mengambil data karakter
   if (bil_pil == 1){
      int id;
      printf("\nProgram mencari ID pokemon\nMasukkan ID pokemon yang ingin dicari: ");
      scanf("%d", &id);

      searchID(chr, n, id);
   }
      
   else if (bil_pil == 2){
      char srh_name[MAX_LEN];
      printf("\nProgram mencari Nama pokemon\nMasukkan Nama pokemon yang ingin dicari: ");
      scanf("%s", &srh_name);
      
      searchName(chr, n, srh_name);
   }

   else if (bil_pil == 3){
      char srh_typ[MAX_LEN];
      printf("\nProgram mencari Type pokemon\nMasukkan Type pokemon yang ingin dicari: ");
      scanf("%s", srh_typ);

      searchType(chr, n, srh_typ);
   }

   return 0;
}
