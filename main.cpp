#include "Tests/guitest.h"
#include "Tests/incidencymatrixtests.h"
#include <iostream>
#include <cassert>
int main( [[maybe_unused]] int argc,[[maybe_unused]] char *argv[]) {
  //  return IncidencyMatrixTest1(argc,argv);
  std::cout.sync_with_stdio(false);
  return guiTest1(argc, argv);
}
