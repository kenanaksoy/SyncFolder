#include "..\include\Folder.h"

using namespace std;

namespace FolderUpdater
{
	vector<IFile*> Folder::GetFiles() const
	{
		return vector<IFile*>();
	}

	string Folder::GetPath() const
	{
		return string();
	}
}