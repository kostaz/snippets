#include <boost/thread/thread.hpp>
#include <iostream>

int count = 0;
boost::mutex mutex;

void increment_count()
{
	boost::unique_lock<boost::mutex> lock(mutex);
	std::cout << "count = " << ++count << std::endl;
}

boost::thread_group threads2;
boost::thread *th2 = 0;

void increment_count_2()
{
	boost::unique_lock<boost::mutex> lock(mutex);
	std::cout << "count = " << ++count << std::endl;
}

int main()
{
	{
		boost::thread_group threads;
		for (int i = 0; i < 3; i++)
			threads.create_thread(&increment_count);
		threads.join_all();
	}
	return 0;
}

