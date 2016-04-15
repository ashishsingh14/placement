#include "functions.h"

void flowers()
{
    int N, K;
    cin >> N >> K;
    int C[N];
    for(int i = 0; i < N; i++){
       cin >> C[i];
    }
     long long ans = 0;
     sort(C,C+N);
     if(K>=N)
     {
         for(int i =0;i<N;i++)
             ans += C[i];
     }
     else
     {
         int x = 0;
         int i = N-1;
         while(i>=0)
         {
             for(int j = 0;j<K && i>=0;j++)
             {
                 ans += (x+1)*C[i];
                 //cout<<ans<<endl;
                 i--;
             }
             x++;
         }

     }

    cout << ans << "\n";
}

void sansaandxor()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int input[n];
        for(int i =0;i<n;i++)
            cin>>input[i];

        if(n%2==0)
        {   cout<<"0"<<endl;
            continue;

        }
        else
        {
            int ans =0;
            for(int i =0;i<n;i++)
            {
                if(i%2==0)
                {
                    ans = ans^input[i];
                }
            }

            cout<<ans<<endl;
        }
    }

}




int main(void){

   //stock();


    char arr[] = {'a','b','c'};
    string a = "abc";

    do{
        cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    }while(next_permutation(arr,arr+3));


    do
    {
        cout<<a<<endl;
    }while(next_permutation(a.begin(),a.end()));

   return 0;
}
