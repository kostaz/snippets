#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>

using namespace std;
using namespace boost;

void workerFunc()
{
	posix_time::seconds workTime(3);
	cout << "worker: running..." << endl;
	this_thread::sleep(workTime);
	cout << "worker: finished." << endl;
}

int main ()
{
	cout << "main: startup" << endl;
	thread workerThread(workerFunc);

	cout << "main: waiting for thread" << endl;
	workerThread.join();

	cout << "main: done" << endl;
	return 0;
}

