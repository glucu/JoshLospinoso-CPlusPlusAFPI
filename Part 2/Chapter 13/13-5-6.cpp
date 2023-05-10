#include <chrono>
#include <cstdio>
#include <random>
#include <map>
#include <vector>

long fib_sum(size_t n) {
	if (n == 0) {
		return 0;
	}
	long a = 0, b = 1, c = 1, sum = 1;
	for (size_t i = 2; i < n; ++i) {
		c = a + b;
		sum += c;
		a = b;
		b = c;
	}
	return sum;
}

long random() {
	static std::mt19937_64 mt_engine{ 102787 };
	static std::uniform_int_distribution<long> int_d{ 1000, 2000 };
	return int_d(mt_engine);
}

struct Stopwatch {
	Stopwatch(std::chrono::nanoseconds& result)
		: result{ result },
		start{ std::chrono::system_clock::now() } { }
	~Stopwatch() {
		result = std::chrono::system_clock::now() - start;
	}
private:
	std::chrono::nanoseconds& result;
	const std::chrono::time_point<std::chrono::system_clock> start;
};

long cached_fib_sum(const size_t& n) {
	static std::vector<long> cache(2, 0);
	if (n < cache.size()) {
		return cache[n];
	}
	long a = cache.back(), b = cache[cache.size() - 2], c = 0, sum = a + b;
	for (size_t i = cache.size(); i <= n; ++i) {
		c = a + b;
		sum += c;
		a = b;
		b = c;
		cache.push_back(sum);
	}
	return sum;
}

int main() {

	size_t samples{ 1'000'000 };
	std::chrono::nanoseconds elapsed;

	{
		Stopwatch stopwatch{ elapsed };
		volatile double answer;
		while (samples--) {
			//answer = fib_sum(random());
			answer = cached_fib_sum(random());
		}
	}

	printf("Elapsed: %g s.\n", elapsed.count() / 1'000'000'000.);
}