#include "replace.hpp"

int replace(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string content;
	std::string res;

	if(s1.length() == 0)
	{
		std::cout << "s1.length can not be 0\n";
		return (1);
	}

	ifs.open(filename);
	if (!ifs)
	{
		std::cout << "Failed to open " << filename << "\n";
		return (1);
	}

	ofs.open(filename + ".replace");
	if (!ofs)
	{
		std::cout << "Failed to open " << filename << "\n";
		return (1);
	}

	ifs >> content;
	int i = 0;
	while (i < content.length())
	{
		int occ = content.find(s1, i);
		if (occ != -1)
		{
			while (i < occ)
				res.push_back(content[i++]);
			res.append(s2);
			i += s1.length();
		}
		else if (occ == -1)
		{
			while (i < content.length())
				res.push_back(content[i++]);
		}
	}
	res.push_back('\n');

	ofs << res;

	return 0;
}
