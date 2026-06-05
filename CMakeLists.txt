cmake_minimum_required(VERSION 3.19)
project(golf-cronos LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Sql Multimedia)

set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CONSOLE_FLAG "")
else()
    set(CONSOLE_FLAG "WIN32;MACOSX_BUNDLE")
endif()

qt_add_executable(golf-cronos
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/recursos.qrc
    src/cerebro/gestorbasedatos.h src/cerebro/gestorbasedatos.cpp
    src/escenario/pantallas/iniciowindow.h src/escenario/pantallas/iniciowindow.cpp src/escenario/pantallas/iniciowindow.ui
    src/escenario/widgets/loginwidget.h src/escenario/widgets/loginwidget.cpp src/escenario/widgets/loginwidget.ui
    src/escenario/widgets/registrarsewidget.h src/escenario/widgets/registrarsewidget.cpp src/escenario/widgets/registrarsewidget.ui
    src/escenario/widgets/modosgamewidget.h src/escenario/widgets/modosgamewidget.cpp src/escenario/widgets/modosgamewidget.ui
    src/escenario/widgets/portadawidget.h src/escenario/widgets/portadawidget.cpp src/escenario/widgets/portadawidget.ui

    src/escenario/modos_juego/juegomodounoqgraphicsview.h src/escenario/modos_juego/juegomodounoqgraphicsview.cpp
    src/cerebro/elementojuego.h src/cerebro/elementojuego.cpp
    src/escenario/modos_juego/juegomododosqgraphicsview.h src/escenario/modos_juego/juegomododosqgraphicsview.cpp
    src/escenario/juego/nivel.h src/escenario/juego/nivel.cpp
    src/escenario/juego_2/nivel_d.h src/escenario/juego_2/nivel_d.cpp
    src/escenario/juego/items/pelota.h src/escenario/juego/items/pelota.cpp
    src/escenario/juego_2/items/personaje.h src/escenario/juego_2/items/personaje.cpp
    src/escenario/juego_2/items/ruedapinchos.h src/escenario/juego_2/items/ruedapinchos.cpp
    src/escenario/juego_2/items/pelotaroja.h src/escenario/juego_2/items/pelotaroja.cpp
    src/escenario/juego_2/items/agenteia.h src/escenario/juego_2/items/agenteia.cpp
    src/escenario/juego_2/items/centrodepoder.h src/escenario/juego_2/items/centrodepoder.cpp
    src/escenario/juego_2/items/cratergris.h src/escenario/juego_2/items/cratergris.cpp
    src/escenario/juego_2/items/craterrojo.h src/escenario/juego_2/items/craterrojo.cpp
    src/escenario/juego_2/items/craterhielo.h src/escenario/juego_2/items/craterhielo.cpp
    src/escenario/juego_2/items/cronometrotiempo.h src/escenario/juego_2/items/cronometrotiempo.cpp
    src/escenario/juego_2/items/bandera.h src/escenario/juego_2/items/bandera.cpp
    src/escenario/juego_2/items/momentopelota.h src/escenario/juego_2/items/momentopelota.cpp
    src/escenario/juego_2/items/pelotablanca.h src/escenario/juego_2/items/pelotablanca.cpp
    src/escenario/juego_2/items/portal.h src/escenario/juego_2/items/portal.cpp
    src/escenario/juego_2/items/remolinometa.h src/escenario/juego_2/items/remolinometa.cpp
    src/escenario/juego_2/items/logrosvidas.h src/escenario/juego_2/items/logrosvidas.cpp


)

target_link_libraries(golf-cronos
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
        Qt6::Multimedia
)

include(GNUInstallDirs)

install(TARGETS golf-cronos
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET golf-cronos
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

