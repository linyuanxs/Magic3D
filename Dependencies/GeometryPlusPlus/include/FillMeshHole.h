#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    enum FillMeshHoleType
    {
        FILL_MESH_HOLE_FLAT = 0,
        FILL_MESH_HOLE_SMOOTH
    };

    class GPP_EXPORT FillMeshHole
    {
    public:
        // Given a input triMesh, it will find out all the hole loops. 
        // Each found hole loop is an array of the hole's boundary vertices IDs. And holesIds outputs all the loops. 
        static ErrorCode FindHoles(const ITriMesh* triMesh, std::vector<std::vector<Int> > *holesIds);
        
        // The input parameters are some of the boundary vertices ids in the triMesh, 
        // and it will fill holes that at least one of its boundary vertices are in the seeds. 
        // NOTE: If the boundarySeedIds are empty, all the holes will be filled.
        static ErrorCode FillHoles(ITriMesh* triMesh, const std::vector<Int>& boundarySeedIds, FillMeshHoleType method = FILL_MESH_HOLE_FLAT);
    };
}