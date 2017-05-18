#ifndef HYPERGRAPH_H
#define HYPERGRAPH_H
#include"vertex.h"
#include"hyperedge.h"
#include<vector>

/**
* @author   Adam Szczepanski
* @date 08.05.2017
* @brief The HyperGraph class
*  This class is data structure representation of hypergraph . Id of every vertex and hyperedge should be diffrent.
*/
class HyperGraph
{
    public:

        /**
        * @brief Create an HyperGraph
        *  @remark create Hypergraph with fix number of vertexes
        *  @param numberOfVertexes initial number for vertexes in hypergraph
        */
        HyperGraph(const int numberOfVertexes=0);

        /**
        * @brief Destructor of HyperGraph
        */
        virtual ~HyperGraph(){}

        /**
        * @brief Create new vertexes and add them to hypergraph
        * @param numberOfVertexes number for vertexes which we want add to hypergraph
        */
        void createVertex(const int numberOfVertexes=1);

        /**
        * @brief remove vertex from hypergraph
        * @param vertexId id of vertex which we want to remove from hypergraph
        */
        void removeVertex(const int vertexId);

        /**
        * @brief check if vertex with this id exists in hypergraph
        * @param vertexId id of vertex
        * @return true if Containing
        * @return false if not Containing
        */
        bool isContainingVertex(const int vertexId)const;

        /**
        * @brief Create new HyperEdge and add them to hypergraph
        * @param numberOfHyperEdges number for HyperEdge which we want add to hypergraph
        */
        void createHyperEdge(const int numberOfHyperEdges=1);

        /**
        * @brief add HyperEdge  to hypergraph
        * @param listOfVertexes list of vertexes we want to add
        */
        void addHyperEdge(const std::vector<Vertex*>& listOfVertexes);

        /**
        * @brief remove HyperEdge from hypergraph
        * @param hyperedgeID list of hyperedge which we want to remove from hypergraph
        */
        void removeHyperEdge(const int hyperedgeID);

        /**
        * @brief check if HyperEdge with this id exists in hypergraph
        * @param hyperedgeID id of HyperEdge
        * @return true if Containing
        * @return false if not Containing
        */
        bool isContainingHyperEdge(const int hyperedgeID)const;

        /**
        * @brief add vertex to HyperEdge  in hypergraph
        * @param hyperedge hyperedge to which we want add vertex
        * @param vertex vertex which we want add
        */
        void addVertexToHyperEdge(HyperEdge* hyperedge,Vertex* vertex);

        /**
        * @brief return Vertex from vector from inputed position
        * @param position from which we want get vertex
        * @return pointer to selected Vertex
        */
        inline Vertex* getVertex(const int position){return &Vertexes[position];}

        /**
        * @brief return HyperEdge from vector from inputed position
        * @param position from which we want get HyperEdge
        * @return pointer to selected hyperedge
        */
        inline HyperEdge* getHyperEdge(const int position){return &HyperEdges[position];}

        /**
        * @brief To get vector of all vertexes in hypergraph
        * @return vector of vertexes
        */
        inline  std::vector<Vertex>& getVertexes() {return Vertexes;}

        /**
        * @brief To get vector of all HyperEdges in hypergraph
        * @return vector of HyperEdges
        */
        inline  std::vector<HyperEdge>& getHyperEdges() {return HyperEdges;}

        void print()const;
    protected:
    private:

        std::vector<Vertex> Vertexes; /**< vector of vertexes in hypergraph */
        std::vector<HyperEdge> HyperEdges;/**< vector of hyperedges in hypergraph */

        int validVertexId=1; /**< next valid id for vertex */
        int validHyperEdgeId=1;/**< next valid id for HyperEdgeId */
};

#endif // HYPERGRAPH_H
