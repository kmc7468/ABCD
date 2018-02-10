#ifndef ABCD_HEADER_DIRECTORY_HPP
#define ABCD_HEADER_DIRECTORY_HPP

#include <vector>

#include <abcd/DirectoryElement.hpp>

namespace abcd
{
	class Directory : public DirectoryElement
	{
	public:
		Directory(const std::string& name, DirectoryElement* const parent);
		Directory(const Directory& directory) = delete;
		Directory(Directory&& directory) noexcept = delete;
		virtual ~Directory() override;

	public:
		Directory& operator=(const Directory& directory) = delete;
		Directory& operator=(Directory&& directory) noexcept = delete;
		bool operator==(const Directory& directory) const = delete;
		bool operator!=(const Directory& directory) const = delete;

	public:
		virtual DirectoryElementType Type() const noexcept override;
		virtual std::string Path() const override;

	public:
		DirectoryElement* CreateFile(const std::string& name, const std::string& extenstion);
		DirectoryElement* CreateDirectory(const std::string& name);
		void RegisterElement(DirectoryElement* const directory_element);
		void UnregisterElement(DirectoryElement* const directory_element);

	public:
		const std::vector<DirectoryElement*>& Elements() const noexcept;

	private:
		std::vector<DirectoryElement*> Elements_;
	};

	class RootDirectory final : public Directory
	{
	public:
		RootDirectory(const std::string& path, const std::string& name);
		RootDirectory(const RootDirectory& directory) = delete;
		RootDirectory(RootDirectory&& directory) noexcept = delete;
		virtual ~RootDirectory() override = default;

	public:
		RootDirectory& operator=(const RootDirectory& directory) = delete;
		RootDirectory& operator=(RootDirectory&& directory) noexcept = delete;
		bool operator==(const RootDirectory& directory) const = delete;
		bool operator!=(const RootDirectory& directory) const = delete;

	public:
		virtual std::string Path() const override;

	public:
		void Path(const std::string& new_path);

	private:
		std::string Path_;
	};
}

#endif