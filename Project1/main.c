#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLENOMFICHIER 100


//Les fichiers


/* string containing a file access mode. It can be:
"r"	read: Open file for input operations. The file must exist.
"w"	write: Create an empty file for output operations. If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file.
"a"	append: Open file for output at the end of a file. Output operations always write data at the end of the file, expanding it.
            Repositioning operations (fseek, fsetpos, rewind) are ignored. The file is created if it does not exist.
"r+" read/update: Open a file for update (both for input and output). The file must exist.
"w+" write/update: Create an empty file and open it for update (both for input and output).
                    If a file with the same name already exists its contents are discarded and the file is treated as a new empty file.
"a+" append/update: Open a file for update (both for input and output) with all output operations writing data at the end of the file.
                    Repositioning operations (fseek, fsetpos, rewind) affects the next input operations, but output operations move the position back to the end of file. The file is created if it does not exist.

*/
//int saisie(char cSaisie[100], int nTaille);



int main()
{

   
    FILE* fSortie = NULL;//Descripteur de fichier
    FILE* fEntree = NULL;//Descripteur de fichier

    //Les fichiers txt
    char *cNomFichier= (char*)malloc(TAILLENOMFICHIER * sizeof(char));
    char *cSaisie= (char*)malloc(TAILLENOMFICHIER * sizeof(char));//chaine de saisie
    int nVal = 0;
    int nOccurence = 0;
    int nNombreVal = 0;
    
    errno_t err;
  
    //On �crit dans le fichier (�criture format�e)
    //Saisir le nom du fichier enregistr� sur le disque.
    printf("Donnez le nom du fichier a creer (ajoutez l'extension .txt): \n");
    scanf_s("%s", cSaisie,TAILLENOMFICHIER);

    //on copie le nom du fichier pour le path dans une variable char*, pour s�curiser le chemin
    if(cSaisie!=NULL && cNomFichier!=NULL)
        strcpy_s(cNomFichier,TAILLENOMFICHIER, cSaisie);


   
    //on s�curise les pointeurs
    if (cNomFichier != NULL) {

        //Pour ouvrir un fichier dans un mode donn�, on utilise un descripteur de fichier(celui-ci va nous aider � naviguer dans le fichier)
        //Ouverture en �criture, si le fichier n'existe pas il le cr�, attention il �crase son contenu � chaque cr�ation
        if (err = fopen_s(&fSortie, cNomFichier, "w") != 0) {

            fprintf_s(stderr, "Erreur ouverture fichier :%s\n", strerror(err));
            //Gestion des erreurs
        }
        else {



            do {
                //on �crit dans le fichier des valeurs num�riques � la vol�e.
                printf("donnez un entier : \n");
                scanf_s("%d", &nVal);//Saisie de notre entier

                if (nVal != 0) {
                    //le 0 n'est pas �crit dans le fichier
                    //fprintf_s fonction permettant d'�crire dans le fichier dans un format donn�.
                    fprintf_s(fSortie,"%d\n",nVal);//Ecriture format�e dans le fichier
                    nOccurence++;//Compte le nombre de valeurs saisies
                }
                //condition de sortie 0
            } while (nVal);


        }

    }

    if (fSortie)
        fclose(fSortie);//fermeture du descripteur de fichier

   
 
    

    //Lecture du fichier
    //On r�alise une lecture format�e
    
    //on saisie le nom du fichier � lire avec l'�xtension .txt
    printf("Donnez le nom du fichier a lister (ajoutez l'extension .txt) : \n");
    scanf_s("%s", cSaisie, TAILLENOMFICHIER);

    //on copie le nom du fichier pour le path dans une variable char*, pour s�curiser le chemin
    if (cSaisie != NULL && cNomFichier != NULL)
        strcpy_s(cNomFichier, TAILLENOMFICHIER, cSaisie);

   

    //on s�curise les pointeurs
    if (cNomFichier != NULL) {

        //Ouverture en lecture
        if (err = fopen_s(&fEntree, cNomFichier, "r") != 0) {

            fprintf_s(stderr, "Erreur ouverture fichier :%s\n", strerror(err));
            //Gestion des erreurs
        }
        else {

            //Connaissant le nombre d'occurrences dans le fichier, on lit tant que j'ai une occurrence � lire.
            while (nNombreVal < nOccurence) {

                int ret=fscanf_s(fEntree, "%d", &nVal);// lecture format�e dans le fichier, affectation de la valeur lue dans nVal, ici on lit un entier
                printf("%d", nVal);//Affichage a l'ecran de la valeur
                nNombreVal++;
            }

        }

    }

    //Apr�s manipulation du fichier
    //on ferme le descripteur de fichier
    if(fEntree)
        fclose(fEntree);//fermeture du descripteur fichier

    //on lib�re les allocations dynamiques de la m�moire pour les chaines.
      free(cSaisie);
      free(cNomFichier);


      

   

    return 0;
}




