add_library(orto orto.cpp orto.txt)
set_property(TARGET orto PROPERTY CXX_STANDARD 20)
install(TARGETS orto)