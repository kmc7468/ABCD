#ifndef ABCD_HEADER_NODE_HPP
#define ABCD_HEADER_NODE_HPP

#include <cstddef>
#include <string>
#include <vector>

namespace abcd
{
	using Code = std::vector<std::string>;

	class Node
	{
	public:
		Node() = default;
		Node(const Node& node) = delete;
		Node(Node&& node) noexcept = delete;
		virtual ~Node() = default;

	public:
		Node& operator=(const Node& node) = delete;
		Node& operator=(Node&& node) noexcept = delete;
		bool operator==(const Node& node) const = delete;
		bool operator!=(const Node& node) const = delete;

	public:
		virtual std::string GenerateTree(std::size_t depth) const = 0;
		virtual void Preprocess() = 0;
		virtual Code GenerateCCode() const = 0;

	protected:
		std::string TreeDepth(std::size_t depth) const;

	public:
		std::string GenerateTree() const;
	};
}

#endif