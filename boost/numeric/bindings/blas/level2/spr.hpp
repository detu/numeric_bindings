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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_SPR_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_SPR_HPP

// Include header of configured BLAS interface
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
#include <boost/numeric/bindings/blas/detail/cblas.h>
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
#include <boost/numeric/bindings/blas/detail/cublas.h>
#else
#include <boost/numeric/bindings/blas/detail/blas.h>
#endif

#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {

// The detail namespace is used for overloads on value type,
// and to dispatch to the right routine

namespace detail {

inline void spr( const char uplo, const integer_t n, const float alpha,
        const float* x, const integer_t incx, float* ap ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_sspr( CblasColMajor, ( uplo == 'U' ? CblasUpper : CblasLower ), n,
            alpha, x, incx, ap );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    cublasSspr( uplo, n, alpha, x, incx, ap );
#else
    BLAS_SSPR( &uplo, &n, &alpha, x, &incx, ap );
#endif
}

inline void spr( const char uplo, const integer_t n, const double alpha,
        const double* x, const integer_t incx, double* ap ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_dspr( CblasColMajor, ( uplo == 'U' ? CblasUpper : CblasLower ), n,
            alpha, x, incx, ap );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    // NOT FOUND();
#else
    BLAS_DSPR( &uplo, &n, &alpha, x, &incx, ap );
#endif
}


} // namespace detail

// value-type based template
template< typename ValueType >
struct spr_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // static template member function
    template< typename VectorX, typename MatrixAP >
    static return_type invoke( const real_type alpha, const VectorX& x,
            MatrixAP& ap ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorX >::value_type, typename traits::matrix_traits<
                MatrixAP >::value_type >::value) );
        detail::spr( traits::matrix_uplo_tag(ap),
                traits::matrix_num_columns(ap), alpha,
                traits::vector_storage(x), traits::vector_stride(x),
                traits::matrix_storage(ap) );
    }
};

// generic template function to call spr
template< typename VectorX, typename MatrixAP >
inline typename spr_impl< typename traits::vector_traits<
        VectorX >::value_type >::return_type
spr( const typename traits::type_traits<
        typename traits::vector_traits<
        VectorX >::value_type >::real_type alpha, const VectorX& x,
        MatrixAP& ap ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    spr_impl< value_type >::invoke( alpha, x, ap );
}

} // namespace blas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
