#include <iostream>
#include <boost/thread.hpp>
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
    std::cout << "other begin" << std::endl;	
	for (int i = 0; i < 5; ++i)
	{                          
		wait(2);                 
		std::cout << i << '\n';  	
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
	boost::thread t{another};  // At this point, 
	boost::thread s{other};   // s,t are running concurrently with main

	thread();
	// To stop the program from ending we call join(). 
	t.join();
	s.join();
	// This blocks the current thread(the one on which main is running)
	// untill the threads s,t have terminated
	
}
