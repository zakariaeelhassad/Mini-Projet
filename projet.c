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
    printf("You chose to add a new livre.\n");
    if(numberlivre < MAX_LIVRE){

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
    printf(" added successfully!\n\n");
    numberlivre++;
    }
     else {
        printf("student limit reached. Cannot add more student.\n\n");
    }
}

/*void afficherlivre(Livre livre[], int numberlivre, char titrecom[]) {
    printf("Enter the student name to search for: ");
    scanf("%s", titrecom);
    for (int i = 0; i < numberlivre; i++) {
        if (strcmp(livre[i].titre, titrecom) == 0) {
            printf("The student is '%s'.\n", titrecom);
            return;
        }
    }
    printf("Student not found.\n");
}*/

void afficherlivre (Livre livre[]){
    for (int i = 0 ; i < numberlivre ; i++){
        printf("livre : %d \n",livre[i].id) ;
        printf("titre : %s <<< auteur : %s <<< prix : %.2f <<< stock : %d .\n",livre[i].titre,livre[i].auteur,livre[i].prix,livre[i].stock);
    }
}

void mettreajourqlivre(Livre livre[],int numberlivre,char titrecom[]){
    printf("Enter the student name to search for: ");
    scanf("%s", titrecom);
    for (int i = 0; i < numberlivre; i++) {
        if (strcmp(livre[i].titre, titrecom) == 0) {
                printf("livre : %d \n",livre[i].id) ;
                printf("titre : %s <<< auteur : %s <<< prix : %.2f <<< stock : %d .\n",livre[i].titre,livre[i].auteur,livre[i].prix,livre[i].stock);
        }

    }
    printf("modifier la quantite :");
    scanf("%d", &livre[numberlivre-1].stock);

    printf("student updated successfully!\n\n");
}

void supprimerlivre(Livre livre[],int numberlivre, char titrecom[]){
    printf("Enter the student name to search for: ");
    scanf("%s", titrecom);
    for (int i = 0; i < numberlivre; i++) {
        if (strcmp(livre[i].titre, titrecom) == 0) {
                if(livre[i].titre == livre[i].id){
                    for (int j = i; j < numberlivre - 1; j++) {
                    livre[j] = livre[j + 1];
                }
                numberlivre--;
                printf("student %s deleted successfully!\n", titrecom);
                }
            return;
        }
    }
    printf("Student not found.\n");

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
        /*case 5:displaystudent(students);
        break;*/
        case 0 :printf("Exiting the program.\n");
                break;
        default :
            printf("hsdhd");
    }
    }while(choice != 0);

    return 0;
}