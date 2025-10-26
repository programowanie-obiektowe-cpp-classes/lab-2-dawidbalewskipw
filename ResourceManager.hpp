#pragma once

#include "Resource.hpp"  
class ResourceManager
{
private:
    Resource* res_;

public:
    ResourceManager() : res_(new Resource()) {}

    ~ResourceManager() { delete res_; }

    ResourceManager(const ResourceManager& other) : res_(new Resource(*other.res_)) {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            Resource* fresh = new Resource(*other.res_);
            delete res_;
            res_ = fresh;
        }
        return *this;
    }

    double get() const { return res_->get(); }
};