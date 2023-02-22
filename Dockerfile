FROM alpine:latest


RUN apk update
RUN apk upgrade
RUN apk add g++
ADD app /app
WORKDIR app
RUN g++ -std=c++98 -pedantic main.cpp
