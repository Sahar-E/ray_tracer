//
// Created by Sahar on 08/06/2022.
//

#include <iostream>
#include "../include/utils.cuh"
#include <string>
#include <vector>
#include <memory>
#include "stb_library/stb_image_write.h"

void saveImgAsJpg(const std::string &filename,
                  const std::vector<std::tuple<double, double, double>> &data,
                  const int width,
                  const int height,
                  const int channelCount) {
    int n = height * width;
    auto dataCopy = std::make_unique<unsigned char[]>(n * channelCount);
    for (int i = 0; i < n; ++i) {
        auto [r, g, b] = data[i];
        dataCopy[i * channelCount] = static_cast<unsigned char>(r * 255);
        dataCopy[i * channelCount + 1] = static_cast<unsigned char>(g * 255);
        dataCopy[i * channelCount + 2] = static_cast<unsigned char>(b * 255);
    }
    std::cout << "\nSaving image to " << filename << "\n";
    stbi_write_jpg(filename.c_str(), width, height, channelCount, dataCopy.get(), width * channelCount);
}


template<typename T> void swap(T& t1, T& t2) {
    T temp = std::move(t1);
    t1 = std::move(t2);
    t2 = std::move(temp);
}