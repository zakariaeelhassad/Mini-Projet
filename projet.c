#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIVRE 10

typedef struct {
    int id;
    char titre[100];
    char auteur[50];
    float prix ;
    int stock;
} Livre;
 int numberlivre = 0;


void ajouterlivre(Livre livre[]){
    int nombert;
    printf("Vous avez choisi d'ajouter un nouveau livre.\n");
    printf("combien des livres tu veux ajouter :");
    scanf("%d",&nombert);
    if(numberlivre < MAX_LIVRE){

    livre[numberlivre].id = numberlivre+1;
    for(int i = 0; i < nombert; i++) {

        livre[numberlivre].id = numberlivre+1;
        printf("livre:%d \n",livre[numberlivre].id);
        printf("TITRE: ");
        scanf(" %[^\n]s",livre[numberlivre].titre);
        printf("AUTEUR: ");
        scanf(" %[^\n]s",livre[numberlivre].auteur);
        printf("PRIX: ");
        scanf(" %f", &livre[numberlivre].prix);
        printf("STOCK: ");
        scanf(" %d", &livre[numberlivre].stock);
        printf("LIVRE : %d \n",livre[numberlivre].id);
        printf("titre de livre '%s' , auteur  thde livre '%s' , prix '%.2f' et le stock '%d' . \n",livre[numberlivre].titre,livre[numberlivre].auteur,livre[numberlivre].prix,livre[numberlivre].stock);
        printf(" ajoute avec succes!\n\n\n");
        numberlivre++;
    }
    }
     else {
        printf("limite de livres atteinte. Impossible d'ajouter plus de livre.\n\n\n");
    }
}

void afficherlivre (Livre livre[]){
    for (int i = 0 ; i < numberlivre ; i++){
        printf("livre : %d \n",livre[i].id) ;
        printf("titre : %s <<< auteur : %s <<< prix : %.2f <<< stock : %d .\n\n\n",livre[i].titre,livre[i].auteur,livre[i].prix,livre[i].stock);
    }
}

void mettreajourqlivre(Livre livre[],int numberlivre,char titrecom[]){
    printf("Entrer le titre de livre  a rechercher: ");
    scanf("%s", titrecom);
    for (int i = 0; i < numberlivre; i++) {
        if (strcmp(livre[i].titre, titrecom) == 0) {
                printf("livre : %d \n",livre[i].id) ;
                printf("titre : %s <<< stock : %d .\n",livre[i].titre,livre[i].stock);
        }

    }
    printf("modifier la quantite :");
    scanf("%d", &livre[numberlivre-1].stock);

    printf("Quantite est mettre a jour avec succes!\n\n\n");
}

void supprimerlivre(Livre livre[],int anumberlivre, char titrecom[]){
    printf("Entrer le titre de livre  a rechercher: ");
    scanf("%s", titrecom);
    int found = 0 ;
    int ids;
    char temtitre[20];
    char tempauteur[20];
    int tempP;
    float temq;

    for (int i = 0; i < numberlivre; i++) {

        if (strcmp(livre[i].titre, titrecom) == 0) {
            printf("livre : %d \n",livre[i].id) ;
            printf("titre : %s <<< auteur : %s <<< prix : %.2f <<< stock : %d .\n",livre[i].titre,livre[i].auteur , livre[i].prix ,livre[i].stock);

             strcpy(temtitre,livre[i].titre);
             strcpy(tempauteur,livre[i].titre);
             tempP = livre[i].prix;
             temq = livre[i].stock;

             for(int j = 0 ; j < numberlivre ; j++  ){

               strcpy(livre[j].titre,livre[j+1].titre) ;
               strcpy(livre[j].auteur , livre[j+1].auteur ) ;
                livre[j].prix = livre[j+1].prix  ;
                livre[j].stock = livre[j+1].stock  ;
             }
             numberlivre -- ;
             printf("livre %s supprimé avec succès!\n\n\n", temtitre);
             break;
        }
    }
}

void affichagenombertotalstock(Livre livre[]){
    int s =0;
    for( int i = 0 ; i < numberlivre ;i++ ){
        s = s + livre[i].stock ;
    }
    printf("le nomber total des livre en stock %d \n\n\n: ",s);
}

void menu(){
    printf("Choose an option:\n");
    printf("1.Ajouter un Livre \n");
    printf("2.Afficher Tous les Livres Disponibles \n");
    printf("3.Mettre a Jour la Quantite d'un Livre \n");
    printf("4.Supprimer un Livre du Stock \n");
    printf("5.Afficher le Nombre Total de Livres en Stock \n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
}
int main()
{
    char titrecom[20];
    Livre livre[MAX_LIVRE];
    int choice;
    do{
    menu();
    scanf("%d", &choice);
    switch(choice){
        case 1 :ajouterlivre(livre);
        break;
        case 2:afficherlivre(livre);
        break;
        case 3 :mettreajourqlivre(livre,numberlivre,titrecom);
        break;
        case 4:supprimerlivre(livre,numberlivre,titrecom);
        break;
        case 5:affichagenombertotalstock(livre);
        break;
        case 0 :printf("Quitter le programme.\n");
                break;
        default :
            printf("Cette option n'existe pas");
    }
    }while(choice != 0);

    return 0;
}