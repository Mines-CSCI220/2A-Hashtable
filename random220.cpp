/*
 * random220.cpp
 * khellman@mines.edu, see random220.h for documentation.
 *
*/

#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <chrono>

#include "random220.h"

static double prng()
{
	return rand()/double(RAND_MAX);
}

unsigned long seed_now()
{
	using std::chrono::system_clock;
	unsigned long seed = system_clock::to_time_t( system_clock::now() ); 
	srand( seed );
	std::cerr << "seed_now " << seed << std::endl; 
	return seed;
}

bool bernoulli( const double p )
{
	// compilicated stuff, eh?
	assert( 0<= p );
	assert( p<= 1 );
	return prng() < p;
}

bool coinflip( ) { return bernoulli(0.5); }

double uniform( const double a, const double b )
{
	assert( a<=b );
	return a + prng()*(b-a);
}

long equalikely( const long a, const long b )
{
	assert( a<=b );
	return ::floor( uniform(a,b+1));
}

template<typename T>
void fisher_yates( std::vector<T>& v, size_t count )
{
	// fisher yates 
	for( size_t i=0; i<v.size()-1 && count!=0; ++i ) {
		T hold(v[i]);
		size_t to = equalikely(i,v.size()-1);
		v[i] = v[to];
		v[to] = hold;
		--count;
	}
}
