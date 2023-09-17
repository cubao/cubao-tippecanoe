// https://github.com/microsoft/vscode-cpptools/issues/9692
#if __INTELLISENSE__
#undef __ARM_NEON
#undef __ARM_NEON__
#endif

#include <string>
#include <vector>
#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;
using namespace pybind11::literals;

int tippecanoe_main(int argc, char **argv);
int decode_main(int argc, char **argv);
int enumerate_main(int argc, char **argv);
int jsontool_main(int argc, char **argv);
int overzoom_main(int argc, char **argv);
int tile_join_main(int argc, char **argv);

int __run_cmd(const std::string &cmd, std::vector<std::string> args) {
    int argc = args.size() + 1;
    std::vector<char*> argv_;
    for (const auto& arg : args) {
        argv_.push_back((char*)arg.data());
    }
    argv_.push_back(nullptr);
    char **argv = &argv_[0];
    if (cmd == "tippecanoe") {
        return tippecanoe_main(argc, argv);
    // } else if (cmd == "decode") {
    //     return decode_main(argc, argv);
    } else if (cmd == "enumerate") {
        return enumerate_main(argc, argv);
    } else if (cmd == "jsontool") {
        return jsontool_main(argc, argv);
    } else if (cmd == "overzoom") {
        return overzoom_main(argc, argv);
    } else if (cmd == "tile_join") {
        return tile_join_main(argc, argv);
    }
    std::cerr << "invalid cmd: " << cmd << std::endl;
    std::cerr << "available commands: " << std::endl;
    std::cerr << "- tippecanoe" << std::endl;
    std::cerr << "- decode" << std::endl;
    std::cerr << "- enumerate" << std::endl;
    std::cerr << "- jsontool" << std::endl;
    std::cerr << "- overzoom" << std::endl;
    std::cerr << "- tile_join" << std::endl;
    return -1;
}


PYBIND11_MODULE(_pybind11_tippecanoe, m)
{
     m.def("run_cmd", &__run_cmd, "cmd"_a, "args"_a)
     //
     ;
#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}