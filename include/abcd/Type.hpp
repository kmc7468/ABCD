#ifndef ABCD_HEADER_TYPE_HPP
#define ABCD_HEADER_TYPE_HPP

#include <string>

#include <abcd/Node.hpp>

namespace abcd
{
	class Type
	{
	public:
		Type(const std::string& name);
		Type(const Type& type) = delete;
		Type(Type&& type) noexcept = delete;
		virtual ~Type() = default;

	public:
		Type& operator=(const Type& type) = delete;
		Type& operator=(Type&& type) noexcept = delete;
		bool operator==(const Type& type) const = delete;
		bool operator!=(const Type& type) const = delete;

	public:
		virtual std::string GenerateTree(std::size_t depth) const = 0;
		virtual void Preprocess() = 0;
		virtual Code GenerateCCode() const = 0;

	public:
		std::string GenerateTree() const;

	protected:
		std::string TreeDepth(std::size_t depth) const;

	public:
		std::string Name() const;

	private:
		std::string Name_;
	};
}

#endif