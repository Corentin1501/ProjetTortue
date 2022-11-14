#include "jardinHandler.hh"
#include <fstream>

JardinHandler::JardinHandler(JardinRendering * J, QObject *parent)
    : QThread(parent)
{
    restart = false;
    abort = false;
    driver = new Driver(this); 
    scanner = new Scanner(std::cin, std::cout);
    parser = new yy::Parser(*scanner, *driver);
    jardin = J;
}

JardinHandler::~JardinHandler()
{
    delete driver;
    delete scanner;
    delete parser;

    mutex.lock();
    abort = true;
    condition.wakeOne();
    mutex.unlock();

    wait();

}

void JardinHandler::parsingJardin()
{
    QMutexLocker locker(&mutex);

    if (!isRunning()) {
        start(LowPriority);
    } else {
        restart = true;
        condition.wakeOne();
    }
}

void JardinHandler::run()
{
        mutex.lock();
	
        parser->parse();

        mutex.unlock();
        emit parse();
}
