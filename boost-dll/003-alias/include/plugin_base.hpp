#pragma once

#include <boost/dll.hpp>
#include <boost/uuid/uuid.hpp>
#include <memory>


class plugin_base;

using uuid_t = boost::uuids::uuid;
using str_t  = const char*;
using factory_t = std::shared_ptr<plugin_base> ();
//using str_t = std::string;


class plugin_base {
protected:
  plugin_base() = default;

public:
  virtual ~plugin_base() = 0;

public:
  virtual uuid_t uuid() const noexcept = 0;
  virtual str_t  name() const noexcept = 0;

  virtual bool   exec() = 0;
};

