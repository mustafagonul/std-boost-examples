#pragma once

#include <plugin_base.hpp>

class plugin_1 final : public plugin_base {
public:
  plugin_1() = default;
  virtual ~plugin_1() = default;

public:
  virtual uuid_t uuid() const noexcept;
  virtual str_t  name() const noexcept;

  virtual bool   exec();
};
