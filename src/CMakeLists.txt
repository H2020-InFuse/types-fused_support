# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

add_definitions(-std=c++11)

set(LIB ${CMAKE_PROJECT_NAME})

set(SOURCES
    asn1MapConvert.cpp
    )
    
set(HEADERS
    asn1MapConvert.hpp
    )

# ASN.1 types are imported and compiled locally to the project, but not installed
esrocos_asn1_types_package(${LIB}_local_types
    OUTDIR asn1
    IMPORT types/base types/sensor_samples types/fused)
    
# Find libraries in ESROCOS' install directory
link_directories(${CMAKE_INSTALL_PREFIX}/lib)

# Target library
add_library(${LIB} SHARED ${SOURCES})
set_target_properties(${LIB} PROPERTIES LINKER_LANGUAGE CXX)
esrocos_pkgconfig_dependency(${LIB}
    eigen3
    base_support
    maps
)
target_include_directories(${LIB} PUBLIC 
   PRIVATE ${CMAKE_BINARY_DIR}
)
add_dependencies(${LIB} ${LIB}_local_types_generate_c)

# Install headers, libraries and pkg-config file
install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${CMAKE_PROJECT_NAME}
)
        
install(TARGETS ${LIB}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

CONFIGURE_FILE("${LIB}.pc.in" "${LIB}.pc" @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${LIB}.pc
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig
)
