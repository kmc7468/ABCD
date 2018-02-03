#include <abcd/Directory.hpp>

#include <abcd/File.hpp>

namespace abcd
{
	Directory::Directory(const std::string& name, DirectoryElement* const parent)
		: DirectoryElement(name, parent)
	{}
	Directory::~Directory()
	{
		for (DirectoryElement* element : elements_)
		{
			delete element;
		}
	}

	DirectoryElementType Directory::Type() const noexcept
	{
		return DirectoryElementType::Directory;
	}
	DirectoryElement* Directory::CreateFile(const std::string& name, const std::string& extenstion)
	{
		File* file = new File(name, extenstion, this);

		elements_.push_back(file);
		return file;
	}
	DirectoryElement* Directory::CreateDirectory(const std::string& name)
	{
		Directory* directory = new Directory(name, this);
	
		elements_.push_back(directory);
		return directory;
	}
}