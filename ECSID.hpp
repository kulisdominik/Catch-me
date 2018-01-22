#include "LibsAndDeclarations.h"
using ComponentID = std::size_t;


// Every component type has unique ID number.
namespace ECSID
{
	// Template store unique ID and return next values if
	// template getComponentTypeID() will need it.
	inline ComponentID getUniqueComponentID() noexcept
	{
		static ComponentID lastID{ 0u };
		return ++lastID;
	}

	// Returns an uniqe ComponetID based upon the type passed. 
	template <typename T>
	inline ComponentID getComponentTypeID() noexcept
	{
		// T must inherit from Component
		static_assert(std::is_base_of<Component, T>::value,
			"T must come into Component");

		static ComponentID typeID{ getUniqueComponentID() };
		return typeID;
	}
}