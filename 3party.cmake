include(ExternalProject)

# Vulkan 1.2.170
set(VULKAN_HPP_REPO Vulkan-Headers)

ExternalProject_Add(
    ${VULKAN_HPP_REPO}
    PREFIX ${VULKAN_HPP_REPO}
    GIT_REPOSITORY "https://github.com/KhronosGroup/Vulkan-Headers.git"
    GIT_TAG "v1.2.170"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_INCLUDEDIR}/${VULKAN_HPP_REPO} -DVULKAN_HPP_INSTALL=ON
    BUILD_COMMAND  ${CMAKE_COMMAND} --build <BINARY_DIR> --target all
)

include_directories("${CMAKE_INSTALL_INCLUDEDIR}/${VULKAN_HPP_REPO}/include")

# volk
set(VOLK_REPO volk)

ExternalProject_Add(
    ${VOLK_REPO}
    PREFIX ${VOLK_REPO}
    GIT_REPOSITORY "https://github.com/zeux/volk.git"
    GIT_TAG "1.2.170"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_INCLUDEDIR}/${VOLK_REPO} -DVOLK_INSTALL=ON -DVOLK_STATIC_DEFINES=VK_USE_PLATFORM_WIN32_KHR 
    BUILD_COMMAND  ${CMAKE_COMMAND} --build <BINARY_DIR> 
)

include_directories("${CMAKE_INSTALL_INCLUDEDIR}/${VOLK_REPO}/include")
link_directories("${CMAKE_INSTALL_INCLUDEDIR}/${VOLK_REPO}/lib")

add_dependencies(${VOLK_REPO} ${VULKAN_HPP_REPO})