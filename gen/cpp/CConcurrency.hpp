// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from concurrency.djinni

#pragma once

#include <memory>
#include <string>

namespace generated {

class CRunnable;

class CConcurrency {
public:
    virtual ~CConcurrency() {}

    virtual void start_thread(const std::string & name, const std::shared_ptr<CRunnable> & runnable) = 0;

    virtual void execute_in_ui(const std::shared_ptr<CRunnable> & runnable) = 0;
};

}  // namespace generated
