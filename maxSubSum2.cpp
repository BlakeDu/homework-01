#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int maxSubSum2(vector<int>& array)
{
	int max = 0;
	int sum = 0;
	// consider that nums in array are all negative
	if(array.size()>0)
		max = array[0];
	for(int i=1; i<array.size(); i++)
	{
		if(array[i]>max)
			max = array[i];
	}
	// find the max_sub_sum
	for(int j=0; j<array.size(); j++)
	{
		sum += array[j];
		if(sum > max)
			max = sum;
		else if(sum < 0)
			sum = 0;
	}
	return max;
}
bool loadArray(string infile, vector<int>& array)
{
	ifstream is(infile.c_str());
	if(!is)
	{
		cerr << "Error occurred in opening files!" << endl;
		return false;
	}
	int num;
	while(is>>num)
	{
		array.push_back(num);
	}
	return true;
}
int main()
{
	vector<int> array;
	string filename;
	cout<<"Please input the directory of the file:"<< endl;
	cin>> filename;
	if(loadArray(filename, array))
	{
		if(array.size()>0){
			cout<<"The max Sum of sub-array is "
			<<maxSubSum2(array)<<endl;
		}
		else
			cout<<"No data input!"<<endl;
	}
	return 0;
}