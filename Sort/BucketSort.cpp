#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> BucketSort(vector<int> unsortedArr,int bucketsize);
void InsertSort(vector<int> &unsortedArr);
void Show(vector<int> unsortedArr);
int main(void)
{
	vector<int> a = {2,4,5,11,8,7,28,77,1,5,6,0};
	Show(a);
	cout << endl;
	a = BucketSort(a,3);
	Show(a);
	return 0;
}

vector<int> BucketSort(vector<int> unsortedArr,int bucketsize)
{
	int n = unsortedArr.size();
	vector<int> resultArr = unsortedArr;
	int max = resultArr[0];
	int min = resultArr[0];
	for(int i = 0; i<n; i++)
	{
		if(max<resultArr[i])
			max = resultArr[i];
		if(min>resultArr[i])
			min = resultArr[i];
	}
	int bucketcount = floor((max - min + 1)/bucketsize);
	vector<vector<int>> buckets(bucketcount);
	
	for(int i = 0; i<n;i++)
	{
		int index = floor((resultArr[i] - min)/bucketsize);
		buckets[index].push_back(resultArr[i]);				
	}
	int arrIndex = 0;
	for(auto bucket : buckets)
	{
		if(bucket.size() != 0)
		{
			InsertSort(bucket);
			for(auto value : bucket)
			{
				resultArr[arrIndex] = value;
				arrIndex++;
			}
		}
	}

	return resultArr;
}

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
}	