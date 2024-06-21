FROM ubuntu:22.04

ENV TZ=Europe/Warsaw
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update && apt install -y git cmake g++ libboost-all-dev valgrind clang clang-tidy clang-format

RUN mkdir /root/game
COPY . /root/game