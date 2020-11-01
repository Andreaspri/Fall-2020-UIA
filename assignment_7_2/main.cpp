#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::vector<float> nums;
    float input=0;
    int count=0;
    float sum=0;
    float median=0;

    while (true)
    {
        std::cin >> input;
        if (input == 0)
            break;
        nums.push_back(input);
        sum += input;
        count++;
    }
    std::sort(nums.begin(),nums.end());
    if (count%2 == 0)
        median = (nums[(count-1)/2] + nums[(count)/2])/2;
    else
        median = nums[(count-1)/2];

    std::cout << "Average : " << sum/count << std::endl;
    std::cout << "Median : " << median << std::endl;
    std::cout << "Descending : ";
    for (int i=(count-1);i>=0;i--)
        std::cout << nums[i] << " ";
    return 0;
}
