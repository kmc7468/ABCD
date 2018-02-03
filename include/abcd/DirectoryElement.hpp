#ifndef ABCD_HEADER_DIRECTORYELEMENT_HPP
#define ABCD_HEADER_DIRECTORYELEMENT_HPP

#include <string>

namespace abcd
{
	enum class DirectoryElementType
	{
		File,
		Directory,
	};

	class DirectoryElement
	{
	public:
		DirectoryElement() = default;
		DirectoryElement(const DirectoryElement& directory_element) = delete;
		DirectoryElement(DirectoryElement&& directory_element) noexcept = delete;
		virtual ~DirectoryElement() = default;

	public:
		DirectoryElement& operator=(const DirectoryElement& directory_element) = delete;
		DirectoryElement& operator=(DirectoryElement&& directory_element) noexcept = delete;
		bool operator==(const DirectoryElement& directory_element) const = delete;
		bool operator!=(const DirectoryElement& directory_element) const = delete;

	public:
		virtual DirectoryElementType Type() const noexcept = 0;

	public:
		bool IsFile() const noexcept;
		bool IsDirectory() const noexcept;

	public:
		std::string Name() const;
		DirectoryElement* Parent() const noexcept;

	private:
		DirectoryElement* Parent_ = nullptr;
		std::string Name_;
	};
}

#endif