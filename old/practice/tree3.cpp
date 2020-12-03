#include<bits/stdc++.h>

using namespace std;

void build_tree(int arr[],int tree[],int node,int start,int end){
	if(start == end){
		tree[node] = arr[start];
	}else{
		int mid = (start+end)/2;
		int left_node  = node *2 + 1;
		int right_node = node *2 + 2;
		build_tree(arr,tree,left_node,start,mid);
		build_tree(arr,tree,right_node,mid+1,end);
		tree[node] = tree[left_node] + tree[right_node];
	}
}

void updata_tree(int arr[],int tree[],int node,int start,int end,int idx,int val){
	if(start == end){
		tree[node] = val;
		arr[idx] = val;
	}else{
		int mid = (start + end)/2;
		int left_node  = node *2+1;
		int right_node = node *2+2;
		if(idx>=start && idx<=mid){
			updata_tree(arr,tree,left_node,start,mid,idx,val);
		}else{
			updata_tree(arr,tree,right_node,mid+1,end,idx,val);
		}
		tree[node] = tree[left_node] + tree[right_node];
	}
}

int query_tree(int arr[],int tree[],int node,int start,int end,int L,int R){
	if(start>R || end<L){
		return 0;
	}else if(start >=L && end <=R){
		return tree[node];
	}else if(start == end){
		return tree[node];
	}else{
		int mid = (start+end)/2;
		int left_node = node*2+1;
		int right_node = node*2+2;
		int sum_left = query_tree(arr,tree,left_node,start,mid,L,R);
		int sum_right = query_tree(arr,tree,right_node,mid+1,end,L,R);
		return sum_left+sum_right;	
	}
	

}

int main(){
	int arr[] = {1,2,3,4,5,6};
	int tree[1000] = {0};
	int len = 6;
	build_tree(arr,tree,0,0,len-1);
	for(int i = 0; i< 16; i++){
		cout <<i << " : "<< tree[i] << endl;
	}
	cout << "\n" << "\n";
	updata_tree(arr,tree,0,0,len-1,2,5);
	for(int i = 0; i< 16; i++){
		cout <<i << " : "<< tree[i] << endl;
	}
	for(int i = 0; i<6; i++){
		cout << arr[i];
	}
	cout << "\n" << "\n";
	cout << "sum : "<< query_tree(arr,tree,0,0,len-1,2,5);
} 
