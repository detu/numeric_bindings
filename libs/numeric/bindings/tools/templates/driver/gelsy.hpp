$TEMPLATE[gelsy.all.min_size_work.args]
M,N,NRHS
$TEMPLATE[gelsy.real.min_size_work]
integer_t minmn = std::min( m, n );
return std::max( 1, std::max( minmn+3*n+1, 2*minmn+nrhs ));
$TEMPLATE[gelsy.complex.min_size_work]
integer_t minmn = std::min( m, n );
return std::max( 1, std::max( std::max( 2*minmn, n+1 ), minmn+nrhs ) );
$TEMPLATE[end]
