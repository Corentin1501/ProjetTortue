#include "jardin.hh"
#include <unistd.h>

Jardin::Jardin(char const *file, QWidget * parent)
:QWidget(parent){
    render = new JardinRendering();
    thread = new JardinHandler(render);
    connect(thread, SIGNAL(parse()), this, SLOT(updateJardin()));
    connect(render, SIGNAL(newTortue(int, int)), this, SLOT(nouvelleTortue(int, int)));
    connect(render, SIGNAL(sizeFenetre(int, int)), this, SLOT(tailleFenetre(int, int)));
    render->construction(file);
    this->setFixedSize(render->tailleJardin().width()*35,render->tailleJardin().height()*35);
    mur = QPixmap("../GUI/IMG/mur.jpg");
    vide = QPixmap("../GUI/IMG/vide.jpg");
    Terrain = new QImage(render->tailleJardin().width()*35,render->tailleJardin().height()*35, QImage::Format_RGB32); //QImage::Format_Mono);
    Terrain->fill(Qt::white);
}

Jardin::~Jardin(){
    delete Terrain;
}

void Jardin::nouvelleTortue(int x, int y){
    tortues.push_back(Tortue(x,y));
}

void Jardin::tailleFenetre(int w, int h){
    this->setFixedSize(w*35, h*35);
    Terrain = new QImage(w*35, h*35, QImage::Format_RGB32); //QImage::Format_Mono);
    Terrain->fill(Qt::white);
    initialisation=true;
}

void Jardin::dessinerTortue(QPainter& p, Tortue T){
//Préparation de la zone de dessin
	p.translate(T.getX()*T.getWidth()+T.getWidth()/2,T.getY()*T.getHeight()+T.getHeight()/2);
	p.rotate(T.getOrientation());
//Affichage de la tortue T
	p.setPen(T.getCouleurCorps());
	p.drawPixmap(QRect(-T.getWidth()/2,-T.getHeight()/2,T.getWidth(),T.getHeight()),T.getCorps(), T.getCorps().rect());
	p.setPen(T.getCouleurCarapace());
	p.drawPixmap(QRect(-T.getWidth()/2,-T.getHeight()/2,T.getWidth(),T.getHeight()),T.getCarapace(), T.getCarapace().rect());
	p.setPen(T.getCouleurMotif());
	p.drawPixmap(QRect(-T.getWidth()/2,-T.getHeight()/2,T.getWidth(),T.getHeight()),T.getMotif(), T.getMotif().rect());
//Remise en place de la zone de dessin
	p.rotate(-T.getOrientation());
	p.translate(-(T.getX()*T.getWidth()+T.getWidth()/2),-(T.getY()*T.getHeight()+T.getHeight()/2));
}

void Jardin::dessinerTortues(QPainter& p){
    for (unsigned int i = 0; i<tortues.size(); i++) {
        dessinerTortue(p,tortues.at(i));
    }
}

void Jardin::dessinerTrait(QPainter& p, QRect pos, EtatTortue mouvement){
    p.setPen(mouvement.getCouleurCarapace());
    int differenceX = pos.width()/2;
    int differenceY = pos.height()/2;
    p.drawLine(pos.x()+differenceX,pos.y()+differenceY,mouvement.getX()*pos.width()+differenceX,mouvement.getX()*pos.height()+differenceY);
}

void Jardin::updateTortue(EtatTortue mouvement){
    tortues.at(mouvement.getNumeroTortue()).setX(mouvement.getX());
    tortues.at(mouvement.getNumeroTortue()).setY(mouvement.getY());
    tortues.at(mouvement.getNumeroTortue()).setOrientation(mouvement.getOrientation());
    tortues.at(mouvement.getNumeroTortue()).setCouleurCarapace(mouvement.getCouleurCarapace());
    tortues.at(mouvement.getNumeroTortue()).setCouleurMotif(mouvement.getCouleurMotif());
    if (mouvement.styloIsPose())
        tortues.at(mouvement.getNumeroTortue()).poserStylo();
    else tortues.at(mouvement.getNumeroTortue()).leverStylo();
}

void Jardin::dessinerMouvement(QPainter& p, EtatTortue mouvement){
    if (mouvement.styloIsPose())
        dessinerTrait(p,tortues.at(mouvement.getNumeroTortue()).getPos(),mouvement);
    updateTortue(mouvement);
}

void Jardin::paintEvent(QPaintEvent *){
    if (initialisation) {
        QPainter carte(Terrain);
        for (unsigned int i = 0; i < render->getMurs().size(); i++){
            carte.drawPixmap(render->getMurs().at(i).getPos(), mur);
        }
        for (unsigned int i = 0; i < render->getVides().size(); i++){
	    carte.drawPixmap(render->getVides().at(i).getPos(), vide);
        }
        carte.end();
        QPainter p(this);
        p.drawImage(0, 0, *Terrain);
        dessinerTortues(p);
        p.end();
        
        initialisation=false;
        thread->parsingJardin();
    }
    else{
            QPainter p(this);
            if (render->getMouvements()->size()!=0)  {
                QPainter carte(Terrain);
                dessinerMouvement(carte,render->getMouvements()->front());
                carte.end();    
            }
            p.drawImage(0, 0, *Terrain);
            dessinerTortues(p);
            p.end();
    }
}

void Jardin::updateJardin()
{   
    while (render->getMouvements()->size()!=0){
         usleep(100000);
         repaint();
         render->getMouvements()->pop();
    }
    thread->parsingJardin();
}


