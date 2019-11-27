/*

K-MEANS CLUSTERING
Test cases:

Dataset 1:
n=10, k=2, Numbers: 2,4,10,12,3,20,30,11,25,23, Mean1:2, Mean2:16

Dataset 2: 
n=10, k=3, Numbers: 4,6,8,9,11,16,18,19,22,24, Mean1:8, Mean2:17, Mean3:23

*/
#include<iostream>
#include<algorithm>
using namespace std;

bool areMeansEqual(int m[],int om[],int k){
	for(int i=0;i<k;i++){
		if(m[i]!=om[i]){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	int k;
	cout<<"Enter no. of elements:\n";
	cin>>n;
	cout<<"Enter no. of clusters:\n";
	cin>>k;
	int numselem[k],temp[k],distances[k],means[k],oldmeans[k];
	int elem[n],clusters[k][n];
	cout<<"Enter elements:\n";
	for(int i=0;i<n;i++){
		cin>>elem[i];
	}
	cout<<"Enter means for all clusters:\n";
	for(int j=0;j<k;j++){
		cin>>means[j];
	}
	do{
	for(int j=0;j<k;j++){
		oldmeans[j]=means[j];
	}
	for(int j=0;j<k;j++){
		numselem[j]=0;
		//cout<<numselem[j]<<endl;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			clusters[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			distances[j]=elem[i]-means[j];
			if(distances[j]<0){
				distances[j]=-distances[j];
			}
			//cout<<"Distance "<<j<<" : "<<distances[j]<<endl;
		}
		int mindist=distances[0];
		int mindistindex;
		for(int p=0;p<k;p++){
			if(distances[p]<=mindist){
				mindist=distances[p];
				mindistindex=p;
			}
		}
		//cout<<"Mindistindex:"<<mindistindex<<endl;
		clusters[mindistindex][numselem[mindistindex]]=elem[i];
		numselem[mindistindex]++;
	}
	for(int i=0;i<k;i++){
		int sum=0;
		for(int j=0;j<numselem[i];j++){
			sum+=clusters[i][j];
		}
		cout<<"Sum of all elems in cluster "<<i<< " : "<<sum<<endl;
		means[i]=sum/numselem[i];
	}
	
	cout<<"The clusters are:\n";
	for(int i=0;i<k;i++){
		cout<<"Cluster "<<i+1<<":"<<endl;
		for(int j=0;j<numselem[i];j++){
			cout<<clusters[i][j]<<"\t";
		}
		cout<<endl;
		cout<<"Mean "<<i+1<<" : "<<means[i]<<endl;
		cout<<"\n";	
	}}while(areMeansEqual(means,oldmeans,k));
	return 0;
}
