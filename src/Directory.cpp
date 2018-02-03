#include <abcd/Directory.hpp>

namespace abcd
{
	Directory::Directory(const std::string& name, DirectoryElement* const parent)
		: DirectoryElement(name, parent)
	{}

	DirectoryElementType Directory::Type() const noexcept
	{
		return DirectoryElementType::Directory;
	}
}