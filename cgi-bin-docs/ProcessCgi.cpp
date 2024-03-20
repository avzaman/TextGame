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

ProcessCgi::ProecessCgi()
{
    _chosen = processChosen();
    _count = processCount();
    _text = processText();
}
ProcessCgi::~ProcessCgi() {}

char ProcessCgi::processChosen()
{
    char in;
    try
    {
        in = cgi("chosen");
        if (!(in >= 65 && in <= 90))
        {
            throw(in);
        }
        else
        {
            return in;
        }
    }
    catch (...)
    {
        cout << "<span style='color: red'>Error handling char input</span>";
    }
    return -1;
}

int ProcessCgi::processCount()
{
    int in;
    try
    {
        in = cgi("count");
        if (!(in > 0 && in <= 100))
        {
            throw(in);
        }
        else
        {
            return in;
        }
    }
    catch (...)
    {
        cout << "<span style='color: red'>Error handling number input</span>";
    }
    return -1;
}

string ProcessCgi::processText()
{
    try
    {
        const_file_iterator file = cgi.getFile("text");
        string filedata;
        if (file != cgi.getFiles().end())
        {
            filedata = file->getData();
            saveUploadFile(filedata, "../CPS3525/fileInput.txt");
        }
        else
        {
            throw(filedata);
        }
    }
    catch (Exception e)
    {
        cout << e;
    }

    ifstream file("../CPS3525/fileInput.txt");

    if (!file)
    {
        cerr << "Error opening file." << endl;
    }
    // Read file contents and construct string containing only A-Z characters
    string content;
    char ch;
    while (file.get(ch))
    {
        if (isalpha(ch))
        {                           // Check if the character is a letter
            content += toupper(ch); // Convert to uppercase and append to the string
        }
    }
    // Close the file
    file.close();
    // Print the string containing only A-Z characters
    return content;
}

void ProcessCgi::saveUploadFile(string mydata, string fname)
{
    ofstream outfile;
    outfile.open(fname);
    outfile << mydata;
    outfile.close();
}