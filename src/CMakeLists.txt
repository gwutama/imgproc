set(HEADER_FILES
        bitmap/bitmaptypes.h
        algorithms/algorithmbase.h
)

set(SOURCE_FILES
        common.cpp
        imageprocessor.cpp
        gsimageadapterbase.cpp
        bitmap/bitmapfile.cpp
        bitmap/bitmapimageadapter.cpp
        algorithms/gsbinarize.cpp
        algorithms/gshistogram.cpp
        algorithms/gshistogramequalization.cpp
        algorithms/gsrotate.cpp
        algorithms/gskernelfilter.cpp
        algorithms/kernel.cpp
        algorithms/gsfilterwindow.cpp
        algorithms/unibrightnessadjustment.cpp
        algorithms/uninegative.cpp
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(imgproc ${HEADER_FILES} ${SOURCE_FILES})
