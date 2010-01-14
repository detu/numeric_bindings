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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GELS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_GELS_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_complex.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/is_real.hpp>
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
#include <boost/utility/enable_if.hpp>

//
// The LAPACK-backend for gels is the netlib-compatible backend.
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
// * float value-type.
//
template< typename Trans >
inline std::ptrdiff_t gels( Trans, const fortran_int_t m,
        const fortran_int_t n, const fortran_int_t nrhs, float* a,
        const fortran_int_t lda, float* b, const fortran_int_t ldb,
        float* work, const fortran_int_t lwork ) {
    fortran_int_t info(0);
    LAPACK_SGELS( &lapack_option< Trans >::value, &m, &n, &nrhs, a, &lda, b,
            &ldb, work, &lwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
template< typename Trans >
inline std::ptrdiff_t gels( Trans, const fortran_int_t m,
        const fortran_int_t n, const fortran_int_t nrhs, double* a,
        const fortran_int_t lda, double* b, const fortran_int_t ldb,
        double* work, const fortran_int_t lwork ) {
    fortran_int_t info(0);
    LAPACK_DGELS( &lapack_option< Trans >::value, &m, &n, &nrhs, a, &lda, b,
            &ldb, work, &lwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<float> value-type.
//
template< typename Trans >
inline std::ptrdiff_t gels( Trans, const fortran_int_t m,
        const fortran_int_t n, const fortran_int_t nrhs,
        std::complex<float>* a, const fortran_int_t lda,
        std::complex<float>* b, const fortran_int_t ldb,
        std::complex<float>* work, const fortran_int_t lwork ) {
    fortran_int_t info(0);
    LAPACK_CGELS( &lapack_option< Trans >::value, &m, &n, &nrhs, a, &lda, b,
            &ldb, work, &lwork, &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * complex<double> value-type.
//
template< typename Trans >
inline std::ptrdiff_t gels( Trans, const fortran_int_t m,
        const fortran_int_t n, const fortran_int_t nrhs,
        std::complex<double>* a, const fortran_int_t lda,
        std::complex<double>* b, const fortran_int_t ldb,
        std::complex<double>* work, const fortran_int_t lwork ) {
    fortran_int_t info(0);
    LAPACK_ZGELS( &lapack_option< Trans >::value, &m, &n, &nrhs, a, &lda, b,
            &ldb, work, &lwork, &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to gels.
//
template< typename Value, typename Enable = void >
struct gels_impl {};

//
// This implementation is enabled if Value is a real type.
//
template< typename Value >
struct gels_impl< Value, typename boost::enable_if< is_real< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename WORK >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, detail::workspace1<
            WORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        BOOST_ASSERT( bindings::size(work.select(real_type())) >=
                min_size_work( bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()),
                bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size_column(b) >= 0 );
        BOOST_ASSERT( bindings::size_column_op(a, trans()) >= 0 );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_row_op(a, trans()) >= 0 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                bindings::size_row_op(a, trans())) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                std::max< std::ptrdiff_t >(bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()))) );
        return detail::gels( trans(), bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b),
                bindings::begin_value(work.select(real_type())),
                bindings::size(work.select(real_type())) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixA, typename MatrixB >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b,
            minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        bindings::detail::array< real_type > tmp_work( min_size_work(
                bindings::size_row_op(a, trans()), bindings::size_column_op(a,
                trans()), bindings::size_column(b) ) );
        return invoke( a, b, workspace( tmp_work ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixA, typename MatrixB >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b,
            optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        real_type opt_size_work;
        detail::gels( trans(), bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), &opt_size_work, -1 );
        bindings::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        return invoke( a, b, workspace( tmp_work ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t m,
            const std::ptrdiff_t n, const std::ptrdiff_t nrhs ) {
        integer_t minmn = std::min< std::ptrdiff_t >( m, n );
        return std::max< std::ptrdiff_t >( 1, minmn + std::max<
                std::ptrdiff_t >( minmn, nrhs ) );
    }
};

//
// This implementation is enabled if Value is a complex type.
//
template< typename Value >
struct gels_impl< Value, typename boost::enable_if< is_complex< Value > >::type > {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixA, typename MatrixB, typename WORK >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b, detail::workspace1<
            WORK > work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixA >::type >::type,
                typename remove_const< typename value<
                MatrixB >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixA >::value) );
        BOOST_STATIC_ASSERT( (bindings::is_mutable< MatrixB >::value) );
        BOOST_ASSERT( bindings::size(work.select(value_type())) >=
                min_size_work( bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()),
                bindings::size_column(b) ));
        BOOST_ASSERT( bindings::size_column(b) >= 0 );
        BOOST_ASSERT( bindings::size_column_op(a, trans()) >= 0 );
        BOOST_ASSERT( bindings::size_minor(a) == 1 ||
                bindings::stride_minor(a) == 1 );
        BOOST_ASSERT( bindings::size_minor(b) == 1 ||
                bindings::stride_minor(b) == 1 );
        BOOST_ASSERT( bindings::size_row_op(a, trans()) >= 0 );
        BOOST_ASSERT( bindings::stride_major(a) >= std::max< std::ptrdiff_t >(1,
                bindings::size_row_op(a, trans())) );
        BOOST_ASSERT( bindings::stride_major(b) >= std::max< std::ptrdiff_t >(1,
                std::max< std::ptrdiff_t >(bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()))) );
        return detail::gels( trans(), bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b),
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
    template< typename MatrixA, typename MatrixB >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b,
            minimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        bindings::detail::array< value_type > tmp_work( min_size_work(
                bindings::size_row_op(a, trans()), bindings::size_column_op(a,
                trans()), bindings::size_column(b) ) );
        return invoke( a, b, workspace( tmp_work ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixA, typename MatrixB >
    static std::ptrdiff_t invoke( MatrixA& a, MatrixB& b,
            optimal_workspace work ) {
        namespace bindings = ::boost::numeric::bindings;
        typedef typename result_of::trans_tag< MatrixA, order >::type trans;
        value_type opt_size_work;
        detail::gels( trans(), bindings::size_row_op(a, trans()),
                bindings::size_column_op(a, trans()),
                bindings::size_column(b), bindings::begin_value(a),
                bindings::stride_major(a), bindings::begin_value(b),
                bindings::stride_major(b), &opt_size_work, -1 );
        bindings::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        return invoke( a, b, workspace( tmp_work ) );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t m,
            const std::ptrdiff_t n, const std::ptrdiff_t nrhs ) {
        integer_t minmn = std::min< std::ptrdiff_t >( m, n );
        return std::max< std::ptrdiff_t >( 1, minmn + std::max<
                std::ptrdiff_t >( minmn, nrhs ) );
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the gels_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for gels. Its overload differs for
// * MatrixA&
// * MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gels( MatrixA& a, MatrixB& b, Workspace work ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            work );
}

//
// Overloaded function for gels. Its overload differs for
// * MatrixA&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
gels( MatrixA& a, MatrixB& b ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            optimal_workspace() );
}

//
// Overloaded function for gels. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gels( const MatrixA& a, MatrixB& b, Workspace work ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            work );
}

//
// Overloaded function for gels. Its overload differs for
// * const MatrixA&
// * MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
gels( const MatrixA& a, MatrixB& b ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            optimal_workspace() );
}

//
// Overloaded function for gels. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gels( MatrixA& a, const MatrixB& b, Workspace work ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            work );
}

//
// Overloaded function for gels. Its overload differs for
// * MatrixA&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
gels( MatrixA& a, const MatrixB& b ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            optimal_workspace() );
}

//
// Overloaded function for gels. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * User-defined workspace
//
template< typename MatrixA, typename MatrixB, typename Workspace >
inline typename boost::enable_if< detail::is_workspace< Workspace >,
        std::ptrdiff_t >::type
gels( const MatrixA& a, const MatrixB& b, Workspace work ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            work );
}

//
// Overloaded function for gels. Its overload differs for
// * const MatrixA&
// * const MatrixB&
// * Default workspace-type (optimal)
//
template< typename MatrixA, typename MatrixB >
inline typename boost::disable_if< detail::is_workspace< MatrixB >,
        std::ptrdiff_t >::type
gels( const MatrixA& a, const MatrixB& b ) {
    return gels_impl< typename value< MatrixA >::type >::invoke( a, b,
            optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
