
#include "Processing.h"

void Processing::buildSketch(std::string sketchPath, std::string outputPath)
{
	std::string command = "processing-jave.exe --sketch=" + sketchPath + " --output=" + outputPath + " --force --run";
	system(command.c_str());
}