add_executable(RestServer restserver.cpp)
add_executable(RestClient restclient.cpp)
target_link_libraries(RestServer ${Casablanca_LIBRARIES})
target_link_libraries(RestClient ${Casablanca_LIBRARIES})

