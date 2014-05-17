#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Path missing" << endl;
		return 1;
	}

	path path(argv[1]);

	try {
		if (!exists(path))
		{
			cout << "Wrong path"<< endl;
		}
		else if (is_regular_file(path))
		{
			cout << path << " size is: " << file_size(path) << endl;
		}
		else if (is_directory(path))
		{
			cout << path << " is directory containing:" << endl;

			typedef vector<boost::filesystem::path> vec;
			vec v;

			copy(directory_iterator(path), directory_iterator(),
			     back_inserter(v));

			sort(v.begin(), v.end());

			for (vec::const_iterator it(v.begin()), it_end(v.end());
			     it != it_end; ++it)
			{
				cout << "   " << *it << endl;
			}
		}
	} catch (const filesystem_error& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}

