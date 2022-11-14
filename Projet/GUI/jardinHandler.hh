#ifndef JARDINHANDLER_H
#define JARDINHANDLER_H

#include "parser.hh"
#include "scanner.hh"
#include "driver.hh"
#include "jardinRendering.hh"
#include <queue>
#include <QMutex>
#include <QSize>
#include <QThread>
#include <QWaitCondition>

class JardinHandler : public QThread
{
    Q_OBJECT

public:
    JardinHandler(JardinRendering * J, QObject *parent = 0);
    ~JardinHandler();
    void parsingJardin();
    JardinRendering * getJardinRendering() {return jardin;}
    
signals:
    void parse();

protected:
    void run() override;

private:
    Driver * driver;
    Scanner * scanner;
    yy::Parser * parser;

    JardinRendering * jardin;

    QMutex mutex;
    QWaitCondition condition;
    bool restart;
    bool abort;

};

#endif
