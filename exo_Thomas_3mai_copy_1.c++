#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main();
int checkIfInf(vector<int> param1, vector<int> param2);
int tri(vector<int> param1, vector<int> param2);
int tri_insertion(vector<int>*param1, vector<int> conteneur_param1, int it, int temp, int count, int index, int forit);
int checkTheBiggest(vector<int> param1, vector<int> param2);
int fonction_recursive(int index, int *valeur, vector<int> param2, vector<int>*param1, vector<int> copy_param1);

//===============================================//
int fonction_recursive(int index, int *valeur, vector<int> param2, vector<int>*param1, vector<int> copy_param1) {
    int value_fonction, i=0, i_erase=0;

    if (*valeur+(*param1)[index+1]<param2[0]) {
        for (i=1; i<((*param1).size()+i_erase);i++) {
            // if (i>=(*param1).size()+i_erase) {
            //     cout << "i = " << i << endl;
            //     return 0;
            //     //return quelquechose a changer

            //     /*  
            //         copy_param1.size()

            //                |-> i = 4 
            //         |_|_|_|_|

            //         (*param1).size()
            //                 |-> i = 4 -> Segfault
            //         |_|_|_|

            //     */
            // }
            if (*valeur+(*param1)[index+i]==param2[0]) {
                *valeur=*valeur+(*param1)[index+i];
                (*param1).erase((*param1).begin()+index);
                i_erase++;
                index++;
                cout << "dans le for *valeur = " << *valeur << endl;
                return *valeur;
            }
        }
    } 
    if (*valeur+(*param1)[index+i]==param2[0]) {
        *valeur=*valeur+(*param1)[index+i];
        (*param1).erase((*param1).begin()+index);
        i_erase++;
        index++;
        cout << "dans le for *valeur = " << *valeur << endl;
        return *valeur;
    }
    // else if (*valeur+(*param1)[index+1]>param2[0]) {

    // }
    if (i==(*param1).size()) {
        //index++;
        cout << "index = " << index << endl;
        int new_param1=(*param1)[index];
        *valeur=*valeur+new_param1;
        //cout << "*valeur = " << *valeur << endl;
        //new_value=*valeur+new_param1;
        value_fonction=fonction_recursive(index, valeur, param2, param1, copy_param1);
        return value_fonction;
    }
    return 0;
}

//===============================================//
int checkIfInf(vector<int> param1, vector<int> param2) {
    int i = 0;
    // int *ibis;
    // ibis = &i;
    int count_param1 = 0;
    int count_param2 = 0;
    cout << "tableau 1 : ";
    for (i = 0; i<param1.size(); i++){
        count_param1 = count_param1 + param1[i];
        cout << param1[i] << ", ";
    }
    i=0;
    cout << endl;
    cout << "tableau 2 : ";
    for (i = 0; i<param2.size(); i++){
        count_param2 = count_param2 + param2[i];
        cout << param2[i] << ", ";
    }
    cout << endl;

    if (count_param1 > count_param2) {
        return 0;
    } else if (count_param1==count_param2) {
        return 1;
    }
    return 2;
}

//===============================================//
int checkTheBiggest(vector<int> param1, vector<int> param2) {
    if (param1[0]>param2[0]) {
        return 0;
    }
    return 1;

}

//===============================================//
int tri(vector<int> param1, vector<int> param2) {

    int it, temp, count, index, forit, equal;
    int check=checkIfInf(param1, param2);

    if (check==0) {
        std::cout << "Le total de la liste des éléments NE PEUT ÊTRE contenu dans le conteneur." << endl;
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
    vector<int> conteneur_param1(size_param1);
    conteneur_param1=param1;

    tri_insertion(&param1, conteneur_param1, it, temp, count, index, forit);
    vector<int> copy_param1(param1.size());
    copy_param1=param1;

    if (checkTheBiggest(param1, param2)==0) {
        cout << "La liste contient un entier trop grand le conteneur NE PEUT PAS contenir cette élément" << endl;
        return 0;
    } else cout << "Le conteneur peut contenir le plus gros élément de la liste" << endl;

    it=0, temp=0, count=0, index=0, forit =0;
    // voir pour enlever le -1
    int it_inverse=size_param1-1; 
    cout << "it_inverse initialisation = " << it_inverse << endl;
    cout << "param1[it_inverse] initialisation = " << param1[it_inverse] << endl;
    int diff, median, it_erase=0;
    int biggest=param1[0];

    if (equal==2) {
        // median=count_param2/biggest;
        //cout << "count_param2 : " << count_param2 << " // biggest : " << biggest << " // la median est de : " << median << endl;
    cout << "mettre en place un systeme de median" << endl;
    } 
    else if (equal==1) {
        cout << "le tableau conteneur_param2 est egal à : ";
        for (forit=0; forit<conteneur_param2.size(); forit++) {
            cout << conteneur_param2[forit] << ",";
        }
        cout << endl;

        cout << "le tableau param2 est egal à : ";
        for (forit=0; forit<param2.size(); forit++) {
            cout << param2[forit] << ",";
        }
        cout << endl;

        // on commence deja par donné la premiere valeur a la premiere case
        conteneur_param2[0]=biggest;
        for (it=0; it<param2[0];it++) {
            if (conteneur_param2[it]<param2[0]) {
                fonction_recursive(it, &conteneur_param2[it], param2, &param1, copy_param1);
            }
        }
    }

    cout << "le tableau param1 est egal à : ";
    for (forit=0; forit<param1.size(); forit++) {
        cout << param1[forit] << ",";
    }
    cout << endl;

    cout << "le tableau conteneur_param2 est egal à : ";
    for (forit=0; forit<conteneur_param2.size(); forit++) {
        cout << conteneur_param2[forit] << ",";
    }
    cout << endl;

    return 0;
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

    cout << "param1 est egal à : ";
    for (forit=0; forit<(*param1).size(); forit++) {
        cout << (*param1)[forit] << ",";
    }
    cout << endl;

    cout << "conteneur_param1 est egal à : ";
    for (forit=0; forit<conteneur_param1.size(); forit++) {
        cout << conteneur_param1[forit] << ",";
    }
    cout << endl;
    return 1;
}

//===============================================//
//===============================================//
int main() {
    vector<int> param1({5, 4, 1, 9, 1, 2, 2, 3, 3});
    vector<int> param2({10, 10, 10});

    tri(param1, param2);
    return 0;
}