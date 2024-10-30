#include <pybind11/pybind11.h>
#include <anl.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

PYBIND11_MODULE(python_anl, m) {
    m.def("hermite_blend", &anl::hermite_blend);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}