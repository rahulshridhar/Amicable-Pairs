#include "amicable.h"

amicable::amicable(int n): _range(n), _factors(n)
{
    a = new bool [_range+1];

    _prime = new int[5000000];
    
    _sum = new int[_range];
    memset(_sum, 0, _range*sizeof(int));
    
    _generatePrime();
    _getPair();
}

amicable::~amicable ()
{
    delete [] a;
    delete [] _prime;
    delete [] _sum;
}

void amicable::_generatePrime()
{
    a[1] = true;
    int index=0;
    for (int i = 2; i * i <= _range; i++)
    {
        if (!a[i])
        {
            _prime[index++] = i;
            int multiple = 2;
            while (i * multiple <= _range) {
                a[i * multiple++] = true;
            }
        }
    }
}

int amicable::_sumFactors(int n)
{
    int sum = 1;
    int num_index = 1;
    int power_index = 2;
    while (_factors[n][num_index] != 0)
    {
        int power = _factors[n][power_index];
        int inner_sum = 1;
        while (power>0)
        {
            inner_sum += pow(_factors[n][num_index], power);
            power--;
        }
        sum *= inner_sum;
        num_index+=2;
        power_index+=2;   
    }
    return (sum-n);
}

void amicable::_computeFactors(int number)
{
    _factors[number][0] = number;
    int temp = number;
    int add = 1;
    for (int i=0; i <= sqrt(number); i++) 
    {
        if (temp == 1) break;
        int p = _prime[i];
        if (temp%p == 0)
        {
            _factors[number][add++] = p;
            temp/=p;
            if (temp == p)
            {
                _factors[number][add++] = 2;
                break;
            }
            else if (temp % p == 0)
            {
                int j = 2;
                while (_factors[temp][j] != 0)
                {
                    if (j==2) _factors[number][add++] = _factors[temp][j++]+1;
                    else _factors[number][add++] = _factors[temp][j++];
                }
                break;
            }
            else if (!a[temp])
            {
                _factors[number][add++] = 1;
                _factors[number][add++] = temp;
                _factors[number][add++] = 1;
                break;
            }
            else
            {
                _factors[number][add++] = 1;
                int j = 1;
                while (_factors[temp][j] != 0)
                {
                    _factors[number][add++] = _factors[temp][j++];
                }
                break;
            }
        }
    }
    _factors[number][add] = 0;
}

void amicable::_getPair() {
    int count = 0;
    for (int i = 2; i < _range; ++i)
    {
        int _a = i%2;
        int _b = i%3;
        int _ab = i%6;
        
        /* Amicable pairs numbers are not prime */
        if (!a[i]) continue;
        
        /* Even amicable numbers cannot be divisible by 3 */
        if (_ab==0) continue;
        if (_a==0 && _b==0) continue;

        int sum = 0;
        if (_sum[i] != 0) {
            sum = _sum[i];
        }
        else {
            _computeFactors(i);
            sum = _sumFactors(i);
            _sum[i] = sum;
        }
        
        /* Odd amicable pairs are divisible by 3 */ 
        if ((i%2!=0) && (i%3!=0) && (sum%2!=0) && (sum%3!=0)) continue;

        int _c = sum%2;
        int _d = sum%3;
        int _cd = sum%6;

        /* Even amicable numbers cannot be divisible by 3 */
        if (_cd==0) continue;
        if (_c==0 && _d==0) continue;
        
        /* Amicable pairs are either both even or both odd */
        if ((_c==0) && (_a!=0)) continue;
        if ((_c!=0) && (_a==0)) continue;

        if (sum < i)
        {
            int sum2 = _sum[sum];
            /* Amicable pairs are either both even or both odd */
            if ((sum2%2==0) && (sum%2!=0)) continue;
            if ((sum2%2!=0) && (sum%2==0)) continue;
            
            if ( i == sum2 ) {
                cout<<count++<<": "<<sum<<" and "<<i<<endl;
            }
        }
    }
}
