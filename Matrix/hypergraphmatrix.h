#ifndef HYPERGRAPHMATRIX_H
#define HYPERGRAPHMATRIX_H
#include<vector>
#include<string>
/**
* @author   Adam Szczepanski
* @date 09.05.2017
* @brief The HyperGraphMatrix class
*  This class is matrix representation of hypergraph.
*/
class HyperGraphMatrix
{
public:
    /**
     * @brief constructor of HyperGraphMatrix class
     */
    explicit HyperGraphMatrix(int numberOfVertexes=0);

     /** @brief destructor of HyperGraphMatrix class
     *
     */
    virtual ~HyperGraphMatrix(){}

    /** @brief create new Vertexes and add them to matrix
    *   @param numberOfVertexes indcate how many vertexes to create
    */
    void createVertexes(int numberOfVertexes=1);

    /** @brief remove Vertex from matrix
    *   @param position indcate which vertex to remove
    */
    void removeVertex(int position);

    /** @brief create empty hyperedges and add them to matrix
    *   @param numberOfHyperEdges indcate how many hyperedges to create
    */
    void createHyperEdges(int numberOfHyperEdges=1);

    /** @brief add hyperedge to matrix
    *   @param hyperedge is reference to hyperedge which we want to add
    */
//    void addHyperEdge(const std::vector<int>& hyperedge);

    /** @brief remove hyperedge from matrix
    *   @param position indcate which hyperedge to remove
    */
    void removeHyperEdge(int position);

    /** @brief Change value in matrix
    *   @param positionOfHyperEdge indcate on which hyperedge value should be changed
    *   @param positionOfVertex indcate on which vertex value should be changed
    *   @param value new value of element in matrix it should be 0 or 1
    */
    void setConnection (int positionOfVertex,int positionOfHyperEdge, int value);

    /** @brief get value from matrix from specific position
    *   @param positionOfHyperEdge indcate from which hyperedge it should take value
    *   @param positionOfVertex indcate from which vertex it should take value
    *   @return 1 if vertex is connected to hyperedge
    *   @return 0 if vertex is not conneted to hyperedge
    */
    int getConnection (int positionOfVertex,int positionOfHyperEdge);

    /** @brief Returns whole incidency Matrix
    *   @return  constance reference to incidencyMatrix
    */
    inline const std::vector<std::vector<int>> & getMatrix(){return matrix;}

    /** @brief Create file in specyfic name and saves hypergraph in it
    *   @param nameWithPath name of file in which we want save hypergraph
    */
    void tofile(std::string& nameWithPath);
    //Implement this
    void print();
protected:
private:
    std::vector<std::vector<int>> matrix;/**< Matrix of hypergraph  */

};

#endif // HYPERGRAPHMATRIX_H
