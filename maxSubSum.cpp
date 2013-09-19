#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int maxSubSum(vector<int>& array)
{
	int max;
	if(array.size()>0)
	    max = array[0];
	for(int i=0; i<array.size(); i++)
	{
		int sum=array[i];
		for(int j=i;j<array.size();j++)
		{
			if(j!=i)
				sum+=array[j];
			if(sum > max)
				max = sum;
		}
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
			<<maxSubSum(array)<<endl;
		}
		else
			cout<<"No data input!"<<endl;
	}
	return 0;
}