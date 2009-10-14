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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_TBSV_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_TBSV_HPP

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

inline void tbsv( const char uplo, const char trans, const char diag,
        const integer_t n, const integer_t k, const float* a,
        const integer_t lda, float* x, const integer_t incx ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_stbsv( CblasColMajor, ( uplo == 'U' ? CblasUpper : CblasLower ),
            ( trans == 'N' ? CblasNoTrans : ( trans == 'T' ? CblasTrans : CblasConjTrans ) ),
            ( uplo == 'N' ? CblasNonUnit : CblasUnit ), n, k, a, lda, x,
            incx );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    cublasStbsv( uplo, trans, diag, n, k, a, lda, x, incx );
#else
    BLAS_STBSV( &uplo, &trans, &diag, &n, &k, a, &lda, x, &incx );
#endif
}

inline void tbsv( const char uplo, const char trans, const char diag,
        const integer_t n, const integer_t k, const double* a,
        const integer_t lda, double* x, const integer_t incx ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_dtbsv( CblasColMajor, ( uplo == 'U' ? CblasUpper : CblasLower ),
            ( trans == 'N' ? CblasNoTrans : ( trans == 'T' ? CblasTrans : CblasConjTrans ) ),
            ( uplo == 'N' ? CblasNonUnit : CblasUnit ), n, k, a, lda, x,
            incx );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    // NOT FOUND();
#else
    BLAS_DTBSV( &uplo, &trans, &diag, &n, &k, a, &lda, x, &incx );
#endif
}

inline void tbsv( const char uplo, const char trans, const char diag,
        const integer_t n, const integer_t k, const traits::complex_f* a,
        const integer_t lda, traits::complex_f* x, const integer_t incx ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_ctbsv( CblasColMajor, ( uplo == 'U' ? CblasUpper : CblasLower ),
            ( trans == 'N' ? CblasNoTrans : ( trans == 'T' ? CblasTrans : CblasConjTrans ) ),
            ( uplo == 'N' ? CblasNonUnit : CblasUnit ), n, k,
            traits::void_ptr(a), lda, traits::void_ptr(x), incx );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    cublasCtbsv( uplo, trans, diag, n, k, traits::void_ptr(a), lda,
            traits::void_ptr(x), incx );
#else
    BLAS_CTBSV( &uplo, &trans, &diag, &n, &k, traits::complex_ptr(a), &lda,
            traits::complex_ptr(x), &incx );
#endif
}

inline void tbsv( const char uplo, const char trans, const char diag,
        const integer_t n, const integer_t k, const traits::complex_d* a,
        const integer_t lda, traits::complex_d* x, const integer_t incx ) {
#if defined BOOST_NUMERIC_BINDINGS_BLAS_CBLAS
    cblas_ztbsv( CblasColMajor, ( uplo == 'U' ? CblasUpper : CblasLower ),
            ( trans == 'N' ? CblasNoTrans : ( trans == 'T' ? CblasTrans : CblasConjTrans ) ),
            ( uplo == 'N' ? CblasNonUnit : CblasUnit ), n, k,
            traits::void_ptr(a), lda, traits::void_ptr(x), incx );
#elif defined BOOST_NUMERIC_BINDINGS_BLAS_CUBLAS
    // NOT FOUND();
#else
    BLAS_ZTBSV( &uplo, &trans, &diag, &n, &k, traits::complex_ptr(a), &lda,
            traits::complex_ptr(x), &incx );
#endif
}


} // namespace detail

// value-type based template
template< typename ValueType >
struct tbsv_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // static template member function
    template< typename MatrixA, typename VectorX >
    static return_type invoke( const char trans, const char diag,
            const integer_t k, const MatrixA& a, VectorX& x ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorX >::value_type >::value) );
        detail::tbsv( traits::matrix_uplo_tag(a), trans, diag,
                traits::matrix_num_columns(a), k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(x),
                traits::vector_stride(x) );
    }
};

// generic template function to call tbsv
template< typename MatrixA, typename VectorX >
inline typename tbsv_impl< typename traits::matrix_traits<
        MatrixA >::value_type >::return_type
tbsv( const char trans, const char diag, const integer_t k,
        const MatrixA& a, VectorX& x ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    tbsv_impl< value_type >::invoke( trans, diag, k, a, x );
}

} // namespace blas
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
