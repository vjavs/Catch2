/*
 *  Created by Phil Nash on 15/6/2018.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_SINGLETONS_HPP_INCLUDED
#define TWOBLUECUBES_CATCH_SINGLETONS_HPP_INCLUDED

#include "catch_compiler_capabilities.h"

#include <mutex>

namespace Catch {

    struct ISingleton {
        virtual ~ISingleton();
    };


    void addSingleton( ISingleton* singleton );
    void cleanupSingletons();


    template<typename SingletonImplT, typename InterfaceT = SingletonImplT, typename MutableInterfaceT = InterfaceT>
    class Singleton : SingletonImplT, public ISingleton {

        static auto getInternal() -> Singleton& {
	    CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS
            static Singleton s_instance;
	    CATCH_INTERNAL_UNSUPPRESS_GLOBALS_WARNINGS
	    static bool s_added = false;
	    static std::mutex s_mutex;
            if( !s_added ) {
		std::lock_guard<std::mutex> lk(s_mutex);
                addSingleton( &s_instance );
		s_added = true;
            }
            return s_instance;
        }

    public:
        static auto get() -> InterfaceT const& {
            return getInternal();
        }
        static auto getMutable() -> MutableInterfaceT& {
            return getInternal();
        }
    };

} // namespace Catch

#endif // TWOBLUECUBES_CATCH_SINGLETONS_HPP_INCLUDED
