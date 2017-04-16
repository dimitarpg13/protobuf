if (UNIX)
  add_definitions(-Wno-switch)
endif()

add_executable(myclient
  MyClient.cpp
  stdafx.cpp
  )

target_link_libraries(myclient ${Casablanca_LIBRARIES})
