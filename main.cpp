#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int array[2][100], n, t, i, remt, marks_prep[100], maxi = -1, totalmarks = 0;

cout << "Enter number of topic: ";
cin >> n;

cout << "Enter total time remainig for preparation in hours : ";
 cin >> t;

cout << "Enter 2D array element: Time (in hours) reqired to prepared topic AND Weightage(marks) of topic";
cout <<"\nTIME(in hours):"<<setw(10)<<"MARKS:"<<endl;
 for (i = 0; i < n; i++)
{ cin >>array[0][i]>> array[1][i];
}
for (i = 0; i < n; i++)
{
marks_prep[i] = 0;
}
remt = t;

cout<<"\n Topic in decreasing weightage order(highest weightage to lowest weightage)";

while (remt >= 0)
{ maxi = -1;

   for (i = 0; i < n; i++)
{ if ((marks_prep[i] == 0) && ((maxi == -1) || (((float)array[1][i]/(float)array[0][i]) > ((float) array[1][maxi]/(float) array[0][maxi]))))
{
    maxi = i;
}
}
marks_prep[maxi] = 1;

remt -= array[0][maxi];

totalmarks += array[1][maxi];
if (remt >= 0)
{  cout << "\nTake topic   " << maxi + 1<<setw(10) << "Time: "
          <<array[0][maxi] <<setw(10)<< "Marks: "<< array[1][maxi]
         <<setw(10)<<" prepared,Topic covered completely, Time left: "<< remt;
}
else
{cout << "\ntake topic   " << maxi + 1<<setw(10) <<"Time: "
<<(array[0][maxi] + remt)<<setw(10) << " Marks: "
<<(array[1][maxi] / array[0][maxi]) * (array[0][maxi]
+	remt) <<setw(10)<< "prepared, Partially covered topic, Time left: 0"
<<	" Time added is: " << remt + array[0][maxi];
totalmarks -= array[1][maxi];

totalmarks += ((array[1][maxi] / array[0][maxi]) * (array[0][maxi] + remt));
}
}

cout << "\nTotal marks prepared: " << totalmarks;
return 0;
}
