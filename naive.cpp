#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

typedef long long ll;

vector<string> query;
map< string , vector<int> > vars;
vector<double> w;
int n,ix = 0;
double b;

ll fastpow(ll a,ll b){
	ll ans = 1;
	while (b){
		if (b&1) ans*=a;
		b>>=1;
        a = a*a;
	}
	return ans;
}
bool eval(){

	//cuantificadores
    if ( query[ix] == "Exists" || query[ix] == "ForAll"){

		bool exists = (query[ix] == "Exists");

    	string var = query[ix+1].substr( 0 , query[ix+1].size() - 1 );

    	ix += 2;

    	int six = ix;

    	ll combs = fastpow(3,n);

        for (ll i = 0 ; i < combs ; i++ ){

			ix = six;

			vector<int> pos(n);

			ll ci = i;
			for (int j=0;j<n;j++){
				pos[j] = ci%3 - 1;
				ci/=3;
			}

			vars[ var ] = pos;

			if (eval() == exists) return exists;

        }

        return !exists;
    }

    //no
    if ( query[ix] == "~" ){
		ix++;
		return !eval();
    }

    // y/o
    if ( query[ix] == "(" && !( isdigit(query[ix+1][0]) || query[ix+1][0] == '?' ) ){

    	ix++;
		bool A = eval();

		ix+=2;
		string op = query[ix];

		ix+=2;
		bool B = eval();
		ix++;

		if (op == "v") return A || B;
		if (op == "^") return A && B;
    }

    //evaluar
    if ( query[ix] == "P(" ){

        ix++;
        if (query[ix] == "("){ //constante

        	ix++;
        	double ceval = 0;
            for (int i=0;i<n;i++) ceval += (query[ix+i][0] - '0') * w[i];

            ix += n;
            return ceval >= -b;

        } else { //variable

        	vector<int> cvar = vars[query[ix]];
        	double ceval = 0;
        	for (int i=0;i<n;i++){
				if (cvar[i] != -1) ceval += cvar[i] * w[i];
				else if (w[i] > 0) ceval += w[i];
        	}

        	ix+=2;
        	return ceval >= -b;

        }

    }

    //c <= x
    if (query[ix] == "(" ){

		ix++;
        vector<int> con(n);
        for (int i=0;i<n;i++){
			if (query[ix+i] == "?") con[i] = -1;
			else con[i] = query[ix+i][0] - '0';
        }
        ix+=n+2;

        vector<int> var = vars[ query[ix] ];

        bool ok = true;

        for (int i=0;i<n && ok;i++){
            if ( con[i] != var[i] && con[i] != -1 ) ok = false;
        }

        return ok;

    } else { // x <= c

    	vector<int> var = vars[ query[ix] ];
    	ix += 3;

    	vector<int> con(n);
        for (int i=0;i<n;i++){
			if (query[ix+i] == "?") con[i] = -1;
			else con[i] = query[ix+i][0] - '0';
        }
        ix+=n;

        bool ok = true;
        for (int i=0;i<n && ok;i++){
            if ( con[i] != var[i] && var[i] != -1 ) ok = false;
        }
        return ok;
    }
}

int main(){

	ifstream cin("input.txt");
    //ofstream cout("output.txt");

	cout<<"Tamaño de perceptron"<<endl;
	cin>>n;

	cout<<"Vector w"<<endl;
	w.resize(n);
	for (int i=0;i<n;i++) cin>>w[i];

	cout<<"Real b"<<endl;
	cin>>b;

	cout<<"consultas se terminan con /"<<endl;
	string q;
	while ( cin>>q , q != "/" ){

		query.clear();
		vars.clear();

        while (q != "/"){
			query.push_back(q);
			cin>>q;
        }

        ix = 0;

        if ( eval() ) cout<<"True"<<endl;
        else cout<<"False"<<endl;
	}

}
