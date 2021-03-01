#include "FBDDsub.h"
#include <cassert>
#include <iostream>

int main(){
	
	FBDD f = sub(2);
	
	assert(f.predict({0,0,0,0,0,0,0,0}));
	assert(f.predict({0,0,0,0,0,0,0,1}));
	assert(f.predict({0,0,0,0,0,0,1,0}));
	assert(f.predict({0,0,0,0,0,1,0,0}));
	assert(f.predict({0,0,0,0,0,1,0,1}));
	assert(f.predict({0,0,0,0,0,1,1,0}));
	assert(f.predict({0,0,0,0,1,0,0,0}));
	assert(f.predict({0,0,0,0,1,0,0,1}));
	assert(f.predict({0,0,0,0,1,0,1,0}));
	
	assert(not f.predict({0,1,0,0,0,0,0,0}));
	assert(not f.predict({0,1,0,0,0,0,0,1}));
	assert(not f.predict({0,1,0,0,0,0,1,0}));
	assert(f.predict({0,1,0,0,0,1,0,0}));
	assert(f.predict({0,1,0,0,0,1,0,1}));
	assert(f.predict({0,1,0,0,0,1,1,0}));
	assert(not f.predict({0,1,0,0,1,0,0,0}));
	assert(not f.predict({0,1,0,0,1,0,0,1}));
	assert(not f.predict({0,1,0,0,1,0,1,0}));
	
	assert(not f.predict({0,0,0,1,0,0,0,0}));
	assert(f.predict({0,0,0,1,0,0,0,1}));
	assert(not f.predict({0,0,0,1,0,0,1,0}));
	assert(not f.predict({0,0,0,1,0,1,0,0}));
	assert(f.predict({0,0,0,1,0,1,0,1}));
	assert(not f.predict({0,0,0,1,0,1,1,0}));
	assert(not f.predict({0,0,0,1,1,0,0,0}));
	assert(f.predict({0,0,0,1,1,0,0,1}));
	assert(not f.predict({0,0,0,1,1,0,1,0}));
	
	assert(not f.predict({0,1,0,1,0,0,0,0}));
	assert(not f.predict({0,1,0,1,0,0,0,1}));
	assert(not f.predict({0,1,0,1,0,0,1,0}));
	assert(not f.predict({0,1,0,1,0,1,0,0}));
	assert(f.predict({0,1,0,1,0,1,0,1}));
	assert(not f.predict({0,1,0,1,0,1,1,0}));
	assert(not f.predict({0,1,0,1,1,0,0,0}));
	assert(not f.predict({0,1,0,1,1,0,0,1}));
	assert(not f.predict({0,1,0,1,1,0,1,0}));
	
	std::cout<<"FINISHED\n";
}
