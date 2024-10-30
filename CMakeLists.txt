cmake_minimum_required(VERSION 2.6)

add_definitions(-DUSETHREAD)

# include_directories(ThirdParty/lua-5.1.4/src/ ThirdParty/toluapp/include/)

file(GLOB sources Framework/main.cpp
  Bindings/bind_anl.cpp
)

add_executable(anl ${sources})
