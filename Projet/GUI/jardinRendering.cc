#include "jardinRendering.hh"
#include <fstream>

JardinRendering::JardinRendering(QObject *parent) : QObject(parent)
{
        
}

JardinRendering::~JardinRendering()
{
    for (unsigned int i=0; i<tortues.size(); i++)
        delete tortues[i];
}

void JardinRendering::construction(char const *file){
    std::cout << "" << std::endl; 
    if (strcmp(file,"")){
        std::ifstream fichier(file, std::ios::in);  // Lecture du fichier contenant le plan du jardin
        if(fichier) {    
            unsigned int height=0;
            unsigned int width=0;
            unsigned int i = 0;
            unsigned int j;
            std::string ligne;
            while(getline(fichier, ligne)) {
                //Création des murs :
                for(j=0;j<ligne.length();j++){
                    if (ligne[j]=='*') murs.push_back(Mur(j,i));
                    if (ligne[j]=='#') vides.push_back(Vide(j,i));
                    if (ligne[j]=='T') {Tortue * T = new Tortue; T->setX(j);T->setY(i);tortues.push_back(T);emit newTortue(j,i);}
                    if (j+1>width) width = j+1;
                }
                i++;
            }
            height=i;
            fichier.close();
            fenetre = QSize(width,height);  
        }
        else
                std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    else {Tortue * T = new Tortue; T->setX(0);T->setY(0);tortues.push_back(T);emit newTortue(0,0);fenetre = QSize(20,15);}
}

void JardinRendering::changePosition(int numeroTortue, int x, int y){
    tortues.at(numeroTortue)->setX(x);
    tortues.at(numeroTortue)->setY(y);
    EtatTortue E = EtatTortue(numeroTortue,*tortues.at(numeroTortue));
    E.setPosition(x,y);
    mouvements.push(E);
}

void JardinRendering::changeOrientation(int numeroTortue, float o){
    tortues.at(numeroTortue)->setOrientation(o);
    EtatTortue E = EtatTortue(numeroTortue,*tortues.at(numeroTortue));
    E.setOrientation(o);
    mouvements.push(E);
}

void JardinRendering::changeCouleurCarapace(int numeroTortue, int r, int g, int b){
    tortues.at(numeroTortue)->setCouleurCarapace(QColor(r,g,b));
    EtatTortue E = EtatTortue(numeroTortue,*tortues.at(numeroTortue));
    E.setCouleurCarapace(QColor(r,g,b));
    mouvements.push(E);
}

void JardinRendering::changeCouleurMotif(int numeroTortue, int r, int g, int b){
    tortues.at(numeroTortue)->setCouleurMotif(QColor(r,g,b));
    EtatTortue E = EtatTortue(numeroTortue,*tortues.at(numeroTortue));
    E.setCouleurMotif(QColor(r,g,b));
    mouvements.push(E);
}

void JardinRendering::poserStylo(int numeroTortue){
    tortues.at(numeroTortue)->poserStylo();
    EtatTortue E = EtatTortue(numeroTortue,*tortues.at(numeroTortue));
    E.setStyloPose(true);
    mouvements.push(E);
}

void JardinRendering::leverStylo(int numeroTortue){
    tortues.at(numeroTortue)->leverStylo();
    EtatTortue E = EtatTortue(numeroTortue,*tortues.at(numeroTortue));
    E.setStyloPose(false);
    mouvements.push(E);
}

bool JardinRendering::estMur(int x, int y){
     for (unsigned int i=0; i<murs.size(); i++){
         if ((murs.at(i).getX()==x) and (murs.at(i).getY()==y)) return true; 
     }
     return false;
}

void JardinRendering::changeTailleJardin(int w, int h){
     fenetre = QSize(w,h);
     emit sizeFenetre(w,h);
}

