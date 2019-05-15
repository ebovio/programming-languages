#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <vector>
#include "calcex.h"
#include "calculator.h"
using namespace std;

void fileReader(vector<string> files, bool compiler);
void noFileReader(bool compiler);

Calculator* calc;

int main(int argc, char* argv[])
{
   string line;

   try
  {
    calc = new Calculator();
    int command;
    vector<string> files;
    bool compiler = false;

    while((command =  getopt(argc, argv, ":v:c")) != EOF)
    {
      switch (command)
	  {
	  case 'v':
	    calc->assign(optarg);
	    break;
	  case 'c':
	    compiler = true;
	    break;
	  case ':':
	    cerr << "* Error: Missing option -v" << endl;
	    throw InvalidCommand;
	    break;
	  }
    }
    string string;
    int size = 0;
    int i = 0;
    while(i < argc)
    {
      string = argv[i];
      size = string.size();
      if(size > 5)
      {
	    if(string.substr(size-5, size) == ".calc")
        {
	      if (fstream(string.c_str()).good())
	       files.push_back(string.c_str());

          else
          {
	        cerr << "* Error: file " << string << " was not found" << endl;
	        throw InvalidCommand;
	      }
	    }
      }
      i++;
    }

    if (files.size() > 0)
    {
      fileReader(files, compiler);
    }
    else
    {
      noFileReader(compiler);
    }

    delete calc;
  }
  catch(Exception ex)
  {
    cout << "Program Aborted due to exception!" << endl;
  }
}

void fileReader(vector<string> files, bool compiler)
{
  int size = files.size();
  string ficheroCalc ;
  string ficheroEwe ;
  if (size > 0)
  {
    int i = 0;
    while (i < size)
    {
      ifstream input;
      ficheroCalc = files[i];
      input.open(ficheroCalc.c_str());
      ficheroEwe = ficheroCalc.substr(0, ficheroCalc.size() - 4) + "ewe";
      string fline;
      ofstream f;
      f.open(ficheroEwe.c_str());

      if (compiler)
      {
	    f << "start: " << endl;
      }

      while(getline(input, fline))
      {
	    try
        {
	     if (fline == "") fline += "\n";
	        if(compiler)
            {
	          f << calc->compileEWE(fline) << endl;
	        }
            else
            {
              int result = calc->eval(fline);
              cout << "= "<< calc->getAssignation() << result << endl;
              calc->setAssignation("");
	        }
	    }
        catch(...) {}
      }
      if (compiler)
      {
	    f << calc->finalCompileEWE() << endl;
      }
      f.close();
      input.close();
      i++;
    }
  }
}

void noFileReader(bool compiler)
{
  if (compiler)
  {
    string line;
    cout << "> ";
    ofstream f;
    f.open("a.ewe");
    f << "start: " << endl;
    while(getline(cin, line))
    {
      try
      {
	    if (line == "") line += "\n";
	      f << calc->compileEWE(line) << endl;
      }
      catch(...) {}
      cout << "> ";
    }
    f << calc->finalCompileEWE() << endl;
    f.close();
  }
  else
  {
    string line;
    cout << "> ";
    while(getline(cin, line))
    {
      try
      {
	    if (line == "") line += "\n";
	    int result = calc->eval(line);
	    cout << "= " << calc->getAssignation() << result << endl;
	    calc->setAssignation("");
      }
      catch(...) {}
      cout << "> ";
    }
  }
}
