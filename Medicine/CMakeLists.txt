cmake_minimum_required(VERSION 3.31)
project(Medicine)

set(CMAKE_CXX_STANDARD 11)

add_executable(Medicine main.cpp
        Medication.cpp
        Medication.h
        MedicalEquipment.cpp
        MedicalEquipment.h
        MedicalItem.cpp
        MedicalItem.h
)
