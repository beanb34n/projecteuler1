#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

//LCM of a subset of the numbers
int lcm_of_vector(const std::vector<int>& numbers,long long index) {
    // Initialize the lcm with the first element of the vector
    int result_lcm = 1;

    // Iterate through the vector and update the lcm
    for (size_t i = 0; i < numbers.size(); ++i) {
        if(index&1)
        {
            result_lcm = std::lcm(result_lcm, numbers[i]);
        }
        index>>=1;
    }

    return result_lcm;
}

//Find number of elements in the subset, to apply PIE
int parity_of_index(long long index) {

    int parity = -1;


    while(index>0) {
        if(index&1)
        {
            parity*=(-1);
        }
        index>>=1;
    }

    return parity;
}

//Sum of all multiples of a number
int sum_of_multiples(int n, int limit)
{
    if(n==0) return 0;
    int number_of_terms=limit/n;
    return (number_of_terms)*(number_of_terms+1)*(n)/2;
}
//Calculates the result using Principle of inclusion and exclusion(PIE)
long long answer(const std::vector<int>& numbers,int limit)
{
    long long sum=0;
    long long index_limit=1<<numbers.size();
    int parity;
    for(long long i=1;i<index_limit;i++)
    {
        parity=parity_of_index(i);
        //cout<<lcm_of_vector(numbers,i)<<endl;
        sum+=parity*sum_of_multiples(lcm_of_vector(numbers,i),limit);
    }
    return sum;
}

int main()
{
    std::vector<int> input_vector = {4, 6,10};
    int limit=999;
    //cout << lcm_of_vector(input_vector,3)<< endl;
    cout << answer(input_vector,limit)<< endl;
    return 0;
}
