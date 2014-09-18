
/*********************************************************************
	@ Title:			��Ч����+ŷ�����+�����	

	@ Description:		1���������������

						2��ŷ������㷨

						3���ж�����

						4�������������ʱ��
	@ Conclusion:			

	@ Author:			rh_Jameson

	@ Date:				2014/08/09
**********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#define MAX 10000
//-----------------------1���������������---------------------------//
//����α�������α�����ÿ�����ж���һ����
void testRand()
{
	for(int i = 0; i < 10; ++i )
	{
		cout << rand() << endl;					//����10�����޶���Χ�������
	}
	for( int j = 0; j < 10; ++j )
	{
		cout <<( rand() % 100 ) << endl;			//����10��100���ڵ������
	}

}
//�����������
void TestSRand()
{
	cout << "���������" << endl;
	srand( (int)time(NULL) );
	for( int k = 0; k < 10; ++k)
	{		
		cout << ( rand() % 100 ) << endl;			
	}
}

//------------------------2��ŷ������㷨----------------------------//
//�ֳ�շת������������������Լ��
int gcdByRecursion( int x, int y )
{

	//�ݹ鷨
	if( y == 0)								//����Ϊ0�Ļ������ر�����
	{
		return x;
	}
	if( x < y )								//���x<y,����x��y��ֵ
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	
	/*if( x % y == 0 )						//��ʽһ
	{
		return y;
	}
	else
	{
		return gcdByRecursion( y, x % y );
	}*/
	return x % y == 0 ? y : gcdByRecursion( y, x % y ); 

	/*if( y == 0 )							//��ʽ��							
	{
		return x;
	}
	else
	{
		return gcdByRecursion(y, (x % y) ) ;
	}*/
	//return y == 0 ? x : gcdByRecursion( y, x % y );
}
int gcd(int x,int y)
{
	int tmp = 0;
	if(x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}

	if( y == 0 )
	{
		return x;
	}	
	
	while( x % y != 0 )
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return y;
}
void testGcd()
{
	int res = gcd(10,20);
	cout << res << endl;
}

//------------------------3���ж�����--------------------------------//
bool isPrime(int n)
{
	if( n < 2 )			//С��2��������������
	{
		return 0;
	}

	if( n == 2)			//2Ϊ����
	{
		return 1;
	}
	
	for(int i = 3; (i * i) <= n; i += 2 )		//1��ż����2���⣬��������
	{											//2�����������κ�ż����������������so i += 2
		if( n % i == 0 )
		{
			return 0;
		}
	}
	return 1;
}
//�򵥵�ɸѡ��
void isPrimeByEra(const int n)
{
	int flag =0;
	bool isPrime[MAX];
	isPrime[0] = false;
	isPrime[1] = false;	

	for(int i = 2; i < n; i++ )
	{
		isPrime[i] = true;
	}

	for(int j = 2; j < n; j++)
	{
		if( isPrime[j] )
		{
			for(int k = j + j; k < n; k += j)
			{
				isPrime[k] = false;
			}
		}
	}
	while( flag < n )
	{
		if( isPrime[flag] == true )
		{
			cout << flag << "\t";
		}
		
		flag++;
	}
	
}

//����ɸѡ����������
#define MAX 1000 
bool isprime[MAX]; 
int p[MAX]; 
void primeHigh(int n) 
{   
	memset(isprime, 0, sizeof(isprime));   
	memset(p, 0, sizeof(p));  
	int np = 0, i, j;  
	for(i = 2; i <= n; i++)  
	{    
		if(!isprime[i]) p[np++] = i;    
		for(j = 0; j < np && p[j]*i <= n; j++)   
		{     
			isprime[p[j]*i] = 1;    
			if(i % p[j] == 0) 
				break;   
		}  
	} 
}    

int IsPrimeHigh(int n) 
{   
	if(n < 2) 
		return 0;	
	for(int i = 0; p[i]*p[i]<= n; i++)  
		if(n%p[i] == 0)    
			return 0;  
	return 1; 
} 




//-------------4�������������ʱ��-----------------//
int recursion(int x)
{
	
	if( x == 1 )
	{
		return 1;
	}
	else
	{
		return x + recursion( x - 1 );
	}
}
void testRecursionTime()
{
	double res = recursion( 60 );	
	cout << res << endl;
	
	cout << clock() / CLOCKS_PER_SEC << endl;

}
//-------------2��ʵ��ÿ���10��Ԫ�أ��ͻ��У������-----------------//
//-------------2��ʵ��ÿ���10��Ԫ�أ��ͻ��У������-----------------//
//-------------2��ʵ��ÿ���10��Ԫ�أ��ͻ��У������-----------------//


int main()
{
	//testRand();
	//TestSRand();
	//testGcd();
	//cout << isPrimer( 99 ) << endl;
	//primeHigh(19);
	//cout << IsPrimeHigh( 19 ) << endl;
	
	//testRecursionTime();
	isPrimeByEra(100);
	return 0;
}