#include <pybind11/pybind11.h>

#include "../anl.h"
#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;
using namespace anl;


PYBIND11_MODULE(pyanlib, m) {
    m.def("hermite_blend", &hermite_blend);
    m.def("quintic_blend", &quintic_blend);


#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}