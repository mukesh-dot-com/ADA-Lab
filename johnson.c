#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
int flag = 0;
int swap(int *a,int *b) {
int t = *a;
*a = *b;
*b = t;
}
int search(int arr[],int num,int mobile) {
int g;
for(g=0;g&lt;num;g++) {
if(arr[g] == mobile)
return g+1;
else
flag++;
}
return -1;
}
int find_Moblie(int arr[],int d[],int num) {
int mobile = 0;
int mobile_p = 0;
int i;
for(i=0;i&lt;num;i++)
{
if((d[arr[i]-1] == 0) &amp;&amp; i != 0)
{
if(arr[i]&gt;arr[i-1] &amp;&amp; arr[i]&gt;mobile_p) {
mobile = arr[i];
mobile_p = mobile;
}

else
flag++;
}
else if((d[arr[i]-1] == 1) &amp; i != num-1)
{
if(arr[i]&gt;arr[i+1] &amp;&amp; arr[i]&gt;mobile_p)
{
mobile = arr[i];
mobile_p = mobile;
}
else
flag++;
}
else
flag++;
}
if((mobile_p == 0) &amp;&amp; (mobile == 0))
return 0;
else
return mobile;
}
void permutations(int arr[],int d[],int num)
{
int i;
int mobile = find_Moblie(arr,d,num);
int pos = search(arr,num,mobile);
if(d[arr[pos-1]-1]==0)
swap(&amp;arr[pos-1],&amp;arr[pos-2]);
else
swap(&amp;arr[pos-1],&amp;arr[pos]);
for(int i=0;i&lt;num;i++)
{
if(arr[i] &gt; mobile)

{
if(d[arr[i]-1]==0)
d[arr[i]-1] = 1;
else
d[arr[i]-1] = 0;
}
}
for(i=0;i&lt;num;i++)
{
printf(&quot; %d &quot;,arr[i]);
} }
int factorial(int k)
{
int f = 1;
int i = 0;
for(i=1;i&lt;k+1;i++)
f = f*i;
return f;
}
int main()
{
int num = 0;
int i;
int j;
int z = 0;
printf(&quot;Johnson trotter algorithm to find all permutations of given
numbers \n&quot;);
printf(&quot;Enter the number\n&quot;);
scanf(&quot;%d&quot;,&amp;num);
int arr[num],d[num];
z = factorial(num);
printf(&quot;total permutations = %d&quot;,z);

printf(&quot;\nAll possible permutations are: \n&quot;);
for(i=0;i&lt;num;i++)
{
d[i] = 0;
arr[i] = i+1;
printf(&quot; %d &quot;,arr[i]);
}
printf(&quot;\n&quot;);
for(j=1;j&lt;z;j++) {
permutations(arr,d,num);
printf(&quot;\n&quot;);
}
return 0;
}
