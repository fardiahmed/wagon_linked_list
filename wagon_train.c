#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Wagon
{
    int Num;
    char *Type;
    char *Etat;
    struct Wagon *NxtWagon;
}ListeDWagon;


ListeDWagon *AjoutLocomotive(int Valeur ,char type[11],char etat[2],ListeDWagon *ptr) //en tete
{
    ListeDWagon *TWag;
    TWag = malloc(sizeof(ListeDWagon));
    TWag->Num = Valeur;
    TWag->Type = type;
    TWag->Etat = etat;
    TWag->NxtWagon = ptr;
 
    return TWag;
}
 
void AfficheTrain(ListeDWagon *ptr)
{
    ListeDWagon *TWag;
    TWag = ptr;
 
    while (TWag)
    {
        printf("Wagon N:%d\n", TWag->Num);
        printf("Type:%s \n", TWag->Type);
        printf("Etat:%s\n",TWag->Etat);
        TWag = TWag->NxtWagon;
    }
}
 
int NumberWagon(ListeDWagon *ptr)
{
    ListeDWagon *TWag;
    TWag = ptr;
    int cpt;
    cpt = 0;
    while (TWag)
    {
        cpt++;
        TWag = TWag->NxtWagon;
    }
    return cpt;
}
 
 
int AjoutNemeWagon (int N, int Valeur, ListeDWagon *ptr)
{
    int cpt;
    cpt = 1;
    ListeDWagon *TWag;
    TWag = ptr;
    ListeDWagon *TWag1;
 
    while(cpt<N-1)
    {
        cpt++;
        TWag = TWag->NxtWagon;
    }
 
    TWag1 = malloc(sizeof(ListeDWagon));
    TWag1->Num = Valeur;
 
    if(N == 1)
    {
        TWag1->NxtWagon = TWag;
        TWag = TWag1;
        return TWag;
    }
    else
    {
        TWag1->NxtWagon = TWag->NxtWagon;
        TWag->NxtWagon = TWag1;
        return ptr;
    }
}
 ListeDWagon *AjoutWagon(int valeur,char type[11],char etat[2],ListeDWagon *liste)
{

    ListeDWagon *Twag1 = malloc(sizeof(ListeDWagon));
 
    Twag1->Num = valeur;
    Twag1->Type = type;
    Twag1->Etat = etat;
    Twag1->NxtWagon = NULL;
 
    if(liste == NULL)
    {
        return Twag1;
    }
    else
    {

        ListeDWagon* temp=liste;
        while(temp->NxtWagon != NULL)
        {
            temp = temp->NxtWagon;
        }
        temp->NxtWagon = Twag1;
        return liste;
    }
}
int rechercherElement(int valeur,ListeDWagon *liste)
{
    ListeDWagon *tmp=liste;

    while(tmp != NULL)
    {
        if(tmp->Num == valeur)
        {
        printf("Wagon trouve \n");
        printf("Wagon N:%d\n", tmp->Num);
        printf("Type:%s \n", tmp->Type);
        printf("Etat:%s\n",tmp->Etat);
            return 1;
        }
        tmp = tmp->NxtWagon;
    }
    return 0;
}
ListeDWagon *supprimerPanne(ListeDWagon *liste)
{
   
    if(liste == NULL)
        return NULL;
 
    if(liste->Etat == "ko")
    {

        ListeDWagon *tmp = liste->NxtWagon;
        free(liste);

        tmp = supprimerPanne(tmp);
        return tmp;
    }
    else
    {

        liste->NxtWagon = supprimerPanne(liste->NxtWagon);
        return liste;
    }
}
main()
{
    ListeDWagon *TRAIN= NULL;
    char type[11];
    char etat[3];
    char Choix;
    int Valeur,val, N;
    char n[10];
    //TRAIN = NULL;
    
    while (1)
    {
        
    
         mainmenu :{ printf("\n           <==========> MENU <==========>\n");
        printf("\n");
        printf("=======================================================\n");
        printf("|| a :: Ajouter un  Wagon a la fin du train           ||\n");
        printf("|| b :: Ajouter une  Locomotive  en tete du train     ||\n");
        printf("|| c :: Rechercher d'un  Wagon                        ||\n");
        printf("|| d :: Afficher le train                             ||\n");
        printf("|| e :: Supprimer un  Wagon  en panne dans le train   ||\n");
        printf("|| f :: comptage du nombre d'elements dans la liste   ||\n");
        printf("|| g :: Ajouter un  Wagon apres un autre wagon donnee ||\n");
        printf("|| h :: Liberer les resources occupe parle train      ||\n");
        printf("=======================================================\n");
        printf("\n  <==========> Choisir une option SVP <==========>\n");}
  

        scanf("%c",&Choix);
        getc(stdin);
 
        switch(Choix)
        {
            case 'a': printf("\n valeur wagon a ajouter ? ");

                    gets(n);
                    //fgets(n,10,stdin);
                   
                     while (strlen(n) > 0)
                     {
                         Valeur = atoi(n);
                        
                         TRAIN = AjoutWagon(Valeur,"Wagon","ok",TRAIN);
 
                         printf("\najouter encore des wagons au train ? ");
                        // scanf("%c ", &n);
                         gets(n);
                     }
                break;
            case 'b': printf("\n valeur Locomotive a ajouter ? ");
                    Valeur=0;
                    TRAIN = AjoutLocomotive(Valeur,"Locomotive","ok",TRAIN);
 
                break;
            case 'd': AfficheTrain(TRAIN);
                break;
            case 'f': printf("Le Train contient %d wagon", NumberWagon(TRAIN));
                break;
            case 'g':
                    {
                        printf("\n Neme wagon? ");

                        scanf("%d", &N);
                        (NumberWagon(TRAIN) >= N)? (TRAIN = AjoutNemeWagon(N, Valeur, TRAIN)): printf("\n Neme wagon absent");
                        goto mainmenu;
                    }

                break;
            case 'c': printf("\n N de wagon a chercher? ");
                    scanf("%d", &val);
                    //val=1;
                    int v=rechercherElement(val,TRAIN);
                break;
            case 'e': printf("\n Supprimer le wagon en panne ");
                    supprimerPanne(TRAIN);
                break;
            case 'h':printf("\n Sortir et liberer resource ...\n\n");free(TRAIN);exit(0);
            default: printf("\n Sortir ...\n\n");
        }
    }
  
    return 0;
}
