#include "FBDDsub.h"

FBDD sub(int size){
	
	std::shared_ptr<FNode> croot = std::make_shared<FNode>(); croot->setLabel(0);
	FBDD ans(croot);
	
	for (int i=0;i<size;i++){
		
		std::shared_ptr<FNode> l = std::make_shared<FNode>(); l->setLabel( 2*i+1 );
		std::shared_ptr<FNode> lr = std::make_shared<FNode>(); lr->setLabel( 2*size + 2*i );
		std::shared_ptr<FNode> lrl = std::make_shared<FNode>(); lrl->setLabel( 2*size + 2*i + 1 );
		std::shared_ptr<FNode> r = std::make_shared<FNode>(); r->setLabel( 2*size + 2*i );
		std::shared_ptr<FNode> rr = std::make_shared<FNode>(); rr->setLabel( 2*i + 1 );
		std::shared_ptr<FNode> rrl = std::make_shared<FNode>(); rrl->setLabel( 2*size + 2*i + 1 );
		std::shared_ptr<FNode> nroot;
		
		if ( i == size-1 ){
			nroot = FNode::TRUE;
		} else {
			nroot = std::make_shared<FNode>();
			nroot->setLabel( 2*(i+1) );
		}
		
		croot->setLeft(l);
		croot->setRight(r);
		
		l->setLeft(nroot);
		l->setRight(lr);
		
		lr->setLeft(lrl);
		lr->setRight(FNode::FALSE);
		
		lrl->setLeft(FNode::FALSE);
		lrl->setRight(nroot);
		
		r->setLeft(FNode::FALSE);
		r->setRight(rr);
		
		rr->setLeft(rrl);
		rr->setRight(FNode::FALSE);
		
		rrl->setLeft(nroot);
		rrl->setRight(FNode::FALSE);
		
		croot = nroot;
		
	}
	
	return ans;
		
}
