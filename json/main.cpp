#include "json.hpp"

#include <iterator>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int
main(int argc, char* argv[])
{
	std::ifstream redditJSON;
	redditJSON.open ("json_from_reddit.txt");
	
	std::stringstream buffer;
	
	if (redditJSON)
    {
        buffer << redditJSON.rdbuf();

        redditJSON.close();   
    }
	
	std::istreambuf_iterator<char> first(buffer);
	std::istreambuf_iterator<char> last;
	std::string s(first, last);
	
	std::vector<std::string>names;
	std::vector<std::string>titles;
	
	int i = s.length();
	for(int ct = 0; ct < i; ct++)
	{
		if(s[ct] == '"')
		{
			ct++;
			if((s[ct] =  'n') && (s[++ct] = 'a') && ((s[(ct + 2)] = 'm') && (s[(ct + 3)] = 'e'))
			{
				ct += 5;
				
				while(s[ct] != '"')
					ct++;
				
				ct++;
				std::string temp;
				int m =0;
				while(s[ct] != '"')
				{
					temp[m] = s[ct];
					ct++;
					m++;
				}
				
				names.push_back(temp);
			}
			else 
			if((s[ct] =  't') && (s[++ct] = 'i') && ((s[(ct + 2)] = 't') && (s[(ct + 3)] = 'l') && (s[(ct + 4)] = 'e'))
			{
				ct += 6;
				
				while(s[ct] != '"')
					ct++;
				
				ct++;
				std::string temp;
				int m =0;
				while(s[ct] != '"')
				{
					temp[m] = s[ct];
					ct++;
					m++;
				}
				
				titles.push_back(temp);
			}
			else{}
	}
	
	std::size_t size = names.size();
	for(int i = 0; i < size; i++)
	{
		json::Value* name = names[i];
		json::Value* title = titles[i];
		title.print(std::ostream, 1, false, false);
		name.print(std::ostream, 1, false, false);
	}

	std::cout << s << std::endl;
}