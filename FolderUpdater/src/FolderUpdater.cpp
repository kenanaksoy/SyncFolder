#include "FolderUpdater.h"
#include "qfileinfo.h"
#include "IFolder.h"
#include "IFile.h"

using std::string;

namespace FolderUpdater
{
	string ExtractFilenameFromPath(string filePath)
	{
		return QFileInfo{ filePath.c_str() }.fileName().toStdString();
	}

	string ConstructFilepath(string folderPath, string fileName)
	{
#ifdef WIN32
		return folderPath + "\\" + fileName;
#elif
		return folderPath + "/" + fileName;
#endif
	}

	void SyncFolder(IFolder & destination, IFolder & source)
	{
		for (auto file : source.GetFiles())
		{
			file->CopyTo(ConstructFilepath(destination.GetPath(), ExtractFilenameFromPath(file->GetPath())));
		}
	}

	
}	
