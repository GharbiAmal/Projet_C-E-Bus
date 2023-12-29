//Amal gharbi II1A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Voyageur {
   int idV;
   char nom[100];
   char prenom[20];
   int age;
   char telephone[100];
   char adresse[50];
}Voyageur;



typedef struct Reservation {
   int idR;
   int voyageur_id;
   int bus_id;
   char date[50];
   char destination[50];
   int prix;
}Reservation;


typedef struct Bus {
   int idB;
   char destination[50];
   int prix;
   int totalseats;
   char date[50];
}Bus;


//Ajouter compte

void nouvCompte()
{
    struct Voyageur v;
    FILE * fv;
    fv = fopen("voyageur.txt","a");

      printf("\n\t       ** Ajouter Votre Coordonnees : ** ");
      printf("\n\t******************************************\n") ;
      printf("\n\t** Gardez votre Id : ** \n");


      printf("\n\tID             : ");
      scanf("%d",&v.idV);
      printf("\n\tNOM             : ");
      scanf("%s",&v.nom);
      printf("\n\tPRENOM          : ");
      scanf("%s",&v.prenom);
      printf("\n\tAge            : ");
      scanf("%s",&v.age);
      printf("\n\tAdresse            : ");
      scanf("%s",&v.adresse);
      printf("\n\tTelephone         : ");
      scanf("%s",&v.telephone);

      fwrite(&v,sizeof(v),1,fv);
      if (fwrite !=0){
        printf("\n\tCompte ajouter avec succes \n");
        printf("\n\t________________________________________\n") ;}
      else
        printf("\tErreur!");
      fclose(fv);
}


//Afficher Compte voyageur
void afficherCompteVoyageur()
{
    FILE * fv;
    struct Voyageur v;
    fv = fopen("voyageur.txt","r");
    if(fv == 0)
    {
        printf("\t\t\t impossible d'ouvrir le fichier!\n");
    }
    else{
    printf("\n\t       ** Touts les comptes : ** ");
    printf("\n\t******************************************\n") ;
    while (fread(&v,sizeof(v),1,fv) != 0)
    {
        printf("\n\t----------------------------------\n") ;
        printf("\t\t\tVoyageur ID    : %d\n",v.idV );
        printf("\t\t\tNom    : %s\n",v.nom  );
        printf("\t\t\tPrenom          : %s\n",v.prenom );
        printf("\t\t\tAge       : %d\n",v.age  );
        printf("\t\t\tAdresse          : %s\n",v.adresse  );
        printf("\t\t\tNumero          : %s\n",v.telephone  );

        printf("\t\t\t---------------------------- \n");
   }

   fclose(fv);
    }
}

//modifier voyageur


void modifierVoyageur(){
    FILE * fv;
    struct Voyageur v;
    fv = fopen("voyageur.txt","rb+");
    if(fv == 0)
    {
        printf("\t\t\t Impossible d'ouvrir le fichier!\n");
    }
    else{
    int K = 0;
    int id;
    char test;
    printf("\n\t       ** Modifier votre Compte : ** ");
      printf("\n\t******************************************\n") ;
    printf("\n\t\t\tSaisir votre ID : ");
    scanf("%d",&id);

     /* verification de id*/
    while (fread(&v, sizeof(v), 1, fv) != 0 && K == 0)
    {
        if (v.idV == id)
         {
            K = 1 ;
            break ;
        }
    }

    if(K == 0){
          printf("Votre compte n'existe pas!! \n");
    }else{

            fseek(fv,-sizeof(v),SEEK_CUR) ;
            printf("\t\t\t Vos Information : \n");
            printf("\t\t\t---------------------------- \n");
            printf("\t\t\tNOM          : %s\n",v.nom  );
            printf("\t\t\tPrenom       : %s\n",v.prenom );
            printf("\t\t\tadresse       : %s\n",v.adresse );
            printf("\t\t\ttelephone       : %s\n",v.telephone );
            printf("\t\t\tage       : %d\n",v.age );
            printf("\t\t\tqu'est ce que tu veux changer ?\n ");

            v.idV = id;
            /* modifier le nom */
           printf("\t\t\tnom ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNew nom : ");
                scanf("%s",&v.nom);
            }else
                {
                    strcpy(v.nom , v.nom);
                }
            printf("\n");

             /* modifier le prenom */
            printf("\t\t\tprenom ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNEW prenom : ");
                scanf("%s",&v.prenom) ;
            }else
                {
                    strcpy(v.prenom,v.prenom);
                }
            printf("\n");

            printf("\t\t\tadresse ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNEW adresse : ");
                scanf("%s",&v.adresse) ;
            }else
                {
                    strcpy(v.adresse,v.adresse);
                }
            printf("\n");

            printf("\t\t\ttelephone ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNEW telephone : ");
                scanf("%s",&v.telephone) ;
            }else
                {
                    strcpy(v.telephone,v.telephone);
                }
            printf("\n");

            printf("\t\t\tAge ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNEW Age : ");
                scanf("%d",&v.age) ;
            }else
                {
                    v.age,v.age;
                }
            printf("\n");

            /* sauvegarder les modification*/
            fwrite(&v,sizeof(v),1,fv);
        }

        fclose(fv);
        printf("\t\t\t votre compte est bien modifier!\n");
    }
}


//supprimer all voyageur

void supprimerVoyageur(){
    FILE* fv;
    FILE* temp;
    struct Voyageur v;
    fv = fopen("voyageur.txt","r");
    if(fv == 0)
    {
        printf("\t\t\ Impossible d'ouvrir le fichier!\n");
    }
    else{
    int K = 0;
    int id;

    printf("Donnez votre Id a supprimer : ");
    scanf("%d",&id);

    // verification de id
    while (fread(&v, sizeof(v), 1, fv) != 0 && K == 0)
    {
        if (v.idV == id)
        {
            K = 1 ;
            break ;
        }
    }

    if (K == 0)
    {
        printf("\t\t\tCet compte n'existe pas!\n");
        system("pause");
    }else{


    /* copier  qui n'est pas supprimer dans le fichier "suppclient" */
    temp = fopen("suppvoy.txt", "a");

    while( fread(&v, sizeof(v), 1, fv))
	{
		if(v.idV == id)
		{
            continue;
		}
		else
		{
			fwrite(&v,sizeof(v),1,temp);
		}
	}
	fclose(fv);
    remove("voyageur.txt");
    fclose(temp);
    rename("suppvoy.txt","voyageur.txt");
    printf("Ce voyageur est bien supprimee!\n");
    }}
}

/*------------------------------------------------------------------------------------------------------*/
void nouvBus()
{
    struct Bus b;
    FILE * fb;
    fb = fopen("bus.txt","a");

      printf("\n\t       ** Ajouter une bus : ** ");
      printf("\n\t******************************************\n") ;


      printf("\n\tID             : ");
      scanf("%d",&b.idB);
      printf("\n\tdestination             : ");
      scanf("%s",&b.destination);
      printf("\n\tdate jj/mm/aaaa          : ");
      scanf("%s",&b.date);
      printf("\n\tPrix du place          : ");
      scanf("%d",&b.prix);
      printf("\n\ttout les places            : ");
      scanf("%d",&b.totalseats);

      fwrite(&b,sizeof(b),1,fb);
      if (fwrite !=0){
        printf("\tbus ajouter avec succes ");
        printf("\n\t________________________________________\n") ;}
      else
        printf("\tErreur!");
      fclose(fb);
}


//Afficher Compte voyageur
void afficherbus()
{
    FILE * fb;
    struct Bus b;
    fb = fopen("bus.txt","r");
    if(fb == 0)
    {
        printf("\t\t\t impossible d'ouvrir le fichier!\n");
    }
    else{
    printf("\n\t       ** Voici les detailles des bus : **");
    printf("\t\t\**********************************************\n") ;
    while (fread(&b,sizeof(b),1,fb)!=0)
    {
        printf("\t\t\________________________________________\n") ;
        printf("\t\t\tbus ID    : %d\n",b.idB  );
        printf("\t\t\tdestination         : %s\n",b.destination );
        printf("\t\t\tPrix       : %d\n",b.prix  );
        printf("\t\t\ttoutes les places         : %d\n",b.totalseats  );
        printf("\t\t\tDate         : %s\n",b.date  );
        printf("\t\t\t---------------------------- \n");
   }

   fclose(fb);
    }
}

//modifier voyageur


void modifierbus(){
    FILE * fb;
    struct Bus b;
    fb = fopen("bus.txt","rb+");
    if(fb == 0)
    {
        printf("\t\t\t Impossible d'ouvrir le fichier!\n");
    }
    else{
    int K = 0;
    int id;
    char test;

    printf("\n\t       ** Modifier Bus : **");
    printf("\t\t\**********************************************\n") ;
    printf("\t\t\tSaisir ID : ");
    scanf("%d",&id);

     /* verification de id*/
    while (fread(&b, sizeof(b), 1, fb) != 0 && K == 0)
    {
        if (b.idB == id)
         {
            K = 1 ;
            break ;
        }
    }

    if(K == 0){
          printf("Cet Bus  n'existe pas\n");
    }else{


            fseek(fb,-sizeof(b),SEEK_CUR) ;
            printf("\t\t\t---------------------------- \n");
            printf("\t\t\tNOM          : %d\n",b.idB  );
            printf("\t\t\tPrenom       : %s\n",b.destination );
            printf("\t\t\tPrenom       : %d\n",b.prix );
            printf("\t\t\tPrenom       : %s\n",b.date );
            printf("\t\t\tPrenom       : %d\n",b.totalseats );
            printf("\t\t\tqu'est ce que tu veux changer ?\n ");

            b.idB = id;
            /* modifier le nom */
           printf("\t\t\tdestination ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNew destination : ");
                scanf("%s",&b.destination);
            }else
                {
                    strcpy(b.destination , b.destination);
                }
            printf("\n");

            printf("\t\t\tPrix ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNew Prix : ");
                scanf("%d",&b.prix);
            }else
                {
                    b.prix , b.prix;
                }
            printf("\n");


            printf("\t\t\tDate ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tDate : ");
                scanf("%s",&b.date);
            }else
                {
                    strcpy(b.date , b.date);
                }
            printf("\n");

            printf("\t\t\tNombre de Place ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNew Nombre de place : ");
                scanf("%s",&b.totalseats);
            }else
                {
                    b.totalseats , b.totalseats;
                }
            printf("\n");




            /* sauvegarder les modification*/
            fwrite(&b,sizeof(b),1,fb);
            printf("\t\t\tCe bus est bien modifier!\n");
        }

        fclose(fb);

    }
}


//supprimer voyageur

void supprimerBus(){
    FILE* fb;
    FILE* temp;
    struct Bus b;
    fb = fopen("bus.txt","r");
    if(fb == 0)
    {
        printf("\t\t\ Impossible d'ouvrir le fichier!\n");
    }
    else{
    int K = 0;
    int id;

    printf("Donnez le id a supprimer : ");
    scanf("%d",&id);

    // verification de id
    while (fread(&b, sizeof(b), 1, fb) != 0 && K == 0)
    {
        if (b.idB == id)
        {
            K = 1 ;
            break ;
        }
    }

    if (K == 0)
    {
        printf("\t\t\tCe bus n'existe pas!\n");
        system("pause");
    }else{


    /* copier  qui n'est pas supprimer dans le fichier "suppclient" */
    temp = fopen("suppvoy.txt", "a");

    while( fread(&b, sizeof(b), 1, fb))
	{
		if(b.idB == id)
		{
            continue;
		}
		else
		{
			fwrite(&b,sizeof(b),1,temp);
		}
	}
	fclose(fb);
    remove("bus.txt");
    fclose(temp);
    rename("suppvoy.txt","bus.txt");
    printf("Ce Bus est bien supprimee!\n");
    }}
}




void rechercher_destination() {
    FILE *fb;
    struct Bus b;
    fb = fopen("bus.txt", "r");

    if (fb == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    struct Bus lb[100];
    int nb = 0;

    while (fread(&b, sizeof(b), 1, fb)) {
        lb[nb] = b;
        nb++;
    }

    fclose(fb);

    printf("\n\t_____________________________________\n");//depart du Tunis
    printf("\n\tVEUILLEZ CHOISIR UNE DESTINATION\n");

    char de[100]; // Utiliser un tableau de caractères pour stocker la destination

    printf("\t\tTA REPONSE : ");
    scanf("%s", de);

    int destinationTrouvee = 0; // Variable pour vérifier si une destination a été trouvée

    for (int j = 0; j < nb; j++) {
        if (strnicmp(lb[j].destination, de, strlen(de)) == 0) {
            destinationTrouvee = 1;

            printf("\n________________________________________\n");
            printf("\t\t\tbus ID    : %d\n", lb[j].idB);
            printf("\t\t\tdestination         : %s\n", lb[j].destination);
            printf("\t\t\tPrix       : %d\n", lb[j].prix);
            printf("\t\t\ttoutes les places         : %d\n", lb[j].totalseats);
            printf("\t\t\tDate         : %s\n", lb[j].date);
            printf("\n________________________________________\n");
        }
    }

    if (!destinationTrouvee) {
        printf("Il n'y a pas de voyage vers la destination entrée précédemment.\n");
    }
}





/*void supprimerOneBus() {
    FILE* fb;
    FILE* temp;
    struct Bus b;

    // Ouverture du fichier en mode lecture
    fb = fopen("bus.txt", "rb");
    if (fb == NULL) {
        perror("\t\tImpossible d'ouvrir le fichier en lecture");
        return;
    }

    int K = 0;
    int id;

    printf("Donnez l'ID à supprimer : ");
    scanf("%d", &id);

    // Vérification de l'ID
    while (fread(&b, sizeof(b), 1, fb) != 0 && K == 0) {
        if (b.idB == id) {
            K = 1;
            break;
        }
    }

    if (K == 0) {
        printf("\t\tCe bus n'existe pas!\n");
        fclose(fb);
        return;
    }

    // Ouverture du fichier temporaire en mode écriture
    temp = fopen("suppvoy.txt", "wb");
    if (temp == NULL) {
        perror("\t\tImpossible d'ouvrir le fichier temporaire en écriture");
        fclose(fb);
        return;
    }

    // Réinitialisation du curseur au début du fichier
    fseek(fb, 0, SEEK_SET);

    // Copier ce qui n'est pas supprimé dans le fichier temporaire
    while (fread(&b, sizeof(b), 1, fb)) {
        if (b.idB != id) {
            fwrite(&b, sizeof(b), 1, temp);
        }
    }

    fclose(fb);
    fclose(temp);

    // Suppression du fichier original
    if (remove("bus.txt") != 0) {
        perror("\t\tImpossible de supprimer le fichier original");
        return;
    }

    // Renommage du fichier temporaire
    if (rename("suppvoy.txt", "bus.txt") != 0) {
        perror("\t\tImpossible de renommer le fichier temporaire");
        return;
    }

    printf("Le bus avec l'ID %d a été supprimé avec succès!\n", id);
}
*/

/*---------------------------------------------------------------------------------*/
void ReservationBus(){
     FILE *fb ;
     FILE *fv ;
     FILE *fres;
     FILE *templ;

    fb = fopen("bus.txt","r");
    fv = fopen("voyageur.txt","r");
    fres = fopen("reservation.txt","a");
    templ= fopen("testres.txt", "a");
    struct Voyageur v ;
	struct Bus test ;
	struct Bus b;
	struct Reservation r ;
    if(fres == 0 )
    {
        printf("\t\t\tImpossible d'ouvrir le fichier!\n");
    }
    else{
	//int K = 0;
	//int L = 0 ;
	int id,idBt;

    printf("\t\t\t Saisir votre ID  :");
    scanf("%d",&r.voyageur_id);


    while (fread(&v, sizeof(v), 1, fv) != 0)
    {
        if ( v.idV == r.voyageur_id )
	    {

	      	printf ("\t\t\tNum bus  : ");
			scanf ("%d", &r.bus_id);

	        while (fread(&b, sizeof(b), 1, fb) != 0)
			{

	            if(b.idB!=r.bus_id)
	            {
	                printf("\t\t\t ok ! \n");

                               }else
                               if(b.totalseats == 0)
                                {
                                    printf("\t\t\t cette bus est pleine \n");

                                }else
                                    {
                                    r.idR=b.idB+v.idV;
                                    r.prix = b.prix;

                                    strcpy(r.date, b.date);
                                    strcpy(r.destination, b.destination);


                                    fwrite(&r,sizeof(r),1,fres);
                                    if (fwrite !=0){
                                    printf("\reservation ajouter avec succes ");}
                                  else{
                                    printf("\tErreur!");}
                                   /* b.availableSeats--;
                                    strcpy(b.availableSeats , b.availableSeats--);

*/


                                    }

	        }



		}else{
		    printf("\t\t\t ok ! \n");
		}
	}
    //fwrite(&b,sizeof(b),1,fb);

	fclose(fv);
	fclose(fres);
	fclose(fb);

    }
}


//afficher res

void afficherReservation()
{
    FILE * fr;
    struct Reservation r;
    fr = fopen("reservation.txt","rb");
    Reservation res[100];
    int nb = 0 ;
    while(fread(&r,sizeof(r),1,fr)){
        res[nb]=r;
        nb++ ;
    }
    fclose(fr);

    printf("Voici les detailles des voyageurs\n");
    for(int j=0;j<nb;j++){
      printf("\n________________________________________") ;
      printf("\nbus Id     : %d",res[j].bus_id);
      printf("\nvoyageur id     : %d",res[j].voyageur_id);
      printf("\ndestination  : %s",res[j].destination);
      printf("\nprix     : %d",res[j].prix);
      printf("\nreservation Id : %d",res[j].idR);


    }
    printf("\n________________________________________") ;


    }


// suppres

void supprimerReservation(){
    FILE* fr;
    FILE* temp;
    struct Reservation r;
    fr = fopen("bus.txt","rb");
    if(fr == 0)
    {
        printf("\t\t\ Impossible d'ouvrir le fichier!\n");
    }
    else{
    int K = 0;
    int L=0;
    int id,idb;

    printf("Donnez votre id a supprimer : ");
    scanf("%d",&id);

    // verification de id
    while (fread(&r, sizeof(r), 1, fr) != 0 && K == 0)
    {
        if (r.voyageur_id == id)
        {
            K = 1 ;
            break ;
        }
    }

    if (K == 0)
    {
        printf("\t\t\tvotre id est incorrecte!\n");
        system("pause");
    }else{

        printf("Donnez votre id bus reserver a supprimer : ");
        scanf("%d",&idb);
        while( fread(&r, sizeof(r), 1, fr)){
                if (r.bus_id == idb)
        {
            L = 1 ;
            break ;
        }

        }

if (L==0){
        printf("\t\t\tpas de bus reserver par cet id!\n");
        system("pause");
}else{
    /* copier  qui n'est pas supprimer dans le fichier "suppclient" */
    temp = fopen("suppres.txt", "a");

    while( fread(&r, sizeof(r), 1, fr))
	{

		if(r.voyageur_id == id && r.bus_id == idb)
		{
            continue;
		}
		else
		{
			fwrite(&r,sizeof(r),1,temp);
		}
	}
	fclose(fr);
    remove("reservation.txt");
    fclose(temp);
    rename("suppres.txt","reservation.txt");
    printf("Cet reservation est bien supprimee!\n");
    }


    }
    }
}


/*--------------------------------------------------*/

void modifierRes(){
    FILE * fr;
    struct Reservation r;
    fr = fopen("reservation.txt","rb+");
    if(fr == 0)
    {
        printf("\t\t\t Impossible d'ouvrir le fichier!\n");
    }
    else{
    int K = 0;

    int id;
    char test;
    printf("\t\t\t Saisir votre Id : ");
    scanf("%d",&id);

     /* verification de id*/
    while (fread(&r, sizeof(r), 1, fr) != 0 && K == 0)
    {
        if (r.voyageur_id == id)
         {
            K = 1 ;
            break ;
        }
    }

    if(K == 0){
          printf("vous n'avez pas une reservation a modifier\n");
    }else{


            fseek(fr,-sizeof(r),SEEK_CUR) ;
            printf("\t\t\tInformation de reservation: \n");
            printf("\t\t\tID reservation          : %d\n",r.idR  );
            printf("\t\t\tID Bus          : %d\n",r.bus_id  );
            printf("\t\t\tDate         : %s\n",r.date  );
            printf("\t\t\tDestination       : %s\n",r.destination );
            printf("\t\t\tqu'est ce que tu veux changer ?\n ");

           r.voyageur_id = id;
            /* modifier le nom */
           printf("\t\t\tdestination ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNew destination : ");
                scanf("%s",&r.destination);
            }else
                {
                    strcpy(r.destination , r.destination);
                }
            printf("\n");
                printf("\t\t\tdate ? (o/n): ") ;
            scanf("%s",&test) ;
            if(test == 'o')
            {
                printf("\t\t\tNew date : ");
                scanf("%s",&r.date);
            }else
                {
                    strcpy(r.date , r.date);
                }
            printf("\n");


            /* sauvegarder les modification*/
            fwrite(&r,sizeof(r),1,fr);
            printf("\t\t\tCe bus est bien modifier!\n");
        }

        fclose(fr);
    }
}




void Menu_principal(){
int choix;
    do{
        printf("\t\t\t|--------MENU PRINCIPAL--------|\n");
        printf("\t\t\t|    Voyageur.................1|\n");
        printf("\t\t\t|    Administrateur.........2|\n");
        printf("\t\t\t|    Quitter..................3|\n");
        printf("\t\t\t Votre choix :");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1:
                voyageur();
                break;
            case 2:
                Admin();
                break;
            case 3:
                printf("\n\t\t\t FIN DU PROGRAMME!\n");
                printf("\n\t\t\t Merci Pour votre utilisation de nos Programme!\n");
                exit(0);
                break;
        }
    }while(choix>1 || choix<3);
}

void voyageur(){
int choix;
    system("cls");
    printf("\t\t\t|-----Partie Voyageur---------|\n");
    printf("\t\t\t|    Creer compte.......1|\n");
    printf("\t\t\t|    Modifier Compte...........2|\n");
    printf("\t\t\t|    Reserver dans une Bus........3|\n");
    printf("\t\t\t|    Modifier Reservation.........4|\n");
    printf("\t\t\t|    Lister Bus disponibles.........5|\n");
    printf("\t\t\t|    Rechercher selon une destination.........6|\n");
    printf("\t\t\t|    Retour...................7|\n");
    printf("\t\t\t Votre choix :");
    scanf("%d",&choix);
    switch(choix)
    {
        case 1:
             nouvCompte();
            break;
        case 2:
            modifierVoyageur();
            break;
        case 3:
            ReservationBus();
            break;
        case 4:
           modifierRes();
            break;
        case 5:
            afficherbus();
            break;
        case 6:
            rechercher_destination();
            break;
        case 7:
            Menu_principal();
            break;
    }while(choix<0 || choix>7);
}


void Admin(){
int choix;
    system("cls");
    printf("\n");
    printf("\n");
    printf("\t\t\t|-----Partie Admin---------|\n");
    printf("\t\t\t|    Ajouter Bus.......1|\n");
    printf("\t\t\t|    Lister Voyageur...........2|\n");
    printf("\t\t\t|    Lister Bus........3|\n");
    printf("\t\t\t|    Lister Reservation.........4|\n");
    printf("\t\t\t|    Supprimer  Voyageur........5|\n");
    printf("\t\t\t|    Supprimer  Bus........6|\n");
    printf("\t\t\t|    Supprimer  Reservation........7|\n");
    printf("\t\t\t|    Retour...................8|\n");
    printf("\t\t\t Votre choix :");
    scanf("%d",&choix);
    switch(choix)
    {
        case 1:
             nouvBus();
            break;
        case 2:
            afficherCompteVoyageur();
            break;
        case 3:
            afficherbus();
            break;
        case 4:
           afficherReservation();
            break;
        case 5:
            supprimerVoyageur();
            break;
        case 6:
            supprimerBus();
            break;
        case 7:
           supprimerReservation();
            break;

        case 8:
            Menu_principal();
            break;
    }while(choix<0 || choix>8);
}





main ()
{
    printf("\n\t\t *********E-BUS APPLICATION (Amal Gharbi II1A)************\n");
    printf("\n \n");
    printf("\n  \n");

    Menu_principal();
   //nouvCompte();
   //afficherCompteVoyageur();
  // modifierVoyageur();
   //supprimerVoyageur();
   //supprimervoy();
   //afficherCompteVoyageur();

    //nouvBus();
   //afficherbus();
   //supprimer();
   //modifierbus();
   //supprimerBus();
   //afficherbus();
    //ReservationBus();
   //afficherReservation();
   //supprimerReservation();
//modifierRes();
    return 0;
}

