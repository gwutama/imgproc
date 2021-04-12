set(HEADER_FILES
        bitmap/bitmaptypes.h
        algorithms/algorithm.h
)

set(SOURCE_FILES
        common.cpp
        image.cpp
        bitmap/bitmapfile.cpp
        bitmap/bitmapreader.cpp
        bitmap/bitmapwriter.cpp
        algorithms/binarize.cpp
        algorithms/histogram.cpp
        algorithms/histogramequalization.cpp
        algorithms/rotate.cpp
        algorithms/kernelfilter.cpp
        algorithms/kernel.cpp
        algorithms/brightnessadjustment.cpp
        algorithms/negative.cpp
        algorithms/downsampling.cpp
        algorithms/noise.cpp
        algorithms/bgrtogray.cpp
        algorithms/morphologicalfilter.cpp
        algorithms/drawline.cpp
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(imgproc ${HEADER_FILES} ${SOURCE_FILES})
