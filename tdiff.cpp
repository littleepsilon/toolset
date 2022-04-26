

/*
 time        : 12:40
 date        : 2021-08-10
 author      : david
 description : None
*/
/* dependency
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

/* macro
*/
 
/* enum
*/
 
/* struct
*/
#pragma pack(1)
 
#pragma pack( )

/* global declare
*/
 

/* interface
*/
class text_al{
    std::map<std::string,int> m_text_list;
public:
    text_al()
    {

    }
    ~text_al()
    {

    }
    void init( const std::string& filename )
    {
        std::ifstream ifs(filename, std::ifstream::in);
        if (!ifs.good())
        {
            exit(-1);
        }
        std::string lines;
        while (getline(ifs, lines))
        {
            m_text_list[lines] = 1;
        }
        ifs.close();
    }
    void operator-(const text_al& right)
    {
        for ( auto it = right.m_text_list.begin(); it != right.m_text_list.end(); ++it ){
            auto itt = m_text_list.find( it->first );
            if ( itt != m_text_list.end() ){
                m_text_list.erase( itt );
            }
        }
    }
    void show()
    {
        for( auto it = m_text_list.begin(); it != m_text_list.end(); ++it ){
            std::cout<< it->first << std::endl;
        }
    }
};

int main( int argc, char* argv[] )
{
    text_al obj;
    text_al obj2;
    obj.init( argv[1] );
    obj2.init( argv[2] );
    obj - obj2;
    obj.show();
}
