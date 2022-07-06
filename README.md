# Docker C++
Template project for modern C++ build and deployment based on Docker, CMake and Conan.  

Features:
- **CMake** build system for cross-platform development.
- **CTest** with GoogleTest integration for Unit Test support.
- **Conan** package manager to facilitate dependency management.
- **Dockerfile** to handle build, test and deploy stages.

What's next:
- **CI** integration to support automated builds.
- **Formatting** support, to style code properly.
- **Sanitizers** support, to check memory related issues.
- **Valgrind** support, to check memory related issues.
- **Benchmark** support, to allow comparison for regression/performance test.
- **Doxygen** support, to manage project documentation.

---

## Local usage

- Restore dependencies:
```bash
./scripts/conan_install.sh Release gcc 10
```

- Configure:
```bash
cmake -G Ninja -D CMAKE_BUILD_TYPE=Release -D UNIT_TESTS=ON -B ./build/Release -S .
```

- Build
```bash
cmake --build ./build/Release --config Release
```

- Test
```bash
ctest --test-dir ./build/Release --config Release
```

- Install
```bash
cmake --install ./build/Release --prefix ./install
```

---

## Docker Usage

- Build image
```bash
docker build -f Dockerfile --rm -t docker_cpp:latest .
```

- Run container
```bash
docker run --rm -it --name docker_cpp docker_cpp:latest
```
