FROM alpine:latest

RUN apk update
RUN apk upgrade
RUN apk add --update make
RUN apk add g++
RUN apk add tar
COPY bircdlinux.tar /bircd.tar
WORKDIR /
RUN tar zxvf /bircd.tar
WORKDIR /bircd
RUN make
CMD ["/bin/sh"]