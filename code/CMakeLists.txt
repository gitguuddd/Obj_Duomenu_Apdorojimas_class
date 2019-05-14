project(code)

set(HEADER_FILES
        Headers/Input.h
        Headers/Mutual.h
        Headers/Output.h
        classes/stud/Stud.h
        classes/Humie/Humie.h
        classes/ImportantValues/Important_Values.h
        classes/Timer/Timer.h
        )

set(SOURCE_FILES
        Cpps/Input.cpp
        Cpps/Mutual.cpp
        Cpps/Output.cpp
        classes/stud/Stud.cpp
        classes/ImportantValues/Important_Values.cpp
        classes/Humie/Humie.cpp
        classes/Timer/Timer.h
        )

add_library(code STATIC ${SOURCE_FILES} ${HEADER_FILES})