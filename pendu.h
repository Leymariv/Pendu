#ifndef PENDU_H_INCLUDED
#define PENDU_H_INCLUDED

int compteur_de_lettre(char *chaine)
{
    int nbr_car=0;
    nbr_car=strlen(chaine);
    return nbr_car;
}

char* init(char *chaine,int taille)
{
int k=0;

    for(k=0;k<(taille);k++)
    {
        chaine[k]='-';
    }

return chaine;
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'à l'\n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu

}

 void affiche_lettre_trouve(char *mot_mystere,char *mot_cherche,char lettre_tapee,int taille)
{
int k=0;

    for(k=0;k<taille;k++)
    {
        if(mot_mystere[k]==lettre_tapee)
        {
            mot_cherche[k]=mot_mystere[k];
        }

    }

}

int nbr_mot(FILE* fichier)
{
int k=0;
char caract_act=0;
caract_act=fgetc(fichier);

while(caract_act!=EOF)
{
    if(caract_act=='\n')
    {
        k=k+1;
    }
    caract_act=fgetc(fichier);
}

return k;

}


int emplacementDuMot(FILE* fichier,int b)
{
    char mot_pioche[]="";
    int numero_mot=0;
    int p=0,compteur=0;
    char caract_act=0;
    srand(time(NULL));
    numero_mot=(rand() % (b - 0 + 1)) + 0;
    fseek(fichier,0,SEEK_SET);
    caract_act=fgetc(fichier);
    while(numero_mot!=p && caract_act!=EOF)
{
    if(caract_act=='\n')
    {

        p=p+1;
    }

    caract_act=fgetc(fichier);
}
fseek(fichier,-1,SEEK_CUR);
compteur=ftell(fichier);

return compteur;
}

int caract_tape(FILE* alphabet,char lettre)

{   char caract_act;
    int test=0;
    fseek(alphabet,0,SEEK_SET);
    caract_act=fgetc(alphabet);
        while(caract_act!=EOF)
        {
            if(caract_act==lettre)
            {
                test=1;
            }

        caract_act=fgetc(alphabet);
        }
    return test;
}


#endif // PENDU_H_INCLUDED

