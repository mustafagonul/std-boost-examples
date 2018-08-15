#pragma once

#include <plugin_base.hpp>

class plugin final : public plugin_base {
public:
  plugin() = default;
  virtual ~plugin() = default;

public:
  virtual uuid_t uuid() const noexcept;
  virtual str_t  name() const noexcept;

  virtual bool   exec();
};
