#include <abcd/Node.hpp>

namespace abcd
{
	std::string Node::GenerateTree() const
	{
		return GenerateTree(0);
	}

	std::string Node::TreeDepth(std::size_t depth) const
	{
		return std::string(depth * 4, ' ');
	}
}