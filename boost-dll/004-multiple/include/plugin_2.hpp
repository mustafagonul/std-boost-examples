#pragma once

#include <plugin_base.hpp>

class plugin_2 final : public plugin_base {
public:
  plugin_2() = default;
  virtual ~plugin_2() = default;

public:
  virtual uuid_t uuid() const noexcept;
  virtual str_t  name() const noexcept;

  virtual bool   exec();
};
