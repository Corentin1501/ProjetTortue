#ifndef DRIVER_H
#define DRIVER_H

#include <map>
#include <string>
#include <QPoint>
#include <QColor>
#include <QSize>
#include "contexte.hh"

class JardinHandler;
class JardinRendering;

class Driver {
private:      
    JardinHandler * monJardin;
    Contexte variables;       

public:
    Driver(JardinHandler * J);
    ~Driver();
    const   Contexte& getContexte() const;
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);
    JardinRendering* getJardin();

    void    changerPositionTortue0(int x, int y);
    QPoint  getPosition(int n);
    void    avancerTortue(int numeroTortue, int nombreFois);

    float   obtenirOrientationTortue(int numeroTortue);
    void    changerOrientationTortue(int numeroTortue, std::string sens);
    bool    estMurIci(std::string position, int numeroTortue);

    void    changerCouleurCarapace(int numeroTortue, int r, int g, int b);

};

#endif


