# This module tries to find IXWebSocket library and include files
#
# LIBIXWEBSOCKET_INCLUDE_DIR, path where to find IXWebSocket.h
# LIBIXWEBSOCKET_LIBRARY_DIR, path where to find libixwebsocket.so
# LIBIXWEBSOCKET_LIBRARIES, the library to link against
# LIBIXWEBSOCKET_FOUND, If false, do not try to use IXWebSocket
#
# This currently works probably only for Linux

include(FindPackageHandleStandardArgs)
SET ( LIBIXWEBSOCKET_FOUND FALSE )

FIND_PATH ( LIBIXWEBSOCKET_INCLUDE_DIR NAMES ixwebsocket/IXWebSocket.h
        HINTS /usr/local/include /usr/include
        )

FIND_LIBRARY ( LIBIXWEBSOCKET_LIBRARIES NAMES ixwebsocket libixwebsocket
        HINTS /usr/local/lib /usr/lib
        )

GET_FILENAME_COMPONENT( LIBIXWEBSOCKET_LIBRARY_DIR ${LIBIXWEBSOCKET_LIBRARIES} PATH )

IF ( LIBIXWEBSOCKET_INCLUDE_DIR )
    IF ( LIBIXWEBSOCKET_LIBRARIES )
        SET ( LIBIXWEBSOCKET_FOUND TRUE )
    ENDIF ( LIBIXWEBSOCKET_LIBRARIES )
ENDIF ( LIBIXWEBSOCKET_INCLUDE_DIR )


IF ( LIBIXWEBSOCKET_FOUND )
    MARK_AS_ADVANCED(
            LIBIXWEBSOCKET_LIBRARY_DIR
            LIBIXWEBSOCKET_INCLUDE_DIR
            LIBIXWEBSOCKET_LIBRARIES
    )
ENDIF ( )

find_package_handle_standard_args(LIBIXWEBSOCKET
        DEFAULT_MSG
        LIBIXWEBSOCKET_INCLUDE_DIR
        LIBIXWEBSOCKET_LIBRARIES)