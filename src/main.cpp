#include <pybind11/pybind11.h>

#define ANL_IMPLEMENTATION 
#include "../anl.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;
using namespace anl;

// Would autogenerating these instead be better?
PYBIND11_MODULE(pyanlib, m) {
    // util.h Functions
    // Might not need to add these
    m.def("hermite_blend", &hermite_blend);
    m.def("quintic_blend", &quintic_blend);
    m.def("fast_floor", &fast_floor);
    m.def("array_dot", &array_dot);
    m.def("array_dot3", &array_dot3);
    m.def("bias", &bias);
    m.def("gain", &gain);

    // imaging.h
    m.def("map2D", &map2D);
    m.def("map2DNoZ", &map2DNoZ);
    m.def("map3D", &map3D);





#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
