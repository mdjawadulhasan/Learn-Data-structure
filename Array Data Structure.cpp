//Reversing an array

#include <iostream>
using namespace std;
int main()
{

  int ar[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int i, j, tmp;
  int p = sizeof(ar) / sizeof(ar[0]);
  for (int i = 0, j = 9; i <= (p / 2); i++, j--)
  {
    tmp = ar[j];
    ar[j] = ar[i];
    ar[i] = tmp;
  }

  for (int i = 0; i < p; i++)
  {
    cout << ar[i] << endl;
  }
}

//Searching elements 	1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ar[] = {1, 3, 5, 7, 8};
    int n;
    cin>>n;

    int size = sizeof(ar)/sizeof(ar[0]);
    for(int i=0;i<size;i++)
    {
        if(n==ar[i])
        {
            cout<<"Found element in " <<i<<"th index"<<endl;
            break;
        }
    }

}
//Searching elements 	1




//Searching and coundting

#include <iostream>
using namespace std;
int main()
{
  int total[] = { 34, 23, 45, 36, 45, 23, 41, 24, 29, 33, 45, 35};

  int mark_count[101];

  for (int i = 0; i < 101; i++)
  {
    mark_count[i] = 0;
  }

  for (int i = 0; i < 12; i++)
  {
    mark_count[total[i]]++;
  }

  for (int i = 20; i < 50; i++)
  {
    cout << "Marks :" << i << " Count :" << mark_count[i] << endl;
  }
}



//Searching and coundting 2
#include <iostream>
using namespace std;
int main()
{
  int total[] = {6, 7, 4, 6, 9, 8, 7, 6, 2, 4, 3, 4, 1};

  int mark_count[11];

  for (int i = 0; i < 11; i++)
  {
    mark_count[i] = 0;
  }

  for (int i = 0; i <= 12; i++)
  {
    mark_count[total[i]]++;

    for (int j = 0; j <10; j++)
    {
      cout << mark_count[j]<<" ";
    }

    cout << endl;
  }
}

//Array inside  the Function

#include <bits/stdc++.h>
using namespace std;
int find_max(int ara[], int n)
{
  int max = ara[0];
  int i;
  for (i = 1; i < n; i++)
  {
    if (ara[i] > max)
    {
      max = ara[i];
    }
  }
  return max;
}


int main()
{
  int ara[]={34,12,5,6,8,3,1,89,98,100,21};
  int n = 11;
  int max = find_max(ara, n);
  cout << max << endl;

  return 0;
}

//Now wait a minute !!!
/*if when you work with array inside the Function, array memory addres changes.
As a result the follwing code snipets output will be 
   1
  100
*/

#include <bits/stdc++.h>
using namespace std;
void test_function(int ara[]) 
{
    ara[0] = 100;
    return;
}
int main() 
{
    int ara [] = {1, 2, 3, 4, 5};
    cout<<ara[0]<<endl;
    test_function(ara);
    cout<<ara[0]<<endl;
   return 0;
}



///Array elements Insertion 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[] = {1, 3, 5, 7, 8};
    int item = 10;
    int k = 3, n = 5;
    n++;
    for (int i = n - 1; i >k; i--)
    {
        ar[i] = ar[i - 1];
    }
    ar[k]=item;
    for (int i = 0; i <6; i++)
    {
        cout<<ar[i]<<endl;
    }
    
}

///Array elements Insertion 2
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, i, n = 5, mimo[10] = {2, 3, 5, 6, 7};
    mimo[n++] = 8;

    for (i = n; i > 0; i--)
        mimo[i] = mimo[i - 1];

    mimo[0] = 1;
    n++;

    k = 3;
    for (i = n; i > k; i--)
        mimo[i] = mimo[i - 1];

    mimo[k] = 4;
    
    for (i = 0; i <= n; i++)
        cout << mimo[i];
}

//Delete an elements from array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ar[] = {1, 3, 5, 7, 8};
    int n = 5;
    int k = 2;

    for (int i = k; i < n; i++)
    {
        ar[i] = ar[i + 1];
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << endl;
    }
}

/////Delete an elements from array

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k, i, n = 8, mimo[10] = {1, 2, 3, 4, 5, 6, 7, 8};
    n--;

    n--;
    for (i = 0; i < n; i++)
        mimo[i] = mimo[i + 1];
    k = 2;
    n--;
    for (i = k; i < n; i++)
        mimo[i] = mimo[i + 1];
    for (i = 0; i < n; i++)
        cout << mimo[i];
}