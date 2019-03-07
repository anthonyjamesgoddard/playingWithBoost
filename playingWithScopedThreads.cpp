#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>

void wait(int seconds)
{
  boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread()
{
	std::cout << "thread begin" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		wait(1);
		std::cout << i << '\n';
	}
	std::cout << "thread end" << std::endl;
}

void other()
{
	try
	{
		std::cout << "other begin" << std::endl;	
		for (int i = 0; i < 5; ++i)
		{                          
			wait(2);                 
			std::cout << i << '\n';  	
		}
	}
	catch(boost::thread_interrupted&)
	{
		// do nothing
	}
    std::cout << "other end" << std::endl;	
}

void another()
{
    std::cout << "another begin" << std::endl;	
	for (int i = 0; i < 5; ++i)
	{                          
		wait(3);                 
		std::cout << i << '\n';  	
	}
    std::cout << "another end" << std::endl;	
}


int main()
{
	std::cout << "hello" << std::endl;
	boost::scoped_thread<> t{boost::thread{another}};  // At this point, 
	boost::scoped_thread<> s{boost::thread{other}};   // s,t are running concurrently with main
	// as the scoped pointer goes out of scope join() is called
	// which forces the current thread to wait untill execution has finished.
	thread();
	wait(1);
	t.interrupt(); // does nothing as another() has no exception handling
	s.interrupt(); // prevents s from finishing as we have added exeption handling

	// interrupts may not always be the best option as we
	// have to reach the s.interrupt() in the current thread

	std::cout << "this computer has " << boost::thread::hardware_concurrency()
			  << " threads" << std::endl;
	
}
