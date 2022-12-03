from conans import CMake, ConanFile


class LearnCPP(ConanFile):
    name = "Learn c++"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"
    requires = ["fmt/9.1.0", "libcurl/7.85.0", "gtest/cci.20210126", "sfml/2.5.1", "boost/1.80.0"]

    def imports(self):
        self.copy("*.dylib*", dst="bin", src="lib") # From lib to bin