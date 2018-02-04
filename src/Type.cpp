#include <abcd/Type.hpp>

namespace abcd
{
	Type::Type(const std::string& name)
		: Name_(name)
	{}

	std::string Type::GenerateTree() const
	{
		return GenerateTree(0);
	}

	std::string Type::TreeDepth(std::size_t depth) const
	{
		return std::string(depth * 4, ' ');
	}

	std::string Type::Name() const
	{
		return Name_;
	}
}