#include <boost/timer/timer.hpp>
#include <boost/thread.hpp>
#include <boost/ref.hpp>
#include <iostream>
#include <cstdint>

void count(int start, int end, std::uint64_t& tot)
{
	for(int i = start; i < end; i++)
		tot += i;
}

int main()
{
    boost::timer::cpu_timer timer;

    std::uint64_t tot1 = 0, tot2 = 0;
	boost::thread thread_1(count, 0, 5000000, boost::ref(tot1));
	boost::thread thread_2(count, 5000001, 10000000, boost::ref(tot2));
	thread_1.join();
	thread_2.join();
	
	auto total = tot1 + tot2;
	// now print the result
    std::cout << timer.format();
    std::cout << total << '\n';
}
