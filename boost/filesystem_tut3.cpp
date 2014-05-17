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
			cout << "Wrong path"<< endl;

		if (is_regular_file(path))
			cout << path << " size is: " << file_size(path) << endl;

		if (is_directory(path)) {
			cout << path << " is directory containing:" << endl;
			copy(directory_iterator(path), directory_iterator(),
			     ostream_iterator<directory_entry>(cout, "\n"));
		}
	} catch (const filesystem_error& ex) {
		cout << ex.what() << endl;
	}

	return 0;
}

