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
		DirectoryElement(const std::string& name);
		DirectoryElement(const std::string& name, DirectoryElement* const parent);
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
		virtual std::string Path() const = 0;
		virtual void Save() const = 0;

	public:
		bool IsFile() const noexcept;
		bool IsDirectory() const noexcept;

	public:
		std::string Name() const;
		void Name(const std::string& new_name);
		DirectoryElement* Parent() const noexcept;
		void Parent(DirectoryElement* const new_parent) noexcept;

	private:
		DirectoryElement* Parent_ = nullptr;
		std::string Name_;
	};
}

#endif