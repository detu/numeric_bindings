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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HPEVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HPEVX_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
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
    inline void hpevx( char const jobz, char const range, char const uplo,
            integer_t const n, traits::complex_f* ap, float const vl,
            float const vu, integer_t const il, integer_t const iu,
            float const abstol, integer_t& m, float* w, traits::complex_f* z,
            integer_t const ldz, traits::complex_f* work, float* rwork,
            integer_t* iwork, integer_t* ifail, integer_t& info ) {
        LAPACK_CHPEVX( &jobz, &range, &uplo, &n, traits::complex_ptr(ap), &vl,
                &vu, &il, &iu, &abstol, &m, w, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), rwork, iwork, ifail, &info );
    }
    inline void hpevx( char const jobz, char const range, char const uplo,
            integer_t const n, traits::complex_d* ap, double const vl,
            double const vu, integer_t const il, integer_t const iu,
            double const abstol, integer_t& m, double* w,
            traits::complex_d* z, integer_t const ldz,
            traits::complex_d* work, double* rwork, integer_t* iwork,
            integer_t* ifail, integer_t& info ) {
        LAPACK_ZHPEVX( &jobz, &range, &uplo, &n, traits::complex_ptr(ap), &vl,
                &vu, &il, &iu, &abstol, &m, w, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), rwork, iwork, ifail, &info );
    }
}

// value-type based template
template< typename ValueType >
struct hpevx_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

$INCLUDE_TEMPLATES
    // user-defined workspace specialization
    template< typename MatrixAP, typename VectorW, typename MatrixZ,
            typename VectorIFAIL, typename WORK, typename RWORK,
            typename IWORK >
    static void invoke( char const jobz, char const range, integer_t const n,
            MatrixAP& ap, real_type const vl, real_type const vu,
            integer_t const il, integer_t const iu, real_type const abstol,
            integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
            integer_t& info, detail::workspace3< WORK, RWORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( range == 'A' || range == 'V' || range == 'I' );
        BOOST_ASSERT( traits::matrix_uplo_tag(ap) == 'U' ||
                traits::matrix_uplo_tag(ap) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n ));
        detail::hpevx( jobz, range, traits::matrix_uplo_tag(ap), n,
                traits::matrix_storage(ap), vl, vu, il, iu, abstol, m,
                traits::vector_storage(w), traits::matrix_storage(z),
                traits::leading_dimension(z),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_storage(ifail), info );
    }

    // minimal workspace specialization
    template< typename MatrixAP, typename VectorW, typename MatrixZ,
            typename VectorIFAIL >
    static void invoke( char const jobz, char const range, integer_t const n,
            MatrixAP& ap, real_type const vl, real_type const vu,
            integer_t const il, integer_t const iu, real_type const abstol,
            integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        invoke( jobz, range, n, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
                info, workspace( tmp_work, tmp_rwork, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAP, typename VectorW, typename MatrixZ,
            typename VectorIFAIL >
    static void invoke( char const jobz, char const range, integer_t const n,
            MatrixAP& ap, real_type const vl, real_type const vu,
            integer_t const il, integer_t const iu, real_type const abstol,
            integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
            integer_t& info, optimal_workspace work ) {
        invoke( jobz, range, n, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
                info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return 2*n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return 7*n;
    }

    static integer_t min_size_iwork( integer_t const n ) {
        return 5*n;
    }
};


// template function to call hpevx
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline integer_t hpevx( char const jobz, char const range,
        integer_t const n, MatrixAP& ap, typename traits::matrix_traits<
        MatrixAP >::value_type const vl, typename traits::matrix_traits<
        MatrixAP >::value_type const vu, integer_t const il,
        integer_t const iu, typename traits::matrix_traits<
        MatrixAP >::value_type const abstol, integer_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    hpevx_impl< value_type >::invoke( jobz, range, n, ap, vl, vu, il, iu,
            abstol, m, w, z, ifail, info, work );
    return info;
}

// template function to call hpevx, default workspace type
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline integer_t hpevx( char const jobz, char const range,
        integer_t const n, MatrixAP& ap, typename traits::matrix_traits<
        MatrixAP >::value_type const vl, typename traits::matrix_traits<
        MatrixAP >::value_type const vu, integer_t const il,
        integer_t const iu, typename traits::matrix_traits<
        MatrixAP >::value_type const abstol, integer_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    hpevx_impl< value_type >::invoke( jobz, range, n, ap, vl, vu, il, iu,
            abstol, m, w, z, ifail, info, optimal_workspace() );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
