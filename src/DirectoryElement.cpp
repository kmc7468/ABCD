#include <abcd/DirectoryElement.hpp>

namespace abcd
{
	bool DirectoryElement::IsFile() const noexcept
	{
		return Type() == DirectoryElementType::File;
	}
	bool DirectoryElement::IsDirectory() const noexcept
	{
		return Type() == DirectoryElementType::Directory;
	}

	std::string DirectoryElement::Name() const
	{
		return Name_;
	}
	DirectoryElement* DirectoryElement::Parent() const noexcept
	{
		return Parent_;
	}
}