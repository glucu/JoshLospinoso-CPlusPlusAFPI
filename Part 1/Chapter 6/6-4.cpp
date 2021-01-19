#include <cstdio>
#include <cstddef>

/*  Refactor mean in Listing 6-13 to accept an array rather than pointer and
 *  length arguments. Use Listing 6-33 as a guide. 
 */


template <std::size_t Index, typename T, std::size_t Length>
T mean(const T(&values)[Length]) {

	T result{ };

	for (std::size_t i{ Index }; i < Length; ++i) {

		result += values[i];
	}

	return result / Length;
}

int main() {

	const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
	const auto result1 = mean<0, double, 4>(nums_d); 
	printf("double: %f\n", result1);

	const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
	const auto result2 = mean<0, float, 4>(nums_f); 
	printf("float: %f\n", result2);

	const size_t nums_c[]{ 1, 2, 3, 4 };
	const auto result3 = mean<0, size_t, 4>(nums_c); 
	printf("size_t: %zd\n", result3);

	return 0;
}