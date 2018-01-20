#ifndef IFOLDER_H
#define IFOLDER_H

#include <vector>
#include <memory>
#include <string>

namespace FolderUpdater
{
	class IFile;

	class IFolder
	{
	public:
		virtual std::vector<IFile *> GetFiles() const = 0;
		virtual std::string GetPath() const = 0;
		virtual ~IFolder() {};
	};
}
#endif