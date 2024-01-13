#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
#define fi first
#define se second
#define endl '\n'
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const bool DC=0;
const ll mod=0;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
void NO(){cout<<"NO\n";}
void YES(){cout<<"YES\n";}
mt19937 rnd((unsigned long long)new char);
int rnad(){return abs((int)rnd());}
int rd(int l,int r){return rnad()%(r-l+1)+l;}

string getFile(string path){
	ifstream fin(path.c_str());
	string tmp;
	fin>>tmp;
	fin.close();
	return tmp;
}
void setFile(string path,string ths){
	ofstream fout(path.c_str());
	fout<<ths;
	fout.close();
}

map<string,string>team;
set<string>teams;
map<string,int>id;
string names[1005];
int cnt;
int scnt[1005][15],lstt[1005][15],ac[1005],allfs[1005];

void addperson(){
	team["sjl"]=" ";
	team["zjz"]=" ";
	team["lqy"]="我谢谢你";
	team["lyx"]="我不知道";
	team["lyc"]="我不知道";
	team["zys"]="我不知道";
	//add more
	for(auto [p,t]:team)teams.insert(t);
	for(auto i:teams)names[id[i]=++cnt]=i;
}

struct th{int a,b,c;};

string gt(string t,string col="black",string bgcol="#ffffff",string fontsize="15px")
{
	return "<td style=\"text-align: center;border: 1px solid grey;background-color:"+bgcol+";\"><span style=\"color:"+col+";font-size: "+fontsize+";\">"+t+"</span></td>\n";
}
string t2s(int t){
	int h=t/60,m=t%60;
	string s="";
	s+=(char)(h/10+'0');
	s+=(char)(h%10+'0');
	s+=":";
	s+=(char)(m/10+'0');
	s+=(char)(m%10+'0');
	return s;
}

string lgreen="#31e631";
string lred="#ff7b7b";
string dgreen="#318331";
string chbckc[2]={"#cccccc","#ffffff"};

void updBoard(){
	string s="<table border: 4px dotted black; style=\"border-collapse: collapse;border: 1px solid grey;\" align=\"center\">\n";
	s+="<caption><h2>组队赛排行榜</h2></caption>\n";
	s+="<thead><tr>\n";
	s+="<th>&emsp;排名&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;队伍名称&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;队伍 ID&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;A&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;B&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;C&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;D&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;E&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;F&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;G&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;H&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;&emsp;I&emsp;&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;题目数&emsp;</th>\n";
	s+="<th colspan=\"1\">&emsp;总罚时&emsp;</th>\n";
	s+="</tr></thead>\n";
	s+="<tbody>\n";
	vector<th>v;
	for(int i=1;i<=cnt;i++)v.push_back({ac[i],allfs[i],i});
	sort(all(v),[&](th a,th b){return a.a==b.a?a.b==b.b?a.c<b.c:a.b<b.b:a.a>b.a;});
	int rk=0;
	for(auto _:v){
		int i=_.c;
		s+="<tr>\n";++rk;
		s+=gt(to_string(rk),"black",chbckc[rk%2]);
		s+=gt(names[i],"black",chbckc[rk%2]);
        s+=gt(to_string(i),"black",chbckc[rk%2]);
		for(int p=1;p<=9;p++){
			int l=lstt[i][p],c=scnt[i][p];
			if(~l) 
			{
				s+=gt("+"+(c?to_string(c):"")+"<br> <span style=\"font-size: 9px;\">"+t2s(l)+"</span>","black",lgreen,"17px");
			}
			else if(c)s+=gt(to_string(c),"black",lred);
			else s+=gt("","black",chbckc[rk%2]);
		}
		s+=gt(to_string(ac[i]),"black",chbckc[rk%2]);
		s+=gt(to_string(allfs[i]),"black",chbckc[rk%2]);
		s+="</tr>\n";
	}
	s+="</tbody>\n</table>\n";
	setFile("BOARD/Board.html",s);
}

void __INIT__(){}
void __SOLVE__(int _case){
	addperson();
	memset(lstt,-1,sizeof(lstt));
	updBoard();
	int Tsk;cin>>Tsk;
	int sth,stm;
	cin>>sth>>stm;
	stm+=sth*60;
	int h,m;string name,pb;bool sta;
    for(int __=1;__<=Tsk;__++)
	{
		// 1 = ac, 0 = wa
		if( !(cin>>h>>m>>name>>pb>>sta) ) break;
		m+=h*60;m-=stm;
		string t=team[name];
		int p=0,i=id[t];
		if(pb=="A"||pb=="1")p=1;
		if(pb=="B"||pb=="2")p=2;
		if(pb=="C"||pb=="3")p=3;
		if(pb=="D"||pb=="4")p=4;
		if(pb=="E"||pb=="5")p=5;
		if(pb=="F"||pb=="6")p=6;
		if(pb=="G"||pb=="7")p=7;
		if(pb=="H"||pb=="8")p=8;
		if(pb=="I"||pb=="9")p=9;
		if(~lstt[i][p])continue;
		if(!sta)--scnt[i][p];
		else scnt[i][p]=-scnt[i][p],lstt[i][p]=m,++ac[i],allfs[i]+=lstt[i][p]+20*scnt[i][p];
		updBoard();
	}
}
int main()
{
    freopen("Input.txt","r",stdin);
    // freopen(".out","w",stdout);
    __INIT__();
    int T;DC?cin>>T,1:T=1;
    for(int _CASE=1;_CASE<=T;_CASE++) __SOLVE__(_CASE);
    return 0;
}
