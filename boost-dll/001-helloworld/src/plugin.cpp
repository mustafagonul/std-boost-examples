#include <plugin.hpp>

#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT

#include <iostream>


// 4e08e426-ed3b-496a-8443-774ef4598212
uuid_t plugin::uuid() const noexcept
{
  return { 
    0x4e, 0x08, 0xe4, 0x26,
    0xed, 0x3b,
    0x49, 0x6a,
    0x84, 0x43,
    0x77, 0x4e, 0xf4, 0x59, 0x82, 0x12,
  };
}

str_t plugin::name() const noexcept
{
  return "plugin example";
}

bool plugin::exec()
{
  std::cout << "plugin::exec()" << std::endl;

  return true;
}

// Instance
extern "C" BOOST_SYMBOL_EXPORT plugin plugin_instance;

plugin plugin_instance;
