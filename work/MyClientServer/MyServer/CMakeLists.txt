if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif()

add_executable(myserver
  MyServer.cpp
  Dealer.cpp
  stdafx.cpp
  Table.cpp
  )

target_link_libraries(myserver ${Casablanca_LIBRARIES})
