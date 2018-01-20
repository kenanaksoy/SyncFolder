#ifndef FILE_H
#define FILE_H

#include "IFile.h"

namespace FolderUpdater
{
	class File:public IFile
	{
		// Inherited via IFile
		virtual std::string GetPath() const override;
		virtual void CopyTo(std::string targetFilePath) const override;
	};
}

#endif