#ifndef INCIDENCYMATRIX_H
#define INCIDENCYMATRIX_H
#include <string>
#include <vector>
/**
* @author   Adam Szczepanski
* @date 08.05.2017
* @brief The Incidency Matrix class
*  This class represents hypergraph as matrix. In this mastix the Hyperedges are
* on rowsand Vertexes are on columns.
*  Values in matrix is 0 if this vertex dont belong in this hyperedge and 1 if
* is.
*/
class IncidencyMatrix {
public:
  /** @brief constructor of IncidencyMatrix class
  *
  */
  explicit IncidencyMatrix(const int numberOfVertexes = 0);

  /** @brief destructor of IncidencyMatrix class
  *
  */
  ~IncidencyMatrix() {}

  /** @brief create new Vertexes and add them to matrix
  *   @param numberOfVertexes indcate how many vertexes to create
  */
  void createVertexes(const int numberOfVertexes = 1);

  /** @brief remove Vertex from matrix
  *   @param position indcate which vertex to remove
  */
  void removeVertex(const int position);

  /** @brief create empty hyperedges and add them to matrix
  *   @param numberOfHyperEdges indcate how many hyperedges to create
  */
  void createHyperEdges(const int numberOfHyperEdges = 1);

  /** @brief add hyperedge to matrix
  *   @param hyperedge is reference to hyperedge which we want to add
  */
  void addHyperEdge(const std::vector<int> &hyperedge);

  inline void setHyperEdge(const int pos, const std::vector<int> &hyperedge) {
    incidencyMatrix[pos] = hyperedge;
  }

  /** @brief remove hyperedge from matrix
  *   @param position indcate which hyperedge to remove
  */
  void removeHyperEdge(const int position);

  /** @brief Change value in matrix
  *   @param positionOfHyperEdge indcate on which hyperedge value should be
  * changed
  *   @param positionOfVertex indcate on which vertex value should be changed
  *   @param value new value of element in matrix it should be 0 or 1
  */
  void setConnection(const int positionOfHyperEdge, const int positionOfVertex,
                     const int value);

  /** @brief get value from matrix from specific position
  *   @param positionOfHyperEdge indcate from which hyperedge it should take
  * value
  *   @param positionOfVertex indcate from which vertex it should take value
  *   @return 1 if vertex is connected to hyperedge
  *   @return 0 if vertex is not conneted to hyperedge
  */
  int getConnection(const int positionOfHyperEdge,
                    const int positionOfVertex) const;

  /** @brief Change whole IncidencyMatrix
  *   @param newMatrix value of new Incidency Matrix
  */
  inline void
  setIncidencyMatrix(const std::vector<std::vector<int>> &newMatrix) {
    incidencyMatrix = newMatrix;
  }

  /** @brief Returns whole incidency Matrix
  *   @return  constance reference to incidencyMatrix
  */

  inline const std::vector<std::vector<int>> &getIncidencyMatrix() const {
    return incidencyMatrix;
  }

  /** @brief Returns whole incidency Matrix
  *   @return  constance reference to incidencyMatrix
  */

  inline std::vector<std::vector<int>> &getIncidencyMatrix() {
    return incidencyMatrix;
  }

  inline int getNumberOfVertexes() const { return numberOfVertexes; }

  inline int getNumberOfHyperEdgess() const { return incidencyMatrix.size(); }

  /**
  * @brief Create file in specyfic name and saves hypergraph in it
  *   @param nameWithPath name of file in which we want save hypergraph
  */
  void tofile(const std::string &nameWithPath) const;

  // Implement this xD
  void print() const;

protected:
private:
  std::vector<std::vector<int>>
      incidencyMatrix;  /**< Incidency Matrix of hypergraph  */
  int numberOfVertexes; /**< Number of Vertexes  in hypergraph */
};

#endif // INCIDENCYMATRIX_H
