#include <abcd/Project.hpp>

namespace abcd
{
	Project::Project()
	{
		Root_ = new abcd::RootDirectory(".", "Project");
	}
	Project::~Project()
	{
		delete Root_;
	}

	void Project::Save() const
	{
		Root_->Save();
	}

	const RootDirectory* Project::RootDirectory() const noexcept
	{
		return Root_;
	}
	RootDirectory* Project::RootDirectory() noexcept
	{
		return Root_;
	}
}