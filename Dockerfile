FROM alpine:latest

RUN apk update
RUN apk upgrade
RUN apk add --update make
RUN apk add g++
ADD app /app
WORKDIR app
CMD ["/bin/sh"]