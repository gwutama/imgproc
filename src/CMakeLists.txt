set(HEADER_FILES
        bitmap/bitmaptypes.h
        algorithms/algorithm.h
)

set(SOURCE_FILES
        common.cpp
        image.cpp
        bitmap/bitmapfile.cpp
        algorithms/binarize.cpp
        algorithms/histogram.cpp
        algorithms/histogramequalization.cpp
        algorithms/rotate.cpp
        algorithms/kernelfilter.cpp
        algorithms/kernel.cpp
        algorithms/gsfilterwindow.cpp
        algorithms/brightnessadjustment.cpp
        algorithms/negative.cpp
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(imgproc ${HEADER_FILES} ${SOURCE_FILES})
