// Implamentation K queue in an array
 #include<iostream>
 #include<stack>
 #include<queue>
 using namespace std;
 class Kqueue{
    public:
    int n,k,freeSpot;
    int *arr, *front, *rear, *next;
    Kqueue(int _n,int _k):n(_n),k(_k),freeSpot(0){
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear  = new int[k];
        for(int i=0;i<k;++i)
        front[i]=rear[i]=-1;
        for(int i=0;i<n;i++)
        next[i]=i+1;
        next[n-1]=-1;
    }
    // push x into ith queue
    bool push(int x,int qi){
        // overflow
        if(freeSpot == -1) return false;
        // find first free index
        int index = freeSpot;
        // update freeSpot
        freeSpot = next[index];
        // if first element in qi
        if(front[qi]== -1){
            front[qi]=index;
        }
        else{
            // link new element to that Q's rearest element
            next[rear[qi]=index];
        }
    //    update next
    next[index]=-1;
    // update rear
    rear[qi]=index;
    arr[index]=x;
    return true;
}
// pop element from qith queue
int pop(int qi){
    // underflow
    if(front[qi]==-1){
        return -1;
    }
    // find index to pop
    int index = front[qi];
    // update front
    front[qi]=next[index];
    // update freeSpot
    next[index]=freeSpot;
    freeSpot = index;
    return arr[index];
    }
    ~Kqueue(){
        delete []arr;
        delete []front;
        delete []rear;
        delete []next;
    }
 };
 int main(){
    Kqueue kq(8,3);
    cout<<kq.push(178,0)<<endl;
    cout<<kq.push(245,2)<<endl;
    cout<<kq.push(501,1)<<endl;
    cout<<kq.pop(1)<<endl;
    return 0;
 }

 
