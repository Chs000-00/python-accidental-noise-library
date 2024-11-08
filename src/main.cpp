#include <pybind11/pybind11.h>

#define ANL_IMPLEMENTATION 
#include "../anl.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

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
    m.def("map2D", &anl::map2D);
    m.def("map2DNoZ", &anl::map2DNoZ);
    m.def("map3D", &anl::map3D);

    // VM/coordinate.h
    py::class_<anl::CCoordinate>(m, "CCoordinate")
        .def(py::init<>())
        .def("set", static_cast<void (anl::CCoordinate::*)(double, double)>(&anl::CCoordinate::set))
        .def("set", static_cast<void (anl::CCoordinate::*)(double, double, double)>(&anl::CCoordinate::set))
        .def("set", static_cast<void (anl::CCoordinate::*)(double, double, double, double)>(&anl::CCoordinate::set))
        .def("set", static_cast<void (anl::CCoordinate::*)(double, double, double, double, double, double)>(&anl::CCoordinate::set));

    // kernel.h
    py::enum_<anl::InterpolationTypes>(m, "InterpolationTypes")
        .value("INTERP_NONE", anl::INTERP_NONE)
        .value("INTERP_LINEAR", anl::INTERP_LINEAR)
        .value("INTERP_HERMITE", anl::INTERP_HERMITE)
        .value("INTERP_QUINTIC", anl::INTERP_QUINTIC)
        .export_values();

    py::enum_<anl::DistanceTypes>(m, "DistanceTypes")
        .value("DISTANCE_EUCLID", anl::DISTANCE_EUCLID)
        .value("DISTANCE_MANHATTAN", anl::DISTANCE_MANHATTAN)
        .value("DISTANCE_LEASTAXIS", anl::DISTANCE_LEASTAXIS)
        .value("DISTANCE_GREATESTAXIS", anl::DISTANCE_GREATESTAXIS)
        .export_values();


    py::enum_<anl::BasisTypes>(m, "BasisTypes")
        .value("BASIS_VALUE", anl::BASIS_VALUE)
        .value("BASIS_GRADIENT", anl::BASIS_GRADIENT)
        .value("BASIS_SIMPLEX", anl::BASIS_SIMPLEX)
        .export_values();






#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
