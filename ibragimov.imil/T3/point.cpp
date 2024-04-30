#include "point.hpp"

#include <iostream>
#include "../common/streamGuard.hpp"
#include "delimiter.hpp"

std::istream& ibragimov::operator>>(std::istream& in, Point& rhs)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  using namespace detail;
  StreamGuard sguard(in);
  in >> std::noskipws;
  in >> Delimiter{'('} >> rhs.x >> Delimiter{';'} >> rhs.y >> Delimiter{')'};
  if (!in)
  {
    in.setstate(std::ios::failbit);
  }
  return in;
}