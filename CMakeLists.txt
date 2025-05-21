cmake_minimum_required(VERSION 3.31)
project(Coen244Assignments)

set(CMAKE_CXX_STANDARD 23)

add_executable(Coen244Assignments main.cpp)
add_executable(A1_Q1
        A1/Q1.cpp
)
add_executable(A1_Q2
        A1/Q2.cpp
)
add_executable(A1_Q3
        A1/Q3.cpp
)
add_executable(A2 A2/main.cpp A2/main.h
        A2/Date.cpp
        A2/Date.h
        A2/AppointmentTime.cpp
        A2/AppointmentTime.h
        A2/Patient.cpp
        A2/Patient.h
        A2/Doctor.cpp
        A2/Doctor.h
        A2/AppointmentRequest.cpp
        A2/AppointmentRequest.h
        A2/ClinicManager.cpp
        A2/ClinicManager.h)
add_executable(A3 A3/main.cpp A3/main.h)
add_executable(A4 A4/main.cpp A4/main.h)
add_executable(A5 A5/main.cpp A5/main.h)
add_executable(A6 A6/main.cpp A6/main.h)
add_executable(A1_Q4 A1/Q4.cpp)
