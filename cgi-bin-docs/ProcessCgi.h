#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream> //for file io
#include <sstream> //for html string spliting
#include <stdexcept> //for error handling

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
        char processChosen(const Cgicc& cgi);
        int processCount(const Cgicc& cgi);
        string processText(const Cgicc& cgi);
        char getChosen();
        int getCount();
        string getText();
        void saveUploadFile(string mydata, string fname);
};
#endif