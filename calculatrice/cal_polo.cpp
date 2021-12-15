#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
  int i;
  float a;
  float b;
  std::vector<float> op;
  for (i=1; i < argc ; i++)
  {
    if (std::string(argv[i]) == "+")
    {
      a = op.back();
      op.pop_back();
      b = op.back();
      op.pop_back();
      op.push_back(a + b);
      continue;
    }
    if (std::string(argv[i]) == "-")
    {
      a = op.back();
      op.pop_back();
      b = op.back();
      op.pop_back();
      op.push_back(b - a);
      continue;
    }
    if (std::string(argv[i]) == "x")
    {
      a = op.back();
      op.pop_back();
      b = op.back();
      op.pop_back();
      op.push_back(a * b);
      continue;
    }
    if (std::string(argv[i]) == "/")
    {
      a = op.back();
      op.pop_back();
      b = op.back();
      op.pop_back();
      op.push_back(b / a);
      continue;
    }
    op.push_back(std::atof(argv[i]));
  }
  std::cout << "résultat : " << op.back() << std::endl;
  return 0;
}
