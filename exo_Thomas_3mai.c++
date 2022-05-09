#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int checkIfInf(vector<int> param1, vector<int> param2, int *count_param1, int *count_param2);
int main();
int tri(vector<int> param1, vector<int> param2);
int checkTheBiggest(vector<int> param1, vector<int> param2);
int tri_insertion(vector<int>*param1, vector<int> conteneur_param1, int it, int temp, int count, int index, int forit);
int fonction_recursive(int index, int *valeur, vector<int> param2, vector<int>*param1);

//===============================================//
int fonction_recursive(int index, int *valeur, vector<int> param2, vector<int>*param1) {
    // int *ibis;
    // ibis = &i;
    // int *value;
    // value=&valeur;
    //int new_index=*index+1;
    // new_index=&index;
    int value_fonction, i=0;
    for (i=0; i<(*param1).size();i++) {
        if (*valeur+(*param1)[i]==param2[0]) {
            (*param1).erase((*param1).begin()+i-1);
            return *valeur=*valeur+(*param1)[i];
        }
    }
    index++;
    int new_param1=(*param1)[index];
    *valeur=*valeur+new_param1;
    //new_value=*valeur+new_param1;
    value_fonction=fonction_recursive(index, valeur, param2, param1);
    return value_fonction;
}

//===============================================//
int tri_insertion(vector<int>*param1, vector<int> conteneur_param1, int it, int temp, int count, int index, int forit) {
    for (it =1; it<(*param1).size();it++ ) {

        temp=(*param1)[it];
        count=it-1;

        do {
            index=false;
            if ((*param1)[count]<temp){
                (*param1)[count+1]=(*param1)[count];
                count--;
                index=true;
            }
            if (count<0) index=false;
        }

        while(index);
        (*param1)[count+1]=temp;
    }

    for (forit=0; forit<(*param1).size(); forit++) {
        cout << (*param1)[forit] << ",";
    }
    cout << endl;

    for (forit=0; forit<conteneur_param1.size(); forit++) {
        cout << conteneur_param1[forit] << ",";
    }
    cout << endl;
    return 1;
}

//===============================================//
int checkTheBiggest(vector<int> param1, vector<int> param2) {
    if (param1[0]>param2[0]) {
        return 0;
    }
    return 1;

}


//===============================================//
int checkIfInf(vector<int> param1, vector<int> param2, int *count_param1, int *count_param2) {
    int i = 0;
    // int *ibis;
    // ibis = &i;
    *count_param1=0;
    *count_param2=0;
    cout << "tableau 1 : ";
    for (i = 0; i<param1.size(); i++){
        (*count_param1) = (*count_param1) + param1[i];
        cout << param1[i] << ", ";
    }
    i=0;
    cout << endl;
    cout << "tableau 2 : ";
    for (i = 0; i<param2.size(); i++){
        (*count_param2) = (*count_param2) + param2[i];
        cout << param2[i] << ", ";
    }
    cout << endl;

    if ((*count_param1) > (*count_param2)) {
        return 0;
    } else if ((*count_param1)==(*count_param2)) {
        return 1;
    }
    return 2;
}


//===============================================//
int tri(vector<int> param1, vector<int> param2) {

    int it, temp, count, index, forit, equal, count_param1, count_param2;
    int check=checkIfInf(param1, param2, &count_param1, &count_param2);

    if (check==0) {
        cout << "Le total de la liste des éléments NE PEUT ÊTRE contenu dans le conteneur." << endl;
        return 0;
    } else if (check==2) {
        cout << "Le total de la liste des éléments peut être contenu dans le conteneur." << endl;
    } else if (check==1) {
        cout << "Le total de la liste des éléments EST STRICTEMENT ÉGALE et peut être contenu dans le conteneur." << endl;
        equal=1;
    }

    int size_param2 = param2.size();
    vector<int> conteneur_param2(size_param2);

    int size_param1 = param1.size();
    cout << "size_param1 initialisation =" << size_param1 << endl;
    vector<int> conteneur_param1(size_param1);
    conteneur_param1=param1;
    // dans le cas d'un conteneur a taille fixe :
    // regarder le nombre le plus grand dans param1 et le comparer au nombre le plus grand dans param2
    // si le nb de param1 esst plus élevé que le nb de param2 alors on ne peut trier le tableau
    // si on peut , on trie le param1 du plus gand au plus petit
    // une fois le premier ( ou les premiers de la meme valeur ) placé dans le conteneur
    // on regarde si on peut retrouver la meme valeur que l'index -1 en additionnant les valeurs qui reste,
    // des que l'on a la meme valeur on les mets dans l'index et on les supprimes.
    // si on ne peut pas retrouver la meme valeur alors on place le plus grand suivant et on réitere le processus pour le prochain.
    //===============================================

    tri_insertion(&param1, conteneur_param1, it, temp, count, index, forit);

    if (checkTheBiggest(param1, param2)==0) {
        cout << "La liste contient un entier trop grand le conteneur NE PEUT PAS contenir cette élément" << endl;
        return 0;
    } else cout << "Le conteneur peut contenir le plus gros élément de la liste" << endl;

    it=0, temp=0, count=0, index=0, forit =0;
    int it_inverse=size_param1-1;
    cout << "it_inverse initialisation = " << it_inverse << endl;
    cout << "param1[it_inverse] initialisation = " << param1[it_inverse] << endl;
    int diff, median, it_erase=0;
    int biggest=param1[0];

    //cout << "longueur param1 : " << param1.size() << endl;
    //cout << "longueur conteneur : " << conteneur_param2.size() << endl;
    cout << "les variables sont remises a zéro : " << it << "; " << temp << "; " << count << "; " << index << "; " << forit << "; " << endl;
    for (forit=0; forit<param1.size(); forit++) {
        cout << param1[forit] << ",";
    }
    cout << endl;

    if (equal==2) {
        median=count_param2/biggest;
        cout << "count_param2 : " << count_param2 << " // biggest : " << biggest << " // la median est de : " << median << endl;
    } else if (equal==1) {
        for (forit=0; forit<conteneur_param2.size(); forit++) {
            cout << conteneur_param2[forit] << ",";
        }
        cout << endl;

        cout << "le tableau param2 est egal à : ";
        for (forit=0; forit<param2.size(); forit++) {
            cout << param2[forit] << ",";
        }
        cout << endl;

        conteneur_param2[0]=biggest;
        for (it=0; it<conteneur_param1.size();it++) {
            if (conteneur_param2[it]==0) {
                conteneur_param2[it]=param1[it-it_erase];
                param1.erase(param1.begin());
                it_erase++;
            }
            if (conteneur_param2[it]<param2[it]) {
                //cout << "conteneur_param2[it]+param1[it_inverse] =  " << conteneur_param2[it]+param1[it_inverse] << endl;
                //cout << "conteneur_param2[it] =  " << conteneur_param2[it] << endl;
                //cout << "it = " << it << endl;
                if (conteneur_param2[it]+param1[it_inverse]==param2[0]) {
                    conteneur_param2[it]=conteneur_param2[it]+param1[it_inverse];
                    //cout << "param1[it_inverse] = " << param1[it_inverse] << endl;
                    param1.erase(param1.begin()+it_inverse);
                    param1.erase(param1.begin());
                    it_erase++;
                } 
                if (conteneur_param2[it+1]+param1[it_inverse]!=param2[0]) {
                    int i=0, somme=0, int_inverse=param1.size();
                    if (conteneur_param2[it+1]==0) {
                        conteneur_param2[it+1]=param1[it+1-it_erase];
                        cout << "dans le if conteneur_param2[it+1] = " << conteneur_param2[it+1] << endl;
                        param1.erase(param1.begin());
                        it_erase++;
                    }
                    somme=conteneur_param2[it+1]+param1[it];
                    cout << "conteneur_param2[it+1] = " << conteneur_param2[it+1] << endl;
                    cout << "param1[it] = " << param1[it] << endl;
                    cout << "somme = " << somme << endl;
                    for (i=it; i<param1.size();i++) {
                        cout << "i = " << i << endl;
                        cout << "it_inverse = " << it_inverse << endl;
                        cout << "param1[it_inverse] = " << param1[it_inverse] << endl;
                        if (somme+param1[it_inverse]==param2[0]) {
                            somme=somme+param1[it_inverse];
                            //cout << "param1[it_inverse] = "
                            cout << "somme dans le for = " << somme << endl;
                            conteneur_param2[it+1]=somme;
                            param1.erase(param1.begin()+it);
                            //cout << "it_inverse = " << it_inverse << endl;
                            cout << "param1[it_inverse] = " << param1[it_inverse] << endl;
                            cout << "it_erase = " << it_erase << endl;
                            param1.erase(param1.begin()+it_inverse-it_erase-2);
                            it_inverse--;
                        }
                        fonction_recursive(index, &conteneur_param2[it+1], param2, &param1);
                    }
                }
                else it_inverse--;
            } 
            // else if (conteneur_param2[it]==param2[it]) {
            //     conteneur_param2[it]=param1[it];
            //     param1.erase(param1.begin()+(it-1));
            // }


            //cout << "it_inverse = " << it_inverse << endl;
        }
        forit=0;
        for (forit=0; forit<conteneur_param2.size(); forit++) {
            cout << conteneur_param2[forit] << ",";
        }
        cout << endl;

        forit=0;
        for (forit=0; forit<param1.size(); forit++) {
            cout << param1[forit] << ",";
        }
        cout << endl;
    }

    // for (it=0; it<size_param1;it++) {
    //     if (conteneur_param2[it]<0) {
    //         conteneur_param2[it]=param1[index];
    //     }
    //     else if (conteneur_param2[it]<biggest) { //voir pour le cas de zero
    //         diff = biggest - conteneur_param2[it];
    //         int itfor=index;
    //         for (itfor=index; conteneur_param2[it]<param1[index]; itfor++) {
    //             if (diff==biggest) {

    //             }
    //         }
    //     }
    //     index++;
    // }
    return 0;
}

        // if (param1[it]>param1[it+1]) {
            
        // }
        // if (param1[it]==param1[it+1]) {
        //     conteneur_param2[it+1]=param1[it+1];
        //     param1[it+1]=temp;
        //     index++;
        // }
        // if (param1[it]<param1[it+1]) {
        //     conteneur_param2[index]=param1[it+1];
        //     param1[it+1]=temp;
        //     //index=it;
        // }
        // for (forit=0; forit<conteneur_param2.size(); forit++) {
        //     cout << conteneur_param2[forit] << ",";
        // }
        // cout << endl;
        // cout << "temp est égal à : "<< temp << endl;
        // }



    // dans le cas d'un conteneur a taille variable :
    // regarder le nombre le plus grand dans param1 et le comparer au nombre le plus grand dans param2
    // si le nb de param1 esst plus élevé que le nb de param2 alors on ne peut trier le tableau
    // trier par nombre décroissant les deux listes,
    // ranger le plus grand de param1 dans le plus grand de param2 ou un nb egal a lui ( a voir )
    // et ainsi desuite.
    //===============================================

    // if valid == 1 alors on commence le tri 
    // sinon (valid == 0) on return error pas assez de place pour ranger la liste param1 dans la liste param2

    // on fait créer un tableau avec dedans des variables dans lesquelles on malloc autant que demandé,
    // répéter pour chaque éléments dans le tableau

    //
//     return 0;
// }


//===============================================//
//===============================================//
int main() {
    vector<int> param1({5, 4, 1, 9, 1, 2, 2, 3, 3});
    vector<int> param2({10, 10, 10});
    // -------
    // vector<int> tab(4);
    // tab[0]=12; 
    // tab[1]= 42; 
    // tab[2]= 72; 
    // cout<<"la taille du tab :" << tab.size() << endl;
    //--------

    tri(param1, param2);
    return 0;
}