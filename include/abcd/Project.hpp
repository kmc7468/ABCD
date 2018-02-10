#ifndef ABCD_HEADER_PROJECT_HPP
#define ABCD_HEADER_PROJECT_HPP

#include <abcd/Directory.hpp>

namespace abcd
{
	class Project final
	{
	public:
		Project();
		Project(const Project& project) = delete;
		Project(Project&& project) noexcept = delete;
		~Project();

	public:
		Project& operator=(const Project& project) = delete;
		Project& operator=(Project&& project) noexcept = delete;
		bool operator==(const Project& project) const = delete;
		bool operator!=(const Project& project) const = delete;

	public:
		void Save() const;

	public:
		const RootDirectory* RootDirectory() const noexcept;
		abcd::RootDirectory* RootDirectory() noexcept;

	private:
		abcd::RootDirectory* Root_;
	};
}

#endif