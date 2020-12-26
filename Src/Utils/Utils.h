//---------------------------------------------------------------------------

#ifndef UtilsH
#define UtilsH

#include "SmartCardPCH.h"

namespace SmartGrid
{
	namespace Utils
	{
		template<typename T, typename... Arg>
		std::unique_ptr<T> ObjectsFactory(Arg... args)
		{
			auto obj = std::make_unique<T>(std::forward<Arg>(args)...);
			return std::move(obj);
		}

		#define RUNTIME_ERROR_IF(cond, message)\
			if(cond)\
				throw std::runtime_error(message);

		#define RETURN_FALSE_IF(cond)\
			if(cond)\
				return false;

		#define RETURN_TRUE_IF(cond)\
			if(cond)\
				return true;

		#define ON_EXIT(...)\
			{\
				std::once_flag flag{};\
                std::call_once(flag, ...);\
			}
	}
}
//---------------------------------------------------------------------------
#endif
