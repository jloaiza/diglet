
SET(CLIENT_CPP_SOURCES
  client.cpp)

ADD_LIBRARY(clientcpp SHARED ${CLIENT_CPP_SOURCES})

# TARGET_LINK_LIBRARIES(main ${OpenCV_LIBS})
# TARGET_LINK_LIBRARIES(main image)
# TARGET_LINK_LIBRARIES(main simplestructures)
# TARGET_LINK_LIBRARIES(main map)
# TARGET_LINK_LIBRARIES(main algorithms)

# Change the name of the final executable
# SET_TARGET_PROPERTIES(main PROPERTIES_OUTPUT_NAME newname)
