add_library(rational main.cpp rational.cpp include/rational/rational.hpp)
set_property(TARGET rational PROPERTY CXX_STANDARD 20)
target_include_directories(rational PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS rational)