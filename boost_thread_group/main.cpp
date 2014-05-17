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

#ifdef BOOST_THREAD_PROVIDES_INTERRUPTIONS
#warning BOOST_THREAD_PROVIDES_INTERRUPTIONS are enabled!
	{
		boost::thread_group threads;
		for (int i = 0; i < 3; i++)
			threads.create_thread(&increment_count);
		threads.interrupt_all();
		threads.join_all();
	}
#endif

	{
		boost::thread_group threads;
		boost::thread *th = new boost::thread(&increment_count);
		threads.add_thread(th);
		threads.join_all();
	}

	{
		{
			boost::unique_lock<boost::mutex> lock(mutex);
			boost::thread *th2 = new boost::thread(&increment_count_2);
			threads2.add_thread(th2);
		}
		threads2.join_all();
	}

	return 0;
}

