#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)(numbers[first] * numbers[second]));
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
	long long max_product = 0;
	int n = numbers.size(), max_index_1 = -1, max_index_2 = -1;
	
	for (int i=0; i<n; i++)
		if (max_index_1 == -1 || numbers[i] > numbers[max_index_1])
			max_index_1 = i;
	
	for (int i=0; i<n; i++)
		if ((numbers[i] > numbers[max_index_2] || max_index_2 == -1) && i != max_index_1)
			max_index_2 = i;
	
	max_product = (long long)numbers[max_index_1] * (long long)numbers[max_index_2];
	return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
