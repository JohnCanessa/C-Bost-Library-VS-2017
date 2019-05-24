#include "pch.h"

#include <iostream>

#include <algorithm>
#include <iterator>
#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>

using boost::uuids::detail::md5;
using namespace std;


/*
* Convert MD5 digest to string.
*/
string digestToString(const md5::digest_type &digest) {

	// **** convert to char[] ****
	const auto charDigest = reinterpret_cast<const char *>(&digest);

	// **** output string ****
	string str;

	// **** convert char[] digest to string ****
	boost::algorithm::hex(charDigest, charDigest + sizeof(md5::digest_type), std::back_inserter(str));

	// **** return digest string ****
	return str;
}


/*
* Test scaffolding.
*/
int main()
{

	// **** general purpose string ****
	string str;

	// **** welcome message ****
	cout << "MD5 using boost!!!\n\n";

	// **** prompt for first string ****
	cout << "main >>> str: ";

	// **** loop processing input ****
	while (getline(cin, str)) {

		// **** check if we are done ****
		if (str.compare(string("-1")) == 0) {
			cout << "main <<< bye bye\n";
			break;
			}

		// **** display string ****
		cout << "main <<< str ==>" << str << "<==\n";

		// **** generate MD5 digest ****
		md5 hash;
		md5::digest_type digest;

		hash.process_bytes(str.data(), str.size());
		hash.get_digest(digest);

		// **** convert to string and display MD5 digest ****
		cout << "main <<< digest ==>" << digestToString(digest) << "<==\n";

		// **** prompt for next string ****
		cout << "main >>> str: ";
	}
}
