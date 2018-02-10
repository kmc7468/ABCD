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
	void DirectoryElement::Name(const std::string& new_name)
	{
		Name_ = new_name;
	}
	DirectoryElement* DirectoryElement::Parent() const noexcept
	{
		return Parent_;
	}
	void DirectoryElement::Parent(DirectoryElement* const new_parent) noexcept
	{
		Parent_ = new_parent;
	}
}