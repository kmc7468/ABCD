#ifndef ABCD_HEADER_FILE_HPP
#define ABCD_HEADER_FILE_HPP

#include <abcd/DirectoryElement.hpp>

namespace abcd
{
	class File final : public DirectoryElement
	{
	public:
		File(const std::string& name, const std::string& extenstion, DirectoryElement* const parent);
		File(const File& file) = delete;
		File(File&& file) noexcept = delete;
		virtual ~File() override = default;

	public:
		File& operator=(const File& file) = delete;
		File& operator=(File&& file) noexcept = delete;
		bool operator==(const File& file) const = delete;
		bool operator!=(const File& file) const = delete;
		
	public:
		virtual DirectoryElementType Type() const noexcept override;
	
	public:
		std::string Extenstion() const;

	private:
		std::string Extenstion_;
	};
}

#endif