docker build -f docker/Dockerfile.gcc --rm -t dkpp_test:gcc --target test .
docker build -f docker/Dockerfile.clang --rm -t dkpp_test:clang --target test .