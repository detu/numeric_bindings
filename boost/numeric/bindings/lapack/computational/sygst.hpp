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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_SYGST_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_SYGST_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void sygst( integer_t const itype, char const uplo,
            integer_t const n, float* a, integer_t const lda, float* b,
            integer_t const ldb, integer_t& info ) {
        LAPACK_SSYGST( &itype, &uplo, &n, a, &lda, b, &ldb, &info );
    }
    inline void sygst( integer_t const itype, char const uplo,
            integer_t const n, double* a, integer_t const lda, double* b,
            integer_t const ldb, integer_t& info ) {
        LAPACK_DSYGST( &itype, &uplo, &n, a, &lda, b, &ldb, &info );
    }
}

// value-type based template
template< typename ValueType >
struct sygst_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

$INCLUDE_TEMPLATES
    // templated specialization
    template< typename MatrixA, typename MatrixB >
    static void invoke( integer_t const itype, integer_t const n, MatrixA& a,
            MatrixB& b, integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        detail::sygst( itype, traits::matrix_uplo_tag(a), n,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                info );
    }
};


// template function to call sygst
template< typename MatrixA, typename MatrixB >
inline integer_t sygst( integer_t const itype, integer_t const n,
        MatrixA& a, MatrixB& b ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    sygst_impl< value_type >::invoke( itype, n, a, b, info );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
