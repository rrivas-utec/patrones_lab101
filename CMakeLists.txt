cmake_minimum_required(VERSION 3.19)
project(patrones)

set(CMAKE_CXX_STANDARD 17)

# Instrucciones para ubicar la librería
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_DEBUG})
set(SFML_ROOT "C:/SFML/mingw/64bit/SFML-2.5.1")
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

# Buscar un nuevo paquete
find_package(Freetype REQUIRED)
find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp
        render.h
        application.cpp application.h
        componente.h
        sfml_factory.h
        sfml_button.h
        sfml_label.h
        sdl_factory.h
        sdl_button.h
        sdl_label.h
        factory.h
        )
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_link_libraries(${PROJECT_NAME} ${FREETYPE_LIBRARIES})

configure_file(./Oxanium-Regular.ttf ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(./components.txt ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)