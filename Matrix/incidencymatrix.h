#ifndef INCIDENCYMATRIX_H
#define INCIDENCYMATRIX_H
#include<vector>
#include<string>
/**
* @author   Adam Szczepanski
* @date 08.05.2017
* @brief The Incidency Matrix class
*  This class represents hypergraph as matrix. In this mastix the Hyperedges are on rowsand Vertexes are on columns.
*  Values in matrix is 0 if this vertex dont belong in this hyperedge and 1 if is.
*/
class IncidencyMatrix
{
    public:
        /** @brief constructor of IncidencyMatrix class
        *
        */
        explicit IncidencyMatrix(int numberOfVertexes=0);

         /** @brief destructor of IncidencyMatrix class
         *
         */
        virtual ~IncidencyMatrix(){}

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
        void addHyperEdge(const std::vector<int>& hyperedge);

        void setHyperEdge(int pos,std::vector<int>& hyperedge){incidencyMatrix[pos]=hyperedge;}

        /** @brief remove hyperedge from matrix
        *   @param position indcate which hyperedge to remove
        */
        void removeHyperEdge(int position);

        /** @brief Change value in matrix
        *   @param positionOfHyperEdge indcate on which hyperedge value should be changed
        *   @param positionOfVertex indcate on which vertex value should be changed
        *   @param value new value of element in matrix it should be 0 or 1
        */
        void setConnection (int positionOfHyperEdge,int positionOfVertex,int value);

        /** @brief get value from matrix from specific position
        *   @param positionOfHyperEdge indcate from which hyperedge it should take value
        *   @param positionOfVertex indcate from which vertex it should take value
        *   @return 1 if vertex is connected to hyperedge
        *   @return 0 if vertex is not conneted to hyperedge
        */
        int getConnection (int positionOfHyperEdge,int positionOfVertex);

        /** @brief Returns whole incidency Matrix
        *   @return  constance reference to incidencyMatrix
        */

        inline  std::vector<std::vector<int>> & getIncidencyMatrix(){return incidencyMatrix;}

        /** @brief Create file in specyfic name and saves hypergraph in it
        *   @param nameWithPath name of file in which we want save hypergraph
        */
        void tofile(std::string& nameWithPath);
        //Implement this
        void print();
        inline  void setIncidencyMatrix(std::vector<std::vector<int>> &newMatrix){incidencyMatrix=newMatrix;}
        inline int getNumberOfVertexes()const{return numberOfVertexes;}
        inline double getK(){return k;}
        inline void setK(double k){this->k=k;}
    protected:
    private:
        std::vector<std::vector<int>> incidencyMatrix;/**<Incidency Matrix of hypergraph  */
        double k;
        int numberOfVertexes; /**< Number of Vertexes  in hypergraph */

};

#endif // INCIDENCYMATRIX_H
