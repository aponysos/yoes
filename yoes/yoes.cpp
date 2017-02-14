#include <vector>
#include <string>
#include <fstream>
#include <tuple>
#include <sstream>
#include "yoes.h"

using namespace std;

yoes::yoes()
{
}

yoes::~yoes()
{
}

bool yoes::load_headwords_txtfile(const std::string & headwords_file)
{
  ifstream ifs(headwords_file);
  if (!ifs)
    return false;

  char buf[32];
  while (ifs.getline(buf, sizeof(buf)))
  {
    string line(buf);
    if (line.length() > 0)
      headwords_.push_back(line);
  }

  return true;
}

bool yoes::load_findoutmore_txtfile(const std::string & findoutmore_file)
{
  ifstream ifs(findoutmore_file);
  if (!ifs)
    return false;

  char buf[32];
  while (ifs.getline(buf, sizeof(buf)))
  {
    istringstream iss(buf);
    fdm_entry fdm;
    string sep;

    iss >> fdm.from;
    if (iss.fail()) return false;

    iss >> sep;
    if (iss.fail() || sep != "->") return false;

    iss >> fdm.to;
    if (iss.fail()) return false;

    iss >> sep;
    if (iss.fail() || sep != ":") return false;

    iss >> fdm.type;
    if (iss.fail()) return false;

    findoutmore_.push_back(fdm);
  }

  return true;
}

bool yoes::dump_txtfile(std::ostream & os)
{
  for (auto fdm : findoutmore_)
    os << fdm.type << ":" << headwords_[fdm.from] << "->" << headwords_[fdm.to] << '\n';
  os.flush();

  return true;
}
