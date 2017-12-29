#ifndef amicable_H
#define amicable_H

#include "../util/util.h"
#include "../darray/darray.h"

class amicable {
    private:
        int _range;  // Range to find the amicable pairs
        bool* a;
        int* _sum;
        int* _prime;
        int _count;
        darray < darray<int> > _factors;
        static bool display;
        void _generatePrime();
        void _getPair();
        int _sumFactors(int n);
        void _computeFactors(int number);

    public:
        amicable(int n=0);
        ~amicable();
};


#endif
