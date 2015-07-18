
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "pendu.h"

int main()
{
    char caract_act,lettre;
    int emplacement_du_mot=0,compteur=10;
    int k=0;
    FILE* fichier=NULL;
    FILE* alphabet=NULL;
    char mot_chr[50];
    char mot_myst[50];
    fichier=fopen("dictionnaire.txt","r+");
    alphabet=fopen("alphabet.txt","w+");
    if(fichier==NULL)
        return 0 ;

    fichier=fopen("dictionnaire.txt","r+");
    int nbr_mots=0;
    nbr_mots=nbr_mot(fichier);
    emplacement_du_mot=emplacementDuMot(fichier,(nbr_mots-1));
    fseek(fichier,emplacement_du_mot,SEEK_SET);
    fgets(mot_myst,50,fichier);
    strcpy(mot_chr,mot_myst);
        for(k=0;k<(strlen(mot_myst)-1);k++)
            {
                mot_chr[k]='-';
            }
        printf("Et si on jouait au pendu? ;)");

    while(compteur!=0 && strcmp(mot_myst,mot_chr) !=0 )
    {
        printf("\nPour l'instant,le mot mystere s'apparente a: %s \nIl vous reste %d coups restant!",mot_chr,compteur);
        printf("\nProposez une lettre...");
        lettre=lireCaractere();

        if(caract_tape(alphabet,lettre)==1)
        {
        printf("\nVous avez deja tape cette lettre,reessayez!");
        }

        else if(strchr(mot_myst,lettre)!=NULL)
        {
        printf("\nBien trouve!");
        affiche_lettre_trouve(mot_myst,mot_chr,lettre,(strlen(mot_myst)-1));
        }

        else
        {
        compteur=compteur-1;
        printf("\nRate!!");
        }

        fprintf(alphabet,"%c",lettre);

    }

        if(compteur==0)
        {
            printf("\nLe mot mystere etait %s Vous avez perdu et vous ferai defoncer la gueule !!!\n",mot_myst);
        }

        else
        {
        printf("\nBravo,le mot mystere etait %s vous ne vous etes fait arracher que %d membres,le bourreau vous \nlaisse partir !!!\n",mot_myst,10-compteur);
        }
return 0;
}


