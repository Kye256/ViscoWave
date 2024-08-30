#include <pybind11/pybind11.h>
#include "ViscoWave.h"

namespace py = pybind11;

PYBIND11_MODULE(viscowave, m) {
    m.def("ViscoWave", &ViscoWave, "A function to run the ViscoWave simulation",
          py::arg("displacement"),
          py::arg("Sigmoid"),
          py::arg("Pavement"),
          py::arg("Load_Pressure"),
          py::arg("Load_Radius"),
          py::arg("Sensor_Location"),
          py::arg("Time"),
          py::arg("Timehistory"),
          py::arg("dt"),
          py::arg("num_prony_elements"),
          py::arg("Num_Pavt_Layers"),
          py::arg("Num_Sensors"),
          py::arg("Num_Time"),
          py::arg("Num_VE_Layer"));
}