#ifndef JARDINRENDERING_H
#define JARDINRENDERING_H

#include "tortue.hh"
#include <queue>
#include <QSize>
#include <iostream>

class Mur{
    private: 
        int posX;
        int posY;
    public:
        Mur(int x, int y):posX(x),posY(y){};
        int getX(){return posX;}
        int getY(){return posY;}
        QRect getPos() {return QRect(posX*35,posY*35,35,35);}
};

class Vide{
    private: 
        int posX;
        int posY;
    public:
        Vide(int x, int y):posX(x),posY(y){};
        int getX(){return posX;}
        int getY(){return posY;}
        QRect getPos() {return QRect(posX*35,posY*35,35,35);}
};

class EtatTortue{
    private:
       unsigned int numeroTortue;
       int posX;
       int posY;
       float orientation;
       QColor couleurCarapace;
       QColor couleurMotif;
       bool styloPose;
   public:
       EtatTortue(unsigned int n, int x, int y, int o, QColor cC, QColor cM, bool s): numeroTortue(n),posX(x),posY(y),orientation(o),couleurCarapace(cC),couleurMotif(cM),styloPose(s){};
       EtatTortue(int n, Tortue T): numeroTortue(n),posX(T.getX()),posY(T.getY()),orientation(T.getOrientation()),
       couleurCarapace(T.getCouleurCarapace()),couleurMotif(T.getCouleurMotif()),styloPose(T.styloIsPose()){};
       void setPosition(int x, int y){posX=x;posY=y;}
       void setOrientation(float o){orientation=o;}
       void setCouleurCarapace(QColor c){couleurCarapace=c;}
       void setCouleurMotif(QColor c){couleurMotif=c;}
       void setStyloPose(bool s){styloPose=s;}
       unsigned int getNumeroTortue(){return numeroTortue;}
       int getX(){return posX;}
       int getY(){return posY;}
       float getOrientation(){return orientation;}
       QColor getCouleurCarapace(){return couleurCarapace;}
       QColor getCouleurMotif(){return couleurMotif;}
       bool styloIsPose(){return styloPose;}
};

class JardinRendering : public QObject
{
    Q_OBJECT;
    
public:
    JardinRendering(QObject *parent = 0);
    ~JardinRendering();
    void construction(char const *file);

    std::vector<Mur> getMurs(){return murs;}
    std::vector<Vide> getVides(){return vides;}
    std::queue<EtatTortue> * getMouvements(){return &mouvements;}
    std::vector<Tortue *> getTortues(){return tortues;}
    
    void changePosition(int numeroTortue, int x, int y);
    void changeOrientation(int numeroTortue, float o);
    void changeCouleurCarapace(int numeroTortue, int r, int g, int b);
    void changeCouleurMotif(int numeroTortue, int r, int g, int b);
    void poserStylo(int numeroTortue);
    void leverStylo(int numeroTortue);
    QPoint position(int numeroTortue){return QPoint(tortues.at(numeroTortue)->getX(),tortues.at(numeroTortue)->getY());}
    float orientation(int numeroTortue){return tortues.at(numeroTortue)->getOrientation();}
    QColor couleurCarapace(int numeroTortue){return tortues.at(numeroTortue)->getCouleurCarapace();}
    QColor couleurMotif(int numeroTortue){return tortues.at(numeroTortue)->getCouleurMotif();}
    bool styloEstPose(int numeroTortue){return tortues.at(numeroTortue)->styloIsPose();}
    QSize tailleJardin(){return fenetre;};
    void changeTailleJardin(int w, int h);
    bool estMur(int x, int y);

signals:
    void newTortue(int x, int y);
    void sizeFenetre(int w, int h);

private:

    std::vector<Tortue *> tortues;
    std::vector<Mur> murs;
    std::vector<Vide> vides;
    std::queue<EtatTortue> mouvements; 
    QSize fenetre;
};

#endif
