#include<iostream>
#include<vector>
using namespace std;
void check(vector<vector<int> >& v, int i, int j, int size, int& maxsize, int& cnt)
{
	int k, l;
	for (k = 0; k < size; k++)
	{
		for (l = 0; l < size; l++)
		{
			if ((l + k) % 2 == 0)
			{
				if (v[i + k][j + l] == 1)
					continue;
				else
					goto lab;
			}
			else
			{
				if (v[i + k][j + l] == 0)
					continue;
				else
					goto lab;
			}
		}
	}
lab:
	if (k == size && l == size)
	{

		maxsize = size;
		cnt++;
	}
}
int main(){
	int n;
	cin>>n;
	vector<vector<int> > map(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			map[i].push_back(ch-'0');
		}
	}
	int ans=1;//�������ٰ���һ��1�ַ�; 
	int cnt=1;//����һ�� 
	for(int size=1;size<=n;size++){ //���ߴ�ı��� 
		int temp_cnt=0;
		for(int i=0;i<=n-size;i++){
			for(int j=0;j<=n-size;j++){

				check(map, i, j, size, ans, temp_cnt);
			}
		}
		if(ans!=size) break; //��ǰsizeû���ҵ�ans�����Ը����sizeҲ�Ҳ���������Ͳ�����
		if(ans==size) cnt=temp_cnt;//����ҵ���ans�����Ǹ����ҵ��ĸ��� 
		
	} 
	cout<<ans<<" "<<cnt<<endl; 
	return 0;
} 


