/*
 *  TrickyTests.cpp
 *  Catch - Test
 *
 *  Created by Phil on 09/11/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

#include "catch.hpp"

namespace Catch
{
    template<>
    std::string toString<std::pair<int, int> >( const std::pair<int, int>& value )
    {
        std::ostringstream oss;
        oss << "std::pair( " << value.first << ", " << value.second << " )";
        return oss.str();
        
    }
}

TEST_CASE( "succeeding/Tricky/std::pair", "Parsing a std::pair" )
{
    std::pair<int, int> aNicePair( 1, 2 );

    // !TBD: would be nice if this could compile without the extra parentheses
    EXPECT( (std::pair<int, int>( 1, 2 )) == aNicePair );
    
}

TEST_CASE( "succeeding/Tricky/complex lhs", "Where the LHS is not a simple value" )
{
    int a = 1;
    int b = 2;

    // This only captures part of the expression, but issues a warning about the rest
    EXPECT( a == 2 || b == 2 );
}

TEST_CASE( "succeeding/Tricky/complex lhs/2", "Where the LHS is not a simple value" )
{
    int a = 1;
    
    // This only captures part of the expression, but issues a warning about the rest
//    EXPECT( a + 1 == 2);
}