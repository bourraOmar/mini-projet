#include<stdio.h>
#include<string.h>

int main(){
    char titre[100][20];
    char auteur[100][20];
    char recherche[100];
    float prix[100];
    int stock[100];
    int count = 0;
    int trouve= 0;
    int stockT= 0;
    int choix , i,j;
    do{
        printf("\n***Bienvenue des la birairie Taliss BASHA***");
		printf("\n Pour ajoute un liver cliquer sur 1");
		printf("\n Pour afficher tout les liver disponible cliquer sur 2");
		printf("\n Pour rechercher un livre par son titre cliquer sur 3");
		printf("\n Pour Mettre à jour la quantité d'un livre cliquer sur 4");
		printf("\n Pour Supprimer un livre du stock cliquer sur 5");
		printf("\n Pour Afficher le nombre total de livres en stock cliquer sur 6");
		printf("\n Pour quitter cliquer sur 7");
		printf("\n Entre votre choix: ");
		scanf("%d",&choix);
        if(choix==1){
            printf("Vous souhaitez ajouter un liver.\n");
            printf("Entrez le titre du livre : ");
            scanf(" %s[^\n]", titre[count]);
            printf("Entrez le nom de l'auteur : ");
            scanf(" %s[^\n]", auteur[count]);
            printf("Entrez le prix du livre : ");
            scanf("%f", &prix[count]);
            printf("Entrez la stock : ");
            scanf("%d", &stock[count]);
                count++;
            printf("le liver a été ajouté avec succès.\n");
        }
        if(choix == 2){
            printf("Pour les livres existants: %d",count);
            if (count == 0) {
                printf("Aucun liver n'a été ajouté \n");
            } else {
                printf("Les livres existants sont: \n");
                for (i = 0; i < count; i++) {
                    printf("Titre : %s\n Auteur : %s\n Prix : %.2f Dh\n Stock : %d\n", titre[i], auteur[i], prix[i], stock[i]);
                }
            }
        }
        if(choix == 3){
        	printf("Entrez le titre de livre vous rechercher: ");
        	scanf("%s[^%]", recherche);
        	for (i = 0; i < count; i++) {
        	     if (strcmp(titre[i], recherche) == 0) {
        	         printf("Livre trouvé :\n");
        	         printf("Titre : %s\nAuteur : %s\nPrix : %.2f\nQuantité : %d\n", titre[i], auteur[i], prix[i], stock[i]);
        	         trouve = 1;
        	         break;
        	      }
        	 }
        	 if (trouve == 0) {
        	     printf("Livre non trouvé.\n");
        	 }
        }
        if(choix == 4){
        	printf("Entrez le titre de livre vous rechercher: ");
        	scanf("%s[^%]", recherche);
        	for (i = 0; i < count; i++) {
        	     if (strcmp(titre[i], recherche) == 0) {
        	         printf("Entre la nouvelle quantité: ");
        	         scanf("%d",stock[i]);
        	         trouve = 1;
        	         break;
        	     }
        	}
        	if (trouve == 0) {
        	 	printf("Livre non trouvé.\n");
        	}
        }
        if(choix == 5){
            printf("Entrez le titre du livre a supprimer : ");
            scanf(" %s[^\n]", recherche);
            for(i=0 ; i<count ; i++){
                 if(strcmp(titre[i],recherche) == 0) {
                    for(j=i;j<count;j++){
                        strcpy(titre[j], titre[j+1]);
                        strcpy (auteur[j], auteur[j+1]);
                        prix[j] = prix[j+1];
                        stock[j] = stock[j+1];
                        trouve = 1 ;
                    }
                    count -- ;
                    printf("Livre supprime avec succes.\n");
                    trouve = 1;
                    break;
                 }
            }
            if (trouve !=1 ) {
            printf("Livre non trouvé\n");
            }
        }
        else if(choix == 6 ){
            for(i=0 ; i<count ; i++){
                  stockT = stockT + stock[i] ;
            }
            printf("Nombre total de livres en stock : %d\n", stockT );
        }
    }while(choix != 7);
    printf("\n Vous avez sortez de la birairie Taliss BASHA");
}
