#include <string>
#include <boost/regex.hpp>

using namespace std;

bool validate_card_format(const string& s)
{
	static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
	return boost::regex_match(s, e);
}

const boost::regex e("\\A(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
const string machine_format("\\1\\2\\3\\4");
const string human_format("\\1-\\2-\\3-\\4");

string machine_readable_card_number(const string& s)
{
	return boost::regex_replace(s, e, machine_format, boost::match_default | boost::format_sed);
}

string human_readable_card_number(const string& s)
{
	return boost::regex_replace(s, e, human_format, boost::match_default | boost::format_sed);
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

	for (int i = 0; i < num_of_strings; i++)
	{
		cout << "machine_readable_card_number(\"" << s[i] << "\") returned "
		     << machine_readable_card_number(s[i]) << endl;
	}

	for (int i = 0; i < num_of_strings; i++)
	{
		cout << "human_readable_card_number(\"" << s[i] << "\") returned "
		     << human_readable_card_number(s[i]) << endl;
	}

	return 0;
}

