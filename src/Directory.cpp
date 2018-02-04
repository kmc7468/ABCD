#include <abcd/Directory.hpp>

#include <algorithm>
#include <stdexcept>

#include <abcd/File.hpp>

namespace abcd
{
	Directory::Directory(const std::string& name, DirectoryElement* const parent)
		: DirectoryElement(name, parent)
	{}
	Directory::~Directory()
	{
		for (DirectoryElement* element : Elements_)
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

		Elements_.push_back(file);
		return file;
	}
	DirectoryElement* Directory::CreateDirectory(const std::string& name)
	{
		Directory* directory = new Directory(name, this);
	
		Elements_.push_back(directory);
		return directory;
	}
	void Directory::RegisterElement(DirectoryElement* const directory_element)
	{
		if (directory_element == nullptr)
			throw std::invalid_argument("'directory_element' can't be nullptr.");
		if (directory_element == this)
			throw std::invalid_argument("'directory_element' can't be itself.");

		Elements_.push_back(directory_element);
	}
	void Directory::UnregisterElement(DirectoryElement* const directory_element)
	{
		if (directory_element == nullptr)
			throw std::invalid_argument("'directory_element' can't be nullptr.");
		if (directory_element == this)
			throw std::invalid_argument("'directory_element' can't be itself.");

		std::vector<DirectoryElement*>::iterator iterator = std::find(Elements_.begin(), Elements_.end(), directory_element);

		if (iterator != Elements_.end())
		{
			Elements_.erase(iterator);
		}
		else
			throw std::invalid_argument("Failed to find 'directory_element'.");
	}

	const std::vector<DirectoryElement*>& Directory::Elements() const noexcept
	{
		return Elements_;
	}
}