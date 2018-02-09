#include <abcd/File.hpp>

#include <algorithm>
#include <stdexcept>

namespace abcd
{
	File::File(const std::string& name, const std::string& extenstion, DirectoryElement* const parent)
		: DirectoryElement(name, parent), Extenstion_(extenstion)
	{}

	DirectoryElementType File::Type() const noexcept
	{
		return DirectoryElementType::File;
	}

	void File::RegisterNode(Node* const node)
	{
		if (node == nullptr)
			throw std::invalid_argument("'node' can't be nullptr.");

		Nodes_.push_back(node);
		IsModified_ = true;
	}
	void File::UnregisterNode(Node* const node)
	{
		if (node == nullptr)
			throw std::invalid_argument("'node' can't be nullptr.");

		std::vector<Node*>::iterator iterator = std::find(Nodes_.begin(), Nodes_.end(), node);

		if (iterator != Nodes_.end())
		{
			Nodes_.erase(iterator);
			IsModified_ = true;
		}
		else
			throw std::invalid_argument("Failed to find 'node'.");
	}

	std::string File::Extenstion() const
	{
		return Extenstion_;
	}
	const std::vector<Node*>& File::Nodes() const noexcept
	{
		return Nodes_;
	}
	bool File::IsModified() const noexcept
	{
		return IsModified_;
	}
}