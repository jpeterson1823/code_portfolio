#include <string>
#include <fstream>
using namespace std;

class HomeworkFile {
    private:
    string fileName;
    string fileText;

    public:
    HomeworkFile(string fileName);
    string getName();
    string getDateString();
    void write(string text);
    void writeln(string text);
    void create();
};