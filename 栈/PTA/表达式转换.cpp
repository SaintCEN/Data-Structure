#include<bits/stdc++.h>
using namespace std;

void trans(string input)
{
	stack<char> op;
	vector<string> output;
	for(int i=0; i<int(input.size()); i++)
	{
		if((input[i]<='9'&&input[i]>='0')||(i==0&&input[i]!='('))
		{
			string num="";
			if(i==1&&input[i-1]=='-') num+='-';
			if(i==1&&input[i-1]=='+')
			    op.pop();
			if(i>1&&input[i-1]=='+'&&input[i-2]=='(')
			    op.pop();
			if(i>1&&input[i-1]=='-'&&input[i-2]=='(') 
			{
				num+='-';
				op.pop();
			}
			while((i<input.size()&&((input[i]>='0'&&input[i]<='9')||input[i]=='.'))||i==0)
			{
		        num+=input[i];
				i++;
			}
			i--;
			output.push_back(num);
		}
	
		else if(input[i]=='(')
			op.push('(');
			
		else if(input[i]==')')
		{
			while(!op.empty()&&op.top()!='(')
			{
				output.push_back(string(1,op.top()));
				op.pop();
			} 
			op.pop();
		}
		
		else if(input[i]=='+'||input[i]=='-')
		{
			while(!op.empty()&&op.top()!='(')
			{
				output.push_back(string(1,op.top()));
				op.pop();
			}
			op.push(input[i]);
		}
		
		else if(input[i]=='*'||input[i]=='/')
		{
			while(!op.empty()&&(op.top()=='*'||op.top()=='/'))
			{
				output.push_back(string(1,op.top()));
				op.pop();
			}
			op.push(input[i]);
		}
	}
	
	while(!op.empty())
	{
		output.push_back(string(1,op.top()));
		op.pop();
	}
	for(int i=0; i<output.size(); i++)
	{
		cout<<output[i];
		if(i!=output.size()-1)
		    cout<<' ';
	}
}

int main()
{
	string input;
	cin>>input;
	
	trans(input);
    
	return 0;
} 
