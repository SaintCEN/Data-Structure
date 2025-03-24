#include <cstdio>
#include <set>
using namespace std;
int main(){
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);
	
	set<int>::iterator ite;
	ite = s.find(1);
	s.erase(3);
	
	for(ite = s.begin();ite!=s.end();ite++){
		cout << *ite ;
	}
	return 0;
}

#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main(){
	map<int,const char*> m;
	//插入元素
	m.insert(make_pair(1,"ONE"));
	m[100]="HUNDRED";
	//查找元素
	map<int,const char*>::iterator ite;
	ite = m.find(1);
	puts(ite.second);
	//删除元素
	m.erase(10);
	//遍历一遍所有元素
	for(ite = m.begin();ite!=m.end();++ite){
		cout << ite.first << ite.second;
	}
}