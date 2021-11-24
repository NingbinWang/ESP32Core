FILE(GLOB_RECURSE ftflcd_src 
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/*.*
)

FILE(GLOB_RECURSE ftflcd_inc
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/bsp/
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/framework/
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/hal/ili9341/
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/hal/ssd1306/
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/hal/st7789v2/
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/include/
${CMAKE_SOURCE_DIR}/lib/TFT_LCD/intf/
)

idf_component_register(SRCS ${ftflcd_src}
    INCLUDE_DIRS ${ftflcd_inc}
)
