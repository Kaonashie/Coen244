cmake_minimum_required(VERSION 3.31)
project(Coen244Assignments)

set(CMAKE_CXX_STANDARD 23)


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
add_executable(A3 
        A3/main.cpp 
        A3/main.h
        A3/Date.cpp
        A3/Date.h
        A3/Person.cpp
        A3/Person.h
        A3/Doctor.cpp
        A3/Doctor.h
        A3/Patient.cpp
        A3/Patient.h
        A3/HospitalManager.cpp
        A3/HospitalManager.h
)
add_executable(A4 A4/main.cpp A4/main.h
        A4/Date.cpp
        A4/Date.h
        A4/Person.cpp
        A4/Person.h
        A4/Customer.cpp
        A4/Customer.h
        A4/RealEstateAgent.cpp
        A4/RealEstateAgent.h
        A4/Property.cpp
        A4/Property.h
        A4/HouseSale.cpp
        A4/HouseSale.h
        A4/ApartmentSale.cpp
        A4/ApartmentSale.h
        A4/RealEstateManager.cpp
        A4/RealEstateManager.h
        A4/LandSale.cpp
        A4/LandSale.h)
add_executable(A5 A5/main.cpp A5/main.h

        A5/Date.cpp
        A5/Date.h
        A5/Person.cpp
        A5/Person.h
        A5/Customer.cpp
        A5/Customer.h
        A5/RealEstateAgent.cpp
        A5/RealEstateAgent.h
        A5/Property.cpp
        A5/Property.h
        A5/HouseSale.cpp
        A5/HouseSale.h
        A5/ApartmentSale.cpp
        A5/ApartmentSale.h
        A5/RealEstateManager.cpp
        A5/RealEstateManager.h
        A5/LandSale.cpp
        A5/LandSale.h)
add_executable(A6 A6/main.cpp A6/main.h)
