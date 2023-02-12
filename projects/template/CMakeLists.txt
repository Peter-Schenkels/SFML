#header directory
set(HEADER_DIRECTORY, ${CMAKE_CURRENT_SOURCE_DIR}/headers)

###############################
# Add all sources and headers #
###############################
set(HELPER_FUNCTIONS)
# create helper functions folder
source_group("Helper Functions" FILES ${HELPER_FUNCTIONS})

set(DATA_TYPES
    src/data.cpp
    headers/data.h
)
# create data types folder
source_group("Data Types" FILES ${DATA_TYPES})

set(MAIN
    src/main.cpp
)
# create Main folder
source_group("Main" FILES ${MAIN})
###############################


# Set all sources and headers to a var
set(SRC ${DATA_TYPES} ${MAIN})

# define the target
sfml_add_project(template GUI_APP
                 SOURCES ${SRC}
                 BUNDLE_RESOURCES ${RESOURCES}
                 DEPENDS SFML::Audio SFML::Graphics
                 RESOURCES_DIR resources)
