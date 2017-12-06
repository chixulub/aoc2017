#include <iostream>
#include <cmath>

int N = 361527;

int main(int, char**)
{
  int shell = 1;
  while (shell*shell < N) { shell += 2; }

  int numbersInsideShell = (shell-2)*(shell-2);
  int numbersInShell = shell*shell - numbersInsideShell;
  int posInShell = N - (numbersInsideShell+1);

  int rot = numbersInShell/4;
  while (posInShell >= rot) { posInShell -= rot; }
  
  int xPos = shell/2;
  int yPos = posInShell - xPos + 1;
 
  shell/=2; 
  int cost = shell + std::abs(posInShell - shell + 1);

  std::cout << cost << std::endl;
  return 0;
}
