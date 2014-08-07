#ifndef FPRINTER
#define FPRINTER

#include <string>
#include <fstream>	
#include <iostream>

using namespace std;

// simple utility class that opens, writes to, and closes a file
class FilePrinter
{
	private:
		std::ofstream mFile;
	
	public:
		FilePrinter(string _fileName)
		{
			cout << "Creating and opening file: '" << _fileName << "'" << endl;
			mFile.open("bin/output/"+_fileName);
		}

		~FilePrinter()
		{
			if (mFile.is_open())
				CloseFile();
		}

		void CloseFile()
		{
			cout << "\nClosing current file..." << endl;
			mFile.close();
		}

		void WriteToFile(string _stringToWrite)
		{
			mFile << _stringToWrite;
		}


};

#endif