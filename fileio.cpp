#include "fileio.h"

fileio::fileio() {
    savefile_ = "save.txt";
    if (FileCheck() == false) {
        // File does not exist.

    } else {
        // File does exist.
    }
}
fileio::~fileio() {
    // Entry
}

bool fileio::FileCheck() {
    struct stat buf;
    if (stat(savefile_.c_str(), &buf) != -1) {
        return true;
    }
    return false;
}

void fileio::OutputToFile(QTime *time, string user) {
    if (user != "") {
        ofstream fout;
        fout.open(savefile_.c_str(), ios::out | ios::app);
        QString time_qs = time->toString("hh : mm : ss");
        QString date_qs = QDateTime::currentDateTime().toString("ddd MMMM d, yyyy");
        string time_s = time_qs.toStdString();
        string date_s = date_qs.toStdString();
        fout << user << " " << date_s << " :: " << time_s << endl;
        fout.close();
    }
}
