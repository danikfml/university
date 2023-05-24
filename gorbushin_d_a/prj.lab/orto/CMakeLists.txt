add_library(orto orto.20230519 orto.txt)
set_property(TARGET orto PROPERTY CXX_STANDARD 20)
target_include_directories(rational PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )
install(TARGETS orto)