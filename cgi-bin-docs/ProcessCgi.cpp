#include "ProcessCgi.h"

using namespace std;
using namespace cgicc;

ProcessCgi::ProcessCgi()
{
    _chosen = processChosen();
    _count = processCount();
    _text = processText();
}
ProcessCgi::~ProcessCgi() {}

char ProcessCgi::processChosen()
{
    cout << "<br> in process chosen";
    Cgicc cgi;
    char in;
    try
    {
        in = cgi("chosen")[0];
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
        exit(1);
    }
    return -1;
}

int ProcessCgi::processCount()
{
    cout << "<br> in process count";
    Cgicc cgi;
    int in;
    try
    {
        cout << "<br> before stoi";
        in = stoi(cgi("count"));
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
        exit(1);
    }
    return -1;
}

string ProcessCgi::processText()
{
    cout << "<br> in process text";
    Cgicc cgi;
    try
    {
        cout << "<br> just before const file iterator";
        const_file_iterator file = cgi.getFile("text");
        string filedata;
        if (file != cgi.getFiles().end())
        {
            filedata = file->getData();
            cout << "<br> just before saving file";
            saveUploadFile(filedata, "../CPS3525/proj3.txt");
        }
        else
        {
            throw(filedata);
        }
    }
    catch (...)
    {
        cout << "<span style='color: red'>Error handling text input</span>";
        exit(1);
    }
    cout << "<br> after file saved";
    string content;
    char ch;
    try
    {
        ifstream file("../CPS3525/proj3.txt");

        if (!file)
        {
            cout << "<span style='color: red'>Error opening file</span>";
            exit(1);
        }
        // Read file contents and construct string containing only A-Z characters
        while (file.get(ch))
        {
            if (isalpha(ch))
            {                           // Check if the character is a letter
                content += toupper(ch); // Convert to uppercase and append to the string
            }
        }
        // Close the file
        file.close();
    }
    catch (...)
    {
        cout << "<span style='color: red'>Error handling text 2 input</span>";
        exit(1);
    }

    // Print the string containing only A-Z characters
    return content;
}

char ProcessCgi::getChosen()
{
    return _chosen;
}

int ProcessCgi::getCount()
{
    return _count;
}

string ProcessCgi::getText()
{
    return _text;
}

void ProcessCgi::saveUploadFile(string mydata, string fname)
{
    ofstream outfile;
    outfile.open(fname);
    outfile << mydata;
    outfile.close();
}