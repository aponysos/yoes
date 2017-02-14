#pragma once

class yoes
{
  struct fdm_entry
  {
    int from;
    int to;
    int type;
  };

public:
  yoes();
  ~yoes();

public:
  bool load_headwords_txtfile(const std::string & headwords_file);
  bool load_findoutmore_txtfile(const std::string & findoutmore_file);
  bool dump_txtfile(std::ostream & os);

private:
  std::vector<std::string> headwords_;
  std::vector<fdm_entry> findoutmore_;

};
