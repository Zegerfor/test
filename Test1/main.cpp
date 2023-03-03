#include "Converter.h"

int main()
{
	Converter* converter = new Converter();
	converter->SetFilePath("input.txt");
	if (converter->IsReady()) {
		converter->Start();
		converter->ShowResult();
	}
}