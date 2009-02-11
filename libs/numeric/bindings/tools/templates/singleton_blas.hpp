$TEMPLATE[blas.h]
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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_BLAS_H
#define BOOST_NUMERIC_BINDINGS_BLAS_BLAS_H

#include <boost/numeric/bindings/traits/type.h>
#include <boost/numeric/bindings/blas/blas_names.h>

extern "C" {

$CONTENT

}

#endif

$TEMPLATE[blas.h_function]
    void BLAS_$SUBROUTINE( $ARGUMENTS );
$TEMPLATE[blas_names.h]
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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_BLAS_NAMES_H
#define BOOST_NUMERIC_BINDINGS_BLAS_BLAS_NAMES_H

#include <boost/numeric/bindings/traits/fortran.h>

$CONTENT

#endif

$TEMPLATE[blas_names.h_function]
#define BLAS_$SUBROUTINE FORTRAN_ID( $subroutine )
$TEMPLATE[end]
