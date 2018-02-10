#include <abcd/File.hpp>

#include <algorithm>
#include <filesystem>
#include <fstream>
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
	std::string File::Path() const
	{
		std::string result;

		if (Parent())
		{
			result = Parent()->Path();
		}

		result += Name();

		if (!Extenstion_.empty())
		{
			result += '.' + Extenstion_;
		}

		return result;
	}
	void File::Save() const
	{
		std::ofstream stream(Path());

		if (!stream.is_open())
			throw std::experimental::filesystem::filesystem_error("Failed to open file.",
				std::make_error_code(std::errc::io_error));

		Code codes;

		for (Node* node : Nodes_)
		{
			codes = node->GenerateCode();

			for (std::string code : codes)
			{
				stream << code << std::endl;
			}
		}
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