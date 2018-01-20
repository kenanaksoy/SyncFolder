#ifndef IFILE_H
#define IFILE_H

#include <string>

namespace FolderUpdater
{
	class IFile
	{
	public:
		virtual  std::string GetPath() const = 0;
		virtual void CopyTo(std::string targetFilePath) const = 0;
		virtual ~IFile() {}
	};
}

#endif