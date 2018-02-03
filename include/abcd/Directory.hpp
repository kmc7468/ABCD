#ifndef ABCD_HEADER_DIRECTORY_HPP
#define ABCD_HEADER_DIRECTORY_HPP

#include <vector>

#include <abcd/DirectoryElement.hpp>

namespace abcd
{
	class Directory final : public DirectoryElement
	{
	public:
		Directory(const std::string& name, DirectoryElement* const parent);
		Directory(const Directory& directory) = delete;
		Directory(Directory&& directory) noexcept = delete;
		virtual ~Directory() override;

	public:
		Directory & operator=(const Directory& directory) = delete;
		Directory& operator=(Directory&& directory) noexcept = delete;
		bool operator==(const Directory& directory) const = delete;
		bool operator!=(const Directory& directory) const = delete;

	public:
		virtual DirectoryElementType Type() const noexcept override;

	public:
		DirectoryElement* CreateFile(const std::string& name, const std::string& extenstion);
		DirectoryElement* CreateDirectory(const std::string& name);

	private:
		std::vector<DirectoryElement*> elements_;
	};
}

#endif