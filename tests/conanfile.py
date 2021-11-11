from conans import ConanFile, CMake

class DockerCppTest(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package"
    requires = "gtest/1.10.0" # comma-separated list of requirements

    def imports(self):
        self.copy("*.so*", dst="../lib", src="lib")
        self.copy("*.dll", dst="../bin", src="bin") 
        self.copy("*.dylib*", dst="../bin", src="lib")
        