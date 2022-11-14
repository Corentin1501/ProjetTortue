#ifndef TORTUE_H
#define TORTUE_H

#include <QtGui>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLayout>
#include <vector>

class Tortue
{
	private:
		int posX;
		int posY;
		int width;
		int height;
		float orientation;
        bool stylo = false;
		QPixmap imageTortue;
		QBitmap corps;
		QBitmap carapace;
		QBitmap motif;
		QColor couleurCorps;
		QColor couleurCarapace;
		QColor couleurMotif;

	public:
		int getX();
		int getY();
		int getWidth();
		int getHeight();
        QRect getPos();
		float getOrientation();
		QBitmap getCorps();
		QBitmap getCarapace();
		QBitmap getMotif();
		QColor getCouleurCorps();
		QColor getCouleurCarapace();
		QColor getCouleurMotif();
        bool styloIsPose();

		void setX(int x);
		void setY(int y);
		void setOrientation(float o);
		void setCouleurCorps(QColor);
		void setCouleurCarapace(QColor);
		void setCouleurMotif(QColor);
        void poserStylo();
        void leverStylo();
		Tortue(int x=0, int y=0);
		~Tortue();
};


#endif
