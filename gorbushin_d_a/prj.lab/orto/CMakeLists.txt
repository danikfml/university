add_library(orto orto.20230519 orto.txt)
set_property(TARGET orto PROPERTY CXX_STANDARD 20)
install(TARGETS orto)