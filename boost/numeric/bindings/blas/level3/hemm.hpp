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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL3_HEMM_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL3_HEMM_HPP

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

inline void hemm( const char side, const char uplo, const integer_t m,
        const integer_t n, const traits::complex_f alpha,
        const traits::complex_f* a, const integer_t lda,
        const traits::complex_f* b, const integer_t ldb,
        const traits::complex_f beta, traits::complex_f* c,
        const integer_t ldc ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_chemm( CblasColMajor, ( uplo == 'L' ? CblasLeft : CblasRight ),
            ( uplo == 'U' ? CblasUpper : CblasLower ), m, n,
            traits::void_ptr(&alpha), traits::void_ptr(a), lda,
            traits::void_ptr(b), ldb, traits::void_ptr(&beta),
            traits::void_ptr(c), ldc );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    cublasChemm( side, uplo, m, n, traits::void_ptr(alpha),
            traits::void_ptr(a), lda, traits::void_ptr(b), ldb,
            traits::void_ptr(beta), traits::void_ptr(c), ldc );
#else
    BLAS_CHEMM( &side, &uplo, &m, &n, traits::complex_ptr(&alpha),
            traits::complex_ptr(a), &lda, traits::complex_ptr(b), &ldb,
            traits::complex_ptr(&beta), traits::complex_ptr(c), &ldc );
#endif
}

inline void hemm( const char side, const char uplo, const integer_t m,
        const integer_t n, const traits::complex_d alpha,
        const traits::complex_d* a, const integer_t lda,
        const traits::complex_d* b, const integer_t ldb,
        const traits::complex_d beta, traits::complex_d* c,
        const integer_t ldc ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_zhemm( CblasColMajor, ( uplo == 'L' ? CblasLeft : CblasRight ),
            ( uplo == 'U' ? CblasUpper : CblasLower ), m, n,
            traits::void_ptr(&alpha), traits::void_ptr(a), lda,
            traits::void_ptr(b), ldb, traits::void_ptr(&beta),
            traits::void_ptr(c), ldc );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    // NOT FOUND();
#else
    BLAS_ZHEMM( &side, &uplo, &m, &n, traits::complex_ptr(&alpha),
            traits::complex_ptr(a), &lda, traits::complex_ptr(b), &ldb,
            traits::complex_ptr(&beta), traits::complex_ptr(c), &ldc );
#endif
}


} // namespace detail

// value-type based template
template< typename ValueType >
struct hemm_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // static template member function
    template< typename MatrixA, typename MatrixB, typename MatrixC >
    static return_type invoke( const char side, const value_type alpha,
            const MatrixA& a, const MatrixB& b, const value_type beta,
            MatrixC& c ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixC >::value_type >::value) );
        detail::hemm( side, traits::matrix_uplo_tag(a),
                traits::matrix_num_rows(c), traits::matrix_num_columns(c),
                alpha, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(b),
                traits::leading_dimension(b), beta, traits::matrix_storage(c),
                traits::leading_dimension(c) );
    }
};

// generic template function to call hemm
template< typename MatrixA, typename MatrixB, typename MatrixC >
inline typename hemm_impl< typename traits::matrix_traits<
        MatrixA >::value_type >::return_type
hemm( const char side, const typename traits::matrix_traits<
        MatrixA >::value_type alpha, const MatrixA& a, const MatrixB& b,
        const typename traits::matrix_traits< MatrixA >::value_type beta,
        MatrixC& c ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    hemm_impl< value_type >::invoke( side, alpha, a, b, beta, c );
}

} // namespace blas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
