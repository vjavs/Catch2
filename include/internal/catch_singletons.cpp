/*
 *  Created by Phil Nash on 15/6/2018.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include "catch_singletons.hpp"

#include <vector>

namespace Catch {

    namespace {
        static auto getSingletons() -> std::vector<ISingleton*>& {
	    CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS
            static std::vector<ISingleton*> g_singletons;
	    CATCH_INTERNAL_UNSUPPRESS_GLOBALS_WARNINGS
            return g_singletons;
        }
    }

    ISingleton::~ISingleton() {}

    void addSingleton(ISingleton* singleton ) {
        getSingletons().push_back( singleton );
    }
    void cleanupSingletons() {
        getSingletons().clear();
    }

} // namespace Catch
