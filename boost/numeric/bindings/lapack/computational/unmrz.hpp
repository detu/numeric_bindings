//
// Copyright (c) 2002--2010
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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNMRZ_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_UNMRZ_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/trans_tag.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for unmrz is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
template< typename Trans >
inline std::ptrdiff_t unmrz( const char side, Trans, const fortran_int_t m,
        const fortran_int_t n, const fortran_int_t k, const fortran_int_t l,
        const std::complex<float>* a, const fortran_int_t lda,
        const std::complex<float>* tau, std::complex<float>* c,
        const fortran_int_t ldc, std::complex<float>* work,
        const fortran_int_t lwork ) {
    fortran_int_t info(0);
    LAPACK_CUNMRZ( &side, &lapack_option< Trans >::value, &m, &n, &k, &l, a,
            &lda, tau, c, &ldc, work, &lwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename Trans >
inline std::ptrdiff_t unmrz( const char side, Trans, const fortran_int_t m,
        const fortran_int_t n, const fortran_int_t k, const fortran_int_t l,
        const std::complex<double>* a, const fortran_int_t lda,
        const std::complex<double>* tau, std::complex<double>* c,
        const fortran_int_t ldc, std::complex<double>* work,
        const fortran_int_t lwork ) {
    fortran_int_t info(0);
    LAPACK_ZUNMRZ( &side, &lapack_option< Trans >::value, &m, &n, &k, &l, a,
            &lda, tau, c, &ldc, work, &lwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to unmrz.
//
template< typename Value >
struct unmrz_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename VectorTAU, typename MatrixC,
            typename WORK >
    static std::ptrdiff_t invoke( const char side, const fortran_int_t k,
            const MatrixA& a, const VectorTAU& tau, MatrixC& c,
            detail::workspace1< WORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                VectorTAU >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                MatrixC >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixC >::value) );
        BOOST_ASSERT( bindings::size(tau) >= k );
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( $CALL_MIN_SIZE ));
        BOOST_ASSERT( bindings::size_column(c) >= 0 );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(c) == 1 ||
                bindings::stride_minor(c) == 1 );
        BOOST_ASSERT( bindings::size_row(c) >= 0 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                k) );
        BOOST_ASSERT( bindings::stride_major(c) >= std::max< std::ptrdiff_t >(1,
                bindings::size_row(c)) );
        BOOST_ASSERT( side == 'L' || side == 'R' );
        return detail::unmrz( side, trans(), bindings::size_row(c),
                bindings::size_column(c), k, bindings::size_column_op(a,
                trans()), bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(tau), bindings::begin_value(c),
                bindings::stride_major(c),
                bindings::begin_value(work.select(value_type())),
                bindings::size(work.select(value_type())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixA, typename VectorTAU, typename MatrixC >
    static std::ptrdiff_t invoke( const char side, const fortran_int_t k,
            const MatrixA& a, const VectorTAU& tau, MatrixC& c,
            minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                $CALL_MIN_SIZE ) );
        return invoke( side, k, a, tau, c, workspace( tmp_work ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixA, typename VectorTAU, typename MatrixC >
    static std::ptrdiff_t invoke( const char side, const fortran_int_t k,
            const MatrixA& a, const VectorTAU& tau, MatrixC& c,
            optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        value_type opt_size_work;
        detail::unmrz( side, trans(), bindings::size_row(c),
                bindings::size_column(c), k, bindings::size_column_op(a,
                trans()), bindings::begin_value(a), bindings::stride_major(a),
                bindings::begin_value(tau), bindings::begin_value(c),
                bindings::stride_major(c), &opt_size_work, -1 );
        bindings::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        return invoke( side, k, a, tau, c, workspace( tmp_work ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( $ARGUMENTS ) {
        $MIN_SIZE
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the unmrz_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for unmrz. Its overload differs for
// * MatrixC&
// * User-defined workspace
//
template< typename MatrixA, typename VectorTAU, typename MatrixC,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
unmrz( const char side, const fortran_int_t k, const MatrixA& a,
        const VectorTAU& tau, MatrixC& c, Workspace work ) {
    return unmrz_impl< typename value< MatrixA >::type >::invoke( side,
            k, a, tau, c, work );
}

//
// Overloaded function for unmrz. Its overload differs for
// * MatrixC&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename VectorTAU, typename MatrixC >
inline typename boost::disable_if< detail::is_workspace< MatrixC >,
        std::ptrdiff_t >::type
unmrz( const char side, const fortran_int_t k, const MatrixA& a,
        const VectorTAU& tau, MatrixC& c ) {
    return unmrz_impl< typename value< MatrixA >::type >::invoke( side,
            k, a, tau, c, optimal_workspace() );
}

//
// Overloaded function for unmrz. Its overload differs for
// * const MatrixC&
// * User-defined workspace
//
template< typename MatrixA, typename VectorTAU, typename MatrixC,
        typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
unmrz( const char side, const fortran_int_t k, const MatrixA& a,
        const VectorTAU& tau, const MatrixC& c, Workspace work ) {
    return unmrz_impl< typename value< MatrixA >::type >::invoke( side,
            k, a, tau, c, work );
}

//
// Overloaded function for unmrz. Its overload differs for
// * const MatrixC&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename VectorTAU, typename MatrixC >
inline typename boost::disable_if< detail::is_workspace< MatrixC >,
        std::ptrdiff_t >::type
unmrz( const char side, const fortran_int_t k, const MatrixA& a,
        const VectorTAU& tau, const MatrixC& c ) {
    return unmrz_impl< typename value< MatrixA >::type >::invoke( side,
            k, a, tau, c, optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
