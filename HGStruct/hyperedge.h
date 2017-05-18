#ifndef EDGE_H
#define EDGE_H

#include<memory>
#include<vector>
#include<iostream>
#include"vertex.h"
/**
* @author   Adam Szczepanski
* @date 08.05.2017
* @brief The HyperEdge class.
*  This class represents HyperEdge. Id of every vertex and hyperedge should be diffrent.
*/
class HyperEdge
{
    public:
       /**
        *  @brief Create an HyperEdge with id equal to eID
        *  @param eID id unique id of hyperedge
        */
        explicit HyperEdge(const int eID);

        /**
        *  @brief Create an HyperEdge with id equal to eID and preset of verexes
        *  @param eID id unique id of hyperedge
        *  @param vertexes preset values of hyperedge
        */
        HyperEdge(const int eID,const std::vector<Vertex*>& vertexes);

        /**
        * @brief Destructor of HyperGraph
        */
        virtual ~HyperEdge(){}

        HyperEdge& operator=(const HyperEdge& hyperedge);

        /**
        * @brief add  vertex to hyperedge
        * @param vertex pionter to vertex we want add
        */
        void addVertex(Vertex *vertex);

        /**
        * @brief remove  vertex to hyperedge
        * @param vertex pionter to vertex we want to remove
        */
        void removeVertex(const Vertex* vertex);

        /**
        * @brief remove  vertex to hyperedge
        * @param vertexID id of vertex we want to remove
        */
        void removeVertex(const int vertexID );

        /**
        * @brief check if vertex with this id exists in hyperedge
        * @param vertexId id of vertex
        * @return true if Containing
        * @return false if not Containing
        */
        bool isContainingVertex(const int id)const;


        /**
         * @brief Use to get Id of hyperedge
         * @return id of hyperedge
         */
        inline  int getId()const{return id;}
        /**
         * @brief Use to  reset connection of hyperedge
         */
        inline void setConnetion(const std::vector<Vertex*>vertexes){connectedVerexes=vertexes;}
        /**
         * @brief Use to get connection of hyperedge
         * @return connection of hyperedge
         */
        inline const std::vector<Vertex*>& getConnectedVerexes()const {return connectedVerexes;}
        /**
         * @brief Use to get number of vertexes in hyperedge
         * @return number of vertexes in hyperedge
         */
//        inline  int getNumberOfVertexes()const{return connectedVerexes.size();}

//        inline auto beginOfHyperedge()const {return connectedVerexes.begin();}
//        inline auto endOfHyperedge()const {return connectedVerexes.end();}

//        inline Vertex* getVertex(const int pos)const { return connectedVerexes[pos]; }

        void print()const;
    protected:
    private:
        const int id;
        std::vector<Vertex*> connectedVerexes;

};

#endif // EDGE_H
