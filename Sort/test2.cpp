#include<iostream>
#include<vector>
using namespace std;
	
void InsertSort(vector<int> &unsortedArr)		
{
	int n = unsortedArr.size();
	if(n <= 0)
		return;
    for(int i = 1; i < n ; i++) 
    {
        int j = i-1;
        int val = unsortedArr[i];
        while(j>=0 && val < unsortedArr[j])
        {
            unsortedArr[j+1] = unsortedArr[j];
            j--;
        }
        unsortedArr[j+1] = val;
    }
}
void Show(vector<int> unsortedArr)
{

	for(auto i : unsortedArr)
	{
		cout<<i<<" ";
	}
	// for(int i =0; i < unsortedArr.size(); i++)
	// {
	// 	cout<<i<<" " ;
	// }
}	
int main()
{
	vector<int> a = {
		2,4,5,11,8,7,28,77,1,5,6,0
	};
	
	Show(a);
	cout << endl;
	InsertSort(a);
	Show(a);

	return 0;
} 
