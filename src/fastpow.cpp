#include "fastpow.h"

long long fastpow(long long a,long long b){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a;
		b>>=1;
		a *= a;
	}
	return ans;
}
