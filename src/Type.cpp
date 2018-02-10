#include <abcd/Type.hpp>

namespace abcd
{
	std::string Type::GenerateTree() const
	{
		return GenerateTree(0);
	}

	std::string Type::TreeDepth(std::size_t depth) const
	{
		return std::string(depth * 4, ' ');
	}
}