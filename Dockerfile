# Use an official image as a parent image
FROM debian:buster
LABEL authors="Hooman Tahmasebipour"
LABEL name="big_exponent_calculator"
LABEL email="hooman.tahmasebipour@mail.utoronto.ca"

# Set the working directory in the container
WORKDIR /usr/src/myapp

# Install g++ compiler
RUN apt-get update && \
    apt-get install -y g++ && \
    rm -rf /var/lib/apt/lists/*

# Copy the current directory contents into the container at /usr/src/myapp
COPY ./* .

# Specify the name of your executable
ARG EXECUTABLE=main

# Compile your project
RUN g++ -o ${EXECUTABLE} *.cpp

# Run the output program from the previous step when the container launches
CMD ["./main"]
