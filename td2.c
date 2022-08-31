#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int etage_base;
    int etage_voulu;
}Personne;

typedef struct _ListePersonne {
    Personne *personne;
    struct _ListePersonne *next;
}ListePersonne;

int taille(ListePersonne *list)
{
    int res = 0;
    ListePersonne *indicateur = list;
    while (indicateur->next != NULL)
    {
        indicateur = indicateur->next;
        res ++;
    }
    return(res);
}

Personne* creer_Personne(int etage_base, int etage_voulu)
{
    Personne *personne;
    personne = malloc(sizeof(Personne));
    personne->etage_base = etage_base;
    personne->etage_voulu = etage_voulu;
    return(personne);
}

ListePersonne* ajouter(Personne *p, ListePersonne *list)
{
    ListePersonne *l;
    l = malloc(sizeof(ListePersonne));
    l->next = list;
    l->personne = p;
    return(l);
}
 
ListePersonne supprimer(ListePersonne list)
{
    ListePersonne queue;
    queue = *list.next;
    return(queue);
}

void afficher(ListePersonne liste)
{
    ListePersonne test = liste;
    printf("[");
    while (test.next != NULL)
    {
        printf("%d->%d,", test.personne->etage_base, test.personne->etage_voulu);
        test = supprimer(test);
    }
    printf("%d->%d]", test.personne->etage_base, test.personne->etage_voulu); 
}

typedef struct {
    int capacite;
    int etage_actuel;
    int prochain_etage;
    ListePersonne *cabine;
}Ascenceur;

typedef struct {
    int taille_immeuble;
    ListePersonne queue;
    Ascenceur ascenceur;
}Immeuble;
 

void changement_etage(Ascenceur asc)
{
    if (asc.etage_actuel < asc.prochain_etage)
    {
        asc.etage_actuel++;
    }
    else 
    {
        asc.etage_actuel--;
    }
}

Ascenceur *creer_ascenceur(int capacite, int etage_actuel, ListePersonne *personne)
{
    Ascenceur *asc;
    asc = malloc(sizeof(Ascenceur));
    asc->capacite = capacite;
    asc->etage_actuel = etage_actuel;
    asc->prochain_etage = personne->personne->etage_voulu;
    asc->cabine = personne;
    return (asc);
}


Immeuble *creer_immeuble(int nbetage, Ascenceur *asc, ListePersonne **liste_attente)
{
    Immeuble *im;
    im = malloc(sizeof(Immeuble));
    im->taille_immeuble = nbetage;
    im->queue = **liste_attente;
    im->ascenceur = *asc;
    return(im);
}

ListePersonne* sortie_ascenceur(Ascenceur *e)
{
    int etage = e->etage_actuel;
    ListePersonne *listet = e->cabine;
    ListePersonne *restent, *partent;
    restent = NULL;
    partent = NULL;
    Personne *p = listet->personne; 
    while (p != NULL)
    {
        if (p->etage_voulu == etage)
        {
            ajouter(p, partent);
        }
        else
        {
            ajouter(p, restent); 
        }
    }
    ListePersonne *res;
    // res = (ListePersonne*)malloc(2 * sizeof(ListePersonne));
    *res = *partent;
    *(res + 1) = *restent;
    return (res);
}


ListePersonne* enterElevator(Ascenceur *e, ListePersonne *list)
{
    int capacite = e->capacite;
    int taille_actuelle = taille(e->cabine);
    while (taille_actuelle < capacite)
    {
        ajouter(list->personne, e->cabine);
        supprimer(*list);
    }
    ListePersonne *res;
    *res = *e->cabine;
    *(res + 1) = *list;
    return(res);
}




int main()
{
    //Tests sur les ListePersonne

    //Personne *p = creer_Personne(5,8);
    //Personne *pp = creer_Personne(4,7);
    //ListePersonne *liste;
    //liste = malloc(sizeof(ListePersonne));
    //liste->personne = p;
    //liste->next = NULL;
    //liste = ajouter(pp, liste);
    //afficher(*liste);
    //afficher(*liste);
    
    //Tests sur les Ascenceur
    //Personne *p = creer_Personne(5,8);
    //Personne *pp = creer_Personne(4,7);
    //ListePersonne *liste;
    //liste = malloc(sizeof(ListePersonne));
    //liste->personne = p;
    //liste->next = NULL;
    //liste = ajouter(pp, liste);
    //Ascenceur *asc;
    //asc = malloc(sizeof(Ascenceur));
    //creer_ascenceur(5, 2, liste);
    //printf("%d,%d,%d", asc->etage_actuel, asc->prochain_etage, asc->capacite);
    //afficher(*asc->cabine);
    return(0);
}
