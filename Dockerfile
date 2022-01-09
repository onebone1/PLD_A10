FROM ubuntu:latest

RUN apt-get update \
    && apt-get install vim g++ -y \
    && rm -rf /var/lib/apt/lists/*

COPY main.cpp /PLD/

WORKDIR /PLD

RUN g++ -w -o main main.cpp