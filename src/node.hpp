/** 
Architecture:

    Data Structures:
       calculated        input data
    +--------------+    +-----------+
    | NodePosition |    | InputData |
    +--------------+    +-----------+

    Threads:
    +-----------+       +------------+       +-----------------+
    | Rendering |  NP*  | Processing |  ID*  | Handling events |
    |   graph   | <---> |  physics   | <---> | and user input  |
    +-----------+       +------------+       +-----------------+

    NP* - NodePosition: `Rendering graph` is reader and
        `Processing physics` is writer. NodePosition or just Node

    ID* - InputData: `Processing physics` is reader and
        `Handling events and user input` is writer.

*/

#pragma once

namespace grator {

struct Node {
private:
friend class reader;
    float x = 0.0;
    float y = 0.0;
    
};

};