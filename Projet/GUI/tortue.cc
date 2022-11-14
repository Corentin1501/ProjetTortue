#include "tortue.hh"

Tortue::Tortue(int x, int y):posX(x),posY(y),width(35),height(35),orientation(0){
	imageTortue = QPixmap("../GUI/IMG/tortue.png");
	corps = imageTortue.createMaskFromColor(QColor(255, 200, 67),Qt::MaskOutColor);
	carapace = imageTortue.createMaskFromColor(QColor(0, 255, 0),Qt::MaskOutColor);
	motif = imageTortue.createMaskFromColor(QColor(0, 170, 0),Qt::MaskOutColor);
	couleurCorps = QColor(255,200,67);
	couleurCarapace = QColor(0,255,0);
	couleurMotif = QColor(0,170,0);
}

Tortue::~Tortue(){
}

int Tortue::getX(){
	return posX;
}

int Tortue::getY(){
	return posY;
}

int Tortue::getWidth(){
	return width;
}

int Tortue::getHeight(){
	return height;
}

QRect Tortue::getPos(){
	return QRect(posX*width,posY*height,width,height);
}

float Tortue::getOrientation(){
	return orientation;
}

void Tortue::poserStylo(){
        stylo = true;
}

void Tortue::leverStylo(){
        stylo = false;
}

QBitmap Tortue::getCorps(){
	return corps;
}

QBitmap Tortue::getCarapace(){
	return carapace;
}

QBitmap Tortue::getMotif(){
	return motif;
}

void Tortue::setCouleurCorps(QColor couleur){
	couleurCorps = couleur;
}

void Tortue::setCouleurCarapace(QColor couleur){
	couleurCarapace = couleur;
}

void Tortue::setCouleurMotif(QColor couleur){
	couleurMotif = couleur;
}

QColor Tortue::getCouleurCorps(){
	return couleurCorps;
}

QColor Tortue::getCouleurCarapace(){
	return couleurCarapace;
}

QColor Tortue::getCouleurMotif(){
	return couleurMotif;
}

void Tortue::setX(int x){
	posX=x;
}

void Tortue::setY(int y){
	posY=y;
}

void Tortue::setOrientation(float o){
	orientation=o;
}

bool Tortue::styloIsPose(){
       return stylo;
}
