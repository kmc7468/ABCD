#ifndef ABCD_HEADER_PROJECT_HPP
#define ABCD_HEADER_PROJECT_HPP

namespace abcd
{
	class Project final
	{
	public:
		Project() = default;
		Project(const Project& project) = delete;
		Project(Project&& project) noexcept = delete;
		~Project() = default;

	public:
		Project& operator=(const Project& project) = delete;
		Project& operator=(Project&& project) noexcept = delete;
		bool operator==(const Project& project) const = delete;
		bool operator!=(const Project& project) const = delete;
	};
}

#endif