/*
 * next数组其实是从下标1开始的，因为下标0之前是个空串，下标1则对应着M串的第0个字符。我们设next[0]=-1，仅仅是个标志而已，没有什么特殊的含义。
 */

void kmpGetNext()
{
	int i= 0,j = -1;
	b[i] = j;
	while(i < m)
	{
		while(j >= 0 && p[i] != p[j])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}

}


// 算导：

COMPUTE-PREFIX-FUNCTION(P)

m = P.length
let B[1..m] be a new array
B[1] = 0
k = 0

for q = 2 to m
	while k > 0 and P[k+1] != P[q]
		k = B[k]
	if P[k+1] == P[q]
		k = k+1
	B[q] = k
return B

