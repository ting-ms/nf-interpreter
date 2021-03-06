#
# Copyright (c) .NET Foundation and Contributors
# See LICENSE file in the project root for full license information.
#

# add header file with common target definitions
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/target_platform.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/target_platform.h @ONLY)

# append nanoCLR source files
list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Memory.cpp)
list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/nanoHAL.cpp)

list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/targetHAL.cpp)

# append target HAL source files
list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/targetHAL_Time.cpp)
list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/targetHAL_Power.c)

# append Random number generator files
list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/targetRandom.cpp)

# append networking files, if enabled
if(USE_NETWORKING_OPTION)
    list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/targetHAL_Network.cpp)
    list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Target_Network.cpp)

    # list(APPEND LWIP_INCLUDE_DIRS ${LWIP_INCLUDE_DIRS}/LwIP)

    # append mbed TLS entropy generator, if hardware has it
    # if(NF_SECURITY_MBEDTLS AND USE_RNG)
    #     list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/mbedtls_entropy_hardware_pool.c")
    # endif()

endif()

# append files from Runtime.Native
list(APPEND TARGET_NXP_NANOCLR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/nanoFramework.Runtime.Native/nf_rt_native_nanoFramework_Runtime_Native_Rtc.cpp)

# append target nanoCLR include directory
list(APPEND TARGET_NXP_NANOCLR_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND TARGET_NXP_NANOCLR_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR})

# make vars global
set(TARGET_NXP_NANOCLR_SOURCES ${TARGET_NXP_NANOCLR_SOURCES} CACHE INTERNAL "make global")
set(TARGET_NXP_NANOCLR_INCLUDE_DIRS ${TARGET_NXP_NANOCLR_INCLUDE_DIRS} CACHE INTERNAL "make global")
