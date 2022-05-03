SPL_VERSION = 2021.1
SPL_URL = https://web.stanford.edu/dept/cs_edu/qt
TEMPLATE    =   app
QT          +=  core gui widgets network
CONFIG      +=  silent debug         # quiet build and debug symbols always
CONFIG      -=  depend_includepath   # library headers not changing, don't add depend
win32|win64     { QTP_EXE = qtpaths.exe } else { QTP_EXE = qtpaths }
USER_DATA_DIR   =   $$system($$[QT_INSTALL_BINS]/$$QTP_EXE --writable-path GenericDataLocation)
SPL_DIR         =   $${USER_DATA_DIR}/cs106
STATIC_LIB      =   $$system_path($${SPL_DIR}/lib/libcs106.a)
SPL_VERSION_FILE =  $$system_path($${SPL_DIR}/lib/version$${SPL_VERSION})
check_lib.target    =  "$${STATIC_LIB}"
check_lib.commands  =  $(error No CS106 library found. Install CS106 package following instructions at $${SPL_URL})
QMAKE_EXTRA_TARGETS +=  check_lib
PRE_TARGETDEPS       +=  $${check_lib.target}
check_version.target    =  "$${SPL_VERSION_FILE}"
check_version.commands  =  $(error Cannot find version $${SPL_VERSION} of CS106 library. Install CS106 package following instructions at $${SPL_URL})
QMAKE_EXTRA_TARGETS +=  check_version
PRE_TARGETDEPS       +=  $${check_version.target}
LIBS            +=  -lcs106 -lpthread
QMAKE_LFLAGS    =   -L$$shell_quote($${SPL_DIR}/lib)
INCLUDEPATH     +=  $$PWD "$${SPL_DIR}/include"
TARGET      =   $$replace(TARGET, " ", _)
DESTDIR     =   $$PWD
DEFINES     +=  main=qMain qMain=studentMain
SOURCES         *=  ""
HEADERS         *=  ""
SOURCES         *=  $$files(*.cpp, true)
HEADERS         *=  $$files(*.h, true)
OTHER_FILES     *=  $$files(res/*, true)
OTHER_FILES     *=  $$files(*.txt, true)
CONFIG          +=  sdk_no_version_check   # removes spurious warnings on Mac OS X
CONFIG          +=  c++11
QMAKE_CXXFLAGS_WARN_ON      +=  -Werror=return-type
QMAKE_CXXFLAGS_WARN_ON      +=  -Werror=uninitialized
QMAKE_CXXFLAGS_WARN_ON      +=  -Wunused-parameter
QMAKE_CXXFLAGS_WARN_ON      +=  -Wmissing-field-initializers
QMAKE_CXXFLAGS_WARN_ON      +=  -Wno-old-style-cast
QMAKE_CXXFLAGS_WARN_ON      +=  -Wno-sign-compare
QMAKE_CXXFLAGS_WARN_ON      +=  -Wno-sign-conversion
QMAKE_CXXFLAGS_WARN_ON      +=  -Wno-unused-const-variable
*-clang { # warning flags specific to clang
    QMAKE_CXXFLAGS_WARN_ON  +=  -Wempty-init-stmt
    QMAKE_CXXFLAGS_WARN_ON  +=  -Wignored-qualifiers
}
*-g++ {   # warning flags specific to g++
    QMAKE_CXXFLAGS_WARN_ON  +=  -Wlogical-op
}
win32|win64 {
    contains(PWD, .*\.zip.*) | contains(PWD, .*\.ZIP.*) {
        message( "*******************************************************************" )
        message( "*** ERROR: You are trying to open this project from within a ZIP archive." )
        message( "*** You must first extract the files then open in Qt Creator." )
        message( "*** In File Explorer open the ZIP and choose to Extract All." )
        message( "*******************************************************************" )
        error( Exiting. Extract project from ZIP first.)
    }
}
PROJECT_DIR = $$basename(PWD)
FOUND  = $$PROJECT_DIR
FOUND ~= s|[a-z A-Z 0-9 _.+-]||   # yes, spaces ok, limited punctuation, $ % & are dicey
!isEmpty(FOUND) {
    message( "*******************************************************************" )
    message( "*** ERROR: The name of your project directory has disallowed characters." )
    message( "*** The allowed characters are letters, numbers, and simple punctuation." )
    message( "*** Your directory is named $$PROJECT_DIR which contains the" )
    message( "*** disallowed characters: $$FOUND" )
    message( "*** Please rename to a simple name such as Assignment_1 that contains" )
    message( "*** no disallowed characters." )
    message( "*******************************************************************" )
    error(Exiting. Rename project directory to remove disallowed characters. )
}
