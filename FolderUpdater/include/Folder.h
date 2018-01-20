#ifndef FOLDER_H
#define FOLDER_H

#include "IFolder.h"

namespace FolderUpdater
{
	class Folder:public IFolder
	{
		// Inherited via IFolder
		virtual std::vector<IFile*> GetFiles() const override;
		virtual std::string GetPath() const override;
	};
}

#endif