#ifndef VERTEX_H
#define VERTEX_H
/**
* @author   Adam Szczepanski
* @date 08.05.2017
* @brief The Vertex class
*  This class represents single node in hypergraph. Id of the vertex shouldbedeffrentfor every vertex in Hypergraph.
*/
class Vertex
{
    public:
        /** @brief Create an Vertex with id equal to vertexId
         *  @remark Set degree of vertex as 0
         *  @param vertexID id initial value for vertex
         */
        Vertex(const int vertexID);

        /** @brief Destructor of the Vertex class */
        virtual ~Vertex(){}

        /**
         * @brief equal operator for Vertex
         */
        Vertex& operator=(const Vertex& vertex);

        /**
         * @brief operator++ is useto increment degree by 1 of the Vertex
        */
        Vertex& operator++();

        /**
         * @brief operator++ is use to decrement degree by 1 of  the Verte
         */
        Vertex& operator--();

        /**
         * @brief Use to get Id of vertex
         * @return id of vertex
         */
        inline int getId()const{return id;}

        /**
         * @brief Use to get degree of vertex
         * @return degree of vertex
         */
        inline int getDegree()const{return degree;}

        /**
         * @brief Use to set degree of vertex
         *  @param degree new value of degree
         */
        inline void setDegree(const int degree){this->degree=degree;}

        /**
         * @brief print vertex to console
        */
        void print();

    protected:
    private:
        const int id; /**< id of the vertex*/
        int degree; /**< degree of the vertex*/
        //string dane;
};

#endif // VERTEX_H
