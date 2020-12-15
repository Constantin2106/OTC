//---------------------------------------------------------------------------
#include <fstream>
#include <string>
#include <filesystem>
#pragma hdrstop

#include "DataControl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace SmartGrid::DataControl
{
	using namespace std;
	using namespace SmartGrid::Types;

	namespace fs = std::filesystem;

	namespace
	{
		fs::path MakeGridDataFolder()
		{
			auto workFolder = fs::current_path();
			auto dataFolder = workFolder / "Data";
			if(!fs::exists(dataFolder) || !fs::is_directory(dataFolder))
				fs::create_directory(dataFolder);

			return dataFolder;
		}
	}

	bool WriteGridData(const Parameters::GridParameters& gridParams, const std::string& fileName)
	{
		auto folder = MakeGridDataFolder();
		auto pathToFile = (folder / fileName).string();

		ofstream oFileStream(pathToFile.c_str());
		if(!oFileStream.is_open())
		{
			ShowMessage("Failed to open file.");
			return false;
		}

		oFileStream << gridParams.Step << endl;
		oFileStream << gridParams.Length << endl;
		oFileStream << gridParams.Vmin << endl;
		oFileStream << gridParams.Vmax << endl;
		oFileStream << gridParams.VStep << endl;

    	return true;
	}

	bool ReadGridData(const std::string fileName, Parameters::GridParameters& gridParams)
	{
		auto folder = MakeGridDataFolder();
		auto pathToFile = (folder / fileName).string();

		ifstream iFileStream(pathToFile.c_str());
		if(!iFileStream.is_open())
		{
			ShowMessage("Failed to open file.");
			return false;
		}

		iFileStream >> gridParams.Step;
		iFileStream >> gridParams.Length;
		iFileStream >> gridParams.Vmin;
		iFileStream >> gridParams.Vmax;
		iFileStream >> gridParams.VStep;

		return true;
	}
}
