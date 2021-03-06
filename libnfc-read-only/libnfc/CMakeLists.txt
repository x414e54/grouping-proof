# Library's chips
SET(CHIPS_SOURCES chips/pn53x)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/chips)

# Library's buses
SET(BUSES_SOURCES buses/uart)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/buses)

# Library's drivers
SET(LIBNFC_SERIAL_AUTOPROBE_ENABLED OFF CACHE BOOL "Allow serial ports to be probed (can seriously disturb connected serial devices)")
IF(LIBNFC_SERIAL_AUTOPROBE_ENABLED)
  ADD_DEFINITIONS("-DSERIAL_AUTOPROBE_ENABLED")
ENDIF(LIBNFC_SERIAL_AUTOPROBE_ENABLED)

INCLUDE(LibnfcDrivers)

INCLUDE_DIRECTORIES(${LIBUSB_INCLUDE_DIRS} ${PCSC_INCLUDE_DIRS})
LINK_DIRECTORIES(${LIBUSB_LIBRARY_DIRS} ${PCSC_LIBRARY_DIRS})

# Library
SET(LIBRARY_SOURCES nfc nfc-device nfc-emulation iso14443-subr mirror-subr ${DRIVERS_SOURCES} ${BUSES_SOURCES} ${CHIPS_SOURCES})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
ADD_LIBRARY(nfc SHARED ${LIBRARY_SOURCES})
TARGET_LINK_LIBRARIES(nfc ${LIBUSB_LIBRARIES} ${PCSC_LIBRARIES})
IF(WIN32)
  TARGET_LINK_LIBRARIES(nfc wsock32)
ENDIF(WIN32)
SET_TARGET_PROPERTIES(nfc PROPERTIES SOVERSION 0)

IF(WIN32)
  # On Windows the shared (runtime) library should be either in the same 
  # directory as the excutables or in the path, we add it to same directory
  INSTALL(TARGETS nfc RUNTIME DESTINATION bin COMPONENT libraries)

  # At compile time we need the .LIB file, we place it in the lib directory
  INSTALL(TARGETS nfc ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT headers)
ELSE(WIN32)
  INSTALL(TARGETS nfc LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries)
ENDIF(WIN32)

