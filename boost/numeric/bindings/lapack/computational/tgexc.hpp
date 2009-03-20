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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TGEXC_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_TGEXC_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void tgexc( logical_t const wantq, logical_t const wantz,
            integer_t const n, float* a, integer_t const lda, float* b,
            integer_t const ldb, float* q, integer_t const ldq, float* z,
            integer_t const ldz, integer_t& ifst, integer_t& ilst,
            float* work, integer_t const lwork, integer_t& info ) {
        LAPACK_STGEXC( &wantq, &wantz, &n, a, &lda, b, &ldb, q, &ldq, z, &ldz,
                &ifst, &ilst, work, &lwork, &info );
    }
    inline void tgexc( logical_t const wantq, logical_t const wantz,
            integer_t const n, double* a, integer_t const lda, double* b,
            integer_t const ldb, double* q, integer_t const ldq, double* z,
            integer_t const ldz, integer_t& ifst, integer_t& ilst,
            double* work, integer_t const lwork, integer_t& info ) {
        LAPACK_DTGEXC( &wantq, &wantz, &n, a, &lda, b, &ldb, q, &ldq, z, &ldz,
                &ifst, &ilst, work, &lwork, &info );
    }
    inline void tgexc( logical_t const wantq, logical_t const wantz,
            integer_t const n, traits::complex_f* a, integer_t const lda,
            traits::complex_f* b, integer_t const ldb, traits::complex_f* q,
            integer_t const ldq, traits::complex_f* z, integer_t const ldz,
            integer_t const ifst, integer_t& ilst, integer_t& info ) {
        LAPACK_CTGEXC( &wantq, &wantz, &n, traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(q), &ldq,
                traits::complex_ptr(z), &ldz, &ifst, &ilst, &info );
    }
    inline void tgexc( logical_t const wantq, logical_t const wantz,
            integer_t const n, traits::complex_d* a, integer_t const lda,
            traits::complex_d* b, integer_t const ldb, traits::complex_d* q,
            integer_t const ldq, traits::complex_d* z, integer_t const ldz,
            integer_t const ifst, integer_t& ilst, integer_t& info ) {
        LAPACK_ZTGEXC( &wantq, &wantz, &n, traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(q), &ldq,
                traits::complex_ptr(z), &ldz, &ifst, &ilst, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct tgexc_impl{};

// real specialization
template< typename ValueType >
struct tgexc_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

$INCLUDE_TEMPLATES
    // templated specialization
    template< typename MatrixA, typename MatrixB, typename MatrixQ,
            typename MatrixZ >
    static void invoke( logical_t const wantq, logical_t const wantz,
            integer_t const n, MatrixA& a, MatrixB& b, MatrixQ& q, MatrixZ& z,
            integer_t& ifst, integer_t& ilst, integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixQ >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( $CALL_MIN_SIZE ));
        detail::tgexc( wantq, wantz, n, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::matrix_storage(q),
                traits::leading_dimension(q), traits::matrix_storage(z),
                traits::leading_dimension(z), ifst, ilst,
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())), info );
    }
};

// complex specialization
template< typename ValueType >
struct tgexc_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

$INCLUDE_TEMPLATES
    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename MatrixQ,
            typename MatrixZ, $WORKSPACE_TYPENAMES >
    static void invoke( logical_t const wantq, logical_t const wantz,
            integer_t const n, MatrixA& a, MatrixB& b, MatrixQ& q, MatrixZ& z,
            integer_t const ifst, integer_t& ilst, integer_t& info,
            detail::workspace$WORKSPACE_SIZE< $WORKSPACE_TYPES > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixQ >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max(1,n) );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max(1,n) );
        detail::tgexc( wantq, wantz, n, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::matrix_storage(q),
                traits::leading_dimension(q), traits::matrix_storage(z),
                traits::leading_dimension(z), ifst, ilst, info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename MatrixQ,
            typename MatrixZ >
    static void invoke( logical_t const wantq, logical_t const wantz,
            integer_t const n, MatrixA& a, MatrixB& b, MatrixQ& q, MatrixZ& z,
            integer_t const ifst, integer_t& ilst, integer_t& info,
            minimal_workspace work ) {
$SETUP_MIN_WORKARRAYS_POST
        invoke( wantq, wantz, n, a, b, q, z, ifst, ilst, info,
                workspace( $TMP_WORKARRAYS ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename MatrixQ,
            typename MatrixZ >
    static void invoke( logical_t const wantq, logical_t const wantz,
            integer_t const n, MatrixA& a, MatrixB& b, MatrixQ& q, MatrixZ& z,
            integer_t const ifst, integer_t& ilst, integer_t& info,
            optimal_workspace work ) {
$OPT_WORKSPACE_FUNC
    }

$MIN_SIZE_FUNCS
};


// template function to call tgexc
template< typename MatrixA, typename MatrixB, typename MatrixQ,
        typename MatrixZ >
inline integer_t tgexc( logical_t const wantq, logical_t const wantz,
        integer_t const n, MatrixA& a, MatrixB& b, MatrixQ& q, MatrixZ& z,
        integer_t& ifst, integer_t& ilst ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    tgexc_impl< value_type >::invoke( wantq, wantz, n, a, b, q, z, ifst,
            ilst, info );
    return info;
}
// template function to call tgexc
template< typename MatrixA, typename MatrixB, typename MatrixQ,
        typename MatrixZ, typename Workspace >
inline integer_t tgexc( logical_t const wantq, logical_t const wantz,
        integer_t const n, MatrixA& a, MatrixB& b, MatrixQ& q, MatrixZ& z,
        integer_t const ifst, integer_t& ilst, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    tgexc_impl< value_type >::invoke( wantq, wantz, n, a, b, q, z, ifst,
            ilst, info, work );
    return info;
}

// template function to call tgexc, default workspace type
template< typename MatrixA, typename MatrixB, typename MatrixQ,
        typename MatrixZ >
inline integer_t tgexc( logical_t const wantq, logical_t const wantz,
        integer_t const n, MatrixA& a, MatrixB& b, MatrixQ& q, MatrixZ& z,
        integer_t const ifst, integer_t& ilst ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    tgexc_impl< value_type >::invoke( wantq, wantz, n, a, b, q, z, ifst,
            ilst, info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
