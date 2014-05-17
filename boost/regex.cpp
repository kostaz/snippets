#include <string>
#include <boost/regex.hpp>

using namespace std;

bool validate_card_format(const string& s)
{
	static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
	return boost::regex_match(s, e);
}

int main()
{
	const int num_of_strings = 4;
	string s[num_of_strings] = {
		"0000111122223333",
		"0000 1111 2222 3333",
		"0000-1111-2222-3333",
		"000-1111-2222-3333",
	};

	for (int i = 0; i < num_of_strings; i++)
	{
		cout << "validate_card_format(\"" << s[i] << "\") returned "
		     << validate_card_format(s[i]) << endl;
	}

	return 0;
}

