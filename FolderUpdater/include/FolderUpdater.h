#ifndef FOLDER_UPDATER_H
#define FOLDER_UPDATER_H

#include <string>

namespace FolderUpdater
{
	class IFolder;

	void SyncFolder(IFolder& destination, IFolder& source);
}
#endif