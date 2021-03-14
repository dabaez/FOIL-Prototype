#include<iostream>
#include<vector>
#include<random>
#include <fstream>
#include <ctime>

using namespace std;

mt19937 gen;
uniform_int_distribution<int> ranb(0,1);
uniform_int_distribution<int> rant(0,2);
uniform_int_distribution<int> rvar;

int lef,varn,fut,n;
bool con,sub;

ofstream out("input.txt");

void outc(){
	out<<" [ ";
	for (int i=0;i<n;i++){
        int cval = rant(gen);
        if (cval == 2) out<<" ? ";
        else out<<" "<<cval<<" ";
	}
    out<<" ] ";
}

void makeq(){

	bool neg = ( (fut + 2 <= lef) && ranb(gen) );

	if (neg){
		out<<" ~ ( ";
		lef--;
	}

	if ( fut == 0 && lef > 1 || ( fut + 2 <= lef && ranb(gen) ) ){
		out<<" ( ";
		fut++;
		makeq();
		out<<" ) ";
		if ( ranb(gen) ) out<<" v ";
		else out<<" ^ ";
		out<<" ( ";
		fut--;
		makeq();
		out<<" ) ";
	} else {
        //contencion
		if ( ((!con) && (!sub)) || ranb(gen)){
            int vn = rvar(gen);
            if ((!con) || vn){
                while (!vn) vn = rvar(gen);
                out<<" x"<<vn<<" ";
                if (!sub){
                    out<<" <= ";
                    outc();
                } else if (!con) {
                    vn = rvar(gen);
                    while (!vn) vn = rvar(gen);
                    out<<" <= x"<<vn<<" ";
                } else {
                    vn = rvar(gen);
                    out<<" <= ";
                    if (vn) out<<" x"<<vn<<" ";
                    else outc();
                }
            } else {
                outc();
                out<<" <= ";
                vn = rvar(gen);
                if (vn) out<<" x"<<vn<<" ";
                else outc();
            }
		} else { //evaluacion
			out<<" P( ";
			int vn = rvar(gen);
            if (!con)
                while (!vn)
                    vn = rvar(gen);
			if (vn) out<<" x"<<vn<<" ";
			else outc();
			out<<" ) ";
		}
	}

	if (neg) out<<" ) ";
}

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);

    cout<<"seed"<<endl;

   	int sneed;
	cin>>sneed;

	if (sneed == -1) gen = mt19937(time(0));
	else gen = mt19937(sneed);

    cout<<"Perceptron size"<<endl;

	cin>>n;
	out<<n<<'\n';

	uniform_real_distribution<double> dis(-100.0,100.0);
	vector<double> w(n);
	for (int i=0;i<n;i++){
		w[i] = dis(gen);
		out<<w[i]<<' ';
	}

	double b = dis(gen);
	out<<'\n'<<b<<'\n';

    
    cout<<"how many and how long"<<endl;
	int q,qs;
	cin>>q>>qs;

    cout<<"should x <= y appear?"<<endl;
    int ans;
    cin>>ans;
    sub = ans;

    cout<<"should constants appear?"<<endl;
    cin>>ans;
    con = ans;

	uniform_int_distribution<int> rnvar(1,qs/2);

	while (q--){

		varn = rnvar(gen);
		rvar = uniform_int_distribution<int>(0,varn);

        for (int i=1;i<=varn;i++){
			if (ranb(gen)) out<<"Exists x"<<i<<", ";
			else out<<"ForAll x"<<i<<", ";
        }

        lef = qs - varn;

        fut = 0;

        makeq();

        out<<"\n";
	}

	out<<"\n";

	return 0;
}