#ifndef HYPERGRAPHMANAGER_H
#define HYPERGRAPHMANAGER_H
#include "HGStruct/hypergraph.h"
#include "Matrix/incidencymatrix.h"
#include <algorithm>
#include <functional>
#include <vector>
/**
 * @author   Adam Szczepanski
 * @date 10.05.2017
 *  @brief Manager class fo HyperGraph
 *  This class is for changing HaperGraph from 1 representation to other
 *
*/
class HyperGraphManager {
public:
  HyperGraphManager();

  static double calculateAverageK(const IncidencyMatrix &hyperGraph);
  static double calculateAverageK(const std::vector<int> &kTable);
  static std::vector<int> *calculateKTable(const IncidencyMatrix &hyperGraph);
  static std::vector<int> *
  generateKTable(const std::function<int()> &kDistribution, const int size);

  static double calculateAverageP(const IncidencyMatrix &hyperGraph);
  static double calculateAverageP(const std::vector<int> &pTable);
  static std::vector<int> *calculatePTable(const IncidencyMatrix &hyperGraph);
  static std::vector<int> *
  generatePTable(const std::function<int()> &pDistribution, const int size);

  // TODO : implementthis two metods
  // static HyperGraph& IncidencyMatrixToHyperGraph(IncidencyMatrix& matrix);
  // static IncidencyMatrix& HyperGraphToIncidencyMatrix(HyperGraph&
  // hypergraph);

protected:
private:
};

#endif // HYPERGRAPHMANAGER_H
