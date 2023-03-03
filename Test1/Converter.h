#include <string>
#include <vector>

using namespace std;

class Converter
{
public:
	Converter() {};
	~Converter() {};
	void ShowResult();
	void SetFilePath(string _str) { filePath = _str; }
	bool IsReady();
	void Start();

private:
	bool ReadFile(string _path);
	void CheckDuplicateSymbols(string, vector<char>, vector<char>);

	vector<string> aResult;
	vector<string> aStrings;
	string filePath;
};
