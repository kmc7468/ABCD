#include <abcd/DirectoryElement.hpp>

namespace abcd
{
	DirectoryElement::DirectoryElement(const std::string& name)
		: Name_(name)
	{}
	DirectoryElement::DirectoryElement(const std::string& name, DirectoryElement* const parent)
		: Name_(name), Parent_(parent)
	{}

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