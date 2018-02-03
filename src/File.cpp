#include <abcd/File.hpp>

namespace abcd
{
	File::File(const std::string& name, const std::string& extenstion, DirectoryElement* const parent)
		: DirectoryElement(name, parent), Extenstion_(extenstion)
	{}

	DirectoryElementType File::Type() const noexcept
	{
		return DirectoryElementType::File;
	}

	std::string File::Extenstion() const
	{
		return Extenstion_;
	}
}