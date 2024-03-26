#include "ProcessCgi.h"

using namespace std;
using namespace cgicc;

ProcessCgi::ProcessCgi()
{
    //need to make cgi object in constructor and pass indidually
    //this is cause if in method then looking to grab new form data each time
    Cgicc cgi;
    _chosen = processChosen(cgi);
    _count = processCount(cgi);
    //cout << "<br>in constructor between count and proctext"; //debugging print
    _text = processText(cgi);
}
ProcessCgi::~ProcessCgi() {}

char ProcessCgi::processChosen(const Cgicc& cgi)
{
    //cout << "<br> in process chosen"; //debugging print
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

int ProcessCgi::processCount(const Cgicc& cgi)
{
    //cout << "<br> in process count"; //debugging print
    int in;
    try
    {
        cout << "<br> before stoi";
        string countStr = cgi("count");
        // Check if countStr is empty or contains non-numeric characters
        if(countStr.empty() || countStr.find_first_not_of("0123456789") != string::npos) {
            throw invalid_argument("Invalid count input");
        }
        in = stoi(countStr);
        if (!(in > 0 && in <= 100))
        {
            throw out_of_range("Count out of range");
        }
        return in;
    }
    catch (const invalid_argument& e)
    {
        cout << "<span style='color: red'>Invalid argument: " << e.what() << "</span>";
        exit(1);
    }
    catch (const out_of_range& e)
    {
        cout << "<span style='color: red'>Out of range: " << e.what() << "</span>";
        exit(1);
    }
    catch (...)
    {
        cout << "<span style='color: red'>Unknown error occurred during count processing</span>";
        exit(1);
    }
}

string ProcessCgi::processText(const Cgicc& cgi)
{
    //cout << "<br> in process text"; //debugging print
    try
    {
        //cout << "<br> just before const file iterator"; //debugging print
        const_file_iterator file = cgi.getFile("text");
        string filedata;
        if (file != cgi.getFiles().end())
        {
            filedata = file->getData();
            //cout << "<br> just before saving file"; //debugging print
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
    //cout << "<br> after file saved"; //debugging print
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