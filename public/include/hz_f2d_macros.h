//
// Created by rasefon on 2019/1/18.
//

#ifndef HZ_F2D_MACROS_H
#define HZ_F2D_MACROS_H

#define BEGIN_HZ_F2D_NAMESPACE namespace hzf2d {
#define END_NAMESPACE }

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

#if defined WIN32 || defined _WIN32
#define NOMINMAX
#ifdef HZ_F2D_API_IMPORT
#define HZ_F2D_API __declspec(dllimport)
#else
#define HZ_F2D_API __declspec(dllexport)
#define EXCEPTION_FILE  "d:\\exception.txt"
#endif
#else
#define HZ_F2D_API
#define EXCEPTION_FILE  "~/exception.txt"
#endif

#define SOFT_ASSERT(Cond_)                                                     \
  if (!(Cond_)) {                                                              \
    std::ofstream exOutput(EXCEPTION_FILE, std::ostream::app);            \
    exOutput << __FILE__ << ":" << __LINE__ << std::endl;                      \
    time_t now = time(nullptr);                                                \
    struct tm tstruct;                                                         \
    char buf[40];                                                              \
    tstruct = *localtime(&now);                                                \
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);                       \
    std::string strDate(buf);                                                  \
    exOutput << strDate << std::endl;                                          \
    exOutput.close();                                                          \
    throw std::exception();                                                    \
  };

#define RELEASE_POINTER(pointer)                                               \
  if (pointer != nullptr) {                                                    \
    delete pointer;                                                            \
    pointer = nullptr;                                                         \
  };

#endif
