#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> //for file io
#include <sstream> //for html string spliting

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

#ifndef PROCESS_CGI_H_INCLUDED
#define PROCESS_CGI_H_INCLUDED

class ProcessCgi
{
    private:
        char _chosen;
        int _count;
        string _text;
    public:
        ProcessCgi();
        ~ProcessCgi();
        char processChosen();
        int processCount();
        string processText();
        char getChosen();
        int getCount();
        string getText();
        void saveUploadFile(string mydata, string fname);
};
#endif