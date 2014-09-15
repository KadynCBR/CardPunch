#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string>
#include <QString>
#include <QDateTime>
#include <QTime>
using std::ofstream;
using std::string;
using std::endl;
using std::ios;
#ifndef FILEIO_H
#define FILEIO_H

class fileio
{
public:
    // Default constructor
    fileio();
    // Default destructor
    ~fileio();
    // Will check to see if the save file is available.
    bool FileCheck();
    // Outputs to file during shutdown.
    void OutputToFile(QTime *time, string user);
private:
    string savefile_;
};

#endif // FILEIO_H
