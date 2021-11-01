FROM ubuntu:20.04 as build
RUN apt update -y && apt upgrade -y

RUN apt-get install -y python3.8 --no-install-recommends 
RUN python3.8 --version

RUN apt install -y pip --no-install-recommends 
RUN pip --version

RUN apt-get -y install cmake --no-install-recommends 
RUN cmake --version

RUN pip install conan
RUN conan --version

RUN apt install -y g++-9 --no-install-recommends
RUN g++-9 --version

RUN apt install -y ninja-build --no-install-recommends
RUN ninja --version

ENV CXX=g++-9

WORKDIR /docker_cpp
COPY . /docker_cpp/
WORKDIR build
ENV BUILD_TYPE=Release
RUN cmake -G Ninja -D CMAKE_BUILD_TYPE=${BUILD_TYPE} ..
RUN cmake --build . --config ${BUILD_TYPE}

FROM ubuntu:20.04 as final
COPY --from=build /docker_cpp/build/bin/ /docker_cpp/bin/
COPY --from=build /docker_cpp/build/lib/ /docker_cpp/lib/
CMD [ "./docker_cpp/bin/app" ]
