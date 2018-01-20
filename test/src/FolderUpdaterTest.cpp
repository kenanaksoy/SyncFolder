#include <vector>
#include <string>
#include "gmock\gmock.h"
#include "gtest\gtest.h"
#include "FolderUpdater.h"
#include "IFolder.h"
#include "IFile.h"

using namespace testing;
using namespace std;
using FolderUpdater::IFile;
using FolderUpdater::IFolder;

class FileCopyTest:public testing::Test
{
};

class FolderMock :public IFolder
{
public:
	MOCK_CONST_METHOD0(GetFiles, std::vector<IFile *>());
	MOCK_CONST_METHOD0(GetPath, std::string());
};

class FileMock :public IFile
{
public:
	MOCK_CONST_METHOD0(GetPath, string());
	MOCK_CONST_METHOD1(CopyTo, void(string));
};

TEST_F(FileCopyTest,CopiesFilesInRoot_IfNotExist)
{
	FolderMock dest;
	FolderMock source;
	FileMock *file=new FileMock();
	
	vector<IFile *> files{file };

	EXPECT_CALL(*file, CopyTo("C:\\Target folder\\filename")).Times(AtLeast(1));
	EXPECT_CALL(*file, GetPath()).WillRepeatedly(Return("C:\\Source folder\\filename"));
	EXPECT_CALL(source, GetFiles()).WillRepeatedly(Return(files));
	EXPECT_CALL(dest, GetPath()).WillRepeatedly(Return("C:\\Target folder"));
	
	SyncFolder(dest, source);

	delete file;
}

TEST_F(FileCopyTest, DoesntCopyFilesInRoot_IfExist)
{
	FolderMock dest;
	FolderMock source;
	auto sourceFile1 = new FileMock;
	auto sourceFile2 = new FileMock;
	auto destFile = new FileMock;

	EXPECT_CALL(source, GetFiles()).WillRepeatedly(Return(vector<IFile *>{sourceFile1, sourceFile2}));
	EXPECT_CALL(dest, GetFiles()).WillRepeatedly(Return(vector<IFile *>{destFile}));
	EXPECT_CALL(*sourceFile1, GetPath()).WillOnce(Return("C:\\Source Folder\\file1"));
	EXPECT_CALL(*sourceFile2, GetPath()).WillOnce(Return("C:\\Source Folder\\file2"));
	EXPECT_CALL(*destFile, GetPath()).WillOnce(Return("C:\\Destination Folder\\file1"));
	EXPECT_CALL(*sourceFile1, CopyTo(_)).Times(0);
	EXPECT_CALL(*sourceFile2, CopyTo("C:\\Destination Folder\\file2")).Times(1);

	SyncFolder(dest, source);

	delete sourceFile1;
	delete sourceFile2;
	delete destFile;
}

