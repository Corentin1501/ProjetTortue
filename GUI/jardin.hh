#ifndef JARDIN_H
#define JARDIN_H

#include "tortue.hh"
#include "jardinHandler.hh"
#include <QtGui>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLayout>
#include <vector>

class Jardin:public QWidget
{
    Q_OBJECT
    private:
        QPixmap mur;      
        QPixmap vide;        
        JardinHandler * thread;
        JardinRendering * render;
        std::vector<Tortue> tortues;
        QImage * Terrain;
        bool initialisation = true;

    private slots:
        void updateJardin();
        void nouvelleTortue(int x, int y);
        void tailleFenetre(int w, int h);
		
    protected:
        void paintEvent(QPaintEvent *event) override;

    public:
        Jardin(char const *file = "", QWidget * parent=0);
        ~Jardin();
        void dessinerMouvement(QPainter& p, EtatTortue mouvement);
        void dessinerTrait(QPainter& p, QRect pos, EtatTortue mouvement);
        void dessinerTortues(QPainter& p);	
        void dessinerTortue(QPainter& p, Tortue T);
        void updateTortue(EtatTortue mouvement);
};

#endif
