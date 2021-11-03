docker build -f docker/Dockerfile.ubuntu_gcc --rm -t dkpp:gcc .
docker build -f docker/Dockerfile.ubuntu_clang --rm -t dkpp:clang .
docker build -f docker/Dockerfile.debian --rm -t dkpp:debian .