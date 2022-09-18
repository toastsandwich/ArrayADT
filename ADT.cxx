#include<bits/stdc++.h>

using namespace std;

class ARRAY{
    private:
    //creating data members in private.
    int *A;
    int size;
    int length;
    public:
    //A constructor is created to access those data members which are in private.
    ARRAY(int *a,int s){
        A=a;
        size=s;
    }
    //input function will allow us to fill the array.
    void input(){
        for(int i=0;i<size;i++){
            cout<<"Enter Element "<<i+1<<" : ";
            cin>>A[i];
        }
    }
    //appending an element at the end of the array.
    //Time:O(1)
    void append(){
        int n;
        cout<<"Enter the element to append : ";
        cin>>n;
        A[size]=n;//element inserted at last
        size++;
    }
    //now i will be creating a function to insert a element at certain position.
    //Time:O(n)                                                        
    //Best case time:O(1)
    //Worst case time:O(n)
    void insert(){
        int n;
        cout<<"Enter the index where you want to insert the element : ";
        cin>>n;
        length=size;
        if(n<0||n>size) cout<<"Invalid Input!"<<endl;
        else{
        for(int i=length;i>n;i--){
            A[i]=A[i-1];
        }
        cout<<"Enter the value of the element : ";
        int x;cin>>x;
        A[n]=x;
        size++;
        }
    }
    //This function will delete the element at a certain index.
    //Time:O(n)
    //Best case:O(1)
    //Worst case:O(n)
    void DELETE(){
        int n;
        cout<<"Enter the index of element you want to remove : ";
        cin>>n;
        if(n>=0&&n<size){
        length=size;
        for(int i=n;i<length-1;i++){
            A[i]=A[i+1];
        }
        size--;
        }
        else cout<<"Invalid Input!\n";
    }
    //This function will find element using searching techniques.
    void search(){
        int key;
        cout<<"Enter the Search Element : ";
        cin>>key;
        int count=0;
        if(size<4){
            //we do linear search
            for(int i=0;i<size;i++){
                if(A[i]==key){
                    cout<<"Element found at A["<<i<< "]."<<endl;
                    count++;
                    //break;
                }
                else continue;
            }
            if(count==0) cout<<"Element not found\n";
        }
        else{
            //we do binary search
            //Time Complexity is worst case : O(n)
            //                   best case : O(1)
            //                   average case : O(log(n))
            int l=0;
            int r=size-1;
            int mid=(l+r)/2;
            while(l<=r){
                if(A[mid]==key){
                    cout<<"Element found at A["<<mid<<"]"<<endl;
                    l=++mid;
                    r=--mid;
                    count++;
                }
                else if(A[mid]<key){
                    r=--mid;
                }
                else l=++mid;
            }
            if(count==0){
                cout<<"Element not found!\n";
            }
        }
    }
    //This function will print the value of index which is input
    void get(){
        int n;
        cout<<"Enter the index of element that you desire to look : ";
        cin>>n;
        if(n<0||n>size) cout<<"Invalid Input!"<<endl;
        else cout<<A[n];
    }
    //  This function will set a value at assif=gned index
    void set(){
        int i;
        int val;
        cout<<"Enter the index : ";
        cin>>i;
        if(i<0||i>size){
            cout<<"Invalid Output"<<endl;
        }
        else{
        cout<<"Enter the value of element you want to store at "<<i<<" : ";
        cin>>val;
        A[i]=val;
        }
    }
    void A_max(){
        int mx=INT_MIN;
        for(int i=0;i<size;i++){
            if(mx<A[i]){
                mx=A[i];
            }
        }
        cout<<"Max element of Array is : "<<mx<<endl;
    }
    //This function is made using inbuilt library.
    //Time complexity : O(n);
    void A_min(){
        cout<<"The element with lowest value is : "<<*min_element(A,A+size)<<endl;
    }

    //Now the below function are going to be important for CP.

    //below created function will reverse the array.
    void reverse(){
        cout<<"The reverse areray is : "<<endl;
        for(int i=0,j=size-1;i<j;i++,j--){
            swap(A[i],A[j]);
        }
    }
    //---------------------------------------------------------------------------------------------- 
    //The below function will help in rotation of an array
    //Let us first know the difference between shift and rotation
    //lets take an array for example
    //A[]={3 5 6 7 3 5}
    //lets see shifting first
    //1.left shift:
    //A[]={5 6 7 3 5 0}
    //2.right shift :
    //A[]={0 3 5 6 7 3}
    //In shifting the extreme values either from right or left are lost
    //whereas for rotation the lost element is appended to the array
    void shift(){
        cout<<"/nShifting Options : \n1.Left Shift\t\t2.Right shift\n";
        cout<<"Input (Give the option number): ";
        int opt;cin>>opt;
        if(opt==1){
            //ex  1 3 2 4
            //O/P 3 2 4 0
            for(int i=1;i<size;i++){
                A[i-1]=A[i];
            }
            A[size-1]=0;
            cout<<"After Left Shift : \n";
            output();
        }
        else {
            //ex  8 7 5 6
            //O/P 0 8 7 5
            for(int i=size-1;i>=1;i--){
                A[i]=A[i-1];
            }
            A[0]=0;
            cout<<"After Right Shift :\n";
            output();
        }
    }
    //Now lets create a function which will rotate the array'
    void rotate(){
        cout<<"Rotation Options:\n";
        cout<<"1.Clockwise\t\t2.Anti-Clockwise"<<endl;
        int opt;
        cout<<"Input (Give the option number): ";
        cin>>opt;
        if(opt==1){
            //code for clockwise goes here
            //1 2 3 4 -> 4 1 2 3
            //1 2 3 4 -> 0 1 2 3 right shift
            int n=A[size-1];
            for(int i=size-1;i>=0;i--){
                A[i]=A[i-1];    //index size-1->0
            }
            A[0]=n;
            output();
        }
        else{
            //code for anti clockwise goes here.
            //1 2 3 4 -> 2 3 4 1 --> we will use left shift
            int n=A[0];
            for(int i=1;i<size;i++){
                A[i-1]=A[i];//left shifting done .
            }
            A[size-1]=n;
            output();
        }
    }
    //--------------------------------------------------------------------------------------------------------------------------
    void arrsort(){
        //we cannot use the inbuilt sort which will have time complexity as O(NlogN)
        multiset<int> ms;
        for(int i=0;i<size;i++){
            ms.insert(A[i]);
        }
        delete []A;
         int i=0;
        for(auto x:ms){
            if(i<size){
                A[i]=x;
                i++;
            }
            else break;
        }
    }
    //the below function will allow us to insert an element in an array which is sorted
    //the position of element will depend on other elements
    void insert_insort(){}
    //output function will allow us to show the elements of array.
    void output(){
        int n=size;
        for(int i=0;i<n;i++){
     
            cout<<"A["<<i<<"] : "<<A[i]<<endl;
        }
    }
    ~ARRAY(){
        delete []A;
    }
};
int main(){
    system("cls");
    cout<<"Enter the size of Array : ";
    int n;cin>>n;
    int *p=new int[n];
    ARRAY arr(p,n);
    //your workspace
    return 0;
}
