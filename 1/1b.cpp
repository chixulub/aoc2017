#include <iostream>

int main(int, char**)
{
  std::string str;
  std::getline(std::cin,str);

  int sum = 0;
  int len = (int)str.length();
  for (int i = 0; i < len; ++i)
  {
    if (str[i] == str[(i+(len/2))%len])
    {
      sum += (str[i]-'0');
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
