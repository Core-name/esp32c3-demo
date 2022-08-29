# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/rmer/esp/esp-idf/components/bootloader/subproject"
  "/home/rmer/esp32c3-demo/freertos_project/build/bootloader"
  "/home/rmer/esp32c3-demo/freertos_project/build/bootloader-prefix"
  "/home/rmer/esp32c3-demo/freertos_project/build/bootloader-prefix/tmp"
  "/home/rmer/esp32c3-demo/freertos_project/build/bootloader-prefix/src/bootloader-stamp"
  "/home/rmer/esp32c3-demo/freertos_project/build/bootloader-prefix/src"
  "/home/rmer/esp32c3-demo/freertos_project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/rmer/esp32c3-demo/freertos_project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
