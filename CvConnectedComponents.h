#include <iostream>

namespace cv
{
    namespace connectedcomponents
    {
        template<typename LabelT> inline static LabelT findRoot( const vector<LabelT> &P, LabelT i );
        template<typename LabelT> inline static void setRoot( vector<LabelT> &P, LabelT i, LabelT root );
        template<typename LabelT> inline static LabelT find( vector<LabelT> &P, LabelT i );
        template<typename LabelT> inline static LabelT set_union( vector<LabelT> &P, LabelT i, LabelT j );
        template<typename LabelT> inline static LabelT flattenL( vector<LabelT> &P );
    }
    int connectedComponents( Mat &L, const Mat &I, int connectivity );
}