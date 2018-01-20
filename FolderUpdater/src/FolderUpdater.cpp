#include "FolderUpdater.h"
#include <filesystem>
#include "IFolder.h"
#include "IFile.h"

using std::string;

namespace FolderUpdater
{
	void SyncFolder(IFolder & destination, IFolder & source)
	{
		for (auto file : source.GetFiles())
		{
			file->CopyTo( destination.GetPath() + file->GetPath() );
		}
	}
}	
