
# executables

add_executable(
    main
    "wscan.cpp"
    "wscan.h"
    "../src/features/ping/ping.cpp"
    "../src/features/ping/ping_config.hpp"
    "../src/server/server.cpp"
    "../src/server/servercfg.hpp"
    "../src/common/net/socket.hpp"
    "../src/common/net/socket.cpp"
    "../src/common/config/config.hpp"

)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

# 