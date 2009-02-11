$TEMPLATE[lapack.h]
//
// Copyright (c) 2003--2009
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_H
#define BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_H

#include <boost/numeric/bindings/traits/type.h>
#include <boost/numeric/bindings/lapack/lapack_names.h>

#ifndef BOOST_NUMERIC_BINDINGS_NO_STRUCTURE_CHECK 
#  define BOOST_NUMERIC_BINDINGS_FORTRAN
#endif 

extern "C" {

$CONTENT

    int LAPACK_ILAENV(int const* ispec, const char* name, const char* opt,
        int const* n1, int const* n2, int const* n3, int const* n4, int, int);
}

#endif

$TEMPLATE[lapack.h_function]
    void LAPACK_$SUBROUTINE( $ARGUMENTS );
$TEMPLATE[lapack_names.h]
//
// Copyright (c) 2003--2009
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_NAMES_H
#define BOOST_NUMERIC_BINDINGS_LAPACK_LAPACK_NAMES_H

#ifndef BOOST_NUMERIC_BINDINGS_USE_CLAPACK
#  include <boost/numeric/bindings/traits/fortran.h>
#else
#  define FORTRAN_ID( id ) id##_
#endif

$CONTENT

#endif

$TEMPLATE[lapack_names.h_function]
#define LAPACK_$SUBROUTINE FORTRAN_ID( $subroutine )
$TEMPLATE[end]
