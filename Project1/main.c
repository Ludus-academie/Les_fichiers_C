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
   
    errno_t err;
  
    int nMap[5][5] = { {0,0,0,0,0},
                       {0,0,0,0,0},
                       {1,1,1,1,1},
                       {2,2,2,2,2},
                       {3,3,3,3,3} };

    //Les fichiers txt
    //Dans cet exemple, nous allons �crire la r�pr�sentation d'une map qui pourra �tre utilis� pour mod�le de donn�es � la construction d'un map pour notre jeu SDL2


    //Ecriture d'une map dans un fichier txt
    //Ouverture en ecriture
    //pour manipuler un fichier nous utilisons un descripteur de fichier, celui-ci nous aide � naviguer dans le fichier
    if (err = fopen_s(&fSortie, "map.txt", "w") != 0) {

        fprintf_s(stderr, "Erreur ouverture fichier :%d\n", err);
        //Gestion des erreurs
    }
    else {

        int i, j;
        //On �crit dans le fichier de mani�re format�e avec fprintf_s
        //le format est compos� de s�quences avec { et } et de s�parateurs avec ,
        fprintf_s(fSortie, "{");
        for (i = 0; i < 5; i++) {

            for (j = 0; j < 5; j++) {
                fprintf_s(fSortie, "%d", nMap[i][j]);
                fprintf_s(fSortie, ",");
            }
            if (i < 4)
                fprintf_s(fSortie, "\n");
        }
        fprintf_s(fSortie, "}");
    }


    //apr�s utilisation du fichier on ferme le descripteur de fichier
    if (fSortie)
        fclose(fSortie);//fermeture du descripteur de fichier


    //lecture map du fichier
    // 
     //Ouverture en lecture
    if (err = fopen_s(&fEntree, "map.txt", "r") != 0) {

        fprintf_s(stderr, "Erreur ouverture fichier :%d\n", err);
        //Gestion des erreurs
    }
    else {


        int nVal[25];
        char sec1, sec2;
        char sep;

        //la lecture format�e est r�alis�e avec la fonction fscanf_s
        //Cette fonctions permet de lire dans un fichier en fonction d'un format (int %d,char %c....)
        fscanf_s(fEntree, "%c", &sec1,1);//// lecture format�e dans le fichier, affectation de l'op�rateur de s�quence
        for (int i = 0; i < 25; i++) {
            fscanf_s(fEntree, "%d", &nVal[i]);// lecture format�e dans le fichier, affectation de la valeur dans nVal
            fscanf_s(fEntree, "%c", &sep,1);// lecture format�e dans le fichier, affectation du s�parateur dans sep
        }
        fscanf_s(fEntree, "%c", &sec2,1);// lecture format�e dans le fichier, affectation de l'op�rateur de s�quence

        //Algo pour l'affichage � l'�cran de la r�pr�sentation en donn�es de la map
        //On copie le tableau de val (nVal) dans le tableau 2d map
        //le tableau map correspond � la repr�sentation de la map qui sera utilis�e pour la cr�ation de la map.
        int map[5][5];
        int c = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                map[i][j] = nVal[c];
                c++;

            }

        }

        //on affiche la map format� dans la console 
        printf("%c", sec1);
        printf("\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d", map[i][j]);//Affichage a l'ecran de la valeur
                printf("%c", sep);
            }
            printf("\n");
        }
        printf("%c", sec2);





    }

    //apr�s utilisaion du fichier, on ferme le descripteur de fichier
    if (fEntree)
        fclose(fEntree);//fermeture du descripteur fichier


      

   

    return 0;
}




