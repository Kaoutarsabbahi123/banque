#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<windows.h>
#include<conio.h>
#include <unistd.h>
using namespace std;
class compte{
private :
    unsigned int num;
    double solde ;
    char nom[20];
    char prenom[20];
    unsigned int code;
public :
    void ajouter();
    void afficher();
    void debiter(unsigned int );
    void deposer(unsigned int );
    void modifier();
    bool login(unsigned int,unsigned int );
    void affichercompte();
    void supprimer();
    bool existe(unsigned int );
    void affichersolde(unsigned int );
    void virverser();
};

int menuguichet()
{
	 system("cls");
	 int choix;
     cout << "\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GESTION DU GUICHET \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n" << endl;
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 1. deposer un montant.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 2. debiter du compte.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 3. voir le solde.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 4. retourner au menu.\n\n";
     cout<<"\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
     cout<<"\t\t\t\t\t    -----------------------------"<<endl;
     cout<<"\t\t\t\t\t          Choisir :[1/2/3]"<<endl;
     cout<<"\t\t\t\t\t    -----------------------------\n\n"<<endl;
     do
     {
         cout<<"\t\tEntrer votre choix :";
         cin>>choix;
         if(choix<1 ||choix >4)
            cout<<"\t\t\t N'EXISTE PAS."<<endl;
     }while(choix<1 ||choix >4);
     return choix;
}
void menu ()
{
     unsigned int choix ,choix2, n,c;
     compte cmp;
     string reponse;
     system("cls");
     cout << "\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GESTION D'UNE BANQUE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n" << endl;
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 1. ouvrir une compte. \n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 2. guichet.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 3. info sur un compte.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 4. info de tous les comptes.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 5. modifier les infos d'un compte.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 6. supprimer un compte.\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 7. verser du compte a un autre .\n\n";
     cout<<"\t\t\t\t\xDB\xDB\xDB\xDB\xB2 8. Quitter le programme.\n\n";
     cout<<"\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
     cout<<"\t\t\t\t\t    -----------------------------"<<endl;
     cout<<"\t\t\t\t\t       Choisir :[1/2/3/4/5/6/7/8]"<<endl;
     cout<<"\t\t\t\t\t    -----------------------------\n\n"<<endl;
     do
     {
         cout<<"\t\tEntrer votre choix :";
         cin>>choix;
         if(choix<1 ||choix >8)
            cout<<"\t\t\t N'EXISTE PAS."<<endl;
     }while(choix<1 ||choix >8);
     do{
   switch(choix)
   {
   case 1:{cmp.ajouter();
       break;}
   case 2:{
            system("cls");
            cout<<"\n\n\t\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 LOGIN ";
            cout<<"\n\n\t\t\t\t  Veuillez saisir votre numero de compte :";
            cin>>n;
            cout<<"\n\t\t\t\t  Veuillez saisir votre code :";
            cin>>c;
            if(cmp.login(n,c)){
            choix2=menuguichet();
             switch(choix2){
             case 1:{cmp.deposer(n);
                break;}
             case 2:{cmp.debiter(n);
                break;}
             case 3:{cmp.affichersolde(n);
                break;}
             case 4:{  menu();
                break;}
             }
            }
            else
            {
                cout<<"\n\t\t\t\t  votre informations est incorrecte."<<endl;
                cout<<"\n\t\t\t\t  Est ce que vous voulez continuer ?(O/N):";
                cin>>reponse;
                if(reponse=="O"|| reponse=="o")
                {
                    system("cls");
                    menu();
                }
              else if(reponse =="N" || reponse =="n")exit(0);
       break;}}
   case 3:{cmp.affichercompte();
       break;}
   case 4:{cmp.afficher();
       break;}
   case 5:{cmp.modifier();
       break;}
   case 6:{cmp.supprimer();
       break;}
   case 7:{cmp.virverser(); break;}
   case 8:{
       system("cls");
       cout<<"\n\n\n\t\t\t\t-------------------------------------";
       cout<<"\n\n\t\t\t\tFIN PRORAMME,MERCI POUR VOTRE VISITE.";
       cout<<"\n\n\t\t\t\t-------------------------------------"<<endl;
       exit(0);}}
   }while(choix!=7);


}


void compte::ajouter()
{
    system("cls");
    fstream file;
    int n;
    file.open("record.txt",ios::app | ios::out );
    string reponse ;
    cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 OUVRIR UN COMPTE ";
    cout<<"\n\n\n\t\t\t\tNumero de compte :";
    if(cin>>n){
    if(existe(n))
    {
        cout<<"\n\t\t\t\tle numero de compte existe .";
        cout<<"\n\n\t\t\t\tveuillez saisir une autre numero  :";
        cin>>n;
    }
    }
    num=n;
    cout<<"\n\t\t\t\tNom:";
    fflush(stdin);
    cin.getline(nom,20);
    cout<<"\n\t\t\t\tPrenom :";
    cin.getline(prenom,20);
    cout<<"\n\t\t\t\tCode :";
    cin>>code;
    cout<<"\n\t\t\t\tSolde :";
    cin>>solde;
    file<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
    file.close();
    do {
    cout<<"\n\t\t\t Est ce que vous voulez ouvrir un autre compte ? (O/N):";
    cin>>reponse;
    if(reponse=="N" || reponse=="n")
        menu();
    else if(reponse=="O"|| reponse =="o") {  system("cls");
            ajouter();
    }
    }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");
}

void compte ::deposer( unsigned int n)
{
    system("cls");
    bool trouve;
    cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 DEPOSER UN MONTANT";
    fstream file ,file1;
    string reponse;
    double mt;
    file1.open("record2.txt", ios::app | ios::out);
    file.open("record.txt",ios::in);
        while (file >> nom >>prenom>> num >> code >> solde)
        {

            if (n == num){
                cout<<"\n\n\t\t\t\t Entrer le montant que vous voulez deposer :";
                cin>>mt;
                solde+=mt;
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";

            }
            else
            {
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";

            }
        }
        file1.close();
        file.close();
        remove("record.txt");
        rename("record2.txt", "record.txt");
        do{
        cout<<"\n\t\t\t\t Est ce que vous voulez deposer une autre montant(O/N)?";
        cin>>reponse;
        if(reponse=="N" || reponse =="n")
            menu();
        else if (reponse =="O" || reponse =="o") {
            system("cls");
            deposer(n);}
        }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");
}

void compte::debiter( unsigned int n)
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 DEBITER UNE MONTANT ";
    fstream file ,file1;
    string reponse;
    double mt;
    file1.open("record2.txt", ios::app | ios::out);
    file.open("record.txt",ios::in);
        while (file >> nom >>prenom>> num >> code >> solde)
        {
            if (n != num){
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
            }
            else
            {
                cout<<"\n\n\t\t\t\tEntrer le montant que vous voulez debiter :";
                cin>>mt;
                if(solde>=mt){
                solde-=mt;
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
                }
                else{ cout<<" \n\n\t\t\t\tvotre solde est insuffisant ."<<endl;
                      file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
                }}
        }
        file1.close();
        file.close();
        remove("record.txt");
        rename("record2.txt", "record.txt");
        do{
        cout<<"\n\n\t\t\t\tEst ce que vous voulez debiter une autre montant(O/N)?";
        cin>>reponse;
        if(reponse=="N" || reponse =="n")
            menu();
        else if(reponse =="O"|| reponse =="o") {
            system("cls");
            debiter(n);}
        }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");

}
void compte::afficher()
{
    system("cls");
    cout<<"\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 LISTE DES COMPTES";
    fstream file;
    int total = 0;
    string reponse;
    file.open("record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t n'existe aucun information.......";
        file.close();
    }
    else
    {
        while (file >> nom>> prenom >> num >> code >> solde)
        {
            cout << "\n\t\t\t Compte No: " << ++total ;
            cout << "\n\t\t\t Nom: " << nom ;
            cout << "\n\t\t\t Prenom: " << prenom ;
            cout << "\n\t\t\t Numero : " << num ;
            cout << "\n\t\t\t code: " << code ;
            cout << "\n\t\t\t solde:"<<solde<<" DH";
            cout<<"\n\n";
        }

    }
    file.close();
    sleep(1);
    system("cls");
    menu();

}
void compte::modifier(){
    system("cls");
     cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 MODIFICATION D'UN COMPTE";
    fstream file, file1;
    string reponse ;
    int n;
    int trouver = 0;
    file.open("record.txt", ios::in);
    if (!file)
        cout << "\n\t\t\t aucun information..";
    else
    {
        cout << "\n\n\t\t\t\t Entrer le numero du compte que vous voulez modifier : ";
        cin >> n;
        file1.open("record2.txt", ios::app | ios::out);
        while (file >> nom >>prenom>> num >> code >> solde)
        {
            if (n != num)

               file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
            else
            {
                cout << "\n\t\t\t\t nom: ";
                cin >> nom;
                cout<<"\n\t\t\t\t prenom:";
                cin>>prenom;
                cout << "\n\t\t\t\t numero: ";
                cin >> num;
                cout << "\n\t\t\t\t code: ";
                cin >> code;
                cout << "\n\t\t\t\t solde: ";
                cin >> solde;
                trouver=1;
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n"; }}
        if(trouver ==0)
            cout<<" \n\t\t\t\t Le compte n'existe pas ."<<endl;
        file1.close();
        file.close();
        remove("record.txt");
        rename("record2.txt", "record.txt"); }
        do {
        cout<<"\n\n\t\t\t\t Est ce que vous voulez modifier une autre compte(O/N)?";
        cin>>reponse;
        if(reponse=="N" || reponse=="n")
            menu();
        else if(reponse =="O" || reponse =="o") {
            system("cls");
            modifier();
        }
        }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");
}
void compte::affichercompte(){
    system("cls");
    cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 LES DONNEES D'UN COMPTE";
    fstream file;
    string reponse;
    int trouver =0;
    file.open("record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t aucun information...";
    }
    else
    {
        int n;
        cout << "\n\n\t\t\t\t Entrer le numero du compte que vous voulez chercher: ";
        cin >> n;
        while (file >> nom >>prenom >> num >> code >> solde)
        {
            if (n == num)
            {
            cout << "\n\t\t\t Nom: " << nom << endl;
            cout << "\n\t\t\t Prenom: " << prenom << endl;
            cout << "\n\t\t\t Numero : " << num << endl;
            cout << "\n\t\t\t code: " << code << endl;
            cout << "\n\t\t\t solde:"<<solde<<" DH"<<endl;
            trouver=1;
            }}
        file.close();
    }
        if(trouver==0)
            cout<<"\n\t\t\t\t Le compte n'existe pas .";
        do{
        cout<<"\n\n\t\t\t Est ce que vous voulez afficher une autre compte(O/N)?";
        cin>>reponse;
        if(reponse=="N" || reponse =="n")
            menu();
        else if(reponse=="O" || reponse=="o"){
            system("cls");
            affichercompte();}
        }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");
}
bool  compte ::existe(unsigned int n)
{
    fstream file;
    int trouver=0 ;
    file.open("record.txt", ios::in);

        while (file >> nom >>prenom >> num >> code >> solde)
        {
            if (n == num)
            {
                trouver =1;
            }
        }
        file.close();
        return trouver ==1;
}
bool compte ::login(unsigned int n ,unsigned int c)
{
    bool trouver=false;
    fstream file;
    file.open("record.txt", ios::in);
        while (file >> nom >>prenom >> num >> code >> solde )
        {
            if (n == num && c==code)
            {
                return true;
            }
        }
         file.close();
        return false;

}
void compte::supprimer()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 SUPPRERION D'UNE COMPTE ";
    fstream file, file1;
    string reponse;
    int trouver =0;
    unsigned int n;
    file.open("record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t aucun information..";
        file.close();
    }
    else
    {
        cout << "\n\n\t\t\t\t Entrer le numero du compte que vous voulez supprimer : ";
        cin >> n;
        file1.open("record2.txt", ios::app | ios::out);
        while (file >> nom >>prenom >>num >> code >> solde)
        {
            if (n != num)
            {
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";

            }
            else
            {
                cout << "\n\t\t\t\t le compte est supprime.";
                 trouver=1;
            }
        }
        file1.close();
        file.close();
        remove("record.txt");
        rename("record2.txt", "record.txt");
        if(trouver==0)
            cout<<"\n\n\t\t\t\t Le compte n'existe pas ."<<endl;
    }
        do{
        cout<<"\n\n\t\t\t\tEst ce que vous voulez supprimer une autre compte(O/N)?";
        cin>>reponse;
        if(reponse=="N" || reponse =="n")
            menu();
        else if(reponse =="O" || reponse =="o") {
            system("cls");
            supprimer();
        }
        }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");
}
void compte::affichersolde(unsigned int n)
{
    system("cls");
    fstream file;
    string reponse;
    file.open("record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t aucun information...";
    }
    else
    {
         cout<<"\n\n\t\t\t\t    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SOLDE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        file >> nom >>prenom >> num >> code >> solde;
        while (!file.eof())
        {
            if (n == num)
            {
            cout << "\n\n\t\t\t\t votre solde est :"<<solde<<" DH"<<endl;
            }
            file >> nom>>prenom >> num >> code >> solde;
        }

        file.close();
    }
    do{
    cout<<"\n\t\t\t\t Est ce que vous voulez continuer ?(O/N):";
    cin>>reponse;
    if(reponse=="O" || reponse =="o"){
       menuguichet();
    }
    else if(reponse =="N" || reponse =="n") menu();
    }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");
}
void compte :: virverser()
{
    system("cls");
    fstream file, file1,file2 ;
    double mt;
    int n1,n;
    cout<<"\n\n\t\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xB2 VERSER UN MONTANT ";
    cout<<"\n\n\n\t\t\t\tEntrer votre Numero du compte :";
    cin>>n;
    cout<<"\n\n\t\t\t\tEntrez le Num de compte que vous voulez transferer du solde :";
    cin>>n1;
    if(existe(n1) && existe(n)){
    file.open("record.txt",ios::in );
    file1.open("record2.txt",ios::out | ios::app);
    cout<<"\n\n\t\t\t\tEntrer le solde  que vous voulez verser :";
    cin>>mt;
    bool suffisant=false ;
    while (file >> nom >>prenom>> num >> code >> solde)
        {
            if (n != num){
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
            }
            else
            {
                if(solde>=mt){
                solde-=mt;
                file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
                }
                else{ file1<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
                        cout<<" \n\n\t\t\t\tvotre solde est insuffisant ."<<endl;
                        suffisant =true;}
                        }
        }
        file1.close();
        file.close();
        remove("record.txt");
        rename("record2.txt", "record.txt");
        if(!suffisant){
        file1.open("record.txt",ios ::in);
        file2.open("record3.txt",ios::out|ios::app);
         while (file1 >> nom >>prenom>> num >> code >> solde)
        {
            if (n1 == num){
                solde+=mt;
                file2<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";
            }
            else
            {
                file2<<" " <<nom<<" "<<prenom<<" "<<num<<" "<<code<<" "<<solde<<"\n";

            }
       }
        file2.close();
        file1.close();
        remove("record.txt");
        rename("record3.txt", "record.txt");}
    }
        else cout<<"\n\n\t\t\t\t l'un des deux comptes n'existe pas."<<endl;
        string reponse;
        do{
                cout<<"\n\n\t\t\t\tEst ce que vous voulez verser une autre montant (O/N)?";
                cin>>reponse;
        if(reponse=="N" || reponse =="n")
            menu();
        else if(reponse =="O" || reponse =="o") {
            system("cls");
            virverser();
        }
        }while(reponse !="N" && reponse!="O" && reponse !="n" && reponse !="o");

}


int main ()
{
   menu();


}
